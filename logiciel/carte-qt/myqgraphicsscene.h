#ifndef MYQGRAPHICSSCENE_H
#define MYQGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
//#include "mainwindow.h"

class MyQGraphicsScene : public  QGraphicsScene
{
    Q_OBJECT
private:
    QObject *mainwindow;
public:
    MyQGraphicsScene(QObject *parent = 0);

protected:
    void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );
};

#endif // MYQGRAPHICSSCENE_H
