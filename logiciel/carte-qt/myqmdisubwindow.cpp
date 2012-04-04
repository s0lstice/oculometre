#include "myqmdisubwindow.h"

MyQMdiSubWindow::MyQMdiSubWindow() : QMdiSubWindow()
{
}

void MyQMdiSubWindow::closeEvent(QCloseEvent *event)
{
  emit closeWindow();
  event->accept();
}
