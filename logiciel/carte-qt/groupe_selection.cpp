#include "groupe_selection.h"

Groupe_selection::Groupe_selection() : Zone()
{
    type = composite;

}

Groupe_selection::~Groupe_selection(){
    Zone * zone;
    int i = groupe.size();
    foreach(zone, groupe){
        delete zone;
        groupe.remove(i);
        i--;
    }
}

Zone *Groupe_selection::getZone(int i){
    return groupe.at(i);
}

void Groupe_selection::addEndZone(Zone *zone){
    groupe.append(zone);
}

QVector<Zone*> Groupe_selection::getZones(){
    return groupe;
}

void Groupe_selection::addEndZones(QVector<Zone*> zone){
    groupe += zone;
}
