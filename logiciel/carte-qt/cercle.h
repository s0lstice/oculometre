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
  @class Cercle : public Zone
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
      @brief constructeur du cercle
      @param Groupe_selection *parent : pointeur sur le groupe contenant cette zone
      */
    Cercle(Groupe_selection *parent);

    /*!
      @fn Cercle::~Cercle()
      @brief destructeur du cercle
      */
    ~Cercle();

    QPointF getCentre();

    /*!
      @fn QPointF Cercle::getCointBD()
      @return QPointF : objet à deux dimantions de Qt, il contient des coordonnées réel
      @brief retourne le coint haut bas droit
      @note En metant dans un carret le cercle, cette fonction renvoie le coint bas droit. \n Utilisé pour le dessin du cercle.
      */
    QPointF getCointBD();

    /*!
      @fn QPointF Cercle::getCointHG()
      @return QPointF : objet à deux dimantions de Qt, il contient des coordonnées réel
      @brief retourne le coint haut gauche du cercle
      @note En metant dans un carret le cercle, cette fonction renvoie le coint haut gauche. \n Utilisé pour le dessin du cercle.
      */
    QPointF getCointHG();

    /*!
      @fn int Cercle::getDiametre()
      @return int : diametre du cercle
      @brief renvoie le diametre du cercle
      */
    int getDiametre();

    /*!
      @fn bool Cercle::positionClick(QPointF point)
      @param QPointF point : position de la souri.
      @return bool : renvoie vrais si tout les valeurs nécessaire pour dessiner le cercle ont été reçu.
      */
    bool positionClick(QPointF point);

    /*!
      @fn QString Cercle::serialisation()
      @QString : chaine de caractaire
      @brief renvoi les parametres de l'objet sous forme texte pour l'exportation.
      */
    QString serialisation();

    /*!
      @fn void Cercle::deserialisation(QString datas)
      @brief initialise l'objet en fonction de la chaine.
      */
    void deserialisation(QString datas);
};

#endif // CERCLE_H
