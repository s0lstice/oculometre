#include "projet.h"
#include <QStringList>

#include "groupe_selection.h"
//class Composite;
#include "sujet.h"
//class Sujet;

Projet::Projet()
{
    zones = new Groupe_selection();
}

Projet::~Projet()
{
    Sujet *tmp;
    int i;
    int nb = v_sujets.size();
    for (i = 0; i < nb; ++i){
        tmp = v_sujets.last();
        v_sujets.pop_back();
        delete tmp;
    }

    //!!!!! gereger larbre !
    delete zones;
}

//verifie que le volontaire a ouvir n'existe pas deja
//s'il n'existe pas on l'ouvre
void Projet::charger_sujets(QStringList liste_sujet){
    QString s_sujet;
    Sujet *s_test_sujet;
    Sujet *points;
    bool find = false;

    foreach(s_sujet, liste_sujet){
        foreach(s_test_sujet, v_sujets){
            if(s_test_sujet->getPath_sujet() == s_sujet)
                find = true;
        }
        if(find == false){
            points =  new Sujet(s_sujet);
            v_sujets.push_back(points);
        }
        find = false;
    }
}

//efface un volontaire
void Projet::supprimer_sujets(QVector<Sujet*> liste_sujet){
    Sujet *s_sujet;
    foreach(s_sujet, liste_sujet){
        delete s_sujet;
    }
}

Groupe_selection *Projet::getZones(){
    return zones;
}
Sujet *Projet::get_sujet(int i){
    return v_sujets.value(i);
}
QVector<Sujet*> Projet::get_sujet(){
    return v_sujets;
}
void Projet::rm_sujet(int i){
    v_sujets.remove(i);
}

int Projet::get_nb_sujet(){
    return v_sujets.size();
}

void Projet::set_path_carte(QString path){
    path_carte = path;
}

QString Projet::get_path_carte(){
    return path_carte;
}
