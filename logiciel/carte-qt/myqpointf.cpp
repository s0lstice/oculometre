#include "myqpointf.h"

#include <QString>
#include <QRegExp>
#include <QStringList>

MyQPointF::MyQPointF(qreal x, qreal y) : QPointF(x, y)
{
}

MyQPointF::MyQPointF(int x, int y) : QPointF((qreal)x, (qreal)y)
{
}

MyQPointF::MyQPointF()
{
}

MyQPointF &MyQPointF::operator=(const QPointF point)
{
    setX(point.x());
    setY(point.y());
    return *this;
}

MyQPointF::MyQPointF(const QPoint &point) : QPointF(point)
{
}

QString MyQPointF::serialisation()
{
    return "{x=" + QString::number(x()) + "," + "y=" +QString::number(y()) + "}";
}

void MyQPointF::deserialisation(QString datas){

    QStringList ListeValeur;
    QString valeur;
    datas.remove(0,3);
    datas.remove(datas.size() -1, 1);
    ListeValeur = datas.split(",");
    valeur = ListeValeur[0];
    setX(valeur.toFloat());
    valeur = ListeValeur[1];
    valeur.remove(0,2);
    setY(valeur.toFloat());
}
