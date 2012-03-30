#include "points.h"
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QFileDialog>

using namespace std;

void points::charger_points(){

    QFile file(path_sujet);

    if(!file.open(QIODevice::ReadOnly)){
        qWarning() << "[erreur] impossible d'ouvrir le ficher en ecriture seul"
                  << qPrintable(file.errorString());
        return;
    }

    QTextStream out(&file);
    QString line;
    {
        line = out.readLine();
        qDebug() <<  line;
    }while(!line.isNull());
}



points::points(const QString path)
{
    path_sujet = path;
    charger_points();
}
