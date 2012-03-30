#ifndef POINT_H
#define POINT_H

#include <QString>

typedef struct _point{
    int numerot;
    int x;
    int y;
    int debut;
    int fin;
}point;

class points
{
private:
    QString path_sujet;
    //QVector<point> v_points;

    void charger_points();
public:

    points(const QString path);
};

#endif // POINT_H
