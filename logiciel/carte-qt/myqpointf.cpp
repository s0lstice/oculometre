#include "myqpointf.h"

#include <QString>

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
