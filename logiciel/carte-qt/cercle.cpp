/**
 * \file cercle.cpp
 * \brief Calsse fille de Zone. Elle definit un cercle.
 * \author Mickael Puret
 *
 */

#include "cercle.h"
#include "groupe_selection.h"
#include <math.h>
#include <QDebug>

#include "myqpointf.h"

/*!
  @fn Cercle::Cercle(Groupe_selection *parent) : Zone(parent)
  @brief constructeur du cercle
  @param Groupe_selection *parent : pointeur sur le groupe contenant cette zone
  */
Cercle::Cercle(Groupe_selection *parent) : Zone(parent)
{
    type = Zone::cercle;
    cointHG = MyQPointF(-1,-1);
    cointBD = MyQPointF(-1,-1);
    label = QObject::tr("Cercle ") + QString::number(id);
}

/*!
  @fn Cercle::~Cercle()
  @brief destructeur du cercle
  */
Cercle::~Cercle(){
}

/*!
  @fn QPointF Cercle::getCentre()
  @return QPointF : objet a deux dimantion de Qt, il contient des coordonnées réel
  @brief retourne le centre du cercle
  */
QPointF Cercle::getCentre(){
    return QPointF(centre.x(), centre.y());
}

/*!
  @fn QPointF Cercle::getCointHG()
  @return QPointF : objet à deux dimantions de Qt, il contient des coordonnées réel
  @brief retourne le coint haut gauche du cercle
  @note En metant dans un carret le cercle, cette fonction renvoie le coint haut gauche. \n Utilisé pour le dessin du cercle.
  */
QPointF Cercle::getCointHG(){
    return QPointF(cointHG.x(), cointHG.y());
}

/*!
  @fn QPointF Cercle::getCointBD()
  @return QPointF : objet à deux dimantions de Qt, il contient des coordonnées réel
  @brief retourne le coint haut bas droit
  @note En metant dans un carret le cercle, cette fonction renvoie le coint bas droit. \n Utilisé pour le dessin du cercle.
  */
QPointF Cercle::getCointBD(){
    return QPointF(cointBD.x(), cointBD.y());
}

/*!
  @fn int Cercle::getDiametre()
  @return int : diametre du cercle
  @brief renvoie le diametre du cercle
  */
int Cercle::getDiametre(){
    return diametre;
}

/*!
  @fn bool Cercle::positionClick(QPointF point)
  @param QPointF point : position de la souri.
  @return bool : renvoie vrais si tout les valeurs nécessaire pour dessiner le cercle ont été reçu.
  */
bool Cercle::positionClick(QPointF point){
    if(cointHG.x() == -1){
        cointHG = point;
        return false;
    }
    else{
        cointBD = point;
        diametre = hypot(cointBD.x() - centre.x(), cointBD.y() - centre.y());

        centre = QPointF(cointHG.x() - diametre, cointHG.y() - diametre);

        diametre = 2*diametre;
        return true;
    }
    return true;
}

/*!
  @fn QString Cercle::serialisation()
  @QString : chaine de caractaire
  @brief renvoi les parametres de l'objet sous forme texte pour l'exportation.
  */
QString Cercle::serialisation()
{
    return "{" + Zone::sub_serialisation() + ",chg=" + cointHG.serialisation() + ",cbd=" + cointBD.serialisation() + ",centre=" + centre.serialisation() + ",diametre=" + QString::number(diametre) + "}";
}

/*!
  @fn void Cercle::deserialisation(QString datas)
  @brief initialise l'objet en fonction de la chaine.
  */
void Cercle::deserialisation(QString datas)
{
}
