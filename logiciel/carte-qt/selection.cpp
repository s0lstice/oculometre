#include "selection.h"

#include "zone.h"
//class Zone;
#include "carte_select.h"
//class Carte_select;

Selection::Selection(Groupe_selection *parent) : Zone(parent)
{
    type = selection;
}

Selection::~Selection(){
}
