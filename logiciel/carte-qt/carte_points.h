#ifndef CARTE_POINTS_H
#define CARTE_POINTS_H

#include <QVector>
//#include "mainwindow.h"
class MainWindow;
//#include "volontaire.h"
class Volontaire;
//#include "projet.h"
class Projet;

class Carte_points
{
public:
    Carte_points(Projet *pro,QVector<Volontaire*> v_Volontaires, MainWindow *parent);
};

#endif // CARTE_POINTS_H
