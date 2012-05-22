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
      @brief Contient toutes les informations nécessaires pour faire le lien entre un point oculaire et une zone.
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
      @brief Ouvre le fichier passé en paramètre du constructeur, le charge et construit un vecteur de point oculaire pour ce volontaire.
      */
    void charger_points();

    /*!
      @fn void charger_points();
      @brief Recupère le nom du volontaire depuis le nom du fichier.
      @note Il faut mettre une sécurité sur le nom du projet. Le volontaire ne doit pas être chargé dans un projet différent de celui associé au volontaire.
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
        @param : Qt::CheckState valeur : (énumération Qt) Coche ou décoche le volontaire.
        @brief Coche ou décoche le volontaire.
    */
    void setDisplayed(Qt::CheckState valeur);

    /*!
        @fn void switchEtat();
        @brief Inverse l'état du volontaire (coché/décoché).
    */
    void switchEtat();

    /*!
      @fn void appendZone(int id, QString label, int numerotPoint);
      @brief Ajoute une zone d'appartenance.
      @note Chaque volontaire est muni d'un vecteur d'appartenance de type zone (voir la structure ci-dessus). C'est ansi que les points oculaires sont associés à une zone.
      */
    void appendZone(int id, QString label, int numerotPoint);

    /*!
      @fn zone atZone(int i);
      @param int i : Position des informations de type zone.
      @brief Renvoie une structure pour faire la jointure entre les zones et les points oculaires.
      */
    zone atZone(int i);

    /*!
      @fn void clearZones();
      @brief Efface le vecteur contenant les informations sur les zones associées aux points.
      */
    void clearZones();

    /*!
      @fn int countZone();
      @return int : Nombre d'éléments dans le vecteur.
      @brief Indique le nombre d'éléments du vecteur.
      */
    int countZone();

};

#endif // POINT_H
