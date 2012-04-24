#include "cercle.h"
#include "groupe_selection.h"

Cercle::Cercle(Groupe_selection *parent) : Zone(parent)
{
    type = cercle;
}

Cercle::~Cercle(){
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
