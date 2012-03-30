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
    void on_pushButton_clicked();

    void on_SelectCarte_clicked();

    void on_SelectSujet_clicked();

private:
    Ui::MainWindow *ui;
    QString path_carte;
};

#endif // MAINWINDOW_H
