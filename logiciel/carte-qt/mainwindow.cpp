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
#include <QTextBrowser>
#include <QLabel>

#include "carte_select.h"
#include "zone.h"
#include "cercle.h"
#include "selection.h"
#include "rectangle.h"
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
#include "mygraphicsview.h"
#include "analyse.h"

//cree le dock gerant les zones; nom a revoir ?
void MainWindow::dockCarte(){
    /***************************************************************************/
    /********************************AnaliseCarte*******************************/
    /***************************************************************************/
    dock_AnaliseCarte = new QDockWidget(QObject::tr("Analyse de la Carte"), this);
    dock_AnaliseCarte->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    pb_selzone = new QPushButton;
    pb_selzone->setText(QObject::tr("Sélection"));
    QVBoxLayout *Layout_Selection = new QVBoxLayout;
    Layout_Selection->addWidget(pb_selzone);
    QPushButton *pb_addGroup = new QPushButton;
    pb_addGroup->setText(QObject::tr("Groupe"));
    QVBoxLayout *Layout_Group = new QVBoxLayout;
    Layout_Group->addWidget(pb_addGroup);

    QPushButton *pb_addRect = new QPushButton;
    pb_addRect->setText(QObject::tr("Rectangle"));
    QVBoxLayout *Layout_Rect = new QVBoxLayout;
    Layout_Rect->addWidget(pb_addRect);

    QPushButton *pb_addCercle = new QPushButton;
    pb_addCercle->setText(QObject::tr("Cercle"));
    QVBoxLayout *Layout_Cercle = new QVBoxLayout;
    Layout_Cercle->addWidget(pb_addCercle);


    QGridLayout *Layout_AddOptions = new QGridLayout;
    Layout_AddOptions->addLayout(Layout_Group, 0, 0);
    Layout_AddOptions->addLayout(Layout_Selection, 0, 1);
    Layout_AddOptions->addLayout(Layout_Rect,1 , 0);
    Layout_AddOptions->addLayout(Layout_Cercle, 1, 1);
    QGroupBox *gb_Creer = new QGroupBox(tr("Créer"));
    gb_Creer->setLayout(Layout_AddOptions);

    QPushButton *pb_deletZone = new QPushButton;
    pb_deletZone->setText(QObject::tr("Supprimer (élément | groupe)"));

    QPushButton *pb_afficher = new QPushButton;
    pb_afficher->setText(QObject::tr("Afficher les zones"));

    QPushButton *pb_inserser = new QPushButton;
    pb_inserser->setText(QObject::tr("(Dé)Sélectionner tout"));

    widget_AnaliseCarte = new QWidget;
    dock_AnaliseCarte->setWidget(widget_AnaliseCarte);

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
    //connect(pb_afficher,SIGNAL(clicked()),carteScene,SLOT(drawZones()));
    connect(pb_afficher,SIGNAL(clicked()),this,SLOT(drawZones()));
    connect(pb_inserser,SIGNAL(clicked()),this,SLOT(switchZoneEtat()));
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
    //connect(afficher_points,SIGNAL(clicked()),carteScene,SLOT(DrowVolontaires()));
    connect(afficher_points,SIGNAL(clicked()),this,SLOT(drawVolontaires()));
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
    carteScene = NULL;
    /**********************************MenuBarra********************************/
    viewMenu = menuBar()->addMenu(tr("&Outils"));

    /***********************************Projet**********************************/
    pro = new Projet();

    /*****************************GestionVolontaire*****************************/
    listeVolontaireModel = new MyQAbstractListModel(this);
    dockVolontaire();

    /********************************AnaliseCarte*******************************/
    zoneModel = new MyTreeZoneModel(this);
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

    MyGraphicsView *carteView = new MyGraphicsView(carteScene);

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

void MainWindow::drawVolontaires(){
    if(carteScene != NULL)
        carteScene->DrawVolontaires();
}

void MainWindow::drawZones(){
    if(carteScene != NULL)
        carteScene->drawZones();
}

void MainWindow::switchZoneEtat(){
    if(zoneModel != NULL)
        zoneModel->switchEtat();
}
bool MainWindow::creatWindow_Carte(){
    if(pro->get_path_carte() != ""){
        if(zoneCentrale->subWindowList().size() == 0)//la gestion de la fenetre est a revoir
            openWindow_Carte();
        return true;
    }else
        QMessageBox::warning(this, tr("Erreur"), tr("Charger une carte avant de faire cette action."));
    return false;
}

void MainWindow::creatGroup(){
    if(creatWindow_Carte() == true){
        zoneModel->addGroup(zoneView->selectionModel()->currentIndex());
    }
}

void MainWindow::creatRect(){
    if(creatWindow_Carte() == true){
        Rectangle * rectangle = zoneModel->addRect(zoneView->selectionModel()->currentIndex());
        carteScene->setZone_courante((Zone *)rectangle);
        carteScene->activerCreation(rectangle->getType());

    }
}

void MainWindow::creatCercle(){
    if(creatWindow_Carte() == true){
        Cercle * cercle = zoneModel->addCercle(zoneView->selectionModel()->currentIndex());
        carteScene->setZone_courante((Zone *)cercle);
        carteScene->activerCreation(cercle->getType());
    }
}

void MainWindow::removeZone(){
    QModelIndex selectionItem = zoneView->selectionModel()->currentIndex();
    Groupe_selection *parentZone;
    Zone *removeZone;

    if(selectionItem.isValid() == false){
        QMessageBox::warning(this, tr("Erreur"), tr("Selectionner l'élément à supprimer."));
        return;
    }

    removeZone = zoneModel->nodeFromIndex(selectionItem);

    if(removeZone->getType() == Zone::selection){
        if(carteScene != NULL)
            if(carteScene->getEtatCreation() == true){
                QMessageBox::warning(this, tr("Erreur"), tr("Terminer la sélection en coure."));
                return;
            }
    }

    parentZone = removeZone->getParent();

    parentZone->removeChild(removeZone);
    zoneModel->setRootNode(pro->getZones());

    if(carteScene != NULL)
        carteScene->drawZones();
}

//gestion de la selection de zone en fonction de couleur
void MainWindow::ceratSelection()
{
    if(creatWindow_Carte() == true){
        if(carteScene->getEtatCreation() == false){
            Selection *select = zoneModel->addSelection(zoneView->selectionModel()->currentIndex());

            Carte_select *selction_tool = new Carte_select(pro);
            carteScene->setZone_courante((Zone *)select);
            carteScene->setTool(selction_tool);

            pb_selzone->setText(QObject::tr("Arrêter"));
            carteScene->activerCreation(select->getType());
        }
        else
        {
            carteScene->delTool();
            carteScene->nullZone_courante();
            carteScene->desactiverCreation();
            pb_selzone->setText(QObject::tr("Sélection"));
        }
    }
}

//invetion de la selection des volontaires, le nom n'est pas terible
void MainWindow::Selpoints_clicked()
{
    if(listeVolontaireModel->rowCount() != 0){
        listeVolontaireModel->switchEtat();
        view->setModel(listeVolontaireModel);
    }else{
        QMessageBox::warning(this, tr("Erreur"), tr("Sélectionner des points avant de faire cette action."));
    }
}

//ouverture de la map
void MainWindow::on_actionCharger_une_carte_triggered()
{
    QString File = QFileDialog::getOpenFileName(this,tr("Choisir une carte"), QDir::homePath(), tr("carte (*)"));

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
        listeVolontaireModel->setItems(pro->getVolontaires());
        view->setModel(listeVolontaireModel);
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
    if(listeVolontaireModel->rowCount() != 0){
        listeVolontaireModel->removeCheckedRow();
    }else{
        QMessageBox::warning(this, tr("Erreur"), tr("Sélectionner des points avant de faire cette action."));
    }
}

//renvoir le projet en cour.
Projet *MainWindow::getCurent_projet(){
    return pro;
}
//////////////////////////édition des données
void MainWindow::openWindow_Data(QStringList liste_data)
{
    /***************************************************************************/
    /************************************Data***********************************/
    /***************************************************************************/

    QString data;
    textEdit = new QTextEdit;
    foreach(data, liste_data)
        textEdit->append(data);

    QWidget *dataWidget = new QWidget;

    QVBoxLayout *Layout_Data = new QVBoxLayout;

    QMenuBar *menu = new QMenuBar();
    Layout_Data->addWidget(menu);
    QAction * saveAct = new QAction(QIcon(":/images/save.png"), tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(saveDonnees()));
    menu->addAction(saveAct);

    Layout_Data->addWidget(textEdit);

    dataWidget->setLayout(Layout_Data);
    QMdiSubWindow *window_Data = new QMdiSubWindow;
    zoneCentrale->addSubWindow(window_Data);
    window_Data->setWindowTitle(QObject::tr("Carte"));
    window_Data->setAttribute(Qt::WA_DeleteOnClose);
    window_Data->setWidget(dataWidget);

    window_Data->showMaximized();
}

void MainWindow::on_actionAnalyse_des_zones_et_des_volontaires_triggered()
{
    if((pro->getVolontaires()->size() != 0)&&(pro->getZones()->size() != 0)){
        Analyse analyse(pro);
        analyse.start();
        QStringList data = analyse.getData();
        openWindow_Data(data);
    }
}

bool MainWindow::saveDonnees(){
    save(textEdit->toPlainText());
    return true;
}

bool MainWindow::save(QString data)
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), QDir::homePath());
    if (fileName.isEmpty())
        return false;

    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("MDI"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << data;
    QApplication::restoreOverrideCursor();

    return true;
}

QStringList MainWindow::open()
{
    QStringList data;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*)"));
    if (fileName.isEmpty())
        return QStringList();

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("MDI"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return QStringList();
    }

    QTextStream stream(&file);

    while( !stream.atEnd() ) {
        data << stream.readLine();
    }

    file.close();

    return data;
}

void MainWindow::on_actionExporter_les_zones_triggered()
{
    save(pro->getZones()->serialisation());
}

void MainWindow::on_actionImporter_des_zones_triggered()
{
    Groupe_selection *groupe = new Groupe_selection(pro->getZones());
    groupe->Groupe_selection::deserialisation(open().at(0), pro);
    Zone *zone;

    zoneModel->beginReset();
    foreach(zone, groupe->getZones())
        pro->getZones()->appendChild(zone);
    zoneModel->endReset();
}

void MainWindow::on_actionA_propos_de_triggered()
{
    QLabel  *about  = new QLabel;
    QPixmap *img = new QPixmap("ressources/images/about/about.png");
    about->setPixmap(*img);
    about->show();
}
