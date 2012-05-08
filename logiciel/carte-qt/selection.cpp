#include "selection.h"

#include "zone.h"
//class Zone;
#include "carte_select.h"
//class Carte_select;

Selection::Selection(Groupe_selection *parent) : Zone(parent)
{
    type = selection;
    label = QObject::tr("Sélection ") + QString::number(id);
    storage = cvCreateMemStorage();
}

Selection::~Selection(){
    cvReleaseMemStorage(&storage);
    cvReleaseImage(&mask);
}

QString Selection::serialisation()
{
    QString datas;

    QVector<MyQPointF> contourQt = getQtPerimetre();
    MyQPointF point;

    datas = "{" + Zone::serialisation();
    datas += ",contour=[";
    foreach(point,contourQt){
       datas += point.serialisation() +",";
    }

    datas.remove(datas.size() -1, 1);
    datas += "]}";
    return datas;
}

void Selection::deserialisation(QString datas)
{
}

CvMemStorage *Selection::getStorage()
{
    return storage;
}

void Selection::setStorage(CvMemStorage * storage)
{
    this->storage = storage;
}

void Selection::setMask(IplImage *mask)
{
    this->mask = mask;
}

IplImage *Selection::getMask()
{
    return mask;
}

void Selection::setPerimetre(CvSeq *contour){
    this->contour = contour;
}

CvSeq * Selection::getPerimetre(){
    return contour;
}

QVector<MyQPointF> Selection::getQtPerimetre()
{
    int i;
    QVector<MyQPointF> contourQt;
    CvPoint *cvPoint;

    for(i = 0; i < contour->total; ++i){
        cvPoint = CV_GET_SEQ_ELEM(CvPoint, contour, i);
        MyQPointF myPoint(cvPoint->x, cvPoint->y);
        contourQt.append(myPoint);
    }

    return contourQt;
}
