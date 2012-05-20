/**
 * \file analyse.cpp
 * \brief classe gérant la meise en relation entre les points de vue des volontaire et les zones.
 * \author Mickael Puret
 *
 * Tous les volontaires sont parcouruent. Dès qu'un point appartien à une zone,
 * le vecteur d'appartement du volontaire est mis à jour et cette information est enregistré dans une chaine de caracteres.
 *
 */

#include "analyse.h"

#include "projet.h"
#include "groupe_selection.h"
#include "zone.h"
#include "volontaire.h"
#include "rectangle.h"
#include "cercle.h"
#include <QDebug>
#include "selection.h"

#include <cv.h>
#include <highgui.h>

/*!
  @fn Analyse::Analyse(Projet *projet)

  @brief constructeur de l'application.
  @param Projet *projet : projet courant, permet de gérer les zones et les volontaires.
*/
Analyse::Analyse(Projet *projet)
{
    this->projet = projet;
}

/*!
  @fn Analyse::getData()

  @brief permet de récuperer les données apres l'analyse.
  @return QStringList, liste de chaine de carataire. La premire ligne est l'entête de chaque colone, les autres sont les données.
*/
QStringList Analyse::getData()
{
    QVector<Volontaire*> volontaires = projet->get_Volontaires();
    Volontaire *volontaire;
    Volontaire::zone dataZone;
    Volontaire::point dataPoint;
    QStringList data;
    data << "'Nom du projet';'ID volontaire';'ID point oculaire';'x point oculaire';'y point oculaire';'début de la fixation';'durée de la fixation';'ID de la zone';'Label de la zone'";
    foreach(volontaire, volontaires){
        for(int i = 0; i < volontaire->countZone(); ++i){
            dataZone = volontaire->atZone(i);
            dataPoint = volontaire->get_points().at(dataZone.numerotPoint -1);
            data << projet->getName() + ";" + volontaire->getId_Volontaire() + ";" + QString::number(dataPoint.numerot) + ";" + QString::number(dataPoint.x) + ";" + QString::number(dataPoint.y) + ";" + QString::number(dataPoint.debut) + ";" + QString::number(dataPoint.fin) + ";" + QString::number(dataZone.id) + ";" + dataZone.label;
        }
    }

    return data;
}

/*!
  @fn void Analyse::appartenance()
  @brief initialise la recherche d'appartemence d'un point a une zone
  @note pour chaque volontaire du projet, la fonction appelle (void Analyse::appartenance(Volontaire *volontaire, Groupe_selection *group)).
    Les parametres sont : le volontaire testé et la racine de l'arbre des zones.
  */
void Analyse::start(){
    QVector<Volontaire*> volontaires = projet->get_Volontaires();
    Volontaire *volontaire;

    foreach(volontaire, volontaires){
        volontaire->clearZones();
        appartenance(volontaire, projet->getZones());
    }
}

/*!
  @fn void Analyse::appartenance(Volontaire *volontaire, Groupe_selection *group)
  @brief pour le volontaire passé en parametre, toutes les zones sont tésté.
  @param Volontaire *volontaire : pointeur sur un volontaire
  @param Groupe_selection *group : pointeur sur un groupe
  @note La fonction testé est choisi en fonction du type de la zone. Si c'est un groupe de zone alors la fonction (void Analyse::appartenance(Volontaire *volontaire, Groupe_selection *group)) est appellé.
    Les parametres sont : le volontaire testé et le groupe testé.
  */
void Analyse::appartenance(Volontaire *volontaire, Groupe_selection *group){

    QVector<Zone*> zones = group->getZones();
    Zone *zone;

    foreach(zone, zones){
        if(zone->getType() == Zone::composite)
        {
            appartenance(volontaire, (Groupe_selection *)zone);
        }else{
            switch(zone->getType()){
            case Zone::rectangle:
                rectangleTest(volontaire, (Rectangle *)zone);
                break;
            case Zone::cercle:
                cercleTest(volontaire, (Cercle *)zone);
                break;
            case Zone::selection:
                selectionTest(volontaire, (Selection *)zone);
                break;
            case Zone::composite://cas imporbable
                break;
            }
        }
    }
}

/*!
  @fn void Analyse::rectangleTest(Volontaire *volontaire, Rectangle *rectangle)
  @param Volontaire *volontaire : pointeur sur un volontaire
  @param Rectangle *rectangle : pointeur sur une zone de type rectangle
  @brief teste tout les points du volontaire pour determiner les quelles font parties du rectangle
  */
void Analyse::rectangleTest(Volontaire *volontaire, Rectangle *rectangle){

    QVector<Volontaire::point> points;
    Volontaire::point point;

    IplImage * carte = projet->get_carte(); //pour avoir les dimantions
    qreal u_carte_x = (carte->width/2)/20;
    qreal u_carte_y = (carte->height/2)/15;

    qreal recxu = rectangle->getPoints().at(0).x();
    qreal recyu = rectangle->getPoints().at(0).y();
    qreal recxd = rectangle->getPoints().at(1).x();
    qreal recyd = rectangle->getPoints().at(1).y();


    points = volontaire->get_points();
    foreach(point, points){
        qreal pointx = carte->width/2 + u_carte_x*point.x;
        qreal pointy = carte->height/2 + u_carte_y*point.y;

        if((pointx >= recxu)&&(pointx <= recxd)&&(pointy >= recyu)&&(pointy <= recyd)){
            volontaire->appendZone(rectangle->getId(), rectangle->getLable(), point.numerot);
        }
    }
}

/*!
  @fn void Analyse::rectangleTest(Volontaire *volontaire, Rectangle *rectangle)
  @param Volontaire *volontaire : pointeur sur un volontaire
  @param Cercle *cercle : pointeur sur une zone de type cercle
  @brief teste tout les points du volontaire pour determiner les quelles font parties du cercle
  */
void Analyse::cercleTest(Volontaire *volontaire, Cercle *cercle){
    QVector<Volontaire::point> points;
    Volontaire::point point;

    IplImage * carte = projet->get_carte(); //pour avoir les dimantions
    qreal u_carte_x = (carte->width/2)/20;
    qreal u_carte_y = (carte->height/2)/15;

    qreal cerx = cercle->getCentre().x();
    qreal cery = cercle->getCentre().y();

    qreal diametre = cercle->getDiametre();

    points = volontaire->get_points();
    foreach(point, points){

        qreal pointx = carte->width/2 + u_carte_x*point.x;
        qreal pointy = carte->height/2 + u_carte_y*point.y;

        qreal distance = hypot(pointx - cerx, pointy - cery);

        if(distance <= diametre){
            volontaire->appendZone(cercle->getId(), cercle->getLable(), point.numerot);
        }
    }
}

/*!
  @fn void Analyse::rectangleTest(Volontaire *volontaire, Rectangle *rectangle)
  @param Volontaire *volontaire : pointeur sur un volontaire
  @param Selection *selection : pointeur sur une zone de type sélection
  @brief teste tout les points du volontaire pour determiner les quelles font parties de la sélection
  */
void Analyse::selectionTest(Volontaire *volontaire, Selection *selection){
    QVector<Volontaire::point> points;
    Volontaire::point point;

    IplImage * mask = selection->getMask();

    qreal u_carte_x = (mask->width/2)/20;
    qreal u_carte_y = (mask->height/2)/15;

    points = volontaire->get_points();
    foreach(point, points){

        int pointx = mask->width/2 + u_carte_x*point.x;
        int pointy = mask->height/2 + u_carte_y*point.y;

        if(((uchar *)(mask->imageData + ((int)pointx)*mask->widthStep))[((int)pointy)] == 255){
            volontaire->appendZone(selection->getId(), selection->getLable(), point.numerot);
        }
    }
}
