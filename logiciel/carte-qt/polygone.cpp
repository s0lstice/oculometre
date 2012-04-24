#include "polygone.h"
#include "groupe_selection.h"

Polygone::Polygone(Groupe_selection *parent) : Zone(parent)
{
    type = polygone;
}

Polygone::~Polygone(){
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
