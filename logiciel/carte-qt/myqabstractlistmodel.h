#ifndef MYQABSTRACTLISTMODEL_H
#define MYQABSTRACTLISTMODEL_H

#include <QAbstractListModel>
#include <QVector>

//#include "Volontaire.h"
class Volontaire;

//#include "mainwindow.h"
class MainWindow;

class MyQAbstractListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit MyQAbstractListModel(QObject *parent = 0);
    ~MyQAbstractListModel();

    QVariant data(const QModelIndex& index, int role) const;
    bool setData (const QModelIndex &index, const QVariant &value, int role);
    int rowCount(const QModelIndex  &parent=QModelIndex() ) const;
    void setItems(const QVector<Volontaire*>* Volontaires);
    Qt::ItemFlags flags (const QModelIndex  &index ) const;
    void switchEtat();

protected:
    const QVector<Volontaire*> *volontaires;

private:
    MainWindow *mainwindow;
};

#endif // MYQABSTRACTLISTMODEL_H
