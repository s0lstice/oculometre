#include "projet.h"
#include <QStringList>
#include <QDebug>

projet *projet::_singleton = NULL;

projet::projet()
{
}

void projet::charger_sujets(QStringList liste_sujet){
    QString sujet;
    points_sujet *points;
    foreach(sujet, liste_sujet){
        qDebug() << sujet;
        points =  new points_sujet(sujet);
        v_sujets.push_back(points);
    }
}
