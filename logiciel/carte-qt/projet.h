#ifndef PROJET_H
#define PROJET_H

#include "cv.h"

#include <QString>
#include <QVector>
#include <QRegExp>
#include <QDebug>
#include <QStringList>
#include <QVariant>

//#include "groupe_selection.h"
class Groupe_selection;
//#include <Volontaire.h>
class Volontaire;

class Projet
{
private:
    IplImage *carte;
    QString path_carte;
    QVector<Volontaire*> v_Volontaires;
    Groupe_selection *zones;
    QString name;

public:
    Projet();
    ~Projet();

    Groupe_selection *getZones();
    Volontaire *get_Volontaire(int i);
    QVector<Volontaire*> get_Volontaire();
    QVector<Volontaire*> *getVolontaires();

    void rm_Volontaire(int i);
    int get_nb_Volontaire();

    void set_carte(QString path, IplImage *image);
    QString get_path_carte();
    IplImage *get_carte();
    void freeCarte();

    void charger_Volontaires(QStringList liste_Volontaire);
    void supprimer_Volontaires(QVector<Volontaire*> liste_Volontaire);
    void supprimer_Volontaire(int row);

    void setName(QString name);
    QString getName();
};

#endif // PROJET_H
