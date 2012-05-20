/**
 * \file analyse.h
 * \brief classe gérant la mise en relation entre les points de vue des volontaire et les zones.
 * \author Mickael Puret
 *
 * Tous les volontaires sont parcourus. Dès qu'un point appartient à une zone,
 * le vecteur d'appartenance du volontaire est mis à jour et cette information est enregistrée dans une chaine de caractères.
 *
 */
#ifndef ANALYSE_H
#define ANALYSE_H

#include <QStringList>

class Projet;
class Groupe_selection;
class Rectangle;
class Cercle;
class Volontaire;
class Selection;

/*!
  @class Analyse
  @brief Rendu de l'application.
  */
class Analyse
{
private :
    Projet *projet;

    /*!
      @fn void Analyse::appartenance(Volontaire *volontaire, Groupe_selection *group)
      @brief pour le volontaire passé en paramètre, toutes les zones sont testées.
      @param Volontaire *volontaire : pointeur sur un volontaire
      @param Groupe_selection *group : pointeur sur un groupe
      @note La fonction testée est choisie en fonction du type de la zone. Si c'est un groupe de zones alors la fonction (void Analyse::appartenance(Volontaire *volontaire, Groupe_selection *group)) est appellée.
        Les paramètres sont : le volontaire testé et le groupe testé.
      */
    void appartenance(Volontaire *volontaire, Groupe_selection *group);

    /*!
      @fn void Analyse::rectangleTest(Volontaire *volontaire, Rectangle *rectangle)
      @param Volontaire *volontaire : pointeur sur un volontaire
      @param Rectangle *rectangle : pointeur sur une zone de type rectangle
      @brief Teste tous les points du volontaire pour déterminer lesquels font partis du rectangle
      */
    void rectangleTest(Volontaire *volontaire, Rectangle *rectangle);

    /*!
      @fn void Analyse::rectangleTest(Volontaire *volontaire, Rectangle *rectangle)
      @param Volontaire *volontaire : pointeur sur un volontaire
      @param Cercle *cercle : pointeur sur une zone de type cercle
      @brief Teste tous les points du volontaire pour déterminer lesquels font partis du cercle
      */
    void cercleTest(Volontaire *volontaire, Cercle *cercle);

    /*!
      @fn void Analyse::rectangleTest(Volontaire *volontaire, Rectangle *rectangle)
      @param Volontaire *volontaire : pointeur sur un volontaire
      @param Selection *selection : pointeur sur une zone de type sélection
      @brief Teste tous les points du volontaire pour déterminer lesquels font partis de la sélection
      */
    void selectionTest(Volontaire *volontaire, Selection *selection);

public:
    /*!
      @fn Analyse::Analyse(Projet *projet)

      @brief constructeur de l'application.
      @param Projet *projet : projet courant, permet de gérer les zones et les volontaires.
    */
    Analyse(Projet *projet);

    /*!
      @fn Analyse::getData()

      @brief permet de récuperer les données après l'analyse.
      @return QStringList, liste de chaine de caractaires. La première ligne est l'entête de chaque colonne, les autres sont les données.
    */
    QStringList getData();

    /*!
      @fn void Analyse::start()
      @brief initialise la recherche d'appartenance d'un point à une zone
      @note pour chaque volontaire du projet, la fonction appelle (void Analyse::appartenance(Volontaire *volontaire, Groupe_selection *group)).
        Les paramètres sont : le volontaire testé et la racine de l'arbre des zones.
      */
    void start();
};

#endif // ANALYSE_H
