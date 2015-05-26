#include "howtoplay.h"
#include "ui_howtoplay.h"

HowToPlay::HowToPlay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HowToPlay)
{
    ui->setupUi(this);

    QString iniPath = CONFIG_SERVEUR;
    fichierIni = new QSettings(iniPath,QSettings::IniFormat);
}

HowToPlay::~HowToPlay()
{
    delete ui;
}

void HowToPlay::on_pushButton_clicked()
{
    fichierIni->setValue(tr("CONF/TUTO"),ui->checkBox->isChecked());
    this->close();
}
