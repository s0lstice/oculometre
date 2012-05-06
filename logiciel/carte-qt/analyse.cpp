#include "analyse.h"
#include "projet.h"
#include "groupe_selection.h"
#include "zone.h"
#include "volontaire.h"
#include "rectangle.h"
#include "cercle.h"
#include <QDebug>

Analyse::Analyse(Projet *projet)
{
    this->projet = projet;
    data << "Identifiant du volontaire;Numerot du point;Identifiant de la zone;Nom de la zone";

    appartenance();
}

QStringList Analyse::getData()
{
    return data;
}

void Analyse::appartenance(){
    QVector<Volontaire*> volontaires = projet->get_Volontaire();
    Volontaire *volontaire;

    foreach(volontaire, volontaires){
        volontaire->clearZones();
        appartenance(volontaire, projet->getZones());
    }
}

void Analyse::appartenance(Volontaire *volontaire, Groupe_selection *group){

    QVector<Zone*> zones = group->getGroupe();
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
                break;
            case Zone::composite://cas imporbable
                break;
            }
        }
    }
}

void Analyse::rectangleTest(Volontaire *volontaire, Rectangle *rectangle){

    QVector<Volontaire::point> points;
    Volontaire::point point;

    IplImage * carte = projet->get_carte(); //pour avoir les dimantions
    qreal u_carte_x = (carte->width/2)/20;
    qreal u_carte_y = (carte->height/2)/15;

    qreal recxu = rectangle->getpoints().at(0).x();
    qreal recyu = rectangle->getpoints().at(0).y();
    qreal recxd = rectangle->getpoints().at(1).x();
    qreal recyd = rectangle->getpoints().at(1).y();


    points = volontaire->get_points();
    foreach(point, points){
        qreal pointx = carte->width/2 + u_carte_x*point.x;
        qreal pointy = carte->height/2 + u_carte_y*point.y;

        if((pointx >= recxu)&&(pointx <= recxd)&&(pointy >= recyu)&&(pointy <= recyd)){
            volontaire->appendZone(rectangle->getId(), rectangle->getLable(), point.numerot);
            //qDebug() << "rectangle find" << "" << volontaire->getId_Volontaire() << " " << rectangle->getId() << " " << rectangle->getLable() << " " << point.numerot;

            data << volontaire->getId_Volontaire() + ";"  + QString::number(point.numerot) + ";" + QString::number(rectangle->getId()) + ";" + rectangle->getLable();
        }
    }
}

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
            //qDebug() << "cercle find" << "" << volontaire->getId_Volontaire() << " " << cercle->getId() << " " << cercle->getLable() << " " << point.numerot;

            data << volontaire->getId_Volontaire() + ";"  + QString::number(point.numerot) + ";" + QString::number(cercle->getId()) + ";" + cercle->getLable();
        }
    }
}
