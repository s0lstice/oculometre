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

    int h, l, s, tolerance;
    bool color_change;
    IplImage *image;
    IplImage *maskSelection;
    IplImage *image_trace;
    IplImage *hls;
    CvSeq* contour;
    MainWindow *parent;
    CvMemStorage* storage;

    /*!
      @fn void Carte_select::binarisation(IplImage *image)
      @param IplImage *image : pointeur sur l'image à binariser
      @brief Binarisation en fonction de la couleur selectionne, la couleur fait partie des parametre de la classe.
     */
    void binarisation(IplImage *image);

public:

    /*!
     @fn Carte_select::Carte_select(Projet * projet)
     @param Projet * projet : pointeur sur le projet pour recupere la carte courante
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
      @param int x : coordonée x de la couleur cherché
      @param int y : coordonée y de la couleur cherché
      @return CvSeq * pointeur sur une sequance d'opencv.
      @brief isole la couleur selectionné, si ce n'est pas la prmeiere selection, la couleur est ajouter au reste de la sélection.
      */
    CvSeq *Selection(int x, int y);

    /*!
      @fn void Carte_select::setStorage(CvMemStorage *storage)
      @brief initialise l'espace memoire de la sequance pour cette sélection
      */
    void setStorage(CvMemStorage* storage);

    /*!
      @fn CvSeq *Carte_select::getContour()
      @return CvSeq * : sequance opencv
      @brief retourne la zone selectionné
      */
    CvSeq* getContour();

    /*!
      @fn IplImage *Carte_select::getMask()
      @return IplImage * : IplImage opencv
      @brief retourne le masque de la selection
      */
    IplImage* getMask();

};

#endif // CARTE_SELECT_H
