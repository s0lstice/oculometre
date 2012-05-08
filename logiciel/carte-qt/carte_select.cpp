#include "carte_select.h"
#include <QDebug>

//class MainWindow;
#include "mainwindow.h"
#include "projet.h"

using namespace std;

/*
 * Binarisation en fonction de la couleur selectionne
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
    cvZero(img_selection);

    binarisation(img_selection);

    cvAdd(maskSelection,img_selection,maskSelection);

    if(img_selection != NULL)
        cvReleaseImage(&img_selection);

   //cvCopy(maskSelection, mask_contour);
    //detourage du mask
    cvFindContours(maskSelection, storage, &contour, sizeof(CvContour), CV_RETR_LIST );


    return contour;
}

//initialisation de l'outil de selection
Carte_select::Carte_select( MainWindow *parent)
{
    maskSelection = NULL;
    hsv = NULL;
    contour = NULL;
    this->parent = parent;

    Projet * pro = parent->getCurent_projet();

    h = 0, s = 0, v = 0, tolerance = 5;
    image = pro->get_carte();

    hsv = cvCloneImage(image);
    cvCvtColor(image, hsv, CV_BGR2HSV);

    maskSelection = cvCreateImage( cvGetSize(image), 8, 1 );
    cvZero(maskSelection);
}

void Carte_select::setStorage(CvMemStorage *storage)
{
    this->storage = storage;
}

CvSeq *Carte_select::getContour()
{
    return contour;
}

IplImage *Carte_select::getMask()
{
    return maskSelection;
}

//destruction de l'outil de selection
Carte_select::~Carte_select(){
    //Libération de l'IplImage (on lui passe un IplImage**).
    //cvReleaseImage(&maskSelection);
    cvReleaseImage(&hsv);
}
