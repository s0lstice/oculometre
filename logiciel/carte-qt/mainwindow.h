#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include "sujet.h"
#include <QVBoxLayout>
#include <cv.h>
#include <highgui.h>

namespace Ui {
    class MainWindow;
}

typedef struct _sujetCheck{
    QCheckBox *checkbox;
    sujet *p_sujet;
}sujetCheck;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void shoowIplImage(IplImage * iplImg);
    ~MainWindow();

private slots:
    void on_SelectCarte_clicked();

    void on_SelectSujet_clicked();

    void on_pb_selzone_clicked();

    void on_afficher_points_clicked();

    void on_Selpoints_clicked();

private:
    Ui::MainWindow *ui;
    bool selection_zone;
    QVector<sujetCheck> v_check_sujet;
    void liste_pointFromListe_sujet();
    QVector<sujet*> build_sujetCheck_list();
    QWidget *checkBoxWidget;
    QVBoxLayout *scrolledLayout;
    bool checked;
};

#endif // MAINWINDOW_H
