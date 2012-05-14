#include "selection.h"

#include "zone.h"
//class Zone;
#include "carte_select.h"
//class Carte_select;
#include <cv.h>
#include <highgui.h>

#include <QDebug>

Selection::Selection(Groupe_selection *parent) : Zone(parent)
{
    type = selection;
    label = QObject::tr("Sélection ") + QString::number(id);
    storage = cvCreateMemStorage();
    mask = NULL;
}

Selection::~Selection(){
    cvReleaseMemStorage(&storage);
    if(mask != NULL)
        cvReleaseImage(&mask);
}

QString Selection::serialisation()
{
    QString datas;

    CvSeq *tmp = contour;
    CvPoint *point;

    datas = "{" + Zone::sub_serialisation();
    datas += ",contour=[";

    do{
        datas += "{flags=" + QString::number(tmp->flags) + ",seq=[";
        for(int j = 0; j < tmp->total; ++j){
            point = CV_GET_SEQ_ELEM(CvPoint, tmp, j);
            MyQPointF myPoint(point->x, point->y);
            datas += myPoint.serialisation() + ",";
        }

        datas.remove(datas.size() -1, 1);
        datas += "]},";
    }while((tmp = tmp->h_next) != NULL);

    datas.remove(datas.size() -1, 1);
    datas += "]}";
    return datas;
}

void Selection::deserialisation(QString datas)
{

    QStringList sequences;
    QString sequence;
    QStringList elements;
    QString element;

    QString str = datas.split(",contour=")[0];

    int nbElements;
    QString flags;

    storage = cvCreateMemStorage(0);
    CvSeq * tmpp;
    CvSeq * tmp = cvCreateSeq(0, sizeof(CvSeq), sizeof(CvPoint*), storage); //1570
    contour = tmp;

    Zone::deserialisation(str);
    str = datas.split(",contour=")[1];
    sequences = str.split("flags");

    sequences.removeAt(0);

    nbElements = sequences.size() -1;
    foreach(sequence, sequences){
        sequence.remove(0,1);
        flags = sequence.split(",")[0];

        tmp->flags = flags.toInt();

        sequence = sequence.split("[{")[1];
        sequence.remove(sequence.size() - 5, 5);

        elements =  sequence.split("},{");
        foreach(element, elements){
            MyQPointF point;
            point.deserialisation("{"+element+"}");
            CvPoint *cvPoint = new CvPoint();
            cvPoint->x = point.x();
            cvPoint->y = point.y();

            cvSeqPush(tmp, cvPoint);
        }

        if(nbElements-- != 0){
            tmpp = cvCreateSeq(0, sizeof(CvSeq), sizeof(CvPoint), storage);
            tmp->h_next = tmpp;
            tmpp->h_prev = tmp;
            tmp = tmpp;
        }
    }
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
    CvSeq *tmp = contour;

    qDebug() << "header_size" + tmp->header_size;
    do{
        for(i = 0; i < tmp->total; ++i){
            cvPoint = CV_GET_SEQ_ELEM(CvPoint, tmp, i);
            MyQPointF myPoint(cvPoint->x, cvPoint->y);
            contourQt.append(myPoint);
        }
    }while((tmp = tmp->h_next) != NULL);

    return contourQt;
}
