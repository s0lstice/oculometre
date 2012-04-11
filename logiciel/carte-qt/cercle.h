#ifndef CERCLE_H
#define CERCLE_H

#include "zone.h"
#include <QPoint>

class Cercle : public Zone
{
private:
    QPoint centre;
    int rayon;

public:
    Cercle();
    ~Cercle();

    QPoint getCentre();
    int getRayon();

    void setCentre(QPoint centre);
    void setRayon(int rayon);
};

#endif // CERCLE_H
