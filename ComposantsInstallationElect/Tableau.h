#ifndef TABLEAU_H
#define TABLEAU_H

#include "ComposantsInstallationElect_global.h"

/* classes de Qt */
#include <QString>
#include <QStringList>
#include <QList>

/* Mes classes */
#include "Recepteur.h"
#include "Local.h"

using namespace cstesRecepteur;

class Tableau;

class COMPOSANTSINSTALLATIONELECTSHARED_EXPORT Tableau
{
public:
    bool operator==(const Tableau & t) const;

public:
    enum TypeDeTableau
    {
        AucunType = 0, TGBT = 1, TableauSecondaire = 2, CoffretDivisionnaire = 3, Terminal = 4
    };

    enum TableauColumn
    {
        Designation = 0, Ks = 1, CosPhi = 2,
        Pinstallee = 3, Qinstallee = 4, Putilisee = 5,
        Qutilisee = 6, TableauEnAmont = 7, TypeDuTableau = 8
    };

public:
    Tableau();
    Tableau(TypeDeTableau type, float ks = 0.9, QString m_designation = QString(),QString nomDuParent = cstesRecepteur::AUCUN_TABLEAU_EN_AMONT);
    Tableau(const QStringList & infos);
    Tableau(const Tableau & t);

    inline int index()const{return m_index;};
    inline void setIndex(int index){m_index = index;};

    QStringList infosDuTableau()const;
    inline QString designation()const{return m_designation;};
    inline TypeDeTableau typeDeTableau()const{return m_typeDeTableau;};
    QString typeDeTableauStr()const;

    inline QList<Tableau> tableauxFils()const{return m_tableauxFils;};
    inline QList<Recepteur> recepteursFils()const{return m_recepteursFils;};
    inline QList<Local> locauxFils()const{return m_locauxFils;};

    void setTableauxFils(const QList<Tableau> & lt);
    void setRecepteursFils(const QList<Recepteur> & lr);
    void setLocauxFils(const QList<Local> & ll);

    void setDesignation(QString nom);
    inline void setTypeDeTableau(TypeDeTableau type){m_typeDeTableau = type;};
    void setTypeDeTableau(QString type);

    void setDesignationDuParent(const QString & designation);
    inline QString designationDuParent()const{return m_designationDuParent;};

    inline float ks()const{return m_ks;};
    void setKs(float ks);

    float PInstallee()const;
    float _QInstallee()const;

    float PInstalleeKW()const;
    float _QInstalleeKW()const;

    float PUtilisee()const;
    float _QUtilisee()const;

    float PUtiliseeKW()const;
    float _QUtiliseeKW()const;

    float cosPhi()const;
    inline bool estUnTGBT()const{return m_typeDeTableau == Tableau::TGBT;};
    inline bool estUnTS()const{return m_typeDeTableau == Tableau::TableauSecondaire;};
    inline bool estUnCD()const{return m_typeDeTableau == Tableau::CoffretDivisionnaire;};
    inline bool estUnTerminal()const{return m_typeDeTableau == Tableau::Terminal;};

    QList<Recepteur >::iterator recepteur(const QString & designation, bool inclureSousTableaux = false);
    bool possedeRecepteurFils(const QString & designation, bool inclureSousTableaux = false);
    Recepteur & recepteurFils(const QString & designation, bool inclureSousTableaux = false);

    QList<Tableau>::iterator tableau(const QString & designation, bool inclureSousTableaux = false);
    bool possedeTableauFils(const QString & designation, bool inclureSousTableaux = false);
    Tableau & tableauFils(const QString & designation, bool inclureSousTableaux = false);

    QList<Local>::iterator local(const QString & designation, bool inclureSousTableaux = false);
    bool possedeLocalFils(const QString & designation, bool inclureSousTableaux = false);
    Local & localFils(const QString & designation, bool inclureSousTableaux = false);

    Tableau & pereDe(const QString & fils);

    bool estPereDe(const Recepteur & r)const;
    bool estPereDe(const Local & l)const;
    bool estPereDe(const Tableau & t)const;
    bool estFilsDe(const Tableau & t)const;

    bool estPereDe(const QString & fils)const;
    bool estFilsDe(const QString & pere)const;
    bool estPere()const;

    inline bool possedeUnPere()const{return m_designationDuParent != AUCUN_TABLEAU_EN_AMONT;};

    bool ajouterUnRecepteur(const Recepteur & recepteur);
    bool ajouterUnLocal(const Local & l);
    bool ajouterUnTableau(const Tableau & tableau);

    void ajouterDesRecepteurs(const QList<Recepteur> & lr);
    void ajouterDesLocaux(const QList<Local> & ll);
    void ajouterDesTableaux(const QList<Tableau> & lt);

    void remplacerUnTableau(const QString & ancien, const Tableau & nouveauTableau);
    void remplacerUnRecepteur(const QString & ancien, const Recepteur & nouveauRecepteur);
    void remplacerUnLocal(const QString & ancien, const Local & nouveauLocal);

    bool supprimerUnRecepteur(const QString & nom);
    bool supprimerUnLocal(const QString & nom);
    bool supprimerUnTableau(const QString & nom);

    void supprimerAllRecepteursFils();
    void supprimerAllLocauxFils();
    void supprimerAllTableauxFils();
    void supprimerAllFils();

    QList<Tableau> tableauxDeDescendance()const;
    QList<Recepteur> recepteursDeDescendance()const;
    QList<Local> locauxDeDescendance()const;

    QList<Recepteur> debrancherRecepteursFils();
    QList<Local> debrancherLocauxFils();
    QList<Tableau> debrancherTableauxFils();

    int niveau()const;
    QList<Tableau> terminauxFils()const;
    QList<Tableau> TSFils()const;
    QList<Tableau> TDFils()const;

    bool typeUtilEstEclairage()const;
    bool typeUtilEstPriseDeCourant()const;
    bool typeUtilEstForceMotrice()const;
    bool typeUtilEstInconnu()const;

    float ksParDefaut()const;
    int nbDeCircuit()const;

    QString description()const;
    void setDescription(QString des);

protected:
    QList<Tableau> m_tableauxFils;
    QList<Recepteur> m_recepteursFils;
    QList<Local> m_locauxFils;

    float m_ks;
    int m_index;

    QString m_designationDuParent;
    QString m_designation;
    QString m_description;

    TypeDeTableau m_typeDeTableau;

    static int niveau(const Tableau & t);

public:
    template <class T>
    static float pPInstallee(QList<T> liste);

    template <class T>
    static float pQInstallee(QList<T> liste);

    template <class T>
    static float pPUtilisee(QList<T> liste, float ks);

    template <class T>
    static float pQUtilisee(QList<T> liste, float ks);

    static QString typeToString(TypeDeTableau type);
    static TypeDeTableau qStringToType(QString type);
    static QStringList listeDeTypeTableau();

    static QStringList tableauToInfos(const Tableau & t);
    static Tableau infosToTableau(const QStringList & infos);
    static bool infosTableauValides(QStringList infos);

public:
    template <class T>
    static void rangerParOrdreCroissant(QList<T> & l);
};

template <class T>
float Tableau::pPInstallee(QList<T> liste)
{
    float somme = 0;
    for(int i = 0; i < liste.count(); i++)
    {
        somme += liste.at(i).PInstallee();
    }
    return somme;
}

template <class T>
float Tableau::pQInstallee(QList<T> liste)
{
    float somme = 0;
    for(int i = 0; i < liste.count(); i++)
    {
        somme += liste.at(i)._QInstallee();
    }

    return somme;
}

template <class T>
float Tableau::pPUtilisee(QList<T> liste, float ks)
{
    float somme = 0;
    for(int i = 0; i < liste.count(); i++)
    {
        somme += liste.at(i).PUtilisee();
    }

    return somme * ks;
}

template <class T>
float Tableau::pQUtilisee(QList<T> liste, float ks)
{
    float somme = 0;
    for(int i = 0; i < liste.count(); i++)
    {
        somme += liste.at(i)._QUtilisee();
    }

    return somme * ks;
}

template <class T>
void Tableau::rangerParOrdreCroissant(QList<T> & lrr)
{
    // ranger par ordre alphabétique
    for(int i = 0; i < lrr.count() - 1; i++)
    {
        for(int j = i+1 ; j < lrr.count(); j++)
        {
            if(lrr.at(i).designation() > lrr.at(j).designation())
            {
                lrr.swap(i,j);
            }
        }
    }
}

#endif // TABLEAU_H
