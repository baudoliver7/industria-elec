#ifndef INSTALLATION_H
#define INSTALLATION_H

#include "ComposantsInstallationElect_global.h"

#include "Tableau.h"
#include "Transformateur.h"
#include <QMessageBox>

#define MOTCLE_TABLEAU "Tableau_cle"
#define MOTCLE_RECEPTEUR "Récepteur_cle"
#define MOTCLE_LOCAL "Local_cle"
#define MOTCLE_TRANSFO "Transfo_cle"

class COMPOSANTSINSTALLATIONELECTSHARED_EXPORT Installation : public Tableau
{
public:
    Installation();
    Installation(const QString & nom, const Tableau & TBGT);
    Installation(const Installation & i);
    ~Installation();

    QStringList infosDeInstallation()const;
    int nbDeNiveau();
    inline void setNom(QString nom){m_nom = nom;};
    inline QString nom()const{return m_nom;};

    inline Transformateur transformateur()const{return *m_transformateur;};
    inline void setTransformateur(const Transformateur & t){*m_transformateur = t;};
    inline void setKsTGBT(float ks){m_ks = ks;};
    inline float ksTGBT()const{return m_ks;};

    void setDesignationTGBT(const QString & designation);
    inline QString designationTGBT()const{return m_designation;};

    inline QList<Tableau> tableauxDeconnectes()const{return m_tableauxDeconnectes;};
    inline QList<Recepteur> recepteursDeconnectes()const{return m_recepteursDeconnectes;};
    inline QList<Local> locauxDeconnectes()const{return m_locauxDeconnectes;};

    QList<Tableau> tableauxSecondairesConnectes()const;
    QList<Tableau> coffretsDivisionnairesConnectes()const;
    QList<Tableau> terminauxConnectes()const;

    QList<Recepteur> recepteurs(bool connectesSeuls = false)const;
    QList<Local> locaux(bool connectesSeuls = false)const;
    QList<Tableau> tableaux(bool connectesSeuls = false)const;

    QList<Tableau> tableaux(Tableau::TypeDeTableau type, bool connectesSeuls = false)const;
    QList<Recepteur> recepteurs(Recepteur::TypeDeRecepteur type, bool connectesSeuls = false)const;
    QList<Local> locaux(Local::TypeDeRecepteur type, bool connectesSeuls = false)const;

    void installerUnRecepteur(const Recepteur & r, QString nomDuPere = AUCUN_TABLEAU_EN_AMONT);
    void installerUnTableau(const Tableau & t, QString nomDuPere = AUCUN_TABLEAU_EN_AMONT);
    void installerUnLocal(const Local & l, QString nomDuPere = AUCUN_TABLEAU_EN_AMONT);

    bool brancherUnRecepteur(const QString & nomDuFils, const QString & nomDuPere);
    bool brancherUnTableau(const QString &nomDuFils, const QString &nomDuPere);
    bool brancherUnLocal(const QString &nomDuFils, const QString &nomDuPere);
    bool brancherUnComposant(const QString &nomDuFils, const QString &nomDuPere);

    bool debrancherUnRecepteur(const QString & nom);
    bool debrancherUnTableau(const QString & nom);
    bool debrancherUnLocal(const QString & nom);
    bool debrancherUnComposant(const QString & nom);

    bool remplacerUnTableau(const QString & ancien, const Tableau & nouveauTableau);
    bool remplacerUnRecepteur(const QString & ancien, const Recepteur & nouveauRecepteur);
    bool remplacerUnLocal(const QString & ancien, const Local & nouveauLocal);

    bool possedeUnTableauConnecte(const QString & nomDuTableau);
    bool possedeUnRecepteurConnecte(const QString & nomDuRecepteur);
    bool possedeUnLocalConnecte(const QString & nomDuLocal);
    bool possedeUnComposantConnecte(const QString & cpt);

    bool possedeUnRecepteur(const QString & nomDuRecepteur);
    bool possedeUnLocal(const QString & nomDuLocal);
    bool possedeUnTableau(const QString & nomDuTableau);
    bool possedeUnComposant(const QString & cpt);

    Tableau & tableauConnecte(const QString & nomDuTableau);
    Tableau & tableauInstalle(const QString & nomDuTableau);

    Recepteur & recepteurConnecte(const QString & nomDuRecepteur);
    Recepteur & recepteurInstalle(const QString & nomDuRecepteur);

    Local & localConnecte(const QString &nomDuLocal);
    Local & localInstalle(const QString & nomDuLocal);

    Tableau & tableauDeconnecte(const QString & nomDuTableau);
    Recepteur & recepteurDeconnecte(const QString & nomDuRecepteur);
    Local & localDeconnecte(const QString & nomDuLocal);

    bool possedeUnRecepteurDeconnecte(const QString & nomDuRecepteur);
    bool possedeUnLocalDeconnecte(const QString & nomDuLocal);
    bool possedeUnTableauDeconnecte(const QString & nomDuTableau);

    bool desinstallerUnRecepteur(const QString & nomDuRecepteur);
    bool desinstallerUnTableau(const QString & nomDuTableau);
    bool desinstallerUnLocal(const QString & nomDuLocal);

    void trouverCaracteristiquesTransfo();

private:
    QString m_nom;
    QList<Tableau> m_tableauxDeconnectes;
    QList<Recepteur> m_recepteursDeconnectes;
    QList<Local> m_locauxDeconnectes;
    Transformateur * m_transformateur;

public:
    static Installation *  infosToInstallation(QStringList infos);
};

#endif // INSTALLATION_H
