#ifndef MYTREEZONEMODEL_H
#define MYTREEZONEMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>

class Groupe_selection;
class MainWindow;
class Selection;
class Rectangle;
class Cercle;
class MyTreeZoneModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit MyTreeZoneModel(QObject *parent = 0);
    ~MyTreeZoneModel();

    void setRootNode(Groupe_selection *node);
    Groupe_selection *addGroup(QModelIndex item);
    Selection *addSelection(QModelIndex item);
    Rectangle * addRect(QModelIndex item);
    Cercle * addCercle(QModelIndex item);
    Groupe_selection *nodeFromIndex(const QModelIndex &index) const;

    void beginReset();
    void endReset();

signals:

public slots:
    void switchEtat(Groupe_selection *zones = NULL);
private:
    Groupe_selection *rootNode;
    MainWindow *mainwindow;

    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags (const QModelIndex  &index ) const;
    bool setData (const QModelIndex &index, const QVariant &value, int role);

};

#endif // MYTREEZONEMODEL_H
