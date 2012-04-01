#include "projet.h"
#include <QStringList>
#include "sujet.h"

projet *projet::_singleton = NULL;

projet::projet()
{
}

projet::~projet()
{
    sujet *tmp;
    int i;
    int nb = v_sujets.size();
    for (i = 0; i < nb; ++i){
        tmp = v_sujets.last();
        v_sujets.pop_back();
        delete tmp;
    }
}

void projet::charger_sujets(QStringList liste_sujet){
    QString s_sujet;
    sujet *points;
    foreach(s_sujet, liste_sujet){
        points =  new sujet(s_sujet);
        v_sujets.push_back(points);
    }
}
