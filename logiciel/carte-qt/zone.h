#ifndef ZONE_H
#define ZONE_H

#include <QString>

typedef enum _type_zone{
    quadrilataire,
    cercle,
    selection,
}type_zone;

class zone
{
protected:
    int id_zone;
    QString label;
    type_zone type;
public:
    zone();
};

#endif // ZONE_H
