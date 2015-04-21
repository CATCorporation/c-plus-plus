#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QtNetwork/QTcpSocket>

namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();

private slots:
    void on_pushButton_clicked();
    void readSoc();
private:
    Ui::Client *ui;
    QString name;
    QTcpSocket socket;
};

#endif // CLIENT_H
