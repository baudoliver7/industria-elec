#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPrintDialog>
#include <QDialog>
#include <exception>

#include "armoiredatasource.h"
#include "filsdatasource.h"
#include "ncreportprinteroutput.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_elementACopier = QString();
    m_elementSelectionne = QString();

    QSettings settings("AIGLEROYAL7", "Industria Elec");
    m_repertoirePrecedent = settings.value("repertoire précédent").toString();

    if(m_repertoirePrecedent.isEmpty())
    {
        m_repertoirePrecedent = "/home";
    }

    initialiserEtatsBtns();
    connect(ui->actionProprietesDesCpts, SIGNAL(toggled(bool)), this, SLOT(afficherBDProprietes(bool)));

    newFrmAccueil();

    NCReport report(this);
}

MainWindow::~MainWindow()
{
    delete ui;

    QSettings settings("AIGLEROYAL7", "Industria Elec");
    settings.setValue("repertoire précédent", m_repertoirePrecedent);
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void  MainWindow::closeEvent(QCloseEvent * e)
{
    if(activeMdiBilanDePuissanceMethod1())
    {
        if(activeMdiBilanDePuissanceMethod1()->fermer())
        {
            e->accept();
            return;
        }else
        {
            e->ignore();
            return;
        }
    }else
    {
        if(activeMdiBilanDePuissanceMethod2())
        {
            if(activeMdiBilanDePuissanceMethod2()->fermer())
            {
                e->accept();
                return;
            }else
            {
                e->ignore();
                return;
            }
        }
    }

    e->accept();
}

void MainWindow::afficherBDProprietes(bool afficher)
{
    if(afficher)
    {
        m_bdProprietesDesCpts = new BDProprietesDesCpts(activeMdiBilanDePuissanceMethod1()->installation(), this);

        m_bdProprietesDesCpts->setWindowTitle("Propriétés");
        m_bdProprietesDesCpts->setWindowModality(Qt::NonModal);

        connect(m_bdProprietesDesCpts, SIGNAL(finished(int)),this, SLOT(fermerBDProprietes()));
        connect(activeMdiBilanDePuissanceMethod1()->driverGraphics(), SIGNAL(itemIsSelected(bool,QString))
                , m_bdProprietesDesCpts, SLOT(afficherProprietes(bool,QString)));

        m_bdProprietesDesCpts->show();
    }else
    {
        // fermer
        fermerBDProprietes();
    }
}

void MainWindow::fermerBDProprietes()
{
    if(ui->actionProprietesDesCpts->isChecked())
    {
        m_bdProprietesDesCpts->close();
        ui->actionProprietesDesCpts->setChecked(false);
    }
}

void MainWindow::newMdiBilanDePuissanceMethod1()
{
    m_evPuissMethod1 = creerMdiEvPuissMethod1();

    m_evPuissMethod1->nouveauFichier();
    m_evPuissMethod1->showMaximized();
}

EvPuissMethod1 * MainWindow::creerMdiEvPuissMethod1()
{
    EvPuissMethod1 * mdi = new EvPuissMethod1(this);

    connect(this, SIGNAL(agrandir()), mdi, SLOT(agrandirInstallationGraphic()));
    connect(this, SIGNAL(reduire()), mdi, SLOT(reduireInstallationGraphic()));

    connect(this, SIGNAL(creerUnTableau(QString,Tableau::TypeDeTableau)), mdi,
            SLOT(creerDirectUnNouveauTableau(QString,Tableau::TypeDeTableau)));

    connect(this, SIGNAL(creerUnRecepteur(QString,Recepteur::TypeDeRecepteur)), mdi,
            SLOT(creerDirectUnNouveauRecepteur(QString,Recepteur::TypeDeRecepteur)));

    connect(this, SIGNAL(creerUnLocal(QString)), mdi,
            SLOT(creerDirectUnNouveauLocal(QString)));

    connect(mdi->driverGraphics(), SIGNAL(itemIsSelected(bool, QString))
            , this, SLOT(updateEtatsBtns(bool,QString)));

    connect(mdi->driverGraphics(), SIGNAL(itemIsSelected(bool, QString))
            , this, SLOT(disabledEtatsActionCpts(bool)));

    connect(mdi->driverGraphics(), SIGNAL(collerItem(QString))
            , this, SLOT(on_actionColler_triggered()));

    connect(mdi->driverGraphics(), SIGNAL(copierItem(QString))
            , this, SLOT(on_actionCopier_triggered()));

    connect(mdi->driverGraphics(), SIGNAL(couperItem(QString))
            , this, SLOT(on_actionCouper_triggered()));

    connect(mdi->driverGraphics(), SIGNAL(editerTransfo())
            , this, SLOT(on_actionD_finir_extension_triggered()));

    connect(mdi, SIGNAL(enableAllerEnArriere(bool))
            , this, SLOT(setEnabledAllerEnArriere(bool)));

    connect(mdi, SIGNAL(enableAllerEnAvant(bool))
            , this, SLOT(setEnabledAllerEnAvant(bool)));
    connect(mdi->driverGraphics(), SIGNAL(clickSurRecepteur()), this, SLOT(updateEtatsActionCptsRecepteur()));
    connect(mdi->driverGraphics(), SIGNAL(clickSurTableauDiv()), this, SLOT(updateEtatsActionCptsTD()));
    connect(mdi->driverGraphics(), SIGNAL(clickSurTableauSec()), this, SLOT(updateEtatsActionCptsTS()));
    connect(mdi->driverGraphics(), SIGNAL(clickSurTableauTer()), this, SLOT(updateEtatsActionCptsTer()));
    connect(mdi->driverGraphics(), SIGNAL(clickSurTransfo()), this, SLOT(updateEtatsActionTransfo()));
    connect(mdi->driverGraphics(), SIGNAL(clickSurTGBT()), this, SLOT(updateEtatsActionCptsTGBT()));

    connect(mdi, SIGNAL(closed()), this, SLOT(fermerBDProprietes()));
    connect(mdi, SIGNAL(closed()), this, SLOT(initialiserEtatsBtns()));


    connect(mdi, SIGNAL(windowIsModified(bool)), ui->actionEnregistrer, SLOT(setEnabled(bool)));
    ui->actionProprietesDesCpts->setEnabled(true);
    ui->actionZoomMoins->setEnabled(true);
    ui->actionZoomPlus->setEnabled(true);    
    ui->actionMethodeIndustrielle->setEnabled(false);
    ui->actionMethodeUsuelle->setEnabled(false);
    ui->actionPage_demarrage->setEnabled(false);

    ui->actionFermerFichierEnCours->setEnabled(true);
    ui->actionOuvrirUnFichier->setEnabled(false);
    ui->actionImprimerInstallation->setEnabled(true);
    ui->actionApercu_avant_impression->setEnabled(true);

    ui->actionEnregistrer->setEnabled(false);
    ui->actionEnregistrerSous->setEnabled(true);
    ui->actionD_finir_extension->setEnabled(true);

    ui->actionTransformateur->setEnabled(false);
    ui->actionTGBT->setEnabled(false);
    ui->actionTableau_secondaire->setEnabled(false);
    ui->actionTableau_divisionnaire->setEnabled(false);
    ui->actionTerminal->setEnabled(false);
    ui->actionRecepteur_simple->setEnabled(false);
    ui->actionEclairage->setEnabled(false);
    ui->actionChauffage->setEnabled(false);
    ui->actionConditionneur_air->setEnabled(false);
    ui->actionForce_motrice->setEnabled(false);
    ui->actionPrise_de_courant->setEnabled(false);
    ui->actionLocal->setEnabled(false);
    ui->actionFleche->setEnabled(false);
    ui->actionCable->setEnabled(false);
    ui->actionGomme->setEnabled(false);

    ui->mdiArea->addSubWindow(mdi);
    m_FenMethod1Affichee = true;
    return mdi;
}

EvPuissMethod2 * MainWindow::creerMdiEvPuissMethod2()
{
    EvPuissMethod2 * mdi = new EvPuissMethod2(this);

    connect(mdi, SIGNAL(windowIsModified(bool)), ui->actionEnregistrer, SLOT(setEnabled(bool)));
    connect(mdi, SIGNAL(closed()), this, SLOT(initialiserEtatsBtns()));

    ui->actionProprietesDesCpts->setEnabled(false);
    ui->actionZoomMoins->setEnabled(false);
    ui->actionZoomPlus->setEnabled(false);    
    ui->actionPage_demarrage->setEnabled(false);
    ui->actionMethodeIndustrielle->setEnabled(false);
    ui->actionMethodeUsuelle->setEnabled(false);

    ui->actionFermerFichierEnCours->setEnabled(true);
    ui->actionOuvrirUnFichier->setEnabled(false);
    ui->actionImprimerInstallation->setEnabled(true);
    ui->actionImprimerInstallation->setVisible(false);
    ui->actionApercu_avant_impression->setEnabled(true);

    ui->actionEnregistrer->setEnabled(false);
    ui->actionEnregistrerSous->setEnabled(true);
    ui->actionD_finir_extension->setEnabled(true);

    ui->mdiArea->addSubWindow(mdi);
    m_FenMethod1Affichee = false;
    return mdi;
}

QString MainWindow::repertoireDuFichier(QString fileName)
{
    QString repertoire;
    if(m_FenMethod1Affichee)
    {
        repertoire = activeMdiBilanDePuissanceMethod1()
                             ->currentFile()
                             .remove(QFileInfo(fileName).fileName());
    }else
    {
        repertoire = activeMdiBilanDePuissanceMethod2()
                             ->currentFile()
                             .remove(QFileInfo(fileName).fileName());
    }


    return repertoire;
}

EvPuissMethod1 * MainWindow::activeMdiBilanDePuissanceMethod1()
{
    if(ui->mdiArea->activeSubWindow())
    {
        return qobject_cast<EvPuissMethod1 *>(ui->mdiArea->activeSubWindow()->widget());
    }

    return 0;
}

EvPuissMethod2 * MainWindow::activeMdiBilanDePuissanceMethod2()
{
    if(ui->mdiArea->activeSubWindow())
    {
        return qobject_cast<EvPuissMethod2 *>(ui->mdiArea->activeSubWindow()->widget());
    }

    return 0;
}

void MainWindow::initialiserEtatsBtns()
{
    ui->actionEditer->setEnabled(false);
    ui->actionCouper->setEnabled(false);
    ui->actionSupprimer->setEnabled(false);
    ui->actionColler->setEnabled(false);
    ui->actionCopier->setEnabled(false);
    ui->actionProprietesDesCpts->setEnabled(false);
    ui->actionZoomMoins->setEnabled(false);
    ui->actionZoomPlus->setEnabled(false);
    ui->actionPage_demarrage->setEnabled(true);

    ui->actionAllerEnArriere->setEnabled(false);
    ui->actionAllerEnAvant->setEnabled(false);

    ui->actionFermerFichierEnCours->setEnabled(false);
    ui->actionImprimerInstallation->setEnabled(false);
    ui->actionImprimerInstallation->setVisible(true);
    ui->actionApercu_avant_impression->setEnabled(false);

    ui->actionOuvrirUnFichier->setEnabled(true);
    ui->actionEnregistrer->setEnabled(false);
    ui->actionEnregistrerSous->setEnabled(false);
    ui->actionD_finir_extension->setEnabled(false);

    ui->actionTransformateur->setEnabled(false);
    ui->actionTGBT->setEnabled(false);
    ui->actionTableau_secondaire->setEnabled(false);
    ui->actionTableau_divisionnaire->setEnabled(false);
    ui->actionTerminal->setEnabled(false);
    ui->actionRecepteur_simple->setEnabled(false);
    ui->actionEclairage->setEnabled(false);
    ui->actionChauffage->setEnabled(false);
    ui->actionConditionneur_air->setEnabled(false);
    ui->actionForce_motrice->setEnabled(false);
    ui->actionPrise_de_courant->setEnabled(false);
    ui->actionLocal->setEnabled(false);
    ui->actionFleche->setEnabled(false);
    ui->actionCable->setEnabled(false);
    ui->actionGomme->setEnabled(false);
    ui->actionMethodeIndustrielle->setEnabled(true);
    ui->actionMethodeUsuelle->setEnabled(true);
}

void MainWindow::ouvrir()
{
    QString FilterSelecter;
    QString fileName = QFileDialog::getOpenFileName(this
                                                    , "Ouvrir un document Industria Elec 2012"
                                                    , m_repertoirePrecedent
                                                    , "Document Industria Elec (*.ieu);;Document Industria Elec (*.iei)"
                                                    , &FilterSelecter);

    if (!fileName.isEmpty())
    {
        if(FilterSelecter.contains("*.ieu"))
        {
            EvPuissMethod1 *child = this->creerMdiEvPuissMethod1();

            if (child->chargerFichier(fileName))
            {
                statusBar()->showMessage(tr("Fichier chargé!"), 2000);
                child->showMaximized();

                m_repertoirePrecedent = repertoireDuFichier(fileName);
            } else {
                QMessageBox::critical(this, "Erreur d'ouverture"
                                      , "Le fichier est corrompu!");
                fermer();
            }
        }else
        {
            EvPuissMethod2 *child = this->creerMdiEvPuissMethod2();

            if (child->chargerFichier(fileName))
            {
                statusBar()->showMessage(tr("Fichier chargé!"), 2000);
                child->showMaximized();

                m_repertoirePrecedent = repertoireDuFichier(fileName);
            } else {
                QMessageBox::critical(this, "Erreur d'ouverture"
                                      , "Le fichier est corrompu!");
                fermer();
            }
        }
    }
}

void MainWindow::fermer()
{
    if(m_FenMethod1Affichee)
    {
        if(activeMdiBilanDePuissanceMethod1() && activeMdiBilanDePuissanceMethod1()->fermer())
        {
            ui->mdiArea->closeActiveSubWindow();
            initialiserEtatsBtns();
        }
    }else
    {
        // fermer
        if(activeMdiBilanDePuissanceMethod2() && activeMdiBilanDePuissanceMethod2()->fermer())
        {
            ui->mdiArea->closeActiveSubWindow();
            initialiserEtatsBtns();
        }
    }

}

void MainWindow::enregistrer()
{
    if(m_FenMethod1Affichee)
    {
        if(activeMdiBilanDePuissanceMethod1()
            && activeMdiBilanDePuissanceMethod1()->enregistrer(m_repertoirePrecedent))
        {
            statusBar()->showMessage(tr("Fichier enregistré"), 2000);
        }
    }else
    {
        if(activeMdiBilanDePuissanceMethod2()
            && activeMdiBilanDePuissanceMethod2()->enregistrer(m_repertoirePrecedent))
        {
            statusBar()->showMessage(tr("Fichier enregistré"), 2000);
        }
    }
}

void MainWindow::enregistrerSous()
{
    if(m_FenMethod1Affichee)
    {
        if(activeMdiBilanDePuissanceMethod1()->enregistrerSous(m_repertoirePrecedent))
        {
            m_repertoirePrecedent = repertoireDuFichier(activeMdiBilanDePuissanceMethod1()->currentFile());
            statusBar()->showMessage(tr("Fichier enregistré"), 2000);
        }
    }else
    {
        // enregistrer sous
        if(activeMdiBilanDePuissanceMethod2()->enregistrerSous(m_repertoirePrecedent))
        {
            m_repertoirePrecedent = repertoireDuFichier(activeMdiBilanDePuissanceMethod2()->currentFile());
            statusBar()->showMessage(tr("Fichier enregistré"), 2000);
        }
    }
}

void MainWindow::on_actionZoomPlus_triggered()
{
    emit agrandir();
}

void MainWindow::on_actionZoomMoins_triggered()
{
    emit reduire();
}

void MainWindow::updateEtatsBtns(bool itemSelected, QString designation)
{
    m_elementSelectionne = designation;
    if(itemSelected)
    {       
        m_typeElementSelectionne = activeMdiBilanDePuissanceMethod1()->driverGraphics()->typeDeComposantEnCours();
        if(activeMdiBilanDePuissanceMethod1()->driverGraphics()->composantEnCoursEstUnTransfo())
        {
            ui->actionEditer->setEnabled(false);
        }else
        {
            ui->actionEditer->setEnabled(true);
        }

        if(activeMdiBilanDePuissanceMethod1()->driverGraphics()->composantEnCoursCopiable())
        {
            ui->actionCopier->setEnabled(true);
            ui->actionCouper->setEnabled(true);
            ui->actionSupprimer->setEnabled(true);
        }else
        {
            ui->actionCopier->setEnabled(false);
            ui->actionCouper->setEnabled(false);
            ui->actionSupprimer->setEnabled(false);
        }

        // dans le cas d'une sélection pour une copie
        if(activeMdiBilanDePuissanceMethod1()->driverGraphics()->composantACopierEstCompatible())
        {
            ui->actionColler->setEnabled(true);
        }else
        {
            ui->actionColler->setEnabled(false);
        }
    }else
    {
        m_typeElementSelectionne = QString();
        ui->actionCopier->setEnabled(false);
        ui->actionColler->setEnabled(false);
        ui->actionCouper->setEnabled(false);
        ui->actionSupprimer->setEnabled(false);
        ui->actionEditer->setEnabled(false);
    }
}

void MainWindow::preparerCopie()
{
    if(!m_copier && !m_elementACopier.isEmpty())
    {
        // coupure en cours. à  supprimer dééfinitivement
        activeMdiBilanDePuissanceMethod1()->supprimerUnComposant(m_elementACopier);
    }

    m_copier = true; // on copie
    m_elementACopier = m_elementSelectionne;
    m_typeElementAcopier = m_typeElementSelectionne;

    // passer les infos au  driver
    activeMdiBilanDePuissanceMethod1()->driverGraphics()->setElementACopier(m_elementACopier, m_typeElementAcopier);

    ui->actionColler->setEnabled(false); // pour ne pas copier un element dans lui-même
}

void MainWindow::preparerCouper()
{
    m_copier = false; // on coupe
    m_elementACopier = m_elementSelectionne;
    m_typeElementAcopier = m_typeElementSelectionne;

    // passer les infos au  driver
    activeMdiBilanDePuissanceMethod1()->driverGraphics()->setElementACopier(m_elementACopier, m_typeElementAcopier);

    // debrancher l'element à  couper
    activeMdiBilanDePuissanceMethod1()->debrancherUnComposant(m_elementACopier);

    // pas besoin d'inhiber actionColler car l'élément disparait et perd le focus
}

void MainWindow::on_actionColler_triggered()
{
    if(m_copier)
    {
        // on renomme la nouvelle copie
        activeMdiBilanDePuissanceMethod1()->dupliquerSousInstallation(m_elementSelectionne, m_elementACopier);
    }else
    {
        // on branche la nouvelle copie
        activeMdiBilanDePuissanceMethod1()->brancherUnComposant(m_elementACopier, m_elementSelectionne);
    }

    // on annule la copie en cours après une seule exécution
    m_elementACopier = QString();
    m_typeElementAcopier = QString();

    // passer les infos au  driver
    activeMdiBilanDePuissanceMethod1()->driverGraphics()->setElementACopier(m_elementACopier, m_typeElementAcopier);
}

void MainWindow::on_actionCopier_triggered()
{
    preparerCopie();
}

void MainWindow::on_actionCouper_triggered()
{
    preparerCouper();
}

void MainWindow::on_actionSupprimer_triggered()
{
    activeMdiBilanDePuissanceMethod1()->supprimerUnComposant(m_elementSelectionne);
}

void MainWindow::on_actionEditer_triggered()
{
    activeMdiBilanDePuissanceMethod1()->editerUnComposant(m_elementSelectionne);
}

void MainWindow::on_actionQuitter_triggered()
{
    close(); // pour le moment
}

void MainWindow::on_actionD_finir_extension_triggered()
{
    if(m_FenMethod1Affichee)
    {
        BDParamTransfo * bdParamTransfo = new BDParamTransfo(activeMdiBilanDePuissanceMethod1()->installation(), this);

        if((bdParamTransfo->exec() == QDialog::Accepted) && bdParamTransfo->isModified())
        {
            activeMdiBilanDePuissanceMethod1()->driverGraphics()->afficher();
        }

        delete bdParamTransfo;
    }else
    {
        BDParamTransfo * bdParamTransfo = new BDParamTransfo(activeMdiBilanDePuissanceMethod2()->transformateur(), this);

        if((bdParamTransfo->exec() == QDialog::Accepted) && bdParamTransfo->isModified())
        {
            activeMdiBilanDePuissanceMethod2()->setPptesDuTransfo(bdParamTransfo->transformateur());
        }

        delete bdParamTransfo;
    }
}

void MainWindow::on_actionAllerEnAvant_triggered()
{
    activeMdiBilanDePuissanceMethod1()->allerEnAvant();
}

void MainWindow::on_actionAllerEnArriere_triggered()
{
    activeMdiBilanDePuissanceMethod1()->allerEnArriere();
}

void MainWindow::setEnabledAllerEnArriere(bool enabled)
{
    ui->actionAllerEnArriere->setEnabled(enabled);
}

void MainWindow::setEnabledAllerEnAvant(bool enabled)
{
    ui->actionAllerEnAvant->setEnabled(enabled);
}

void MainWindow::on_actionMethodeUsuelle_triggered()
{
    newMdiBilanDePuissanceMethod1();
}

void MainWindow::on_actionFermerFichierEnCours_triggered()
{
    fermer();
}

void MainWindow::on_actionOuvrirUnFichier_triggered()
{
    ouvrir();
}

void MainWindow::on_actionEnregistrer_triggered()
{
    enregistrer();
}

void MainWindow::on_actionEnregistrerSous_triggered()
{
    enregistrerSous();
}

void MainWindow::on_actionMethodeIndustrielle_triggered()
{
    EvPuissMethod2 * mdi = creerMdiEvPuissMethod2();

    mdi->nouveauFichier();
    mdi->showMaximized();
}

void MainWindow::on_actionApropos_triggered()
{
    BDApropos * bdApropos = new BDApropos(this);
    bdApropos->exec();

    delete bdApropos;
}

void MainWindow::on_actionAideSurIndustriaElec_triggered()
{
    QString path = QApplication::applicationDirPath();
    QString chemin = tr("file:///%1/aide d'industria elec.pdf").arg(path);
    QDesktopServices::openUrl(QUrl(chemin));
}

FrmAccueil * MainWindow::initFrmAccueil()
{
    FrmAccueil * mdi = new FrmAccueil();
    mdi->setWindowTitle(tr("Page de démarrage"));

    connect(mdi, SIGNAL(createNewMI()), this, SLOT(on_actionMethodeIndustrielle_triggered()));
    connect(mdi, SIGNAL(createNewMT()), this, SLOT(on_actionMethodeUsuelle_triggered()));
    connect(mdi, SIGNAL(openProject()), this, SLOT(on_actionOuvrirUnFichier_triggered()));
    connect(mdi, SIGNAL(destroyed()), this, SLOT(terminerFrmAccueil()));

    return mdi;
}

void MainWindow::newFrmAccueil()
{
    m_frmAccueil = initFrmAccueil();

    if(m_frmAccueil)
    {
        ui->mdiArea->addSubWindow(m_frmAccueil);
        m_frmAccueil->showMaximized();
    }
}

void MainWindow::on_actionPage_demarrage_triggered()
{
    if(m_frmAccueil)
    {
        m_frmAccueil->showMaximized();
    }else
    {
        newFrmAccueil();
    }
}

void MainWindow::terminerFrmAccueil()
{
    m_frmAccueil = 0;
}

void MainWindow::changerCurseur(QString fileName)
{
    if(m_evPuissMethod1)
    {
        QPixmap pixmap = QPixmap(fileName);
        pixmap = pixmap.scaledToWidth(32);
        m_evPuissMethod1->driverGraphics()->graphicsView()->setCursor(QCursor(pixmap));
    }
}

void MainWindow::on_actionTransformateur_triggered()
{
    changerCurseur(":/images/transfo.png");
}

void MainWindow::on_actionTGBT_triggered()
{
    //changerCurseur(":/images/TGBT.png");
    emit creerUnTableau(m_elementSelectionne, Tableau::TGBT);
}

void MainWindow::on_actionTableau_divisionnaire_triggered()
{
    //changerCurseur(":/images/TD.png");
    emit creerUnTableau(m_elementSelectionne, Tableau::CoffretDivisionnaire);
}

void MainWindow::on_actionTableau_secondaire_triggered()
{
    //changerCurseur(":/images/TS.png");
    emit creerUnTableau(m_elementSelectionne, Tableau::TableauSecondaire);
}

void MainWindow::on_actionTerminal_triggered()
{
    //changerCurseur(":/images/TER.png");
    emit creerUnTableau(m_elementSelectionne, Tableau::Terminal);
}

void MainWindow::on_actionRecepteur_simple_triggered()
{
    //changerCurseur(":images/autre récepteur.png");
    emit creerUnRecepteur(m_elementSelectionne, Recepteur::AucunType);
}

void MainWindow::on_actionEclairage_triggered()
{
    //changerCurseur(":/images/eclairage.png");
    emit creerUnRecepteur(m_elementSelectionne, Recepteur::Eclairage);
}

void MainWindow::on_actionChauffage_triggered()
{
    //changerCurseur(":/images/Chauffage.png");
    emit creerUnRecepteur(m_elementSelectionne, Recepteur::Chauffage);
}

void MainWindow::on_actionConditionneur_air_triggered()
{
    //changerCurseur(":/images/climatiseur.png");
    emit creerUnRecepteur(m_elementSelectionne, Recepteur::ConditionnementAir);
}

void MainWindow::on_actionForce_motrice_triggered()
{
    //changerCurseur(":/images/moteur.png");
    emit creerUnRecepteur(m_elementSelectionne, Recepteur::ForceMotrice);
}

void MainWindow::on_actionPrise_de_courant_triggered()
{
    //changerCurseur(":/images/prise de courant.png");
    emit creerUnRecepteur(m_elementSelectionne, Recepteur::PriseDeCourant);
}

void MainWindow::on_actionLocal_triggered()
{
    //changerCurseur(":/images/Local_ecl.png");
    emit creerUnLocal(m_elementSelectionne);
}

void MainWindow::on_actionFleche_triggered()
{
    if(m_evPuissMethod1)
    {
        m_evPuissMethod1->driverGraphics()->graphicsView()->setCursor(Qt::ArrowCursor);
    }
}

void MainWindow::on_actionCable_triggered()
{
    changerCurseur(":/images/liaison.png");
}

void MainWindow::on_actionGomme_triggered()
{
    changerCurseur(":/images/gomme.png");
}

void MainWindow::updateEtatsActionCptsRecepteur()
{
    ui->actionTableau_secondaire->setEnabled(false);
    ui->actionTableau_divisionnaire->setEnabled(false);
    ui->actionTerminal->setEnabled(false);
    ui->actionRecepteur_simple->setEnabled(false);
    ui->actionEclairage->setEnabled(false);
    ui->actionChauffage->setEnabled(false);
    ui->actionConditionneur_air->setEnabled(false);
    ui->actionForce_motrice->setEnabled(false);
    ui->actionPrise_de_courant->setEnabled(false);
    ui->actionLocal->setEnabled(false);
}

void MainWindow::updateEtatsActionCptsTD()
{
    ui->actionTableau_secondaire->setEnabled(false);
    ui->actionTableau_divisionnaire->setEnabled(false);
    ui->actionTerminal->setEnabled(true);
    ui->actionRecepteur_simple->setEnabled(true);
    ui->actionEclairage->setEnabled(true);
    ui->actionChauffage->setEnabled(true);
    ui->actionConditionneur_air->setEnabled(true);
    ui->actionForce_motrice->setEnabled(true);
    ui->actionPrise_de_courant->setEnabled(true);
    ui->actionLocal->setEnabled(true);
}

void MainWindow::updateEtatsActionCptsTer()
{
    ui->actionTableau_secondaire->setEnabled(false);
    ui->actionTableau_divisionnaire->setEnabled(false);
    ui->actionTerminal->setEnabled(false);
    ui->actionRecepteur_simple->setEnabled(true);
    ui->actionEclairage->setEnabled(true);
    ui->actionChauffage->setEnabled(true);
    ui->actionConditionneur_air->setEnabled(true);
    ui->actionForce_motrice->setEnabled(true);
    ui->actionPrise_de_courant->setEnabled(true);
    ui->actionLocal->setEnabled(true);
}

void MainWindow::updateEtatsActionCptsTGBT()
{
    ui->actionTableau_secondaire->setEnabled(true);
    ui->actionTableau_divisionnaire->setEnabled(false);
    ui->actionTerminal->setEnabled(false);
    ui->actionRecepteur_simple->setEnabled(false);
    ui->actionEclairage->setEnabled(false);
    ui->actionChauffage->setEnabled(false);
    ui->actionConditionneur_air->setEnabled(false);
    ui->actionForce_motrice->setEnabled(false);
    ui->actionPrise_de_courant->setEnabled(false);
    ui->actionLocal->setEnabled(false);
}

void MainWindow::updateEtatsActionCptsTS()
{
    ui->actionTableau_secondaire->setEnabled(false);
    ui->actionTableau_divisionnaire->setEnabled(true);
    ui->actionTerminal->setEnabled(true);
    ui->actionRecepteur_simple->setEnabled(false);
    ui->actionEclairage->setEnabled(false);
    ui->actionChauffage->setEnabled(false);
    ui->actionConditionneur_air->setEnabled(false);
    ui->actionForce_motrice->setEnabled(false);
    ui->actionPrise_de_courant->setEnabled(false);
    ui->actionLocal->setEnabled(true);
}

void MainWindow::updateEtatsActionTransfo()
{
    ui->actionTableau_secondaire->setEnabled(false);
    ui->actionTableau_divisionnaire->setEnabled(false);
    ui->actionTerminal->setEnabled(false);
    ui->actionRecepteur_simple->setEnabled(false);
    ui->actionEclairage->setEnabled(false);
    ui->actionChauffage->setEnabled(false);
    ui->actionConditionneur_air->setEnabled(false);
    ui->actionForce_motrice->setEnabled(false);
    ui->actionPrise_de_courant->setEnabled(false);
    ui->actionLocal->setEnabled(false);
}

void MainWindow::disabledEtatsActionCpts(bool isItemSelected)
{
    if(!isItemSelected)
    {
        ui->actionTableau_secondaire->setEnabled(false);
        ui->actionTableau_divisionnaire->setEnabled(false);
        ui->actionTerminal->setEnabled(false);
        ui->actionRecepteur_simple->setEnabled(false);
        ui->actionEclairage->setEnabled(false);
        ui->actionChauffage->setEnabled(false);
        ui->actionConditionneur_air->setEnabled(false);
        ui->actionForce_motrice->setEnabled(false);
        ui->actionPrise_de_courant->setEnabled(false);
        ui->actionLocal->setEnabled(false);
    }
}

void MainWindow::on_actionImprimerInstallation_triggered()
{
    if(activeMdiBilanDePuissanceMethod1())
    {
        QPrinter printer;        
        printer.setOrientation(QPrinter::Landscape);
        printer.setPaperSize(QPrinter::Folio);
        printer.setFullPage(true);

        QPrintDialog printDialog(&printer, this);

        if(printDialog.exec() == QPrintDialog::Accepted)
            printBilanMethod1(&printer);
    }else
    {
        // Afficher dialog printer
    }
}

void MainWindow::printBilanMethod1(QPrinter *printer)
{    
    // print ...
    QPainter painter;
    painter.begin(printer);    
    QGraphicsView * myWidget = activeMdiBilanDePuissanceMethod1()->driverGraphics()->graphicsView();
    double xscale = printer->pageRect().width()/double(myWidget->width());
    double yscale = printer->pageRect().height()/double(myWidget->height());
    double scale = qMin(xscale, yscale);
    painter.translate(printer->paperRect().x() + printer->pageRect().width()/2,
                        printer->paperRect().y() + printer->pageRect().height()/2);
    painter.scale(scale, scale);
    painter.translate(-width()/2, -height()/2);

    myWidget->render(&painter);
}

void MainWindow::on_actionApercu_avant_impression_triggered()
{
    if(activeMdiBilanDePuissanceMethod1())
    {
        QPrinter printer;
        printer.setOrientation(QPrinter::Landscape);
        printer.setPaperSize(QPrinter::Folio);
        printer.setFullPage(true);

        QPrintPreviewDialog printPreviewDialog(&printer, this);
        printPreviewDialog.setWindowTitle("Aperçu avant impression");
        connect(&printPreviewDialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(printBilanMethod1(QPrinter*)));

        printPreviewDialog.exec();
    }else
    {
        EvPuissMethod2 * ev2 = activeMdiBilanDePuissanceMethod2();

        NCReportOutput *output=0;

        output = new NCReportPreviewOutput();
        output->setAutoDelete( FALSE );
        NCReport * report = createReportM2(ev2, output);

        QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
        report->runReport();
        bool error = report->hasError();
        QString err = report->lastErrorMsg();
        QApplication::restoreOverrideCursor();

        if ( error )
            QMessageBox::information( this, "Report error", err );
        else {
            //-----------------------------
            // PRINT PREVIEW
            //-----------------------------
            NCReportPreviewWindow *pv = new NCReportPreviewWindow();
            pv->setWindowTitle("Aperçu avant impression");
            pv->setReport( report );
            pv->setOutput( (NCReportPreviewOutput*)output );
            pv->setWindowModality(Qt::ApplicationModal );
            pv->setAttribute( Qt::WA_DeleteOnClose );
            pv->show();
        }

        delete report;
    }
}

NCReport * MainWindow::createReportM2(EvPuissMethod2 * ev2, NCReportOutput * output)
{
    NCReport * report = new NCReport();

    report->setOutput( output );
    report->setReportFile("reportBilanM2.ncr");

    // Récupérer toutes les armoires de l'installation
    QList<Tableau> listeDesTableaux;
    QList<Recepteur> listeDesRecepteurs;

    listeDesTableaux = ev2->getAllTableaux();
    listeDesRecepteurs = ev2->getAllRecepteurs();

    /* construction de la source de données des fils  */
    FilsDataSource *ds0 = new FilsDataSource();
    ds0->setID("cds0");

    for( int i = 0; i < listeDesTableaux.count(); i++ )
    {
        Tableau pere = listeDesTableaux.at(i);
        Tableau pereCopie = pere;

        // rechercher les fils tableaux et récepteurs directs de ce tableau
        foreach(Tableau t, listeDesTableaux)
        {
            if(t.designationDuParent() == pere.designation())
            {
                pere.ajouterUnTableau(t);
            }
        }

        foreach(Recepteur r, listeDesRecepteurs)
        {
            if(r.designationDuParent() == pere.designation())
            {
                pere.ajouterUnRecepteur(r);
            }
        }
        // fin de recherche

        if(pere.estPere())
        {
            QList<Tableau> filsTableaux;
            filsTableaux = pere.tableauxFils();

            for(int i = 0; i < filsTableaux.count(); i++)
            {
                Tableau fils = filsTableaux.at(i);

                FilsData d1;
                d1.ID = i + 1;
                d1.DesignationDuParent = pere.designation();
                d1.TypeDuParent = pere.typeDeTableauStr();
                d1.CosphiP = QString::number(ev2->cosPhi(pereCopie), 'f', 2).toFloat();
                d1.PiP = QString::number(ev2->PInstalleeKW(pereCopie), 'f', 2).toFloat();
                d1.QiP = QString::number(ev2->_QInstalleeKW(pereCopie), 'f', 2).toFloat();
                d1.PuP = QString::number(ev2->PUtiliseeKW(pereCopie), 'f', 2).toFloat();
                d1.QuP = QString::number(ev2->_QUtiliseeKW(pereCopie), 'f', 2).toFloat();

                d1.Designation = fils.designation();
                d1.Type = fils.typeDeTableauStr();
                d1.CosPhi = QString::number(ev2->cosPhi(fils), 'f', 2).toFloat();
                d1.Pi = QString::number(ev2->PInstalleeKW(fils), 'f', 2).toFloat();
                d1.Qi = QString::number(ev2->_QInstalleeKW(fils), 'f', 2).toFloat();
                d1.Pu = QString::number(ev2->PUtiliseeKW(fils), 'f', 2).toFloat();
                d1.Qu = QString::number(ev2->_QUtiliseeKW(fils), 'f', 2).toFloat();
                ds0->addData( d1 );
            }

            QList<Recepteur> filsRecepteurs;
            filsRecepteurs = pere.recepteursFils();

            for(int i = 0; i < filsRecepteurs.count(); i++)
            {
                Recepteur fils = filsRecepteurs.at(i);

                FilsData d1;
                d1.ID = 1;
                d1.DesignationDuParent = pere.designation();
                d1.TypeDuParent = pere.typeDeTableauStr();
                d1.CosphiP = QString::number(ev2->cosPhi(pereCopie), 'f', 2).toFloat();
                d1.PiP = QString::number(ev2->PInstalleeKW(pereCopie), 'f', 2).toFloat();
                d1.QiP = QString::number(ev2->_QInstalleeKW(pereCopie), 'f', 2).toFloat();
                d1.PuP = QString::number(ev2->PUtiliseeKW(pereCopie), 'f', 2).toFloat();
                d1.QuP = QString::number(ev2->_QUtiliseeKW(pereCopie), 'f', 2).toFloat();

                d1.Designation = fils.designation();
                d1.Type = fils.typeDeRecepteurToStr();
                d1.CosPhi = QString::number(fils.cosPhi(), 'f', 2).toFloat();
                d1.Pi = QString::number(fils.PInstalleeKW(), 'f', 2).toFloat();
                d1.Qi = QString::number(fils._QInstalleeKW(), 'f', 2).toFloat();
                d1.Pu = QString::number(fils.PUtiliseeKW(), 'f', 2).toFloat();
                d1.Qu = QString::number(fils._QUtiliseeKW(), 'f', 2).toFloat();
                ds0->addData( d1 );
            }
        }
    }

    // on ajoute les tableaux (Sauf le TGBT) et récepteurs qui n'ont pas de parent
    foreach(Tableau t, listeDesTableaux)
    {
        if(!(t.estUnTGBT() || t.possedeUnPere()))
        {
            FilsData d1;
            d1.ID = 1;
            d1.DesignationDuParent = "Inconnu";
            d1.TypeDuParent = "NEANT";
            d1.CosphiP = 0.0;
            d1.PiP = 0.0;
            d1.QiP = 0.0;
            d1.PuP = 0.0;
            d1.QuP = 0.0;

            d1.Designation = t.designation();
            d1.Type = t.typeDeTableauStr();
            d1.CosPhi = QString::number(ev2->cosPhi(t), 'f', 2).toFloat();
            d1.Pi = QString::number(ev2->PInstalleeKW(t), 'f', 2).toFloat();
            d1.Qi = QString::number(ev2->_QInstalleeKW(t), 'f', 2).toFloat();
            d1.Pu = QString::number(ev2->PUtiliseeKW(t), 'f', 2).toFloat();
            d1.Qu = QString::number(ev2->_QUtiliseeKW(t), 'f', 2).toFloat();
            ds0->addData( d1 );
        }
    }

    foreach(Recepteur r, listeDesRecepteurs)
    {
        if(!r.possedeUnPere())
        {
            FilsData d1;
            d1.ID = 1;
            d1.DesignationDuParent = "Inconnu";
            d1.TypeDuParent = "NEANT";
            d1.CosphiP = 0.0;
            d1.PiP = 0.0;
            d1.QiP = 0.0;
            d1.PuP = 0.0;
            d1.QuP = 0.0;

            d1.Designation = r.designation();
            d1.Type = r.typeDeRecepteurToStr();
            d1.CosPhi = QString::number(r.cosPhi(), 'f', 2).toFloat();
            d1.Pi = QString::number(r.PInstalleeKW(), 'f', 2).toFloat();
            d1.Qi = QString::number(r._QInstalleeKW(), 'f', 2).toFloat();
            d1.Pu = QString::number(r.PUtiliseeKW(), 'f', 2).toFloat();
            d1.Qu = QString::number(r._QUtiliseeKW(), 'f', 2).toFloat();
            ds0->addData( d1 );
        }
    }
    // fin ajout composants non liés à un parent

    report->addCustomDataSource(ds0);
    /* fin construction de la source de données des fils */

    return report;
}
