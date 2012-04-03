#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include "sujet.h"
#include <QVBoxLayout>
#include <cv.h>
#include <highgui.h>
#include <QGraphicsScene>
#include "myqgraphicsscene.h"

namespace Ui {
    class MainWindow;
}

typedef struct _sujetCheck{
    QCheckBox *checkbox;
    sujet *p_sujet;
}sujetCheck;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void shoowIplImage(IplImage * iplImg);
    ~MainWindow();

    bool getSelection_zone(){
        return selection_zone;
    }

private slots:
    void on_SelectCarte_clicked();

    void on_SelectSujet_clicked();

    void on_pb_selzone_clicked();

    void on_afficher_points_clicked();

    void on_Selpoints_clicked();

    void click(QPoint);

private:
    Ui::MainWindow *ui;
    bool selection_zone;
    QVector<sujetCheck> v_check_sujet;
    void liste_pointFromListe_sujet();
    QVector<sujet*> build_sujetCheck_list();
    QWidget *checkBoxWidget;
    QVBoxLayout *scrolledLayout;
    bool checked;
    MyQGraphicsScene *scene;
};

#endif // MAINWINDOW_H
