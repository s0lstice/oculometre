#include "zone.h"

#include <QDateTime>
#include <QDateTime>
#include "groupe_selection.h"

Zone::Zone(Groupe_selection *parent)
{
    Displayed = Qt::Checked;
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

QVector<QVariant> Zone::data() const {
    QVector<QVariant> datas;
    datas << id << type << label;
    return datas;
}

int Zone::row() const
{
    if(parent)
        if(parent->getType() == composite)
            return parent->getGroupe().indexOf(const_cast<Zone*>(this));

    return 0;
}

Qt::CheckState Zone::getDisplayed(){
    return Displayed;
}

void Zone::setDisplayed(Qt::CheckState valeur){
    Displayed = valeur;
}

void Zone::switchEtat(){

    if(Displayed == Qt::Checked)
        Displayed = Qt::Unchecked;
    else
        Displayed = Qt::Checked;
}
