#include "carte_select.h"

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

/*
 * Get the color of the pixel where the mouse has clicked
 * We put this color as model color (the color we want to tracked)
 */
void getObjectColor(int event, int x, int y, int flags, void *param) {

        // Vars
        carte_select* carte = (carte_select*)param;
        CvScalar pixel;
        IplImage *hsv;

        if(event == CV_EVENT_LBUTTONUP)	{

                carte->set_color_change(true);
                // Get the hsv image
                hsv = cvCloneImage(carte->get_image());
                cvCvtColor(carte->get_image(), hsv, CV_BGR2HSV);

                // Get the selected pixel
                pixel = cvGet2D(hsv, y, x);

                // Change the value of the tracked color with the color of the selected pixel
                carte->set_hsv((int)pixel.val[0], (int)pixel.val[1], (int)pixel.val[2]);
                /*h = (int)pixel.val[0];
                s = (int)pixel.val[1];
                v = (int)pixel.val[2];*/

                // Release the memory of the hsv image
                cvReleaseImage(&hsv);
        }
}

carte_select::carte_select(const QString path_carte)
{
    char key;

    IplImage *mask = NULL, *image_trace = NULL;

    CvMemStorage* storage = cvCreateMemStorage();
    CvSeq* first_contour = NULL;

    h = 0, s = 0, v = 0, tolerance = 10;
    color_change = false;

    cvNamedWindow("Map", CV_WINDOW_AUTOSIZE);

    image = cvLoadImage(path_carte.toStdString().c_str());

    cvShowImage( "Map", image );

    mask = cvCreateImage( cvGetSize(image), 8, 1 );

    CvScalar red = CV_RGB(250,0,0);
    CvScalar blue = CV_RGB(0,0,250);

    cvSetMouseCallback("Map", getObjectColor, this);

    while(key != 'Q' && key != 'q') {
        if(color_change == true){
            color_change = false;

            if(image_trace != NULL)
                cvReleaseImage(&image_trace);
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
            cvShowImage( "Map", image_trace );


        }
        key = cvWaitKey(10);
    }

    //Libération de l'IplImage (on lui passe un IplImage**).
    cvReleaseImage(&mask);
    cvReleaseImage(&image);
    cvDestroyWindow("Map");
}
