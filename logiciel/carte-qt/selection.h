#ifndef SELECTION_H
#define SELECTION_H

#include <cv.h>

#include "zone.h"
#include "myqpointf.h"

class Carte_select;
class Groupe_selection;

class Selection : public Zone
{
protected:
    CvSeq *contour;

public:
    Selection(Groupe_selection *parent);
    void setPerimetre(CvSeq *contour);
    CvSeq * getPerimetre();
    QVector<MyQPointF> getQtPerimetre();
    ~Selection();

    QString serialisation();
    void deserialisation(QString datas);
};

#endif // SELECTION_H
