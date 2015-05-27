#include "client.h"
#include "ui_client.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QDesktopServices>
#include <QDir>
#include <QFileInfoList>
#include "howtoplay.h"

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    QString iniPath = CONFIG_SERVEUR;
    fichierIni = new QSettings(iniPath,QSettings::IniFormat);

    timer = new QTimer;
    isConnected = new QTimer;
    loginDiaog = new Login(this);
    rendu = new renderer;
    showTuto = true;
    tutoriel = new HowToPlay(this);
    isOk = false;
    makeConenct();

}

Client::~Client()
{
    delete rendu;
    delete ui;
}

void Client::showEvent(QShowEvent *e)
{
    Q_UNUSED(e);
}

void Client::mousePressEvent(QMouseEvent *e)
{
    m_nMouseClick_X_Coordinate = e->x();
    m_nMouseClick_Y_Coordinate = e->y();
}

void Client::mouseMoveEvent(QMouseEvent *e)
{
    this->move(e->globalX()-m_nMouseClick_X_Coordinate,e->globalY()-m_nMouseClick_Y_Coordinate);
}

void Client::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Return)
        on_pushButton_clicked();
}

void Client::closeEvent(QCloseEvent *e)
{
    Q_UNUSED(e);
    sendDisconnect();
}

void Client::on_pushButton_clicked()
{
    QTextStream flux(&socket);
    if(name.isEmpty())
        showLogin();
    else
    {
        if(ui->message->text().size() > 200)
            QMessageBox::information(this,"Too long","Un message ne doit pas compter plus de 200 charactères");
        else
        {
            flux << name<<">> " << ui->message->text() << endl;
            ui->message->clear();
            ui->message->setFocus();
        }
    }
}

void Client::readSoc()
{
    QString ligne;
    QString reponse;
        while(socket.canReadLine()) // tant qu'il y a quelque chose à lire dans la socket
        {
            ligne = socket.readLine();

            if(ligne.contains("connect"))
            {
               reponse = ligne.split("|").at(1);
               reponse.remove("\n");
               if(reponse == "NO")
               {
                    loginDiaog->changeText("Pseudo deja utilisé");
                    loginDiaog->exec();
               }
               else
               {
                    if(showTuto)
                        tutoriel->show();
                    isOk = true;
               }

               loginDiaog->deleteLater();
            }
            else if(ligne.contains("count"))
            {
                reponse = ligne.split("|").at(1);
                reponse.remove("\n");
                if(reponse.toInt() != countMap())
                {
                    QMessageBox::warning(this,"Mise à jour disponible","Votre version n'est pas à jour.\nVeuiller télécharger la dernière mise à jour afin de pouvoir continuer à utiliser le logiciel");
                    QDesktopServices::openUrl ( QUrl("http://stitch.synology.me/Maze solvers/donwload.html") );
                    this->close();
                }
                else
                {
                    this->show();
                    showLogin();
                    timer->deleteLater();
                }
            }
            else if(ligne.contains("load"))
            {
                reponse = ligne.split("|").at(1);
                reponse.remove("\n");
                if(rendu->loadMap(reponse))
                {
                    currentLevel = ligne.split("|").at(2).toInt();
                    rendu->rendu(ligne.split("|").at(3),currentLevel,ui->graphicsView);
                }

                ui->label->setText("Niveau : " + QString::number(currentLevel));
            }
            else if(ligne.contains("move") && isOk)
            {
                reponse = ligne.split("|").at(1);
                reponse.remove("\n");
                rendu->rendu(reponse,currentLevel,ui->graphicsView);
                ui->vie->setText("Vie : "+reponse.split("&").at(4));
            }
            else if(ligne.contains("mode") && isOk)
            {
                reponse = ligne.split("|").at(2);
                reponse.remove("\n");
                ui->horizontalSlider->setValue(reponse.toInt());
                ui->chat->textCursor().insertText(ligne.split("|").at(0));
            }
            else
                ui->chat->textCursor().insertText(ligne.split("|").at(0));
        }

        QTextCursor c = ui->chat->textCursor();
        c.movePosition(QTextCursor::End);
        ui->chat->setTextCursor(c);
}

void Client::timeout()
{
    if(socket.state() != QTcpSocket::ConnectedState)
    {
        QMessageBox::critical(0,"ERREUR","Impossible de se connecter au serveur");
        this->close();
    }
}

void Client::receivePseudo(QString psd)
{
    name = psd;
    QTextStream flux(&socket);

    flux << "connect|" << psd << endl;
}

void Client::sendDisconnect()
{
    QTextStream flux(&socket);
    flux << "disconnect|" << name << endl;
    this->close();
}

void Client::againConnected()
{
    if(socket.state() != QTcpSocket::ConnectedState)
    {
        QMessageBox::information(this,"Erreur serveur","Connexion au serveur perdue");
        this->close();
    }
    isConnected->start(20000);
}

void Client::showLogin()
{
    loginDiaog->show();
}

void Client::loadMap(QString idx)
{
    rendu->loadMap(idx);
}

void Client::makeConenct()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));
    connect(isConnected,SIGNAL(timeout()),this,SLOT(againConnected()));
    connect(&socket,SIGNAL(readyRead()),this,SLOT(readSoc()));
    connect(loginDiaog,SIGNAL(envoyerPseudo(QString)),this,SLOT(receivePseudo(QString)));
    connect(ui->exit,SIGNAL(clicked()),this,SLOT(sendDisconnect()));
}

int Client::countMap()
{
    QDir dir = QDir::currentPath() + "/map/";

    QFileInfoList listRepertoire = dir.entryInfoList(QDir::Dirs | QDir::Files);
    int numberFiles = 0;

    for (int i = 0; i < listRepertoire.size(); ++i)
    {
        QFileInfo fileInfos = listRepertoire.at(i);
        if(fileInfos.isFile())
        {
            numberFiles++;
        }
    }
    return numberFiles;
}

void Client::loadConfig()
{
    showTuto = fichierIni->value(tr("CONF/TUTO"),"true").toBool();
    serverAddr = fichierIni->value(tr("RESEAU/ADDRESS"),"").toString();
    if(serverAddr.isEmpty())
    {
        QMessageBox::information(this,"Erreur chargement","Impossible de charger la configuration");
        this->close();
    }
}

void Client::checkUpdate()
{
    QTextStream flux(&socket);
    flux << "count|"<< endl;
}

void Client::connectApplication()
{
    socket.connectToHost(serverAddr, 1234);


    timer->start(1500);
    isConnected->start(20000);

}

void Client::on_aide_clicked()
{
    tutoriel->show();
}
