#ifndef POLYGONE_H
#define POLYGONE_H

#include "zone.h"
#include <QPointF>
#include <QVector>
#include "myqpointf.h"

class Groupe_selection;

class Rectangle : public Zone
{
private:
    MyQPointF point_haut_gauche;
    MyQPointF point_bas_droit;
    int nb_poisitions;

public:
    Rectangle(Groupe_selection *parent);
    ~Rectangle();

    QVector<QPointF> getpoints();
    bool positionClick(QPointF point);
    qreal getWidth();
    qreal getHeight();

    QString serialisation();
    void deserialisation(QString datas);
};

#endif // POLYGONE_H
