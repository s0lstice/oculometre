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
      @brief Constructeur.
      */
    explicit MainWindow(QWidget *parent = 0);

    /*!
      @fn ~MainWindow();
      @brief Destructeur.
      */
    ~MainWindow();

    /*!
      @fn MyQGraphicsScene *getCarteScene();
      @return MyQGraphicsScene * : Instance de la zone de dessin sur le carte.
      @brief Permet la manipulation de la zone de dessin depuis l'extérieur.
      @note Ne respecte pas le principe d'encapsulation, mérite l'utilisation d'un Abstract factory design pattern.
      */
    MyQGraphicsScene *getCarteScene();

    /*!
      @fn bool creatWindow_Carte();
      @return bool : True : La fenêtre de la carte est ouverte, sinon elle s'ouvre. False, la fenêtre ne peut être ouverte.
      @brief Ouvre la fenêtre avec la carte.
      */
    bool creatWindow_Carte();

    /*!
      @fn Projet *getCurent_projet();
      @return Projet * : Projet courant.
      @brief Renvoie le projet courant
      */
    Projet *getCurent_projet();

private slots:
    /*!
      @fn void ceratSelection();
      @brief Evènement, déclanche la sélection ou l'arrêt de la sélection d'une couleur.
      */
    void ceratSelection();

    /*!
      @fn void ceratSelection();
      @brief Evènement, intervertit la sélection des Volontaires.
      @note Renomme cette méthode.
      */
    void Selpoints_clicked();

    /*!
      @fn void on_actionCharger_une_carte_triggered();
      @brief Evènement, invite l'utilisateur à charger une carte en mémoire et l'afficher.
      */
    void on_actionCharger_une_carte_triggered();

    /*!
      @fn on_actionCharger_des_Volontaires_triggered();
      @brief Evènement, invite l'utilisateur à charger une liste de Volontaires.
      */
    void on_actionCharger_des_Volontaires_triggered();

    /*!
      @fn void on_actionQuiter_triggered();
      @brief Evènement, met fin à l'application.
      */
    void on_actionQuiter_triggered();

    /*!
      @fn void supprimer_Volontaires();
      @brief Evènement, supprime les Volontaies sélectionnés.
      */
    void supprimer_Volontaires();

    /*!
      @fn void creatGroup();
      @brief Evènement, crée un groupe (objet de type Groupe_selection) et l'ajoute au groupe racine ou sélectionné.
      */
    void creatGroup();

    /*!
      @fn void creatRect();
      @brief Evènement, crée un rectangle (objet de type Rectangle) et l'ajoute au groupe racine ou sélectionné.
      */
    void creatRect();

    /*!
      @fn void creatCercle();
      @brief Evènement, crée un cercle (objet de type Cercle) et l'ajoute au groupe racine ou sélectionné.
      */
    void creatCercle();

    /*!
      @fn void removeZone();
      @brief Evènement, supprime une zone (peu importe son type) et la retire du groupe racine ou sélectionné.
      */
    void removeZone();

    /*!
      @fn void drawVolontaires();
      @brief Evènement, affiche tous les volontaires sélectionnés.
      */
    void drawVolontaires();

    /*!
      @fn void drawZones();
      @brief Evènement, affiche toutes les zones sélectionnées.
      */
    void drawZones();

    /*!
      @fn void switchZoneEtat();
      @brief Evènement, inverse la sélection des zones.
      */
    void switchZoneEtat();

    /*!
      @fn void switchZoneEtat();
      @brief Evènement, inverse la sélection des zones.
      */
    void on_actionAnalyse_des_zones_et_des_volontaires_triggered();

    /*!
      @fn void saveDonnees();
      @brief Evènement, sauvegarde les données de la fenêtre de texte.
      */
    bool saveDonnees();

    /*!
      @fn void on_actionExporter_les_zones_triggered();
      @brief Evènement, exporte les zones dans un format texte.
      */
    void on_actionExporter_les_zones_triggered();

    /*!
      @fn void on_actionImporter_des_zones_triggered();
      @brief Evènement, importe les zones dans un format texte.
      */
    void on_actionImporter_des_zones_triggered();

    /*!
      @fn void on_actionA_propos_de_triggered();
      @brief Evènement, affiche les informations du logiciel.
      */
    void on_actionA_propos_de_triggered();

private:
    Projet *pro;
    Ui::MainWindow *ui;
    //QWidget *checkBoxWidget;
    //QVBoxLayout *scrolledLayout;

    /*!
      @fn void openWindow_Carte();
      @brief Initialise et ouvre la fenêtre "carte" avec la carte affichée.
      */
    void openWindow_Carte();

    /*!
      @fn void openWindow_Carte();
      @brief Désalocation des objets de la fenêtre "carte" lors de la fermeture.
      */
    void closeWindow_Carte();

    QMenu *viewMenu;

    //doc gestion des zones
    /*!
      @fn void dockCarte();
      @brief Initialise et ouvre la barre d'outils "carte"
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
      @brief Initialise et ouvre la barre d'outils "volontaire"
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
      @param QStringList liste_data : Liste de QString, une ligne par élément de la liste.
      @brief Initialise et ouvre la fenêtre "résultat" avec le texte passé en paramètre.
      */
    void openWindow_Data(QStringList liste_data);
    QTextEdit *textEdit;

    /*!
      @fn bool save(QString data);
      @param QString data : Chaine à sauvegarder.
      @brief Sauvegarde la chaine passée en paramètre.
      */
    bool save(QString data);

    /*!
      @fn QStringList open();
      @return QStringList : Liste de QString, une ligne par élément de la liste.
      @brief Initialise et ouvre la fenêtre "résultat" avec le texte passé en paramètre.
      */
    QStringList open();
};

#endif // MAINWINDOW_H
