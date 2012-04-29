#ifndef MYTREEZONEMODEL_H
#define MYTREEZONEMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>

class Groupe_selection;
class MyTreeZoneModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit MyTreeZoneModel(QObject *parent = 0);
    ~MyTreeZoneModel();

    void setRootNode(Groupe_selection *node);
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    Groupe_selection *nodeFromIndex(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    QVariant data(const QModelIndex &index, int role) const;

signals:

public slots:

private:
    Groupe_selection *rootNode;

};

#endif // MYTREEZONEMODEL_H
