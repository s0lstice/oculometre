/**
 * \file mygraphicsview.h
 * \brief Vue affichant la carte et gerant les evenemets de deplacement et de zoome.
 * \author Mickael Puret
 *
 */
#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>

class MyQGraphicsScene;
class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT;
public:
    MyGraphicsView(MyQGraphicsScene* parent);

protected:
    //Holds the current centerpoint for the view, used for panning and zooming
    QPointF CurrentCenterPoint;

    //From panning the view
    QPoint LastPanPoint;

    //Set the current centerpoint in the

    /*!
      @fn void SetCenter(const QPointF& centerPoint);
      @param const QPointF& centerPoint : coordonnée du point sur le quelle il faut se centrer.
      @brief Recarde la vue sur les coordonnées.
      */
    void SetCenter(const QPointF& centerPoint);

    /*!
      @fn QPointF GetCenter();
      @return QPointF : Coordonnée du cente de l'affichage.
      @brief Retourne les coordonnées du cente de l'affichage.
      */
    QPointF GetCenter();

    //Take over the interaction
    //virtual void mousePressEvent(QMouseEvent* event);
    //virtual void mouseReleaseEvent(QMouseEvent* event);
    //virtual void mouseMoveEvent(QMouseEvent* event);

    /*!
      @fn virtual void wheelEvent(QWheelEvent* event);
      @param QWheelEvent* event : action de la molette.
      @brief Zoome et dézoome
      */
    virtual void wheelEvent(QWheelEvent* event);

    /*!
      @fn virtual void wheelEvent(QWheelEvent* event);
      @param QResizeEvent* event.
      @brief Gestion du recadrage.
      */
    virtual void resizeEvent(QResizeEvent* event);
};

#endif // MYGRAPHICSVIEW_H
