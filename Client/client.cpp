#include "client.h"
#include "ui_client.h"
#include <QMessageBox>

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    socket.connectToHost("127.0.0.1", 1234);
    timer = new QTimer;

    connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));
    connect(&socket,SIGNAL(readyRead()),this,SLOT(readSoc()));

    loginDiaog = new Login(this);
    connect(loginDiaog,SIGNAL(envoyerPseudo(QString)),this,SLOT(receivePseudo(QString)));

    connect(ui->exit,SIGNAL(clicked()),this,SLOT(sendDisconnect()));

    rendu = new renderer;
}

Client::~Client()
{
    delete ui;
}

void Client::showEvent(QShowEvent *e)
{
    Q_UNUSED(e);
    timer->start(1000);
}

void Client::on_pushButton_clicked()
{
    QTextStream flux(&socket);

    flux << name<<">> " << ui->message->text() << endl;
    ui->message->clear();
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
           }
           else if(ligne.contains("load"))
           {
                reponse = ligne.split("|").at(1);
                reponse.remove("\n");
                if(rendu->loadMap(reponse))
                    rendu->rendu(0,0,0,ui->graphicsView);
           }
           else
            ui->chat->textCursor().insertText(ligne);
        }
}

void Client::timeout()
{
    if(socket.state() == QTcpSocket::UnconnectedState)
    {
        QMessageBox::critical(0,"ERREUR","Impossible de se connecter au serveur");
        this->close();
    }
    else
    {
        showLogin();
        timer->stop();
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

void Client::showLogin()
{
    loginDiaog->show();
}

void Client::loadMap(QString idx)
{
    rendu->loadMap(idx);
}
