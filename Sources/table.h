#ifndef TABLE_H
#define TABLE_H

#include <QTableWidget>
#include <QString>
#include <QStringList>
#include <QTableWidgetItem>
#include <QList>

#include "installation.h"
#include "Recepteur.h"

class Table
{
public:
    Table(QTableWidget * tableWidget, Installation * installation);
    ~Table();

    inline void setTableWidget(QTableWidget * tableWidget){m_tableWidget = tableWidget;};
    inline QTableWidget * tableWidget()const{return m_tableWidget;};

    inline void setInstallation(Installation * installation){m_installation = installation;};
    inline Installation * installation()const{return m_installation;};

    void afficher(Tableau::TypeDeTableau type);
    void afficher(Recepteur::TypeDeRecepteur type);

    QStringList infosDeElement(int row);
    QStringList infosDeCurrentElement();
    QStringList infosDeElement(const QString & designation);

    int rowDe(const QString & designation)const;

    void afficher(int row, int column, const QString & text, bool modifiable = true);
    void afficher(int row, const QStringList & valeurs, bool modifiable = true);
    void afficherCurrentRange(bool modifiable = true);
    void supprimer(int row);
    void suppprimerCurrentRow();
    void ajouter(const QStringList & valeurs, bool modifiable = true);
    void remplacerDesignationParent(QString ancien, QString nouveau);
    int columnTableauEnAmont();
    QString element(int row, int column);

private:
    QTableWidget * m_tableWidget;
    Installation * m_installation;


};

#endif // TABLE_H
