#ifndef MYQGRAPHICSSCENE_H
#define MYQGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMenu>

#include <cv.h>
#include <highgui.h>

#include "zone.h"
//class Zone;
//#include "mainwindow.h"
class MainWindow;
//#include "carte_select.h"
class Carte_select;


class MyQGraphicsScene : public  QGraphicsScene
{
    Q_OBJECT
private:
    Zone * zone_courante;
    bool creation_encours;
    Zone::type_zone type_creation;
    MainWindow *mainwindow;
    Carte_select *carte_selection;

    QPixmap IplImgToPixmap(IplImage *iplImg);

    //couche d'items (pixmap 0; groupVolontaire 1; groupZone 2)
        //couche volontaires
    QList<QGraphicsItem *> itemsVolontaire;
    QGraphicsItemGroup * groupVolontaire;
        //couche zones
    QList<QGraphicsItem *> itemsZone;
    QGraphicsItemGroup * groupZone;
        //couche draw
    QList<QGraphicsItem *> itemDraw;
    QGraphicsItemGroup * drawZone;

    //draw item
    QGraphicsRectItem *drawRectangle(QPointF pointHG,QPointF pointBD);
    QGraphicsEllipseItem *drawCercle(QPointF centre, QPointF exterieur);
    QGraphicsPixmapItem *drawSelection(CvSeq* contour);

    //position de dessin
    QPointF positonClick;
    bool stratDraw;

public:

    MyQGraphicsScene(QObject *parent = 0);

    void setTool(Carte_select *pcarte_selection);
    void delTool();
    void activerCreation(Zone::type_zone type);
    void desactiverCreation();
    bool getEtatCreation();
    void setZone_courante(Zone *pzone);
    void nullZone_courante();
    void shoowIplImage(IplImage * iplImg);

public slots:
    void drawZones(Groupe_selection *zones = NULL);
    void DrawVolontaires();

protected:
    void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );
    void mouseMoveEvent ( QGraphicsSceneMouseEvent * mouseEvent );
    void mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent );
};

#endif // MYQGRAPHICSSCENE_H
