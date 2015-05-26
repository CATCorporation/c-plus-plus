/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLineEdit *message;
    QPushButton *pushButton;
    QTextEdit *chat;
    QPushButton *exit;
    QGraphicsView *graphicsView;
    QLabel *label;

    void setupUi(QMainWindow *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QStringLiteral("Client"));
        Client->resize(1173, 702);
        Client->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(Client);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("background-image: url(:/img/fond.png);\n"
""));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(690, 50, 461, 641));
        groupBox->setStyleSheet(QLatin1String("border : 1px solid black;\n"
"background:transparent;\n"
"border-radius:15px;"));
        message = new QLineEdit(groupBox);
        message->setObjectName(QStringLiteral("message"));
        message->setGeometry(QRect(6, 540, 451, 51));
        message->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:15px;"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 600, 131, 31));
        pushButton->setStyleSheet(QLatin1String("border-radius:15px;\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:0, stop:0 rgba(170, 0, 255, 187), stop:1 rgba(211, 209, 218, 255));"));
        chat = new QTextEdit(groupBox);
        chat->setObjectName(QStringLiteral("chat"));
        chat->setGeometry(QRect(10, 10, 441, 511));
        chat->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:15px;"));
        exit = new QPushButton(centralWidget);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(1124, 10, 32, 32));
        exit->setStyleSheet(QLatin1String("background-image: url(:/img/close.png);\n"
"border: none;\n"
"margin: 0px;\n"
"padding: 0px;\n"
""));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(20, 60, 641, 631));
        graphicsView->setStyleSheet(QLatin1String("background:transparent;\n"
"border:none;"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 641, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("background: none;"));
        label->setAlignment(Qt::AlignCenter);
        Client->setCentralWidget(centralWidget);

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QMainWindow *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "Client", 0));
        groupBox->setTitle(QString());
        pushButton->setText(QApplication::translate("Client", "PushButton", 0));
        exit->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
