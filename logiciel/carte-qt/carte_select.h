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

    void binarisation();

    int h, s, v, tolerance;
    IplImage *image;
    bool color_change;
    IplImage *mask;
    IplImage *image_trace;
    IplImage *hsv;
    CvSeq* first_contour;
    MainWindow *parent;

public:
    CvSeq *Selection(int x, int y);
    Carte_select(MainWindow *parent);
    ~Carte_select();
};

#endif // CARTE_SELECT_H
