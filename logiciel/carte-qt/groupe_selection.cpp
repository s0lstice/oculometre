#include "groupe_selection.h"
#include <QVariant>

Groupe_selection::Groupe_selection(Groupe_selection *parent) : Zone(parent)
{
    type = composite;
    label = "Groupe " + QString::number(id);
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

int Groupe_selection::size()
{
    Zone *zone;
    int nombre = 0;

    foreach(zone, groupe){
        if(zone->getType() == Zone::composite){
            nombre += zone->size();
        }
        else
        {
            nombre++;
        }
    }

    return nombre;
}

QString Groupe_selection::serialisation()
{
    QString datas;

    datas = "{";
    datas += Zone::sub_serialisation();
    datas += ",group=[";
    Zone *zone;

    if(groupe.size() != 0){
        foreach(zone, groupe){
            datas += zone->serialisation() + ",";
        }

        datas.remove(datas.size() -1, 1);
    }
    datas += "]}";
    return datas;
}

void Groupe_selection::deserialisation(QString datas)
{
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
