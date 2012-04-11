#ifndef QUADRILATAIRE_H
#define QUADRILATAIRE_H

#include "zone.h"
#include <QPoint>
#include <QVector>

class polygonne : public zone
{
private:
    QVector<QPoint> coordonees;
    int nb_sommet;
public:
    polygonne();

    QVector<QPoint> getCoordonees(){
        return coordonees;
    }
};

#endif // QUADRILATAIRE_H
