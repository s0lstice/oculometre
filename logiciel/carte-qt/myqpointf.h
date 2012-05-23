/**
 * \file mytreezonemodel.h
 * \brief Surcharge QPointF pour permetre la sérialisation et la de-sérialisation.
 * \author Mickael Puret
 *
 */
#ifndef MYQPOINTF_H
#define MYQPOINTF_H

#include <QPointF>

/*!
  @class MyQPointF : public QPointF
  @brief Surcharge QPointF pour permettre la sérialisation et la de-sérialisation
  */
class MyQPointF : public QPointF
{
public:
    /*!
      @fn MyQPointF( const QPoint & point);
      @param const QPoint & point :  Un objet de type QPoint
      @brief Permet la copie d'un QPoint
      */
    MyQPointF( const QPoint & point);

    /*!
      @fn MyQPointF(qreal x, qreal y);
      @param qreal x : Coordonnée X à affecter
      @param qreal y : Coordonnée Y à affecter
      @brief Initialise l'objet avec les coordonnées passées en paramètre.
      */
    MyQPointF(qreal x, qreal y);

    /*!
      @fn MyQPointF(int x, int y);
      @param int x : Coordonnée X à affecter
      @param int y : Coordonnée Y à affecter
      @brief Initialise l'objet avec les coordonnées passées en paramètre.
      */
    MyQPointF(int x, int y);

    /*!
      @fn MyQPointF();
      @brief Constructeur par défaut.
      */
    MyQPointF();

    /*!
      @fn QString serialisation();
      @return QString : Chaine comportant les attibuts et leurs valeurs sous la norme JSun.
      @brief : Cette chaine ne sérialise que les paramètres de la classe Zone et non ceux des enfants.
      */
    QString serialisation();

    /*!
      @fn void deserialisation(QString datas);
      @param QString datas : Chaine comportant les attibuts et leurs valeurs sous la norme JSun.
      @param Projet *pro : Projet courant. Nécessaire pour la création du masque.
      @brief : Permet l'initialisation des attributs de Zone.
      */
    void deserialisation(QString datas);

    /*!
      @fn MyQPointF &operator=(const QPointF point);
      @brief Opérateur d'affectation d'un QPointF vers un QPointF.
      */
    MyQPointF &operator=(const QPointF point);
};

#endif // MYQPOINTF_H
