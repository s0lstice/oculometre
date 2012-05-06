#include "volontaire.h"
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <dialog.h>
#include <QString>
#include <QObject>
#include <QDebug>

using namespace std;

//definit l'identifiant du Volontaire, il faut le subdiviser pour obtenir son groupe
void Volontaire::path_VolontaireToId_Volontaire(){
    QRegExp file("/(.*)/(.*.txt)$");
    QRegExp name("(.*)_(.*).txt");
    file.indexIn(path_Volontaire);
    name.indexIn(file.cap(file.captureCount()));
    id_Volontaire = name.cap(1);
}

//metre en place une gestion derreur pour supprimer la classe instancie alors que ce n'est pas un Volontaire !!!
void Volontaire::charger_points(){
    QStringList liste_info_point;
    point temp_point;
    QFile file(path_Volontaire);

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
            Dialog(QObject::tr("fichier non conforme :\n %1 .").arg(path_Volontaire)).exec();
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

Volontaire::Volontaire(const QString path)
{
    Displayed = Qt::Checked;
    path_Volontaire = path;
    path_VolontaireToId_Volontaire();
    charger_points();
}

QVector<Volontaire::point> Volontaire::get_points(){
    return v_points;
}
QString Volontaire::getPath_Volontaire(){
    return path_Volontaire;
}

QString Volontaire::getId_Volontaire(){
    return id_Volontaire;
}

Qt::CheckState Volontaire::getDisplayed(){
    return Displayed;
}

void Volontaire::setDisplayed(Qt::CheckState valeur){
    Displayed = valeur;
}

void Volontaire::switchEtat(){

    if(Displayed == Qt::Checked)
        Displayed = Qt::Unchecked;
    else
        Displayed = Qt::Checked;
}

void Volontaire::appendZone(int id, QString label, int numerotPoint){
    zone info;
    info.id = id;
    info.label = label;
    info.numerotPoint = numerotPoint;

    appartenance.append(info);
}

void Volontaire::clearZones()
{
    appartenance.clear();
}
/*
QDataStream & operator << (QDataStream & out, const Volontaire::zone & Valeur){
    out << Valeur.id
        << Valeur.label
        << Valeur.numerotPoint;

    return out;
}

QDataStream & operator >> (QDataStream & in, Volontaire::zone & Valeur){
    in >> Valeur.id;
    in >> Valeur.label;
    in >> Valeur.numerotPoint;

    return in;
}

QDataStream & operator << (QDataStream & out, const Volontaire::point & Valeur){
    out << Valeur.debut
        << Valeur.fin
        << Valeur.numerot
        << Valeur.x
        << Valeur.y;

    return out;
}

QDataStream & operator >> (QDataStream & in, Volontaire::point & Valeur){
    in >> Valeur.debut;
    in >> Valeur.fin;
    in >> Valeur.numerot;
    in >> Valeur.x;
    in >> Valeur.y;

    return out;
}

QDataStream & operator << (QDataStream & out, const Volontaire & Valeur){
    out << Valeur.id_Volontaire
        << Valeur.path_Volontaire
        << Valeur.Displayed
        << Valeur.v_points
        << Valeur.appartenance;

    return out;
}

QDataStream & operator >> (QDataStream & in, Volontaire & Valeur){
    in >> Valeur.id_Volontaire;
    in >> Valeur.path_Volontaire;
    in >> Valeur.Displayed;
    in >> Valeur.v_points;
    in >> Valeur.appartenance;

    return in;
}*/
