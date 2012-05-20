/**
 * \file myqgraphicsscene.h
 * \brief Surcharge QGraphicsScene pour dessiner des Zones et les points de vue des volontaires.
 * \author Mickael Puret
 *
 */
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

/*!
  @class MyQGraphicsScene : public  QGraphicsScene
  @brief Surcharge QGraphicsScene pour dessiner des Zones et les points de vue des volontaires.
  */
class MyQGraphicsScene : public  QGraphicsScene
{
    Q_OBJECT
private:
    Zone * zone_courante;
    bool creation_encours;
    Zone::type_zone type_creation;
    MainWindow *mainwindow;
    Carte_select *carte_selection;

    /*!
      @fn QPixmap IplImgToPixmap(IplImage *iplImg);
      @param IplImage *iplImg : pointeur sur une image opencv.
      @return QPixmap : un image Qt.
      @brief transforme un IplImage en une QPixmap
      */
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
    /*!
      @fn QGraphicsRectItem *drawRectangle(QPointF pointHG,QPointF pointBD);
      @param QPointF pointHG : coînt haut gauche du rectangle
      @param QPointF pointBD : coînt bas droite du rectangle
      @return QGraphicsRectItem : Item rectangulaire pour un QGraphicsScene
      @brief Initialise un item de type rectangle.
      */
    QGraphicsRectItem *drawRectangle(QPointF pointHG,QPointF pointBD);

    /*!
      @fn QGraphicsEllipseItem *drawCercle(QPointF centre, QPointF exterieur);
      @param QPointF centre : contre du cercle.
      @param QPointF exterieur : un point sur le perimetre.
      @return QGraphicsEllipseItem : Item circulaire pour un QGraphicsScene
      @brief Initialise un item de type circulaire.
      */
    QGraphicsEllipseItem *drawCercle(QPointF centre, QPointF exterieur);

    /*!
      @fn QGraphicsPixmapItem *drawSelection(CvSeq* contour);
      @param vSeq* contour : Sequance opencv represantant le contour d'une zone.
      @return QGraphicsPixmapItem : Item image pour un QGraphicsScene
      @brief L'image represente le contour de la zone.
      */
    QGraphicsPixmapItem *drawSelection(CvSeq* contour);

    //position de dessin
    QPointF positonClick;
    bool stratDraw;

public:
    /*!
      @fn MyQGraphicsScene(QObject *parent = 0);
      @brief Contructeur.
      */
    MyQGraphicsScene(QObject *parent = 0);

    /*!
        @fn void setTool(Carte_select *pcarte_selection);
        @param Carte_select *pcarte_selection : Objet de type Carte_select.
        @brief MyQGraphicsScene necessite des outils telque Carte_select pour le dessin des zones.
      */
    void setTool(Carte_select *pcarte_selection);

    /*!
        @fn void delTool();
        @brief Descative les outils utilisé pour le dessin de zones.
      */
    void delTool();

    /*!
        @fn void activerCreation(Zone::type_zone type);
        @param Zone::type_zone type : Type de la zone à créer.
        @brief Indique qu'une zone de type definit doit etres parametré.
      */
    void activerCreation(Zone::type_zone type);

    /*!
        @fn void desactiverCreation();
        @brief Met fin à la création de la zone.
      */
    void desactiverCreation();

    /*!
        @fn bool getEtatCreation();
        @return bool : Induqe si une creation est en cours.
        @brief retourne vrai si une Zone est en cour de création. Faux sinon.
      */
    bool getEtatCreation();

    /*!
        @fn void setZone_courante(Zone *pzone);
        @param Zone *pzone : Pointeur sur l'ojet en cours d'initialisation.
        @brief Indique la zone à initialiser.
      */
    void setZone_courante(Zone *pzone);

    /*!
        @fn void nullZone_courante();
        @brief Remet à null le pointeur sur la zone à initialiser.
      */
    void nullZone_courante();

    /*!
        @fn void shoowIplImage(IplImage * iplImg);
        @param IplImage * iplImg : image à afficher dans la fenêtre de gestion de carte.
        @brief Affiche l'image dans la fenêtre de la carte.
      */
    void shoowIplImage(IplImage * iplImg);

public slots:

    /*!
        @fn void drawZones(Groupe_selection *zones = NULL);
        @param Groupe_selection *zones = NULL : Racine de l'arbre don les éléments sont à déssiner, Si c'est NULL, tout l'arbre est dessiné.
        @brief Dessine les zones sélectionné.
      */
    void drawZones(Groupe_selection *zones = NULL);

    /*!
        @fn void DrawVolontaires();
        @brief Dessine les volontaires sélectionnés.
      */
    void DrawVolontaires();

protected:
    /*!
      @fn void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );
      @param QGraphicsSceneMouseEvent * mouseEvent :  Evenment de la sourie.
      @brief Envement lors du clique de la sourie.
      */
    void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );

    /*!
      @fn void mouseMoveEvent ( QGraphicsSceneMouseEvent * mouseEvent );
      @param QGraphicsSceneMouseEvent * mouseEvent :  Evenment de la sourie.
      @brief Envement lors du deplacement de la sourie.
      */
    void mouseMoveEvent ( QGraphicsSceneMouseEvent * mouseEvent );

    /*!
      @fn void mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent );
      @param QGraphicsSceneMouseEvent * mouseEvent :  Evenment de la sourie.
      @brief Envement lors du relachement du bouton de la sourie.
      */
    void mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent );
};

#endif // MYQGRAPHICSSCENE_H
