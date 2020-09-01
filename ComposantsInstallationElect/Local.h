#ifndef LOCAL_H
#define LOCAL_H

#include "ComposantsInstallationElect_global.h"

#include <QString>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlRecord>
#include <math.h>

#define COSPHI_MOYEN 0.86
#define AUCUN_TABLEAU_PARENT "aucun tableau"
#define NOM_DE_BD "puissance_estimee"
#define TAB_ECLAIRAGE_FLUO "eclairage_fluo"
#define TAB_FORCE_MOTRICE "force_motrice"

class COMPOSANTSINSTALLATIONELECTSHARED_EXPORT Local
{
public:
    enum Unite{
        W = 0, KW = 1
    };

    enum TypeDeRecepteur
    {
        AucunType = 0, EclairageFluo = 1, ForceMotrice = 2
    };

    enum columnECL
    {
        NumECL = 0, ECL_TypeExploitation = 1, ECL_TypeLocal = 2, ECL_PEstimeeMax = 3, ECL_PEstimeeMin = 4, EclairementMoy = 5, CosPhi = 6
    };

    enum columnFM
    {
        NumFM = 0, FM_TypeLocal = 1, FM_PEstimeeMax = 2, FM_PEstimeeMin = 3
    };

    enum LocalColumn
    {
        Designation = 0, DesignationParent = 1, PuissanceEstimeeVAParM2 = 2, Superficie = 3,
        TypeDExploitation = 4, t_TypeDeLocal = 5, t_TypeDeRecepteur = 6, t_EclairementMoy = 7,
        t_CosPhi = 8, t_Unite = 9, t_PEstimeeMaxi = 10, t_PEstimeeMini = 11, t_TableauEnAmont = 12
    };

public:
    bool operator==(const Local & l)const;
    Local();
    Local(const QStringList & infos);
    Local(QString designation, TypeDeRecepteur typeDeRecepteur, QString typeDeLocal, float superficie, Unite u = KW, float cosPhi = COSPHI_MOYEN);
    Local(const Local & l);

    QStringList infosDuLocal()const;
    inline float superficie()const{return m_superficie;};
    inline float cosPhi()const{return m_cosPhi;};
    inline float puissanceEstimeeVAParM2()const{return m_puissanceEstimeeVAParM2;}; // pour des puissances qui varient
    inline Unite unite()const{return m_unite;};
    float puissanceUtiliseeM2()const;
    float puissanceUtiliseeM2(Unite u)const;
    QString typeDeExploitation()const;
    inline QString typeDeLocal()const{return m_typeDeLocal;};
    QString typeDeRecepteurStr()const;
    inline TypeDeRecepteur typeDeRecepteur()const{return m_typeDeRecepteur;};
    inline QString designation()const{return m_designation;};
    inline QString designationDuParent()const{return m_designationParent;};
    inline int eclairementMoy()const{return m_eclairementMoy;};
    inline bool typeUtilEstEclairage()const{return m_typeDeRecepteur == EclairageFluo;};
    inline bool typeUtilEstForceMotrice()const{return m_typeDeRecepteur == ForceMotrice;};

    void setSuperficie(float superficie);
    inline void setPEstimeeVAParM2(float puissance){m_puissanceEstimeeVAParM2 = puissance;};
    void setCosPhi(float cosPhi);
    void setUnite(Unite u);
    void setTypeDeRecepteur(QString type);
    void setTypeDeRecepteur(TypeDeRecepteur type);
    void setTypeDeLocal(QString type);
    inline void setDesignation(QString designation){m_designation = designation;};
    inline void setDesignationDuParent(QString designation){m_designationParent = designation;};

    float PInstallee()const;
    float _QInstallee()const;
    float PUtilisee()const;
    float _QUtilisee()const;

    float PInstalleeKW()const;
    float _QInstalleeKW()const;
    float PUtiliseeKW()const;
    float _QUtiliseeKW()const;

    bool localValide()const;
    bool possedeUnPere()const;

    inline float PEstimeeMax()const{return m_PEstimeeMaxi;};
    inline float PEstimeeMin()const{return m_PEstimeeMini;};
    QString description()const;
    void setDescription(QString des);

private:
    QString m_designation;
    QString m_designationParent;
    QString m_description;
    float m_puissanceEstimeeVAParM2;
    float m_superficie;
    QString m_typeDeExploitation;
    QString m_typeDeLocal;
    TypeDeRecepteur m_typeDeRecepteur;
    int m_eclairementMoy;
    float m_cosPhi;
    Unite m_unite;
    float m_PEstimeeMaxi;
    float m_PEstimeeMini;

    bool chargerDonneesDuLocal();
    void initialiserChampsDependants();

public:
    static QStringList listeDesTypesRecepteurs();
    static QString typeRecptToString(TypeDeRecepteur type);
    static TypeDeRecepteur stringToTypRecept(QString type);
    static QStringList listeDesTypesDExploitation(QString typeDeRecepteur);
    static QStringList listeDesTypesDeLocal(QString typeDeRecepteur);
    static QSqlRecord enregistrement1(QString typeDeRecepteur, QString typeDeLocal);
    static QSqlRecord enregistrement2(QString typeDeRecepteur, QString typeDExploitation);
    static QString adjusterValeur(QString valeur);
    static Local infosToLocal(const QStringList & infos);
    static QStringList localToInfos(const Local & l);
    static bool infosLocalValides(QStringList infos);
};

#endif // LOCAL_H
