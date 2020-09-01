#include "Tableau.h"

bool Tableau::operator ==(const Tableau & t)const
{
    return(m_designation == t.m_designation);
}

Tableau::Tableau()
{
    m_typeDeTableau = AucunType;
    m_designation = QString();
    m_ks = ksParDefaut();
    m_designationDuParent = AUCUN_TABLEAU_EN_AMONT;
    m_index = 0;
}

Tableau::Tableau(const QStringList &infos)
{
    m_typeDeTableau = Tableau::qStringToType(infos.at(Tableau::TypeDuTableau));
    m_designation = infos.at(Tableau::Designation);
    m_ks = infos.at(Tableau::Ks).toFloat();
    m_designationDuParent = infos.at(Tableau::TableauEnAmont);
    m_index = 0;
}

Tableau::Tableau(TypeDeTableau type, float ks, QString designation, QString nomDuParent)
{
    m_designation = designation;
    m_designationDuParent = nomDuParent;
    m_typeDeTableau = type;
    m_ks = ks;
    m_index = 0;
}

Tableau::Tableau(const Tableau &t)
{
   m_designation = t.m_designation;
   m_ks = t.m_ks;
   m_typeDeTableau = t.m_typeDeTableau;
   m_designationDuParent = t.m_designationDuParent;

   m_tableauxFils.clear();
   m_recepteursFils.clear();
   m_locauxFils.clear();

   m_tableauxFils << t.m_tableauxFils;
   m_recepteursFils << t.m_recepteursFils;
   m_locauxFils << t.m_locauxFils;
   m_index = t.m_index;
   m_description = t.m_description;
}

QStringList Tableau::infosDuTableau()const
{
    return tableauToInfos(*this);
}

QString Tableau::typeDeTableauStr()const
{
    return typeToString(m_typeDeTableau);
}

void Tableau::setTypeDeTableau(QString type)
{
    m_typeDeTableau = qStringToType(type);
}

void Tableau::setDesignationDuParent(const QString & designation)
{
    m_designationDuParent = designation;
}

void Tableau::setTableauxFils(const QList<Tableau> &lt)
{
    m_tableauxFils.clear();
    ajouterDesTableaux(lt);
}

void Tableau::setRecepteursFils(const QList<Recepteur> &lr)
{
    m_recepteursFils.clear();
    ajouterDesRecepteurs(lr);
}

void Tableau::setLocauxFils(const QList<Local> &ll)
{
    m_locauxFils.clear();
    ajouterDesLocaux(ll);
}

void Tableau::setDesignation(QString nom)
{
    m_designation = nom;

    /* actualiser cette désignation dans les fils */
    QList<Recepteur> lr;
    QList<Tableau> lt;

    lr << m_recepteursFils; lt << m_tableauxFils;

    setRecepteursFils(lr);
    setTableauxFils(lt);
}

void Tableau::setKs(float ks)
{
    if(ks > 0 && ks <= 1)
    {
         m_ks = ks;
    }
}

float Tableau::PInstallee()const
{
    return  pPInstallee(m_recepteursFils) + pPInstallee(m_tableauxFils)
            + pPInstallee(m_locauxFils);
}

float Tableau::_QInstallee()const
{
    return  pQInstallee(m_recepteursFils) + pQInstallee(m_tableauxFils)
            + pPInstallee(m_locauxFils);
}

float Tableau::PInstalleeKW()const
{
    return PInstallee()/1000;
}

float Tableau::_QInstalleeKW()const
{
    return _QInstallee() / 1000;
}

float Tableau::PUtilisee()const
{
    return  pPUtilisee(m_recepteursFils, m_ks) + pPUtilisee(m_tableauxFils, m_ks)
            + pPUtilisee(m_locauxFils, m_ks);
}

float Tableau::_QUtilisee()const
{
    return  pQUtilisee(m_recepteursFils, m_ks) + pQUtilisee(m_tableauxFils, m_ks)
            + pQUtilisee(m_locauxFils, m_ks);
}

float Tableau::PUtiliseeKW()const
{
    return PUtilisee() / 1000;
}

float Tableau::_QUtiliseeKW()const
{
    return _QUtilisee() / 1000;
}

float Tableau::cosPhi()const
{
    float SUtilisee = sqrt(PUtilisee() * PUtilisee() + _QUtilisee() * _QUtilisee());

    if(SUtilisee != 0)
    {
        return PUtilisee()/SUtilisee;
    }

    return 1.0;
}


QString Tableau::typeToString(TypeDeTableau type)
{
    return listeDeTypeTableau().at(type);
}

Tableau::TypeDeTableau Tableau::qStringToType(QString type)
{
    if(listeDeTypeTableau().contains(type))
    {
        return ((TypeDeTableau)listeDeTypeTableau().indexOf(type));
    }else
    {
        return AucunType;
    }
}

QStringList Tableau::listeDeTypeTableau()
{
    QStringList liste;
    liste << "Aucun type" << "TGBT" << "Tableau secondaire" << "Tableau divisionnaire" << "Terminal";
    return liste;
}

QList<Recepteur >::iterator Tableau::recepteur(const QString &designation, bool inclureSousTableaux)
{
    if(!m_recepteursFils.isEmpty())
    {
        QList<Recepteur>::iterator it = m_recepteursFils.begin();

        while(it != m_recepteursFils.end())
        {
            if((*it).designation() == designation)
            {
                return it;
            }
            it++;
        }
    }

    // pere ne possede pas le recepteur recherché
    // rechercher dans ses tableaux fils si permis
    if(inclureSousTableaux)
    {
        // cherchons dans les tableaux fils
        QList<Tableau>::iterator it = m_tableauxFils.begin();

        while(it != m_tableauxFils.end())
        {
            QList<Recepteur>::iterator it1 = (*it).recepteur(designation, inclureSousTableaux);
            if(it1 != (*it).m_recepteursFils.end())
            {
                return it1;
            }
            it++;
        }
    }

    // le recepteur n'existe pas dans la descendance de ce père
    return m_recepteursFils.end();
}

bool Tableau::possedeRecepteurFils(const QString &designation, bool inclureSousTableaux)
{
    if(recepteur(designation, inclureSousTableaux) != m_recepteursFils.end())
    {
        return true;
    }else
    {
        return false;
    }
}

Recepteur & Tableau::recepteurFils(const QString &designation, bool inclureSousTableaux)
{
    return *recepteur(designation, inclureSousTableaux);
}

QList<Tableau>::iterator Tableau::tableau(const QString &designation, bool inclureSousTableaux)
{
    // on suppose que le tableau recherché est unique et seul dans le tableau pere
    // pere possede des sous tableaux
    QList<Tableau>::iterator it = m_tableauxFils.begin();

    while(it != m_tableauxFils.end())
    {
        if((*it).m_designation == designation)
        {
            return it;
        }

        if(inclureSousTableaux)
        {
            // rechercher dans ce cas dans ses sous-tableaux
            QString nom = designation;
            QList<Tableau>::iterator it1 = (*it).tableau(nom, true);
            if(it1 != (*it).m_tableauxFils.end())
            {
                return it1;
            }
        }

        it++;
    }  

    return m_tableauxFils.end();
}

bool Tableau::possedeTableauFils(const QString &designation, bool inclureSousTableaux)
{
    QString nom = designation;

    if(tableau(nom, inclureSousTableaux) != m_tableauxFils.end())
    {
        return true;
    }else
    {
        return false;
    }
}

Tableau & Tableau::pereDe(const QString & fils)
{
    QString nomDuPere;

    if(possedeTableauFils(fils,true))
    {
        nomDuPere = tableauFils(fils, true).designationDuParent();
    }else
    {
        nomDuPere = recepteurFils(fils, true).designationDuParent();
    }

    if(nomDuPere == m_designation)
    {
        return *this;
    }else
    {
        return tableauFils(nomDuPere,true);
    }
}

bool Tableau::estFilsDe(const Tableau &t)const
{
    return t.designation() == m_designationDuParent;
}

bool Tableau::estPere()const
{
    return !(m_tableauxFils.isEmpty() && m_recepteursFils.isEmpty());
}

bool Tableau::estPereDe(const Recepteur &r)const
{
    return m_recepteursFils.contains(r);
}

bool Tableau::estPereDe(const Local &l) const
{
    return m_locauxFils.contains(l);
}

bool Tableau::estPereDe(const Tableau &t)const
{
    return m_tableauxFils.contains(t);
}

bool Tableau::estFilsDe(const QString &pere)const
{
    return pere == m_designationDuParent;
}

bool Tableau::estPereDe(const QString &fils)const
{
    Tableau t; t.setDesignation(fils); Recepteur r; r.setDesignation(fils); Local l;l.setDesignation(fils);
    return estPereDe(t)||estPereDe(r)||estPereDe(l);
}

Tableau & Tableau::tableauFils(const QString &designation, bool inclureSousTableaux)
{
    QString nom = designation;
    return *tableau(nom, inclureSousTableaux);
}

bool Tableau::possedeLocalFils(const QString &designation, bool inclureSousTableaux)
{
    if(local(designation, inclureSousTableaux) != m_locauxFils.end())
    {
        return true;
    }else
    {
        return false;
    }
}

QList<Local>::iterator Tableau::local(const QString &designation, bool inclureSousTableaux)
{
    if(!m_locauxFils.isEmpty())
    {
        QList<Local>::iterator it = m_locauxFils.begin();

        while(it != m_locauxFils.end())
        {
            if((*it).designation() == designation)
            {
                return it;
            }
            it++;
        }
    }

    // pere ne possede pas le recepteur recherché
    // rechercher dans ses tableaux fils si permis
    if(inclureSousTableaux)
    {
        // cherchons dans les tableaux fils
        QList<Tableau>::iterator it = m_tableauxFils.begin();

        while(it != m_tableauxFils.end())
        {
            QList<Local>::iterator it1 = (*it).local(designation, inclureSousTableaux);
            if(it1 != (*it).m_locauxFils.end())
            {
                return it1;
            }
            it++;
        }
    }

    // le recepteur n'existe pas dans la descendance de ce père
    return m_locauxFils.end();
}

Local & Tableau::localFils(const QString &designation, bool inclureSousTableaux)
{
    return *local(designation, inclureSousTableaux);
}

bool Tableau::ajouterUnTableau(const Tableau & tableau)
{
    if(!m_tableauxFils.contains(tableau))
    {
        Tableau t(tableau);
        t.setDesignationDuParent(m_designation);
        m_tableauxFils << t;
        m_ks = ksParDefaut(); // c'est le ks par défaut

        QList<Tableau> lt;
        lt << TSFils() << TDFils() << terminauxFils();

        m_tableauxFils.clear();
        m_tableauxFils << lt;
        return true;
    }

    return false;
}

void Tableau::ajouterDesRecepteurs(const QList<Recepteur> &lr)
{
    for(int i = 0; i < lr.count(); i++)
    {
        ajouterUnRecepteur(lr.at(i));
    }
}

void Tableau::ajouterDesLocaux(const QList<Local> &ll)
{
    for(int i = 0; i < ll.count(); i++)
    {
        ajouterUnLocal(ll.at(i));
    }
}

void Tableau::ajouterDesTableaux(const QList<Tableau> &lt)
{
    for(int i = 0; i < lt.count(); i++)
    {
        ajouterUnTableau(lt.at(i));
    }
}

void Tableau::remplacerUnTableau(const QString &ancien, const Tableau &nouveauTableau)
{
    Tableau t;
    t.setDesignation(ancien);

    if(m_tableauxFils.contains(t))
    {
        m_tableauxFils.replace(m_tableauxFils.indexOf(t), nouveauTableau);
        m_ks = ksParDefaut();
    }

    rangerParOrdreCroissant(m_tableauxFils);
}

void Tableau::remplacerUnLocal(const QString &ancien, const Local &nouveauLocal)
{
    Local l;
    l.setDesignation(ancien);

    if(m_locauxFils.contains(l))
    {
        m_locauxFils.replace(m_locauxFils.indexOf(l), nouveauLocal);
        m_ks = ksParDefaut();
    }

    rangerParOrdreCroissant(m_locauxFils);
}

void Tableau::remplacerUnRecepteur(const QString &ancien, const Recepteur &nouveauRecepteur)
{
    Recepteur r;
    r.setDesignation(ancien);

    if(m_recepteursFils.contains(r))
    {
        m_recepteursFils.replace(m_recepteursFils.indexOf(r), nouveauRecepteur);
        m_ks = ksParDefaut();
    }

    rangerParOrdreCroissant(m_recepteursFils);
}

bool Tableau::supprimerUnRecepteur(const QString &nom)
{
    Recepteur r;
    r.setDesignation(nom);
    return m_recepteursFils.removeOne(r);
}

bool Tableau::supprimerUnLocal(const QString &nom)
{
    Local l;
    l.setDesignation(nom);
    return m_locauxFils.removeOne(l);
}

bool Tableau::supprimerUnTableau(const QString &nom)
{
    Tableau t;
    t.setDesignation(nom);
    return m_tableauxFils.removeOne(t);
}

void Tableau::supprimerAllRecepteursFils()
{
    m_recepteursFils.clear();
}

void Tableau::supprimerAllLocauxFils()
{
    m_locauxFils.clear();
}

void Tableau::supprimerAllTableauxFils()
{
    m_tableauxFils.clear();
}

void Tableau::supprimerAllFils()
{
    supprimerAllRecepteursFils();
    supprimerAllTableauxFils();
}

bool Tableau::ajouterUnRecepteur(const Recepteur & recepteur)
{
    if(!m_recepteursFils.contains(recepteur))
    {
        Recepteur r(recepteur);
        r.setDesignationDuParent(m_designation);
        m_recepteursFils << r;
        m_ks = ksParDefaut(); // c'est le ks par défaut
        rangerParOrdreCroissant(m_recepteursFils);
        return true;
    }

    return false;
}

bool Tableau::ajouterUnLocal(const Local &l)
{
    if(!m_locauxFils.contains(l))
    {
        Local l_m(l);
        l_m.setDesignationDuParent(m_designation);
        m_locauxFils << l_m;
        m_ks = ksParDefaut(); // c'est le ks par défaut
        rangerParOrdreCroissant(m_locauxFils);
        return true;
    }

    return false;
}

QStringList Tableau::tableauToInfos(const Tableau &t)
{
    QStringList l;

    l << t.designation()
      << QString::number(t.ks(), 'f', 2)
      << QString::number(t.cosPhi(), 'f', 2)
      << QString::number(t.PInstalleeKW(), 'f', 2)
      << QString::number(t._QInstalleeKW(), 'f', 2)
      << QString::number(t.PUtiliseeKW(), 'f', 2)
      << QString::number(t._QUtiliseeKW(), 'f', 2)
      << t.designationDuParent()
      << t.typeDeTableauStr();

    return l;
}

Tableau Tableau::infosToTableau(const QStringList &infos)
{
    Tableau::TypeDeTableau type = Tableau::qStringToType(infos.at(TypeDuTableau));
    Tableau t(type,
              infos.at(Ks).toFloat(),
              infos.at(Designation),
              infos.at(TableauEnAmont));

    return t;
}

QList<Tableau> Tableau::tableauxDeDescendance()const
{
    QList<Tableau> lt;
    for(int i = 0; i < m_tableauxFils.count(); i++)
    {
        Tableau t = m_tableauxFils.at(i);

        lt << t;
        lt << t.tableauxDeDescendance();
    }

    return lt;
}

QList<Recepteur> Tableau::recepteursDeDescendance()const
{
    QList<Recepteur> lr;
    lr << m_recepteursFils;

    for(int i = 0; i < m_tableauxFils.count(); i++)
    {
        Tableau t = m_tableauxFils.at(i);
        lr << t.recepteursDeDescendance();
    }

    return lr;
}

QList<Local> Tableau::locauxDeDescendance()const
{
    QList<Local> ll;
    ll << m_locauxFils;

    for(int i = 0; i < m_tableauxFils.count(); i++)
    {
        Tableau t = m_tableauxFils.at(i);
        ll << t.locauxDeDescendance();
    }

    return ll;
}

QList<Tableau> Tableau::debrancherTableauxFils()
{
    QList<Tableau> lt;
    for(int i = 0; i < m_tableauxFils.count(); i++)
    {
        Tableau t = m_tableauxFils.at(i);
        t.setDesignationDuParent(AUCUN_TABLEAU_EN_AMONT);
        lt << t;
    }

    m_tableauxFils.clear();
    return lt;
}

QList<Recepteur> Tableau::debrancherRecepteursFils()
{
    QList<Recepteur> lr;

    for(int i = 0; i < m_recepteursFils.count(); i++)
    {
        Recepteur r = m_recepteursFils.at(i);
        r.setDesignationDuParent(AUCUN_TABLEAU_EN_AMONT);
        lr << r;
    }

    m_recepteursFils.clear();
    return lr;
}

QList<Local> Tableau::debrancherLocauxFils()
{
    QList<Local> ll;

    for(int i = 0; i < m_locauxFils.count(); i++)
    {
        Local l = m_locauxFils.at(i);
        l.setDesignationDuParent(AUCUN_TABLEAU_EN_AMONT);
        ll << l;
    }

    m_locauxFils.clear();
    return ll;
}

int Tableau::niveau()const
{
    return niveau(*this);
}

int Tableau::niveau(const Tableau & t)
{
    int niv = 1; // niveau de t

    if(!t.tableauxFils().isEmpty())
    {
        QList<int> l_niv;
        for(int i = 0; i < t.tableauxFils().count(); i++)
        {
            l_niv << niv + niveau(t.tableauxFils().at(i));
        }

        if(!l_niv.isEmpty()) // on cherche le niveau maxi si l_niv pas vide
        {
            int max_niv = l_niv.at(0);
            for(int i = 1; i < l_niv.count(); i++)
            {
                if(max_niv < l_niv.at(i))
                {
                    max_niv = l_niv.at(i);
                }
            }
        }
    }else
    {
        niv++; // niveau des récepteurs et locaux
    }

    return niv;
}

QList<Tableau> Tableau::terminauxFils()const
{
    QList<Tableau> lt;

    for(int i = 0; i < m_tableauxFils.count(); i++)
    {
        if(m_tableauxFils.at(i).estUnTerminal())
        {
            lt << m_tableauxFils.at(i);
        }
    }

    rangerParOrdreCroissant(lt);
    return lt;
}

QList<Tableau> Tableau::TDFils()const
{
    QList<Tableau> lt;

    for(int i = 0; i < m_tableauxFils.count(); i++)
    {
        if(m_tableauxFils.at(i).estUnCD())
        {
            lt << m_tableauxFils.at(i);
        }
    }

    rangerParOrdreCroissant(lt);
    return lt;
}

QList<Tableau> Tableau::TSFils()const
{
    QList<Tableau> lt;

    for(int i = 0; i < m_tableauxFils.count(); i++)
    {
        if(m_tableauxFils.at(i).estUnTS())
        {
            lt << m_tableauxFils.at(i);
        }
    }

    rangerParOrdreCroissant(lt);
    return lt;
}

bool Tableau::typeUtilEstEclairage()const
{
    if((estUnCD()||estUnTerminal()))
    {
        for(int i = 0; i < m_tableauxFils.count(); i++)
        {
            if(!m_tableauxFils.at(i).typeUtilEstEclairage())
            {
                return false;
            }
        }

        for(int i = 0; i < m_recepteursFils.count(); i++)
        {
            if(!(m_recepteursFils.at(i).estEclairage()
                || m_recepteursFils.at(i).estChauffage()
                || m_recepteursFils.at(i).estConditionneurAir()))
            {
                return false;
            }
        }

        for(int i = 0; i < m_locauxFils.count(); i++)
        {
            if(!m_locauxFils.at(i).typeUtilEstEclairage())
            {
                return false;
            }
        }

        return true;
    }

    return false;
}

bool Tableau::typeUtilEstForceMotrice()const
{
    if((estUnCD()||estUnTerminal()))
    {
        for(int i = 0; i < m_tableauxFils.count(); i++)
        {
            if(!m_tableauxFils.at(i).typeUtilEstForceMotrice())
            {
                return false;
            }
        }

        for(int i = 0; i < m_recepteursFils.count(); i++)
        {
            if(!m_recepteursFils.at(i).estUnMoteur())
            {
                return false;
            }
        }

        for(int i = 0; i < m_locauxFils.count(); i++)
        {
            if(!m_locauxFils.at(i).typeUtilEstForceMotrice())
            {
                return false;
            }
        }

        return true;
    }

    return false;
}

bool Tableau::typeUtilEstPriseDeCourant()const
{
    if((estUnCD()||estUnTerminal()) && m_tableauxFils.isEmpty() && m_locauxFils.isEmpty())
    {
        for(int i = 0; i < m_recepteursFils.count();i++)
        {
            if(!m_recepteursFils.at(i).estPriseDeCourant())
            {
                return false;
            }
        }

        return true;
    }

    return false;
}

bool Tableau::typeUtilEstInconnu()const
{
    if(estUnCD()||estUnTerminal())
    {
        if(!(typeUtilEstEclairage()
            ||typeUtilEstForceMotrice()
            ||typeUtilEstPriseDeCourant()))
            {
                return true;
            }
        return false;
    }

    return true;
}

float Tableau::ksParDefaut()const
{
    if(nbDeCircuit() == 0)
        return 1;

    if(typeUtilEstInconnu())
    {
        int nb = nbDeCircuit();
        if(nb == 1)
            return 1;
        if(nb>= 2 && nb <=3)
        {
            return 0.9;
        }else
        {
            if(nb >= 4 && nb <=5)
            {
                return 0.8;
            }else
            {
                if(nb >= 6 && nb <= 9)
                {
                    return 0.7;
                }else
                {
                    return 0.6;
                }
            }
        }
    }else
    {
        if(typeUtilEstEclairage())
        {
            return 1;
        }else
        {
            if(typeUtilEstForceMotrice())
            {
                return 0.8;
            }else
            {
                // alors c'est un terminal qui possède un ou plusieurs groupes de récepteurs
                return (0.1 + 0.9/nbDeCircuit());
            }
        }
    }
}

int Tableau::nbDeCircuit()const
{
    int nb = 0;
    for(int i = 0; i < m_recepteursFils.count(); i++)
    {
        nb += m_recepteursFils.at(i).quantite();
    }

    nb += m_locauxFils.count() + m_tableauxFils.count();

    return nb;
}

QString Tableau::description()const
{
    return m_description;
}

void Tableau::setDescription(QString des)
{
    m_description = des;
}

bool Tableau::infosTableauValides(QStringList infos)
{
    // vérifier la taille de la liste
    return (infos.count() == Tableau::tableauToInfos(Tableau()).count());
}

