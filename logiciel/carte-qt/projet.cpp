#include "projet.h"
#include <QStringList>

#include "groupe_selection.h"
//class Composite;
#include "volontaire.h"
//class Volontaire;

Projet::Projet()
{
    carte = NULL;
    path_carte = "";
    name = "";

    zones = new Groupe_selection(NULL);
    zones->setLabel("Root Item");
}

Projet::~Projet()
{
    Volontaire *tmp;
    int i;
    int nb = v_Volontaires.size();
    for (i = 0; i < nb; ++i){
        tmp = v_Volontaires.last();
        v_Volontaires.pop_back();
        delete tmp;
    }

    if(path_carte != "")
        cvReleaseImage(&carte);

    delete zones;
}

//verifie que le Volontaire a ouvir n'existe pas deja
//s'il n'existe pas on l'ouvre
void Projet::charger_Volontaires(QStringList liste_Volontaire){
    QString s_Volontaire;
    Volontaire *s_test_Volontaire;
    Volontaire *points;
    bool find = false;

    foreach(s_Volontaire, liste_Volontaire){
        foreach(s_test_Volontaire, v_Volontaires){
            if(s_test_Volontaire->getPath_Volontaire() == s_Volontaire)
                find = true;
        }
        if(find == false){
            points =  new Volontaire(this, s_Volontaire);
            if(points->getId_Volontaire() != "")
                v_Volontaires.push_back(points);
        }
        find = false;
    }
}

//efface un Volontaire
void Projet::supprimer_Volontaires(QVector<Volontaire*> liste_Volontaire){
    Volontaire *s_Volontaire;
    foreach(s_Volontaire, liste_Volontaire){
        delete s_Volontaire;
    }
}

void Projet::supprimer_Volontaire(int row){
        delete v_Volontaires.at(row);
        v_Volontaires.remove(row);
}

Groupe_selection *Projet::getZones(){
    return zones;
}
Volontaire *Projet::get_Volontaire(int i){
    return v_Volontaires.value(i);
}
QVector<Volontaire*> Projet::get_Volontaire(){
    return v_Volontaires;
}
QVector<Volontaire*> *Projet::getVolontaires(){
    return &v_Volontaires;
}

void Projet::rm_Volontaire(int i){
    v_Volontaires.remove(i);
}

int Projet::get_nb_Volontaire(){
    return v_Volontaires.size();
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

void Projet::setName(QString name){
    this->name = name;
}

QString Projet::getName(){
    return name;
}
