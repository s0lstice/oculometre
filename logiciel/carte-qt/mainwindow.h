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
#include <QTreeView>
#include <QGraphicsItemGroup>

//#include "projet.h"
class Projet;
//#include "Volontaire.h"
class Volontaire;
//#include "myqgraphicsscene.h"
class MyQGraphicsScene;
class MyQAbstractListModel;
class MyTreeZoneModel;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyQGraphicsScene *getCarteScene();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool creatWindow_Carte();
    Projet *getCurent_projet();

private slots:
    void ceratSelection();
    void Selpoints_clicked();
    void on_actionCharger_une_carte_triggered();
    void on_actionCharger_des_Volontaires_triggered();
    void on_actionQuiter_triggered();
    void supprimer_Volontaires();
    void creatGroup();
    void creatRect();
    void creatCercle();
    void removeZone();
    void drawVolontaires();
    void drawZones();
    void switchZoneEtat();

    void on_actionAnalyse_des_zones_et_des_volontaires_triggered();

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

    //doc gestion des zones
    void dockCarte();
    QDockWidget *dock_AnaliseCarte;
    QWidget *widget_AnaliseCarte;
    QPushButton *pb_selzone;
        //tree zones
    QTreeView *zoneView;
    MyTreeZoneModel *zoneModel;

    //gestion des volontaires
    void dockVolontaire();
    QDockWidget *dock_GestionVolontaire;
    QWidget *widget_GestionVolontaire;
    QPushButton *Selpoints;
    QPushButton *afficher_points;
    QPushButton *suppre_points;
    MyQAbstractListModel *listeVolontaireModel;
    QListView *view;

    //affichage de la carte
    QMdiArea *zoneCentrale;
    QMdiSubWindow *window_Carte;
    MyQGraphicsScene *carteScene;
    QGraphicsItemGroup *carteVolontaire;
    QGraphicsItemGroup *carteZone;

    //affichage du resultat

};

#endif // MAINWINDOW_H
