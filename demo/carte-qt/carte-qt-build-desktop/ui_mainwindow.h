/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Mar 31 16:46:16 2012
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
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *pb_selzone;
    QPushButton *pushButton_4;
    QGroupBox *groupBox_2;
    QPushButton *SelectCarte;
    QPushButton *SelectSujet;
    QGroupBox *groupBox_3;
    QPushButton *afficher_points;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(385, 300);
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
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(200, 0, 181, 231));
        pb_selzone = new QPushButton(groupBox);
        pb_selzone->setObjectName(QString::fromUtf8("pb_selzone"));
        pb_selzone->setGeometry(QRect(10, 30, 161, 27));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 60, 161, 27));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 0, 181, 101));
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        SelectCarte = new QPushButton(groupBox_2);
        SelectCarte->setObjectName(QString::fromUtf8("SelectCarte"));
        SelectCarte->setGeometry(QRect(10, 30, 161, 27));
        SelectSujet = new QPushButton(groupBox_2);
        SelectSujet->setObjectName(QString::fromUtf8("SelectSujet"));
        SelectSujet->setGeometry(QRect(10, 60, 161, 27));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 110, 181, 121));
        afficher_points = new QPushButton(groupBox_3);
        afficher_points->setObjectName(QString::fromUtf8("afficher_points"));
        afficher_points->setGeometry(QRect(10, 30, 161, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 385, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Analise de la carte", 0, QApplication::UnicodeUTF8));
        pb_selzone->setText(QApplication::translate("MainWindow", "S\303\251lectionner une zone", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "ajouter un motif", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Gestion des donn\303\251es", 0, QApplication::UnicodeUTF8));
        SelectCarte->setText(QApplication::translate("MainWindow", "Charger une carte", 0, QApplication::UnicodeUTF8));
        SelectSujet->setText(QApplication::translate("MainWindow", "charger des sujets", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "gestion des points", 0, QApplication::UnicodeUTF8));
        afficher_points->setText(QApplication::translate("MainWindow", "Afficher les points", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
