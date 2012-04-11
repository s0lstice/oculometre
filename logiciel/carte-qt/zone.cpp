#include "zone.h"

#include <QDateTime>
#include <QDateTime>

Zone::Zone()
{
    id = QDateTime::currentMSecsSinceEpoch();
}

Zone::~Zone(){
}

int Zone::getId(){
    return id;
}

type_zone Zone::getType(){
    return type;
}

QString Zone::getLable(){
    return label;
}

void Zone::setLabel(QString label){
    this->label = label;
}
