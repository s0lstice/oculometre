/**
 * \file myqabstractlistmodel.h
 * \brief Model pour la gestion des volontaires.
 * \author Mickael Puret
 *
 */
#ifndef MYQABSTRACTLISTMODEL_H
#define MYQABSTRACTLISTMODEL_H

#include <QAbstractListModel>
#include <QVector>

//#include "Volontaire.h"
class Volontaire;

//#include "mainwindow.h"
class MainWindow;

/*!
  @class MyQAbstractListModel : public QAbstractListModel
  @brief Met en place un modèle pour afficher une liste de volontaires.
  */
class MyQAbstractListModel : public QAbstractListModel
{
    Q_OBJECT
public:

    /*!
      @fn explicit MyQAbstractListModel(QObject *parent = 0);
      @brief Constructeur du modèle.
      */
    explicit MyQAbstractListModel(QObject *parent = 0);

    /*!
      @fn ~MyQAbstractListModel();
      @brief Destructeur du modèle.
      */
    ~MyQAbstractListModel();

    /*!
        @fn QVariant data(const QModelIndex &index, int role) const;
        @param const QModelIndex &index : Item sélectionné.
        @param int role : Définit l'information demandée.
        @return QVariant : Change en fonction du type d'information demandée.
        @brief  Retourne la valeur désignée par le rôle.
     */
    QVariant data(const QModelIndex& index, int role) const;

    /*!
        @fn bool setData (const QModelIndex &index, const QVariant &value, int role);
        @param const QModelIndex &index : Item sélectionné.
        @param const QVariant &value :  Valeur.
        @param int role :  Désigne ce qu'il faut initialiser.
        @return bool : False en cas d'échec, true sinon.
        @brief Fixe une valeur du modèle en fonction du rôle.
     */
    bool setData (const QModelIndex &index, const QVariant &value, int role);

    /*!
        @fn int rowCount(const QModelIndex &parent) const;
        @param const QModelIndex &parent : Parent de l'item
        @return int : Nombre d'élèments.
        @brief Retourne le nombre de lignes contenues par l'index.
        @note Dans notre cas, il n'y a qu'une unique ligne pour l'affichage du label.
    */
    int rowCount(const QModelIndex  &parent=QModelIndex() ) const;

    /*!
        @fn int rowCount(const QModelIndex &parent) const;
        @param const QModelIndex &parent : Parent de l'item
        @return int : Nombre d'élements.
        @brief Retourne le nombre de lignes contenues par l'index.
        @note Dans notre cas, il n'y a qu'une unique ligne pour l'affichage du label.
    */
    void setItems(const QVector<Volontaire*>* Volontaires);
    Qt::ItemFlags flags (const QModelIndex  &index ) const;
    void switchEtat();
    bool removeRow(int row);
    bool removeCheckedRow();
    void afficheVolontaire();

protected:
    const QVector<Volontaire*> *volontaires;

private:
    MainWindow *mainwindow;
};

#endif // MYQABSTRACTLISTMODEL_H
