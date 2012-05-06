#include "myqabstractlistmodel.h"
#include "projet.h"
#include "mainwindow.h"
#include "volontaire.h"
#include "myqgraphicsscene.h"

MyQAbstractListModel::MyQAbstractListModel(QObject *parent) :
    QAbstractListModel(parent)
{
    mainwindow = qobject_cast<MainWindow*>(parent);
    //Projet *pro = mainwindow->getCurent_projet();
    //Volontaires = pro->getVolontaires();
}
MyQAbstractListModel::~MyQAbstractListModel()
{
}

bool MyQAbstractListModel::removeRow(int row)
{

    if(row < 0 || row >= volontaires->size())
        return false;

    beginRemoveRows(QModelIndex(), row, row);

    mainwindow->getCurent_projet()->supprimer_Volontaire(row);

    endRemoveRows();

    return true;
}

bool MyQAbstractListModel::removeCheckedRow()
{
    int row;
    int nb_volontaire = volontaires->size()-1;

    for(row = nb_volontaire; row >= 0; row--){
        if(volontaires->at(row)->getDisplayed() == Qt::Checked){
            beginRemoveRows(QModelIndex(), row, row);

            mainwindow->getCurent_projet()->supprimer_Volontaire(row);

            endRemoveRows();
        }
    }

    return true;
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

void MyQAbstractListModel::afficheVolontaire(){
    Volontaire *volon;
    QVector<Volontaire*> liste;

    mainwindow->creatWindow_Carte(); //on s'assure que le fenetre est bien ouverte
    foreach(volon, *volontaires){
        if(volon->getDisplayed() == Qt::Checked){
            liste.append(volon);
        }
    }

    if(liste.size() != 0)
        mainwindow->getCarteScene()->DrawVolontaires();
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
    if(this->volontaires == NULL)
        return 0;
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
