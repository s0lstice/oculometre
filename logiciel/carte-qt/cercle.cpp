#include "cercle.h"

Cercle::Cercle() : Zone()
{
    type = cercle;
}

QPoint Cercle::getCentre(){
    return centre;
}

int Cercle::getRayon(){
    return rayon;
}

void Cercle::setCentre(QPoint centre){
    this->centre = centre;
}

void Cercle::setRayon(int rayon){
    this->rayon = rayon;
}
