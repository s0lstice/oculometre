#ifndef GROUPE_SELECTION_H
#define GROUPE_SELECTION_H

#include "zone.h"
#include <QVector>

class Groupe_selection : public Zone
{
private:
    QVector<Zone *> groupe;
public:
    Groupe_selection(Groupe_selection *parent);
    ~Groupe_selection();

    Zone *child(int i);
    void appendChild(Zone *zone);
    QVector<Zone*> getZones();
    void appendChilds(QVector<Zone*> zone);
    int childCount() const;
    QVector<Zone *> getGroupe();
    void removeChild(Zone *zone);
};

#endif // GROUPE_SELECTION_H
