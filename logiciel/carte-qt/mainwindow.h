#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <QVBoxLayout>
#include <cv.h>
#include <highgui.h>
#include <QGraphicsScene>
#include <QWidget>
#include <QPushButton>
#include <QScrollArea>
#include <QMdiSubWindow>
#include <QMdiArea>

//#include "projet.h"
class Projet;
//#include "sujet.h"
class Sujet;
//#include "myqgraphicsscene.h"
class MyQGraphicsScene;

namespace Ui {
    class MainWindow;
}

typedef struct _sujetCheck{
    QCheckBox *checkbox;
    Sujet *p_sujet;
}sujetCheck;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void shoowIplImage(IplImage * iplImg);
    ~MainWindow();

    Projet *getCurent_projet();

private slots:
    void pb_selzone_clicked();
    void afficher_points_clicked();
    void Selpoints_clicked();
    void on_actionCharger_une_carte_triggered();
    void on_actionCharger_des_volontaires_triggered();
    void on_actionQuiter_triggered();
    void supprimer_sujets();

private:
    Projet *pro;
    Ui::MainWindow *ui;
    QVector<sujetCheck> v_check_sujet;
    QWidget *checkBoxWidget;
    QVBoxLayout *scrolledLayout;
    bool checked;

    void liste_pointFromListe_sujet();
    QVector<Sujet*> build_sujetCheck_list();
    void openWindow_Carte();
    void closeWindow_Carte();

    QMenu *viewMenu;

    void dockCarte();
    QDockWidget *dock_AnaliseCarte;
    QWidget *widget_AnaliseCarte;
    QPushButton *pb_selzone;
    QPushButton *pb_selmotif;

    void dockVolontaire();
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
