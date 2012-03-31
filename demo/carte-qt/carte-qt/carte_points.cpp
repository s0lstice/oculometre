#include "carte_points.h"
#include "projet.h"
#include <QString>
#include <cv.h>
#include <highgui.h>
#include "points_sujet.h"
#include <QDebug>

carte_points::carte_points()
{
    int i;
    QString path_carte;
    IplImage *image;
    projet *pro = projet::proj();
    points_sujet *points;
    QVector<point> v_points;
    float u_carte_x;
    float u_carte_y;

    path_carte = pro->get_path_carte();
    image = cvLoadImage(path_carte.toStdString().c_str());

    CvFont font;
    cvInitFont(&font, CV_FONT_HERSHEY_PLAIN, 1.0, 1.0, 0, 1, CV_AA);

    u_carte_x = (image->width/2)/20;
    u_carte_y = (image->height/2)/15;

    qDebug() << pro->get_nb_sujet();
    int b = 0;
    for(i = 0; i < pro->get_nb_sujet(); ++i){
        points = pro->get_sujet(i);
        v_points = points->get_points();
        qDebug() << i << " : " << v_points.size();
        foreach(point sujet_point, v_points){
            qDebug()<< b << " " << sujet_point.x << " : " << - sujet_point.y;
            cvCircle(image, cvPoint( image->width/2 + u_carte_x*sujet_point.x, image->height/2 + u_carte_y*sujet_point.y), 5, CV_RGB(255,0,0));
            cvPutText(image, QString::number(++b).toStdString().c_str(),  cvPoint( image->width/2 + u_carte_x*sujet_point.x, image->height/2 + u_carte_y*sujet_point.y), &font, cvScalar(255, 0, 0, 0));
        }
    }
    cvShowImage("Map", image);
}
