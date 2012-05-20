/**
 * \file projet.h
 * \brief Classe projet definit un projet.
 * \author Mickael Puret
 *
 */

#ifndef PROJET_H
#define PROJET_H

#include "cv.h"

#include <QString>
#include <QVector>
#include <QRegExp>
#include <QDebug>
#include <QStringList>
#include <QVariant>

//#include "groupe_selection.h"
class Groupe_selection;
//#include <Volontaire.h>
class Volontaire;

/*!
  @class projet
  @brief Parametre du projet
  */
class Projet
{
private:
    IplImage *carte;
    QString path_carte;
    QVector<Volontaire*> v_Volontaires;
    Groupe_selection *zones;
    QString name;

public:
    Projet();
    ~Projet();

    /*!
      @fn Groupe_selection *getZones();
      @return Groupe_selection * : renvoie le groupe principale, racine de l'arbre.
      @brief Cette fonction premet d'obtenir la racine de toutes Zones.
      */
    Groupe_selection *getZones();

    /*!
      @fn Volontaire *get_Volontaire(int i);
      @param int i : position du volontaire.
      @return Volontaire * : pointeur sur un volontaire.
      @brief Cette fonction renvoie le volontaire demandé.
    */
    Volontaire *get_Volontaires(int i);

    /*!
      @fn QVector<Volontaire*> get_Volontaires();
      @return QVector<Volontaire*> : Vecteur de volontaire
      @brief Cette fonction renvoie un vecteur avec tous les volontaires
    */
    QVector<Volontaire*> get_Volontaires();

    /*!
      @fn QVector<Volontaire*> *getVolontaires();
      @return QVector<Volontaire*> * : pointeur vers un vecteur de volontaire
      @brief Cette fonction renvoie un pointeur vers un vecteur avec tous les volontaires
    */
    QVector<Volontaire*> *getVolontaires();

    /*!
      @fn void rm_Volontaire(int i);
      @param int i : position du volontaire.
      @brief Cette fonction supprime le volontaire.
    */
    void rm_Volontaire(int i);

    /*!
      @fn int get_nb_Volontaire();
      @return int : nombre de volontaires
      @brief renvoie le nombre de volontaires.
      */
    int get_nb_Volontaire();

    /*!
      @fn void set_carte(QString path, IplImage *image);
      @param QString path : adresse de l'image
      @param IplImage *image : pointeur sur l'instance de l'image au format opencv.
      @brief Initialise les parametres du projet en definissant l'adresse de l'image et possedant un pointeur dessus.
      */
    void set_carte(QString path, IplImage *image);

    /*!
      @fn QString get_path_carte();
      @return QString : adresse de l'image ou une chaine vide.
      @brief renvoie l'adresse de l'image ou une chaine vide.
      */
    QString get_path_carte();

    /*!
      @fn IplImage *get_carte();
      @return IplImage : Pointeur sur l'image au format opencv.
      @brief pointeur sur la carte.
      */
    IplImage *get_carte();

    /*!
      @fn void freeCarte();
      @brief Désaloue la carte.
      */
    void freeCarte();

    /*!
      @fn void charger_Volontaires(QStringList liste_Volontaire);
      @param QStringList liste_Volontaire : liste d'adresse de fichier de volontaires.
      @brief Charge en memoire plusieurs volontaires.
      */
    void charger_Volontaires(QStringList liste_Volontaire);

    /*!
      @fn void supprimer_Volontaire(int row);
      @param int row : position du volontaire a supprimer.
      @brief Supprimer un volontaire.
      */
    void supprimer_Volontaire(int row);

    /*!
      @fn void setName(QString name);
      @param QString name : nom du projet.
      @brief Definit un nom au projet.
      */
    void setName(QString name);

    /*!
      @fn QString getName();
      @return QString : Le nom du projet.
      @brief Renvoie le nom du projet ou une chaine vide si celui-ci n'est pas indiqué.
      */
    QString getName();
};

#endif // PROJET_H
