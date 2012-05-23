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
  @brief Classe parente du composit pattern, definit les attributs communs.
  */
class Zone
{
public:
    /*!
      @enum _type_zone
      @typedef type_zone
      @brief Differant type de Zone possible.
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
      @param Groupe_selection *parent : Groupe partant de cette Zone.
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
      @brief Renvoi l'identifiant de la zone
      */
    int getId();

    /*!
      @fn type_zone getType();
      @brief Renvoi le type de la zone
      */
    type_zone getType();

    /*!
      @fn QString getLable();
      @brief Renvoi le nom de la zone.
      */
    QString getLable();

    /*!
      @fn void setLabel(QString label);
      @param QString label : nom de la zone.
      @brief Definit le nom de la Zone.
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
      @return int : position de la Zone dans le vecteur parent.
      @brief Renvoie la position de la Zone dans la vecteur parent.
      */
    int row() const;

    /*!
        @fn Qt::CheckState getDisplayed();
        @return Qt::CheckState : enumeration Qt, indique si la Zone est coché ou non.
        @brief Indique si la Zone est coché ou non.
    */
    Qt::CheckState getDisplayed();

    /*!
        @fn void setDisplayed(Qt::CheckState valeur);
        @param : Qt::CheckState valeur : (enumeration Qt) Coche ou décoche la Zone.
        @brief Coche ou décoche la Zone.
    */
    void setDisplayed(Qt::CheckState valeur);

    /*!
      @fn void switchEtat();
      @brief Inverse l'etat de la Zone (coché/décoché).
      */
    void switchEtat();

    /*!
      @fn int size();
      @brief Indique que la zone ne contient pas d'enfant.
      */
    int size(){return 0;}

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

protected:
    int id;
    type_zone type;
    QString label;
    Groupe_selection *parent;
    Qt::CheckState displayed;

    /*!
      @fn QString sub_serialisation();
      @return QString : chaine comportant les attibuts et leurs valeurs sous la norme JSun.
      @brief : cette sous-chaine ne comporte pas les acolade de debut et de fin.
      */
    QString sub_serialisation();

};
#endif // ZONE_H
