#include <cv.h>
#include <highgui.h>

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

// Position of the object we overlay
CvPoint objectPos = cvPoint(-1, -1);
// Color tracked and our tolerance towards it
int h = 0, s = 0, v = 0, tolerance = 10;
IplImage *image;
/*
 * Transform the image into a two colored image, one color for the color we want to track,
 * another color for the others colors
 * From this image, we get two datas : the number of pixel detected, and the center of gravity of these pixel
 */
CvPoint binarisation(IplImage* image, int *nbPixels) {

	int x, y;
	//CvScalar pixel;
	IplImage *hsv, *mask;
	IplConvKernel *kernel;
	int sommeX = 0, sommeY = 0;
	*nbPixels = 0;

	// Create the mask &initialize it to white (no color detected)
	mask = cvCreateImage(cvGetSize(image), image->depth, 1);

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

	// We go through the mask to look for the tracked object and get its gravity center
	for(x = 0; x < mask->width; x++) {
		for(y = 0; y < mask->height; y++) {

			// If its a tracked pixel, count it to the center of gravity's calcul
			if(((uchar *)(mask->imageData + y*mask->widthStep))[x] == 255) {
				sommeX += x;
				sommeY += y;
				(*nbPixels)++;
			}
		}
	}

	// Show the result of the mask image
	cvShowImage("GeckoGeek Mask", mask);

	// We release the memory of kernels
	cvReleaseStructuringElement(&kernel);

	// We release the memory of the mask
	cvReleaseImage(&mask);
	// We release the memory of the hsv image
    cvReleaseImage(&hsv);

	// If there is no pixel, we return a center outside the image, else we return the center of gravity
	if(*nbPixels > 0)
		return cvPoint((int)(sommeX / (*nbPixels)), (int)(sommeY / (*nbPixels)));
	else
		return cvPoint(-1, -1);
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

int main()
{
    int nbpx = 0;
    CvPoint cg;

	// Key for keyboard event
	char key;

    //On déclare "un pointeur vers une structure IplImage" :
    //En gros, on "déclare une image".
    //IplImage *image;

    //On charge notre image depuis un fichier.
    image = cvLoadImage("01_K949.bmp");
    //On crée une fenêtre intitulée "Hello World",
    //La taille de cette fenêtre s'adapte à ce qu'elle contient.
    cvNamedWindow("Map", CV_WINDOW_AUTOSIZE);

    //On affiche l'image dans la fenêtre "Hello World".
    cvShowImage("Map", image);

	// Mouse event to select the tracked color on the original image
	cvSetMouseCallback("Map", getObjectColor);

	while(key != 'Q' && key != 'q') {
        cg = binarisation(image, &nbpx);

        cout << "cg : x=" << cg.x << " y=" << cg.y << " nbpx=" << nbpx << endl;

        // We wait 10 ms
		key = cvWaitKey(10);

	}

    //Destruction de la fenêtre.
    cvDestroyWindow("Map");

    //Libération de l'IplImage (on lui passe un IplImage**).
    cvReleaseImage(&image);

    //Fini ^^
    return 0;
}
