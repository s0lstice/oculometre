/**
 * \file volontaire.h
 * \brief Classe definissant un volontaire.
 * \author Mickael Puret
 *
 */

#ifndef POINT_H
#define POINT_H

#include <QString>
#include <QVector>

#include <QVariant>

class Projet;

/*!
  @class Volontaire
  @brief Objet volontaire
  */
class Volontaire
{

public :
    /*!
      @struct _fixation
      @typedef fixation
      @brief Structure d'une fixation oculaire.
      */
    typedef struct _fixation{
        int numerot;
        float x;
        float y;
        float debut;
        float duree;
    }fixation;

    /*!
      @struct _zone
      @typedef zone
      @brief Contient toutes les informations necessaire pour faire le lien entre un point oculaire et une Zone.
      */
    typedef struct _jointure{
        int id; /*! identifiant de la Zone */
        int numerotPoint; /*! identifiant de la fixation */
    }jointure;

private:

    Qt::CheckState Displayed;

    QString path_Volontaire;
    QString id_Volontaire;
    QVector<fixation> v_points;
    QVector<jointure> appartenance;
    Projet *projet;

    /*!
      @fn void charger_points();
      @brief Ouvre le fichier passé en parametre du constructeur, le parce et construit un vecteur de point oculaire pour ce Volontaire.
      */
    void charger_points();

    /*!
      @fn void charger_points();
      @brief Recupaire le nom du volontaire de puis le nom du fichier.
      @note il faut metre une securité sur le nom du projet. Le volontaire ne doit pas etre chargé dans un projet differant que celui associé au volontaire.
      */
    void path_VolontaireToId_Volontaire();

public:

    /*!
      @brief Constructeur
      @param projet : projet au quel est rataché le volontaire
      @param path : adresse du fichier du colontaire
      */
    Volontaire(Projet *projet, const QString path);

    /*!
      @brief Renvoie la trajectoire oculaire
      @return Verteur contenant toutes le fixation du volontaire.
      */
    QVector<fixation> get_fixations();

    /*!
      @return Adresse du fichier du colontaire
      @brief Renvoie l'adresse du fichier du colontaire
      */
    QString getPath_Volontaire();

    /*!
      @return Le nom du volonatire
      @brief Revoie le nom du volontaire
      */
    QString getId_Volontaire();

    /*!
      @return Checked : le volontaire est coché; sinon Unchecked
      @brief Indique l'etat du volontaire
      */
    Qt::CheckState getDisplayed();

    /*!
        @fn void setDisplayed(Qt::CheckState valeur);
        @param : Qt::CheckState valeur : (enumeration Qt) Coche ou décoche le Volontaire.
        @brief Coche ou décoche le Volontaire.
    */
    void setDisplayed(Qt::CheckState valeur);

    /*!
        @fn void switchEtat();
        @brief Inverse l'etat du Volontaire (coché/décoché).
    */
    void switchEtat();

    /*!
      @fn void appendZone(int id, int numerotPoint);
      @brief Ajoute une zone d'appartenance.
      @note Chaque volontaire est munie d'un vecteur appartemance de type zone (voir la structure ci dessus). C'est ansi que les points oculaires sont associé à une zone.
      */
    void appendZone(int id, int numerotPoint);

    /*!
      @fn zone atZone(int i);
      @param int i : position des informations de type zone.
      @brief Renvoie une tructure pour faire la jointure entre les zones et les points oculaire.
      */
    jointure atZone(int i);

    /*!
      @fn void clearZones();
      @brief Efface le vecteur contenant les informations sur les zones associées au points.
      */
    void clearZones();

    /*!
      @fn int countZone();
      @return int : nombre d'élément dans le vecteur.
      @brief Indique le nombre d'élément du vecteur.
      */
    int countZone();

};

#endif // POINT_H
