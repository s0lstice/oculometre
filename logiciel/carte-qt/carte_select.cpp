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
    CvMemStorage* storage = cvCreateMemStorage();
    CvScalar pixel;

    //couleur a la position donne
    pixel = cvGet2D(hsv, y, x);
    h = (int)pixel.val[0];
    s = (int)pixel.val[1];
    v = (int)pixel.val[2];

    //masque rouge et bleu
    //CvScalar red = CV_RGB(250,0,0);
    //CvScalar blue = CV_RGB(0,0,250);

    //definitntion du mask
    IplImage *img_selection = cvCreateImage( cvGetSize(image), 8, 1 );
    IplImage *mask_contour = cvCreateImage( cvGetSize(image), 8, 1 );
    binarisation(img_selection);

    cvAdd(mask,img_selection,mask);

    if(img_selection != NULL)
        cvReleaseImage(&img_selection);

    cvCopy(mask,mask_contour);
    //detourage du mask
    cvFindContours(mask_contour, storage, &first_contour, sizeof(CvContour), CV_RETR_LIST );

    cvReleaseImage(&mask_contour);
/*
    if(image_trace != NULL)
        cvReleaseImage(&image_trace);
    image_trace = cvCloneImage(image);

    //tracer le contour
    for( CvSeq* c=first_contour; c!=NULL; c=c->h_next ){
        cvDrawContours(
            image_trace,
            c,
            red,		// Red
            blue,		// Blue
            0.1,			// Vary max_level and compare results
            1,
            8 );
    }
    //affichage du resultat
    parent->getCarteScene()->shoowIplImage(image_trace);*/

    //renvoi de la sequance
    return first_contour;
}

//initialisation de l'outil de selection
Carte_select::Carte_select( MainWindow *parent)
{
    mask = NULL;
    image_trace = NULL;
    hsv = NULL;
    first_contour = NULL;
    this->parent = parent;
    Projet * pro = parent->getCurent_projet();

    h = 0, s = 0, v = 0, tolerance = 10;
    image = pro->get_carte();

    //image = cvLoadImage(path_carte.toStdString().c_str());
    hsv = cvCloneImage(image);
    cvCvtColor(image, hsv, CV_BGR2HSV);

    mask = cvCreateImage( cvGetSize(image), 8, 1 );

    //image_trace = cvCloneImage(image);
}

//destruction de l'outil de selection
Carte_select::~Carte_select(){
    //Libération de l'IplImage (on lui passe un IplImage**).
    cvReleaseImage(&mask);
    cvReleaseImage(&image_trace);
    cvReleaseImage(&hsv);
}
