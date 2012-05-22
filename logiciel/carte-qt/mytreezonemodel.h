/**
 * \file mytreezonemodel.h
 * \brief Model definissant l'affichage des zones dans un QtreeView.
 * \author Mickael Puret
 *
 */
#ifndef MYTREEZONEMODEL_H
#define MYTREEZONEMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>

class Groupe_selection;
class MainWindow;
class Selection;
class Rectangle;
class Cercle;

/*!
  @class class MyTreeZoneModel : public QAbstractItemModel
  @brief Définition d'un modèle pour afficher une structure composite pattern dans un QTreeView.
  */
class MyTreeZoneModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    /*!
      @fn explicit MyTreeZoneModel(QObject *parent = 0);
      @brief Constructeur du modèle.
      */
    explicit MyTreeZoneModel(QObject *parent = 0);

    /*!
      @fn ~MyTreeZoneModel();
      @brief Destructeur du modèle.
      */
    ~MyTreeZoneModel();

    /*!
      @fn void setRootNode(Groupe_selection *node);
      @param Groupe_selection *node : Pointeur sur la racine de l'arbre à afficher.
      @brief Définit la racine de l'arbre à afficher
      */
    void setRootNode(Groupe_selection *node);

    /*!
      @fn Groupe_selection *addGroup(QModelIndex item);
      @param QModelIndex item : Désigne l'item sélectionné.
      @return Groupe_selection * : La nouvelle zone.
      @brief Ajoute un groupe (Objet de type Groupe_selection) dans l'arbre à la position sélectionnée, et réactualise l'affichage du modèle.
      */
    Groupe_selection *addGroup(QModelIndex item);

    /*!
      @fn Selection *addSelection(QModelIndex item);
      @param QModelIndex item : Désigne l'item selectionné.
      @return Selection * : La nouvelle zone.
      @brief Ajoute une sélection (Objet de type Selection) dans l'arbre à la position sélectionnée, et réactualise l'affichage du modèle.
      */
    Selection *addSelection(QModelIndex item);

    /*!
      @fn Rectangle * addRect(QModelIndex item);
      @param QModelIndex item : Désigne l'item selectionné.
      @return Rectangle * : La nouvelle zone.
      @brief Ajoute un rectangle (Objet de type Rectangle) dans l'arbre à la position sélectionnée, et réactualise l'affichage du modèle.
      */
    Rectangle * addRect(QModelIndex item);

    /*!
      @fn Cercle * addCercle(QModelIndex item);
      @param QModelIndex item : Désigne l'item selectionné.
      @return Cercle * : La nouvelle zone.
      @brief Ajoute un cercle (Objet de type Cercle) dans l'arbre à la position sélectionnée, et réactualise l'affichage du modèle.
      */
    Cercle * addCercle(QModelIndex item);

    /*!
      @fn Groupe_selection *nodeFromIndex(const QModelIndex &index) const;
      @param const QModelIndex &index : Désigne l'item selectionné.
      @return Groupe_selection * : Zone de type composite.
      @brief Convertie un QModelIndex (référence une position de l'arbre dans le modèle) en un pointeur vers un objet de type Groupe_selection.
      @note Si l'index ne designe pas un objet de type Groupe_selection, alors c'est l'objet parent qui est renvoyé.
      */
    Groupe_selection *nodeFromIndex(const QModelIndex &index) const;

    /*!
      @fn void beginReset();
      @brief Accesseur indiquant que l'arbre commence à être modifié.
      */
    void beginReset();

    /*!
      @fn void endReset();
      @brief Accesseur indiquant que la modification de l'arbre est terminée.
      */
    void endReset();

signals:

public slots:
    /*!
      @fn void switchEtat(Groupe_selection *zones = NULL);
      @param Groupe_selection *zones : Racine de l'arbre dont l'état de ses éléments sera inversé. Si c'est null alors l'inversion s'applique sur tout l'arbre.
      @brief Evènement, inverse l'état de chaque zone designée.
      */
    void switchEtat(Groupe_selection *zones = NULL);
private:
    Groupe_selection *rootNode;
    MainWindow *mainwindow;

    /*!
        @fn QModelIndex index(int row, int column, const QModelIndex &parent) const;
        @param int row : Ligne de l'item
        @param int column : Colonne de l'item
        @param const QModelIndex &parent : Parent de l'item
        @brief Retourne l'index de l'item du modèle défini par la ligne, la colonne et le parent.
    */
    QModelIndex index(int row, int column, const QModelIndex &parent) const;

    /*!
        @fn int rowCount(const QModelIndex &parent) const;
        @param const QModelIndex &parent : Parent de l'item
        @return int : Nombre d'éléments.
        @brief Retourne le nombre de lignes contenues par l'index.
        @note Dans notre cas, il n'y a qu'une unique ligne pour l'affichage du label.
    */
    int rowCount(const QModelIndex &parent) const;

    /*!
        @fn int columnCount(const QModelIndex &parent) const;
        @param const QModelIndex &parent : Parent de l'item
        @return int : Nombre d'éléments.
        @brief Retourne le nombre de colonnes contenues par l'index.
        @note Si l'index n'est pas un composite, la fonction renvoie zéro.
    */
    int columnCount(const QModelIndex &parent) const;

    /*!
        @fn QModelIndex parent(const QModelIndex &child) const;
        @param const QModelIndex &child : Item sélectionné.
        @return QModelIndex : Parent de l'item.
        @brief Retourne un index sur l'item parent de celui passé en paramètre.
        @note Si l'index n'est pas un composite, la fonction renvoie zéro.
    */
    QModelIndex parent(const QModelIndex &child) const;

    /*!
        @fn QVariant data(const QModelIndex &index, int role) const;
        @param const QModelIndex &index : Item sélectionné.
        @param int role : Définit l'information demandée.
        @return QVariant : Change en fonction du type d'information demandée.
        @brief  Retourne la valeur désignée par le rôle.
     */
    QVariant data(const QModelIndex &index, int role) const;

    /*!
        @fn Qt::ItemFlags flags (const QModelIndex  &index ) const;
        @param const QModelIndex &index : Item sélectionné.
        @return Qt::ItemFlags : Paramètres de l'item.
        @brief  Retourne le paramètre associé à l'index.
     */
    Qt::ItemFlags flags (const QModelIndex  &index ) const;

    /*!
        @fn bool setData (const QModelIndex &index, const QVariant &value, int role);
        @param const QModelIndex &index : Item sélectionné.
        @param const QVariant &value :  Valeur.
        @param int role :  Désigne ce qu'il faut initialiser.
        @return bool : False en cas d'échec, true sinon.
        @brief Fixe une valeur du modèle en fonction du rôle.
     */
    bool setData (const QModelIndex &index, const QVariant &value, int role);

};

#endif // MYTREEZONEMODEL_H
