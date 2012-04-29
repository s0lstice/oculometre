#ifndef MYQGRAPHICSSCENE_H
#define MYQGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMenu>

#include <cv.h>
#include <highgui.h>

//#include "zone.h"
class Zone;
//#include "mainwindow.h"
class MainWindow;
//#include "carte_select.h"
class Carte_select;


class MyQGraphicsScene : public  QGraphicsScene
{
    Q_OBJECT
private:
    Zone * zone_courante;
    bool selection_zone;
    MainWindow *mainwindow;
    Carte_select *carte_selection;
    //couche d'items (pixmap 0; groupVolontaire 1; groupZone 2)
        //couche volontaires
    QList<QGraphicsItem *> itemsVolontaire;
    QGraphicsItemGroup * groupVolontaire;
        //couche zones
    QList<QGraphicsItem *> itemsZone;
    QGraphicsItemGroup * groupZone;

public:
    MyQGraphicsScene(QObject *parent = 0);

    void setCarte_selection(Carte_select *pcarte_selection);
    void delCarte_selection();
    void setSelection_zone(bool value);
    bool getSelection_zone();
    void setZone_courante(Zone *pzone);
    void nullZone_courante();
    void DrowVolontaires();
    void shoowIplImage(IplImage * iplImg);

protected:
    void mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent );
};

#endif // MYQGRAPHICSSCENE_H
