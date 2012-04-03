#include "carte_select.h"
#include "mainwindow.h"
#include <QDebug>

using namespace std;

/*
 * Transform the image into a two colored image, one color for the color we want to track,
 * another color for the others colors
 * From this image, we get two datas : the number of pixel detected, and the center of gravity of these pixel
 */
IplImage* carte_select::binarisation(IplImage* image, IplImage* mask) {

        //CvScalar pixel;
        IplImage *hsv;
        IplConvKernel *kernel;

        // Create the hsv image
        hsv = cvCloneImage(image);

        cvCvtColor(image, hsv, CV_BGR2HSV);

        // We create the mask
        cvInRangeS(hsv, cvScalar(h - tolerance -1, s - tolerance, 0), cvScalar(h + tolerance -1, s + tolerance, 255), mask);

        // Create kernels for the morphological operation
        kernel = cvCreateStructuringElementEx(5, 5, 2, 2, CV_SHAPE_ELLIPSE);

        // Morphological opening (inverse because we have white pixels on black background)
        cvDilate(mask, mask, kernel, 1);
        cvErode(mask, mask, kernel, 1);

        // We release the memory of kernels
        cvReleaseStructuringElement(&kernel);

        // We release the memory of the hsv image
    cvReleaseImage(&hsv);
    return mask;
}

carte_select::carte_select(const QString path_carte, int x, int y, MainWindow *parent)
{
    IplImage *mask = NULL, *image_trace = NULL, *hsv = NULL;

    CvMemStorage* storage = cvCreateMemStorage();
    CvSeq* first_contour = NULL;
    CvScalar pixel;

    h = 0, s = 0, v = 0, tolerance = 10;

    image = cvLoadImage(path_carte.toStdString().c_str());

    hsv = cvCloneImage(image);

    cvCvtColor(image, hsv, CV_BGR2HSV);

    pixel = cvGet2D(hsv, y, x);
    h = (int)pixel.val[0];
    s = (int)pixel.val[1];
    v = (int)pixel.val[2];

    mask = cvCreateImage( cvGetSize(image), 8, 1 );

    CvScalar red = CV_RGB(250,0,0);
    CvScalar blue = CV_RGB(0,0,250);

    image_trace = cvCloneImage(image);

    mask = binarisation(image, mask);

    cvFindContours(mask, storage, &first_contour, sizeof(CvContour), CV_RETR_LIST );

    for( CvSeq* c=first_contour; c!=NULL; c=c->h_next ){
        cvDrawContours(
            image_trace,
            c,
            red,		// Red
            blue,		// Blue
            1,			// Vary max_level and compare results
            2,
            8 );
    }
    parent->shoowIplImage(image_trace);

    //Libération de l'IplImage (on lui passe un IplImage**).
    cvReleaseImage(&mask);
    cvReleaseImage(&image);
    cvReleaseImage(&hsv);
    cvDestroyWindow("Map");
}
