#include "BDProprietesDesCpts.h"
#include "ui_BDProprietesDesCpts.h"

BDProprietesDesCpts::BDProprietesDesCpts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDProprietesDesCpts)
{
    ui->setupUi(this);

    m_installation = 0;

    for(int i = 0; i <= LOCAL; i++)
    {
        m_tabText << ui->tabWidget->tabText(i);
    }

    afficherOnglet(TRANSFO);
}

BDProprietesDesCpts::BDProprietesDesCpts(Installation *i, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDProprietesDesCpts)
{
    ui->setupUi(this);

    m_installation = i;

    for(int i = 0; i <= LOCAL; i++)
    {
        m_tabText << ui->tabWidget->tabText(i);
    }

    afficherOnglet(TRANSFO);
    ui->tabWidget->setEnabled(false);
}

BDProprietesDesCpts::~BDProprietesDesCpts()
{
    delete ui;
}

void BDProprietesDesCpts::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void BDProprietesDesCpts::afficherMateriel(Recepteur r)
{
    if(r.typeDeDonneesEntree() == Recepteur::PuissanceAbsorbee)
    {
        afficherOnglet(MATERIEL_PA);

        ui->lineEditCosMat->setText(QString::number(r.cosPhi(), 'f', 2));
        ui->lineEditQuantite->setText(QString::number(r.quantite()));
        ui->lineEditDesignationMat->setText(r.designation());
        ui->lineEditKu->setText(QString::number(r.ku(), 'f', 2));
        ui->lineEditTypeMat->setText(r.typeDeRecepteurToStr());
        ui->lineEditPInstalleeMat->setText(QString::number(r.PInstalleeKW(), 'f', 2));
        ui->lineEditQInstalleeMat->setText(QString::number(r._QInstalleeKW(), 'f', 2));
        ui->lineEditPUtiliseeMat->setText(QString::number(r.PUtiliseeKW(), 'f', 2));
        ui->lineEditQUtiliseeMat->setText(QString::number(r._QUtiliseeKW(), 'f', 2));
        ui->lineEditPAbsUnitaireKW->setText(QString::number(r.pAbsorbeeUnitaireKW(), 'f', 2));
    }else
    {
        if(r.typeDeDonneesEntree() == Recepteur::PUtileEtRendement)
        {
            afficherOnglet(MATERIEL_PU);

            ui->lineEditCosMat_2->setText(QString::number(r.cosPhi(), 'f', 2));
            ui->lineEditQuantite_2->setText(QString::number(r.quantite()));
            ui->lineEditDesignationMat_2->setText(r.designation());
            ui->lineEditKu_2->setText(QString::number(r.ku(), 'f', 2));
            ui->lineEditTypeMat_2->setText(r.typeDeRecepteurToStr());
            ui->lineEditPInstalleeMat_2->setText(QString::number(r.PInstalleeKW(), 'f', 2));
            ui->lineEditQInstalleeMat_2->setText(QString::number(r._QInstalleeKW(), 'f', 2));
            ui->lineEditPUtiliseeMat_2->setText(QString::number(r.PUtiliseeKW(), 'f', 2));
            ui->lineEditQUtiliseeMat_2->setText(QString::number(r._QUtiliseeKW(), 'f', 2));
            ui->lineEditPUtileUnitaire->setText(QString::number(r.pUtileUnitaireKW(), 'f', 2));
            ui->lineEditRendement->setText(QString::number(r.rendement(), 'f', 2));
        }else
        {
            if(r.typeDeDonneesEntree() == Recepteur::CourantTension)
            {
                afficherOnglet(MATERIEL_CT);

                ui->lineEditCosMat_3->setText(QString::number(r.cosPhi(), 'f', 2));
                ui->lineEditQuantite_3->setText(QString::number(r.quantite()));
                ui->lineEditDesignationMat_3->setText(r.designation());
                ui->lineEditKu_3->setText(QString::number(r.ku(), 'f', 2));
                ui->lineEditTypeMat_3->setText(r.typeDeRecepteurToStr());
                ui->lineEditPInstalleeMat_3->setText(QString::number(r.PInstalleeKW(), 'f', 2));
                ui->lineEditQInstalleeMat_3->setText(QString::number(r._QInstalleeKW(), 'f', 2));
                ui->lineEditPUtiliseeMat_3->setText(QString::number(r.PUtiliseeKW(), 'f', 2));
                ui->lineEditQUtiliseeMat_3->setText(QString::number(r._QUtiliseeKW(), 'f', 2));
                ui->lineEditCourant->setText(QString::number(r.courant(), 'f', 2));
                ui->lineEditTension->setText(QString::number(r.tension(), 'f', 2));

                if(r.monophase())
                {
                    monophase = true;
                    ui->Monophase->setChecked(true);
                }else
                {
                    monophase = false;
                    ui->Triphase->setChecked(true);
                }
            }
        }
    }

}

void BDProprietesDesCpts::afficherTableau(Tableau t)
{
    afficherOnglet(TABLEAU);

    ui->lineEditCosTab->setText(QString::number(t.cosPhi(), 'f', 2));
    ui->lineEditDesignationTab->setText(t.designation());
    ui->lineEditKs->setText(QString::number(t.ks(), 'f', 2));
    ui->lineEditTypeTab->setText(t.typeDeTableauStr());
    ui->lineEditPInstalleeTab->setText(QString::number(t.PInstalleeKW(), 'f', 2));
    ui->lineEditQInstalleeTab->setText(QString::number(t._QInstalleeKW(), 'f', 2));
    ui->lineEditPUtiliseeTab->setText(QString::number(t.PUtiliseeKW(), 'f', 2));
    ui->lineEditQUtiliseeTab->setText(QString::number(t._QUtiliseeKW(), 'f', 2));
}

void BDProprietesDesCpts::afficherTransfo(Transformateur t)
{
    afficherOnglet(TRANSFO);

    ui->lineEditPuissanceTransfo->setText(QString::number(t.puissanceKVA()));
    ui->lineEditKa->setText(QString::number(t.ka()));
    ui->lineEditKi->setText(QString::number(t.ki()));
    ui->lineEditCosPhiTransfo->setText(QString::number(t.cosPhi()));
    ui->lineEditTempAmb->setText(QString::number(t.temperature()));
}

QWidget * BDProprietesDesCpts::tab(int index)
{
    switch(index)
    {
    case TRANSFO:
        return ui->tabTransfo;
        break;
    case TABLEAU:
        return ui->tabTableau;
        break;
    case MATERIEL_PA:
        return ui->tabMatPA;
        break;
    case MATERIEL_PU:
        return ui->tabMatPR;
        break;
    case MATERIEL_CT:
        return ui->tabMatCT;
        break;
    case LOCAL:
        return ui->tabLocal;
        break;
    default:
        return 0;
    }
}

void BDProprietesDesCpts::afficherOnglet(int index)
{
    ui->tabWidget->clear();
    ui->tabWidget->addTab(tab(index), m_tabText.at(index));
}

void BDProprietesDesCpts::afficherLocal(Local l)
{
    afficherOnglet(LOCAL);

    ui->lineEditDesignationLocal->setText(l.designation());
    ui->lineEditCosPhiLocal->setText(QString::number(l.cosPhi()));
    ui->lineEditSuperficie->setText(QString::number(l.superficie()));
    ui->lineEditPuissanceVA->setText(QString::number(l.puissanceEstimeeVAParM2()));
    ui->lineEditPuissanceKW->setText(QString::number(l.PUtiliseeKW(), 'f', 2));
}

void BDProprietesDesCpts::afficherProprietes(bool afficher, QString designation)
{
    if(!m_installation) // si installation n'existe pas
        return;

    if(afficher)
    {
        ui->tabWidget->setEnabled(true);
        if(m_installation->possedeUnTableauConnecte(designation))
        {
            Tableau t = m_installation->tableauConnecte(designation);
            afficherTableau(t);
        }else
        {
            if(m_installation->possedeUnRecepteurConnecte(designation))
            {
                Recepteur r = m_installation->recepteurConnecte(designation);
                afficherMateriel(r);
            }else
            {
                if(m_installation->possedeUnLocalConnecte(designation))
                {
                    Local l = m_installation->localConnecte(designation);
                    afficherLocal(l);
                }else
                {
                    Transformateur t = m_installation->transformateur();
                    afficherTransfo(t);
                }
            }
        }
    }else
    {
        ui->tabWidget->setEnabled(false);
    }
}

void BDProprietesDesCpts::afficherProprietes(const Transformateur & transfo)
{
    Transformateur t = transfo;
    afficherTransfo(t);
}

void BDProprietesDesCpts::on_Monophase_clicked()
{
    if(monophase)
    {
        ui->Monophase->setChecked(true);
    }else
    {
        ui->Triphase->setChecked(true);
    }
}

void BDProprietesDesCpts::on_Triphase_clicked()
{
    if(monophase)
    {
        ui->Monophase->setChecked(true);
    }else
    {
        ui->Triphase->setChecked(true);
    }
}
