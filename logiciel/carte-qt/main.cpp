#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator translator;
    translator.load("lang_fr");
    app.installTranslator(&translator);

    MainWindow w;
    w.showMaximized();

    return app.exec();
}
