#include "InstallationGraphicDriver.h"

InstallationGraphicDriver::InstallationGraphicDriver(QGraphicsView *graphicsView, Installation *i)
{
    m_installation = i;
    m_graphicsView = graphicsView;
    m_scene = new QGraphicsScene();    
    m_graphicsView->setScene(m_scene);    
    m_graphicsView->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
    m_scale = 0.5;
    setElementACopier(QString(), QString());
    initialiserActions();

    connect(m_scene, SIGNAL(selectionChanged()), this, SLOT(preparerEtLancerSignalItemIsSelected()));
}

Composant * InstallationGraphicDriver::composant(const Tableau &t)
{
    cstes::TypeDeComposant type;

    switch(t.typeDeTableau())
    {
    case Tableau::TGBT:
        type = cstes::t_TGBT;
        break;
    case Tableau::TableauSecondaire:
        type = cstes::t_TS;
        break;
    case Tableau::CoffretDivisionnaire:
        type = cstes::t_TD;
        break;
    case Tableau::Terminal:
        type = cstes::t_TER;
        break;
    default:
        // rien
        break;
    }

    Composant * cpt = new Composant(type, this);
    cpt->setDesignation(t.designation());

    return cpt;
}

Composant * InstallationGraphicDriver::composant(const Local &l)
{
    cstes::TypeDeComposant type;

    switch(l.typeDeRecepteur())
    {
    case Local::EclairageFluo:
        type = cstes::Local_ecl;
        break;
    case Local::ForceMotrice:
        type = cstes::Local_fm;
        break;
    default:
        // rien
        break;
    }

    Composant * cpt = new Composant(type, this);
    cpt->setDesignation(l.designation());

    return cpt;
}

Composant * InstallationGraphicDriver::composant(const Recepteur &r)
{
    cstes::TypeDeComposant type;

    switch(r.typeDeRecepteur())
    {
    case Recepteur::Eclairage:
        type = cstes::t_Eclairage;
        break;
    case Recepteur::ConditionnementAir:
        type = cstes::t_ConditionneurAir;
        break;
    case Recepteur::Chauffage:
        type = cstes::t_Chauffage;
        break;
    case Recepteur::PriseDeCourant:
        type = cstes::t_PC;
        break;
    case Recepteur::ForceMotrice:
        type = cstes::t_Moteur;
        break;
    default:
        type = cstes::AutreComposant;
    }

    Composant * cpt = new Composant(type, this);
    cpt->setDesignation(r.designation());

    return cpt;
}

void  InstallationGraphicDriver::afficher()
{
    m_scene->clear();
    m_scene->setSceneRect(QRect());
    mettreAjourNiveaux();

    m_installation->trouverCaracteristiquesTransfo();
    afficherSousInstallation(*m_installation, afficherTGBT(afficherTransfo()));       

    m_scene->update();
}

void InstallationGraphicDriver::mettreAjourNiveaux()
{
    m_niveaux.clear();

    float h0 = 150.0 * m_scale; float y0 = 10.0;

    float l_canalTransfo = y0;
    float l_canalTGBT = l_canalTransfo + h0 + (new Composant(cstes::Transfo))->hauteur() * m_scale;

    float hauteurParent = (new Composant(cstes::t_TGBT))->hauteur() * m_scale;
    float canal = l_canalTGBT;

    float l_canalTS = 0;
    float l_canalTD = 0;
    float l_canalTer = 0;
    float l_canalRecept = 0;

    if(!m_installation->tableauxSecondairesConnectes().isEmpty())
    {
        l_canalTS = canal + h0 + hauteurParent;

        canal = l_canalTS;
        hauteurParent = (new Composant(cstes::t_TS))->hauteur() * m_scale;
    }

    if(!m_installation->coffretsDivisionnairesConnectes().isEmpty())
    {       
        l_canalTD = canal + h0 + hauteurParent;

        canal = l_canalTD;
        hauteurParent = (new Composant(cstes::t_TD))->hauteur() * m_scale;
    }

    if(!m_installation->terminauxConnectes().isEmpty())
    {
        l_canalTer = canal + h0 + hauteurParent;

        canal = l_canalTer;
        hauteurParent = (new Composant(cstes::t_TER))->hauteur() * m_scale;
    }

    l_canalRecept = canal + h0 + hauteurParent;

    m_niveaux << l_canalTransfo
              << l_canalTGBT
              << l_canalTS
              << l_canalTD
              << l_canalTer
              << l_canalRecept;
}

Composant * InstallationGraphicDriver::afficherTGBT(Composant *transfo)
{
    Composant * tgbt = new Composant(cstes::t_TGBT, this);
    tgbt->setDesignation(m_installation->designationTGBT());
    QString caracteristiques = tr("Pi = %1 kW\nPu = %2 kW\nFP = %3").arg(QString::number(m_installation->PInstalleeKW(), 'f', 2)).arg(QString::number(m_installation->PUtiliseeKW(), 'f', 2)).arg(QString::number(m_installation->cosPhi(), 'f', 2));
    tgbt->setCaracteristiques(caracteristiques);
    tgbt->setTextePostion(cstes::TextCache);
    m_scene->addItem(tgbt);
    tgbt->setY(m_niveaux.at(canalTGBT));
    tgbt->setScale(m_scale);
    connecter(transfo, tgbt);

    return tgbt;
}

Composant * InstallationGraphicDriver::afficher(cstes::TypeDeComposant type, QString designation, float x, float y)
{
    Composant * cpt = new Composant(type, this);
    cpt->setDesignation(designation);
    cpt->setTextePostion(cstes::TextCache);
    m_scene->addItem(cpt);
    cpt->setX(x);
    cpt->setY(y);
    cpt->setScale(m_scale);

    return cpt;
}

Composant * InstallationGraphicDriver::afficherTransfo()
{
    Composant * transfo = new Composant(cstes::Transfo, this);
    transfo->setDesignation("Transformateur");
    QString caracteristiques = tr("%1 KVA").arg(QString::number(m_installation->transformateur().puissanceKVA(), 'f', 2));
    transfo->setCaracteristiques(caracteristiques);
    transfo->setTextePostion(cstes::TextCoteDroit);
    m_scene->addItem(transfo);
    transfo->setY(m_niveaux.at(canalTranfo));
    transfo->setScale(m_scale);
    transfo->centrerH(m_scene);

    return transfo;
}

GroupeDeComposants InstallationGraphicDriver::group(const QList<Recepteur> & lr)
{
    GroupeDeComposants group;

    for(int i = 0; i < lr.count(); i++)
    {
        Composant * cpt = composant(lr.at(i));
        m_scene->addItem(cpt);
        cpt->setDesignation(lr.at(i).designation());
        QString caracteristiques = tr("Pu = %1 kW").arg(QString::number(lr.at(i).PUtiliseeKW(), 'f', 2));
        cpt->setCaracteristiques(caracteristiques);
        cpt->textBasVertical();
        cpt->setScale(m_scale);
        group.ajouterUnComposant(cpt, false);
    }

    return group;
}

GroupeDeComposants InstallationGraphicDriver::group(const QList<Local> &ll)
{
    GroupeDeComposants group;

    for(int i = 0; i < ll.count(); i++)
    {
        Composant * cpt = composant(ll.at(i));
        m_scene->addItem(cpt);
        cpt->setDesignation(ll.at(i).designation());
        QString caracteristiques = tr("Pu = %1 kW").arg(QString::number(ll.at(i).PUtiliseeKW(), 'f', 2));
        cpt->setCaracteristiques(caracteristiques);
        cpt->textBasVertical();
        cpt->setScale(m_scale);
        group.ajouterUnComposant(cpt, false);
    }

    return group;
}

GroupeDeComposants InstallationGraphicDriver::group(const QList<Tableau> &lt)
{
    GroupeDeComposants group;

    for(int i = 0; i < lt.count(); i++)
    {
        Composant * cpt = composant(lt.at(i));
        m_scene->addItem(cpt);
        cpt->setDesignation(lt.at(i).designation());
        QString caracteristiques = tr("Pu = %1 kW").arg(QString::number(lt.at(i).PUtiliseeKW(), 'f', 2));
        cpt->setCaracteristiques(caracteristiques);
        cpt->centrerText();
        cpt->setScale(m_scale);
        group.ajouterUnComposant(cpt, false);
    }

    return group;
}

void InstallationGraphicDriver::afficherSousInstallation(const Tableau &pere, Composant *pereCpt)
{
    GroupeDeComposants groupTAB;
    QList<Tableau> l_tfils;

    // ajouter les ts fils
    if(!pere.TSFils().isEmpty())
    {
        QList<Tableau> l_ts;
        l_ts << pere.TSFils();
        GroupeDeComposants groupTS(group(l_ts));
        groupTS.setY(m_niveaux.at(canalTS));
        groupTAB.ajouterUnGroupe(groupTS, false);

        l_tfils << l_ts;
    }

    // ajouter les td fils
    if(!pere.TDFils().isEmpty())
    {
        QList<Tableau> l_td;
        l_td << pere.TDFils();
        GroupeDeComposants groupTD(group(l_td));
        groupTD.setY(m_niveaux.at(canalTD));
        groupTAB.ajouterUnGroupe(groupTD, false);
        l_tfils << l_td;
    }

    // ajouter les terminaux fils
    if(!pere.terminauxFils().isEmpty())
    {
        QList<Tableau> l_ter;
        l_ter << pere.terminauxFils();
        GroupeDeComposants groupTER(group(l_ter));
        groupTER.setY(m_niveaux.at(canalTerminal));
        groupTAB.ajouterUnGroupe(groupTER, false);
        l_tfils << l_ter;
    }

    // ajouter les locaux fils
    if(!pere.locauxFils().isEmpty())
    {
        QList<Local> l_loc;
        l_loc << pere.locauxFils();
        GroupeDeComposants groupLOC(group(l_loc));
        groupLOC.setY(m_niveaux.at(canalRecepteur));
        groupTAB.ajouterUnGroupe(groupLOC, false);
    }

    // ajouter les récepteurs fils
    if(!pere.recepteursFils().isEmpty())
    {
        QList<Recepteur> recepteurs;
        recepteurs << pere.recepteursFils();
        GroupeDeComposants groupRecept(group(recepteurs));
        groupRecept.setY(m_niveaux.at(canalRecepteur));
        groupTAB.ajouterUnGroupe(groupRecept, false);
    }

    // afficher la sous installation
    connecter(pereCpt, groupTAB, espacementsFils(pere));

    // afficher la sous installation des fils
    for(int i = 0; i < l_tfils.count(); i++)
    {
        afficherSousInstallation(l_tfils.at(i), (*groupTAB.iteratorAt(i)));
    }
}

void InstallationGraphicDriver::agrandir()
{
    float pas = 0.1;

    if(m_scale < 1.0)
    {
        m_scale += pas;
        afficher();
    }
}

void InstallationGraphicDriver::reduire()
{
    float pas = 0.1;

    if(m_scale > 0.2)
    {
        m_scale -= pas;
        afficher();
    }
}

void InstallationGraphicDriver::lancerSignalCreerNouveauTableau(const QString &designationParent, Tableau::TypeDeTableau type, int nombre)
{
    emit creerNouveauTableau(designationParent, type, nombre);
}

void InstallationGraphicDriver::lancerSignalEditerTableau(const QString &designation)
{
    emit editerTableau(designation);
}

void InstallationGraphicDriver::lancerSignalSupprimerTableau(const QString &designation)
{
    emit supprimerTableau(designation);
}

void InstallationGraphicDriver::lancerSignalCreerNouveauRecepteur(const QString &designationParent, int nombre)
{
    emit creerNouveauRecepteur(designationParent, nombre);
}

void InstallationGraphicDriver::lancerSignalEditerRecepteur(const QString &designation)
{
    emit editerRecepteur(designation);
}

void InstallationGraphicDriver::lancerSignalSupprimerRecepteur(const QString &designation)
{
    emit supprimerRecepteur(designation);
}

void InstallationGraphicDriver::lancerSignalCreerNouveauLocal(const QString &designationParent, int nombre)
{
    emit creerNouveauLocal(designationParent, nombre);
}

void InstallationGraphicDriver::lancerSignalEditerLocal(const QString &designation)
{
    emit editerLocal(designation);
}

void InstallationGraphicDriver::lancerSignalSupprimerLocal(const QString &designation)
{
    emit supprimerLocal(designation);
}

void InstallationGraphicDriver::lancerSignalDefinirExtension(bool definir)
{
    emit definirExtension(definir);
}

void InstallationGraphicDriver::lancerSignalItemIsSelected(bool selected, QString itemName)
{
    emit itemIsSelected(selected, itemName);
}

void InstallationGraphicDriver::lancerSignalCopierItem(QString designation)
{
    emit copierItem(designation);
}

void InstallationGraphicDriver::lancerSignalCollerItem(QString designation)
{
    emit collerItem(designation);
}

void InstallationGraphicDriver::lancerSignalCouperItem(QString designation)
{
    emit couperItem(designation);
}

void InstallationGraphicDriver::lancerSignalEditerTransfo()
{
    emit editerTransfo();
}

void InstallationGraphicDriver::lancerSignalClickSurTableauDiv()
{
    emit clickSurTableauDiv();
}

void InstallationGraphicDriver::lancerSignalClickSurTableauSec()
{
    emit clickSurTableauSec();
}

void InstallationGraphicDriver::lancerSignalClickSurTableauTer()
{
    emit clickSurTableauTer();
}

void InstallationGraphicDriver::lancerSignalClickSurTGBT()
{
    emit clickSurTGBT();
}

void InstallationGraphicDriver::lancerSignalClickSurRecepteur()
{
    emit clickSurRecepteur();
}

void InstallationGraphicDriver::lancerSignalClickSurTransfo()
{
    emit clickSurTransfo();
}

float InstallationGraphicDriver::Li(const Recepteur &r)
{
    Composant * cpt = composant(r);
    float li = cpt->longueur() * m_scale;

    delete cpt;

    return li;
}

float InstallationGraphicDriver::Li(const Local &l)
{
    Composant * cpt = composant(l);
    float li = cpt->longueur() * m_scale;

    delete cpt;

    return li;
}

float InstallationGraphicDriver::Li(const Tableau &t)
{
    Composant * cpt = composant(t);
    float li = cpt->longueur() * m_scale;

    delete cpt;

    return li;
}

float InstallationGraphicDriver::largeurDeSousInstallation(const Tableau & pere)
{
    int lgrTotal = 0;
    // trois types de fils possibles

    // tableaux
    for(int i = 0; i < pere.tableauxFils().count(); i++)
    {
        lgrTotal += largeurDeSousInstallation(pere.tableauxFils().at(i));
    }

    // locaux
    for(int i = 0; i < pere.locauxFils().count(); i++)
    {
        lgrTotal += Li(pere.locauxFils().at(i));
    }

    // récepteurs
    for(int i = 0; i < pere.recepteursFils().count(); i++)
    {
        lgrTotal += Li(pere.recepteursFils().at(i));
    }

    int nbDeFils = pere.tableauxFils().count() + pere.locauxFils().count()
                   + pere.recepteursFils().count();

    if(nbDeFils != 0)
    {
        lgrTotal += (nbDeFils - 1) * espace();
    }

    int lgrPere = Li(pere);
    if(lgrTotal < lgrPere) lgrTotal = lgrPere; // on retient le maximum

    return lgrTotal;
}

QList<float> InstallationGraphicDriver::espacementsFils(const Tableau &t)
{
    QList<float> lesp;

    // trois types de fils

    // tableaux
    for(int i = 1; i < t.tableauxFils().count(); i++)
    {
        lesp << espacement(t.tableauxFils().at(i-1), t.tableauxFils().at(i));
    }

    if(!t.tableauxFils().isEmpty() && !t.locauxFils().isEmpty())
    {
        lesp << espacement(t.tableauxFils().last(), t.locauxFils().first());
    }

    // locaux
    for(int i = 1; i < t.locauxFils().count(); i++)
    {
        lesp << espacement(t.locauxFils().at(i-1), t.locauxFils().at(i));
    }

    if(!t.locauxFils().isEmpty() && !t.recepteursFils().isEmpty())
    {
        lesp << espacement(t.recepteursFils().first(), t.locauxFils().last());
    }

    if(t.locauxFils().isEmpty())
    {
        if(!t.tableauxFils().isEmpty() && !t.recepteursFils().isEmpty())
        {
            lesp << espacement(t.tableauxFils().last(), t.recepteursFils().first());
        }
    }

    // récepteurs
    for(int i = 1; i < t.recepteursFils().count(); i++)
    {
        lesp << espacement(t.recepteursFils().at(i-1), t.recepteursFils().at(i));
    }

    return lesp;
}

float InstallationGraphicDriver::espace()
{
    return ESPACE * m_scale;
}

float InstallationGraphicDriver::espacement(Local l1, Local l2)
{
    return espace();
}

float InstallationGraphicDriver::espacement(Recepteur r, Local l)
{
    return espace();
}

float InstallationGraphicDriver::espacement(Recepteur r1, Recepteur r2)
{
    return espace();
}

float InstallationGraphicDriver::espacement(Tableau t1, Tableau t2)
{
    float espace1 = (largeurDeSousInstallation(t1) - Li(t1))/2;
    float espace2 = (largeurDeSousInstallation(t2) - Li(t2))/2;
    return espace() + espace1 + espace2;
}

float InstallationGraphicDriver::espacement(Tableau t, Local l)
{
    float espaceT = (largeurDeSousInstallation(t) - Li(t))/2;

    // espaceT >= 0 car largeur >= Li et espaceT est sous échelle

    return espaceT + espace();
}

float InstallationGraphicDriver::espacement(Tableau t, Recepteur r)
{
    float espaceT = (largeurDeSousInstallation(t) - Li(t))/2;

    // espaceT >= 0 car largeur >= Li et espaceT est sous échelle

    return espaceT + espace();
}

QList<float> InstallationGraphicDriver::longueurs(QList<Local>ll)
{
    QList<float> l;
    for(int i = 0; i < ll.count(); i++)
    {
        l << Li(ll.at(i));
    }

    return l;
}

QList<float> InstallationGraphicDriver::longueurs(QList<Recepteur>lr)
{
    QList<float> l;
    for(int i = 0; i < lr.count(); i++)
    {
        l << Li(lr.at(i));
    }

    return l;
}

QList<float> InstallationGraphicDriver::longueurs(QList<Tableau>lt)
{
    QList<float> l;
    for(int i = 0; i < lt.count(); i++)
    {
        l << largeurDeSousInstallation(lt.at(i));
    }

    return l;
}

void InstallationGraphicDriver::connecter(Composant *pere, Composant *fils)
{
    Cable * cable = new Cable(m_scene);
    m_scene->addItem(cable);
    cable->connecter(pere, fils);
}

void InstallationGraphicDriver::connecter(Composant *pere, GroupeDeComposants fils, float espacement)
{
    Cable * cable = new Cable(m_scene);
    m_scene->addItem(cable);
    cable->connecter(pere, fils, espacement);
}

void InstallationGraphicDriver::connecter(Composant *pere, GroupeDeComposants fils, QList<float>espacements)
{
    Cable * cable = new Cable(m_scene);
    m_scene->addItem(cable);
    cable->connecter(pere, fils, espacements);
}

void InstallationGraphicDriver::preparerEtLancerSignalItemIsSelected()
{
    if(m_scene->selectedItems().isEmpty())
    {
        emit itemIsSelected(false);
    }else
    {
        // alors un seul composant est sélectionné
        emit itemIsSelected(true, composantSelectionne()->designation());
    }
}

Composant * InstallationGraphicDriver::composantSelectionne() const
{
    if(m_scene->selectedItems().isEmpty())
    {
        return 0;
    }else
    {
        return qgraphicsitem_cast<Composant *>(m_scene->selectedItems().first());
    }
}

void InstallationGraphicDriver::selectionnerUnComposant(QString designation)
{
    foreach (QGraphicsItem * item, m_scene->items()) {
        Composant * cpt = qgraphicsitem_cast<Composant *>(item);
        if(cpt && cpt->designation() == designation)
        {
            cpt->setSelected(true);
            emit itemIsSelected(true, designation);

            // envoyer des signaux pour les objets clickables
            switch (cpt->getTypeDeComposant()) {
            case cstes::t_TGBT:
                emit clickSurTGBT();
                break;
            case cstes::t_TS:
                emit clickSurTableauSec();
                break;
            case cstes::t_TD:
                emit clickSurTableauDiv();
                break;
            case cstes::t_TER:
                emit clickSurTableauTer();
                break;
            default:
                emit clickSurRecepteur();
                break;
            }
        }
    }
}

bool InstallationGraphicDriver::composantEnCoursCopiable()const
{
    if(composantSelectionne()->typeDeComposant() == cstes::Transfo
       || composantSelectionne()->typeDeComposant() == cstes::t_TGBT)
    {
        return false;
    }else
    {
        return true;
    }   
}

bool InstallationGraphicDriver::composantEnCoursEstUnTransfo()const
{
    if(composantSelectionne()->typeDeComposant() == cstes::Transfo)
    {
        return true;
    }else
    {
        return false;
    }
}

bool InstallationGraphicDriver::composantACopierEstCompatible()const
{
    cstes::TypeDeComposant type = composantSelectionne()->typeDeComposant();
    QString designation = composantSelectionne()->designation();

    cstes::TypeDeComposant typeEltAcopier = Composant::stringToType(m_typeDeEltACopier);

    if(typeEltAcopier == cstes::AucunComposant)
    {
        return false;
    }

    // nous avons un élément à  copier

    switch(type)
    {
        case cstes::t_TGBT:
            if(typeEltAcopier == cstes::t_TS)
            {
                return true;
            }else
            {
                return false;
            }
            break;
        case cstes::t_TD:
            if(typeEltAcopier != cstes::t_TS
               && typeEltAcopier != cstes::t_TD)
            {
                return true;
            }else
            {
                return false;
            }
            break;
        case cstes::t_TS:
            if(typeEltAcopier != cstes::t_TS
               && !Composant::estUnRecepteur(m_typeDeEltACopier))
            {
                return true;
            }else
            {
                return false;
            }
            break;
       case cstes::t_TER:
            if(Composant::estUnRecepteur(m_typeDeEltACopier))
            {
                return true;
            }else
            {
                return false;
            }
            break;
         default:
            return false;
    }

    return false;
}

QString InstallationGraphicDriver::typeDeComposantEnCours()const
{
    return composantSelectionne()->typeDeComposantStr();
}

void InstallationGraphicDriver::setElementACopier(QString designation, QString typeDeComposant)
{
    m_elementACopier = designation;
    m_typeDeEltACopier = typeDeComposant;
}

QString InstallationGraphicDriver::ElementACopier()const
{
    return m_elementACopier;
}

QString InstallationGraphicDriver::typeDeEltACopier()const
{
    return m_typeDeEltACopier;
}

void InstallationGraphicDriver::initialiserActions()
{
    actionAjouter = menu.addAction("Ajouter...");
    actionTS = menuAjouter.addAction("Tableau secondaire");
    sousMenuDeQuantite(actionTS, "tableau secondaire");
    actionTD = menuAjouter.addAction("Tableau divisionnaire");
    sousMenuDeQuantite(actionTD, "tableau divisionnaire");
    actionTER = menuAjouter.addAction("Tableau terminal");
    sousMenuDeQuantite(actionTER, "tableau terminal");
    actionRecepteur = menuAjouter.addAction("Récepteur");
    sousMenuDeQuantite(actionRecepteur, "récepteur");
    actionLocal = menuAjouter.addAction("Local");
    sousMenuDeQuantite(actionLocal, "local");

    actionAjouter->setMenu(&menuAjouter);
    actionEditer = menu.addAction("Editer");

    menu.addSeparator();

    actionCopier = menu.addAction("Copier");
    actionCouper = menu.addAction("Couper");
    actionColler = menu.addAction("Coller");
    actionSupprimer = menu.addAction("Supprimer");
}

void InstallationGraphicDriver::afficherMenuContextuel(const Composant * cpt, QGraphicsSceneContextMenuEvent *e)
{
    mettreAjourEtatsActions(cpt);
    QAction * actionSelected = menu.exec(e->screenPos());

    if(actionSelected)
    {
        if(cpt->typeDeComposant() == cstes::t_TS || cpt->typeDeComposant() == cstes::t_TD || cpt->typeDeComposant() == cstes::t_TGBT || cpt->typeDeComposant() == cstes::t_TER)
       {
           choisirActionTableau(actionSelected, cpt);
           return;
       }else
       {
           if(cpt->typeDeComposant() == cstes::Local_ecl || cpt->typeDeComposant() == cstes::Local_fm)
           {
               choisirActionLocal(actionSelected,cpt);
               return;
           }else
           {
               choisirActionRecepteur(actionSelected,cpt);
           }
       }
    }
}

void InstallationGraphicDriver::choisirActionTableau(QAction *actionSelected, const Composant * cpt)
{
    if(actionSelected->text().contains("tableau"))
    {
        Tableau::TypeDeTableau type;
        if(actionSelected->text().contains("secondaire"))
        {
            type = Tableau::TableauSecondaire;
        }else
        {
            if(actionSelected->text().contains("divisionnaire"))
            {
                type = Tableau::CoffretDivisionnaire;
            }else
            {
                type = Tableau::Terminal;
            }

        }

        int l_nombre;
        if(actionSelected->text().contains(AUTRE_NOMBRE))
        {
            l_nombre = 0;
        }else
        {
            l_nombre = nombre(actionSelected);
        }

        lancerSignalCreerNouveauTableau(cpt->designation(), type, l_nombre);
    }

    if(actionSelected->text().contains("récepteur"))
    {
        int l_nombre;
        if(actionSelected->text().contains(AUTRE_NOMBRE))
        {
            l_nombre = 0;
        }else
        {
            l_nombre = nombre(actionSelected);
        }

        lancerSignalCreerNouveauRecepteur(cpt->designation(), l_nombre);
    }

    if(actionSelected->text().contains("local")
        ||actionSelected->text().contains("locaux"))
    {
        int l_nombre;
        if(actionSelected->text().contains(AUTRE_NOMBRE))
        {
            l_nombre = 0;
        }else
        {
            l_nombre = nombre(actionSelected);
        }

        lancerSignalCreerNouveauLocal(cpt->designation(), l_nombre);
    }

    if(actionSelected->text() == actionEditer->text())
    {
        lancerSignalEditerTableau(cpt->designation());
    }

    if(actionSelected->text() == actionSupprimer->text())
    {
        lancerSignalSupprimerTableau(cpt->designation());
    }

    if(actionSelected->text() == actionCopier->text())
    {
        lancerSignalCopierItem(cpt->designation());
    }

    if(actionSelected->text() == actionColler->text())
    {
        lancerSignalCollerItem(cpt->designation());
    }

    if(actionSelected->text() == actionCouper->text())
    {
        lancerSignalCouperItem(cpt->designation());
    }
}

void InstallationGraphicDriver::choisirActionRecepteur(QAction * actionSelected, const Composant * cpt)
{
    // c'est un récepteur
     if(actionSelected->text() == actionEditer->text())
     {
          lancerSignalEditerRecepteur(cpt->designation());
     }

     if(actionSelected->text() == actionSupprimer->text())
     {
         lancerSignalSupprimerRecepteur(cpt->designation());
     }

     if(actionSelected->text() == actionCopier->text())
     {
         lancerSignalCopierItem(cpt->designation());
     }

     if(actionSelected->text() == actionColler->text())
     {
         lancerSignalCollerItem(cpt->designation());
     }

     if(actionSelected->text() == actionCouper->text())
     {
         lancerSignalCouperItem(cpt->designation());
     }
}

void InstallationGraphicDriver::choisirActionLocal(QAction * actionSelected, const Composant * cpt)
{
    // c'est un local
    if(actionSelected->text() == actionEditer->text())
    {
         lancerSignalEditerLocal(cpt->designation());
    }

    if(actionSelected->text() == actionSupprimer->text())
    {
        lancerSignalSupprimerLocal(cpt->designation());
    }

    if(actionSelected->text() == actionColler->text())
    {
        lancerSignalCollerItem(cpt->designation());
    }

    if(actionSelected->text() == actionCouper->text())
    {
        lancerSignalCouperItem(cpt->designation());
    }
    if(actionSelected->text() == actionCopier->text())
    {
        lancerSignalCopierItem(cpt->designation());
    }

    return;
}

void InstallationGraphicDriver::mettreAjourEtatsActions(const Composant * cpt)
{
    actionRecepteur->setVisible(true);
    actionTER->setVisible(true);
    actionTD->setVisible(true);
    actionLocal->setVisible(true);
    actionSupprimer->setVisible(true);
    actionTS->setVisible(true);
    actionEditer->setVisible(true);
    actionColler->setEnabled(true);
    actionCouper->setEnabled(true);
    actionCopier->setEnabled(true);
    actionAjouter->setVisible(true);

    if(!composantEnCoursCopiable())
    {
        actionCopier->setEnabled(false);
        actionCouper->setEnabled(false);
    }

    if(!composantACopierEstCompatible())
    {
        actionColler->setEnabled(false);
    }

    if(cpt->typeDeComposant() == cstes::t_TGBT)
    {
        actionRecepteur->setVisible(false);
        actionTER->setVisible(false);
        actionTD->setVisible(false);
        actionLocal->setVisible(false);
        actionSupprimer->setVisible(false);
    }else
    {
        if(cpt->typeDeComposant() == cstes::t_TS)
        {
           actionTS->setVisible(false);
           actionRecepteur->setVisible(false);
        }else
        {
            if(cpt->typeDeComposant() == cstes::t_TER)
            {
                actionTS->setVisible(false);
                actionTD->setVisible(false);
                actionTER->setVisible(false);
                actionLocal->setVisible(false);
            }else
            {
                if(cpt->typeDeComposant() == cstes::t_TD)
                {
                    actionTD->setVisible(false);
                    actionTS->setVisible(false);
                }else
                {
                    // récepteur et local
                    actionAjouter->setVisible(false);
                }
            }
        }
    }
}

void InstallationGraphicDriver::sousMenuDeQuantite(QAction *action, QString suffixe)
{
    QMenu * menu_l = new QMenu();

    for(int i = 1; i <= 5; i++)
    {
        menu_l->addAction(QString::number(i) + " " + accorderSuffixe(i, suffixe));
    }

    menu_l->addSeparator();
    menu_l->addAction(QObject::tr("n %1...").arg(accorderSuffixe(2, suffixe)));

    action->setMenu(menu_l);
}

QString InstallationGraphicDriver::accorderSuffixe(int nombre, QString suffixe)
{
    if(nombre > 1)
    {
        if(suffixe.contains("divisionnaire"))
            return QString("tableaux divisionnaires");

        if(suffixe.contains("secondaire"))
            return QString("tableaux secondaires");

        if(suffixe.contains("récepteur"))
            return QString("récepteurs");

        if(suffixe.contains("local"))
            return QString("locaux");

        if(suffixe.contains("terminal"))
            return QString("tableaux terminaux");
    }

    return suffixe;
}

int InstallationGraphicDriver::nombre(QAction * actionQuantite)
{
    QString text = actionQuantite->text();

    for(int i = 1; i <= 5; i++)
    {
        if(text.contains(QString::number(i)))
            return i;
    }

    return 0;
}
