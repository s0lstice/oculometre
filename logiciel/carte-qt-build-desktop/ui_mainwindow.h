/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Apr 5 20:14:48 2012
**      by: Qt User Interface Compiler version 4.7.4
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
    QAction *actionCharger_des_volontaires;
    QAction *actionAnaliser_la_carte;
    QAction *actionGestion_des_volontaires;
    QAction *actionQuiter;
    QAction *actionA;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuDonnees;
    QMenu *menuOutils;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(257, 85);
        MainWindow->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	background-color: transparent;\n"
"	border: 2px groove gray; \n"
"	border-radius: 5px;				\n"
"}\n"
"QGroupBox::title { \n"
"    background-color: transparent;\n"
"     subcontrol-position: top left; /* position at the top left*/ \n"
"     padding:2 13px;\n"
" } "));
        actionCharger_une_carte = new QAction(MainWindow);
        actionCharger_une_carte->setObjectName(QString::fromUtf8("actionCharger_une_carte"));
        actionCharger_des_volontaires = new QAction(MainWindow);
        actionCharger_des_volontaires->setObjectName(QString::fromUtf8("actionCharger_des_volontaires"));
        actionAnaliser_la_carte = new QAction(MainWindow);
        actionAnaliser_la_carte->setObjectName(QString::fromUtf8("actionAnaliser_la_carte"));
        actionGestion_des_volontaires = new QAction(MainWindow);
        actionGestion_des_volontaires->setObjectName(QString::fromUtf8("actionGestion_des_volontaires"));
        actionQuiter = new QAction(MainWindow);
        actionQuiter->setObjectName(QString::fromUtf8("actionQuiter"));
        actionA = new QAction(MainWindow);
        actionA->setObjectName(QString::fromUtf8("actionA"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 257, 25));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuDonnees = new QMenu(menuBar);
        menuDonnees->setObjectName(QString::fromUtf8("menuDonnees"));
        menuOutils = new QMenu(menuBar);
        menuOutils->setObjectName(QString::fromUtf8("menuOutils"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuDonnees->menuAction());
        menuBar->addAction(menuOutils->menuAction());
        menuFichier->addAction(actionQuiter);
        menuDonnees->addAction(actionCharger_une_carte);
        menuDonnees->addAction(actionCharger_des_volontaires);
        menuOutils->addAction(actionGestion_des_volontaires);
        menuOutils->addAction(actionAnaliser_la_carte);
        menuOutils->addSeparator();
        menuOutils->addAction(actionA);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionCharger_une_carte->setText(QApplication::translate("MainWindow", "Charger une carte", 0, QApplication::UnicodeUTF8));
        actionCharger_une_carte->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        actionCharger_des_volontaires->setText(QApplication::translate("MainWindow", "Charger des volontaires", 0, QApplication::UnicodeUTF8));
        actionCharger_des_volontaires->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        actionAnaliser_la_carte->setText(QApplication::translate("MainWindow", "Analiser la carte", 0, QApplication::UnicodeUTF8));
        actionGestion_des_volontaires->setText(QApplication::translate("MainWindow", "Gestion des volontaires", 0, QApplication::UnicodeUTF8));
        actionQuiter->setText(QApplication::translate("MainWindow", "Quiter", 0, QApplication::UnicodeUTF8));
        actionQuiter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionA->setText(QApplication::translate("MainWindow", "a", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menuDonnees->setTitle(QApplication::translate("MainWindow", "Donn\303\251es", 0, QApplication::UnicodeUTF8));
        menuOutils->setTitle(QApplication::translate("MainWindow", "Outils", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
