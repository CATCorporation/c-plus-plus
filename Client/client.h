#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QtNetwork/QTcpSocket>
#include <QTimer>
#include <QSettings>

#include "login.h"
#include "renderer.h"

#define CONFIG_SERVEUR  "CONFIG_SERV.ini"

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
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void closeEvent(QCloseEvent *e);    
    void connectApplication();
    void loadConfig();
    void checkUpdate();

private slots:
    void on_pushButton_clicked();
    void readSoc();
    void timeout();
    void receivePseudo(QString psd);
    void sendDisconnect();
    void againConnected();

private:
    Ui::Client *ui;
    QString name;
    QString serverAddr;
    int currentLevel;
    QTcpSocket socket;
    QTimer *timer;
    QTimer *isConnected;
    Login * loginDiaog;
    renderer *rendu;
    int  m_nMouseClick_X_Coordinate;
    int  m_nMouseClick_Y_Coordinate;
    QSettings * fichierIni;

    void showLogin();
    void loadMap(QString idx);
    void makeConenct();
    int countMap();

};

#endif // CLIENT_H
