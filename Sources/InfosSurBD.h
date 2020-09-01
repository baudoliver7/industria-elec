#ifndef INFOSSURBD_H
#define INFOSSURBD_H

#include <QString>
#include <QStringList>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlRecord>
#include <QList>

namespace Memoire
{
    const QString Libelle = "Memoire";
    enum Id
    {
        Theme = 0, Auteur = 1, NiveauScolaire = 2, Annee = 3, NbPages = 4
    };
}

namespace TTableau
{
    const QString Libelle = "Tableau";

    enum Id
    {
        NumTableau = 0, Designation = 1, Ks = 2, DesignationParent = 3, TypeDeTableau = 4, NomDeInstallation = 5
    };
}

namespace TTGBT
{
    const QString Libelle = "TGBT";
    enum Id
    {
        Designation = 0, Ks = 1, NomDeInstallation = 2 /*clé primaire*/, Theme = 3
    };
}

namespace TRecepteur
{
    const QString Libelle = "Recepteur";
    enum Id
    {
        NumRecepteur = 0, Designation = 1, PUtileUnitaire = 2, Quantite = 3,
        CosPhi = 4, Rendement = 5, Tension = 6, Courant = 7, PAbsorbeeUnitaire = 8,
        Ks = 9, Ku = 10,
        TypeDeRecepteur = 11, DesignationParent = 12, TypeDeDonneesChoisi = 13,
        Monophase = 14, UnitePU = 15, UnitePA = 16, NomDeInstallation = 17
    };
}

class InfosSurBD
{
public:
    static bool enregistrerMemoire(const QStringList & infos);
    static bool enregistrerTableau(const QStringList & infos);
    static void enregistrerTableaux(const QList<QStringList> & tableaux);
    static bool enregistrerTGBT(const QStringList & infos);
    static bool enregistrerRecepteur(const QStringList & infos);
    static void enregistrerRecepteurs(const QList<QStringList> & recepteurs);

    static bool modifierTGBT(const QStringList & infos);
    static bool modifierTableau(const QStringList & infos);
    static bool modifierRecepteur(const QStringList & infos);

    static bool supprimerTGBT(const QString & nomDeInstallation); // pour supprimer toute l'installation

    static QStringList columnNames(const QSqlTableModel & model);
    static QStringList themes();
    static QStringList nomsDesInstallations();
    static QStringList nomsDesInstallations(const QString & theme);

    static bool tableauExiste(const QString & designation, const QString & nomDeInstallation);
    static bool recepteurExiste(const QString & designation, const QString & nomDeInstallation);
    static bool memoireExiste(const QString & theme);

    static QStringList infosTGBT(const QString & designation, const QString & nomDeInstallation);
    static QStringList infosTGBT(const QString & nomDeInstallation);
    static QStringList infosTableau(const QString & designation, const QString & nomDeInstallation);
    static QStringList infosRecepteur(const QString & designation, const QString & nomDeInstallation);

    static QList<QStringList> listeInfosTableaux(const QString & nomDeInstallation);
    static QList<QStringList> listeInfosRecepteurs(const QString & nomDeInstallation);
    static QString adapterValeur(const QString & valeur);
};

#endif // INFOSSURBD_H
