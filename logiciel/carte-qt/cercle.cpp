#include "cercle.h"
#include "groupe_selection.h"
#include <math.h>
#include <QDebug>

Cercle::Cercle(Groupe_selection *parent) : Zone(parent)
{
    type = cercle;
    cointHG = QPointF(-1,-1);
    cointBD = QPointF(-1,-1);
    label = QObject::tr("Cercle ") + QString::number(id);
}

Cercle::~Cercle(){
}

QPointF Cercle::getCentre(){
    return centre;
}

QPointF Cercle::getCointHG(){
    return cointHG;
}

QPointF Cercle::getCointBD(){
    return cointBD;
}

int Cercle::getDiametre(){
    return diametre;
}

bool Cercle::positionClick(QPointF point){
    if(cointHG.x() == -1){
        cointHG = point;
        return false;
    }
    else{
        cointBD = point;
        diametre = hypot(cointBD.x() - centre.x(), cointBD.y() - centre.y());

        centre = QPointF(cointHG.x() - diametre, cointHG.y() - diametre);

        diametre = 2*diametre;
        return true;
    }
    return true;
}
