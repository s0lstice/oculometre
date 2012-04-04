#ifndef MYQMDISUBWINDOW_H
#define MYQMDISUBWINDOW_H

#include <QMdiSubWindow>

class MyQMdiSubWindow : public QMdiSubWindow
{
public:
    MyQMdiSubWindow();
    void closeEvent(QCloseEvent *event);

signals:
   void closeWindow();
};

#endif // MYQMDISUBWINDOW_H
