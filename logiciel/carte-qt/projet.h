#ifndef PROJET_H
#define PROJET_H

#include <QString>
#include <QVector>
#include <sujet.h>
#include <QRegExp>
#include <QDebug>
#include <QStringList>

class projet
{
private:
    QString path_carte;
    QVector<sujet*> v_sujets;
    projet();
    ~projet();
public:
    sujet *get_sujet(int i){
        return v_sujets.value(i);
    }
    QVector<sujet*> get_sujet(){
        return v_sujets;
    }

    int get_nb_sujet(){
        return v_sujets.size();
    }

    void set_path_carte(QString path){
        path_carte = path;
    }

    QString get_path_carte(){
        return path_carte;
    }

    static projet *_singleton;

    static projet *proj()
    {
        if (NULL == _singleton)
        {
            _singleton = new projet();
        }
        return _singleton;
    }

    static void projExit(){
        if (NULL != _singleton)
        {
            delete _singleton;
            _singleton = NULL;
        }
    }

    void charger_sujets(QStringList liste_sujet);
    void supprimer_sujets(QVector<sujet*> liste_sujet);
};

#endif // PROJET_H
