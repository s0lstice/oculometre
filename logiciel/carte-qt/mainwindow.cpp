#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "carte_select.h"
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <projet.h>
#include <cv.h>
#include <highgui.h>
#include "carte_points.h"
#include <QVBoxLayout>
#include "dialog.h"
#include <QPixmap>
#include <QDockWidget>
#include <QGraphicsView>
#include <QMdiSubWindow>
#include <QMdiArea>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //cvNamedWindow("Map", CV_WINDOW_AUTOSIZE);
    QString dock_style = "QDockWidget {"
            "border: 2px solid #a0a0a0; "
            "border-radius: 5px;"
            "}"

            "QDockWidget::title {"
            "background-color: #a0a0a0;"
            "subcontrol-position: top left;" /* position at the top left*/
            "padding:2 13px;"
            "}";
    ui->setupUi(this);
    zoneCentrale = new QMdiArea;
    setCentralWidget(zoneCentrale);
    widget_Carte = NULL;

    checked = true;
    selection_zone = false;


    /***************************************************************************/
    /**********************************MenuBarra********************************/
    /***************************************************************************/
    viewMenu = menuBar()->addMenu(tr("&Outils"));

    /***************************************************************************/
    /********************************AnaliseCarte*******************************/
    /***************************************************************************/
    dock_AnaliseCarte = new QDockWidget(QObject::tr("Analise de la Carte"), this);
    dock_AnaliseCarte->setStyleSheet(dock_style);
    dock_AnaliseCarte->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);


    widget_AnaliseCarte = new QWidget;
    dock_AnaliseCarte->setWidget(widget_AnaliseCarte);

    pb_selzone = new QPushButton;
    pb_selzone->setText(QObject::tr("Sélectionner une zone"));
    pb_selmotif = new QPushButton;
    pb_selmotif->setText(QObject::tr("Ajouter un motif"));

    connect(pb_selzone,SIGNAL(clicked()),this,SLOT(pb_selzone_clicked()));
    QVBoxLayout *Layout_AnaliseCarte = new QVBoxLayout;
    Layout_AnaliseCarte->addWidget(pb_selzone);
    Layout_AnaliseCarte->addWidget(pb_selmotif);

    widget_AnaliseCarte->setLayout(Layout_AnaliseCarte);

    addDockWidget(Qt::LeftDockWidgetArea, dock_AnaliseCarte);
    viewMenu->addAction(dock_AnaliseCarte->toggleViewAction());

    /***************************************************************************/
    /*****************************GestionVolontaire*****************************/
    /***************************************************************************/
    dock_GestionVolontaire = new QDockWidget(QObject::tr("Gestion des volontaires"), this);
    dock_GestionVolontaire->setStyleSheet(dock_style);
    dock_GestionVolontaire->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    widget_GestionVolontaire = new QWidget;
    dock_GestionVolontaire->setWidget(widget_GestionVolontaire);

    Selpoints = new QPushButton;
    Selpoints->setText(QObject::tr("(Dé)Sélectionner tout"));
    afficher_points = new QPushButton;
    afficher_points->setText(QObject::tr("Afficher les points"));
    suppre_points = new QPushButton;
    suppre_points->setText(QObject::tr("Supprimer des points"));
    ScrollCheckBox = new QScrollArea;

    connect(suppre_points,SIGNAL(clicked()),this,SLOT(supprimer_sujets()));
    connect(afficher_points,SIGNAL(clicked()),this,SLOT(afficher_points_clicked()));
    connect(Selpoints,SIGNAL(clicked()),this,SLOT(Selpoints_clicked()));
    QVBoxLayout *Layout_GestionVolontaire = new QVBoxLayout;
    Layout_GestionVolontaire->addWidget(suppre_points);
    Layout_GestionVolontaire->addWidget(afficher_points);
    Layout_GestionVolontaire->addWidget(Selpoints);
    Layout_GestionVolontaire->addWidget(ScrollCheckBox);

    widget_GestionVolontaire->setLayout(Layout_GestionVolontaire);

    addDockWidget(Qt::LeftDockWidgetArea, dock_GestionVolontaire);
    viewMenu->addAction(dock_GestionVolontaire->toggleViewAction());
}

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

MainWindow::~MainWindow()
{

    if(v_check_sujet.size() != 0){
        foreach(sujetCheck chekBox,v_check_sujet){
            if(chekBox.checkbox->isChecked() == true){
                delete chekBox.checkbox;
            }
        }
    }

    //Destruction de la fenêtre.
    //cvDestroyWindow("Map");

    //delete scrolledLayout;
    //delete checkBoxWidget;
    delete ui;


}

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

    if(zoneCentrale->subWindowList().size() == 0)
        openWindow_Carte();
    scene->addPixmap(QPixmap::fromImage(qimg));
    //window_Carte->resize(qimg.width(),qimg.height());
}

void MainWindow::liste_pointFromListe_sujet(){
    projet *pro = projet::proj();
    QVector<sujet *> v_sujet = pro->get_sujet();
    checkBoxWidget = new QWidget(ScrollCheckBox);
    scrolledLayout = new QVBoxLayout(checkBoxWidget);

    foreach(sujet *sujet, v_sujet){
        QCheckBox *check = new QCheckBox();
        check->setText(sujet->getId_sujet());
        check->setChecked(true);
        scrolledLayout->addWidget(check);

        sujetCheck str_sujet;
        str_sujet.checkbox = check;
        str_sujet.p_sujet = sujet;
        v_check_sujet.append(str_sujet);
    }

    ScrollCheckBox->setWidget(checkBoxWidget);

}

void MainWindow::pb_selzone_clicked()
{
    QString path_carte;
    projet *pro = projet::proj();
    path_carte = pro->get_path_carte();

    if(path_carte != ""){
        //carte_select map(path_carte);

        if(selection_zone == false){
            selection_zone = true;
            pb_selzone->setText(QObject::tr("Arrêter la sélection"));
        }
        else
        {
            pb_selzone->setText(QObject::tr("Sélectionner une zone"));
            selection_zone = false;
        }
    }
    else
        QMessageBox::warning(this, tr("Erreur"), tr("Charger une carte avant de faire cette action."));
}

QVector<sujet*> MainWindow::build_sujetCheck_list(){
    QVector<sujet*> v_sujets;
    if(v_check_sujet.size() != 0){
        foreach(sujetCheck chekBox,v_check_sujet){
            if(chekBox.checkbox->isChecked() == true){
                v_sujets.append( chekBox.p_sujet);
            }
        }
        return v_sujets;
    }else{
        Dialog(QObject::tr("Sélectionner des points avant de faire cette action.")).exec();
        return v_sujets;
    }
}

void MainWindow::afficher_points_clicked()
{
    QVector<sujet*> v_sujets = build_sujetCheck_list();
    if(v_sujets.size() != 0)
        carte_points drow(build_sujetCheck_list(), this);
    else{
        projet *pro = projet::proj();
        shoowIplImage(cvLoadImage(pro->get_path_carte().toStdString().c_str()));
    }
}

void MainWindow::Selpoints_clicked()
{
    if(v_check_sujet.size() != 0){
        foreach(sujetCheck chekBox,v_check_sujet){
            chekBox.checkbox->setChecked(!checked);
        }
        checked = !checked;
        ScrollCheckBox->setWidget(checkBoxWidget);
    }else{
        Dialog(QObject::tr("Sélectionner des points avant de faire cette action.")).exec();
        return;
    }
}

void MainWindow::on_actionCharger_une_carte_triggered()
{
    QString File = QFileDialog::getOpenFileName(this,tr("Choisir une carte"), QDir::homePath(), tr("carte (*.bmp)"));

    if (!File.isEmpty())
         {
             projet *pro = projet::proj();
             pro->set_path_carte(File);
             //cvShowImage("Map", cvLoadImage(File.toStdString().c_str()));
             shoowIplImage(cvLoadImage(File.toStdString().c_str()));
         }
}

void MainWindow::on_actionCharger_des_volontaires_triggered()
{
    QStringList fileNames;

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setFilter(QObject::tr("sujet (*.txt)"));

    if (dialog.exec()){
        fileNames = dialog.selectedFiles();
        projet::proj()->charger_sujets(fileNames);
    }
    liste_pointFromListe_sujet();
}

void MainWindow::on_actionQuiter_triggered()
{
    this->close();
}

void MainWindow::supprimer_sujets(){
    sujetCheck s_sujet;
    int i = 0;
    projet *pro = projet::proj();

    foreach(s_sujet, v_check_sujet){
        if(s_sujet.checkbox->isChecked() == true){
            delete s_sujet.p_sujet;
            delete s_sujet.checkbox;
            v_check_sujet.remove(i);
            pro->rm_sujet(i);
        }
        else
            i++;
    }
}
