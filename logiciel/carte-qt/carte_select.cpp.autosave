/**
 * \file carte_select.cpp
 * \brief Classe permetant la selection des couleur sur une carte.
 * \author Mickael Puret
 *
 * Determine un masque et une sequance de point en fonction de la zone cliqué.
 *
 */

#include "carte_select.h"
#include <QDebug>

//class MainWindow;
#include "mainwindow.h"
#include "projet.h"

using namespace std;

/*!
  @fn void Carte_select::binarisation(IplImage *image)
  @param IplImage *image : pointeur sur l'image à binariser
  @brief Binarisation en fonction de la couleur selectionne, la couleur fait partie des parametre de la classe.
 */
void Carte_select::binarisation(IplImage *image) {

    //IplImage *hsv;
    IplConvKernel *kernel;

    // We create the mask
    cvInRangeS(hsv, cvScalar(h - tolerance -1, s - tolerance, 0), cvScalar(h + tolerance -1, s + tolerance, 255), image);

    // Create kernels for the morphological operation
    kernel = cvCreateStructuringElementEx(5, 5, 2, 2, CV_SHAPE_ELLIPSE);

    // Morphological opening (inverse because we have white pixels on black background)
    cvDilate(image, image, kernel, 1);
    cvErode(image, image, kernel, 1);

    // We release the memory of kernels
    cvReleaseStructuringElement(&kernel);
}

/*!
  @fn CvSeq *Carte_select::Selection(int x, int y)
  @param int x : coordonée x de la couleur cherché
  @param int y : coordonée y de la couleur cherché
  @return CvSeq * pointeur sur une sequance d'opencv.
  @brief isole la couleur selectionné, si ce n'est pas la prmeiere selection, la couleur est ajouter au reste de la sélection.
  */
//sequance de points, definissant un contour, en fonction de la couleur se trouvant a la position x y
CvSeq *Carte_select::Selection(int x, int y){
    CvScalar pixel;

    //couleur a la position donne
    pixel = cvGet2D(hsv, y, x);
    h = (int)pixel.val[0];
    s = (int)pixel.val[1];
    v = (int)pixel.val[2];

    //definitntion du mask
    IplImage *img_selection = cvCreateImage( cvGetSize(image), 8, 1 );
    IplImage *mask_contour = cvCreateImage( cvGetSize(image), 8, 1 );
    cvZero(img_selection);

    binarisation(img_selection);

    cvAdd(maskSelection,img_selection,maskSelection);

    if(img_selection != NULL)
        cvReleaseImage(&img_selection);

    cvCopy(maskSelection, mask_contour);
    //detourage du mask
    cvFindContours(mask_contour, storage, &contour, sizeof(CvContour), CV_RETR_LIST );
    cvReleaseImage(&mask_contour);

    return contour;
}

/*!
 @fn Carte_select::Carte_select(Projet * projet)
 @param Projet * projet : pointeur sur le projet pour recupere la carte courante
 @brief Constructeur de la classe
  */
//initialisation de l'outil de selection
Carte_select::Carte_select(Projet * projet)
{
    maskSelection = NULL;
    hsv = NULL;
    contour = NULL;
    this->parent = parent;

    h = 0, s = 0, v = 0, tolerance = 5;
    image = projet->get_carte();

    hsv = cvCloneImage(image);
    cvCvtColor(image, hsv, CV_BGR2HSV);

    maskSelection = cvCreateImage( cvGetSize(image), 8, 1 );
    cvZero(maskSelection);
}

/*!
  @fn void Carte_select::setStorage(CvMemStorage *storage)
  @brief initialise l'espace memoire de la sequance pour cette sélection
  */
void Carte_select::setStorage(CvMemStorage *storage)
{
    this->storage = storage;
}

/*!
  @fn CvSeq *Carte_select::getContour()
  @return CvSeq * : sequance opencv
  @brief retourne la zone selectionné
  */
CvSeq *Carte_select::getContour()
{
    return contour;
}

/*!
  @fn IplImage *Carte_select::getMask()
  @return IplImage * : IplImage opencv
  @brief retourne le masque de la selection
  */
IplImage *Carte_select::getMask()
{
    return maskSelection;
}

/*!
  @fn Carte_select::~Carte_select()
  @brief destructeur
  */
Carte_select::~Carte_select(){
    //Libération de l'IplImage (on lui passe un IplImage**).
    //cvReleaseImage(&maskSelection);
    cvReleaseImage(&hsv);
}
