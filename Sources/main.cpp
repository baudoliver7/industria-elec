#include <QApplication>
#include <QDir>

#include "mainwindow.h"
//#include "EvPuissMethod1.h"
//#include "EvPuissMethod2.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // supprimer le chemin qt des plugins
    a.removeLibraryPath("C:/Qt/2010.02.1/qt/plugins/");

    QStringList env = QProcess::systemEnvironment();

    // ajouter le path des plugins
    int i = 0;
    while(!(env.at(i).contains("Common Files")||env.at(i).contains("Fichiers communs")))
    {
        i++;
    }

    QString cf32 = QDir::fromNativeSeparators(QString(env.at(i)).split("=").last());
    QString pluginPath = cf32 + "/Industria Elec/plugins/";
    a.addLibraryPath(pluginPath);

    // on démarre l'application
    MainWindow w;
    //EvPuissMethod1 w;
    //EvPuissMethod2 w;
    w.showMaximized();
    return a.exec();
}
