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
class Zone;

/*!
  @class Projet
  @brief Paramètre du projet
  */
class Projet
{
private:
    IplImage *carte;
    QString path_carte;
    QVector<Volontaire*> v_Volontaires;
    Groupe_selection *zones;
    QString name;

    /*!
      @fn Zone * getZoneById(Groupe_selection * groupe, int id);
      @param Groupe_selection * groupe : racine de l'arbre dans le quel faire la recherche.
      @param int id : identifiant de la zone recherché.
      @return Zone * : La zone trouvé, NULL sinon.
      @brief Cette fonction parcour un arbre a la recheche d'une zone.
      */
    Zone * getZoneById(Groupe_selection * groupe, int id);

public:
    Projet();
    ~Projet();

    /*!
      @fn Groupe_selection *getZones();
      @return Groupe_selection * : Renvoie le groupe principal, racine de l'arbre.
      @brief Cette fonction permet d'obtenir la racine de toutes les Zones.
      */
    Groupe_selection *getZones();

    Zone * getZoneById(int id);

    /*!
      @fn Volontaire *get_Volontaire(int i);
      @param int i : Position du volontaire.
      @return Volontaire * : Pointeur sur un volontaire.
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
      @return QVector<Volontaire*> * : Pointeur vers un vecteur de volontaires
      @brief Cette fonction renvoie un pointeur vers un vecteur avec tous les volontaires
    */
    QVector<Volontaire*> *getVolontaires();

    /*!
      @fn void rm_Volontaire(int i);
      @param int i : Position du volontaire.
      @brief Cette fonction supprime le volontaire.
    */
    void rm_Volontaire(int i);

    /*!
      @fn int get_nb_Volontaire();
      @return int : Nombre de volontaires
      @brief Renvoie le nombre de volontaires.
      */
    int get_nb_Volontaire();

    /*!
      @fn void set_carte(QString path, IplImage *image);
      @param QString path : Adresse de l'image
      @param IplImage *image : Pointeur sur l'instance de l'image au format opencv.
      @brief Initialise les paramètres du projet en définissant l'adresse de l'image et possédant un pointeur dessus.
      */
    void set_carte(QString path, IplImage *image);

    /*!
      @fn QString get_path_carte();
      @return QString : Adresse de l'image ou une chaine vide.
      @brief Renvoie l'adresse de l'image ou une chaine vide.
      */
    QString get_path_carte();

    /*!
      @fn IplImage *get_carte();
      @return IplImage : Pointeur sur l'image au format opencv.
      @brief Pointeur sur la carte.
      */
    IplImage *get_carte();

    /*!
      @fn void freeCarte();
      @brief Désaloue la carte.
      */
    void freeCarte();

    /*!
      @fn void charger_Volontaires(QStringList liste_Volontaire);
      @param QStringList liste_Volontaire : Liste d'adresses du fichier de volontaires.
      @brief Charge en mémoire plusieurs volontaires.
      */
    void charger_Volontaires(QStringList liste_Volontaire);

    /*!
      @fn void supprimer_Volontaire(int row);
      @param int row : Position du volontaire à supprimer.
      @brief Supprimer un volontaire.
      */
    void supprimer_Volontaire(int row);

    /*!
      @fn void setName(QString name);
      @param QString name : Nom du projet.
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
