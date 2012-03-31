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

class points_sujet
{
private:

    QString path_sujet;
    QVector<point> v_points;

    void charger_points();
public:
    points_sujet(const QString path);
    QVector<point> get_points(){
        return v_points;
    }
};

#endif // POINT_H
