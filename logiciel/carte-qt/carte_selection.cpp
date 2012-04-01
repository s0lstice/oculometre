#include <cv.h>
#include <highgui.h>
#include <stdio.h>

#include <iostream>

// Maths methods
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define abs(x) ((x) > 0 ? (x) : -(x))
#define sign(x) ((x) > 0 ? 1 : -1)

// Step mooving for object min & max
#define STEP_MIN 5
#define STEP_MAX 100

using namespace std;

// Color tracked and our tolerance towards it
int h = 0, s = 0, v = 0, tolerance = 10;
IplImage *image;

bool color_change = false;
/*
 * Transform the image into a two colored image, one color for the color we want to track,
 * another color for the others colors
 * From this image, we get two datas : the number of pixel detected, and the center of gravity of these pixel
 */
IplImage* binarisation(IplImage* image, IplImage* mask) {

        //CvScalar pixel;
        IplImage *hsv;
        IplConvKernel *kernel;

        // Create the mask &initialize it to white (no color detected)
        //mask = cvCreateImage(cvGetSize(image), image->depth, 1);

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

        // We release the memory of the mask

        // We release the memory of the hsv image
    cvReleaseImage(&hsv);
    return mask;
}

/*
 * Get the color of the pixel where the mouse has clicked
 * We put this color as model color (the color we want to tracked)
 */
void getObjectColor(int event, int x, int y, int flags, void *param = NULL) {

        // Vars
        CvScalar pixel;
        IplImage *hsv;

        if(event == CV_EVENT_LBUTTONUP)	{
        color_change = true;
                // Get the hsv image
                hsv = cvCloneImage(image);
                cvCvtColor(image, hsv, CV_BGR2HSV);

                // Get the selected pixel
                pixel = cvGet2D(hsv, y, x);
        cout << "x =" << x << " y=" << y <<endl;

                // Change the value of the tracked color with the color of the selected pixel
                h = (int)pixel.val[0];
                s = (int)pixel.val[1];
                v = (int)pixel.val[2];

                // Release the memory of the hsv image
                cvReleaseImage(&hsv);

        }

}

int selection_main()
{
    char key;
    IplImage *mask = NULL, *img_8uc3 = NULL, *image_trace = NULL;

    CvMemStorage* storage = cvCreateMemStorage();
    CvSeq* first_contour = NULL;

    image = cvLoadImage("01_K949.bmp");

    mask = cvCreateImage( cvGetSize(image), 8, 1 );
    img_8uc3 = cvCreateImage( cvGetSize(image), 8, 3 );

    CvScalar red = CV_RGB(250,0,0);
    CvScalar blue = CV_RGB(0,0,250);

    cvNamedWindow("Map", CV_WINDOW_AUTOSIZE);

    cvShowImage("Map", image);

    cvSetMouseCallback("Map", getObjectColor);

    while(key != 'Q' && key != 'q') {
        if(color_change == true){
            color_change = false;

            if(image_trace != NULL)
                cvReleaseImage(&image_trace);
            image_trace = cvCloneImage(image);

            mask = binarisation(image, mask);

            int Nc = cvFindContours(mask, storage, &first_contour, sizeof(CvContour), CV_RETR_LIST );
            printf( "Total Contours Detected: %d\n", Nc );

            for( CvSeq* c=first_contour; c!=NULL; c=c->h_next ){
                //cvCvtColor( image_0, img_8uc3, CV_GRAY2BGR );
                cvDrawContours(
                    image_trace,
                    c,
                    red,		// Red
                    blue,		// Blue
                    1,			// Vary max_level and compare results
                    2,
                    8 );
                    cout << "." << endl;
            }
            cout << endl;

            printf( "Finished all contours.\n");
            cvShowImage( "Map", image_trace );

        // Show the result of the mask image
        //cvAddWeighted(image, 1, mask, 0.5, 1, imgreuslt);
        //cvShowImage("Mask", mask);
        }
    // We wait 10 ms
            key = cvWaitKey(10);

    }

    //Destruction de la fenêtre.
    cvDestroyWindow("Map");

    //Libération de l'IplImage (on lui passe un IplImage**).
    cvReleaseImage(&mask);
    cvReleaseImage(&image);

    //Fini ^^
    return 0;
}
