#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_SelectCarte_clicked();

    void on_SelectSujet_clicked();

    void on_pb_selzone_clicked();

    void on_afficher_points_clicked();

private:
    Ui::MainWindow *ui;
    bool selection_zone;
};

#endif // MAINWINDOW_H
