#include "InfosSurBD.h"

bool InfosSurBD::tableauExiste(const QString &designation, const QString &nomDeInstallation)
{
    QSqlTableModel model;
    model.setTable(TTableau::Libelle);

    QString DesignationLib = columnNames(model).at(TTableau::Designation);
    QString NomDeInstallationLib = columnNames(model).at(TTableau::NomDeInstallation);

    model.setFilter(QObject::tr("%1 = '%2' AND %3 = '%4'")
                    .arg(DesignationLib).arg(QString(designation).replace(QString("'"), QString("''")))
                    .arg(NomDeInstallationLib).arg(QString(nomDeInstallation).replace(QString("'"), QString("''"))));
    model.select();

    bool existe;

    if(model.rowCount())
    {
        existe = true;        
    }else
    {
        existe = false;
    }

    model.clear();
    return existe;
}

bool InfosSurBD::recepteurExiste(const QString &designation, const QString &nomDeInstallation)
{
    QSqlTableModel model;
    model.setTable(TRecepteur::Libelle);

    QString DesignationLib = columnNames(model).at(TRecepteur::Designation);
    QString NomDeInstallationLib = columnNames(model).at(TRecepteur::NomDeInstallation);

    model.setFilter(QObject::tr("%1 = '%2' AND %3 = '%4'")
                    .arg(DesignationLib).arg(QString(designation).replace(QString("'"), QString("''")))
                    .arg(NomDeInstallationLib).arg(QString(nomDeInstallation).replace(QString("'"), QString("''"))));
    model.select();

    bool existe;

    if(model.rowCount())
    {
        existe = true;
    }else
    {
        existe = false;
    }

    model.clear();
    return existe;
}

QStringList InfosSurBD::columnNames(const QSqlTableModel &model)
{
    QStringList l;

    for(int i = 0; i < model.columnCount(); i++)
    {
        l << model.record().fieldName(i);
    }
    return l;
}

bool InfosSurBD::enregistrerTableau(const QStringList &infos)
{
    QSqlTableModel model;
    model.setTable(TTableau::Libelle);

    model.setFilter(QObject::tr("NumTableau = %1")
                    .arg(infos.at(TTableau::NumTableau)));
    model.select();

    bool succes = false;
    if(model.rowCount()==0)
    {
        int irowAjout = model.rowCount();
        model.insertRow(irowAjout);

        for(int column = 1; column < infos.count(); column++) /*on omet le numero*/
        {
            model.setData(model.index(irowAjout, column), infos.at(column));
        }

        succes = model.submitAll();
    }else
    {
        // il existe
        QSqlRecord record = model.record(0);

        for(int column = 1; column < infos.count(); column++)
        {
            record.setValue(column, infos.at(column));
        }

        if(model.setRecord(0,record))
        {
            succes = model.submitAll();
        }
    }


    model.clear();
    return succes;
}

bool InfosSurBD::enregistrerRecepteur(const QStringList &infos)
{
    QSqlTableModel model;
    model.setTable(TRecepteur::Libelle);

    model.setFilter(QObject::tr("NumRecepteur = %1")
                    .arg(infos.at(TRecepteur::NumRecepteur)));
    model.select();

    bool succes = false;
    if(model.rowCount()==0)
    {
        int irowAjout = model.rowCount();
        model.insertRow(irowAjout);

        for(int column = 1; column < infos.count(); column++) /*on omet le numero*/
        {
            model.setData(model.index(irowAjout, column), infos.at(column));
        }

        succes = model.submitAll();
    }else
    {
        // il existe
        QSqlRecord record = model.record(0);

        for(int column = 1; column < infos.count(); column++)
        {
            record.setValue(column, infos.at(column));
        }

        if(model.setRecord(0,record))
        {
            succes = model.submitAll();
        }
    }

    model.clear();
    return succes;
}

bool InfosSurBD::enregistrerMemoire(const QStringList &infos)
{
    QSqlTableModel model;
    model.setTable(Memoire::Libelle);

    model.select();

    int iRowAjout = model.rowCount();
    model.insertRow(iRowAjout);

    for(int column = 0; column < infos.count(); column++)
    {
        model.setData(model.index(iRowAjout, column), infos.at(column));
    }

    bool succes = model.submitAll();
    model.clear();
    return succes;
}

bool InfosSurBD::enregistrerTGBT(const QStringList &infos)
{
    QSqlTableModel model;
    model.setTable(TTGBT::Libelle);

    model.setFilter(QObject::tr("NomDeInstallation = '%1'")
                    .arg(adapterValeur(infos.at(TTGBT::NomDeInstallation))));
    model.select();

    bool succes = false;

    if(model.rowCount() == 0)
    {
        int irowAjout = model.rowCount();
        model.insertRow(irowAjout);

        for(int column = 0; column < infos.count(); column++)
        {
            model.setData(model.index(irowAjout, column), infos.at(column));
        }

        succes = model.submitAll();
    }else
    {
        // il existe
        QSqlRecord record = model.record(0);

        for(int column = 0; column < infos.count(); column++)
        {
            record.setValue(column, infos.at(column));
        }

        if(model.setRecord(0,record))
        {
            succes = model.submitAll();
        }
    }

    model.clear();
    return succes;
}

bool InfosSurBD::memoireExiste(const QString &theme)
{
    QSqlTableModel model;
    model.setTable(Memoire::Libelle);

    QString ThemeLib = columnNames(model).at(Memoire::Theme);

    model.setFilter(QObject::tr("%1 = '%2'").arg(ThemeLib).arg(QString(theme).replace(QString("'"), QString("''"))));
    model.select();

    bool existe;

    if(model.rowCount())
    {
        existe = true;
    }else
    {
        existe = false;
    }

    model.clear();
    return existe;
}

QStringList InfosSurBD::themes()
{
    QSqlTableModel model;
    model.setTable(Memoire::Libelle);
    model.select();

    QStringList l;
    for(int i = 0; i < model.rowCount(); i++)
    {
        l << model.record(i).value(Memoire::Theme).toString();
    }

    model.clear();
    return l;
}

QStringList InfosSurBD::nomsDesInstallations()
{
    QSqlTableModel model;
    model.setTable(TTGBT::Libelle);
    model.select();

    QStringList l;
    for(int i = 0; i < model.rowCount(); i++)
    {
        l << model.record(i).value(TTGBT::NomDeInstallation).toString();
    }

    model.clear();
    return l;
}

QStringList InfosSurBD::nomsDesInstallations(const QString &theme)
{
    QSqlTableModel model;
    model.setTable(TTGBT::Libelle);

    QString ThemeLib = columnNames(model).at(TTGBT::Theme);

    model.setFilter(QObject::tr("%1 = '%2'")
                    .arg(ThemeLib).arg(QString(theme).replace(QString("'"), QString("''"))));
    model.select();

    QStringList l;
    for(int i = 0; i < model.rowCount(); i++)
    {
        l << model.record(i).value(TTGBT::NomDeInstallation).toString();
    }

    model.clear();
    return l;
}

bool InfosSurBD::modifierTGBT(const QStringList & infos)
{
    QSqlTableModel model;
    model.setTable(TTGBT::Libelle);

    QString DesignationLib = columnNames(model).at(TTGBT::Designation);
    QString NomDeInstallationLib = columnNames(model).at(TTGBT::NomDeInstallation);

    model.setFilter(QObject::tr("%1 = '%2' AND %3 = '%4'")
                    .arg(DesignationLib).arg(QString(infos.at(TTGBT::Designation)).replace(QString("'"), QString("''")))
                    .arg(NomDeInstallationLib).arg(QString(infos.at(TTGBT::NomDeInstallation)).replace(QString("'"), QString("''"))));

    bool trouve = model.rowCount() != 0;

    if(trouve)
    {
        QSqlRecord record = model.record(0);

        for(int i = 0; i < infos.count(); i++)
        {
            record.setValue(i, infos.at(i));
        }

        model.setRecord(0, record);
        model.submitAll();
    }

    model.clear();
    return trouve;
}

bool InfosSurBD::modifierTableau(const QStringList & infos)
{
    QSqlTableModel model;
    model.setTable(TTableau::Libelle);

    QString DesignationLib = columnNames(model).at(TTableau::Designation);
    QString NomDeInstallationLib = columnNames(model).at(TTableau::NomDeInstallation);

    model.setFilter(QObject::tr("%1 = '%2' AND %3 = '%4'")
                    .arg(DesignationLib).arg(QString(infos.at(TTableau::Designation)).replace(QString("'"), QString("''")))
                    .arg(NomDeInstallationLib).arg(QString(infos.at(TTableau::NomDeInstallation)).replace(QString("'"), QString("''"))));
    model.select();

    bool trouve = model.rowCount() != 0;
    bool modifie = false;

    if(trouve)
    {
        QSqlRecord record = model.record(0);

        for(int i = 1; i < infos.count(); i++) /*on omet le numero*/
        {
            record.setValue(i, infos.at(i));
        }

        model.setRecord(0, record);
        modifie = model.submitAll();
    }else
    {
        modifie = enregistrerTableau(infos);
    }

    model.clear();
    return modifie;
}

bool InfosSurBD::modifierRecepteur(const QStringList &infos)
{
    QSqlTableModel model;
    model.setTable(TRecepteur::Libelle);

    QString DesignationLib = columnNames(model).at(TRecepteur::Designation);
    QString NomDeInstallationLib = columnNames(model).at(TRecepteur::NomDeInstallation);

    model.setFilter(QObject::tr("%1 = '%2' AND %3 = '%4'")
                    .arg(DesignationLib).arg(QString(infos.at(TRecepteur::Designation)).replace(QString("'"), QString("''")))
                    .arg(NomDeInstallationLib).arg(QString(infos.at(TRecepteur::NomDeInstallation)).replace(QString("'"), QString("''"))));
    model.select();

    bool modifie = false;
    bool trouve = model.rowCount() != 0;

    if(trouve)
    {
        QSqlRecord record = model.record(0);

        for(int i = 1; i < infos.count(); i++) /*on omet le numero*/
        {
            record.setValue(i, infos.at(i));
        }

        model.setRecord(0, record);
        modifie = model.submitAll();
    }else
    {
        modifie = enregistrerRecepteur(infos);
    }

    model.clear();
    return modifie;
}

bool InfosSurBD::supprimerTGBT(const QString & nomDeInstallation)
{
    QSqlTableModel model;
    model.setTable(TTGBT::Libelle);

    QString NomDeInstallationLib = columnNames(model).at(TTGBT::NomDeInstallation);

    QString requete = QObject::tr("%1='%2'")
                      .arg(NomDeInstallationLib).arg(QString(nomDeInstallation).replace(QString("'"), QString("''")));
    model.setFilter(requete);
    model.select();

    bool supprime = false;
    bool trouve = model.rowCount() != 0;
    if(trouve)
    {
        supprime = model.removeRow(0);  // ceci supprime tous les tableaux et recepteurs appartenant à l'installation électrique
        model.submitAll();
    }

    model.clear();
    return supprime;
}

QStringList InfosSurBD::infosTGBT(const QString &designation, const QString &nomDeInstallation)
{
    QSqlTableModel model;
    model.setTable(TTGBT::Libelle);

    QString DesignationLib = columnNames(model).at(TTGBT::Designation);
    QString NomDeInstallationLib = columnNames(model).at(TTGBT::NomDeInstallation);

    model.setFilter(QObject::tr("%1 = '%2' AND %3 = '%4'")
                    .arg(DesignationLib).arg(QString(designation).replace(QString("'"), QString("''")))
                    .arg(NomDeInstallationLib).arg(QString(nomDeInstallation).replace(QString("'"), QString("''"))));
    model.select();

    QStringList infos;

    bool trouve =  model.rowCount() != 0;

    if(trouve)
    {
        for(int i = 0; i < model.columnCount(); i++)
        {
            infos << model.record(0).value(i).toString();
        }
    }

    model.clear();
    return infos;
}

QStringList InfosSurBD::infosTGBT(const QString &nomDeInstallation)
{
    QSqlTableModel model;
    model.setTable(TTGBT::Libelle);

    QString NomDeInstallationLib = columnNames(model).at(TTGBT::NomDeInstallation);

    model.setFilter(QObject::tr("%1 = '%2'")
                    .arg(NomDeInstallationLib).arg(QString(nomDeInstallation).replace(QString("'"), QString("''"))));
    model.select();

    QStringList infos;

    bool trouve =  model.rowCount() != 0;

    if(trouve)
    {
        for(int i = 0; i < model.columnCount(); i++)
        {
            infos << model.record(0).value(i).toString();
        }
    }

    model.clear();
    return infos;
}

QStringList InfosSurBD::infosTableau(const QString &designation, const QString &nomDeInstallation)
{
    QSqlTableModel model;
    model.setTable(TTableau::Libelle);

    QString DesignationLib = columnNames(model).at(TTableau::Designation);
    QString NomDeInstallationLib = columnNames(model).at(TTableau::NomDeInstallation);

    model.setFilter(QObject::tr("%1 = '%2' AND %3 = '%4'")
                    .arg(DesignationLib).arg(QString(designation).replace(QString("'"), QString("''")))
                    .arg(NomDeInstallationLib).arg(QString(nomDeInstallation).replace(QString("'"), QString("''"))));
    model.select();

    QStringList infos;

    bool trouve =  model.rowCount() != 0;

    if(trouve)
    {
        for(int i = 0; i < model.columnCount(); i++)
        {
            infos << model.record(0).value(i).toString();
        }
    }

    model.clear();
    return infos;
}

QStringList InfosSurBD::infosRecepteur(const QString &designation, const QString &nomDeInstallation)
{
    QSqlTableModel model;
    model.setTable(TRecepteur::Libelle);

    QString DesignationLib = columnNames(model).at(TRecepteur::Designation);
    QString NomDeInstallationLib = columnNames(model).at(TRecepteur::NomDeInstallation);

    model.setFilter(QObject::tr("%1 = '%2' AND %3 = '%4'")
                    .arg(DesignationLib).arg(QString(designation).replace(QString("'"), QString("''")))
                    .arg(NomDeInstallationLib).arg(QString(nomDeInstallation).replace(QString("'"), QString("''"))));
    model.select();

    QStringList infos;

    bool trouve =  model.rowCount() != 0;

    if(trouve)
    {
        for(int i = 0; i < model.columnCount(); i++)
        {
            infos << model.record(0).value(i).toString();
        }
    }

    model.clear();
    return infos;
}

QList<QStringList> InfosSurBD::listeInfosTableaux(const QString &nomDeInstallation)
{
    QSqlTableModel model;
    model.setTable(TTableau::Libelle);

    QString NomDeInstallationLib = columnNames(model).at(TTableau::NomDeInstallation);

    model.setFilter(QObject::tr("%1 = '%2'")
                    .arg(NomDeInstallationLib).arg(QString(nomDeInstallation).replace(QString("'"), QString("''"))));
    model.select();

    QList<QStringList> listeInfos;
    QList<QStringList> infosTD;
    QList<QStringList> infosTer;

    for(int i = 0; i < model.rowCount(); i++)
    {
        QStringList infos;

        for(int j = 0; j < model.columnCount(); j++)
        {
            infos << model.record(i).value(j).toString();
        }

        if(infos.at(TTableau::TypeDeTableau)=="Tableau sécondaire")
        {
            listeInfos << infos;
        }else
        {
            if(infos.at(TTableau::TypeDeTableau)=="Tableau divisionnaire")
            {
                infosTD << infos;
            }else
            {
                infosTer << infos;
            }
        }
    }

    listeInfos << infosTD
               << infosTer;

    model.clear();
    return listeInfos;
}

QList<QStringList> InfosSurBD::listeInfosRecepteurs(const QString &nomDeInstallation)
{
    QSqlTableModel model;
    model.setTable(TRecepteur::Libelle);

    QString NomDeInstallationLib = columnNames(model).at(TRecepteur::NomDeInstallation);

    model.setFilter(QObject::tr("%1 = '%2'")
                    .arg(NomDeInstallationLib).arg(adapterValeur(nomDeInstallation)));
    model.select();

    QList<QStringList> listeInfos;

    for(int i = 0; i < model.rowCount(); i++)
    {
        QStringList infos; infos.clear();

        for(int j = 0; j < model.columnCount(); j++)
        {
            infos << model.record(i).value(j).toString();
        }

        listeInfos << infos;
    }

    model.clear();
    return listeInfos;
}

QString InfosSurBD::adapterValeur(const QString &valeur)
{
    return QString(valeur).replace("'", "''");
}

void InfosSurBD::enregistrerTableaux(const QList<QStringList> &tableaux)
{
    if(!tableaux.isEmpty())
    {
        QString nomDeInstallation = tableaux.at(0).at(TTableau::NomDeInstallation);

        QSqlTableModel model;
        model.setTable(TTableau::Libelle);
        model.setFilter(QObject::tr("NomDeInstallation = '%1'").arg(adapterValeur(nomDeInstallation)));
        model.select();

        QList<int> indexes; // liste des indexes des élements à enregistrer
        for(int i = 0; i < tableaux.count(); i++)
        {
            indexes << tableaux.at(i).at(TTableau::NumTableau).toInt();
        }

        indexes.removeAll(0); // supprimer les indexes nuls

        // supprimer les enregistrements manquants
        for(int i = 0; i < model.rowCount();i++)
        {
            if(!indexes.contains(model.record(i).value(TTableau::NumTableau).toInt()))
            {
                // enregistrement n'existe plus donc à supprimer
                model.removeRow(i);
                i--;
            }
        }

        model.submitAll();
        model.clear();

        for(int i = 0; i < tableaux.count(); i++)
        {
            enregistrerTableau(tableaux.at(i));
        }
    }
}

void InfosSurBD::enregistrerRecepteurs(const QList<QStringList> &recepteurs)
{
    if(!recepteurs.isEmpty())
    {
        QString nomDeInstallation = recepteurs.at(0).at(TRecepteur::NomDeInstallation);

        QSqlTableModel model;
        model.setTable(TRecepteur::Libelle);
        model.setFilter(QObject::tr("NomDeInstallation = '%1'").arg(adapterValeur(nomDeInstallation)));
        model.select();

        QList<int> indexes; // liste des indexes des élements à enregistrer
        for(int i = 0; i < recepteurs.count(); i++)
        {
            indexes << recepteurs.at(i).at(TRecepteur::NumRecepteur).toInt();
        }

        indexes.removeAll(0); // supprimer les indexes nuls

        // supprimer les enregistrements manquants
        for(int i = 0; i < model.rowCount();i++)
        {
            if(!indexes.contains(model.record(i).value(TRecepteur::NumRecepteur).toInt()))
            {
                // enregistrement n'existe plus donc à supprimer
                model.removeRow(i);
                i--;
            }
        }

        model.submitAll();
        model.clear();

        for(int i = 0; i < recepteurs.count(); i++)
        {
            enregistrerRecepteur(recepteurs.at(i));
        }
    }
}
