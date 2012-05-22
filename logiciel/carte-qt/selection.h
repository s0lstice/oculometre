/**
 * \file selection.h
 * \brief Classe selection du composite pattern de la gestion des zones. Elle definit une selection de couleur et herite de Zone.
 * \author Mickael Puret
 *
 */

#ifndef SELECTION_H
#define SELECTION_H

#include <cv.h>

#include "zone.h"
#include "myqpointf.h"

class Carte_select;
class Groupe_selection;
class Projet;
/*!
  @class Sélection
  @brief Etant la classe Zone en lui permettant de gérer la sélection d'une couleur.
  */
class Selection : public Zone
{
protected:
    CvSeq *contour;
    CvMemStorage* storage;
    IplImage* mask;

public:
    /*!
      @fn Selection(Groupe_selection *parent);
      @param Groupe_selection *parent : Zone parent de type Groupe_selection.
      @brief Constructeur de la sélection.
      */
    Selection(Groupe_selection *parent);

    /*!
      @fn ~Selection();
      @brief Destructeur de sélection.
      */
    ~Selection();

    /*!
      @fn void setPerimetre(CvSeq *contour);
      @param CvSeq *contour : Séquence opencv pour la gestion de contour.
      @brief Initialise le contour de la sélection.
      */
    void setPerimetre(CvSeq *contour);

    /*!
      @fn CvSeq * getPerimetre();
      @return CvSeq * : Séquence opencv pour la gestion de contour.
      @brief Renvoie le contour de la sélection.
      */
    CvSeq * getPerimetre();

    /*!
      @fn CvMemStorage* getStorage();
      @return CvMemStorage * : Mémoire opencv pour la gestion de séquence.
      @brief Renvoie la memoire permetant la gestion de la séquence de cette sélection.
      */
    CvMemStorage* getStorage();

    /*!
      @fn void setStorage(CvMemStorage * storage);
      @param CvMemStorage * storage : Mémoire opencv pour la gestion de séquence.
      @brief Initialise la mémoire permetant la gestion de la séquence de cette sélection.
      */
    void setStorage(CvMemStorage * storage);

    /*!
      @fn void setMask(IplImage* mask);
      @param IplImag * mask : Image opencv. Cette image est monochrome et est codée sur un canal.
      @brief Initialise le mask permetant de déterminier l'appartenance d'un point à la sélection.
    */
    void setMask(IplImage* mask);

    /*!
      @fn IplImage *getMask();
      @return IplImag * : Image opencv. Cette image est monochrome et est codée sur un canal.
      @brief Renvoie le mask permetant de déterminier l'appartenance d'un point à la sélection.
    */
    IplImage *getMask();

    /*!
      @fn QString serialisation();
      @return QString : Chaine comportant les attibuts et leurs valeurs sous la norme JSun.
      @brief : Cette chaine ne sérialise que les paramètres de la classe Zone et non ceux des enfants.
      */
    QString serialisation();

    /*!
      @fn void deserialisation(QString datas, Projet *pro);
      @param QString datas : Chaine comportant les attibuts et leurs valeurs sous la norme JSun.
      @param Projet *pro : Projet courant. Nécessaire pour la création du masque.
      @brief : Permet l'initialisation des attributs de Zone.
      */
    void deserialisation(QString datas, Projet *pro);

};

#endif // SELECTION_H
