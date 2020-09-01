#include "Recepteur.h"

bool Recepteur::operator ==(const Recepteur & r) const
{
//    return (m_typeDeRecepteur == r.m_typeDeRecepteur
//            && m_pUtileUnitaire == r.m_pUtileUnitaire
//            && m_rendement == r.m_rendement
//            && m_pAbsorbeeUnitaire == r.m_pAbsorbeeUnitaire);
    return (m_designation == r.m_designation);
}

Recepteur::Recepteur()
{
    m_typeDeRecepteur = AucunType;

    m_pUtileUnitaire = 0.0;
    m_quantite = 1;
    m_cosPhi = cosParDefaut();
    m_rendement = rendementParDefaut();
    m_ku = kuParDefaut();
    m_ks = ksParDefaut();
    m_tension = 231;
    m_courant = 0;
    m_pUtileEtRendInconnus = false;
    m_designationDuParent = AUCUN_TABLEAU_EN_AMONT;
    m_typeDeDonneesEntre = PUtileEtRendement;
    m_monophase = true;
    m_unitePA = KW;
    m_unitePU = KW;
    m_index = 0;

    actualiserCalculs();
}

Recepteur::Recepteur(const QStringList &infos)
{
    m_designation = infos.at(Designation);
    m_typeDeRecepteur = qStringToType(infos.at(TypeDuRecepteur));

    m_pUtileUnitaire = infos.at(Putile).toFloat();
    m_quantite = infos.at(Quantite).toInt();
    m_cosPhi = infos.at(CosPhi).toFloat();
    m_rendement = infos.at(Rendement).toFloat();
    m_ku = infos.at(Ku).toFloat();
    m_ks = infos.at(Ks).toFloat();
    m_pAbsorbeeUnitaire = infos.at(Pasborbee).toFloat();
    m_designationDuParent = infos.at(TableauEnAmont);
    m_typeDeDonneesEntre = qStringToTypeDeDonnees(infos.at(TypeDeDonneesChoisi));
    m_courant = infos.at(Courant).toFloat();
    m_tension = infos.at(Tension).toFloat();
    m_monophase = (bool)infos.at(Monophase).toInt();
    m_unitePA = (Unite)infos.at(UnitePA).toInt();
    m_unitePU = (Unite)infos.at(UnitePU).toInt();
    m_index = 0;

    actualiserCalculs();
}

Recepteur::Recepteur(float pUtileUnitaire, float rendement, int quantite, float cos, float ku, QString designation, TypeDeRecepteur typeDeRecepteur,QString nomDuParent)
{
    m_typeDeRecepteur = typeDeRecepteur;
    m_designation = designation;
    m_pUtileUnitaire = pUtileUnitaire;
    m_quantite = quantite;
    m_cosPhi = cos;
    m_rendement = rendement;
    m_ku = ku;
    m_ks = 1.0;
    m_tension = 231;
    m_courant = 0;
    m_designationDuParent = nomDuParent;

    m_pUtileEtRendInconnus = false;
    m_typeDeDonneesEntre = PUtileEtRendement;
    m_monophase = true;
    m_unitePA = W;
    m_unitePU = W;
    m_index = 0;

    actualiserCalculs();
}

Recepteur::Recepteur(float pAbsorbeeUnitaire, int quantite, float cos, float ku, QString designation, TypeDeRecepteur typeDeRecepteur, QString nomDuParent)
{
    m_typeDeRecepteur = typeDeRecepteur;
    m_designation = designation;
    m_pUtileUnitaire = 0;
    m_quantite = quantite;
    m_cosPhi = cos;
    m_rendement = 1;
    m_ku = ku;
    m_ks = 1.0;
    m_tension = 231;
    m_courant = 0;
    m_pAbsorbeeUnitaire = pAbsorbeeUnitaire;
    m_designationDuParent = nomDuParent;
    m_typeDeDonneesEntre = PuissanceAbsorbee;

    m_pUtileEtRendInconnus = true;
    m_monophase = true;
    m_unitePA = W;
    m_unitePU = W;
    m_index = 0;

    actualiserCalculs();
}

Recepteur::Recepteur(float courant, int tension, int quantite, float cos, float ku, QString designation, TypeDeRecepteur typeDeRecepteur, QString nomDuParent)
{
    m_typeDeRecepteur = typeDeRecepteur;
    m_designation = designation;
    m_pUtileUnitaire = 0;
    m_quantite = quantite;
    m_cosPhi = cos;
    m_rendement = 1;
    m_ku = ku;
    m_ks = 1.0;
    m_tension = tension;
    m_courant = courant;
    m_designationDuParent = nomDuParent;

    m_pUtileEtRendInconnus = true;
    m_typeDeDonneesEntre = CourantTension;
    m_monophase = true;
    m_unitePA = W;
    m_unitePU = W;
    m_index = 0;

    actualiserCalculs();
}

Recepteur::Recepteur(const Recepteur & r)
{
    m_typeDeRecepteur = r.m_typeDeRecepteur;
    m_designation = r.m_designation;
    m_pUtileUnitaire = r.m_pUtileUnitaire;
    m_quantite = r.m_quantite;
    m_cosPhi = r.m_cosPhi;
    m_rendement = r.m_rendement;
    m_ku = r.m_ku;
    m_ks = r.m_ks;
    m_pAbsorbeeUnitaire = r.m_pAbsorbeeUnitaire;
    m_pUtileEtRendInconnus = r.m_pUtileEtRendInconnus;
    m_designationDuParent = r.m_designationDuParent;
    m_typeDeDonneesEntre = r.m_typeDeDonneesEntre;
    m_courant = r.m_courant;
    m_tension = r.m_tension;
    m_monophase = r.m_monophase;
    m_unitePA = r.m_unitePA;
    m_unitePU = r.m_unitePU;
    m_index = r.m_index;
    m_description = r.m_description;

    actualiserCalculs();
}

QStringList Recepteur::infosDuRecepteur()const
{
    return recepteurToInfos(*this);
}

QString Recepteur::typeDeRecepteurToStr()const
{
    return Recepteur::typeToString(m_typeDeRecepteur);
}

Recepteur::TypeDeRecepteur Recepteur::typeDeRecepteur()const
{
    return m_typeDeRecepteur;
}

float Recepteur::pUtileUnitaire(Unite u) const
{
    if(u == KW)
        return pUtileUnitaireKW();
    else if(u == CH)
        return pUtileUnitaireCh();

    return pUtileUnitaire();
}

void Recepteur::setPUtileUnitaire(float pu)
{
    if(pu >= 0)
    {
        m_pUtileUnitaire = pu;
    }
}

void Recepteur::setPUtileUnitaireCh(float pu)
{
    if(pu >= 0)
    {
        m_pUtileUnitaire = UN_CHEVAL * pu;
    }
}

void Recepteur::setPUtileUnitaire(float pu, Unite u)
{
    if(pu >= 0)
    {
        if(u == KW)
            setPUtileUnitaireKW(pu);
        else if(u==W)
            setPUtileUnitaire(pu);
            else
                setPUtileUnitaireCh(pu);
    }
}

void Recepteur::setPUtileUnitaireKW(float pu)
{
    setPUtileUnitaire(pu * 1000);
}

void Recepteur::setQuantite(int qte)
{
    if(qte >= 0)
    {
        m_quantite = qte;
    }
}

void Recepteur::setCosPhi(float cos)
{
    if(cos > 0 && cos <=1)
    {
        m_cosPhi = cos;
    }
}

void Recepteur::setRendement(float r)
{
    if(r > 0 && r <=1)
    {
        m_rendement = r;
    }
}

void Recepteur::setKu(float ku)
{
    if(ku > 0 && ku <= 1)
    {
        m_ku = ku;
    }
}

void Recepteur::setKUParDefaut()
{
    m_ku = kuParDefaut();
}

void Recepteur::setCosPhiParDefaut()
{
    m_cosPhi = cosParDefaut();
}

void Recepteur::setRendementParDefaut()
{
    m_rendement = rendementParDefaut();
}

void Recepteur::setKs(float ks)
{
    if(ks > 0 && ks <= 1)
    {
        m_ks = ks;
    }
}

void Recepteur::setPAbsorbeeUnitaire(float pa)
{
    if(pa >= 0)
    {
        m_pAbsorbeeUnitaire = pa;
    }
}

void Recepteur::setPAbsorbeeUnitaire(float pa, Unite u)
{
    if(pa >= 0)
    {
        if(u == KW)
        {
            setPAbsorbeeUnitaireKW(pa);
        }else
        {
            setPAbsorbeeUnitaire(pa);
        }
    }
}

void Recepteur::setPAbsorbeeUnitaireKW(float pa)
{
    if(pa >=0 )
    {
        m_pAbsorbeeUnitaire = pa * 1000;
    }
}

void Recepteur::setTypeDeRecepteur(QString type)
{
    setTypeDeRecepteur(qStringToType(type));
}

void Recepteur::setTypeDeRecepteur(TypeDeRecepteur type)
{
    m_typeDeRecepteur = type;
}

float Recepteur::pAbsorbeeUnitaire(Unite u) const
{
    if(u == KW)
    {
        return pAbsorbeeUnitaireKW();
    }

    return pAbsorbeeUnitaire();
}

QStringList Recepteur::listeDesTypes()
{
    QStringList liste;

    liste << "Aucun type" << "Eclairage" << "Chauffage" << "Conditionneur d'air" << "Force motrice" << "Prise de courant";
    return liste;
}

QString Recepteur::typeToString(TypeDeRecepteur type)
{
    return listeDesTypes().at(type);
}

Recepteur::TypeDeRecepteur Recepteur::qStringToType(QString type)
{
    if(listeDesTypes().contains(type))
    {
        return ((TypeDeRecepteur)listeDesTypes().indexOf(type));
    }else
    {
        return AucunType;
    }
}

float Recepteur::calculerPAbsorbeeUnitaire()
{
    if(m_typeDeDonneesEntre == PUtileEtRendement)
    {
        return m_pUtileUnitaire / m_rendement;
    }else
    {
        if(m_typeDeDonneesEntre == CourantTension)
        {
            float facteur = 1.0;
            if(!m_monophase) facteur = sqrt(3);
            return facteur * m_courant * m_tension * m_cosPhi;
        }else
        {
            return m_pAbsorbeeUnitaire; // je ramène l'ancienne valeur
        }
    }
}

float Recepteur::PInstallee()const
{
    return m_pAbsorbeeUnitaire * m_quantite;
}

float Recepteur::_QInstallee()const
{
    float f_tan = tan(acos(m_cosPhi));

    return (PInstallee() * f_tan);
}

float Recepteur::PUtilisee()const
{
    return (PInstallee() * m_ku * m_ks);
}

float Recepteur::_QUtilisee()const
{
    return (_QInstallee() * m_ku * m_ks);
}

float Recepteur::PUtiliseeKW()const
{
    return PUtilisee() / 1000;
}

float Recepteur::_QUtiliseeKW()const
{
    return _QUtilisee() / 1000;
}

float Recepteur::PInstalleeKW()const
{
    return PInstallee()/1000;
}

float Recepteur::_QInstalleeKW()const
{
    return _QInstallee()/1000;
}

bool Recepteur::estEclairage()const
{
    return (m_typeDeRecepteur == Eclairage);
}

bool Recepteur::estConditionneurAir()const
{
    return (m_typeDeRecepteur == ConditionnementAir);
}

bool Recepteur::estChauffage()const
{
    return (m_typeDeRecepteur == Chauffage);
}

bool Recepteur::estPriseDeCourant()const
{
    return (m_typeDeRecepteur == PriseDeCourant);
}

bool Recepteur::estUnMoteur()const
{
    return (m_typeDeRecepteur == ForceMotrice);
}

float Recepteur::ksPriseDeCourant()const
{
    if(m_quantite > 0)
    {
        return (0.1 + 0.9/m_quantite);
    }

    return 1.0;
}

float Recepteur::ksParDefaut()const
{
    if(estPriseDeCourant())
    {
        return ksPriseDeCourant();
    }

    return 1.0;
}

float Recepteur::kuParDefaut()const
{
    if(estUnMoteur())
    {
        return 0.75;
    }else
    {
        if(estPriseDeCourant())
        {
            return 0.5;
        }
    }

    return 1.0;
}

float Recepteur::cosParDefaut()const
{
    if(estUnMoteur()||estConditionneurAir())
    {
        return 0.86;
    }

    return 1.0;
}

float Recepteur::rendementParDefaut()const
{
    if(estUnMoteur()||estConditionneurAir())
    {
        return 0.86;
    }

    return 1.0;
}

void Recepteur::actualiserCalculs()
{
    m_pAbsorbeeUnitaire =  calculerPAbsorbeeUnitaire();
}

QString Recepteur::description()const
{
    return m_description;
}

void Recepteur::setDescription(QString des)
{
    m_description = des;
}

QStringList Recepteur::recepteurToInfos(const Recepteur &r)
{
    QStringList infos;
    infos << r.designation()
          << QString::number(r.pUtileUnitaire())
          << QString::number(r.rendement())
          << QString::number(r.courant())
          << QString::number(r.tension())
          << QString::number(r.quantite())
          << QString::number(r.cosPhi())
          << QString::number(r.pAbsorbeeUnitaire())
          << QString::number(r.ks())
          << QString::number(r.ku())
          << QString::number(r.PInstalleeKW())
          << QString::number(r._QInstalleeKW())
          << QString::number(r.PUtiliseeKW())
          << QString::number(r._QUtiliseeKW())
          << r.designationDuParent()
          << r.typeDeRecepteurToStr()
          << r.typeDeDonneeEntreeStr()
          << QString::number(r.monophase())
          << QString::number((int)r.unitePU())
          << QString::number((int)r.unitePA());

    return infos;
}

QString Recepteur::typeDeDonneeEntreeStr()const
{
    return typeDeDonneesToString(m_typeDeDonneesEntre);
}

void Recepteur::setTypeDeDonneesEntre(TypeDeDonneesAEntrer type)
{
    m_typeDeDonneesEntre = type;
}

void Recepteur::setTypeDeDonneesEntre(QString type)
{
    setTypeDeDonneesEntre(qStringToTypeDeDonnees(type));
}

void Recepteur::setCourant(float courant)
{
    if(courant >= 0)
    {
        m_courant = courant;
    }
}

void Recepteur::setTension(float tension)
{
    if(tension >= 0)
    {
        m_tension = tension;
    }
}

Recepteur Recepteur::infosToRecepteur(const QStringList &infos)
{
    Recepteur::TypeDeDonneesAEntrer type = qStringToTypeDeDonnees(infos.at(TypeDeDonneesChoisi));

    Recepteur r;
    r.setTypeDeDonneesEntre(type);
    r.setDesignation(infos.at(Designation));
    r.setCosPhi(infos.at(CosPhi).toFloat());
    r.setKs(infos.at(Ks).toFloat());  // toujours à  1
    r.setKu(infos.at(Ku).toFloat());
    r.setQuantite(infos.at(Quantite).toInt());
    r.setUnitePA((Unite)infos.at(UnitePA).toInt());
    r.setUnitePU((Unite)infos.at(UnitePU).toInt());
    r.setPAbsorbeeUnitaire(infos.at(Pasborbee).toFloat(), r.unitePA());
    r.setPUtileUnitaire(infos.at(Putile).toFloat(), r.unitePU());
    r.setRendement(infos.at(Rendement).toFloat());
    r.setDesignationDuParent(infos.at(TableauEnAmont));
    r.setTypeDeRecepteur(infos.at(TypeDuRecepteur));
    r.setCourant(infos.at(Courant).toFloat());
    r.setTension(infos.at(Tension).toFloat());
    r.m_monophase = (bool)infos.at(Monophase).toInt();

    r.actualiserCalculs();

    return r;
}

Recepteur::TypeDeDonneesAEntrer Recepteur::qStringToTypeDeDonnees(QString type)
{
    QStringList l; l << listeDeTypeDeDonnees();

    for(int i = 0; i < l.count(); i++)
    {
        if(type == l.at(i))
        {
            return (TypeDeDonneesAEntrer)i;
        }
    }

    return AucunTypeDeDonnees;
}

QString Recepteur::typeDeDonneesToString(TypeDeDonneesAEntrer type)
{
    return listeDeTypeDeDonnees().at(type);
}

QStringList Recepteur::listeDeTypeDeDonnees()
{
    QStringList l;
    l << "aucun type de données"
      << "puissance utile et rendement"
      << "courant et tension"
      << "puissance absorbée";

    return l;
}

bool Recepteur::infosRecepteurValides(QStringList infos)
{
    // vérifier la taille de la liste
    return (infos.count() == Recepteur::recepteurToInfos(Recepteur()).count());
}

Recepteur::~Recepteur()
{

}
