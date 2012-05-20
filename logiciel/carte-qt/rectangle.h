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
  @class class Rectangle : public Zone
  @brief Classe Recangle pour geréer des zones rectangulaires.
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
      @brief Recourne les cordonnées du carrée.\n La premiere valeur du vecteur est un QpointF contement les coodonnées haut gauche. \n La dexieme valeur du vecteur est un QpointF contement les coodonnées bas droit.
      */
    QVector<QPointF> getPoints();

    /*!
      @fn bool positionClick(QPointF point);
      @param QPointF point : position du clic.
      @return bool : indique si d'autre position sont attendus. (flase : il manque des parametres, true : toutes les informations sont presentes.)
      @brief Determine les parametres du rectangle.
      @note Au premier clic, la fonction mémorise la position de la sourie et renvoie false.
        Au dexieme clic, la fonction mémorise les postion de la sourie er renvoie true.
      */
    bool positionClick(QPointF point);

    /*!
      @fn qreal getWidth();
      @return qreal : lageur du renctangle
      @brief renvoie la largeur du rectangle.
      */
    qreal getWidth();

    /*!
      @fn qreal getHeight();
      @return qreal : Hauteur du renctangle
      @brief renvoie la hauteur du rectangle.
      */
    qreal getHeight();

    /*!
      @fn QString serialisation();
      @return QString : chaine comportant les attibuts et leurs valeurs sous la norme JSun.
      @brief : cette chaine ne sérialise que les parametres de la classe Zone et non ceux des enfants.
      */
    virtual QString serialisation();

    /*!
      @fn QString deserialisation(QString datas);
      @param QString datas : chaine comportant les attibuts et leurs valeurs sous la norme JSun.
      @brief : permet l'initialisation des attributs de Zone.
      */
    virtual void deserialisation(QString datas);
};

#endif // POLYGONE_H
