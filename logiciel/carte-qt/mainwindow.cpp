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

#include "zone.h"
#include "cercle.h"
#include "selection.h"
#include "polygone.h"
#include "carte_select.h"
#include "carte_points.h"
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

//cree le dock gerant les zones; nom a revoir ?
void MainWindow::dockCarte(){
    /***************************************************************************/
    /********************************AnaliseCarte*******************************/
    /***************************************************************************/
    dock_AnaliseCarte = new QDockWidget(QObject::tr("Analyse de la Carte"), this);
    dock_AnaliseCarte->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    widget_AnaliseCarte = new QWidget;
    dock_AnaliseCarte->setWidget(widget_AnaliseCarte);

    pb_selzone = new QPushButton;
    pb_selzone->setText(QObject::tr("Sélectionner une Zone"));
    pb_selmotif = new QPushButton;
    pb_selmotif->setText(QObject::tr("Ajouter un motif"));

    connect(pb_selzone,SIGNAL(clicked()),this,SLOT(pb_selzone_clicked()));
    QVBoxLayout *Layout_AnaliseCarte = new QVBoxLayout;
    Layout_AnaliseCarte->addWidget(pb_selzone);
    Layout_AnaliseCarte->addWidget(pb_selmotif);

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
    widget_Carte = NULL;

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

    widget_Carte = new QWidget;

    image = new QGraphicsView;
    scene = new MyQGraphicsScene(this);
    image->setScene(scene);

    QVBoxLayout *Layout_Carte = new QVBoxLayout;
    Layout_Carte->addWidget(image);

    widget_Carte->setLayout(Layout_Carte);
    window_Carte = zoneCentrale->addSubWindow(widget_Carte);
    window_Carte->setWindowTitle(QObject::tr("Carte"));
    window_Carte->setAttribute(Qt::WA_DeleteOnClose);
    window_Carte->showMaximized();

    //connect(widget_Carte, SIGNAL(close()), this, SLOT(closeWindow_carte()));
}

//fermeture de la fenetre, la gestion de la fenetre est a revoir
void MainWindow::closeWindow_Carte(){
    delete scene;
    delete image;
    delete window_Carte;
    delete widget_Carte;
}

//afichage de l'image, a metre dans MyQGraphicssene ?
void  MainWindow::shoowIplImage(IplImage *iplImg)
{
    int h = iplImg->height;
    int w = iplImg->width;
    int channels = iplImg->nChannels;
    QImage qimg(w, h, QImage::Format_ARGB32);
    char *data = iplImg->imageData;

    for (int y = 0; y < h; y++, data += iplImg->widthStep)
    {
        for (int x = 0; x < w; x++)
        {
        char r, g, b, a = 0;
        if (channels == 1)
        {
            r = data[x * channels];
            g = data[x * channels];
            b = data[x * channels];
        }
        else if (channels == 3 || channels == 4)
        {
            r = data[x * channels + 2];
            g = data[x * channels + 1];
            b = data[x * channels];
        }

        if (channels == 4)
        {
            a = data[x * channels + 3];
            qimg.setPixel(x, y, qRgba(r, g, b, a));
        }
        else
        {
            qimg.setPixel(x, y, qRgb(r, g, b));
        }
        }
    }

    if(zoneCentrale->subWindowList().size() == 0)//la gestion de la fenetre est a revoir
        openWindow_Carte();
    scene->addPixmap(QPixmap::fromImage(qimg));
}

//gestion de la selection de zone en fonction de couleur
void MainWindow::pb_selzone_clicked()
{
    QString path_carte = pro->get_path_carte();

    if(path_carte != ""){
        if(scene->getSelection_zone() == false){
            Selection *select = new Selection(pro->getZones());
            Groupe_selection *main_composite = pro->getZones();

            Carte_select *selction_tool = new Carte_select(this);
            main_composite->appendChild(select);
            scene->setZone_courante((Zone *)select);
            scene->setCarte_selection(selction_tool);

            pb_selzone->setText(QObject::tr("Arrêter la sélection"));
            scene->setSelection_zone(true);
        }
        else
        {
            scene->delCarte_selection();
            scene->nullZone_courante();
            scene->setSelection_zone(false);
            pb_selzone->setText(QObject::tr("Sélectionner une Zone"));
        }
    }
    else
        QMessageBox::warning(this, tr("Erreur"), tr("Charger une carte avant de faire cette action."));
}

//construit une liste de Volontaire en fonction des selectionnes
//Arevoir !!
/*
QVector<Volontaire*> MainWindow::build_VolontaireCheck_list(){
    QVector<Volontaire*> v_Volontaires;
    if(v_check_Volontaire.size() != 0){
        foreach(VolontaireCheck chekBox,v_check_Volontaire){
            if(chekBox.checkbox->isChecked() == true){
                v_Volontaires.append(chekBox.p_Volontaire);
            }
        }
        return v_Volontaires;
    }else{
        Dialog(QObject::tr("Sélectionner des points avant de faire cette action.")).exec();
        return v_Volontaires;
    }
}
*/
//affiche les Volontaire selectionnes
//Arevoir
void MainWindow::afficher_points_clicked()
{
    if(model->rowCount() != 0){
        model->afficheVolontaire();
    }else{
        QMessageBox::warning(this, tr("Erreur"), tr("Sélectionner des points avant de faire cette action."));
    }
}

//invetion de la selection
//n'est plus ici
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
             shoowIplImage(image);
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
