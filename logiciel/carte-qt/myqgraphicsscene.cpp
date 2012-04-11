#include "myqgraphicsscene.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

#include "zone.h"
//class Zone;
#include "mainwindow.h"
//class MainWindow;
#include "carte_select.h"
//class Carte_select;
#include "projet.h"

MyQGraphicsScene::MyQGraphicsScene(QObject  *parent) : QGraphicsScene(parent)
{
    mainwindow = qobject_cast<MainWindow*>(parent);
}

/*****************************************************************************/
// Function mousePressEvent
/*****************************************************************************/
void MyQGraphicsScene::mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent ) {

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
