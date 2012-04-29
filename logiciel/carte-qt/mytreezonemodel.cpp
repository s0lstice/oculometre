#include "mytreezonemodel.h"
#include "groupe_selection.h"
#include "zone.h"
#include <Qt>

MyTreeZoneModel::MyTreeZoneModel(QObject *parent) :
    QAbstractItemModel(parent)
{
    rootNode = NULL;
}

MyTreeZoneModel::~MyTreeZoneModel(){
    if(rootNode != NULL)
        delete rootNode;
    rootNode = NULL;
}

void MyTreeZoneModel::setRootNode(Groupe_selection *node){
    //if(rootNode != NULL)
    //    delete this->rootNode;
    rootNode = node;
    reset(); //refertch
}

QModelIndex MyTreeZoneModel::index(int row, int column, const QModelIndex &parent) const{
    if(!rootNode || row < 0 || column < 0)
        return QModelIndex();
    Groupe_selection *parentNode = nodeFromIndex(parent);
    Zone *childNode = parentNode->getGroupe().value(row);

    if(!childNode)
        return QModelIndex();
    return createIndex(row, column, childNode);
}

Groupe_selection *MyTreeZoneModel::nodeFromIndex(const QModelIndex &index) const {
    if(index.isValid())
        return static_cast<Groupe_selection *>(index.internalPointer());
    else
        return rootNode;
}

int MyTreeZoneModel::rowCount(const QModelIndex &parent) const{
    if(parent.column() > 0)
        return 0;
    Groupe_selection *parentNode =nodeFromIndex(parent);
    if(parentNode->getType() != composite)
        return 0;
    if(!parentNode)
        return 0;
    return parentNode->getGroupe().count();
}

int MyTreeZoneModel::columnCount(const QModelIndex &parent) const{
    return 2;
}

QModelIndex MyTreeZoneModel::parent(const QModelIndex &child) const{
    Groupe_selection *node = nodeFromIndex(child);
    if(!node)
        return QModelIndex();
    Groupe_selection *parentNode = node->getParent();
    if(!parentNode)
        return QModelIndex();
    Groupe_selection *grandparentNode = parentNode->getParent();
    if(!grandparentNode)
        return QModelIndex();

    int row = grandparentNode->getGroupe().indexOf(parentNode);
    return createIndex(row, 0, parentNode);
}

QVariant MyTreeZoneModel::data(const QModelIndex &index, int role) const{
    if(role != Qt::DisplayRole)
        return QVariant();

    Zone *node = nodeFromIndex(index);
    if(!node)
        return QVariant();
    if(index.column() == 0){
        switch(node->getType()){
            case selection:
                return tr("selection");
            case cercle:
                return tr("cercle");
            case polygone:
                return tr("polygone");
            case composite:
                return tr("composite");
        }
     }
     else{
        return node->getLable();
     }
     return QVariant();
}
