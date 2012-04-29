#include "groupe_selection.h"
#include <QVariant>

Groupe_selection::Groupe_selection(Groupe_selection *parent) : Zone(parent)
{
    type = composite;

}

Groupe_selection::~Groupe_selection(){
    qDeleteAll(groupe);
}

Zone *Groupe_selection::child(int i){
    return groupe.at(i);
}

void Groupe_selection::appendChild(Zone *zone){
    groupe.append(zone);
}

void Groupe_selection::removeChild(Zone *zone){
    Zone *p_zone;
    for(int i = 0; i < groupe.size(); ++i){
        if(groupe.at(i) == zone){
            p_zone = groupe.at(i);
            groupe.remove(i);
            delete p_zone;
            break;
        }
    }
}

QVector<Zone*> Groupe_selection::getZones(){
    return groupe;
}

void Groupe_selection::appendChilds(QVector<Zone*> zone){
    groupe += zone;
}

int Groupe_selection::childCount() const{
    return groupe.size();
}

QVector<Zone *> Groupe_selection::getGroupe(){
    return groupe;
}
