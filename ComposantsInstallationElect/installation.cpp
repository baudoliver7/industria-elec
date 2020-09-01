#include "installation.h"

Installation::Installation(): Tableau()
{
    m_nom = "Installation";
    m_transformateur = new Transformateur(1.2, 40, 0, 0.86);
    m_typeDeTableau = Tableau::TGBT;
    m_ks = 1.0;
    m_designation = "TGBT";
    m_designationDuParent = "Aucun parent";
}

Installation::Installation(const QString &nom, const Tableau &t_TGBT):
        Tableau(t_TGBT),m_nom(nom)
{
    m_transformateur = new Transformateur(1.2, 40, 0, 0.86);
}

Installation::Installation(const Installation &i):
        Tableau(i)
{
    m_nom = i.m_nom;
    m_tableauxDeconnectes = i.m_tableauxDeconnectes;
    m_recepteursDeconnectes = i.m_recepteursDeconnectes;

    m_transformateur = new Transformateur(*i.m_transformateur);
}

Installation::~Installation()
{
    delete m_transformateur;
}

QStringList Installation::infosDeInstallation()const
{
    QStringList donnees;

    // transfo d'abord
    donnees << MOTCLE_TRANSFO
            << m_transformateur->infosDuTransfo()
            << MOTCLE_TRANSFO;

    // Tableau ensuite
    donnees << MOTCLE_TABLEAU // TGBT
            << this->infosDuTableau()
            << MOTCLE_TABLEAU;

    QList<Tableau> l_ts;
    l_ts << tableauxSecondairesConnectes();
    for(int i = 0; i < l_ts.count(); i++)
    {
        donnees << MOTCLE_TABLEAU
                << l_ts.at(i).infosDuTableau()
                << MOTCLE_TABLEAU;
    }

    QList<Tableau> l_td;
    l_td << coffretsDivisionnairesConnectes();
    for(int i = 0; i < l_td.count(); i++)
    {
        donnees << MOTCLE_TABLEAU
                << l_td.at(i).infosDuTableau()
                << MOTCLE_TABLEAU;
    }

    QList<Tableau> l_ter;
    l_ter << terminauxConnectes();
    for(int i = 0; i < l_ter.count(); i++)
    {
        donnees << MOTCLE_TABLEAU
                << l_ter.at(i).infosDuTableau()
                << MOTCLE_TABLEAU;
    }

    // les locaux ensuite
    QList<Local> l_lo;
    l_lo << locaux(true);
    for(int i = 0; i < l_lo.count(); i++)
    {
        donnees << MOTCLE_LOCAL
                << l_lo.at(i).infosDuLocal()
                << MOTCLE_LOCAL;
    }

    // enfin les récepteurs
    QList<Recepteur> l_re;
    l_re << recepteurs(true);
    for(int i = 0; i < l_re.count(); i++)
    {
        donnees << MOTCLE_RECEPTEUR
                << l_re.at(i).infosDuRecepteur()
                << MOTCLE_RECEPTEUR;
    }

    return donnees;
}

int Installation::nbDeNiveau()
{
    return (this->niveau() + 1); // +1 pour le transfo
}

void Installation::setDesignationTGBT(const QString & designation)
{
    setDesignation(designation);
}

void Installation::installerUnRecepteur(const Recepteur &r, QString nomDuPere)
{
    if(possedeUnTableau(nomDuPere))
    {
        tableauInstalle(nomDuPere).ajouterUnRecepteur(r); // tjrs vrai;
    }else
    {
        Recepteur r1(r); r1.setDesignationDuParent(AUCUN_TABLEAU_EN_AMONT);
        m_recepteursDeconnectes << r1;  // on le stocke dans l'installation
    }
}

void Installation::installerUnTableau(const Tableau &t, QString nomDuPere)
{
    if(possedeUnTableau(nomDuPere))
    {
        tableauInstalle(nomDuPere).ajouterUnTableau(t); // tjrs vrai;
    }else
    {
        Tableau t1(t);
        t1.setDesignationDuParent(AUCUN_TABLEAU_EN_AMONT);
        m_tableauxDeconnectes << t1;  // on le stocke dans l'installation
    }
}

void Installation::installerUnLocal(const Local &l, QString nomDuPere)
{
    if(possedeUnTableau(nomDuPere))
    {
        tableauInstalle(nomDuPere).ajouterUnLocal(l); // tjrs vrai;
    }else
    {
        Local l1(l); l1.setDesignationDuParent(AUCUN_TABLEAU_EN_AMONT);
        m_locauxDeconnectes << l1;  // on le stocke dans l'installation
    }
}

bool Installation::brancherUnRecepteur(const QString &nomDuRecepteur, const QString &nomDuPere)
{
    if(possedeUnTableau(nomDuPere) && possedeUnRecepteurDeconnecte(nomDuRecepteur))
    {
        Recepteur r; r.setDesignation(nomDuRecepteur);

        /* rétirer le recepteur des recepteurs déconnectés */
        r = m_recepteursDeconnectes.takeAt(m_recepteursDeconnectes.indexOf(r));

        tableauInstalle(nomDuPere).ajouterUnRecepteur(r); // tjrs vrai
        return true;
    }

    return false;
}

bool Installation::brancherUnTableau(const QString &nomDuFils, const QString &nomDuPere)
{
    if(possedeUnTableau(nomDuPere) && possedeUnTableauDeconnecte(nomDuFils))
    {
        Tableau t; t.setDesignation(nomDuFils);

        /* rétirer le tableau des tableaux déconnectés */
        t = m_tableauxDeconnectes.takeAt(m_tableauxDeconnectes.indexOf(t));

        tableauInstalle(nomDuPere).ajouterUnTableau(t); // tjrs vrai
        return true;
    }

    return false;
}

bool Installation::brancherUnLocal(const QString &nomDuFils, const QString &nomDuPere)
{
    if(possedeUnTableau(nomDuPere) && possedeUnLocalDeconnecte(nomDuFils))
    {
        Local r; r.setDesignation(nomDuFils);

        /* rétirer le local des locaux déconnectés */
        r = m_locauxDeconnectes.takeAt(m_locauxDeconnectes.indexOf(r));

        tableauInstalle(nomDuPere).ajouterUnLocal(r); // tjrs vrai
        return true;
    }

    return false;
}

bool Installation::brancherUnComposant(const QString &nomDuFils, const QString &nomDuPere)
{
    if(!brancherUnRecepteur(nomDuFils, nomDuPere))
    {
        if(!brancherUnLocal(nomDuFils, nomDuPere))
        {
            return brancherUnTableau(nomDuFils, nomDuPere);
        }
    }

    return true;
}

bool Installation::debrancherUnRecepteur(const QString &nom)
{
    if(possedeUnRecepteurConnecte(nom))
    {
        Recepteur r = recepteurConnecte(nom);

        tableauInstalle(r.designationDuParent()).supprimerUnRecepteur(r.designation());

        r.setDesignationDuParent(AUCUN_TABLEAU_EN_AMONT);
        m_recepteursDeconnectes << r;
        return true;
    }

    return false; // récepteur non débranché
}

bool Installation::debrancherUnLocal(const QString & nom)
{
    if(possedeUnLocalConnecte(nom))
    {
        Local r = localConnecte(nom);

        tableauInstalle(r.designationDuParent()).supprimerUnLocal(r.designation());
        r.setDesignationDuParent(AUCUN_TABLEAU_EN_AMONT);
        m_locauxDeconnectes << r;
        return true;
    }

    return false; // local non débranché
}

bool Installation::debrancherUnTableau(const QString &nom)
{
    if(possedeUnTableauConnecte(nom))
    {
        Tableau t = tableauConnecte(nom);

        tableauInstalle(t.designationDuParent()).supprimerUnTableau(t.designation());
        t.setDesignationDuParent(AUCUN_TABLEAU_EN_AMONT);
        m_tableauxDeconnectes << t;
        return true;
    }

    return false; // tableau non débranché
}

bool Installation::debrancherUnComposant(const QString &nom)
{
    if(!debrancherUnRecepteur(nom))
    {
        if(!debrancherUnLocal(nom))
        {
            return debrancherUnTableau(nom);
        }
    }

    return true;
}

bool Installation::remplacerUnTableau(const QString &ancien, const Tableau &nouveauTableau)
{
    if(possedeUnTableau(ancien))
    { 
        if(ancien == m_designation) // c'est le tgbt
        {
            // modifications possibles
            setDesignationTGBT(nouveauTableau.designation());
            m_ks = nouveauTableau.ks();
        }else
        {
            Tableau t = tableauInstalle(ancien);

            QString pere = t.designationDuParent(); // brancher sur l'ancien pere

            tableauInstalle(pere).remplacerUnTableau(ancien, nouveauTableau);
        }
        return true;
    }

    return false; // n'est pas remplacé
}

bool Installation::remplacerUnRecepteur(const QString &ancien, const Recepteur &nouveauRecepteur)
{
    if(possedeUnRecepteur(ancien))
    {
        Recepteur & r = recepteurInstalle(ancien); // r peut être modifié directement

        QString pere = r.designationDuParent();
        tableauInstalle(pere).remplacerUnRecepteur(ancien, nouveauRecepteur);
        return true;
    }

    return false;
}

bool Installation::remplacerUnLocal(const QString &ancien, const Local &nouveauLocal)
{
    if(possedeUnLocal(ancien))
    {
        Local & r = localInstalle(ancien); // r peut être modifié directement

        QString pere = r.designationDuParent();
        tableauInstalle(pere).remplacerUnLocal(ancien, nouveauLocal);
        return true;
    }

    return false;
}

bool Installation::possedeUnTableauConnecte(const QString & nomDuTableau)
{
    QString nom = nomDuTableau;
    return (nom == m_designation)||Tableau::possedeTableauFils(nom, true); // le TBGT est concernÃ©
}

bool Installation::possedeUnRecepteurConnecte(const QString &nomDuRecepteur)
{
    return Tableau::possedeRecepteurFils(nomDuRecepteur, true);
}

bool Installation::possedeUnLocalConnecte(const QString &nomDuLocal)
{
    return Tableau::possedeLocalFils(nomDuLocal, true);
}

bool Installation::possedeUnTableau(const QString &nomDuTableau)
{
    QString nom = nomDuTableau;
    return possedeUnTableauConnecte(nom)||possedeUnTableauDeconnecte(nom);
}

bool Installation::possedeUnComposant(const QString &cpt)
{
    return (possedeUnTableau(cpt)
            || possedeUnRecepteur(cpt)
            || possedeUnLocal(cpt));
}

bool Installation::possedeUnComposantConnecte(const QString &cpt)
{
    return (possedeUnTableauConnecte(cpt)
            || possedeUnRecepteurConnecte(cpt)
            || possedeUnLocalConnecte(cpt));
}

bool Installation::possedeUnRecepteur(const QString &nomDuRecepteur)
{
    return possedeUnRecepteurConnecte(nomDuRecepteur)||possedeUnRecepteurDeconnecte(nomDuRecepteur);
}

bool Installation::possedeUnLocal(const QString & nomDuLocal)
{
    return possedeUnLocalConnecte(nomDuLocal)||possedeUnLocalDeconnecte(nomDuLocal);
}

Tableau & Installation::tableauConnecte(const QString &nomDuTableau)
{
    if(nomDuTableau == m_designation)
    {
        // renvoyer le TGBT
        return *this;
    }else
    {
        // renvoyer l'un de ses fils
        QString nom = nomDuTableau;
        return tableauFils(nom, true);
    }
}

Recepteur & Installation::recepteurConnecte(const QString &nomDuRecepteur)
{
    return recepteurFils(nomDuRecepteur, true);
}

Local & Installation::localConnecte(const QString &nomDuLocal)
{
    return localFils(nomDuLocal, true);
}

Local & Installation::localInstalle(const QString &nomDuLocal)
{
    if(possedeUnLocalConnecte(nomDuLocal))
    {
        return localConnecte(nomDuLocal);
    }else
    {
        return localDeconnecte(nomDuLocal);
    }
}

Tableau & Installation::tableauInstalle(const QString &nomDuTableau)
{
    QString nom = nomDuTableau;
    if(possedeUnTableauConnecte(nom))
    {
        return tableauConnecte(nom);
    }else
    {
        // chercher dans les tableaux non connectés à  l'installation
        return tableauDeconnecte(nom);
    }
}

Recepteur & Installation::recepteurInstalle(const QString &nomDuRecepteur)
{
    if(possedeUnRecepteurConnecte(nomDuRecepteur))
    {
        return recepteurConnecte(nomDuRecepteur);
    }else
    {
        return recepteurDeconnecte(nomDuRecepteur);
    }
}

Tableau & Installation::tableauDeconnecte(const QString &nomDuTableau)
{
    QList<Tableau>::iterator it = m_tableauxDeconnectes.begin();

    while(it != m_tableauxDeconnectes.end())
    {
        if((*it).designation() == nomDuTableau)
        {
            return (*it);
        }else
        {
            // chercher dans sa descendance
            QString nom = nomDuTableau;
            if((*it).possedeTableauFils(nom, true))
            {
                return (*it).tableauFils(nom, true);
            }
        }
        it++;
    }

    return *m_tableauxDeconnectes.end();
}

Recepteur & Installation::recepteurDeconnecte(const QString &nomDuRecepteur)
{
    QList<Recepteur>::iterator itr = m_recepteursDeconnectes.begin();

    while(itr != m_recepteursDeconnectes.end())
    {
        if((*itr).designation() == nomDuRecepteur)
        {
            return (*itr);
        }
        itr++;
    }

    // chercher dans la descendante des tableaux non connectés
    QList<Tableau>::iterator it = m_tableauxDeconnectes.begin();

    while(it != m_tableauxDeconnectes.end())
    {
        if((*it).possedeRecepteurFils(nomDuRecepteur, true))
        {
            return (*it).recepteurFils(nomDuRecepteur, true);
        }
        it++;
    }

    return *m_recepteursDeconnectes.end(); // le recepteur n'est pas trouvé
}

Local & Installation::localDeconnecte(const QString &nomDuLocal)
{
    QList<Local>::iterator itr = m_locauxDeconnectes.begin();

    while(itr != m_locauxDeconnectes.end())
    {
        if((*itr).designation() == nomDuLocal)
        {
            return (*itr);
        }
        itr++;
    }

    // chercher dans la descendante des tableaux non connectés
    QList<Tableau>::iterator it = m_tableauxDeconnectes.begin();

    while(it != m_tableauxDeconnectes.end())
    {
        if((*it).possedeLocalFils(nomDuLocal, true))
        {
            return (*it).localFils(nomDuLocal, true);
        }
        it++;
    }

    return *m_locauxDeconnectes.end(); // le local n'est pas trouvé
}

bool Installation::possedeUnTableauDeconnecte(const QString &nomDuTableau)
{
    QString nom = nomDuTableau;
    QList<Tableau>::iterator it = m_tableauxDeconnectes.begin();

    while(it != m_tableauxDeconnectes.end())
    {
        if(((*it).designation() == nom) || (*it).possedeTableauFils(nom, true))
        {
            return true;
        }
        it++;
    }

    return false;
}

bool Installation::possedeUnRecepteurDeconnecte(const QString &nomDuRecepteur)
{
    QList<Recepteur>::iterator itr = m_recepteursDeconnectes.begin();

    while(itr != m_recepteursDeconnectes.end())
    {
        if((*itr).designation() == nomDuRecepteur)
        {
            return true;
        }
        itr++;
    }

    // chercher dans la descendante des tableaux non connectés
    QList<Tableau>::iterator it = m_tableauxDeconnectes.begin();

    while(it != m_tableauxDeconnectes.end())
    {
        if((*it).possedeRecepteurFils(nomDuRecepteur, true))
        {
            return true;
        }
        it++;
    }

    return false; // le recepteur n'est pas trouvé
}

bool Installation::possedeUnLocalDeconnecte(const QString &nomDuLocal)
{
    QList<Local>::iterator itr = m_locauxDeconnectes.begin();

    while(itr != m_locauxDeconnectes.end())
    {
        if((*itr).designation() == nomDuLocal)
        {
            return true;
        }
        itr++;
    }

    // chercher dans la descendante des tableaux non connectés
    QList<Tableau>::iterator it = m_tableauxDeconnectes.begin();

    while(it != m_tableauxDeconnectes.end())
    {
        if((*it).possedeLocalFils(nomDuLocal, true))
        {
            return true;
        }
        it++;
    }

    return false; // le local n'est pas trouvé
}

bool Installation::desinstallerUnRecepteur(const QString &nomDuRecepteur)
{
    if(possedeUnRecepteur(nomDuRecepteur))
    {
        Recepteur r = recepteurInstalle(nomDuRecepteur);
        if(r.possedeUnPere())
        {
            debrancherUnRecepteur(r.designation());
        }

        m_recepteursDeconnectes.removeOne(r);
        return true;
    }

    return false;
}

bool Installation::desinstallerUnLocal(const QString &nomDuLocal)
{
    if(possedeUnLocal(nomDuLocal))
    {
        Local r = localInstalle(nomDuLocal);
        if(r.possedeUnPere())
        {
            debrancherUnLocal(r.designation());
        }

        m_locauxDeconnectes.removeOne(r);
        return true;
    }

    return false;
}

bool Installation::desinstallerUnTableau(const QString &nomDuTableau)
{
    if(possedeUnTableau(nomDuTableau))
    {
        Tableau t = tableauInstalle(nomDuTableau);
        debrancherUnTableau(t.designation());
        if(t.possedeUnPere())
        {
            debrancherUnTableau(t.designation());
        }

//        // ramener tous ses enfants dans les appareils déconnectés
//        if(t.estPere())
//        {
//            m_tableauxDeconnectes << t.debrancherTableauxFils();
//            m_recepteursDeconnectes << t.debrancherRecepteursFils();
//        }

        m_tableauxDeconnectes.removeOne(t);
        return true;
    }

    return false;
}

QList<Tableau> Installation::tableauxSecondairesConnectes()const
{
    return tableaux(Tableau::TableauSecondaire, true);
}

QList<Tableau> Installation::coffretsDivisionnairesConnectes()const
{
    return tableaux(Tableau::CoffretDivisionnaire, true);
}

QList<Tableau> Installation::terminauxConnectes()const
{
    return tableaux(Tableau::Terminal, true);
}

QList<Tableau> Installation::tableaux(Tableau::TypeDeTableau type, bool connectesSeuls) const
{
    QList<Tableau> lt, ltt;
    lt << tableaux(connectesSeuls);

    for(int i = 0; i < lt.count(); i++)
    {
        if(lt.at(i).typeDeTableau() == type)
        {
            ltt << lt.at(i);
        }
    }

    rangerParOrdreCroissant(ltt);

    return ltt;
}

QList<Recepteur> Installation::recepteurs(bool connectesSeuls) const
{
    QList<Recepteur> lr;
    lr << recepteursDeDescendance(); // tous les recepteurs connectés

    if(!connectesSeuls)
    {
        /* recepteurs déconnectés */
        lr << m_recepteursDeconnectes;
    }

    for(int i = 0; i < m_tableauxDeconnectes.count(); i++)
    {
        lr << m_tableauxDeconnectes.at(i).recepteursDeDescendance();
    }

    return lr;
}

QList<Local> Installation::locaux(bool connectesSeuls) const
{
    QList<Local> ll;
    ll << locauxDeDescendance(); // tous les recepteurs connectés

    if(!connectesSeuls)
    {
        /* recepteurs déconnectés */
        ll << m_locauxDeconnectes;
    }

    for(int i = 0; i < m_tableauxDeconnectes.count(); i++)
    {
        ll << m_tableauxDeconnectes.at(i).locauxDeDescendance();
    }

    return ll;
}

QList<Local> Installation::locaux(Local::TypeDeRecepteur type, bool connectesSeuls) const
{
    QList<Local> lr, lrr;
    lr << locaux(connectesSeuls);

    for(int i = 0; i < lr.count(); i++)
    {
        if(lr.at(i).typeDeRecepteur() == type)
        {
            lrr << lr.at(i);
        }
    }

    rangerParOrdreCroissant(lrr);

    return lrr;
}

QList<Recepteur> Installation::recepteurs(Recepteur::TypeDeRecepteur type, bool connectesSeuls) const
{
    QList<Recepteur> lr, lrr;
    lr << recepteurs(connectesSeuls);

    for(int i = 0; i < lr.count(); i++)
    {
        if(lr.at(i).typeDeRecepteur() == type)
        {
            lrr << lr.at(i);
        }
    }

    rangerParOrdreCroissant(lrr);

    return lrr;
}

QList<Tableau> Installation::tableaux(bool connectesSeuls) const
{
    QList<Tableau> lt;
    Tableau t = *this;

    lt << t; // enregistrement du tgbt

    lt << tableauxDeDescendance(); // enregistrement des tableaux connectés

    if(!connectesSeuls)
    {
        /* enregistrement des tableaux déconnectés */
        for(int i = 0; i < m_tableauxDeconnectes.count(); i++)
        {
            Tableau td = m_tableauxDeconnectes.at(i);
            lt << td;
            lt << td.tableauxDeDescendance();
        }
    }

    return lt;
}

void Installation::trouverCaracteristiquesTransfo()
{
    m_transformateur->setPUtilisation(PUtiliseeKW());
}

Installation * Installation::infosToInstallation(QStringList infos)
{
    Installation installation;
    int indexEnCours = 0;
    QList<Tableau> l_tableaux;

    // transfo d'abord
    if(infos.at(indexEnCours) == MOTCLE_TRANSFO)
    {
        indexEnCours++;
        int indexFin = indexEnCours + Transformateur(1.2, 40).infosDuTransfo().count() - 1;

        QStringList info;
        for(int i = indexEnCours; i <= indexFin; i++)
        {
            info << infos.at(i);
        }

        if(Transformateur::infosTransfoValides(info))
        {
            installation.m_transformateur = new Transformateur(info);
        }else
            return 0;
        indexEnCours = indexFin++;
    }else
        return 0;

    int lgrInfosTableau = (new Tableau())->infosDuTableau().count();

    // le TGBT
    indexEnCours++;
    if(infos.at(indexEnCours) == MOTCLE_TABLEAU)
    {
        indexEnCours++;
        int indexFin = indexEnCours + lgrInfosTableau - 1;

        QStringList info;
        for(int i = indexEnCours; i <= indexFin; i++)
        {
            info << infos.at(i);
        }

        if(Tableau::infosTableauValides(info))
        {
            Tableau t = Tableau::infosToTableau(info);
            installation.m_ks = t.ks();
            installation.m_designation =  t.designation();
            l_tableaux << t;
        }else
            return 0;

        indexEnCours = indexFin;
        indexEnCours++;
    }

    // les tableaux ensuite
    indexEnCours++;
    while((infos.count() > indexEnCours) && (infos.at(indexEnCours) == MOTCLE_TABLEAU))
    {
        indexEnCours++;
        int indexFin = indexEnCours + lgrInfosTableau - 1;

        QStringList info;
        for(int i = indexEnCours; i <= indexFin; i++)
        {
            info << infos.at(i);
        }

        if(Tableau::infosTableauValides(info))
        {
            Tableau t = Tableau::infosToTableau(info);
            installation.installerUnTableau(t, t.designationDuParent());
            l_tableaux << t;
        }else
            return 0;

        indexEnCours = indexFin;
        indexEnCours += 2;
    }


    // locaux ensuite
    int lgrInfosLocal = (new Local())->infosDuLocal().count();
    while((indexEnCours < infos.count()) && (infos.at(indexEnCours) == MOTCLE_LOCAL))
    {
        indexEnCours++;
        int indexFin = indexEnCours + lgrInfosLocal - 1;

        QStringList info;
        for(int i = indexEnCours; i <= indexFin; i++)
        {
            info << infos.at(i);
        }

        if(Local::infosLocalValides(info))
        {
            Local l(info);
            installation.installerUnLocal(l, l.designationDuParent());
        }else
            return 0;

        indexEnCours = indexFin;
        indexEnCours += 2;
    }

    // recepteurs enfin
    int lgrInfosRe = (new Recepteur())->infosDuRecepteur().count();
    while((indexEnCours < infos.count()) &&  (infos.at(indexEnCours) == MOTCLE_RECEPTEUR))
    {
        indexEnCours++;
        int indexFin = indexEnCours + lgrInfosRe - 1;

        QStringList info;
        for(int i = indexEnCours; i <= indexFin; i++)
        {
            info << infos.at(i);
        }

        if(Recepteur::infosRecepteurValides(info))
        {
            Recepteur r(info);
            installation.installerUnRecepteur(r, r.designationDuParent());
        }else
            return 0;

        indexEnCours = indexFin;
        indexEnCours +=2;
    }

    // actualiser les ks
    for(int i = 0; i < l_tableaux.count(); i++)
    {
        Tableau t = l_tableaux.at(i);
        installation.tableauConnecte(t.designation()).setKs(t.ks());
    }

    return new Installation(installation);
}

