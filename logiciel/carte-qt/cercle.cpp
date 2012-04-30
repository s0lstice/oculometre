#include "cercle.h"
#include "groupe_selection.h"
#include <math.h>
#include <QDebug>

Cercle::Cercle(Groupe_selection *parent) : Zone(parent)
{
    type = cercle;
    label = "Cercle " + QString::number(id);
    nb_poisitions = 0;
}

Cercle::~Cercle(){
}

QPoint Cercle::getCentre(){
    return centre;
}

int Cercle::getDiametre(){
    return diametre;
}

bool Cercle::positionClick(QPointF point){
    if(++nb_poisitions == 1){
        centre.setX(point.x());
        centre.setY(point.y());
        return false;
    }
    if(nb_poisitions == 2){
        diametre = hypot(point.x() - centre.x(), point.y() - centre.y());

        centre.setX(centre.x() - diametre);
        centre.setY(centre.y() - diametre);

        diametre = 2*diametre;
        return true;
    }
    return true;
}
