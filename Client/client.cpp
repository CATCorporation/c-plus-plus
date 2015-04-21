#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    socket.connectToHost("127.0.0.1", 1234);

    connect(&socket,SIGNAL(readyRead()),this,SLOT(readSoc()));

}

Client::~Client()
{
    delete ui;
}

void Client::on_pushButton_clicked()
{
    QTextStream flux(&socket);

    flux << "toto>>" << ui->message->text() << endl;
    ui->message->clear();
}

void Client::readSoc()
{
    QString ligne;
        while(socket.canReadLine()) // tant qu'il y a quelque chose à lire dans la socket
        {
           ligne = socket.readLine();

           ui->chat->textCursor().insertText(ligne);
        }

       // ui->chat->moveCursor(QTextCursor::End);

}
