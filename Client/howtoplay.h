#ifndef HOWTOPLAY_H
#define HOWTOPLAY_H

#include <QDialog>
#include <QSettings>

#define CONFIG_SERVEUR  "CONFIG_SERV.ini"

namespace Ui {
class HowToPlay;
}

class HowToPlay : public QDialog
{
    Q_OBJECT

public:
    explicit HowToPlay(QWidget *parent = 0);
    ~HowToPlay();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HowToPlay *ui;
    QSettings * iniFile;
};

#endif // HOWTOPLAY_H
