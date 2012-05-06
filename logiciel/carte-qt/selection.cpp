#include "selection.h"

#include "zone.h"
//class Zone;
#include "carte_select.h"
//class Carte_select;

Selection::Selection(Groupe_selection *parent) : Zone(parent)
{
    type = selection;
    label = QObject::tr("Sélection ") + QString::number(id);
}

Selection::~Selection(){
}

QString Selection::serialisation()
{
    QString datas;

    /*QVector<MyQPointF> contourQt = getQtPerimetre();
    MyQPointF point;

    datas = "{" + Zone::serialisation();
    datas += ",contour=[";
    foreach(point,contourQt){
       datas += point.serialisation() +",";
    }

    datas.remove(datas.size() -1, 1);
    datas += "]}";*/
    return datas;
}

void Selection::deserialisation(QString datas)
{
}

void Selection::setPerimetre(CvSeq *contour){
    this->contour = contour;
}

CvSeq * Selection::getPerimetre(){
    return contour;
}

QVector<MyQPointF> Selection::getQtPerimetre()
{
    CvMemStorage* storage = cvCreateMemStorage();
    QVector<MyQPointF> contourQt;
    CvSeq *tmp;
    //tmp = cvCloneSeq(contour, storage); << ca plante
    int i;
    CvPoint cvPoint;

    for(i = 0; i < tmp->total; ++i){
        cvSeqPop(tmp,&cvPoint);
        MyQPointF myPoint(cvPoint.x, cvPoint.y);
        contourQt.append(myPoint);
    }

    cvReleaseMemStorage(&storage);
    return contourQt;
}
