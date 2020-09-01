#include "Local.h"
#include <QSqlDatabase>

bool Local::operator ==(const Local & l)const
{
    return (m_designation == l.m_designation);
}

Local::Local()
{
    // je suppose que je suis connecté à la BD
    m_designation = QString();
    m_designationParent = AUCUN_TABLEAU_PARENT;
    m_puissanceEstimeeVAParM2 = 0;
    m_superficie = 0;
    m_typeDeExploitation = QString();
    m_typeDeLocal = QString();
    m_typeDeRecepteur = AucunType;
    m_cosPhi = COSPHI_MOYEN;
    m_unite = KW;
    m_eclairementMoy = 0;
    m_PEstimeeMaxi = 0;
    m_PEstimeeMini = 0;
}

Local::Local(QString designation, TypeDeRecepteur typeDeRecepteur, QString typeDeLocal, float superficie, Unite u, float cosPhi)
{
    // je suppose que je suis connecté à la BD
    m_designation = designation;
    m_designationParent = AUCUN_TABLEAU_PARENT;
    m_typeDeRecepteur = typeDeRecepteur;
    m_typeDeLocal = typeDeLocal;

    setSuperficie(superficie);
    setCosPhi(cosPhi);

    m_unite = u;
    m_puissanceEstimeeVAParM2 = 0;
    m_typeDeExploitation = QString();
    m_eclairementMoy = 0;
    m_PEstimeeMaxi = 0;
    m_PEstimeeMini = 0;

    chargerDonneesDuLocal();
}

Local::Local(const Local &l)
{
    m_designation = l.m_designation;
    m_designationParent = l.m_designationParent;
    m_puissanceEstimeeVAParM2 = l.m_puissanceEstimeeVAParM2;
    m_superficie = l.m_superficie;
    m_typeDeExploitation = l.m_typeDeExploitation;
    m_typeDeLocal = l.m_typeDeLocal;
    m_typeDeRecepteur = l.m_typeDeRecepteur;
    m_eclairementMoy = l.m_eclairementMoy;
    m_cosPhi = l.m_cosPhi;
    m_unite = l.m_unite;
    m_PEstimeeMaxi = l.m_PEstimeeMaxi;
    m_PEstimeeMini = l.m_PEstimeeMini;
    m_description = l.m_description;
}

QStringList Local::infosDuLocal()const
{
    return localToInfos(*this);
}

Local::Local(const QStringList &infos)
{
    *this = infosToLocal(infos);
}

float Local::puissanceUtiliseeM2()const
{
    return puissanceUtiliseeM2(m_unite);
}

float Local::puissanceUtiliseeM2(Unite u) const
{
    float puissance = m_puissanceEstimeeVAParM2 * m_cosPhi;
    if(m_unite == u)
    {
        return puissance / 1000.0;
    }

    return puissance;
}

QString Local::typeDeExploitation()const
{
    return m_typeDeExploitation;
}

QString Local::typeDeRecepteurStr()const
{
    return typeRecptToString(m_typeDeRecepteur);
}

void Local::setSuperficie(float superficie)
{
    if(superficie >= 0)
        m_superficie = superficie;
        else
        m_superficie = 0;
}

void Local::setCosPhi(float cosPhi)
{
    if(cosPhi > 0 && cosPhi <= 1)
        m_cosPhi = cosPhi;
        else
        m_cosPhi = 0;
}

void Local::setUnite(Unite u)
{
    m_unite = u;
}

void Local::setTypeDeLocal(QString type)
{
    m_typeDeLocal = type; // nouveau type de local donc recherche du type

    chargerDonneesDuLocal();
}

void Local::setTypeDeRecepteur(QString type)
{
    setTypeDeRecepteur(stringToTypRecept(type));
}

void Local::setTypeDeRecepteur(TypeDeRecepteur type)
{
    m_typeDeRecepteur = type;

    if(m_typeDeRecepteur == AucunType)
    {
        initialiserChampsDependants();
        return;
    }   

    m_typeDeLocal = listeDesTypesDeLocal(typeDeRecepteurStr()).at(0); // premier élement
    chargerDonneesDuLocal(); // caractéristiques de ce type de local
}

float Local::PInstallee()const
{
    return m_superficie * puissanceUtiliseeM2(W);
}

float Local::_QInstallee()const
{
    float f_tan = tan(acos(m_cosPhi));
    return f_tan * PInstallee();
}

float Local::PUtilisee()const
{
    return PInstallee();
}

float Local::_QUtilisee()const
{
    return _QInstallee();
}

float Local::PInstalleeKW()const
{
    return m_superficie * puissanceUtiliseeM2(KW);
}

float Local::_QInstalleeKW()const
{
    float f_tan = tan(acos(m_cosPhi));
    return f_tan * PInstalleeKW();
}

float Local::PUtiliseeKW()const
{
    return PInstalleeKW();
}

float Local::_QUtiliseeKW()const
{
    return _QInstalleeKW();
}


bool Local::localValide()const
{
    return ((m_typeDeExploitation == QString())
            || (m_typeDeLocal == QString()));
}

bool Local::possedeUnPere()const
{
    return m_designationParent != AUCUN_TABLEAU_PARENT;
}

QString Local::description()const
{
    return m_description;
}

void Local::setDescription(QString des)
{
    m_description = des;
}

QStringList Local::listeDesTypesRecepteurs()
{
    QStringList l;
    l << "Aucun type" << "Eclairage fluorescent" << "Force motrice";

    return l;
}

QString Local::typeRecptToString(TypeDeRecepteur type)
{
    return listeDesTypesRecepteurs().at(type);
}

Local::TypeDeRecepteur Local::stringToTypRecept(QString type)
{
    if(listeDesTypesRecepteurs().contains(type))
    {
        return (TypeDeRecepteur)listeDesTypesRecepteurs().indexOf(type);
    }else
    {
        return AucunType;
    }
}

QStringList Local::listeDesTypesDeLocal(QString typeDeRecepteur)
{
    QStringList l;
    TypeDeRecepteur type = stringToTypRecept(typeDeRecepteur);

    // on suppose BD ouverte
    QSqlDatabase db = QSqlDatabase::database("puissance_estimee");
    QSqlTableModel model(0, db);
    int typeLocalId;

    if(type == AucunType) return l;

    if(type == EclairageFluo)
    {
        model.setTable(TAB_ECLAIRAGE_FLUO);
        typeLocalId = ECL_TypeLocal;
    }else
    {
        model.setTable(TAB_FORCE_MOTRICE);
        typeLocalId = FM_TypeLocal;
    }

    model.select();

    for(int i = 0; i < model.rowCount(); i++)
    {
        l << model.record(i).value(typeLocalId).toString();
    }

    return l;
}

QStringList Local::listeDesTypesDExploitation(QString typeDeRecepteur)
{
    QStringList l;
    TypeDeRecepteur type = stringToTypRecept(typeDeRecepteur);

    // on suppose BD ouverte
    QSqlDatabase db = QSqlDatabase::database("puissance_estimee");
    QSqlTableModel model(0, db);

    if((type == AucunType)||(type == ForceMotrice)) return l;

    model.setTable(TAB_ECLAIRAGE_FLUO);

    model.select();

    for(int i = 0; i < model.rowCount(); i++)
    {
        l << model.record(i).value(ECL_TypeExploitation).toString();
    }

    return l;
}

QSqlRecord Local::enregistrement1(QString typeDeRecepteur, QString typeDeLocal)
{
    // on suppose BD ouverte
    QSqlDatabase db = QSqlDatabase::database("puissance_estimee");
    QSqlTableModel model(0, db);

    TypeDeRecepteur type = stringToTypRecept(typeDeRecepteur);

    if(type == AucunType) return model.record(); // retourner un record nul

    QString typeLocalLib;

    if(type == EclairageFluo)
    {
        model.setTable(TAB_ECLAIRAGE_FLUO);
        typeLocalLib = model.record().fieldName(ECL_TypeLocal);
    }else
    {
        model.setTable(TAB_FORCE_MOTRICE);
        typeLocalLib = model.record().fieldName(FM_TypeLocal);
    }

    model.setFilter(QObject::tr("%1 = '%2'")
                    .arg(typeLocalLib).arg(adjusterValeur(typeDeLocal)));
    model.select();

    if(model.rowCount() != 0)
    {
        return model.record(0); // 1 seul enregistrement
    }

    return model.record(); // retourner un record Eclairage vide
}

QSqlRecord Local::enregistrement2(QString typeDeRecepteur, QString typeDExploitation)
{
    // on suppose BD ouverte
    QSqlDatabase db = QSqlDatabase::database("puissance_estimee");
    QSqlTableModel model(0, db);

    TypeDeRecepteur type = stringToTypRecept(typeDeRecepteur);

    if(type == AucunType) return model.record(); // retourner un record nul

    QString typeDExpoitationLib;

    if(type == EclairageFluo)
    {
        model.setTable(TAB_ECLAIRAGE_FLUO);
        typeDExpoitationLib = model.record().fieldName(ECL_TypeExploitation);
    }else
    {
        // force motrice ne possède pas de type d'exploitation
        return model.record(); // retourner un record nul
    }

    model.setFilter(QObject::tr("%1 = '%2'").arg(typeDExpoitationLib).arg(adjusterValeur(typeDExploitation)));
    model.select();

    if(model.rowCount() != 0)
    {
        return model.record(0); // 1 seul enregistrement
    }

    return model.record(); // retourner un record Eclairage vide
}

bool Local::chargerDonneesDuLocal()
{
    if(m_typeDeRecepteur != AucunType)
    {
        QSqlRecord record = enregistrement1(typeDeRecepteurStr(), m_typeDeLocal);

        if(!record.isEmpty()&&!record.isNull(0)) // clé n'est pas nulle
        {
            if(m_typeDeRecepteur == EclairageFluo)
            {
                m_typeDeExploitation = record.value(ECL_TypeExploitation).toString();
                m_eclairementMoy = record.value(EclairementMoy).toInt();
                m_PEstimeeMaxi = record.value(ECL_PEstimeeMax).toFloat();
                m_PEstimeeMini = record.value(ECL_PEstimeeMin).toFloat();
            }else
            {
                m_typeDeExploitation = QString(); // n'en possède pas
                m_PEstimeeMaxi = record.value(FM_PEstimeeMax).toFloat();
                m_PEstimeeMini = record.value(FM_PEstimeeMin).toFloat();
            }

            m_puissanceEstimeeVAParM2 = m_PEstimeeMini;
            return true;
        }
    }

    return false;
}

void Local::initialiserChampsDependants()
{
    m_puissanceEstimeeVAParM2 = 0;
    m_superficie = 0;
    m_typeDeExploitation = QString();
    m_typeDeLocal = QString();
    m_cosPhi = COSPHI_MOYEN;
    m_eclairementMoy = 0;
    m_PEstimeeMaxi = 0;
    m_PEstimeeMini = 0;
}

QString Local::adjusterValeur(QString valeur)
{
    return valeur.replace("'", "''");
}

Local Local::infosToLocal(const QStringList &infos)
{
    Local l(infos.at(Designation)
          ,stringToTypRecept(infos.at(t_TypeDeRecepteur))
          ,infos.at(t_TypeDeLocal)
          ,infos.at(Superficie).toFloat()
          ,(Unite)infos.at(t_Unite).toInt()
          ,infos.at(t_CosPhi).toFloat()
          );

    l.m_puissanceEstimeeVAParM2 = infos.at(PuissanceEstimeeVAParM2).toFloat();
    l.m_eclairementMoy = infos.at(EclairementMoy).toInt();
    l.m_typeDeExploitation = infos.at(TypeDExploitation);
    l.m_PEstimeeMaxi = infos.at(t_PEstimeeMaxi).toFloat();
    l.m_PEstimeeMini = infos.at(t_PEstimeeMini).toFloat();
    l.setDesignationDuParent(infos.at(t_TableauEnAmont));
    return l;
}

QStringList Local::localToInfos(const Local &l)
{
    QStringList ll;
    ll << l.m_designation
            << l.m_designationParent
            << QString::number(l.m_puissanceEstimeeVAParM2)
            << QString::number(l.m_superficie)
            << l.m_typeDeExploitation
            << l.m_typeDeLocal
            << typeRecptToString(l.m_typeDeRecepteur)
            << QString::number(l.m_eclairementMoy)
            << QString::number(l.m_cosPhi)
            << QString::number((int)l.m_unite)
            << QString::number(l.m_PEstimeeMaxi)
            << QString::number(l.m_PEstimeeMini)
            << l.designationDuParent();

    return ll;
}

bool Local::infosLocalValides(QStringList infos)
{
    // vérifier la taille de la liste
    return (infos.count() == Local::localToInfos(Local()).count());
}
