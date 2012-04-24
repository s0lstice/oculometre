#ifndef ZONE_H
#define ZONE_H

#include <QString>
#include <QVariant>
#include <QVector>

class Groupe_selection;

typedef enum _type_zone
   {
    selection,
    cercle,
    polygone,
    composite
   }type_zone;

class Zone
{
protected:
    int id;
    type_zone type;
    QString label;
    Groupe_selection *parent;

public:
    Zone(Groupe_selection *parent);
    virtual ~Zone();

    int getId();
    type_zone getType();
    QString getLable();
    void setLabel(QString label);

    Groupe_selection *getParent();
    QVector<QVariant> data() const;
    int row() const;
};

#endif // ZONE_H
