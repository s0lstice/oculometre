#include "myqgraphicsscene.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "mainwindow.h"
#include "carte_select.h"
#include "projet.h"
MyQGraphicsScene::MyQGraphicsScene(QObject  *parent) : QGraphicsScene(parent)
{
    mainwindow = parent;
}

/*****************************************************************************/
// Function mousePressEvent
/*****************************************************************************/
void MyQGraphicsScene::mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent ) {

  // Ici on appelle la fonction de gestion de l'événement souris
    MainWindow *window = qobject_cast<MainWindow*>(mainwindow);
    QString path_carte;
    projet *pro = projet::proj();
    path_carte = pro->get_path_carte();

    if(window->getSelection_zone() == true){
      carte_select zone(path_carte, mouseEvent->scenePos().x(), mouseEvent->scenePos().y(), window);

    }
}
