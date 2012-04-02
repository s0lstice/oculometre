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

void MainWindow::liste_pointFromListe_sujet(){
    projet *pro = projet::proj();
    QVector<sujet *> v_sujet = pro->get_sujet();
    QWidget *checkBoxWidget = new QWidget(ui->ScrollCheckBox);
    QVBoxLayout *scrolledLayout = new QVBoxLayout(checkBoxWidget);

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

    ui->ScrollCheckBox->setWidget(checkBoxWidget);

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

void MainWindow::on_pb_selzone_clicked()
{
    QString path_carte;
    projet *pro = projet::proj();
    path_carte = pro->get_path_carte();

    if(path_carte != ""){
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

void MainWindow::on_afficher_points_clicked()
{
    QVector<sujet*> v_sujets = build_sujetCheck_list();
    if(v_sujets.size() != 0)
        carte_points drow(build_sujetCheck_list());
}
