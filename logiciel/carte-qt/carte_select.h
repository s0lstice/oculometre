/**
 * \file carte_select.h
 * \brief Classe permetant la selection des couleur sur une carte.
 * \author Mickael Puret
 *
 * Determine un masque et une sequance de point en fonction de la zone cliqué.
 *
 */

#ifndef CARTE_SELECT_H
#define CARTE_SELECT_H

#include <cv.h>
#include <highgui.h>
#include <QString>
#include <QMessageBox>
#include <QThread>
#include <QMutex>

//#include "mainwindow.h"
class MainWindow;
class Projet;

/*!
  @class Carte_select
  @brief Gestion de la sélection d'une ou plusieurs couleurs.
  */
class Carte_select
{
private:

    int h, s, v, tolerance;
    bool color_change;
    IplImage *image;
    IplImage *maskSelection;
    IplImage *image_trace;
    IplImage *hsv;
    CvSeq* contour;
    MainWindow *parent;
    CvMemStorage* storage;

    /*!
      @fn void Carte_select::binarisation(IplImage *image)
      @param IplImage *image : Pointeur sur l'image à binariser
      @brief Binarisation en fonction de la couleur sélectionnée, la couleur fait partie des paramètres de la classe.
     */
    void binarisation(IplImage *image);

public:

    /*!
     @fn Carte_select::Carte_select(Projet * projet)
     @param Projet * projet : Pointeur sur le projet pour récupérer la carte courante
     @brief Constructeur de la classe
      */
    Carte_select(Projet *projet);

    /*!
      @fn Carte_select::~Carte_select()
      @brief destructeur
      */
    ~Carte_select();

    /*!
      @fn CvSeq *Carte_select::Selection(int x, int y)
      @param int x :Coordonée x de la couleur cherchée
      @param int y : Coordonée y de la couleur cherchée
      @return CvSeq * pointeur sur une séquence d'opencv.
      @brief Isole la couleur sélectionnée, si ce n'est pas la première sélection, la couleur est ajoutée au reste de la sélection.
      */
    CvSeq *Selection(int x, int y);

    /*!
      @fn void Carte_select::setStorage(CvMemStorage *storage)
      @brief Initialise l'espace mémoire de la séquence pour cette sélection
      */
    void setStorage(CvMemStorage* storage);

    /*!
      @fn CvSeq *Carte_select::getContour()
      @return CvSeq * : Séquence opencv
      @brief Retourne la zone sélectionnée
      */
    CvSeq* getContour();

    /*!
      @fn IplImage *Carte_select::getMask()
      @return IplImage * : IplImage opencv
      @brief Retourne le masque de la sélection
      */
    IplImage* getMask();

};

#endif // CARTE_SELECT_H
