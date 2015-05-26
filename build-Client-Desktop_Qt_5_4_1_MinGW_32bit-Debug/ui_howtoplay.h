/********************************************************************************
** Form generated from reading UI file 'howtoplay.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOWTOPLAY_H
#define UI_HOWTOPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HowToPlay
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QCheckBox *checkBox;
    QPushButton *pushButton;

    void setupUi(QDialog *HowToPlay)
    {
        if (HowToPlay->objectName().isEmpty())
            HowToPlay->setObjectName(QStringLiteral("HowToPlay"));
        HowToPlay->resize(536, 324);
        groupBox = new QGroupBox(HowToPlay);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 521, 271));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 501, 251));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        checkBox = new QCheckBox(HowToPlay);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 290, 331, 17));
        checkBox->setChecked(true);
        pushButton = new QPushButton(HowToPlay);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(404, 290, 111, 23));

        retranslateUi(HowToPlay);

        QMetaObject::connectSlotsByName(HowToPlay);
    } // setupUi

    void retranslateUi(QDialog *HowToPlay)
    {
        HowToPlay->setWindowTitle(QApplication::translate("HowToPlay", "Dialog", 0));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("HowToPlay", "/!\\ Comment jouer /!\\ \n"
"\n"
"\n"
"Pour se deplacer il suffit d'\303\251crire les commandes suivantes :\n"
"\n"
"up\n"
"donw\n"
"left\n"
"right\n"
"\n"
"Deux modes de jeu sont disponibles  \"Anarchie\" ou \"D\303\251mocratie\".\n"
"Le mode actif est celui poss\303\251dant le + de voix. Pour voter il faut taper l'une des commandes suivantes :\n"
"\n"
"anarchie\n"
"d\303\251mocratie\n"
"\n"
"\n"
"Bon jeu.", 0));
        checkBox->setText(QApplication::translate("HowToPlay", "Afficher au prochain lancement", 0));
        pushButton->setText(QApplication::translate("HowToPlay", "Fermer", 0));
    } // retranslateUi

};

namespace Ui {
    class HowToPlay: public Ui_HowToPlay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOWTOPLAY_H
