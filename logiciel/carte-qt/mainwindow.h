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
#include <QWidget>
#include <QPushButton>
#include <QScrollArea>
#include <QMdiSubWindow>
#include <QMdiArea>
#include "projet.h"

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

    projet *getCurent_projet(){
        return pro;
    }

private slots:
    void pb_selzone_clicked();
    void afficher_points_clicked();
    void Selpoints_clicked();
    void on_actionCharger_une_carte_triggered();
    void on_actionCharger_des_volontaires_triggered();
    void on_actionQuiter_triggered();
    void supprimer_sujets();

private:
    projet *pro;
    Ui::MainWindow *ui;
    bool selection_zone;
    QVector<sujetCheck> v_check_sujet;
    QWidget *checkBoxWidget;
    QVBoxLayout *scrolledLayout;
    bool checked;

    void liste_pointFromListe_sujet();
    QVector<sujet*> build_sujetCheck_list();
    void openWindow_Carte();

    QMenu *viewMenu;

    QDockWidget *dock_AnaliseCarte;
    QWidget *widget_AnaliseCarte;
    QPushButton *pb_selzone;
    QPushButton *pb_selmotif;

    QDockWidget *dock_GestionVolontaire;
    QWidget *widget_GestionVolontaire;
    QPushButton *Selpoints;
    QPushButton *afficher_points;
    QPushButton *suppre_points;
    QScrollArea *ScrollCheckBox;

    QMdiArea *zoneCentrale;
    QMdiSubWindow *window_Carte;
    QWidget *widget_Carte;
    QGraphicsView *image;
    MyQGraphicsScene *scene;
};

#endif // MAINWINDOW_H
