#ifndef ZONE_H
#define ZONE_H

#include <QString>
#include <QVariant>
#include <QVector>

class Groupe_selection;

class Zone
{
public:
    typedef enum _type_zone
       {
        selection,
        cercle,
        rectangle,
        composite
       }type_zone;

    Zone(Groupe_selection *parent);
    virtual ~Zone();

    int getId();
    type_zone getType();
    QString getLable();
    void setLabel(QString label);

    Groupe_selection *getParent();
    QVector<QVariant> data() const;
    int row() const;

    Qt::CheckState getDisplayed();
    void setDisplayed(Qt::CheckState valeur);
    void switchEtat();

protected:
    int id;
    type_zone type;
    QString label;
    Groupe_selection *parent;
    Qt::CheckState Displayed;
};

#endif // ZONE_H
