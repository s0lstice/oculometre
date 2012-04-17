#include "myqabstractlistmodel.h"
#include "projet.h"
#include "mainwindow.h"
#include "volontaire.h"

MyQAbstractListModel::MyQAbstractListModel(QObject *parent) :
    QAbstractListModel(parent)
{
    //mainwindow = qobject_cast<MainWindow*>(parent);
    //Projet *pro = mainwindow->getCurent_projet();
    //Volontaires = pro->getVolontaires();
}
MyQAbstractListModel::~MyQAbstractListModel()
{
}

void MyQAbstractListModel::setItems(const QVector<Volontaire*> *Volontaires)
{
    emit beginResetModel();
    this->volontaires = Volontaires;
    emit endResetModel();
}

void MyQAbstractListModel::switchEtat(){
    Volontaire *volon;

    emit beginResetModel();
    foreach(volon, *volontaires){
        volon->switchEtat();
    }
    emit endResetModel();
}

Qt::ItemFlags MyQAbstractListModel::flags (const QModelIndex  &index ) const
{
  if (index.row() < 0 || index.row() >= rowCount() || !index.isValid())
    {
    return Qt::NoItemFlags;
    }
  return Qt::ItemIsUserCheckable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

int MyQAbstractListModel::rowCount(const QModelIndex& parent) const
{
  return this->volontaires->size();
}

QVariant MyQAbstractListModel::data (const QModelIndex  &index , int role ) const
{
  if (index.row() < 0 || index.row() >= rowCount() || !index.isValid())
    {
    return QVariant();
    }

  if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        return this->volontaires->at(index.row())->getId_Volontaire();
    }

  if(role == Qt::CheckStateRole)
    {
        return this->volontaires->at(index.row())->getDisplayed();
    }

  return QVariant();
}

bool MyQAbstractListModel::setData (const QModelIndex &index, const QVariant &value, int role)
{
  if (index.row() < 0 || index.row() >= rowCount() || !index.isValid())
    {
    return false;
    }

  if(role == Qt::CheckStateRole)
    {
        this->volontaires->at(index.row())->setDisplayed(static_cast<Qt::CheckState>(value.toUInt()));
    }

  emit dataChanged(index, index);
  return true;
}
