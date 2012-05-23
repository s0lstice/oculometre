#include "zone.h"

#include <QStringList>
#include <QDebug>
#include <QDateTime>
#include "groupe_selection.h"

Zone::Zone(Groupe_selection *parent)
{
    displayed = Qt::Checked;
    id = QDateTime::currentMSecsSinceEpoch();
    this->parent = parent;
}

Zone::~Zone(){
}

int Zone::getId(){
    return id;
}

Zone::type_zone Zone::getType(){
    return type;
}

QString Zone::getLable(){
    return label;
}

void Zone::setLabel(QString label){
    this->label = label;
}

Groupe_selection *Zone::getParent(){
    return parent;
}

int Zone::row() const
{
    if(parent)
        if(parent->getType() == composite)
            return parent->getZones().indexOf(const_cast<Zone*>(this));

    return 0;
}

Qt::CheckState Zone::getDisplayed(){
    return displayed;
}

void Zone::setDisplayed(Qt::CheckState valeur){
    displayed = valeur;
}

void Zone::switchEtat(){

    if(displayed == Qt::Checked)
        displayed = Qt::Unchecked;
    else
        displayed = Qt::Checked;
}

QString Zone::serialisation()
{
    return "{" + sub_serialisation() + "}";
}

void Zone::deserialisation(QString datas)
{
    QString str;
    QStringList liste = datas.split(",");

    foreach(str, liste){
        QStringList split = str.split("=");
        if(split[0] == "type"){
            type = (Zone::type_zone)split[1].toInt();
        }else if(split[0] == "id"){
            id = split[1].toInt();
        }else if(split[0] == "label"){
            label = split[1];
        }else if(split[0] == "display"){
            if(split[1].toInt() == 1){
                displayed = Qt::Checked;
            }
            else
                displayed = Qt::Unchecked;
        }
    }
}

QString Zone::sub_serialisation()
{
    QString datas;
    datas = "type=" + QString::number((int)type) + ",";
    datas += "id=" + QString::number(id) + ",";
    datas += "label=\"" + label + "\",";
    if(displayed == Qt::Checked)
        datas += "display=1";
    else
        datas += "display=0";

    return datas;
}
