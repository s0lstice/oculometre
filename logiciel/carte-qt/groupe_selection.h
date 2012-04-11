#ifndef GROUPE_SELECTION_H
#define GROUPE_SELECTION_H

#include "zone.h"
#include <QVector>

class Groupe_selection : public Zone
{
private:
    QVector<Zone *> groupe;
public:
    Groupe_selection();
    ~Groupe_selection();

    Zone *getZone(int i);
    void addEndZone(Zone *zone);
    QVector<Zone*> getZones();
    void addEndZones(QVector<Zone*> zone);
};

#endif // GROUPE_SELECTION_H
