#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "carte_select.h"
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <points.h>
#include <points.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(path_carte != "")
        carte_select map(path_carte);
    else
        QMessageBox::warning(this, tr("Erreur"),
                             tr("Charger une carte avant de faire cette action."));
}

void MainWindow::on_SelectCarte_clicked()
{
    QString File = QFileDialog::getOpenFileName(this,tr("Choisir une carte"), QDir::currentPath(), tr("carte (*.bmp)"));

    if (!File.isEmpty())
         {
             path_carte = File;
         }
}

void MainWindow::on_SelectSujet_clicked()
{
    QString File = QFileDialog::getOpenFileName(this,QObject::tr("Choisir un sujet"), QDir::currentPath(), QObject::tr("sujet (*.txt)"));

    if (!File.isEmpty())
         {
             points points_sujet(File);
         }
}
