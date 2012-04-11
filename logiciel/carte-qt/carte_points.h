#ifndef CARTE_POINTS_H
#define CARTE_POINTS_H

#include <QVector>
//#include "mainwindow.h"
class MainWindow;
//#include "sujet.h"
class Sujet;
//#include "projet.h"
class Projet;

class Carte_points
{
public:
    Carte_points(Projet *pro,QVector<Sujet*> v_sujets, MainWindow *parent);
};

#endif // CARTE_POINTS_H
