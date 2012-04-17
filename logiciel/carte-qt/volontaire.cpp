#include "sujet.h"
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <dialog.h>
#include <QString>
#include <QObject>
#include <QDebug>

using namespace std;

//definit l'identifiant du sujet, il faut le subdiviser pour obtenir son groupe
void Sujet::path_sujetToId_sujet(){
    QRegExp file("/(.*)/(.*.txt)$");
    QRegExp name("(.*).txt");
    file.indexIn(path_sujet);
    name.indexIn(file.cap(file.captureCount()));
    id_sujet = name.cap(1);
}

//metre en place une gestion derreur pour supprimer la classe instancie alors que ce n'est pas un volontaire !!!
void Sujet::charger_points(){
    QStringList liste_info_point;
    point temp_point;
    QFile file(path_sujet);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qWarning() << "[erreur] impossible d'ouvrir le ficher en ecriture seul"
                  << qPrintable(file.errorString());
        return;
    }

    QTextStream out(&file);
    QString line;
    while(!out.atEnd()){
        line = out.readLine();
        liste_info_point = line.split("	");

        if(liste_info_point.size() != 5)
        {
            Dialog(QObject::tr("fichier non conforme :\n %1 .").arg(path_sujet)).exec();
            return;
        }

        temp_point.numerot = liste_info_point[0].toInt();
        temp_point.x = liste_info_point[1].toFloat();
        temp_point.y = liste_info_point[2].toFloat();
        temp_point.debut = liste_info_point[3].toFloat();
        temp_point.fin = liste_info_point[4].toFloat();

        v_points.append(temp_point);
    }
}

Sujet::Sujet(const QString path)
{
    path_sujet = path;
    path_sujetToId_sujet();
    charger_points();
}

QVector<point> Sujet::get_points(){
    return v_points;
}
QString Sujet::getPath_sujet(){
    return path_sujet;
}

QString Sujet::getId_sujet(){
    return id_sujet;
}

void Sujet::setZone_id(int id){
    zone_id = id;
}

int Sujet::getZone_Id(){
    return zone_id;
}
