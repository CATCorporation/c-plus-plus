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
#include <QtWidgets/QSlider>
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
    QSlider *horizontalSlider;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *exit;
    QGraphicsView *graphicsView;
    QLabel *label;
    QPushButton *aide;

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
        chat->setGeometry(QRect(10, 60, 441, 461));
        chat->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:15px;"));
        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setEnabled(false);
        horizontalSlider->setGeometry(QRect(119, 20, 191, 31));
        horizontalSlider->setStyleSheet(QLatin1String("border: none;\n"
"margin: 0px;\n"
"padding: 0px;\n"
""));
        horizontalSlider->setValue(45);
        horizontalSlider->setTracking(false);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 111, 31));
        QFont font;
        font.setPointSize(16);
        label_2->setFont(font);
        label_2->setStyleSheet(QLatin1String("border: none;\n"
"margin: 0px;\n"
"padding: 0px;\n"
""));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(330, 20, 111, 31));
        label_3->setFont(font);
        label_3->setStyleSheet(QLatin1String("border: none;\n"
"margin: 0px;\n"
"padding: 0px;\n"
""));
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
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("background: none;"));
        label->setAlignment(Qt::AlignCenter);
        aide = new QPushButton(centralWidget);
        aide->setObjectName(QStringLiteral("aide"));
        aide->setGeometry(QRect(1080, 10, 31, 31));
        aide->setStyleSheet(QLatin1String("background-image: url(:/img/aide.png);\n"
"border: none;\n"
"margin: 0px;\n"
"padding: 0px;\n"
""));
        Client->setCentralWidget(centralWidget);

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QMainWindow *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "Client", 0));
        groupBox->setTitle(QString());
        pushButton->setText(QApplication::translate("Client", "PushButton", 0));
        label_2->setText(QApplication::translate("Client", "Anarchie", 0));
        label_3->setText(QApplication::translate("Client", "D\303\251mocratie", 0));
        exit->setText(QString());
        label->setText(QString());
        aide->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
