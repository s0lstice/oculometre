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
    sujet *s_test_sujet;
    sujet *points;
    bool find = false;
    foreach(s_sujet, liste_sujet){
        foreach(s_test_sujet, v_sujets){
            if(s_test_sujet->getPath_sujet() == s_sujet)
                find = true;
        }
        if(find == false){
            points =  new sujet(s_sujet);
            v_sujets.push_back(points);
        }
        find = false;
    }
}

void projet::supprimer_sujets(QVector<sujet*> liste_sujet){
    sujet *s_sujet;
    foreach(s_sujet, liste_sujet){
        delete s_sujet;
    }
}
