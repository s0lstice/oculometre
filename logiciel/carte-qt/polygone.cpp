#include "polygone.h"

Polygone::Polygone() : Zone()
{
    type = polygone;
}

void Polygone::addEndPoint(QPoint point){
    points.append(point);
}

QPoint Polygone::getPoint(int i){
    return points.at(i);
}

QVector<QPoint> Polygone::getpoints(){
    return points;
}

void Polygone::addEndPoints(QVector<QPoint> points){
    this->points += points;
}
