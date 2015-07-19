#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("Choisissez votre pseudo");
}

Login::~Login()
{
    delete ui;
}

void Login::changeText(QString text)
{
    ui->label->setText(text);
    ui->pseudo->clear();
}
void Login::on_connecter_clicked()
{
    emit sendPseudo(ui->pseudo->text());
    this->close();
}

