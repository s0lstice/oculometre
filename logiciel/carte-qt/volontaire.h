#ifndef POINT_H
#define POINT_H

#include <QString>
#include <QVector>

#include <QVariant>

class Projet;
class Volontaire
{

public :
    typedef struct _point{
        int numerot;
        float x;
        float y;
        float debut;
        float fin;
    }point;

private:

    typedef struct _zone{
        int id;
        QString label;
        int numerotPoint;
    }zone;

    Qt::CheckState Displayed;

    QString path_Volontaire;
    QString id_Volontaire;
    QVector<point> v_points;
    QVector<zone> appartenance;
    Projet *projet;

    void charger_points();
    void path_VolontaireToId_Volontaire();

public:

    Volontaire(Projet *projet,const QString path);

    QVector<point> get_points();
    QString getPath_Volontaire();
    QString getId_Volontaire();
    Qt::CheckState getDisplayed();
    void setDisplayed(Qt::CheckState valeur);
    void switchEtat();
    void appendZone(int id, QString label, int numerotPoint);
    void clearZones();

};

#endif // POINT_H
