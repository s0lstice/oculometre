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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //cvNamedWindow("Map", CV_WINDOW_AUTOSIZE);
    ui->setupUi(this);

    scene = new MyQGraphicsScene(this);
    checked = true;
    selection_zone = false;


    ui->image->setScene(scene);

    //connect(scene, SIGNAL(clicked(QPoint)), this, SLOT(click(QPoint)));

}
void MainWindow::click(QPoint){
    qDebug() << "click";
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

    scene->addPixmap(QPixmap::fromImage(qimg));

}

void MainWindow::liste_pointFromListe_sujet(){
    projet *pro = projet::proj();
    QVector<sujet *> v_sujet = pro->get_sujet();
    checkBoxWidget = new QWidget(ui->ScrollCheckBox);
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

    ui->ScrollCheckBox->setWidget(checkBoxWidget);

}

void MainWindow::on_SelectCarte_clicked()
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
        //carte_select map(path_carte);

        if(selection_zone == false){
            selection_zone = true;
            ui->pb_selzone->setText(QObject::tr("Arrêter la sélection"));
        }
        else
        {
            ui->pb_selzone->setText(QObject::tr("Sélectionner une zone"));
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

void MainWindow::on_afficher_points_clicked()
{
    QVector<sujet*> v_sujets = build_sujetCheck_list();
    if(v_sujets.size() != 0)
        carte_points drow(build_sujetCheck_list(), this);
    else{
        projet *pro = projet::proj();
        shoowIplImage(cvLoadImage(pro->get_path_carte().toStdString().c_str()));
    }
}

void MainWindow::on_Selpoints_clicked()
{
    if(v_check_sujet.size() != 0){
        foreach(sujetCheck chekBox,v_check_sujet){
            chekBox.checkbox->setChecked(!checked);
        }
        checked = !checked;
        ui->ScrollCheckBox->setWidget(checkBoxWidget);
    }else{
        Dialog(QObject::tr("Sélectionner des points avant de faire cette action.")).exec();
        return;
    }
}
