/**
 * \file groupe_selection.h
 * \brief Classe composite du composite pattern de la gestion des zones, dérive de Zone.
 * \author Mickael Puret
 *
 */
#ifndef GROUPE_SELECTION_H
#define GROUPE_SELECTION_H

#include "zone.h"
#include <QVector>

#include <QVariant>
class Projet;

/*!
  @class Groupe_selection : Public Zone
  @brief Gestion des groupes dans les zones.
  */
class Groupe_selection : public Zone
{
private:
    QVector<Zone *> groupe;

public:
    /*!
      @fn Groupe_selection(Groupe_selection *parent);
      @param Groupe_selection *parent : Zone parent.
      @brief Constructeur.
      @note Groupe_selection *parent est NULL si et seulement si l'objet créé est le premier élément de l'arbre.
      */
    Groupe_selection(Groupe_selection *parent);
    /*!
      @fn ~Groupe_selection();
      @brief Destructeur
      */
    ~Groupe_selection();

    /*!
      @fn Zone *child(int i);
      @param int i : Position de la zone demandée dans le vecteur.
      @return Zone *: Une Zone.
      @brief Retourne la Zone demandée.
      */
    Zone *child(int i);

    /*!
      @fn Zone *child(int i);
      @param int i : Position de la zone demandée dans le vecteur.
      @return Zone *: Une Zone.
      @brief Retourne la Zone demandée.
      */
    void appendChild(Zone *zone);

    /*!
      @fn QVector<Zone*> getZones();
      @return QVector<Zone*> : Vecteur de Zones.
      @brief Retourne un vecteur avec toutes les zones du groupe.
      */
    QVector<Zone*> getZones();

    /*!
      @fn void appendChilds(QVector<Zone*> zone);
      @brief Ajoute une Zone au vecteur.
      */
    void appendChilds(QVector<Zone*> zone);

    /*!
      @fn int childCount() const;
      @return Nombre de Zones
      @brief Indique le nombre de Zones dans le groupe.
      */
    int childCount() const;

    /*!
      @fn void removeChild(Zone *zone);
      @param Zone *zone : Zone à supprimer
      @brief Retire la Zone désignée du vecteur.
      */
    void removeChild(Zone *zone);

    /*!
      @fn int size();
      @return int : Nombre de Zones.
      @brief Indique le nombre de Zones du groupe et des sous-groupes.
      */
    int size();

    /*!
      @fn QString serialisation();
      @return QString : Chaine contenant toutes les valeurs des attributs au format JSun.
      @brief Permet de sauvegarder la Zone.
      */
    QString serialisation();

    /*!
      @fn void deserialisation(QString datas, Projet *pro);
      @param QString : Chaine contenant toutes les valeurs des attributs au format JSun.
      @brief Permet de charger une Zone
      */
    void deserialisation(QString datas, Projet *pro);
};

#endif // GROUPE_SELECTION_H
