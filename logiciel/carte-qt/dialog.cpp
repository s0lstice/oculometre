#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QString msg,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->msg->setReadOnly(true);
    ui->msg->setText(msg);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_ok_clicked()
{
    this->close();
}
