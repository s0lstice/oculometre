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

class Carte_select
{
private:

    void binarisation(IplImage *image);

    int h, s, v, tolerance;
    IplImage *image;
    bool color_change;
    IplImage *maskSelection;
    IplImage *image_trace;
    IplImage *hsv;
    CvSeq* contour;
    MainWindow *parent;
    CvMemStorage* storage;

public:
    CvSeq *Selection(int x, int y);
    Carte_select(MainWindow *parent);
    void setStorage(CvMemStorage* storage);
    CvSeq* getContour();
    IplImage* getMask();
    ~Carte_select();
};

#endif // CARTE_SELECT_H
