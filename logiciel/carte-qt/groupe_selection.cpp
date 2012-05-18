#include "groupe_selection.h"
#include <QVariant>
#include <QRegExp>
#include "cercle.h"
#include "selection.h"
#include "rectangle.h"
#include "projet.h"
#include <QDebug>
#include <QStringList>

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

/*!
  @fn int Groupe_selection::size()
  @return int : entier
  @brief donne le nombre délements dans l'arbre
  */
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
    datas += ",groupe=[";
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

void Groupe_selection::deserialisation(QString datas, Projet *pro)
{
    QStringList listeZone;

    datas.remove(0,1);
    datas.remove(datas.size() -1,1);

    QString str = datas.split(",groupe")[0];
    Zone::deserialisation(str);

    str = datas.split(",groupe")[1];
    str.remove(0,2);
    str.remove(str.size() -1, 1);
    listeZone = str.split("{type=");
    //liste = datas.split(",groupe")[1].split(",");

    listeZone.pop_front();
    foreach(str, listeZone){
        int type = str.at(0).digitValue();
        str = "{type=" +  str;
        if(str[str.size() -1] == ',')
            str.remove(str.size() - 1, 1);
        switch(type){
            case Zone::cercle :{
                Cercle * cercle = new Cercle(this);
                cercle->deserialisation(str);
                groupe.append(cercle);
            }
            break;
            case Zone::selection :{
                Selection * selection = new Selection(this);
                selection->deserialisation(str, pro);
                groupe.append(selection);
            }
            break;
            case Zone::rectangle :{
                Rectangle * rectangle = new Rectangle(this);
                rectangle->deserialisation(str);
                groupe.append(rectangle);
            }
            break;
            case Zone::composite :{
                Groupe_selection * group = new Groupe_selection(this);
                group->deserialisation(str, pro);
                groupe.append(group);
            }
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
