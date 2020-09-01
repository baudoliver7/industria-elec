#include "EvPuissMethod1.h"
#include "ui_EvPuissMethod1.h"

#include <QDebug>

bool EvPuissMethod1::m_bdChoixRecepteurConnectee = false;

EvPuissMethod1::EvPuissMethod1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EvPuissMethod1)
{
    ui->setupUi(this);

    // trouver le repertoire des bds
    QStringList env = QProcess::systemEnvironment();
    int i = 0;
    while(!(env.at(i).contains("Common Files")||env.at(i).contains("Fichiers communs")))
    {
        i++;
    }
    QString cf32 = QDir::fromNativeSeparators(QString(env.at(i)).split("=").last());
    m_dirBD = cf32 + "/Industria Elec/data";

    initialiserTGBT();
    initialiserGraphisme();

    // enregistrer l'état en cours
    m_sauvegardes << *m_installation;
    m_indexSauvegardeEnCours = 0;

    afficherTout();

    m_bdLocauxConnectee = false;
    connect(this, SIGNAL(etatChanged()), this, SLOT(sauvegarderEtat()));

    // la base de données catalogue
    seConnecterABDChoixRecepteur();

    // afficher manuellement quelques événements
    //Composant * C1 = m_driverGraphicsView->afficher(cstes::t_Moteur, "M1", 10, 10);
    //C1->setFlag(QGraphicsItem::ItemIsMovable);
}

EvPuissMethod1::~EvPuissMethod1()
{
    delete ui;    

    fermerBDLocaux();
    fermerBDChoixRecepteur();
}

void EvPuissMethod1::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void EvPuissMethod1::closeEvent(QCloseEvent *e)
{
    if(!sauvegarder())
    {
        e->ignore();
    }else
    {
        //fermerBDLocaux();
        //fermerBDChoixRecepteur();
        emit closed();
        e->accept();
    }
}

void EvPuissMethod1::initialiserTGBT()
{
    m_installation = new Installation("Mon Installation", *(new Tableau(Tableau::TGBT, 1.0, "TGBT")));
}

QList<Tableau> EvPuissMethod1::tableaux() const
{
    return m_installation->tableaux(true);
}

QList<Recepteur> EvPuissMethod1::recepteurs()const
{
    return m_installation->recepteurs(true);
}

void EvPuissMethod1::initialiserGraphisme()
{
    m_driverGraphicsView = new InstallationGraphicDriver(ui->graphicsView, m_installation);    

    connect(m_driverGraphicsView, SIGNAL(creerNouveauTableau(QString,Tableau::TypeDeTableau,int)),
            this, SLOT(creerDesNouveauxTableaux(QString,Tableau::TypeDeTableau,int)));

    connect(m_driverGraphicsView, SIGNAL(editerTableau(QString)),
            this, SLOT(editerUnTableau(QString)));

    connect(m_driverGraphicsView, SIGNAL(supprimerTableau(QString)),
            this, SLOT(supprimerUnTableau(QString)));

    connect(m_driverGraphicsView, SIGNAL(creerNouveauRecepteur(QString,int)),
            this, SLOT(creerDesNouveauxRecepteurs(QString, int)));

    connect(m_driverGraphicsView, SIGNAL(editerRecepteur(QString)),
            this, SLOT(editerUnRecepteur(QString)));

    connect(m_driverGraphicsView, SIGNAL(supprimerRecepteur(QString)),
            this, SLOT(supprimerUnRecepteur(QString)));

    connect(m_driverGraphicsView, SIGNAL(creerNouveauLocal(QString,int)),
            this, SLOT(creerDesNouveauxLocaux(QString, int)));

    connect(m_driverGraphicsView, SIGNAL(editerLocal(QString)),
            this, SLOT(editerUnLocal(QString)));

    connect(m_driverGraphicsView, SIGNAL(supprimerLocal(QString)),
            this, SLOT(supprimerUnLocal(QString)));
}

void EvPuissMethod1::editerUnTableau(const QString &designation)
{
    if(m_installation->possedeUnTableauConnecte(designation))
    {
        Tableau t = m_installation->tableauConnecte(designation);
    
        BDFormulaireDeTableau formulaire (this
                                          ,tr("Editer %1").arg(t.designation())
                                          ,m_installation
                                          ,t.designationDuParent()
                                          ,t.typeDeTableau()
                                          ,true // éditer
                                          ,t);
        if((formulaire.exec() == QDialog::Accepted)
                && formulaire.isModified())
            {
                afficherTout();

                // indiquer qu'une modification a eu lieu
                setWindowModified(true);
                emit etatChanged();
                emit windowIsModified(true);
            }
    }
}

void EvPuissMethod1::supprimerUnTableau(const QString &designation)
{
    // on peut supprimer un tableau déconnecté par coupure
    if(m_installation->possedeUnTableau(designation))
    {
        if(QMessageBox::question(this, "Suppression d'un tableau"
                                 ,tr("Désirez-vous supprimer %1 ?").arg(designation)
                                 ,"Oui"
                                 ,"Non") == 0)
        {
            m_installation->desinstallerUnTableau(designation);
            afficherTout();

            // indiquer qu'une modification a eu lieu
            setWindowModified(true);
            emit etatChanged();
            windowIsModified(true);

        }
    }
}

bool EvPuissMethod1::creerUnNouveauTableau(QString title, QString designationParent, Tableau::TypeDeTableau type)
{
    BDFormulaireDeTableau formulaire (this
                                      ,title
                                      ,m_installation
                                      ,designationParent
                                      ,type);

    return (formulaire.exec() == QDialog::Accepted);
}

void EvPuissMethod1::creerDirectUnNouveauTableau(QString designationParent, Tableau::TypeDeTableau type)
{
    /*QMessageBox::information(this, "tableau", designationParent);
    return;*/

    // chercher un nom de tableau unique
    QString designation;
    int id = 0;

    do
    {
        id++;

        if(type == Tableau::TableauSecondaire)
        {
            designation = "TS " + QString::number(id);
        }else
        {
            if(type == Tableau::CoffretDivisionnaire)
            {
                designation = "TD " + QString::number(id);
            }else
            {
                if(type == Tableau::Terminal)
                {
                    designation = "TER " + QString::number(id);
                }
            }
        }
    }while(m_installation->possedeUnTableau(designation));

    // créer un tableau par défaut
    Tableau tableau(type, 1.0, designation);

    // installer le tableau
    m_installation->installerUnTableau(tableau, designationParent);

    // actualiser l'affichage
    afficherTout();

    // indiquer qu'une modification a eu lieu
    emit etatChanged();
    setWindowModified(true);
    emit windowIsModified(true);

    // sélectionner le composant parent pour favoriser un autre ajout
    m_driverGraphicsView->selectionnerUnComposant(designationParent);
}

void EvPuissMethod1::creerDirectUnNouveauRecepteur(QString designationParent, Recepteur::TypeDeRecepteur type)
{
    /*QMessageBox::information(this, "tableau", designationParent);
    return;*/

    // chercher un nom de tableau unique
    QString designation;
    int id = 0;

    do
    {
        id++;
        designation = tr("récepteur %1").arg(id);
    }while(m_installation->possedeUnRecepteur(designation));

    // créer un récepteur par défaut
    Recepteur recepteur;
    recepteur.setDesignation(designation);
    recepteur.setTypeDeRecepteur(type);
    recepteur.setKUParDefaut();

    // installer un récepteur
    m_installation->installerUnRecepteur(recepteur, designationParent);

    // actualiser l'affichage
    afficherTout();

    // indiquer qu'une modification a eu lieu
    emit etatChanged();
    setWindowModified(true);
    emit windowIsModified(true);

    // sélectionner le composant parent pour favoriser un autre ajout
    m_driverGraphicsView->selectionnerUnComposant(designationParent);
}

void EvPuissMethod1::creerDesNouveauxTableaux(const QString &designationParent, Tableau::TypeDeTableau type, int nombre)
{
    if(nombre == 0)
    {
        DialogNbDeElement dbNbDeElement(this, "Autre nombre...",6);
        if(dbNbDeElement.exec() == DialogNbDeElement::Accepted)
        {
            nombre = dbNbDeElement.nombre();
        }
    }

    QString parent = designationParent;

    for(int i = 1; i <= nombre; i++)
    {
        QString title = tr("%1 tableau %2 / %3").arg(designationParent).arg(i).arg(nombre);
        if(!creerUnNouveauTableau(title, parent, type))
        {
            return;
        }

        afficherTout();

        // indiquer qu'une modification a eu lieu
        emit etatChanged();
        setWindowModified(true);
        emit windowIsModified(true);
    }
}

Installation * EvPuissMethod1::installation()
{
    return m_installation;
}

void EvPuissMethod1::afficherTout()
{
    // afficher le graphe
    m_driverGraphicsView->afficher();
}

void EvPuissMethod1::setInstallation(const Installation &i)
{
    *m_installation = i;
    afficherTout();
}

void EvPuissMethod1::agrandirInstallationGraphic()
{
    m_driverGraphicsView->agrandir();
}

void EvPuissMethod1::reduireInstallationGraphic()
{
    m_driverGraphicsView->reduire();
}

bool EvPuissMethod1::creerUnNouveauRecepteur(QString title, QString designationParent)
{
    BDFormulaireDeRecepteur formulaire (this
                                        ,BD_RECEPTEUR_NAME
                                        ,title
                                        ,m_installation
                                        ,designationParent
                                        ,false // on n'édite pas
                                        );
    return (formulaire.exec() == BDFormulaireDeRecepteur::Accepted);
}

void EvPuissMethod1::creerDesNouveauxRecepteurs(const QString &designationParent, int nombre)
{
    if(nombre == 0)
    {
        DialogNbDeElement dbNbDeElement(this, "Autre nombre...",6);
        if(dbNbDeElement.exec() == DialogNbDeElement::Accepted)
        {
            nombre = dbNbDeElement.nombre();
        }
    }

    QString parent = designationParent;

    for(int i = 1; i <= nombre; i++)
    {
        QString title = tr("%1 - nouveau récepteur %2 / %3").arg(designationParent).arg(i).arg(nombre);
        if(!creerUnNouveauRecepteur(title, parent))
        {
            return;
        }

        afficherTout();

        // indiquer qu'une modification a eu lieu
        emit etatChanged();
        setWindowModified(true);
        emit windowIsModified(true);
    }
}

void EvPuissMethod1::supprimerUnRecepteur(const QString &designation)
{
    // peut être déconnecté par une coupure
    if(m_installation->possedeUnRecepteur(designation))
    {
        QString message = tr("Désirez-vous supprimer %1 ?").arg(designation);
        if(QMessageBox::question(this, "Suppression d'un récepteur", message,
                                 "Oui", "Non") == 0)
        {
            m_installation->desinstallerUnRecepteur(designation);
            afficherTout();

            // indiquer qu'une modification a eu lieu
            emit etatChanged();
            setWindowModified(true);
        }
    }
}

void EvPuissMethod1::supprimerUnLocal(const QString &designation)
{
    // peut être déconnecté par une coupure
    if(m_installation->possedeUnLocal(designation))
    {
        QString message = tr("Désirez-vous supprimer %1 ?").arg(designation);
        if(QMessageBox::question(this, "Suppression d'un local", message,
                                 "Oui", "Non") == 0)
        {
            m_installation->desinstallerUnLocal(designation);
            afficherTout();

            // indiquer qu'une modification a eu lieu
            emit etatChanged();
            setWindowModified(true);
        }
    }
}

void EvPuissMethod1::editerUnRecepteur(const QString &designation)
{
    if(m_installation->possedeUnRecepteurConnecte(designation))
    {
        Recepteur r = m_installation->recepteurConnecte(designation);

        BDFormulaireDeRecepteur formulaire (this
                                            ,BD_RECEPTEUR_NAME
                                            ,tr("Editer %1").arg(r.designation())
                                            ,m_installation
                                            ,r.designationDuParent()
                                            ,true // on n'édite
                                            ,r);
        if((formulaire.exec() == BDFormulaireDeRecepteur::Accepted)
            && formulaire.isModified())
            {
                afficherTout();

                // indiquer qu'une modification a eu lieu
                emit etatChanged();
                setWindowModified(true);
                emit windowIsModified(true);
            }
    }
}

void EvPuissMethod1::dupliquerSousInstallation(QString pere, QString sousPere)
{
    if(m_installation->possedeUnTableauConnecte(sousPere))
    {
        dupliquerUnTableau(pere, sousPere);
    }else
    {
        if(m_installation->possedeUnLocalConnecte(sousPere))
        {
            dupliquerUnLocal(pere, sousPere);
        }else
        {
            dupliquerUnRecepteur(pere, sousPere);
        }
    }

    // indiquer qu'une modification a eu lieu
    emit etatChanged();
    setWindowModified(true);
}

bool EvPuissMethod1::debrancherUnComposant(QString element)
{
    if(!m_installation->debrancherUnTableau(element))
    {
        if(!m_installation->debrancherUnLocal(element))
        {
            // debrancher un récepteur. le faire seul
            if(!m_installation->debrancherUnRecepteur(element))
            {
                return false;
            }
        }
    }

    afficherTout();

    // indiquer qu'une modification a eu lieu
    emit etatChanged();
    setWindowModified(true);

    return true;
}

bool EvPuissMethod1::brancherUnComposant(QString element, QString pere)
{
    if(!m_installation->brancherUnTableau(element, pere))
    {
        if(!m_installation->brancherUnLocal(element, pere))
        {
            // debrancher un récepteur. le faire seul
            if(!m_installation->brancherUnRecepteur(element, pere))
            {
                return false;
            }
        }
    }

    afficherTout();

    // indiquer qu'une modification a eu lieu
    emit etatChanged();
    setWindowModified(true);

    return true;
}

void EvPuissMethod1::supprimerUnComposant(QString element)
{
    // on peut supprimer un élément déconnecté par une coupure

    if(m_installation->possedeUnRecepteur(element))
    {
        supprimerUnRecepteur(element);
    }else
    {
        if(m_installation->possedeUnLocal(element))
        {
            supprimerUnLocal(element);
        }else
        {
            supprimerUnTableau(element);
        }

    }

    // indiquer qu'une modification a eu lieu
    emit etatChanged();
    setWindowModified(true);
}

void EvPuissMethod1::dupliquerUnRecepteur(QString pere, QString designation)
{
    Recepteur r = m_installation->recepteurConnecte(designation);
        r.setDesignation(designationDupliquee(r.designation()));
        m_installation->installerUnRecepteur(r, pere);

    afficherTout();
}

void EvPuissMethod1::dupliquerUnLocal(QString pere, QString designation)
{
    Local r = m_installation->localConnecte(designation);
    r.setDesignation(designationDupliquee(r.designation()));
    m_installation->installerUnLocal(r, pere);

    afficherTout();
}

void EvPuissMethod1::dupliquerUnTableau(QString pere, QString designation)
{
    reconstruireSousInstallation(designation, pere); // reconstruire en dupliquant les noms

    afficherTout();
}

QString EvPuissMethod1::designationDupliquee(QString designation)
{
    supprimerFinal(designation);
    return designation + tr(" %1").arg(indexMAX(designation) + 1);
}

bool EvPuissMethod1::finalExisteDans(QString designation)
{
    QString nombre;
    if(designation.split(" ").first() != designation)
    {
        nombre = designation.split(" ").last();
    }

    bool ok;
    nombre.toInt(&ok);

    return (!nombre.isEmpty() && ok);
}

void EvPuissMethod1::supprimerFinal(QString &designation)
{
    if(finalExisteDans(designation))
    {
        QString nombre = designation.split(" ").last();
        designation.chop(nombre.length() + 1);
    }
}

void EvPuissMethod1::reconstruireSousInstallation(QString fils, QString pere)
{
    QString nomDuplique = designationDupliquee(fils);

    // c'est un tableau
    Tableau t = m_installation->tableauConnecte(fils);

    Tableau t1 = t;
    t1.supprimerAllFils();
    t1.setDesignation(nomDuplique);
    m_installation->installerUnTableau(t1, pere);

    for(int i = 0; i < t.recepteursFils().count(); i++)
    {
        Recepteur r = t.recepteursFils().at(i);
        r.setDesignation(designationDupliquee(r.designation()));
        m_installation->installerUnRecepteur(r, t1.designation());
    }

    for(int i = 0; i < t.locauxFils().count(); i++)
    {
        Local l = t.locauxFils().at(i);
        l.setDesignation(designationDupliquee(l.designation()));
        m_installation->installerUnLocal(l, t1.designation());
    }

    for(int i = 0; i < t.tableauxFils().count(); i++)
    {
        QString designation = t.tableauxFils().at(i).designation();
        reconstruireSousInstallation(designation, t1.designation());
    }

    t1.setKs(t.ks());
}

void EvPuissMethod1::editerUnComposant(QString element)
{
    if(m_installation->possedeUnRecepteur(element))
    {
        editerUnRecepteur(element);
    }else
    {
        editerUnTableau(element);
    }
}

void EvPuissMethod1::creerDirectUnNouveauLocal(QString designationParent)
{
    /*QMessageBox::information(this, "tableau", designationParent);
    return;*/

    // chercher un nom de tableau unique
    QString designation;
    int id = 0;

    do
    {
        id++;
        designation = tr("local %1").arg(id);
    }while(m_installation->possedeUnLocal(designation));

    // créer un local par défaut
    Local local = Local(designation
                    ,Local::EclairageFluo
                    ,QString()
                    ,0
                    ,Local::KW);

    // installer un local
    m_installation->installerUnLocal(local, designationParent);

    // actualiser l'affichage
    afficherTout();

    // indiquer qu'une modification a eu lieu
    emit etatChanged();
    setWindowModified(true);
    emit windowIsModified(true);

    // sélectionner le composant parent pour favoriser un autre ajout
    m_driverGraphicsView->selectionnerUnComposant(designationParent);
}

bool EvPuissMethod1::creerUnNouveauLocal(QString title, QString designationParent)
{
    BDFormulaireDeLocal formulaire(this
                                   ,title
                                   ,m_installation
                                   ,designationParent
                                   ,false // on n'édite pas
                                   );

    return (formulaire.exec() == BDFormulaireDeLocal::Accepted);
}

void EvPuissMethod1::creerDesNouveauxLocaux(QString designationParent, int nombre)
{
    if(!m_bdLocauxConnectee)
    {
        seConnecterABDLocaux();
    }

    if(m_bdLocauxConnectee)
    {
        if(nombre == 0)
        {
            DialogNbDeElement dbNbDeElement(this, "Autre nombre...",6);
            if(dbNbDeElement.exec() == DialogNbDeElement::Accepted)
            {
                nombre = dbNbDeElement.nombre();
            }
        }

        for(int i = 1; i <= nombre; i++)
        {
            QString title = tr("%1 - nouveau local %2 / %3").arg(designationParent).arg(i).arg(nombre);
            if(!creerUnNouveauLocal(title, designationParent))
            {
                return;
            }

            afficherTout();

            // indiquer qu'une modification a eu lieu
            emit etatChanged();
            setWindowModified(true);
            emit windowIsModified(true);
        }
    }
}

void EvPuissMethod1::editerUnLocal(QString designation)
{
    if(!m_bdLocauxConnectee)
    {
        seConnecterABDLocaux();
    }

    if(m_bdLocauxConnectee && m_installation->possedeUnLocalConnecte(designation))
    {
        Local l = m_installation->localConnecte(designation);

        BDFormulaireDeLocal formulaire (this
                                        ,tr("Editer %1").arg(l.designation())
                                        ,m_installation
                                        ,l.designationDuParent()
                                        ,true // on édite
                                        ,l
                                        );

        if(formulaire.exec() == BDFormulaireDeLocal::Accepted)
        {
            afficherTout();

            // indiquer qu'une modification a eu lieu
            emit etatChanged();
            setWindowModified(true);
            emit windowIsModified(true);
        }
    }
}

bool EvPuissMethod1::seConnecterABDLocaux()
{
    // connection
    QString chemin = tr("%1/puissance_estimee.mdb").arg(m_dirBD);
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", BD_PUISSANCE_ESTIMEE_NAME);
    db.setDatabaseName(tr("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=%1").arg(chemin));
    db.setPassword("aigleroyal7");

    m_bdLocauxConnectee = db.open();
    if(!m_bdLocauxConnectee)
    {
        QMessageBox::warning(this, "Base de données indisponible", QObject::tr("La base de données des puissances estimées est indisponible! : %1").arg(db.lastError().text()));
    }

    return m_bdLocauxConnectee;
}

void EvPuissMethod1::fermerBDLocaux()
{
    if(m_bdLocauxConnectee)
    {
        QSqlDatabase::database(BD_PUISSANCE_ESTIMEE_NAME).close();
        QSqlDatabase::removeDatabase(BD_PUISSANCE_ESTIMEE_NAME);
        m_bdLocauxConnectee = false;
    }

}

void EvPuissMethod1::setFichierEnCours(const QString &fileName)
{
    m_curFile = QFileInfo(fileName).canonicalFilePath();
    m_isUntitled = false;

    setWindowModified(false);
    setWindowTitle(userFriendlyCurrentFile() + "[*]");

    emit windowIsModified(false);
}

QString EvPuissMethod1::userFriendlyCurrentFile()
{
    return strippedName(m_curFile);
}

QString EvPuissMethod1::strippedName(const QString &fullFileName)
{
    return  QFileInfo(fullFileName).fileName();
}

QStringList EvPuissMethod1::donnees()const
{
    // sauvegarder l'installation
    return m_installation->infosDeInstallation();
}

bool EvPuissMethod1::setDonnees(QStringList data)
{
    Installation * i = Installation::infosToInstallation(data);

    if(i)
    {
        setInstallation(*i);

        // enregistrer l'état en cours
        m_sauvegardes.clear();
        m_sauvegardes << *m_installation;
        m_indexSauvegardeEnCours = 0;
        return true;
    }else
        return false;
}

void EvPuissMethod1::allerEnArriere()
{    
    m_indexSauvegardeEnCours--;
    this->setInstallation(m_sauvegardes.at(m_indexSauvegardeEnCours));

    if(m_indexSauvegardeEnCours  == 0)
        emit enableAllerEnArriere(false);

    emit enableAllerEnAvant(true);
}

void EvPuissMethod1::nouveauFichier()
{
    static int sequenceNumber = 1;

    m_isUntitled = true;
    m_curFile = tr("document%1.ieu").arg(sequenceNumber++);
    setWindowTitle(m_curFile + "[*]");
}

bool EvPuissMethod1::enregistrerSous(const QString &repertoire)
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Enregistrer Sous"),
                                                    repertoire,tr("Documents Industria Elec 2012(*.ieu)"));
    if (fileName.isEmpty())
        return false;

    return enregistrerFichier(fileName);
}

bool EvPuissMethod1::enregistrer(const QString &repertoire)
{
    if (m_isUntitled) {
        return enregistrerSous(repertoire);
    } else {
        return enregistrerFichier(m_curFile);
    }
}

bool EvPuissMethod1::enregistrerFichier(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, tr("Industria Elec 2012"),
                             tr("Ne peut enregistrer le fichier %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QDataStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << donnees();
    QApplication::restoreOverrideCursor();

    setFichierEnCours(fileName);
    return true;
}

bool EvPuissMethod1::chargerFichier(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text))
        return false;

    QDataStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    QStringList d;
    in >> d;

    if(!this->setDonnees(d))
    {
        QApplication::restoreOverrideCursor();
        return false;
    }

    QApplication::restoreOverrideCursor();

    setFichierEnCours(fileName);

    return true;
}

bool EvPuissMethod1::fermer()
{
    if(sauvegarder())
    {
        fermerBDLocaux();
        fermerBDChoixRecepteur();
        close();
        return true;
    }else
    {
        return false;
    }
}

bool EvPuissMethod1::sauvegarder()
{
    if(isWindowModified())
    {
        int sortie = QMessageBox::warning(this, "Enregistrer le fichier en cours"
                             ,"Désirez-vous enregistrer les dernières modifications apportées?", "Oui", "Non", "Annuler");
        switch(sortie)
        {
        case 0:
            return enregistrer(m_curFile);
            break;
        case 1:
            setWindowModified(false); // pour encourager la ferméture
            return true; // sans enregistrer
            break;
        case 2:
            return false; // annuler la ferméture
            break;
        default:
            return false; // annuler la ferméture
        }
    }

    return true; // déjà  sauvegardé
}

QString EvPuissMethod1::getFullFileName()
{
    return m_curFile;
}

void EvPuissMethod1::allerEnAvant()
{
    m_indexSauvegardeEnCours++; // positionner sur une autre sauvegarde
    this->setInstallation(m_sauvegardes.at(m_indexSauvegardeEnCours));

    if(m_indexSauvegardeEnCours  == m_sauvegardes.count() - 1)
        emit enableAllerEnAvant(false);

    emit enableAllerEnArriere(true);
}

void EvPuissMethod1::sauvegarderEtat()
{
    // supprimer les sauvegardes venant après index en cours
    QList<Installation> installations;
    installations << m_sauvegardes;
    m_sauvegardes.clear();

    for(int i = 0; i <= m_indexSauvegardeEnCours; i++)
    {
        m_sauvegardes << installations.at(i);
    }

    // supprimer la première sauvegarde si on a atteint nb max
    if(m_sauvegardes.size() == NBMAX_SAUVEGARDE)
    {
        m_sauvegardes.removeFirst();
        m_indexSauvegardeEnCours--;
    }

    // enregistrer l'état en cours
    m_sauvegardes << *m_installation;
    m_indexSauvegardeEnCours = m_sauvegardes.count() - 1;

    emit enableAllerEnAvant(false);
    emit enableAllerEnArriere(true);
}

int EvPuissMethod1::indexMAX(QString initial)
{
    int i = 0;
    QString designation = initial;

    do
    {
        i++;
        supprimerFinal(designation);
        designation += tr(" %1").arg(i);
    }while( m_installation->possedeUnComposant(designation));

    return (i - 1);
}

bool EvPuissMethod1::seConnecterABDChoixRecepteur()
{
    // connection
    QString chemin = tr("%1/catalogue_de_recepteurs.mdb").arg(m_dirBD);
    QSqlDatabase dbChoixRecepteur = QSqlDatabase::addDatabase("QODBC", BD_RECEPTEUR_NAME);
    dbChoixRecepteur.setDatabaseName(tr("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=%1").arg(chemin));
    dbChoixRecepteur.setPassword("aigleroyal7");

    m_bdChoixRecepteurConnectee = dbChoixRecepteur.open();
    if(!m_bdChoixRecepteurConnectee)
    {
        QMessageBox::warning(this, "Base de données indisponible", QObject::tr("La base de données du catalogue des matériels est indisponible! : %1").arg(dbChoixRecepteur.lastError().text()));
    }

    return m_bdChoixRecepteurConnectee;
}

void EvPuissMethod1::fermerBDChoixRecepteur()
{
    if(m_bdChoixRecepteurConnectee)
    {
        QSqlDatabase::database(BD_RECEPTEUR_NAME).close();
        QSqlDatabase::removeDatabase(BD_RECEPTEUR_NAME);
        m_bdChoixRecepteurConnectee = false;
    }
}
