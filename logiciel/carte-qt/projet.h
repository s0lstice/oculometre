#ifndef PROJET_H
#define PROJET_H

#include "cv.h"

#include <QString>
#include <QVector>
#include <QRegExp>
#include <QDebug>
#include <QStringList>

//#include "groupe_selection.h"
class Groupe_selection;
//#include <sujet.h>
class Sujet;

class Projet
{
private:
    IplImage *carte;
    QString path_carte;
    QVector<Sujet*> v_sujets;
    Groupe_selection *zones;
    int nb_zones;

public:
    Projet();
    ~Projet();

    Groupe_selection *getZones();
    Sujet *get_sujet(int i);
    QVector<Sujet*> get_sujet();

    void rm_sujet(int i);
    int get_nb_sujet();

    void set_carte(QString path, IplImage *image);
    QString get_path_carte();
    IplImage *get_carte();
    void freeCarte();

    void charger_sujets(QStringList liste_sujet);
    void supprimer_sujets(QVector<Sujet*> liste_sujet);

    int getNb_zone();
    void upNb_zone();
    void downNb_zone();
};

#endif // PROJET_H
