#include "projet.h"
#include <QStringList>

#include "groupe_selection.h"
//class Composite;
#include "sujet.h"
//class Sujet;

Projet::Projet()
{
    carte = NULL;
    path_carte = "";
    nb_zones = 0;

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

    if(path_carte != "")
        cvReleaseImage(&carte);

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

void Projet::set_carte(QString path, IplImage *image){
    if(path_carte == ""){
        carte = image;
    }
    else
    {
        cvReleaseImage(&carte);
        carte = image;
    }
    path_carte = path;
}

QString Projet::get_path_carte(){
    return path_carte;
}

IplImage * Projet::get_carte(){
    return carte;
}

void Projet::freeCarte(){
    cvReleaseImage(&carte);
}

int Projet::getNb_zone(){
    return nb_zones;
}

void Projet::upNb_zone(){
    nb_zones++;
}

void Projet::downNb_zone(){
    nb_zones--;
}
