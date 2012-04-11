#ifndef ZONE_H
#define ZONE_H

#include <QString>

typedef enum _type_zone
   {
    selection,
    cercle,
    polygone,
    groupe
   }type_zone;

class Zone
{
protected:
    int id;
    type_zone type;
    QString label;

public:
    Zone();

    int getId();
    type_zone getType();
    QString getLable();
    void setLabel(QString label);

};

#endif // ZONE_H
