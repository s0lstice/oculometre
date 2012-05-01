#include "myqgraphicsscene.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QVector>

#include "mainwindow.h"
//class MainWindow;
#include "carte_select.h"
//class Carte_select;
#include "projet.h"
#include "volontaire.h"
#include "cercle.h"
#include "rectangle.h"
#include "selection.h"
#include "groupe_selection.h"

MyQGraphicsScene::MyQGraphicsScene(QObject  *parent) : QGraphicsScene(parent)
{
    creation_encours = false;
    mainwindow = qobject_cast<MainWindow*>(parent);

    groupVolontaire = createItemGroup(itemsVolontaire);
    groupVolontaire->setZValue(1);

    groupZone = createItemGroup(itemsZone);
    groupZone->setZValue(2);

    drawZone = createItemGroup(itemDraw);
    drawZone->setZValue(3);
}

/*****************************************************************************/
// Function mousePressEvent
/*****************************************************************************/
void MyQGraphicsScene::mouseMoveEvent ( QGraphicsSceneMouseEvent * mouseEvent ) {

  // Ici on appelle la fonction de gestion de l'événement souris
    //MainWindow *window = qobject_cast<MainWindow*>(mainwindow);
    QString path_carte;
    Projet *pro = mainwindow->getCurent_projet();
    path_carte = pro->get_path_carte();

    //si la selection des couleurs est acctivé
    if(creation_encours == true){
        if(stratDraw == true){
            switch(type_creation){
                case Zone::selection :
                    break;
            case Zone::cercle :{

                        qreal diametre = hypot(mouseEvent->scenePos().x() - x, mouseEvent->scenePos().y() - y);

                        qreal cx = x - diametre;
                        qreal cy = y - diametre;

                        diametre = 2*diametre;

                        QGraphicsEllipseItem *ellipse = new QGraphicsEllipseItem(cx, cy, diametre, diametre);

                        if(itemDraw.size() > 0){
                            QGraphicsItem *item = itemDraw.at(0);
                            itemDraw.clear();
                            drawZone->removeFromGroup(item);
                            itemDraw.removeOne(item);
                            delete item;
                        }

                        itemDraw.append(ellipse);
                        drawZone->addToGroup(ellipse);
                    }
                    break;
                case Zone::rectangle :
                    break;
                case Zone::composite : break; //rien a faire
            }
        }
    }
}

void MyQGraphicsScene::mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent ) {

  // Ici on appelle la fonction de gestion de l'événement souris
    //MainWindow *window = qobject_cast<MainWindow*>(mainwindow);
    QString path_carte;
    Projet *pro = mainwindow->getCurent_projet();
    path_carte = pro->get_path_carte();

    //si la selection des couleurs est acctivé
    if(creation_encours == true){
        switch(type_creation){
            case Zone::selection :
                ((Selection *)zone_courante)->setPerimetre(carte_selection->Selection(mouseEvent->scenePos().x(), mouseEvent->scenePos().y()));
                break;
            case Zone::cercle :
                //save position pour affichage
                if(((Cercle *)zone_courante)->positionClick(mouseEvent->scenePos()) == false){
                    x = mouseEvent->scenePos().x();
                    y = mouseEvent->scenePos().y();
                    stratDraw = true;
                }
                else{

                    //affichage du resultat
                    QGraphicsEllipseItem *ellipse = new QGraphicsEllipseItem(((Cercle *)zone_courante)->getCentre().x(), ((Cercle *)zone_courante)->getCentre().y(), ((Cercle *)zone_courante)->getDiametre(), ((Cercle *)zone_courante)->getDiametre());
                    itemsZone.append(ellipse);
                    groupZone->addToGroup(ellipse);

                    //arret de la gestion des clicks
                    nullZone_courante();
                    desactiverCreation();
                }
                break;
            case Zone::rectangle :
                if(((Rectangle *)zone_courante)->positionClick(mouseEvent->scenePos()) == false){
                    x = mouseEvent->scenePos().x();
                    y = mouseEvent->scenePos().y();
                }
                else{
                    //affichage du resultat
                    qreal x = ((Rectangle *)zone_courante)->getpoints().at(0).x();
                    qreal y = ((Rectangle *)zone_courante)->getpoints().at(0).y();
                    qreal w = ((Rectangle *)zone_courante)->getWidth();
                    qreal h = ((Rectangle *)zone_courante)->getHeight();
                    QGraphicsRectItem *rectangle = new QGraphicsRectItem(x, y, w, h);
                    itemsZone.append(rectangle);
                    groupZone->addToGroup(rectangle);

                    //arret de la gestion des clicks
                    nullZone_courante();
                    desactiverCreation();
                }
                break;
            case Zone::composite : break; //rien a faire
        }
    }
}

void MyQGraphicsScene::setTool(Carte_select *pcarte_selection){
    carte_selection = pcarte_selection;
}

void MyQGraphicsScene::delTool(){
    delete carte_selection;
}

void MyQGraphicsScene::activerCreation(Zone::type_zone type){
    creation_encours = true;
    type_creation = type;
    y = 0;
    x = 0;
    stratDraw = false;
}

void MyQGraphicsScene::desactiverCreation(){
    creation_encours = false;
    stratDraw = false;
}

bool MyQGraphicsScene::getEtatCreation(){
    return creation_encours;
}

void MyQGraphicsScene::setZone_courante(Zone *pzone){
    zone_courante = pzone;
}

void MyQGraphicsScene::nullZone_courante(){
    zone_courante = NULL;
}

//l'appel de cette methode ce fait obligatoirement a null
void MyQGraphicsScene::drawZones(Groupe_selection *zones){
    if(zones == NULL){
        if(mainwindow->creatWindow_Carte() == false){
            return;
        }

        QGraphicsItem *item;
        foreach(item, itemsZone){
            groupZone->removeFromGroup(item);
            itemsZone.removeOne(item);
            delete item;
        }

        Projet *pro = mainwindow->getCurent_projet();
        zones = pro->getZones();
    }
    Zone * child;
    QVector<Zone*> childs = zones->getZones();

    foreach(child, childs){
        if(child->getType() == Zone::composite){
            drawZones((Groupe_selection *)child);
        }else{
            if(child->getDisplayed() == Qt::Checked){
                switch(child->getType()){
                    case Zone::selection :
                        break;
                    case Zone::cercle :{
                            QGraphicsEllipseItem *ellipse = new QGraphicsEllipseItem(((Cercle *)child)->getCentre().x(), ((Cercle *)child)->getCentre().y(), ((Cercle *)child)->getDiametre(), ((Cercle *)child)->getDiametre());
                            itemsZone.append(ellipse);
                            groupZone->addToGroup(ellipse);
                        }
                        break;
                    case Zone::rectangle :{
                            qreal x = ((Rectangle *)child)->getpoints().at(0).x();
                            qreal y = ((Rectangle *)child)->getpoints().at(0).y();
                            qreal w = ((Rectangle *)child)->getpoints().at(1).x() - ((Rectangle *)child)->getpoints().at(0).x();
                            qreal h = ((Rectangle *)child)->getpoints().at(1).y() - ((Rectangle *)child)->getpoints().at(0).y();
                            QGraphicsRectItem *rectangle = new QGraphicsRectItem(x, y, w, h);
                            itemsZone.append(rectangle);
                            groupZone->addToGroup(rectangle);
                        }
                        break;
                    case Zone::composite : break; //rien a faire
                }
            }
        }
    }
}

void MyQGraphicsScene::DrawVolontaires(){
    IplImage *carte;
    float u_carte_x;
    float u_carte_y;
    Volontaire* volontaire;
    QVector<point> v_points;
    point s_point;
    QGraphicsItem *item;

    if(mainwindow->creatWindow_Carte() == false){
        return;
    }

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
