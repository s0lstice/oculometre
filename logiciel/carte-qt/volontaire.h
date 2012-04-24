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

class Volontaire
{
public:


    Volontaire(const QString path);

    QVector<point> get_points();
    QString getPath_Volontaire();
    QString getId_Volontaire();
    void setZone_id(int id);
    int getZone_Id();
    Qt::CheckState getDisplayed();
    void setDisplayed(Qt::CheckState valeu);
    void switchEtat();

private:

    Qt::CheckState Displayed;

    QString path_Volontaire;
    int zone_id;
    QString id_Volontaire;
    QVector<point> v_points;

    void charger_points();
    void path_VolontaireToId_Volontaire();

};

#endif // POINT_H
