#include "carte_points.h"
#include "projet.h"
#include <QString>
#include <cv.h>
#include <highgui.h>
#include "dialog.h"

#include "mainwindow.h"
//class MainWindow;
#include "sujet.h"
//class Sujet;
#include "projet.h"
//class Projet;

//trace des points contenues dans un vecteur
Carte_points::Carte_points(Projet *pro,QVector<Sujet*> v_sujets, MainWindow *parent)
{
    //int i;
    QString path_carte;
    IplImage *image;
    Sujet *points;
    QVector<point> v_points;
    CvFont font;

    float u_carte_x;
    float u_carte_y;

    //si la carte existe
    if(pro->get_path_carte() != ""){
        //chargement de l'image
        path_carte = pro->get_path_carte();
        image = cvLoadImage(path_carte.toStdString().c_str());

        //definition de la font pour ecrire le n° du point
        cvInitFont(&font, CV_FONT_HERSHEY_PLAIN, 1.0, 1.0, 0, 1, CV_AA);

        //changement de repaire px -> oculomaitre
        u_carte_x = (image->width/2)/20;
        u_carte_y = (image->height/2)/15;

        //s il y a bien des sujet de selectionnné
        if(v_sujets.size() != 0){
            int numero;
            foreach (points, v_sujets) {
                v_points = points->get_points(); //rucuperation du vecteur de point appartenaint au volontaire
                numero = 0;
                foreach(point sujet_point, v_points){
                    //cercle
                    cvCircle(image, cvPoint( image->width/2 + u_carte_x*sujet_point.x, image->height/2 + u_carte_y*sujet_point.y), 5, CV_RGB(255,0,0));
                    //numero
                    cvPutText(image, QString::number(++numero).toStdString().c_str(),  cvPoint( image->width/2 + u_carte_x*sujet_point.x, image->height/2 + u_carte_y*sujet_point.y), &font, cvScalar(255, 0, 0, 0));
                }
            }
            //affichage
            parent->shoowIplImage(image);
         }
        else{
            Dialog(QObject::tr("Sélectionner des points avant de faire cette action .")).exec();
            return;
        }
    }
    else
    {
        Dialog(QObject::tr("Charger une carte avant de faire cette action .")).exec();
        return;
    }
}
