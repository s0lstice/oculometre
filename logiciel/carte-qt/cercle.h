#ifndef CERCLE_H
#define CERCLE_H

#include "zone.h"
#include <QPoint>
#include <QPointF>

class Groupe_selection;

class Cercle : public Zone
{
private:
    QPointF centre;
    QPointF cointBD;
    QPointF cointHG;

    int diametre;
    int nb_poisitions;

public:
    Cercle(Groupe_selection *parent);
    ~Cercle();

    QPointF getCentre();
    QPointF getCointBD();
    QPointF getCointHG();
    int getDiametre();

    bool positionClick(QPointF point);

};

#endif // CERCLE_H
