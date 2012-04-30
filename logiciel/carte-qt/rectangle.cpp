#include "rectangle.h"
#include "groupe_selection.h"

Rectangle::Rectangle(Groupe_selection *parent) : Zone(parent)
{
    type = rectangle;
    label = "Rectangle " + QString::number(id);
    nb_poisitions = 0;
}

Rectangle::~Rectangle(){
}

QVector<QPointF> Rectangle::getpoints(){
    QVector<QPointF> points;
    points.append(point_haut_gauche);
    points.append(point_bas_droit);
    return points;
}

bool Rectangle::positionClick(QPointF point){
    if(++nb_poisitions == 1){
        point_haut_gauche = point;
        return false;
    }
    if(nb_poisitions == 2){
        point_bas_droit = point;
        return true;
    }
    return true;
}
