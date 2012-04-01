#ifndef CARTE_SELECT_H
#define CARTE_SELECT_H

#include <cv.h>
#include <highgui.h>
#include <QString>
#include <QMessageBox>
#include <QThread>
#include <QMutex>

void getObjectColor(int event, int x, int y, int flags, void *param = NULL);

class carte_select
{
private:

    IplImage* binarisation(IplImage* image, IplImage* mask);
    int h, s, v, tolerance;
    IplImage *image;
    bool color_change;

public:
    carte_select(const QString path_carte);

    IplImage * get_image(){
        return image;
    }

    void set_color_change(bool value){
        this->color_change = value;
    }

    void set_hsv(int h, int s, int v){
        this->h = h;
        this->s = s;
        this->v = v;
    }
};

#endif // CARTE_SELECT_H
