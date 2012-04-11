#ifndef POINT_H
#define POINT_H

#include <QString>
#include <QVector>

typedef struct _point{
    int numerot;
    float x;
    float y;
    float debut;
    float fin;
}point;

class Sujet
{
private:

    QString path_sujet;
    int zone_id;
    QString id_sujet;
    QVector<point> v_points;

    void charger_points();
    void path_sujetToId_sujet();

public:
    Sujet(const QString path);

    QVector<point> get_points();
    QString getPath_sujet();
    QString getId_sujet();
    void setZone_id(int id);
    int getZone_Id();
};

#endif // POINT_H
