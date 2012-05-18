/**
 * \file dialog.cpp
 * \brief Affiche une fenetre avec un message. (Ne pas utiliser)
 * \author Mickael Puret
 *
 */
#include "dialog.h"
#include "ui_dialog.h"

/*!
  @fn Dialog::Dialog(QString msg,QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
  @param QString msg : message à afficher.
  @param QWidget *parent : classe applemente.
  @brief constructeur de la fenetre
  */
Dialog::Dialog(QString msg,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->msg->setReadOnly(true);
    ui->msg->setText(msg);
}

/*!
  @fn Dialog::Dialog(QString msg,QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
  @brief constructeur de la fenetre
  */
Dialog::~Dialog()
{
    delete ui;
}

/*!
  @fn void Dialog::on_ok_clicked()
  @brief Evenement du clique.
  */
void Dialog::on_ok_clicked()
{
    this->close();
}
