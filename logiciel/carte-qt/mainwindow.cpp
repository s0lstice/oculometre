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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    cvNamedWindow("Map", CV_WINDOW_AUTOSIZE);
    selection_zone = false;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    //Destruction de la fenêtre.
    cvDestroyWindow("Map");
}

void MainWindow::on_SelectCarte_clicked()
{
    QString File = QFileDialog::getOpenFileName(this,tr("Choisir une carte"), QDir::homePath(), tr("carte (*.bmp)"));

    if (!File.isEmpty())
         {
             projet *pro = projet::proj();
             pro->set_path_carte(File);
             cvShowImage("Map", cvLoadImage(File.toStdString().c_str()));
         }
}

void MainWindow::on_SelectSujet_clicked()
{
    //QString File = QFileDialog::getOpenFileName(this,QObject::tr("Choisir un sujet"), QDir::currentPath(), QObject::tr("sujet (*.txt)"));

    QStringList fileNames;

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setFilter(QObject::tr("sujet (*.txt)"));

    if (dialog.exec()){
        fileNames = dialog.selectedFiles();
        projet::proj()->charger_sujets(fileNames);
        //qDebug() << fileNames;
    }
}

void MainWindow::on_pb_selzone_clicked()
{
    QString path_carte;
    projet *pro = projet::proj();
    path_carte = pro->get_path_carte();

    if(path_carte != ""){
        qDebug() << "go";
        carte_select map(path_carte);

        /*if(selection_zone == false){
            selection_zone = true;


        }
        else
        {
            ui->pb_selzone->setText(QObject::tr("Sélectionner une zone"));

            selection_zone = false;
        }*/
    }
    else
        QMessageBox::warning(this, tr("Erreur"), tr("Charger une carte avant de faire cette action."));
}

void MainWindow::on_afficher_points_clicked()
{
    carte_points();
}
