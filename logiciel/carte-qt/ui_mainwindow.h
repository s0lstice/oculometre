/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun May 20 21:45:29 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCharger_une_carte;
    QAction *actionCharger_des_Volontaires;
    QAction *actionAnaliser_la_carte;
    QAction *actionGestion_des_Volontaires;
    QAction *actionQuiter;
    QAction *actionA;
    QAction *actionAnalyse_des_zones_et_des_volontaires;
    QAction *actionSauvgarder_la_relation;
    QAction *actionExporter_les_zones;
    QAction *actionImporter_des_zones;
    QAction *actionAide;
    QAction *actionA_propos_de;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuDonnees;
    QMenu *menuInformations;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(570, 337);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow::separator{\n"
"	width: 1px;\n"
"	height: 1px;\n"
" 	background-color:black;	\n"
"}\n"
"QMenuBar{\n"
"     border-bottom: 1px solid black;\n"
" }\n"
"\n"
" QDockWidget {\n"
"	border: 1px solid black; \n"
"	/*color: white;*/\n"
" }\n"
"\n"
"QDockWidget::title {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 LightGray, stop: 1 Gray);\n"
"	subcontrol-position: top left; /* position at the top left*/\n"
"	padding:2 13px;\n"
"}\n"
"\n"
"QDockWidget::close-button:hover, QDockWidget::float-button:hover {\n"
"	background-color: qlineargradient(x1: 1, y1: 0, x2: 1, y2: 0, stop: 0 LightGray, stop: 1 Gray);\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"QGroupBox::title\n"
"{\n"
"    subcontrol-position: top left;\n"
"    padding: -15 10 0 10px;\n"
"    font-size: 8px;\n"
"	color: black;\n"
"}\n"
"\n"
"QGroupBox{\n"
"	margin: 5 0 0 0px;\n"
"	padding: 0 0 0 0px;\n"
"    border: 1px solid black;\n"
"}"));
        actionCharger_une_carte = new QAction(MainWindow);
        actionCharger_une_carte->setObjectName(QString::fromUtf8("actionCharger_une_carte"));
        actionCharger_des_Volontaires = new QAction(MainWindow);
        actionCharger_des_Volontaires->setObjectName(QString::fromUtf8("actionCharger_des_Volontaires"));
        actionAnaliser_la_carte = new QAction(MainWindow);
        actionAnaliser_la_carte->setObjectName(QString::fromUtf8("actionAnaliser_la_carte"));
        actionGestion_des_Volontaires = new QAction(MainWindow);
        actionGestion_des_Volontaires->setObjectName(QString::fromUtf8("actionGestion_des_Volontaires"));
        actionQuiter = new QAction(MainWindow);
        actionQuiter->setObjectName(QString::fromUtf8("actionQuiter"));
        actionA = new QAction(MainWindow);
        actionA->setObjectName(QString::fromUtf8("actionA"));
        actionAnalyse_des_zones_et_des_volontaires = new QAction(MainWindow);
        actionAnalyse_des_zones_et_des_volontaires->setObjectName(QString::fromUtf8("actionAnalyse_des_zones_et_des_volontaires"));
        actionSauvgarder_la_relation = new QAction(MainWindow);
        actionSauvgarder_la_relation->setObjectName(QString::fromUtf8("actionSauvgarder_la_relation"));
        actionExporter_les_zones = new QAction(MainWindow);
        actionExporter_les_zones->setObjectName(QString::fromUtf8("actionExporter_les_zones"));
        actionImporter_des_zones = new QAction(MainWindow);
        actionImporter_des_zones->setObjectName(QString::fromUtf8("actionImporter_des_zones"));
        actionAide = new QAction(MainWindow);
        actionAide->setObjectName(QString::fromUtf8("actionAide"));
        actionA_propos_de = new QAction(MainWindow);
        actionA_propos_de->setObjectName(QString::fromUtf8("actionA_propos_de"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 570, 25));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuDonnees = new QMenu(menuBar);
        menuDonnees->setObjectName(QString::fromUtf8("menuDonnees"));
        menuInformations = new QMenu(menuBar);
        menuInformations->setObjectName(QString::fromUtf8("menuInformations"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuDonnees->menuAction());
        menuBar->addAction(menuInformations->menuAction());
        menuFichier->addSeparator();
        menuFichier->addSeparator();
        menuFichier->addAction(actionImporter_des_zones);
        menuFichier->addAction(actionExporter_les_zones);
        menuFichier->addAction(actionQuiter);
        menuFichier->addSeparator();
        menuDonnees->addAction(actionCharger_une_carte);
        menuDonnees->addAction(actionCharger_des_Volontaires);
        menuDonnees->addSeparator();
        menuDonnees->addSeparator();
        menuDonnees->addAction(actionAnalyse_des_zones_et_des_volontaires);
        menuInformations->addAction(actionAide);
        menuInformations->addAction(actionA_propos_de);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionCharger_une_carte->setText(QApplication::translate("MainWindow", "Charger une carte", 0, QApplication::UnicodeUTF8));
        actionCharger_une_carte->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        actionCharger_des_Volontaires->setText(QApplication::translate("MainWindow", "Charger des volontaires", 0, QApplication::UnicodeUTF8));
        actionCharger_des_Volontaires->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        actionAnaliser_la_carte->setText(QApplication::translate("MainWindow", "Analiser la carte", 0, QApplication::UnicodeUTF8));
        actionGestion_des_Volontaires->setText(QApplication::translate("MainWindow", "Gestion des Volontaires", 0, QApplication::UnicodeUTF8));
        actionQuiter->setText(QApplication::translate("MainWindow", "Quiter", 0, QApplication::UnicodeUTF8));
        actionQuiter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionA->setText(QApplication::translate("MainWindow", "a", 0, QApplication::UnicodeUTF8));
        actionAnalyse_des_zones_et_des_volontaires->setText(QApplication::translate("MainWindow", "Relation des zones et des volontaires", 0, QApplication::UnicodeUTF8));
        actionAnalyse_des_zones_et_des_volontaires->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        actionSauvgarder_la_relation->setText(QApplication::translate("MainWindow", "Sauvgarder la relation", 0, QApplication::UnicodeUTF8));
        actionSauvgarder_la_relation->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionExporter_les_zones->setText(QApplication::translate("MainWindow", "Exporter les zones", 0, QApplication::UnicodeUTF8));
        actionExporter_les_zones->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0, QApplication::UnicodeUTF8));
        actionImporter_des_zones->setText(QApplication::translate("MainWindow", "Importer des zones", 0, QApplication::UnicodeUTF8));
        actionImporter_des_zones->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", 0, QApplication::UnicodeUTF8));
        actionAide->setText(QApplication::translate("MainWindow", "Aide", 0, QApplication::UnicodeUTF8));
        actionA_propos_de->setText(QApplication::translate("MainWindow", "A propos de", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "&Fichier", 0, QApplication::UnicodeUTF8));
        menuDonnees->setTitle(QApplication::translate("MainWindow", "&Donn\303\251es", 0, QApplication::UnicodeUTF8));
        menuInformations->setTitle(QApplication::translate("MainWindow", "informations", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
