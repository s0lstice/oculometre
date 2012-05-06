#include "rectangle.h"
#include "groupe_selection.h"

Rectangle::Rectangle(Groupe_selection *parent) : Zone(parent)
{
    type = rectangle;
    label = QObject::tr("Rectangle ") + QString::number(id);
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

qreal Rectangle::getWidth(){
    return point_bas_droit.x() - point_haut_gauche.x();
}

qreal Rectangle::getHeight(){
    return point_bas_droit.y() - point_haut_gauche.y();
}

QString Rectangle::serialisation()
{
    QString datas;
    datas = "{";
    datas += Zone::sub_serialisation();
    datas += ",";
    datas += "phg=" + point_haut_gauche.serialisation() + ",";
    datas += "pbd=" + point_bas_droit.serialisation() ;
    datas += "}";

    return datas;
}

void Rectangle::deserialisation(QString datas)
{
}
