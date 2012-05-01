#include "selection.h"

#include "zone.h"
//class Zone;
#include "carte_select.h"
//class Carte_select;

Selection::Selection(Groupe_selection *parent) : Zone(parent)
{
    type = selection;
    label = QObject::tr("Sélection ") + QString::number(id);
}

Selection::~Selection(){
}

void Selection::setPerimetre(CvSeq *contour){
    this->contour = contour;
}

CvSeq * Selection::getPerimetre(){
    return contour;
}
