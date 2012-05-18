/**
 * \file mainwindow.h
 * \brief Classe principale pour la gestion graphique.
 * \note Classe a découper en sous classe. Aprofondir l'encapsulation.
 * \author Mickael Puret
 *
 */
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
#include <QTextEdit>

//#include "projet.h"
class Projet;
//#include "Volontaire.h"
class Volontaire;
//#include "myqgraphicsscene.h"
class MyQGraphicsScene;
class MyQAbstractListModel;
class MyTreeZoneModel;

/*!
  @namespace Ui
  @class MainWindow
  */
namespace Ui {
    class MainWindow;
}

/*!
  @class MainWindow
  @brief Classe principale de la geston graphique.
  */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /*!
      @fn explicit MainWindow(QWidget *parent = 0);
      @brief Construcateur.
      */
    explicit MainWindow(QWidget *parent = 0);

    /*!
      @fn ~MainWindow();
      @brief Destructeur.
      */
    ~MainWindow();

    /*!
      @fn MyQGraphicsScene *getCarteScene();
      @return MyQGraphicsScene * : Instance De la zone de dessin sur le carte.
      @brief Permet la manipulation de la zone de dessin de puis l'exterieur.
      @note Ne respecte pas le principe d'encapsulation, merite l'utilisation d'un Abstract factory design pattern.
      */
    MyQGraphicsScene *getCarteScene();

    /*!
      @fn bool creatWindow_Carte();
      @return bool : True : la fenetre de la carte est ouvrete, sinon elle souvre. False, la fenetre ne peut etre ouvrete.
      @brief Ouvre la fenetre avec la carte.
      */
    bool creatWindow_Carte();

    /*!
      @fn Projet *getCurent_projet();
      @return Projet * : Projet courant.
      @brief Renvoie le Projet courant
      */
    Projet *getCurent_projet();

private slots:
    /*!
      @fn void ceratSelection();
      @brief Evenement, declanche la sélection ou l'erret de la sélection d'une couleur.
      */
    void ceratSelection();

    /*!
      @fn void ceratSelection();
      @brief Evenement, intervertie la selection des Volontaires.
      @note renomer cette methode.
      */
    void Selpoints_clicked();

    /*!
      @fn void on_actionCharger_une_carte_triggered();
      @brief Evenement, invite l'utilisateur à charger une carte en memoire et l'affiche.
      */
    void on_actionCharger_une_carte_triggered();

    /*!
      @fn on_actionCharger_des_Volontaires_triggered();
      @brief Evenement, invite l'utilisateur à charger une liste de Volontaire.
      */
    void on_actionCharger_des_Volontaires_triggered();

    /*!
      @fn void on_actionQuiter_triggered();
      @brief Evenement, met fin à l'application.
      */
    void on_actionQuiter_triggered();

    /*!
      @fn void supprimer_Volontaires();
      @brief Evenement, supprime les Volontaies sélectionnés.
      */
    void supprimer_Volontaires();

    /*!
      @fn void creatGroup();
      @brief Evement, créer un groupe (objet de type Groupe_selection) et l'ajoute au groupe racine ou sélectionné.
      */
    void creatGroup();

    /*!
      @fn void creatRect();
      @brief Evement, créer un rectangle (objet de type Rectangle) et l'ajoute au groupe racine ou sélectionné.
      */
    void creatRect();

    /*!
      @fn void creatCercle();
      @brief Evement, créer un cercle (objet de type Cercle) et l'ajoute au groupe racine ou sélectionné.
      */
    void creatCercle();

    /*!
      @fn void removeZone();
      @brief Evement, supprime une zone (peu importe son type) et la retir du groupe racine ou sélectionné.
      */
    void removeZone();

    /*!
      @fn void drawVolontaires();
      @brief Evement, affiche touts les volontaires selectionnés.
      */
    void drawVolontaires();

    /*!
      @fn void drawZones();
      @brief Evement, affiche toutes les zones selectionnées.
      */
    void drawZones();

    /*!
      @fn void switchZoneEtat();
      @brief Evement, inverse la selction des zones.
      */
    void switchZoneEtat();

    /*!
      @fn void switchZoneEtat();
      @brief Evement, inverse la selction des zones.
      */
    void on_actionAnalyse_des_zones_et_des_volontaires_triggered();

    /*!
      @fn void saveDonnees();
      @brief Evement, sauvgarde les donnés de la fêntre de texte.
      */
    bool saveDonnees();

    /*!
      @fn void on_actionExporter_les_zones_triggered();
      @brief Evement, exporte les zones dans un fomat text.
      */
    void on_actionExporter_les_zones_triggered();

    /*!
      @fn void on_actionImporter_des_zones_triggered();
      @brief Evement, importe les zones dans un fomat text.
      */
    void on_actionImporter_des_zones_triggered();

    /*!
      @fn void on_actionA_propos_de_triggered();
      @brief Evement, affiche les information du logiciel.
      */
    void on_actionA_propos_de_triggered();

private:
    Projet *pro;
    Ui::MainWindow *ui;
    //QWidget *checkBoxWidget;
    //QVBoxLayout *scrolledLayout;

    /*!
      @fn void openWindow_Carte();
      @brief Initialise et ouvre la fenêtre "carte" avec la carte d'affiché.
      */
    void openWindow_Carte();

    /*!
      @fn void openWindow_Carte();
      @brief désalocation des objet de la fenêtre "carte" lors de la fermeture.
      */
    void closeWindow_Carte();

    QMenu *viewMenu;

    //doc gestion des zones
    /*!
      @fn void dockCarte();
      @brief Initialise et ouvre la barre d'outil "carte"
      */
    void dockCarte();
    QDockWidget *dock_AnaliseCarte;
    QWidget *widget_AnaliseCarte;
    QPushButton *pb_selzone;
        //tree zones
    QTreeView *zoneView;
    MyTreeZoneModel *zoneModel;

    //gestion des volontaires
    /*!
      @fn void dockVolontaire();
      @brief Initialise et ouvre la barre d'outil "volontaire"
      */
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
    /*!
      @fn void openWindow_Data(QStringList liste_data);
      @param QStringList liste_data : Liste de QString, une ligne par élément de la  liste.
      @brief Initialise et ouvre la fenêtre "resultat" avec le text passé en parametre.
      */
    void openWindow_Data(QStringList liste_data);
    QTextEdit *textEdit;

    /*!
      @fn bool save(QString data);
      @param QString data : chaine à sauvgarder.
      @brief Sauvgare la chine passé en parametre.
      */
    bool save(QString data);

    /*!
      @fn QStringList open();
      @return QStringList : Liste de QString, une ligne par élément de la liste.
      @brief Initialise et ouvre la fenêtre "resultat" avec le text passé en parametre.
      */
    QStringList open();
};

#endif // MAINWINDOW_H
