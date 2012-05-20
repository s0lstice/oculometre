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
      @struct _point
      @typedef point
      @brief Structure d'un point oculaire.
      */
    typedef struct _point{
        int numerot;
        float x;
        float y;
        float debut;
        float fin;
    }point;

    /*!
      @struct _zone
      @typedef zone
      @brief Contient toutes les informations necessaire pour faire le lien entre un point oculaire et une Zone.
      */
    typedef struct _zone{
        int id;
        QString label;
        int numerotPoint;
    }zone;

private:

    Qt::CheckState Displayed;

    QString path_Volontaire;
    QString id_Volontaire;
    QVector<point> v_points;
    QVector<zone> appartenance;
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

    Volontaire(Projet *projet,const QString path);

    QVector<point> get_points();
    QString getPath_Volontaire();
    QString getId_Volontaire();
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
      @fn void appendZone(int id, QString label, int numerotPoint);
      @brief Ajoute une zone d'appartenance.
      @note Chaque volontaire est munie d'un vecteur appartemance de type zone (voir la structure ci dessus). C'est ansi que les points oculaires sont associé à une zone.
      */
    void appendZone(int id, QString label, int numerotPoint);

    /*!
      @fn zone atZone(int i);
      @param int i : position des informations de type zone.
      @brief Renvoie une tructure pour faire la jointure entre les zones et les points oculaire.
      */
    zone atZone(int i);

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
