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
  @brief Met en place un model pour afficher une liste de volontaire.
  */
class MyQAbstractListModel : public QAbstractListModel
{
    Q_OBJECT
public:

    /*!
      @fn explicit MyQAbstractListModel(QObject *parent = 0);
      @brief Constructeur du model.
      */
    explicit MyQAbstractListModel(QObject *parent = 0);

    /*!
      @fn ~MyQAbstractListModel();
      @brief Desrtucteur du model.
      */
    ~MyQAbstractListModel();

    /*!
        @fn QVariant data(const QModelIndex &index, int role) const;
        @param const QModelIndex &index : Item s'électionné.
        @param int role : Definit l'information demendé.
        @return QVariant : Change en fonction du type d'inforation demandé.
        @brief  Retourne la valeur designé par le role.
     */
    QVariant data(const QModelIndex& index, int role) const;

    /*!
        @fn bool setData (const QModelIndex &index, const QVariant &value, int role);
        @param const QModelIndex &index : Item s'électionné.
        @param const QVariant &value :  valeur.
        @param int role :  designe ce qu'il fait initialiser.
        @return bool : False en cas d'échque, true sinon.
        @brief Fixe une valeur du model en fonction du role.
     */
    bool setData (const QModelIndex &index, const QVariant &value, int role);

    /*!
        @fn int rowCount(const QModelIndex &parent) const;
        @param const QModelIndex &parent : parent de l'item
        @return int : nombre d'élements.
        @brief Retourne le nombre de lignes contenus par l'index.
        @note Dans notre cas, il n'y a qu'une unique ligne pour l'affichage du label.
    */
    int rowCount(const QModelIndex  &parent=QModelIndex() ) const;

    /*!
        @fn int rowCount(const QModelIndex &parent) const;
        @param const QModelIndex &parent : parent de l'item
        @return int : nombre d'élements.
        @brief Retourne le nombre de lignes contenus par l'index.
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
