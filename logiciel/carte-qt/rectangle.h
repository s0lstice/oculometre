/**
 * \file rectangle.h
 * \brief Classe rectangle du composite pattern de la gestion des zones. Elle definit un recangle et herite de Zone.
 * \author Mickael Puret
 *
 */

#ifndef POLYGONE_H
#define POLYGONE_H

#include "zone.h"
#include <QPointF>
#include <QVector>
#include "myqpointf.h"

class Groupe_selection;

/*!
  @class class Rectangle : Public Zone
  @brief Classe Rectangle pour géréer des zones rectangulaires.
  */
class Rectangle : public Zone
{
private:
    MyQPointF point_haut_gauche;
    MyQPointF point_bas_droit;
    int nb_poisitions;

public:
    /*!
      @fn Rectangle(Groupe_selection *parent);
      @param Groupe_selection *parent : Zone parent de type Groupe_selection.
      @brief Constructeur de Recantgle.
      */
    Rectangle(Groupe_selection *parent);

    /*!
      @fn  ~Rectangle();
      @brief Destructeur de Rectangle.
      */
    ~Rectangle();

    /*!
      @fn QVector<QPointF> getPoints();
      @return QVector<QPointF> : deux QPointF dans un vecteur.
      @brief Retourne les cordonnées du carré.\n La première valeur du vecteur est un QpointF contenant les coodonnées haut gauche. \n La deuxième valeur du vecteur est un QpointF contenant les coodonnées bas droit.
      */
    QVector<QPointF> getPoints();

    /*!
      @fn bool positionClick(QPointF point);
      @param QPointF point : Position du clic.
      @return bool : Indique si d'autres positions sont attendues. (flase : il manque des paramètres, true : toutes les informations sont présentes.)
      @brief Détermine les paramètres du rectangle.
      @note Au premier clic, la fonction mémorise la position de la souris et renvoie false.
        Au deuxième clic, la fonction mémorise les positions de la souris et renvoie true.
      */
    bool positionClick(QPointF point);

    /*!
      @fn qreal getWidth();
      @return qreal : Largeur du renctangle
      @brief Renvoie la largeur du rectangle.
      */
    qreal getWidth();

    /*!
      @fn qreal getHeight();
      @return qreal : Hauteur du renctangle
      @brief Renvoie la hauteur du rectangle.
      */
    qreal getHeight();

    /*!
      @fn QString serialisation();
      @return QString : Chaine comportant les attibuts et leurs valeurs sous la norme JSun.
      @brief : Cette chaine ne sérialise que les paramètres de la classe Zone et non ceux des enfants.
      */
    virtual QString serialisation();

    /*!
      @fn QString deserialisation(QString datas);
      @param QString datas : Chaine comportant les attibuts et leurs valeurs sous la norme JSun.
      @brief : Permet l'initialisation des attributs de Zone.
      */
    virtual void deserialisation(QString datas);
};

#endif // POLYGONE_H
