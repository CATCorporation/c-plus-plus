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
    qApp->processEvents();
    w.connectApplication();
    QThread::sleep(2);

    splash.showMessage("Vérification des mises à jours");
    qApp->processEvents();
    QThread::sleep(2);
    w.checkUpdate();

    return a.exec();
}
