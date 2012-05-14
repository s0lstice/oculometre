#include "mytreezonemodel.h"
#include "groupe_selection.h"
#include "zone.h"
#include "mainwindow.h"
#include "projet.h"
#include "selection.h"
#include "rectangle.h"
#include "cercle.h"

#include <Qt>
#include <QDebug>

MyTreeZoneModel::MyTreeZoneModel(QObject *parent) :
    QAbstractItemModel(parent)
{
    mainwindow = qobject_cast<MainWindow*>(parent);
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
    if(parentNode->getType() != Zone::composite)
        return 0;
    if(!parentNode)
        return 0;
    return parentNode->getGroupe().count();
}

int MyTreeZoneModel::columnCount(const QModelIndex &parent) const{
    return 1;
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
    if(role == Qt::CheckStateRole)
      {
          return nodeFromIndex(index)->getDisplayed();
      }

    if(role != Qt::DisplayRole)
        return QVariant();

    Zone *node = nodeFromIndex(index);
    if(!node)
        return QVariant();

    return node->getLable();
}

Groupe_selection * MyTreeZoneModel::addGroup(QModelIndex item){

    Groupe_selection *main_composite;
    Projet *pro = mainwindow->getCurent_projet();

    if(item.isValid() == false)
        main_composite = pro->getZones();
    else
        main_composite = nodeFromIndex(item);

    if(main_composite->getType() != Zone::composite)
        main_composite = main_composite->getParent();

    Groupe_selection *group = new Groupe_selection(main_composite);
    emit beginResetModel();
    main_composite->appendChild(group);
    emit endResetModel();

    return group;
}

Selection * MyTreeZoneModel::addSelection(QModelIndex item){

    Groupe_selection *main_composite;
    Projet *pro = mainwindow->getCurent_projet();

    if(item.isValid() == false)
        main_composite = pro->getZones();
    else
        main_composite = nodeFromIndex(item);

    if(main_composite->getType() != Zone::composite)
        main_composite = main_composite->getParent();

    Selection *selection = new Selection(main_composite);

    emit beginResetModel();
    main_composite->appendChild(selection);
    emit endResetModel();

    return selection;
}

Rectangle * MyTreeZoneModel::addRect(QModelIndex item){

    Groupe_selection *main_composite;
    Projet *pro = mainwindow->getCurent_projet();

    if(item.isValid() == false)
        main_composite = pro->getZones();
    else
        main_composite = nodeFromIndex(item);

    if(main_composite->getType() != Zone::composite)
        main_composite = main_composite->getParent();

    Rectangle *polygone = new Rectangle(main_composite);

    emit beginResetModel();
    main_composite->appendChild(polygone);
    emit endResetModel();

    return polygone;
}

Cercle * MyTreeZoneModel::addCercle(QModelIndex item){
    Groupe_selection *main_composite;
    Projet *pro = mainwindow->getCurent_projet();

    if(item.isValid() == false)
        main_composite = pro->getZones();
    else
        main_composite = nodeFromIndex(item);

    if(main_composite->getType() != Zone::composite)
        main_composite = main_composite->getParent();

    Cercle *cercle = new Cercle(main_composite);

    emit beginResetModel();
    main_composite->appendChild(cercle);
    emit endResetModel();

    return cercle;
}

//gestion de la selectionabilité
Qt::ItemFlags MyTreeZoneModel::flags (const QModelIndex  &index ) const
{
    return Qt::ItemIsUserCheckable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

bool MyTreeZoneModel::setData (const QModelIndex &index, const QVariant &value, int role)
{
    Zone *zIndex = nodeFromIndex(index);

    if(role == Qt::EditRole){
        zIndex->setLabel(value.toString());
    }

    if(role == Qt::CheckStateRole)
    {
        zIndex->setDisplayed(static_cast<Qt::CheckState>(value.toUInt()));
        emit dataChanged(index, index);

        if(zIndex->getType() == Zone::composite){
            switchEtat((Groupe_selection *)zIndex);
            emit layoutChanged();
        }
    }
    return true;
}

void MyTreeZoneModel::switchEtat(Groupe_selection *zones){

    if(zones == NULL){
        Projet *pro = mainwindow->getCurent_projet();
        zones = pro->getZones();
    }
    Zone * child;
    QVector<Zone*> childs = zones->getZones();

    foreach(child, childs){
        if(child->getType() == Zone::composite){
            switchEtat((Groupe_selection *)child);
        }
        else{
            child->switchEtat();
            emit layoutChanged();
        }
    }
}

void MyTreeZoneModel::beginReset(){
    emit beginResetModel();
}

void MyTreeZoneModel::endReset(){
    emit endResetModel();
}
