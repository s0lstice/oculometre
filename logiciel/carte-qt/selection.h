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
  @class Selection
  @brief Etant la classe Zone en lui permetant de gérer la selection d'une couleur.
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
      @brief Constructeur de la Selection.
      */
    Selection(Groupe_selection *parent);

    /*!
      @fn ~Selection();
      @brief Destructeur de Selection.
      */
    ~Selection();

    /*!
      @fn void setPerimetre(CvSeq *contour);
      @param CvSeq *contour : sequance opencv pour la gestion de contour.
      @brief Initialise le contour de la Selection
      */
    void setPerimetre(CvSeq *contour);

    /*!
      @fn CvSeq * getPerimetre();
      @return CvSeq * : sequance opencv pour la gestion de contour.
      @brief Rencoir le contour de la Selection
      */
    CvSeq * getPerimetre();

    /*!
      @fn CvMemStorage* getStorage();
      @return CvMemStorage * : memoire opencv pour la gestion de sequance.
      @brief Renvoie la memoire permetant la gestion de la sequance de cette Selection.
      */
    CvMemStorage* getStorage();

    /*!
      @fn void setStorage(CvMemStorage * storage);
      @param CvMemStorage * storage : memoire opencv pour la gestion de sequance.
      @brief initialise la memoire permetant la gestion de la sequance de cette Selection.
      */
    void setStorage(CvMemStorage * storage);

    /*!
      @fn void setMask(IplImage* mask);
      @param IplImag * mask : Image opencv. Cette image est monochome et est codé sur un canal.
      @brief Initialise le mask permetant de determinier l'appartenance d'un point a la Selection.
    */
    void setMask(IplImage* mask);

    /*!
      @fn IplImage *getMask();
      @return IplImag * : Image opencv. Cette image est monochome et est codé sur un canal.
      @brief Renvoie le mask permetant de determinier l'appartenance d'un point a la Selection.
    */
    IplImage *getMask();

    /*!
      @fn QString serialisation();
      @return QString : chaine comportant les attibuts et leurs valeurs sous la norme JSun.
      @brief : cette chaine ne sérialise que les parametres de la classe Zone et non ceux des enfants.
      */
    QString serialisation();

    /*!
      @fn void deserialisation(QString datas, Projet *pro);
      @param QString datas : chaine comportant les attibuts et leurs valeurs sous la norme JSun.
      @param Projet *pro : Projet courant. Necessaire pour la creation du masque.
      @brief : permet l'initialisation des attributs de Zone.
      */
    void deserialisation(QString datas, Projet *pro);

};

#endif // SELECTION_H
