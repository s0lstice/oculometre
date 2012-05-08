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
                        QGraphicsEllipseItem *ellipse = drawCercle(positonClick, mouseEvent->scenePos());

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
                    case Zone::rectangle :{

                        QGraphicsRectItem *rectangle = drawRectangle(positonClick, mouseEvent->scenePos());

                        if(itemDraw.size() > 0){
                            QGraphicsItem *item = itemDraw.at(0);
                            itemDraw.clear();
                            drawZone->removeFromGroup(item);
                            itemDraw.removeOne(item);
                            delete item;
                        }

                        itemDraw.append(rectangle);
                        drawZone->addToGroup(rectangle);
                    }
                    break;
                case Zone::composite : break; //rien a faire
            }
        }
    }
}

void MyQGraphicsScene::mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent ){
    mousePressEvent ( mouseEvent );
}

void MyQGraphicsScene::mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent ) {

  // Ici on appelle la fonction de gestion de l'événement souris
    //MainWindow *window = qobject_cast<MainWindow*>(mainwindow);
    QString path_carte;
    Projet *pro = mainwindow->getCurent_projet();
    path_carte = pro->get_path_carte();

    //si la selection des couleurs est acctivé
    if(creation_encours == true){
        switch(type_creation){
            case Zone::selection :{
                carte_selection->setStorage(((Selection *)zone_courante)->getStorage());
                CvSeq* contour = carte_selection->Selection(mouseEvent->scenePos().x(), mouseEvent->scenePos().y());
                ((Selection *)zone_courante)->setPerimetre(contour);
                ((Selection *)zone_courante)->setMask(carte_selection->getMask());

                QGraphicsPixmapItem * pixmap = drawSelection(contour);

                if(itemDraw.size() > 0){
                    QGraphicsItem *item = itemDraw.at(0);
                    itemDraw.clear();
                    drawZone->removeFromGroup(item);
                    itemDraw.removeOne(item);
                    delete item;
                }

                itemDraw.append(pixmap);
                drawZone->addToGroup(pixmap);
            }
            break;
            case Zone::cercle :
                //save position pour affichage
                if(((Cercle *)zone_courante)->positionClick(mouseEvent->scenePos()) == false){
                    positonClick = mouseEvent->scenePos();
                    stratDraw = true;
                }
                else{

                    //affichage du resultat
                    QGraphicsEllipseItem *ellipse = drawCercle(((Cercle *)zone_courante)->getCointHG(), ((Cercle *)zone_courante)->getCointBD());
                    itemsZone.append(ellipse);
                    groupZone->addToGroup(ellipse);

                    //arret de la gestion des clicks
                    stratDraw = false;

                    if(itemDraw.size() > 0){
                        QGraphicsItem *item = itemDraw.at(0);
                        itemDraw.clear();
                        drawZone->removeFromGroup(item);
                        itemDraw.removeOne(item);
                        delete item;
                    }

                    nullZone_courante();
                    desactiverCreation();
                }
                break;
            case Zone::rectangle :
                if(((Rectangle *)zone_courante)->positionClick(mouseEvent->scenePos()) == false){
                    positonClick = mouseEvent->scenePos();
                    stratDraw = true;
                }
                else{
                    //affichage du resultat
                    QGraphicsRectItem *rectangle = drawRectangle(((Rectangle *)zone_courante)->getpoints().at(0),((Rectangle *)zone_courante)->getpoints().at(1));
                    itemsZone.append(rectangle);
                    groupZone->addToGroup(rectangle);

                    //arret de la gestion des clicks
                    stratDraw = false;

                    if(itemDraw.size() > 0){
                        QGraphicsItem *item = itemDraw.at(0);
                        itemDraw.clear();
                        drawZone->removeFromGroup(item);
                        itemDraw.removeOne(item);
                        delete item;
                    }

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
}

void MyQGraphicsScene::desactiverCreation(){
    if(type_creation == Zone::selection)
    {
        if(itemDraw.size() > 0){
            QGraphicsItem *item = itemDraw.at(0);

            itemsZone.append(item);
            groupZone->addToGroup(item);

            drawZone->removeFromGroup(item);
            itemDraw.removeOne(item);
        }
    }
    creation_encours = false;
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
                    case Zone::selection :{
                            QGraphicsPixmapItem * pixmap = drawSelection(((Selection *)child)->getPerimetre());

                            itemsZone.append(pixmap);
                            groupZone->addToGroup(pixmap);
                        }
                        break;
                    case Zone::cercle :{
                            QGraphicsEllipseItem *ellipse = drawCercle(((Cercle *)child)->getCointHG(), ((Cercle *)child)->getCointBD());
                            itemsZone.append(ellipse);
                            groupZone->addToGroup(ellipse);
                        }
                        break;
                    case Zone::rectangle :{
                            QGraphicsRectItem *rectangle = drawRectangle(((Rectangle *)child)->getpoints().at(0),((Rectangle *)child)->getpoints().at(1));
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

QGraphicsRectItem *MyQGraphicsScene::drawRectangle(QPointF pointHG,QPointF pointBD){
    qreal x = pointHG.x();
    qreal y = pointHG.y();
    qreal w = pointBD.x() - x;
    qreal h = pointBD.y() - y;
    return new QGraphicsRectItem(x, y, w, h);
}

QGraphicsEllipseItem *MyQGraphicsScene::drawCercle(QPointF centre, QPointF exterieur){

    qreal diametre = hypot(exterieur.x() - centre.x(), exterieur.y() - centre.y());

    qreal x = centre.x() - diametre;
    qreal y = centre.y() - diametre;

    diametre = 2*diametre;

    return new QGraphicsEllipseItem(x, y, diametre, diametre);
}

QGraphicsPixmapItem *MyQGraphicsScene::drawSelection(CvSeq* contour){
    Projet *pro = mainwindow->getCurent_projet();
    IplImage* contourImg = cvCreateImage( cvGetSize(pro->get_carte()), 8, 4 );

    cvZero( contourImg );

    CvScalar red = cvScalar(0,0,255,255);

    CvScalar blue = cvScalar(255,0,0,255);

    for( CvSeq* c=contour; c!=NULL; c=c->h_next ){
        cvDrawContours(
            contourImg,
            c,
            red,		// Red
            blue,		// Blue
            0.1,        // Vary max_level and compare results
            1,
            8 );
    }

    QPixmap image = IplImgToPixmap(contourImg);
    cvReleaseImage(&contourImg);

    return new QGraphicsPixmapItem(image);
}

void MyQGraphicsScene::DrawVolontaires(){
    IplImage *carte;
    float u_carte_x;
    float u_carte_y;
    Volontaire* volontaire;
    QVector<Volontaire::point> v_points;
    Volontaire::point s_point;
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

    groupVolontaire->update();
}

//afichage de l'image, a metre dans MyQGraphicssene ?

QPixmap MyQGraphicsScene::IplImgToPixmap(IplImage *iplImg){
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

    return QPixmap::fromImage(qimg);
}

void  MyQGraphicsScene::shoowIplImage(IplImage *iplImg)
{
    mainwindow->getCarteScene()->addPixmap(IplImgToPixmap(iplImg));
}
