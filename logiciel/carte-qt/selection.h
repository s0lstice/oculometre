#ifndef SELECTION_H
#define SELECTION_H

#include <cv.h>

#include "zone.h"
#include "myqpointf.h"

class Carte_select;
class Groupe_selection;
class Projet;

class Selection : public Zone
{
protected:
    CvSeq *contour;
    CvMemStorage* storage;
    IplImage* mask;

public:
    Selection(Groupe_selection *parent);
    void setPerimetre(CvSeq *contour);
    CvSeq * getPerimetre();
    ~Selection();

    CvMemStorage* getStorage();
    void setStorage(CvMemStorage * storage);
    void setMask(IplImage* mask);
    IplImage *getMask();

    QString serialisation();
    void deserialisation(QString datas, Projet *pro);

};

#endif // SELECTION_H
