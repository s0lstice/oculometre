#ifndef MYQPOINTF_H
#define MYQPOINTF_H

#include <QPointF>

class MyQPointF : public QPointF
{
public:
    MyQPointF( const QPoint & point);
    MyQPointF(qreal x, qreal y);
    MyQPointF(int x, int y);
    MyQPointF();

    QString serialisation();
    void deserialisation(QString datas);

    MyQPointF &operator=(const QPointF point);
};

#endif // MYQPOINTF_H
