#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QtNetwork/QTcpSocket>
#include <QTimer>

#include "login.h"
#include "renderer.h"

namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();
    void showEvent(QShowEvent *e);

private slots:
    void on_pushButton_clicked();
    void readSoc();
    void timeout();
    void receivePseudo(QString psd);
    void sendDisconnect();

private:
    Ui::Client *ui;
    QString name;
    QTcpSocket socket;
    QTimer *timer;
    Login * loginDiaog;
    renderer *rendu;

    void showLogin();
    void loadMap(QString idx);

};

#endif // CLIENT_H
