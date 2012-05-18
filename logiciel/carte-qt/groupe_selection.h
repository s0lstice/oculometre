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
  @class Groupe_selection : public Zone
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
      @note Groupe_selection *parent et NULL si et seulment si l'objet créé et le premier élement de l'arbre.
      */
    Groupe_selection(Groupe_selection *parent);
    /*!
      @fn ~Groupe_selection();
      @brief Destructeur
      */
    ~Groupe_selection();

    /*!
      @fn Zone *child(int i);
      @param int i : position de la zone demandé dans le vecteur.
      @return Zone *: Une Zone.
      @brief Retourne la Zone demandé.
      */
    Zone *child(int i);

    /*!
      @fn Zone *child(int i);
      @param int i : position de la zone demandé dans le vecteur.
      @return Zone *: Une Zone.
      @brief Retourne la Zone demandé.
      */
    void appendChild(Zone *zone);

    /*!
      @fn QVector<Zone*> getZones();
      @return QVector<Zone*> : Veteur de Zones.
      @brief Retourne un vecteur avec toutes les zones du groupe.
      */
    QVector<Zone*> getZones();

    /*!
      @fn void appendChilds(QVector<Zone*> zone);
      @brief Ajoute une Zone au vcteur.
      */
    void appendChilds(QVector<Zone*> zone);

    /*!
      @fn int childCount() const;
      @return Nombre de Zones
      @brief indique le nombre de Zone dans le groupe.
      */
    int childCount() const;

    /*!
      @fn void removeChild(Zone *zone);
      @param Zone *zone : Zone a supprimer
      @brief Retir la Zone designé du vecteur.
      */
    void removeChild(Zone *zone);

    /*!
      @fn int size();
      @return int : nombre de Zones.
      @brief indique le nombre de Zone du groupe et des sous-groupe.
      */
    int size();

    /*!
      @fn QString serialisation();
      @return QString : Chaine contenant toutes les valeurs des attribus au format JSun.
      @brief Permet de sauvgarder la Zone.
      */
    QString serialisation();

    /*!
      @fn void deserialisation(QString datas, Projet *pro);
      @param QString : Chaine contenant toutes les valeurs des attribus au format JSun.
      @brief permet de charger une Zone
      */
    void deserialisation(QString datas, Projet *pro);
};

#endif // GROUPE_SELECTION_H
