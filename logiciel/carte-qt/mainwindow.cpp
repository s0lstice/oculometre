#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <projet.h>
#include <highgui.h>
#include <QVBoxLayout>
#include <QPixmap>
#include <QDockWidget>
#include <QGraphicsView>
#include <QMdiSubWindow>
#include <QMdiArea>
#include <QStackedWidget>
#include <QGroupBox>

#include "zone.h"
#include "cercle.h"
#include "selection.h"
#include "polygone.h"
#include "carte_select.h"
#include "dialog.h"

#include "projet.h"
//class Projet;
#include "groupe_selection.h"
//class Composit;
#include "volontaire.h"
//class Volontaire;
#include "myqgraphicsscene.h"
//class MyQGraphicsScene;
#include "myqabstractlistmodel.h"
#include "mytreezonemodel.h"

//cree le dock gerant les zones; nom a revoir ?
void MainWindow::dockCarte(){
    /***************************************************************************/
    /********************************AnaliseCarte*******************************/
    /***************************************************************************/
    dock_AnaliseCarte = new QDockWidget(QObject::tr("Analyse de la Carte"), this);
    dock_AnaliseCarte->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    QString bt_style = "QPushButton{ padding: 0 0 0 0px; margin: 0 0 0 0px }";

    pb_selzone = new QPushButton;
    pb_selzone->setText(QObject::tr("Sélection"));
    //pb_selzone->setStyleSheet(bt_style);
    //QPushButton *pb_deletSelection = new QPushButton;
    //pb_deletSelection->setText(QObject::tr("Supprimer"));
    //pb_deletSelection->setStyleSheet(bt_style);
    QVBoxLayout *Layout_Selection = new QVBoxLayout;
    Layout_Selection->addWidget(pb_selzone);
    //Layout_Selection->addWidget(pb_deletSelection);
    //QGroupBox *gb_Selection = new QGroupBox(tr("Selection"));
    //gb_Selection->setLayout(Layout_Selection);

    QPushButton *pb_addGroup = new QPushButton;
    pb_addGroup->setText(QObject::tr("Groupe"));
    //pb_addGroup->setStyleSheet(bt_style);
    //QPushButton *pb_deletGroup = new QPushButton;
    //pb_deletGroup->setText(QObject::tr("Supprimer"));
    //pb_deletGroup->setStyleSheet(bt_style);
    QVBoxLayout *Layout_Group = new QVBoxLayout;
    Layout_Group->addWidget(pb_addGroup);
    //Layout_Group->addWidget(pb_deletGroup);
    //QGroupBox *gb_Group = new QGroupBox(tr("Groupe"));
    //gb_Group->setLayout(Layout_Group);

    QPushButton *pb_addRect = new QPushButton;
    pb_addRect->setText(QObject::tr("Rectangle"));
    //pb_addRect->setStyleSheet(bt_style);
    //QPushButton *pb_deletRect = new QPushButton;
    //pb_deletRect->setText(QObject::tr("Supprimer"));
    //pb_deletRect->setStyleSheet(bt_style);
    QVBoxLayout *Layout_Rect = new QVBoxLayout;
    Layout_Rect->addWidget(pb_addRect);
    //Layout_Rect->addWidget(pb_deletRect);
    //QGroupBox *gb_Rect = new QGroupBox(tr("Rectangle"));
    //gb_Rect->setLayout(Layout_Rect);

    QPushButton *pb_addCercle = new QPushButton;
    pb_addCercle->setText(QObject::tr("Cercle"));
    //pb_addCercle->setStyleSheet(bt_style);
    //QPushButton *pb_deletCercle = new QPushButton;
    //pb_deletCercle->setText(QObject::tr("Supprimer"));
    //pb_deletCercle->setStyleSheet(bt_style);
    QVBoxLayout *Layout_Cercle = new QVBoxLayout;
    Layout_Cercle->addWidget(pb_addCercle);
    //Layout_Cercle->addWidget(pb_deletCercle);
    //QGroupBox *gb_Cercle = new QGroupBox(tr("Cercle"));
    //gb_Cercle->setLayout(Layout_Cercle);

    QGridLayout *Layout_AddOptions = new QGridLayout;
    Layout_AddOptions->addLayout(Layout_Group, 0, 0);
    Layout_AddOptions->addLayout(Layout_Selection, 0, 1);
    Layout_AddOptions->addLayout(Layout_Rect,1 , 0);
    Layout_AddOptions->addLayout(Layout_Cercle, 1, 1);
    QGroupBox *gb_Creer = new QGroupBox(tr("Créer"));
    gb_Creer->setLayout(Layout_AddOptions);

    QPushButton *pb_deletZone = new QPushButton;
    pb_deletZone->setText(QObject::tr("Supprimer"));
    //pb_deletZone->setStyleSheet(bt_style);

    QPushButton *pb_afficher = new QPushButton;
    pb_afficher->setText(QObject::tr("Afficher les zones"));
    //pb_afficher->setStyleSheet(bt_style);

    QPushButton *pb_inserser = new QPushButton;
    pb_inserser->setText(QObject::tr("(Dé)Sélectionner tout"));

    widget_AnaliseCarte = new QWidget;
    dock_AnaliseCarte->setWidget(widget_AnaliseCarte);

    zoneModel = new MyTreeZoneModel();
    zoneView = new QTreeView();
    zoneView->header()->hide();

    zoneModel->setRootNode(pro->getZones());
    zoneView->setModel(zoneModel);

    QVBoxLayout *Layout_AnaliseCarte = new QVBoxLayout;
    Layout_AnaliseCarte->addWidget(gb_Creer);
    Layout_AnaliseCarte->addWidget(pb_deletZone);
    Layout_AnaliseCarte->addWidget(pb_afficher);
    Layout_AnaliseCarte->addWidget(pb_inserser);
    Layout_AnaliseCarte->addWidget(zoneView);

    connect(pb_addGroup,SIGNAL(clicked()),this,SLOT(creatGroup()));
    connect(pb_selzone,SIGNAL(clicked()),this,SLOT(ceratSelection()));
    connect(pb_addRect,SIGNAL(clicked()),this,SLOT(creatRect()));
    connect(pb_addCercle,SIGNAL(clicked()),this,SLOT(creatCercle()));

    connect(pb_deletZone,SIGNAL(clicked()),this,SLOT(removeZone()));
    widget_AnaliseCarte->setLayout(Layout_AnaliseCarte);

    addDockWidget(Qt::LeftDockWidgetArea, dock_AnaliseCarte);
    viewMenu->addAction(dock_AnaliseCarte->toggleViewAction());
}

//cree le dock avec les Volontaire
void MainWindow::dockVolontaire(){
    /***************************************************************************/
    /*****************************GestionVolontaire*****************************/
    /***************************************************************************/
    dock_GestionVolontaire = new QDockWidget(QObject::tr("Gestion des Volontaires"), this);
    dock_GestionVolontaire->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    view = new QListView();

    widget_GestionVolontaire = new QWidget;
    dock_GestionVolontaire->setWidget(widget_GestionVolontaire);

    Selpoints = new QPushButton;
    Selpoints->setText(QObject::tr("(Dé)Sélectionner tout"));
    afficher_points = new QPushButton;
    afficher_points->setText(QObject::tr("Afficher les points"));
    suppre_points = new QPushButton;
    suppre_points->setText(QObject::tr("Supprimer des points"));

    connect(suppre_points,SIGNAL(clicked()),this,SLOT(supprimer_Volontaires()));
    connect(afficher_points,SIGNAL(clicked()),this,SLOT(afficher_points_clicked()));
    connect(Selpoints,SIGNAL(clicked()),this,SLOT(Selpoints_clicked()));
    QVBoxLayout *Layout_GestionVolontaire = new QVBoxLayout;
    Layout_GestionVolontaire->addWidget(suppre_points);
    Layout_GestionVolontaire->addWidget(afficher_points);
    Layout_GestionVolontaire->addWidget(Selpoints);
    Layout_GestionVolontaire->addWidget(view);

    widget_GestionVolontaire->setLayout(Layout_GestionVolontaire);

    addDockWidget(Qt::LeftDockWidgetArea, dock_GestionVolontaire);
    viewMenu->addAction(dock_GestionVolontaire->toggleViewAction());
}

//constructeur
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    zoneCentrale = new QMdiArea;
    setCentralWidget(zoneCentrale);

    /**********************************MenuBarra********************************/
    viewMenu = menuBar()->addMenu(tr("&Outils"));

    /***********************************Projet**********************************/
    pro = new Projet();

    /*****************************GestionVolontaire*****************************/
    model = new MyQAbstractListModel(this);
    dockVolontaire();

    /********************************AnaliseCarte*******************************/
    dockCarte();
}

//destructeur; a pofiner !!
MainWindow::~MainWindow()
{

    delete ui;
}

//ouverture de la fenetre, la gestion de la fenetre est a revoir
void MainWindow::openWindow_Carte()
{
    /***************************************************************************/
    /************************************Map************************************/
    /***************************************************************************/

    QString path_carte = pro->get_path_carte();

    carteScene = new MyQGraphicsScene(this);

    QGraphicsView *carteView = new QGraphicsView(carteScene);

    QWidget *carteWidget = new QWidget;
    carteWidget->setStyleSheet("background: transparent");

    QVBoxLayout *Layout_Carte = new QVBoxLayout;
    Layout_Carte->addWidget(carteView);

    carteWidget->setLayout(Layout_Carte);
    window_Carte = zoneCentrale->addSubWindow(carteWidget);
    window_Carte->setWindowTitle(QObject::tr("Carte"));
    window_Carte->setAttribute(Qt::WA_DeleteOnClose);
    window_Carte->showMaximized();

    //s'il y a une catre de charger en memoir alors on l'affiche
    if(path_carte != "")
        carteScene->shoowIplImage(pro->get_carte());
}

MyQGraphicsScene *MainWindow::getCarteScene(){
    return carteScene;
}

//fermeture de la fenetre, la gestion de la fenetre est a revoir
void MainWindow::closeWindow_Carte(){
    delete carteScene;
    delete window_Carte;
}

void MainWindow::creatWindow_Carte(){
    if(zoneCentrale->subWindowList().size() == 0)//la gestion de la fenetre est a revoir
        openWindow_Carte();
}

void MainWindow::creatGroup(){
    QString path_carte = pro->get_path_carte();

    if(path_carte != ""){
        QModelIndex selctionItem = zoneView->selectionModel()->currentIndex();
        Groupe_selection *main_composite;

        if(selctionItem.isValid() == false)
            main_composite = pro->getZones();
        else
            main_composite = zoneModel->nodeFromIndex(selctionItem);

        if(main_composite->getType() != composite)
            main_composite = main_composite->getParent();

        Groupe_selection *groupe = new Groupe_selection(main_composite);
        main_composite->appendChild(groupe);

        zoneModel->setRootNode(pro->getZones());
    }else
        QMessageBox::warning(this, tr("Erreur"), tr("Charger une carte avant de faire cette action."));
}

void MainWindow::creatRect(){
    QString path_carte = pro->get_path_carte();

    if(path_carte != ""){
        QModelIndex selctionItem = zoneView->selectionModel()->currentIndex();
        Groupe_selection *main_composite;

        if(selctionItem.isValid() == false)
            main_composite = pro->getZones();
        else
            main_composite = zoneModel->nodeFromIndex(selctionItem);

        if(main_composite->getType() != composite)
            main_composite = main_composite->getParent();

        Polygone *poly = new Polygone(main_composite);
        main_composite->appendChild(poly);

        zoneModel->setRootNode(pro->getZones());
    }else
        QMessageBox::warning(this, tr("Erreur"), tr("Charger une carte avant de faire cette action."));
}

void MainWindow::creatCercle(){
    QString path_carte = pro->get_path_carte();

    if(path_carte != ""){
        QModelIndex selctionItem = zoneView->selectionModel()->currentIndex();
        Groupe_selection *main_composite;

        if(selctionItem.isValid() == false)
            main_composite = pro->getZones();
        else
            main_composite = zoneModel->nodeFromIndex(selctionItem);

        if(main_composite->getType() != composite)
            main_composite = main_composite->getParent();

        Cercle *cercle = new Cercle(main_composite);
        main_composite->appendChild(cercle);

        zoneModel->setRootNode(pro->getZones());
    }else
        QMessageBox::warning(this, tr("Erreur"), tr("Charger une carte avant de faire cette action."));
}

void MainWindow::removeZone(){
    QModelIndex selctionItem = zoneView->selectionModel()->currentIndex();
    Groupe_selection *parentZone;
    Zone *removeZone;

    if(selctionItem.isValid() == false){
        QMessageBox::warning(this, tr("Erreur"), tr("Selectionner l'élément à supprimer."));
        return;
    }

    removeZone = zoneModel->nodeFromIndex(selctionItem);
    parentZone = removeZone->getParent();

    parentZone->removeChild(removeZone);
    zoneModel->setRootNode(pro->getZones());
}

//gestion de la selection de zone en fonction de couleur
void MainWindow::ceratSelection()
{
    QString path_carte = pro->get_path_carte();

    if(path_carte != ""){
        if(carteScene->getSelection_zone() == false){
            QModelIndex selctionItem = zoneView->selectionModel()->currentIndex();
            Groupe_selection *main_composite;

            if(selctionItem.isValid() == false)
                main_composite = pro->getZones();
            else
                main_composite = zoneModel->nodeFromIndex(selctionItem);

            if(main_composite->getType() != composite)
                main_composite = main_composite->getParent();

            Selection *select = new Selection(main_composite);
            main_composite->appendChild(select);

            Carte_select *selction_tool = new Carte_select(this);
            carteScene->setZone_courante((Zone *)select);
            carteScene->setCarte_selection(selction_tool);

            pb_selzone->setText(QObject::tr("Arrêter"));
            carteScene->setSelection_zone(true);
            zoneModel->setRootNode(pro->getZones());
        }
        else
        {
            carteScene->delCarte_selection();
            carteScene->nullZone_courante();
            carteScene->setSelection_zone(false);
            pb_selzone->setText(QObject::tr("Sélection"));
        }
    }
    else
        QMessageBox::warning(this, tr("Erreur"), tr("Charger une carte avant de faire cette action."));
}

//affiche les Volontaire selectionnes
//Arevoir
void MainWindow::afficher_points_clicked()
{
    QString path_carte = pro->get_path_carte();
    if(model->rowCount() != 0){
        if(path_carte != ""){
            creatWindow_Carte();//on s'assure que la fenetre existe
            carteScene->DrowVolontaires();
        }
        else
            QMessageBox::warning(this, tr("Erreur"), tr("Charger une carte avant de faire cette action."));
    }else{
        QMessageBox::warning(this, tr("Erreur"), tr("Sélectionner des points avant de faire cette action."));
    }
}


//invetion de la selection des volontaires, non nom n'est pas terible
void MainWindow::Selpoints_clicked()
{
    if(model->rowCount() != 0){
        model->switchEtat();
        view->setModel(model);
    }else{
        QMessageBox::warning(this, tr("Erreur"), tr("Sélectionner des points avant de faire cette action."));
    }
}

//ouverture de la map
void MainWindow::on_actionCharger_une_carte_triggered()
{
    QString File = QFileDialog::getOpenFileName(this,tr("Choisir une carte"), QDir::homePath(), tr("carte (*.bmp)"));

    if (!File.isEmpty())
         {
             IplImage *image;
             image = cvLoadImage(File.toStdString().c_str());
             pro->set_carte(File, image);
             creatWindow_Carte();
             carteScene->shoowIplImage(image);
         }
}

//ouverture des Volontaires
void MainWindow::on_actionCharger_des_Volontaires_triggered()
{
    QStringList fileNames;

    QFileDialog Dialog(this);
    Dialog.setDirectory(QDir::homePath());
    Dialog.setFileMode(QFileDialog::ExistingFiles);
    Dialog.setFilter(QObject::tr("Volontaire (*.txt)"));

    if (Dialog.exec()){
        fileNames = Dialog.selectedFiles();
        pro->charger_Volontaires(fileNames);

        //mise a jour du model
        model->setItems(pro->getVolontaires());
        view->setModel(model);
    }
}

//quite l'application par le menu
void MainWindow::on_actionQuiter_triggered()
{
    this->close();
}

//supression des Volontaires selectionné
//n'est pas ici
void MainWindow::supprimer_Volontaires(){
    if(model->rowCount() != 0){
        model->removeCheckedRow();
    }else{
        QMessageBox::warning(this, tr("Erreur"), tr("Sélectionner des points avant de faire cette action."));
    }
}

//renvoir le projet en cour.
Projet *MainWindow::getCurent_projet(){
    return pro;
}
