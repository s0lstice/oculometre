#ifndef MYQGRAPHICSSCENE_H
#define MYQGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMenu>

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

public:
    MyQGraphicsScene(QObject *parent = 0);

    void setCarte_selection(Carte_select *pcarte_selection);
    void delCarte_selection();
    void setSelection_zone(bool value);
    bool getSelection_zone();
    void setZone_courante(Zone *pzone);
    void nullZone_courante();

protected:
    void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );
};

#endif // MYQGRAPHICSSCENE_H
