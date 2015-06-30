#include "client.h"
#include <QApplication>
#include <QSplashScreen>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Client w;

    QPixmap pixmap(":/img/logo.jpg");
    QSplashScreen splash(pixmap);
    splash.show();

    splash.showMessage("Chargement en de la configuration");
    QThread::sleep(2);
    qApp->processEvents();
    w.loadConfig();

    splash.showMessage("Connexion en cours");
    QThread::sleep(2);
    qApp->processEvents();
    w.connectApplication();

    splash.showMessage("Vérification mise a jours client");
    qApp->processEvents();
    w.checkVersion();

    splash.showMessage("Vérification mise a jours contenue");
    qApp->processEvents();
    w.checkUpdate();

    return a.exec();
}
