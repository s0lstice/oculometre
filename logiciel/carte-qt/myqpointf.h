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
  @brief Surcharge QPointF pour permetre la sérialisation et la de-sérialisation
  */
class MyQPointF : public QPointF
{
public:
    /*!
      @fn MyQPointF( const QPoint & point);
      @param const QPoint & point :  un Objet de type QPoint
      @brief Permet la copie d'un QPoint
      */
    MyQPointF( const QPoint & point);

    /*!
      @fn MyQPointF(qreal x, qreal y);
      @param qreal x : coordonnée X a affecter
      @param qreal y : coordonnée Y a affecter
      @brief Initialise l'objet avec les coordonnées passé en parametre.
      */
    MyQPointF(qreal x, qreal y);

    /*!
      @fn MyQPointF(int x, int y);
      @param int x : coordonnée X a affecter
      @param int y : coordonnée Y a affecter
      @brief Initialise l'objet avec les coordonnées passé en parametre.
      */
    MyQPointF(int x, int y);

    /*!
      @fn MyQPointF();
      @brief Constructeur par defaut.
      */
    MyQPointF();

    /*!
      @fn QString serialisation();
      @return QString : chaine comportant les attibuts et leurs valeurs sous la norme JSun.
      @brief : cette chaine ne sérialise que les parametres de la classe Zone et non ceux des enfants.
      */
    QString serialisation();

    /*!
      @fn void deserialisation(QString datas);
      @param QString datas : chaine comportant les attibuts et leurs valeurs sous la norme JSun.
      @brief : permet l'initialisation des attributs de Zone.
      */
    void deserialisation(QString datas);

    /*!
      @fn MyQPointF &operator=(const QPointF point);
      @brief Operateur d'affectation d'un QPointF vers un QPointF.
      */
    MyQPointF &operator=(const QPointF point);
};

#endif // MYQPOINTF_H
