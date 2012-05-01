#ifndef POLYGONE_H
#define POLYGONE_H

#include "zone.h"
#include <QPointF>
#include <QVector>

class Groupe_selection;

class Rectangle : public Zone
{
private:
    QPointF point_haut_gauche;
    QPointF point_bas_droit;
    int nb_poisitions;

public:
    Rectangle(Groupe_selection *parent);
    ~Rectangle();

    QVector<QPointF> getpoints();
    bool positionClick(QPointF point);
    qreal getWidth();
    qreal getHeight();
};

#endif // POLYGONE_H
