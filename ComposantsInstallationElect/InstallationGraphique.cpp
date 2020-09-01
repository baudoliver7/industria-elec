#include "InstallationGraphique.h"

InstallationGraphique::InstallationGraphique(Installation *i)
{
    m_installation = i;
    m_scene = new QGraphicsScene();
    setScene(m_scene);
    m_scale = 0.5;

    initialiserNiveaux();
}

Composant * InstallationGraphique::composant(const Tableau &t)
{
    Composant::TypeDeComposant type;

    switch(t.typeDeTableau())
    {
    case Tableau::TGBT:
        type = Composant::t_TGBT;
        break;
    case Tableau::TableauSecondaire:
        type = Composant::t_TS;
        break;
    case Tableau::CoffretDivisionnaire:
        type = Composant::t_TD;
        break;
    case Tableau::Terminal:
        type = Composant::t_TER;
        break;
    default:
        // rien
        break;
    }

    Composant * cpt = new Composant(type, this);
    cpt->setDesignation(t.designation());

    return cpt;
}

//Composant * InstallationGraphique::composant(Composant::TypeDeComposant type,
//                                             const QString &designation,
//                                             Composant::PositionDeTexte position)
//{
//    Composant * cpt = new Composant(type, this);
//    cpt->setDesignation(designation);
//    cpt->setTextePostion(position);
//
//    return cpt;
//}

Composant * InstallationGraphique::composant(const Recepteur &r)
{
    Composant::TypeDeComposant type;

    switch(r.typeDeRecepteur())
    {
    case Recepteur::Eclairage:
        type = Composant::t_Eclairage;
        break;
    case Recepteur::ConditionnementAir:
        type = Composant::t_ConditionneurAir;
        break;
    case Recepteur::Chauffage:
        type = Composant::t_Chauffage;
        break;
    case Recepteur::PriseDeCourant:
        type = Composant::t_PC;
        break;
    case Recepteur::ForceMotrice:
        type = Composant::t_Moteur;
        break;
    default:
        type = Composant::AutreComposant;
    }

    Composant * cpt = new Composant(type, this);
    cpt->setDesignation(r.designation());

    return cpt;
}

void  InstallationGraphique::afficher()
{
    m_scene->clear();
    construireSousInstallation(*m_installation, afficherTGBT(afficherTransfo()));

    m_scene->update();
}

void InstallationGraphique::initialiserNiveaux()
{
    m_niveaux.clear();

    float h0 = 150.0 * m_scale; float y0 = 10.0;

    float l_canalTransfo = y0;
    float l_canalTGBT = l_canalTransfo + h0 + (new Composant(Composant::Transfo))->hauteur() * m_scale;
    float l_canalTS = l_canalTGBT + h0 + (new Composant(Composant::t_TGBT))->hauteur() * m_scale;
    float l_canalTD = l_canalTS + h0 + (new Composant(Composant::t_TS))->hauteur() * m_scale;
    float l_canalTer = l_canalTD + h0 + (new Composant(Composant::t_TD))->hauteur() * m_scale;
    float l_canalRecept = l_canalTer + h0 + (new Composant(Composant::t_TER))->hauteur() * m_scale;

    m_niveaux << l_canalTransfo
              << l_canalTGBT
              << l_canalTS
              << l_canalTD
              << l_canalTer
              << l_canalRecept;
}

Composant * InstallationGraphique::afficherTGBT(Composant *transfo)
{
    Composant * tgbt = new Composant(Composant::t_TGBT, this);
    tgbt->setDesignation(m_installation->designationTGBT());
    tgbt->setTextePostion(Composant::TextCache);
    m_scene->addItem(tgbt);
    tgbt->setY(m_niveaux.at(canalTGBT));
    tgbt->setScale(m_scale);
    connecter(transfo, tgbt);

    return tgbt;
}

Composant * InstallationGraphique::afficherTransfo()
{
    Composant * transfo = new Composant(Composant::Transfo, this);
    transfo->setDesignation("Transformateur");
    transfo->setTextePostion(Composant::TextCoteDroit);
    m_scene->addItem(transfo);
    transfo->setY(m_niveaux.at(canalTranfo));
    transfo->setScale(m_scale);
    transfo->centrerH(m_scene);

    return transfo;
}

GroupeDeComposants InstallationGraphique::group(const QList<Recepteur> & lr)
{
    GroupeDeComposants group;

    for(int i = 0; i < lr.count(); i++)
    {
        Composant * cpt = composant(lr.at(i));
        m_scene->addItem(cpt);
        cpt->setDesignation(lr.at(i).designation());
        cpt->textBasVertical();
        cpt->setScale(m_scale);
        group.ajouterUnComposant(cpt, false);
    }

    return group;
}

GroupeDeComposants InstallationGraphique::group(const QList<Tableau> &lt)
{
    GroupeDeComposants group;

    for(int i = 0; i < lt.count(); i++)
    {
        Composant * cpt = composant(lt.at(i));
        m_scene->addItem(cpt);
        cpt->setDesignation(lt.at(i).designation());
        cpt->centrerText();
        cpt->setScale(m_scale);
        group.ajouterUnComposant(cpt, false);
    }

    return group;
}

void InstallationGraphique::construireSousInstallation(const Tableau & pere, Composant * pereCpt)
{

    if(pere.estUnTerminal())
    {
        // afficher des récepteurs
        QList<Recepteur> recepteurs;
        recepteurs << pere.recepteursFils();
        if(!recepteurs.isEmpty())
        {
            GroupeDeComposants groupRecept(group(recepteurs));
            groupRecept.setY(m_niveaux.at(canalRecepteur));

            connecter(pereCpt, groupRecept, espacementFils(pere));
        }
        return;
    }

    GroupeDeComposants groupTAB;
    QList<Tableau> l_tfils;

    // afficher les ts
    QList<Tableau> l_ts;
    l_ts << pere.TSFils();
    if(!l_ts.isEmpty())
    {
        GroupeDeComposants groupTS(group(l_ts));
        groupTS.setY(m_niveaux.at(canalTS));

        if(m_installation->ExtensionDefinie())
        {
            Composant * disjoncteur = new Composant(Composant::Disjoncteur, this);
            disjoncteur->setDesignation("Disjoncteur");
            disjoncteur->setTextePostion(Composant::TextCoteDroit);
            m_scene->addItem(disjoncteur);
            disjoncteur->setScale(m_scale);

            groupTS.ajouterUnComposant(disjoncteur, true);
        }

        groupTAB.ajouterUnGroupe(groupTS, false);

        l_tfils << l_ts;
    }

    // afficher les td
    QList<Tableau> l_td;
    l_td << pere.TDFils();
    if(!l_td.isEmpty())
    {
        GroupeDeComposants groupTD(group(l_td));
        groupTD.setY(m_niveaux.at(canalTD));

        if(m_installation->ExtensionDefinie())
        {
            QString etiquette = "Extension de " + QString::number(m_installation->extension() * 100) + " %";
            Composant * extension = new Composant(Composant::t_Extension, this);
            extension->setDesignation(etiquette);
            extension->setTextePostion(Composant::TextCentre);
            m_scene->addItem(extension);
            extension->setScale(m_scale);
            
            groupTD.ajouterUnComposant(extension, true);
        }

        groupTAB.ajouterUnGroupe(groupTD, false);
        l_tfils << l_td;
    }

    // afficher des terminaux
    QList<Tableau> l_ter;
    l_ter << pere.terminauxFils();
    if(!l_ter.isEmpty())
    {
        GroupeDeComposants groupTER(group(l_ter));
        groupTER.setY(m_niveaux.at(canalTerminal));
        groupTAB.ajouterUnGroupe(groupTER, false);
        l_tfils << l_ter;
    }

    // connecter les fils au père
    connecter(pereCpt, groupTAB, espacementFils(pere));

    // construire sous installation des fils
    for(int i = 0; i < l_tfils.count(); i++)
    {
        construireSousInstallation(l_tfils.at(i), (*groupTAB.iteratorAt(i)));
    }
}

void InstallationGraphique::agrandir()
{
    float pas = 0.1;

    if(m_scale < 1.0)
    {
        m_scale += pas;
        initialiserNiveaux();
        afficher();
    }
}

void InstallationGraphique::reduire()
{
    float pas = 0.1;

    if(m_scale > 0.2)
    {
        m_scale -= pas;
        initialiserNiveaux();
        afficher();
    }
}

void InstallationGraphique::lancerSignalCreerNouveauTableau(const QString &designationParent, Tableau::TypeDeTableau type, int nombre)
{
    emit creerNouveauTableau(designationParent, type, nombre);
}

void InstallationGraphique::lancerSignalEditerTableau(const QString &designation)
{
    emit editerTableau(designation);
}

void InstallationGraphique::lancerSignalSupprimerTableau(const QString &designation)
{
    emit supprimerTableau(designation);
}

void InstallationGraphique::lancerSignalCreerNouveauRecepteur(const QString &designationParent, int nombre)
{
    emit creerNouveauRecepteur(designationParent, nombre);
}

void InstallationGraphique::lancerSignalEditerRecepteur(const QString &designation)
{
    emit editerRecepteur(designation);
}

void InstallationGraphique::lancerSignalSupprimerRecepteur(const QString &designation)
{
    emit supprimerRecepteur(designation);
}

void InstallationGraphique::lancerSignalDefinirExtension(bool definir)
{
    emit definirExtension(definir);
}

void InstallationGraphique::lancerSignalItemIsSelected(bool selected, QString itemName)
{
    emit itemIsSelected(selected, itemName);
}

float InstallationGraphique::Li(const Recepteur &r)
{
    Composant * cpt = composant(r);
    float li = cpt->longueur() * m_scale;

    delete cpt;

    return li;
}

float InstallationGraphique::Li(const Tableau &t)
{
    Composant * cpt = composant(t);
    float li = cpt->longueur() * m_scale;

    delete cpt;

    return li;
}

float InstallationGraphique::largeurDeSousInstallation(const Tableau & pere)
{
    if(pere.estUnTerminal())
    {
        if(pere.estPere()) // pere de recepteur
        {
            // terminal possède un seul fils
            float lgrFils =  Li(pere.recepteursFils().at(0));
            float lgrPere = Li(pere);

            float max = lgrFils;
            if(lgrFils < lgrPere)
                max = lgrPere;

            return max;

        }else
        {
            // on envoie sa longueur
            return Li(pere);
        }
    }

    float lgrMax = Li(pere);

    // entrer les tableaux fils
    // un tableau de type non terminal n'a que des tableaux comme fils
    QList<Tableau> tableaux_l;
    tableaux_l << pere.tableauxFils();

    int nb = tableaux_l.count();
    if(nb==0)
        return lgrMax;

    float l_L = 0.0;
    for(int j = 0; j < nb; j++)
    {
        l_L += Li(tableaux_l.at(j));
    }

    if(pere.estUnTGBT())
    {
        if(m_installation->ExtensionDefinie())
        {
            l_L += (ESPACE + Composant(Composant::t_Extension).longueur()/2.0
                   + Composant(Composant::Disjoncteur).longueur()/2.0) * m_scale;
        }
    }

    int k = nb - 1;

    l_L += ESPACE * m_scale * k;

    if(lgrMax < l_L)
        lgrMax = l_L;

    float somLgri = 0.0;
    for(int i = 0; i < nb; i++)
    {
        somLgri += largeurDeSousInstallation(tableaux_l.at(i));
    }

    somLgri += ESPACE * m_scale * k;

    if(somLgri > lgrMax)
        lgrMax = somLgri;

    return lgrMax;
}

QList<float> InstallationGraphique::espacementFils(const Tableau &t)
{
    QList<float> lesp;

    QList<Tableau> l_tableaux;
    l_tableaux << t.tableauxFils();

    int nb = l_tableaux.count();
    if((nb == 0)||(nb == 1))
        return lesp; // liste vide

    float esp2 =  largeurDeSousInstallation(l_tableaux.at(0)) - Li(l_tableaux.at(0)); // pondéré
    if(esp2 < 0) esp2 = 0;
    float esp1;

    for(int i = 1; i < nb; i++)
    {
        esp1 = esp2;
        esp2 =  largeurDeSousInstallation(l_tableaux.at(i)) - Li(l_tableaux.at(i)); // pondéré
        if(esp2 < 0)esp2 = 0;

        lesp << (esp2 + esp1)/2.0 + ESPACE * m_scale;
    }

    if(m_installation->ExtensionDefinie())
    {
        if(t.estUnTGBT())
        {
            lesp << (ESPACE + Composant(Composant::t_TGBT).longueur()/2.0
                    - Composant(Composant::Disjoncteur).longueur()/2.0) * m_scale;
        }
    }

    return lesp;
}

void InstallationGraphique::connecter(Composant *pere, Composant *fils)
{
    Cable * cable = new Cable(m_scene);
    m_scene->addItem(cable);
    cable->connecter(pere, fils);
}

void InstallationGraphique::connecter(Composant *pere, GroupeDeComposants fils, float espacement)
{
    Cable * cable = new Cable(m_scene);
    m_scene->addItem(cable);
    cable->connecter(pere, fils, espacement);
}

void InstallationGraphique::connecter(Composant *pere, GroupeDeComposants fils, QList<float>espacements)
{
    Cable * cable = new Cable(m_scene);
    m_scene->addItem(cable);
    cable->connecter(pere, fils,espacements);
}
