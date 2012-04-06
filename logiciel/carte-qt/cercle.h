#ifndef CERCLE_H
#define CERCLE_H

#include "zone.h"
#include <QPoint>

class cercle : public zone
{
private:
    QPoint centre;
    int rayon;

public:
    cercle();

    QPoint getCentre(){
        return centre;
    }

    int getRayon(){
        return rayon;
    }
};

#endif // CERCLE_H
