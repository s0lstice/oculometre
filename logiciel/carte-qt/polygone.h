#ifndef POLYGONE_H
#define POLYGONE_H

#include "zone.h"
#include <QPoint>
#include <QVector>

class Groupe_selection;
class Polygone : public Zone
{
private:
    QVector<QPoint> points;
public:
    Polygone(Groupe_selection *parent);
    ~Polygone();

    void addEndPoint(QPoint point);
    QPoint getPoint(int i);
    QVector<QPoint> getpoints();
    void addEndPoints(QVector<QPoint> points);
};

#endif // POLYGONE_H
