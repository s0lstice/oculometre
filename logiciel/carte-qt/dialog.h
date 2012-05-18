/**
 * \file dialog.h
 * \brief Affiche une fenetre avec un message. (Ne pas utiliser)
 * \author Mickael Puret
 *
 */
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
    class Dialog;
}

/*!
  @class Dialog : public QDialog
  @brief Affiche un message. (Ne pas utiliser)
  */
class Dialog : public QDialog
{
    Q_OBJECT

public:
    /*!
      @fn Dialog::Dialog(QString msg,QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
      @param QString msg : message à afficher.
      @param QWidget *parent : classe applemente.
      @brief constructeur de la fenetre
      */
    Dialog(QString msg,QWidget *parent = 0);

    /*!
      @fn Dialog::Dialog(QString msg,QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
      @brief constructeur de la fenetre
      */
    ~Dialog();

private slots:
    /*!
      @fn void Dialog::on_ok_clicked()
      @brief Evenement du clique.
      */
    void on_ok_clicked();

private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
