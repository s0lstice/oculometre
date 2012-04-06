#ifndef SELECTION_H
#define SELECTION_H

#include "zone.h"
#include <cv.h>

class selection : public zone
{
    CvSeq *contour;
public:
    selection();
};

#endif // SELECTION_H
