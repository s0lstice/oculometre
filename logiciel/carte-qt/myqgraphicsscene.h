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
class Rectangle;
class Cercle;
class Selection;

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
      @param IplImage *iplImg : Pointeur sur une image opencv.
      @return QPixmap : Une image Qt.
      @brief Transforme une IplImage en une QPixmap
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
      @param QPointF pointHG : Coin haut gauche du rectangle
      @param QPointF pointBD : Coin bas droit du rectangle
      @return QGraphicsRectItem : Item rectangulaire pour un QGraphicsScene
      @brief Initialise un item de type rectangle.
      */
    QGraphicsRectItem *drawRectangle(QPointF pointHG,QPointF pointBD);

    /*!
      @fn GraphicsRectItem *drawRectangle(Rectangle rectangle);
      @param Rectangle rectangle : objet a dessiner
      @return QGraphicsRectItem : Item rectangulaire pour un QGraphicsScene
      @brief Initialise un item de type rectangle.
      */
    QGraphicsRectItem *drawRectangle(Rectangle *rectangle);

    /*!
      @fn QGraphicsEllipseItem *drawCercle(QPointF centre, QPointF exterieur);
      @param QPointF centre : Centre du cercle.
      @param QPointF exterieur : Un point sur le périmètre.
      @return QGraphicsEllipseItem : Item circulaire pour un QGraphicsScene
      @brief Initialise un item de type circulaire.
      */
    QGraphicsEllipseItem *drawCercle(QPointF centre, QPointF exterieur);

    /*!
      @fn QGraphicsEllipseItem *drawCercle(Cercle cercle);
      @param Cercle cercle : objet a dessiner
      @return QGraphicsEllipseItem : Item circulaire pour un QGraphicsScene
      @brief Initialise un item de type circulaire.
      */
    QGraphicsEllipseItem *drawCercle(Cercle *cercle);

    /*!
      @fn QGraphicsPixmapItem *drawSelection(CvSeq* contour);
      @param CvSeq* contour : Séquence opencv représantant le contour d'une zone.
      @return QGraphicsPixmapItem : Item image pour un QGraphicsScene
      @brief L'image représente le contour de la zone.
      */
    QGraphicsPixmapItem *drawSelection(CvSeq* contour);

    /*!
      @fn QGraphicsPixmapItem *drawSelection(Selection *selection);
      @param Selection *selection : objet a dessiner.
      @return QGraphicsPixmapItem : Item image pour un QGraphicsScene
      @brief L'image represente le contour de la zone.
      */
    QGraphicsPixmapItem * drawSelection(Selection *selection);
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
        @brief MyQGraphicsScene Nécessite des outils tels que Carte_select pour le dessin des zones.
      */
    void setTool(Carte_select *pcarte_selection);

    /*!
        @fn void delTool();
        @brief Désactive les outils utilisés pour le dessin de zones.
      */
    void delTool();

    /*!
        @fn void activerCreation(Zone::type_zone type);
        @param Zone::type_zone type : Type de la zone à créer.
        @brief Indique qu'une zone de type défini doit être paramétrée.
      */
    void activerCreation(Zone::type_zone type);

    /*!
        @fn void desactiverCreation();
        @brief Met fin à la création de la zone.
      */
    void desactiverCreation();

    /*!
        @fn bool getEtatCreation();
        @return bool : Indique si une création est en cours.
        @brief Retourne vrai si une Zone est en cours de création. Faux sinon.
      */
    bool getEtatCreation();

    /*!
        @fn void setZone_courante(Zone *pzone);
        @param Zone *pzone : Pointeur sur l'objet en cours d'initialisation.
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
        @param IplImage * iplImg : Image à afficher dans la fenêtre de gestion de carte.
        @brief Affiche l'image dans la fenêtre de la carte.
      */
    void shoowIplImage(IplImage * iplImg);

public slots:

    /*!
        @fn void drawZones(Groupe_selection *zones = NULL);
        @param Groupe_selection *zones = NULL : Racine de l'arbre dont les éléments sont à dessiner, Si c'est NULL, tout l'arbre est dessiné.
        @brief Dessine les zones sélectionnées.
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
      @param QGraphicsSceneMouseEvent * mouseEvent :  Evènement de la souris.
      @brief Envènement lors du clic de la souris.
      */
    void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );

    /*!
      @fn void mouseMoveEvent ( QGraphicsSceneMouseEvent * mouseEvent );
      @param QGraphicsSceneMouseEvent * mouseEvent :  Evènement de la souris.
      @brief Envènement lors du déplacement de la souris.
      */
    void mouseMoveEvent ( QGraphicsSceneMouseEvent * mouseEvent );

    /*!
      @fn void mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent );
      @param QGraphicsSceneMouseEvent * mouseEvent :  Envènement de la souris.
      @brief Envènement lors du relachement du bouton de la souris.
      */
    void mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent );
};

#endif // MYQGRAPHICSSCENE_H
