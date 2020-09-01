#ifndef RECEPTEUR_H
#define RECEPTEUR_H

#include "ComposantsInstallationElect_global.h"

#include <QString>
#include <QStringList>
#include <QObject>
#include <math.h>

#define RECEPTEUR "recepteur"
#define UN_CHEVAL 736

namespace cstesRecepteur
{
    const  QString AUCUN_TYPE_RECEPTEUR = "Aucun type";
    const QString AUCUN_TABLEAU_EN_AMONT = "aucun tableau";
}

using namespace cstesRecepteur;

class COMPOSANTSINSTALLATIONELECTSHARED_EXPORT Recepteur
{
public:
    bool operator==(const Recepteur & r) const;

public:
    enum TypeDeRecepteur
    {
        AucunType = 0, Eclairage = 1, Chauffage = 2, ConditionnementAir = 3, ForceMotrice = 4, PriseDeCourant = 5
    };

    enum Unite
    {
        KW = 0, W = 1, CH = 2
    };

    enum RecepteurColumn
    {
        Designation = 0, Putile = 1, Rendement = 2, Courant = 3, Tension = 4,
        Quantite = 5, CosPhi = 6, Pasborbee = 7, Ks = 8, Ku = 9, Pinstallee = 10,
        Qinstallee = 11, Putilisee = 12, Qutilisee = 13, TableauEnAmont = 14,
        TypeDuRecepteur = 15, TypeDeDonneesChoisi = 16, Monophase = 17,
        UnitePU = 18, UnitePA = 19
    };

    enum TypeDeDonneesAEntrer
    {
        AucunTypeDeDonnees = 0, PUtileEtRendement = 1, CourantTension = 2, PuissanceAbsorbee = 3
    };

public:
    Recepteur();
    Recepteur(const QStringList & infos);
    Recepteur(float pUtileUnitaire, float rendement = 1.0, int quantite = 1
              , float cos = 1.0, float ku = 1.0 , QString designation = QString()
                                                                        , TypeDeRecepteur typeDeRecepteur = AucunType, QString nomDuParent = cstesRecepteur::AUCUN_TABLEAU_EN_AMONT);
    Recepteur(float pAbsorbeeUnitaire, int quantite = 1, float cos = 1.0, float ku = 1.0
              , QString designation = QString(), TypeDeRecepteur typeDeRecepteur = AucunType, QString nomDuParent = cstesRecepteur::AUCUN_TABLEAU_EN_AMONT);

    Recepteur(float courant, int tension, int quantite = 1, float cos = 1.0, float ku = 1.0
              , QString designation = QString(), TypeDeRecepteur typeDeRecepteur = AucunType, QString nomDuParent = cstesRecepteur::AUCUN_TABLEAU_EN_AMONT);
    Recepteur(const Recepteur & r);
    ~Recepteur();

    inline int index()const{return m_index;};
    inline void setIndex(int index){m_index = index;};

    QStringList infosDuRecepteur()const;
    inline QString designation()const{return m_designation;};
    QString typeDeRecepteurToStr()const;
    TypeDeRecepteur typeDeRecepteur()const;
    float pUtileUnitaire(Unite u)const;
    inline float pUtileUnitaire()const{return m_pUtileUnitaire;};
    inline float pUtileUnitaireKW()const{return m_pUtileUnitaire/1000;};
    inline float pUtileUnitaireCh() const{return m_pUtileUnitaire/UN_CHEVAL;};
    inline int quantite()const{return m_quantite;};
    inline float cosPhi()const{return m_cosPhi;};
    inline float rendement()const{return m_rendement;};
    inline float ku()const{return m_ku;};
    inline float ks()const{return m_ks;};
    float pAbsorbeeUnitaire(Unite u)const;
    inline float pAbsorbeeUnitaire()const{return m_pAbsorbeeUnitaire;};
    inline float pAbsorbeeUnitaireKW()const{return m_pAbsorbeeUnitaire/1000;};
    inline QString designationDuParent()const{return m_designationDuParent;};

    inline void setDesignation(QString design){m_designation = design;};
    void setTypeDeRecepteur(QString type);
    void setTypeDeRecepteur(TypeDeRecepteur type);
    inline void setDesignationDuParent(QString designation){m_designationDuParent = designation;};

    void setPUtileUnitaire(float pu);
    void setPUtileUnitaire(float pu, Unite u);
    void setPUtileUnitaireCh(float pu);
    void setPUtileUnitaireKW(float pu);
    void setQuantite(int qte);
    void setCosPhi(float cos);
    void setRendement(float r);
    void setKu(float ku);
    void setKUParDefaut();
    void setKs(float ks);
    void setCosPhiParDefaut();
    void setRendementParDefaut();
    void setPAbsorbeeUnitaire(float pa, Unite u);
    void setPAbsorbeeUnitaire(float pa);
    void setPAbsorbeeUnitaireKW(float pa);

    inline bool PUtileEtRendementConnus()const{return !m_pUtileEtRendInconnus;};
    inline void setPUtileEtRendementConnus(bool connu){m_pUtileEtRendInconnus = !connu;};

    void setTypeDeDonneesEntre(TypeDeDonneesAEntrer type);
    inline TypeDeDonneesAEntrer typeDeDonneesEntree()const{return m_typeDeDonneesEntre;};
    QString typeDeDonneeEntreeStr()const;
    void setTypeDeDonneesEntre(QString type);

    void setCourant(float courant);
    void setTension(float tension);
    inline float courant()const{return m_courant;};
    inline float tension()const{return m_tension;};

    float PInstallee()const;
    float _QInstallee()const;

    float PUtilisee()const;
    float _QUtilisee()const;

    float PUtiliseeKW()const;
    float _QUtiliseeKW()const;

    float PInstalleeKW()const;
    float _QInstalleeKW()const;

    bool estEclairage()const;
    bool estConditionneurAir()const;
    bool estChauffage()const;
    bool estPriseDeCourant()const;
    bool estUnMoteur()const;
    inline bool possedeUnPere()const{return m_designationDuParent != AUCUN_TABLEAU_EN_AMONT;};
    float ksPriseDeCourant()const;
    float ksParDefaut()const;
    float kuParDefaut()const;
    float cosParDefaut()const;
    float rendementParDefaut()const;
    void actualiserCalculs(); // exécuter manuellement cette fonction
                                      // avant de prendre cette fonction
    inline void setMonophase(bool monophase){m_monophase = monophase;};
    inline bool monophase()const{return m_monophase;};

    inline void setUnitePU(Unite u){m_unitePU = u;};
    inline void setUnitePA(Unite u){m_unitePA = u;};

    inline Unite unitePA()const{return m_unitePA;};
    inline Unite unitePU()const{return m_unitePU;};
    QString description()const;
    void setDescription(QString des);

protected:
    QString m_designation;
    QString m_description;
    TypeDeRecepteur m_typeDeRecepteur;
    float m_pUtileUnitaire;
    float m_pAbsorbeeUnitaire;
    int m_quantite;
    float m_cosPhi;
    float m_rendement;
    float m_ku;
    float m_ks;
    bool m_monophase;
    QString m_designationDuParent;
    bool m_pUtileEtRendInconnus;
    TypeDeDonneesAEntrer m_typeDeDonneesEntre;
    float m_courant; // en ampères
    float m_tension; // en volts
    Unite m_unitePU;
    Unite m_unitePA;
    int m_index;

public:
    static QString typeToString(TypeDeRecepteur type);
    static TypeDeRecepteur qStringToType(QString type);
    static QStringList listeDesTypes();
    static QStringList recepteurToInfos(const Recepteur & r);
    static Recepteur infosToRecepteur(const QStringList & infos);
    static TypeDeDonneesAEntrer qStringToTypeDeDonnees(QString type);
    static QString typeDeDonneesToString(TypeDeDonneesAEntrer type);
    static QStringList listeDeTypeDeDonnees();
    static bool infosRecepteurValides(QStringList infos);

protected:
    float calculerPAbsorbeeUnitaire();

};

#endif // RECEPTEUR_H
