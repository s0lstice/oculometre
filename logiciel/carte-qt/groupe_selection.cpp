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
