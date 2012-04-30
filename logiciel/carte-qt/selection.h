#ifndef SELECTION_H
#define SELECTION_H

#include <cv.h>

#include "zone.h"
//class Zone;
//#include "carte_select.h"
class Carte_select;
class Groupe_selection;

class Selection : public Zone
{
protected:
    Carte_select *methode_selection;
    CvSeq *contour;
public:
    Selection(Groupe_selection *parent);
    void setPerimetre(CvSeq *contour);
    ~Selection();
};

#endif // SELECTION_H
