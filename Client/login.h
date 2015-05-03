#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    void changeText(QString text);

private slots:
    void on_connecter_clicked();

private:
    Ui::Login *ui;

signals:
    void envoyerPseudo(QString ps);

};

#endif // LOGIN_H
