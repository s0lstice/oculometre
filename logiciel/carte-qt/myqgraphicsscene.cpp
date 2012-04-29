#include "myqgraphicsscene.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QVector>

#include "zone.h"
//class Zone;
#include "mainwindow.h"
//class MainWindow;
#include "carte_select.h"
//class Carte_select;
#include "projet.h"
#include "volontaire.h"

MyQGraphicsScene::MyQGraphicsScene(QObject  *parent) : QGraphicsScene(parent)
{
    selection_zone = false;
    mainwindow = qobject_cast<MainWindow*>(parent);

    groupVolontaire = createItemGroup(itemsVolontaire);
    groupVolontaire->setZValue(1);

    groupZone = createItemGroup(itemsZone);
    groupZone->setZValue(2);
}

/*****************************************************************************/
// Function mousePressEvent
/*****************************************************************************/
void MyQGraphicsScene::mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent ) {

  // Ici on appelle la fonction de gestion de l'événement souris
    //MainWindow *window = qobject_cast<MainWindow*>(mainwindow);
    QString path_carte;
    Projet *pro = mainwindow->getCurent_projet();
    path_carte = pro->get_path_carte();

    //si la selection des couleurs est acctivé
    if(selection_zone == true){
      carte_selection->Selection(mouseEvent->scenePos().x(), mouseEvent->scenePos().y());
    }
}

void MyQGraphicsScene::setCarte_selection(Carte_select *pcarte_selection){
    carte_selection = pcarte_selection;
}

void MyQGraphicsScene::delCarte_selection(){
    delete carte_selection;
}

void MyQGraphicsScene::setSelection_zone(bool value){
    selection_zone = value;
}

bool MyQGraphicsScene::getSelection_zone(){
    return selection_zone;
}

void MyQGraphicsScene::setZone_courante(Zone *pzone){
    zone_courante = pzone;
}

void MyQGraphicsScene::nullZone_courante(){
    zone_courante = NULL;
}

void MyQGraphicsScene::DrowVolontaires(){
    IplImage *carte;
    float u_carte_x;
    float u_carte_y;
    Volontaire* volontaire;
    QVector<point> v_points;
    point s_point;
    QGraphicsItem *item;

    Projet *pro = mainwindow->getCurent_projet();
    QVector<Volontaire*> v_Volontaires = pro->get_Volontaire();

    carte = pro->get_carte(); //pour avoir les dimantions
    u_carte_x = (carte->width/2)/20;
    u_carte_y = (carte->height/2)/15;

    foreach(item, itemsVolontaire){
        groupVolontaire->removeFromGroup(item);
        itemsVolontaire.removeOne(item);
        delete item;
    }

    foreach(volontaire, v_Volontaires){
        if(volontaire->getDisplayed() == Qt::Checked){
            v_points = volontaire->get_points();

            foreach(s_point, v_points){
                QGraphicsEllipseItem *ellipse = new QGraphicsEllipseItem(carte->width/2 + u_carte_x*s_point.x, carte->height/2 + u_carte_y*s_point.y, 2*u_carte_x,2*u_carte_x);
                itemsVolontaire.append(ellipse);
                groupVolontaire->addToGroup(ellipse);
            }
        }
    }
    qDebug() << groupVolontaire->childItems().size();
    groupVolontaire->update();
}

//afichage de l'image, a metre dans MyQGraphicssene ?
void  MyQGraphicsScene::shoowIplImage(IplImage *iplImg)
{
    int h = iplImg->height;
    int w = iplImg->width;
    int channels = iplImg->nChannels;
    QImage qimg(w, h, QImage::Format_ARGB32);
    char *data = iplImg->imageData;

    for (int y = 0; y < h; y++, data += iplImg->widthStep)
    {
        for (int x = 0; x < w; x++)
        {
        char r, g, b, a = 0;
        if (channels == 1)
        {
            r = data[x * channels];
            g = data[x * channels];
            b = data[x * channels];
        }
        else if (channels == 3 || channels == 4)
        {
            r = data[x * channels + 2];
            g = data[x * channels + 1];
            b = data[x * channels];
        }

        if (channels == 4)
        {
            a = data[x * channels + 3];
            qimg.setPixel(x, y, qRgba(r, g, b, a));
        }
        else
        {
            qimg.setPixel(x, y, qRgb(r, g, b));
        }
        }
    }

    mainwindow->getCarteScene()->addPixmap(QPixmap::fromImage(qimg));
}
