/**
 * \file zone.h
 * \brief Classe parente du composit pattern.
 * \author Mickael Puret
 *
 */
#ifndef ZONE_H
#define ZONE_H

#include <QString>
#include <QVariant>
#include <QVector>

class Groupe_selection;

/*!
  @class Zone
  @brief Classe parente du composit pattern, définit les attributs communs.
  */
class Zone
{
public:
    /*!
      @enum _type_zone
      @typedef type_zone
      @brief Différents types de Zone possible.
      */
    typedef enum _type_zone
       {
        selection,
        cercle,
        rectangle,
        composite
       }type_zone;

    /*!
      @fn Zone(Groupe_selection *parent);
      @param Groupe_selection *parent : Groupe parent de cette Zone.
      @brief DConstructeur de la Zone.
      */
    Zone(Groupe_selection *parent);

    /*!
      @fn virtual ~Zone();
      @brief DConstructeur de la Zone.
      */
    virtual ~Zone();

    /*!
      @fn int getId();
      @brief Renvoie l'identifiant de la zone
      */
    int getId();

    /*!
      @fn type_zone getType();
      @brief Renvoie le type de la zone
      */
    type_zone getType();

    /*!
      @fn QString getLable();
      @brief Renvoie le nom de la zone.
      */
    QString getLable();

    /*!
      @fn void setLabel(QString label);
      @param QString label : Nom de la zone.
      @brief Définit le nom de la Zone.
      */
    void setLabel(QString label);

    /*!
      @fn Groupe_selection *getParent();
      @return Groupe_selection * : Zone parent.
      @brief Indique la Zone parent.
      */
    Groupe_selection *getParent();

    /*!
      @fn int row() const;
      @return int : Position de la Zone dans le vecteur parent.
      @brief Renvoie la position de la Zone dans le vecteur parent.
      */
    int row() const;

    /*!
        @fn Qt::CheckState getDisplayed();
        @return Qt::CheckState : énumération Qt, indique si la Zone est cochée ou non.
        @brief Indique si la Zone est cochée ou non.
    */
    Qt::CheckState getDisplayed();

    /*!
        @fn void setDisplayed(Qt::CheckState valeur);
        @param : Qt::CheckState valeur : (énumération Qt) Coche ou décoche la Zone.
        @brief Coche ou décoche la Zone.
    */
    void setDisplayed(Qt::CheckState valeur);

    /*!
      @fn void switchEtat();
      @brief Inverse l'état de la Zone (cochée/décochée).
      */
    void switchEtat();

    /*!
      @fn int size();
      @brief Indique que la zone ne contient pas d'enfant.
      */
    int size(){return 0;}

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

protected:
    int id;
    type_zone type;
    QString label;
    Groupe_selection *parent;
    Qt::CheckState Displayed;

    /*!
      @fn QString sub_serialisation();
      @return QString : Chaine comportant les attibuts et leurs valeurs sous la norme JSun.
      @brief : Cette sous-chaine ne comporte pas les accolades de début et de fin.
      */
    QString sub_serialisation();

};
#endif // ZONE_H
