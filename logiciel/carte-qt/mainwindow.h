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
#include <QTableView>
#include <QListView>

//#include "projet.h"
class Projet;
//#include "Volontaire.h"
class Volontaire;
//#include "myqgraphicsscene.h"
class MyQGraphicsScene;
class MyQAbstractListModel;

namespace Ui {
    class MainWindow;
}

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
    void on_actionCharger_des_Volontaires_triggered();
    void on_actionQuiter_triggered();
    void supprimer_Volontaires();

private:
    Projet *pro;
    Ui::MainWindow *ui;
    //QWidget *checkBoxWidget;
    //QVBoxLayout *scrolledLayout;

    //void liste_pointFromListe_Volontaire();
    QVector<Volontaire*> build_VolontaireCheck_list();
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
    MyQAbstractListModel *model;
    QListView *view;

    QMdiArea *zoneCentrale;
    QMdiSubWindow *window_Carte;
    QWidget *widget_Carte;
    QGraphicsView *image;
    MyQGraphicsScene *scene;


};

#endif // MAINWINDOW_H
