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

class sujet
{
private:

    QString path_sujet;
    int zone_id;
    QString id_sujet;
    QVector<point> v_points;

    void charger_points();
    void path_sujetToId_sujet();

public:
    sujet(const QString path);

    QVector<point> get_points(){
        return v_points;
    }
    QString getPath_sujet(){
        return path_sujet;
    }

    QString getId_sujet(){
        return id_sujet;
    }

    void setZone_id(int id){
        zone_id = id;
    }

    int getZone_Id(){
        return zone_id;
    }
};

#endif // POINT_H
