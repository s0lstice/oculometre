/**
 * \file cercle.h
 * \brief Classe cercle du composite pattern de la gestion des zones. Elle definit un cercle et herite de Zone.
 * \author Mickael Puret
 *
 */

#ifndef CERCLE_H
#define CERCLE_H

#include "zone.h"
#include <QPoint>
#include <QPointF>

//class MyQPointF;
#include "myqpointf.h"

class Groupe_selection;

/*!
  @class Cercle : Public Zone
  @brief Définit une zone circulaire.
  */
class Cercle : public Zone
{
private:
    MyQPointF centre;
    MyQPointF cointBD;
    MyQPointF cointHG;

    int diametre;
    int nb_poisitions;

public:

    /*!
      @fn Cercle::Cercle(Groupe_selection *parent) : Zone(parent)
      @brief Constructeur du cercle
      @param Groupe_selection *parent : pointeur sur le groupe contenant cette zone
      */
    Cercle(Groupe_selection *parent);

    /*!
      @fn Cercle::~Cercle()
      @brief Destructeur du cercle
      */
    ~Cercle();

    QPointF getCentre();

    /*!
      @fn QPointF Cercle::getCointBD()
      @return QPointF : Objet à deux dimentions de Qt, il contient des coordonnées réelles
      @brief Retourne le coin haut bas droit
      @note En mettant le cercle dans un carré , cette fonction renvoie le coin bas droit. \n Utilisé pour le dessin du cercle.
      */
    QPointF getCointBD();

    /*!
      @fn QPointF Cercle::getCointHG()
      @return QPointF : Objet à deux dimentions de Qt, il contient des coordonnées réelles
      @brief Retourne le coin haut gauche du cercle
      @note En mettant le cercle dans un carré, cette fonction renvoie le coint haut gauche. \n Utilisé pour le dessin du cercle.
      */
    QPointF getCointHG();

    /*!
      @fn int Cercle::getDiametre()
      @return int : Diamètre du cercle
      @brief Renvoie le diamètre du cercle
      */
    int getDiametre();

    /*!
      @fn bool Cercle::positionClick(QPointF point)
      @param QPointF point : Position de la souris.
      @return bool : Renvoie vrai si toutes les valeurs nécessaires pour dessiner le cercle ont été reçues.
      */
    bool positionClick(QPointF point);

    /*!
      @fn QString Cercle::serialisation()
      @QString : Chaine de caractères
      @brief Renvoie les paramètres de l'objet sous forme texte pour l'exportation.
      */
    QString serialisation();

    /*!
      @fn void Cercle::deserialisation(QString datas)
      @brief Initialise l'objet en fonction de la chaine.
      */
    void deserialisation(QString datas);
};

#endif // CERCLE_H
