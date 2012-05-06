#ifndef ANALYSE_H
#define ANALYSE_H

#include <QStringList>

class Projet;
class Groupe_selection;
class Rectangle;
class Cercle;
class Volontaire;

class Analyse
{
private :
    Projet *projet;
    QStringList data;

    void appartenance();
    void appartenance(Volontaire *volontaire, Groupe_selection *group);
    void rectangleTest(Volontaire *volontaire, Rectangle *rectangle);
    void cercleTest(Volontaire *volontaire, Cercle *cercle);

public:
    Analyse(Projet *projet);
    QStringList getData();
};

#endif // ANALYSE_H
