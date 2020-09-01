#include "BDFormulaireDeRecepteur.h"
#include "ui_BDFormulaireDeRecepteur.h"

#include <QDebug>

int BDFormulaireDeRecepteur::nbRecepteursCrees = 0;

BDFormulaireDeRecepteur::BDFormulaireDeRecepteur(QWidget *parent):
        QDialog(parent),
        ui(new Ui::BDFormulaireDeRecepteur)
{
    ui->setupUi(this); // juste pour utiliser une fonction
}

BDFormulaireDeRecepteur::BDFormulaireDeRecepteur(QWidget *parent, QString dbName, QString title, Installation *i, QString pere, bool editer, Recepteur r) :
    QDialog(parent),
    ui(new Ui::BDFormulaireDeRecepteur)
{
    ui->setupUi(this);

    setWindowTitle(title);
    m_installation = i;
    m_editer = editer;
    m_modifie = false;
    m_pere = pere;
    m_bdChoixDeMoteur = 0;
    m_dbName = dbName;
    QSqlDatabase db = QSqlDatabase::database(m_dbName);
    m_connected = db.isOpen();    

    if(m_editer)
    {
        m_nomSauvegarder = r.designation();
        m_recepteur = r;
        ui->comboBoxTypeDeRecepteur->setEnabled(false);// on ne doit pas changer de type
    }else
    {
            // nouveau formulaire
            nbRecepteursCrees++;

            m_recepteur = Recepteur();
            m_recepteur.setDesignation(tr("récepteur %1").arg(nbRecepteursCrees));
            m_recepteur.setTypeDeRecepteur(Recepteur::AucunType);
            m_recepteur.setKUParDefaut();
    }

    setPAbsorbeeEnabled(false);
    setCourantTensionEnabled(false);
    setPUtileEnabled(false);

    connect(ui->radioButtonCourant_Tension, SIGNAL(toggled(bool)), this, SLOT(setCourantTensionEnabled(bool)));
    connect(ui->radioButtonPabsorbee, SIGNAL(toggled(bool)), this, SLOT(setPAbsorbeeEnabled(bool)));
    connect(ui->radioButtonPutile, SIGNAL(toggled(bool)), this, SLOT(setPUtileEnabled(bool)));

    initialiserBtnPredefini();
    initialiserTypeDeRecepteur();

    afficherRecepteur(m_recepteur);
}

BDFormulaireDeRecepteur::~BDFormulaireDeRecepteur()
{
    delete ui;
    if(m_bdChoixDeMoteur) delete m_bdChoixDeMoteur;
}

void BDFormulaireDeRecepteur::changeEvent(QEvent *e)
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

void BDFormulaireDeRecepteur::on_btn_OK_clicked()
{
    QString designation = m_recepteur.designation();
    if(designation.isEmpty())
    {
        QMessageBox::information(this, "Désignation du récepteur", tr("La désignation du récepteur est vide!\n\n Vous devez la définir."));
    }else
    {
        if(m_editer)
        {
            // c'est une édition
            if((m_nomSauvegarder != designation) && m_installation->possedeUnRecepteurConnecte(designation))
            {
                QMessageBox::information(this
                                         ,"Désignation du récepteur"
                                         ,tr("La désignation de votre récepteur existe déjà !\n\n Vous devez définir une désignation différente."));
            }else
            {
                if(isModified())
                {
                    m_recepteur.actualiserCalculs();
                    m_installation->remplacerUnRecepteur(m_nomSauvegarder, m_recepteur);                   
                }

                accept();
            }
        }else
        {
            // c'est une création
            if(m_installation->possedeUnRecepteur(designation))
            {
                QMessageBox::information(this
                                         ,"Désignation du récepteur"
                                         ,tr("La désignation de votre récepteur existe déjà !\n\n Vous devez définir une désignation différente."));
            }else
            {
                m_recepteur.actualiserCalculs();
                m_installation->installerUnRecepteur(m_recepteur, m_pere);
                accept();
            }
        }
    }
}

void BDFormulaireDeRecepteur::on_btn_Annuler_clicked()
{
    if(!m_editer) nbRecepteursCrees--;
    reject();
}

void BDFormulaireDeRecepteur::afficherRecepteur(const Recepteur & r)
{
    m_affichage = true;

    ui->comboBoxTypeDeRecepteur->setCurrentIndex(r.typeDeRecepteur());
    ui->lineEditDesignation->setText(r.designation());
    ui->spinBoxQuantite->setValue(r.quantite());
    if(r.monophase())
    {
        ui->Monophase->setChecked(true);
    }else
    {
        ui->Triphase->setChecked(true);
    }

    ui->comboBoxUnitePU->setCurrentIndex(r.unitePU());
    ui->comboBoxUnitePA->setCurrentIndex(r.unitePA());

    ui->doubleSpinBoxPutile->setValue(r.pUtileUnitaire());
    ui->doubleSpinBoxRendement->setValue(r.rendement());

    ui->doubleSpinBoxPabsorbee->setValue(r.pAbsorbeeUnitaire(r.unitePA()));
    ui->doubleSpinBoxPutile->setValue(r.pUtileUnitaire(r.unitePU()));

    ui->doubleSpinBoxCourant->setValue(r.courant());
    for(int i = 0; i < ui->comboBoxTension->count(); i++)
    {
        if(ui->comboBoxTension->itemText(i).toFloat() == r.tension())
        {
            ui->comboBoxTension->setCurrentIndex(i);
        }
    }

    ui->doubleSpinBoxCosPhi->setValue(r.cosPhi());
    ui->doubleSpinBoxKu->setValue(r.ku());

    ui->comboBoxTypeDeRecepteur->setCurrentIndex(r.typeDeRecepteur());
    if(r.typeDeDonneesEntree() == Recepteur::PUtileEtRendement)
    {
        ui->radioButtonCourant_Tension->setChecked(false);
        ui->radioButtonPabsorbee->setChecked(false);
        ui->radioButtonPutile->setChecked(true);
    }else
    {
        if(r.typeDeDonneesEntree() == Recepteur::CourantTension)
        {
            ui->radioButtonCourant_Tension->setChecked(true);
            ui->radioButtonPabsorbee->setChecked(false);
            ui->radioButtonPutile->setChecked(false);
        }else
        {
            ui->radioButtonCourant_Tension->setChecked(false);
            ui->radioButtonPabsorbee->setChecked(true);
            ui->radioButtonPutile->setChecked(false);
        }
    }

    if(m_recepteur.estPriseDeCourant()
        && (m_recepteur.typeDeDonneesEntree() == Recepteur::CourantTension))
    {
        setCourantTensionEnabled(true);
    }

    if(m_recepteur.estUnMoteur())
    {
        if(m_connected)
        {
            ui->btn_predefini->setEnabled(true);
        }
    }else
    {
        ui->btn_predefini->setEnabled(false);
    }

    m_affichage = false;
}

void BDFormulaireDeRecepteur::on_spinBoxQuantite_valueChanged(int qte)
{
    if(!m_affichage)
    {
        m_recepteur.setQuantite(qte);
        modifierFormulaire(true);
    }
}

void BDFormulaireDeRecepteur::on_lineEditDesignation_textChanged(QString designation)
{
    if(!m_affichage)
    {
        m_recepteur.setDesignation(designation);
        modifierFormulaire(true);
    }
}

void BDFormulaireDeRecepteur::on_doubleSpinBoxPutile_valueChanged(double pUtile)
{
    if(!m_affichage)
    {
        m_recepteur.setPUtileUnitaire(pUtile, m_recepteur.unitePU());
        modifierFormulaire(true);
    }
}

void BDFormulaireDeRecepteur::on_doubleSpinBoxRendement_valueChanged(double rendement)
{
    if(!m_affichage)
    {
        m_recepteur.setRendement(rendement);
        modifierFormulaire(true);
    }
}

void BDFormulaireDeRecepteur::on_doubleSpinBoxPabsorbee_valueChanged(double pAbsorbee)
{
    if(!m_affichage)
    {
        m_recepteur.setPAbsorbeeUnitaire(pAbsorbee, m_recepteur.unitePA());
        modifierFormulaire(true);
    }
}

void BDFormulaireDeRecepteur::on_doubleSpinBoxCosPhi_valueChanged(double cosPhi)
{
    if(!m_affichage)
    {
        m_recepteur.setCosPhi(cosPhi);
        modifierFormulaire(true);
    }
}

void BDFormulaireDeRecepteur::on_doubleSpinBoxKu_valueChanged(double ku)
{
    if(!m_affichage)
    {
        m_recepteur.setKu(ku);
        modifierFormulaire(true);
    }
}

void BDFormulaireDeRecepteur::on_radioButtonPutile_clicked()
{
    if(!m_affichage)
    {
        m_recepteur.setTypeDeDonneesEntre(Recepteur::PUtileEtRendement);
        afficherRecepteur(m_recepteur);
        modifierFormulaire(true);
    }
}

void BDFormulaireDeRecepteur::on_radioButtonPabsorbee_clicked()
{
    if(!m_affichage)
    {
        m_recepteur.setTypeDeDonneesEntre(Recepteur::PuissanceAbsorbee);
        afficherRecepteur(m_recepteur);
        modifierFormulaire(true);
    }
}

void BDFormulaireDeRecepteur::initialiserBtnPredefini()
{
    if(m_recepteur.typeDeRecepteur() == Recepteur::AucunType)
    {
        ui->btn_predefini->setEnabled(false);
    }else
    {
        ui->btn_predefini->setEnabled(true);
    }
}

void BDFormulaireDeRecepteur::initialiserTypeDeRecepteur()
{
    m_affichage = true;
    ui->comboBoxTypeDeRecepteur->addItems(Recepteur::listeDesTypes());
    actualiserRadioButtonPuissanceUnitaire();
    m_affichage = false;
}

Recepteur::TypeDeDonneesAEntrer BDFormulaireDeRecepteur::actualiserRadioButtonPuissanceUnitaire()
{
    m_affichage = true;

    ui->radioButtonPutile->setEnabled(true);
    ui->radioButtonCourant_Tension->setEnabled(true);
    ui->radioButtonPabsorbee->setEnabled(true);

    Recepteur::TypeDeDonneesAEntrer type;
    switch(m_recepteur.typeDeRecepteur())
    {
    case Recepteur::Eclairage:
        ui->radioButtonPabsorbee->setChecked(true);
        ui->radioButtonPutile->setEnabled(false);
        type = Recepteur::PuissanceAbsorbee;
        break;
    case Recepteur::ConditionnementAir:
        ui->radioButtonPutile->setChecked(true);
        ui->radioButtonCourant_Tension->setEnabled(false);
        type = Recepteur::PUtileEtRendement;
        break;
    case Recepteur::Chauffage:
        ui->radioButtonPabsorbee->setChecked(true);
        ui->radioButtonPutile->setEnabled(false);
        ui->radioButtonCourant_Tension->setEnabled(false);
        type = Recepteur::PuissanceAbsorbee;
        break;
    case Recepteur::ForceMotrice:
        ui->radioButtonPutile->setChecked(true);
        ui->radioButtonCourant_Tension->setEnabled(false);
        type = Recepteur::PUtileEtRendement;
        break;
    case Recepteur::PriseDeCourant:
        ui->radioButtonCourant_Tension->setChecked(true);
        ui->radioButtonPutile->setEnabled(false);
        type = Recepteur::CourantTension;
        break;
    case Recepteur::AucunType:
        ui->radioButtonPutile->setChecked(true);
        type = Recepteur::PUtileEtRendement;
    }
    m_affichage = false;

    return type;
}

void BDFormulaireDeRecepteur::on_radioButtonCourant_Tension_clicked()
{
    if(!m_affichage)
    {
        m_recepteur.setTypeDeDonneesEntre(Recepteur::CourantTension);
        afficherRecepteur(m_recepteur);
        modifierFormulaire(true);
    }
}

void BDFormulaireDeRecepteur::on_doubleSpinBoxCourant_valueChanged(double i)
{
    if(!m_affichage)
    {
        m_recepteur.setCourant(i);
        modifierFormulaire(true);
    }
}

void BDFormulaireDeRecepteur::on_comboBoxTension_currentIndexChanged(QString u)
{
    if(!m_affichage)
    {
        m_recepteur.setTension(u.toFloat());
        modifierFormulaire(true);
    }
}

void BDFormulaireDeRecepteur::on_comboBoxTypeDeRecepteur_currentIndexChanged(QString type)
{
    if(!m_affichage)
    {
        m_recepteur.setTypeDeRecepteur(type);
        m_recepteur.setTypeDeDonneesEntre(actualiserRadioButtonPuissanceUnitaire());
        m_recepteur.setKUParDefaut();
        m_recepteur.setCosPhiParDefaut();
        m_recepteur.setRendementParDefaut();
        afficherRecepteur(m_recepteur);
        modifierFormulaire(true);
    }   
}

void BDFormulaireDeRecepteur::on_comboBoxUnitePU_currentIndexChanged(int index)
{
    if(!m_affichage)
    {
        if(index == 0)
        {
            // en kW
            m_recepteur.setUnitePU(Recepteur::KW);
            m_recepteur.setPUtileUnitaireKW(ui->doubleSpinBoxPutile->value());
        }else   if(index == 1)
                {
                    // en W
                    m_recepteur.setUnitePU(Recepteur::W);
                    m_recepteur.setPUtileUnitaire(ui->doubleSpinBoxPutile->value());
                }else
                {
                    // en ch
                    m_recepteur.setUnitePU(Recepteur::CH);
                    m_recepteur.setPUtileUnitaireCh(ui->doubleSpinBoxPutile->value());
                }

                modifierFormulaire(true);
    }
}

void BDFormulaireDeRecepteur::on_comboBoxUnitePA_currentIndexChanged(int index)
{
    if(!m_affichage)
    {
        if(index == 0)
        {
            // en kW
            m_recepteur.setUnitePA(Recepteur::KW);
            m_recepteur.setPAbsorbeeUnitaireKW(ui->doubleSpinBoxPabsorbee->value());
        }else
        {
            // en W
            m_recepteur.setUnitePA(Recepteur::W);
            m_recepteur.setPAbsorbeeUnitaire(ui->doubleSpinBoxPabsorbee->value());
        }

        modifierFormulaire(true);
    }
}

void BDFormulaireDeRecepteur::on_Monophase_clicked()
{
    if(!m_affichage)
    {
        m_recepteur.setMonophase(true);
        modifierFormulaire(true);
    }
}

void BDFormulaireDeRecepteur::on_Triphase_clicked()
{
    if(!m_affichage)
    {
        m_recepteur.setMonophase(false);
        modifierFormulaire(true);
    }
}

void BDFormulaireDeRecepteur::setPUtileEnabled(bool enabled)
{
    ui->doubleSpinBoxPutile->setEnabled(enabled);
    ui->doubleSpinBoxRendement->setEnabled(enabled);
    ui->comboBoxUnitePU->setEnabled(enabled);
}

void BDFormulaireDeRecepteur::setCourantTensionEnabled(bool enabled)
{
    ui->doubleSpinBoxCourant->setEnabled(enabled);
    ui->comboBoxTension->setEnabled(enabled);
    ui->groupBoxNPhase->setEnabled(enabled);
}

void BDFormulaireDeRecepteur::setPAbsorbeeEnabled(bool enabled)
{
    ui->doubleSpinBoxPabsorbee->setEnabled(enabled);
    ui->comboBoxUnitePA->setEnabled(enabled);
}

void BDFormulaireDeRecepteur::on_radioButtonCourant_Tension_toggled(bool)
{

}

void BDFormulaireDeRecepteur::on_radioButtonPabsorbee_toggled(bool)
{

}

void BDFormulaireDeRecepteur::on_radioButtonPutile_toggled(bool)
{

}

void BDFormulaireDeRecepteur::on_btn_predefini_clicked()
{
    if(!m_bdChoixDeMoteur)
    {
        m_bdChoixDeMoteur = new BDChoixDeMoteur(m_dbName, m_recepteur, this);        
    }

    if(m_recepteur.estUnMoteur())
    {
        if(m_bdChoixDeMoteur->exec() == QDialog::Accepted)
        {
            QString designation = m_recepteur.designation();
            m_recepteur = m_bdChoixDeMoteur->recepteurChoisi();

            if(!designation.contains("récepteur")) // si pas nom par défaut
            {
                // remettre l'ancien nom
                m_recepteur.setDesignation(designation);
            }
            afficherRecepteur(m_recepteur);
            modifierFormulaire(true);
        }
    }
}
