#include "cercle.h"
#include "groupe_selection.h"
#include <math.h>
#include <QDebug>

#include "myqpointf.h"

Cercle::Cercle(Groupe_selection *parent) : Zone(parent)
{
    type = Zone::cercle;
    cointHG = MyQPointF(-1,-1);
    cointBD = MyQPointF(-1,-1);
    label = QObject::tr("Cercle ") + QString::number(id);
}

Cercle::~Cercle(){
}

QPointF Cercle::getCentre(){
    return QPointF(centre.x(), centre.y());
}

QPointF Cercle::getCointHG(){
    return QPointF(cointHG.x(), cointHG.y());
}

QPointF Cercle::getCointBD(){
    return QPointF(cointBD.x(), cointBD.y());
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

QString Cercle::serialisation()
{
    return "{" + Zone::sub_serialisation() + ",chg=" + cointHG.serialisation() + ",cbd=" + cointBD.serialisation() + ",centre=" + centre.serialisation() + ",diametre=" + QString::number(diametre) + "}";
}

void Cercle::deserialisation(QString datas)
{
}
