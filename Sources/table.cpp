#include "table.h"

Table::Table(QTableWidget *tableWidget, Installation *installation)
{
    m_tableWidget = tableWidget;
    m_installation = installation;
}

Table::~Table()
{
    //delete m_tableWidget;
}

void Table::afficher(int row, const QStringList &valeurs, bool modifiable)
{
    if(row >= m_tableWidget->rowCount())
    {
        m_tableWidget->setRowCount(row + 1);
    }

    for(int i = 0; i < valeurs.count(); i++)
    {
        afficher(row, i, valeurs.at(i),modifiable);
    }
}

void Table::afficher(Tableau::TypeDeTableau type)
{
    m_tableWidget->setRowCount(0);
    QList<Tableau> lt;
    lt << m_installation->tableaux(type);

    for(int i = 0; i < lt.count(); i++)
    {
        afficher(i, lt.at(i).infosDuTableau(), true);
    }
}

void Table::afficher(Recepteur::TypeDeRecepteur type)
{
    m_tableWidget->setRowCount(0);
    QList<Recepteur> lr;
    lr << m_installation->recepteurs(type);

    for(int i = 0; i < lr.count(); i++)
    {
        afficher(i, lr.at(i).infosDuRecepteur(), true);
    }
}


void Table::afficherCurrentRange(bool modifiable)
{
    afficher(m_tableWidget->currentRow(), infosDeCurrentElement(), modifiable);
}

void Table::afficher(int row, int column, const QString &text, bool modifiable)
{
    QTableWidgetItem * item = new QTableWidgetItem(text);
    item->setTextAlignment(Qt::AlignCenter);

    if(!modifiable)
    {
        item->setFlags(Qt::ItemIsEditable);
    }

    m_tableWidget->setItem(row, column, item);
}

void Table::supprimer(int row)
{
    m_tableWidget->removeRow(row);
}

void Table::suppprimerCurrentRow()
{
    m_tableWidget->removeRow(m_tableWidget->currentRow());
}

void Table::ajouter(const QStringList &valeurs, bool modifiable)
{
    int rowAjout = m_tableWidget->rowCount();
    afficher(rowAjout,valeurs, modifiable);
}

QStringList Table::infosDeElement(int row)
{
    QStringList infos;

    for(int i = 0; i < m_tableWidget->columnCount(); i++)
    {
        infos << m_tableWidget->item(row, i)->text();
    }

    return infos;
}

QStringList Table::infosDeElement(const QString &designation)
{
    return infosDeElement(rowDe(designation));
}

int Table::rowDe(const QString &designation) const
{
    for(int row = 0; row < m_tableWidget->rowCount(); row++)
    {
        if(designation == m_tableWidget->item(row, 0)->text()); // 0 = column de désignation
        {
            return row;
        }
    }

    return -1;
}

QStringList Table::infosDeCurrentElement()
{
    return infosDeElement(m_tableWidget->currentRow());
}

void Table::remplacerDesignationParent(QString ancien, QString nouveau)
{
    int column = columnTableauEnAmont();


    if(column != -1)
    {
        for(int row = 0; row < m_tableWidget->rowCount(); row++)
        {
            if(element(row, column) == ancien)
            {
                afficher(row, columnTableauEnAmont(), nouveau, true);
            }
        }
    }
}

QString Table::element(int row, int column)
{
    return m_tableWidget->item(row, column)->text();
}

int Table::columnTableauEnAmont()
{
    for(int i = 0; i < m_tableWidget->columnCount(); i++)
    {
        if(m_tableWidget->horizontalHeaderItem(i)->text() == "Tableau en amont")
        {
            return i;
        }
    }

    return -1;
}
