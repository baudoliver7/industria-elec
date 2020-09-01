#include "BDFormulaireDeLocal.h"
#include "ui_BDFormulaireDeLocal.h"

int BDFormulaireDeLocal::sm_index = 0;

BDFormulaireDeLocal::BDFormulaireDeLocal(QWidget *parent, QString title, Installation *i, QString pere, bool editer, Local local) :
    QDialog(parent),
    ui(new Ui::BDFormulaireDeLocal)
{
    ui->setupUi(this);

    setWindowTitle(title);

    // on suppose qu'on est connecté
    m_installation = i;
    m_editer = editer;
    m_pere = pere;

    if(m_editer)
    {
        m_local = local;
        m_localSauvegarde = m_local.designation();
    }else
    {
        sm_index++;
        // éclairage fluo
        m_local = Local(INITIAL + QString::number(sm_index)
                        ,Local::EclairageFluo
                        ,QString()
                        ,0
                        ,Local::KW);

        m_local.setTypeDeLocal(Local::listeDesTypesDeLocal(m_local.typeDeRecepteurStr()).at(0));
        m_local.setDesignationDuParent(m_pere);
    }

   afficherLocal(m_local);
}

BDFormulaireDeLocal::~BDFormulaireDeLocal()
{
    delete ui;
}

void BDFormulaireDeLocal::changeEvent(QEvent *e)
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

void BDFormulaireDeLocal::afficherLocal(Local l)
{
    m_afficher = true;

    ui->lineEditDesignation->setText(l.designation());

    ui->comboBoxTypeUtil->clear();
    QStringList typesDeRecepteur = Local::listeDesTypesRecepteurs();
    typesDeRecepteur.removeFirst();
    ui->comboBoxTypeUtil->addItems(typesDeRecepteur);
    ui->comboBoxTypeUtil->setCurrentIndex(typesDeRecepteur.indexOf(l.typeDeRecepteurStr()));

    ui->comboBoxTypeLocal->clear();
    QStringList typesDeLocal = Local::listeDesTypesDeLocal(m_local.typeDeRecepteurStr());
    ui->comboBoxTypeLocal->addItems(typesDeLocal);

    if(!l.typeDeLocal().isEmpty())
    {
        ui->comboBoxTypeLocal->setCurrentIndex(typesDeLocal.indexOf(l.typeDeLocal()));
    }

    ui->spinBoxPEstimee->setMinimum(l.PEstimeeMin());
    ui->spinBoxPEstimee->setMaximum(l.PEstimeeMax());
    ui->spinBoxPEstimee->setValue(l.puissanceEstimeeVAParM2());

    ui->doubleSpinBoxSuperficie->setValue(l.superficie());

    m_afficher = false;
}

void BDFormulaireDeLocal::on_lineEditDesignation_textChanged(QString nom)
{
    if(!m_afficher)
    {
        m_local.setDesignation(nom);
    }
}

void BDFormulaireDeLocal::on_comboBoxTypeLocal_currentIndexChanged(QString type)
{
    if(!m_afficher)
    {
        m_local.setTypeDeLocal(type);
        afficherLocal(m_local);
    }
}

void BDFormulaireDeLocal::on_comboBoxTypeUtil_currentIndexChanged(QString type)
{
    if(!m_afficher)
    {
        m_local.setTypeDeRecepteur(type);
        afficherLocal(m_local);
    }
}

void BDFormulaireDeLocal::on_spinBoxPEstimee_valueChanged(int value)
{
    if(!m_afficher)
    {
        m_local.setPEstimeeVAParM2(value);
    }
}

void BDFormulaireDeLocal::on_doubleSpinBoxSuperficie_valueChanged(double value)
{
    if(!m_afficher)
    {
       m_local.setSuperficie(value);
    }
}

void BDFormulaireDeLocal::on_btn_Annuler_clicked()
{
    if(!m_editer) sm_index--;
    reject();
}

void BDFormulaireDeLocal::on_btn_OK_clicked()
{
    if(m_local.designation().isEmpty())
    {
        QMessageBox::information(this
                                 ,"Erreur sur la désignation"
                                 ,"La désignation du local est vide!\n\n Vous devez spécifier une désignation.");
    }else
    {
        // enregistrer dans l'installation
        if(!m_editer)
        {
            if(!m_installation->possedeUnLocalConnecte(m_local.designation()))
            {
                m_installation->installerUnLocal(m_local, m_pere);
                accept();
            }else
            {
                QMessageBox::information(this, "Erreur sur la désignation", "La désignation du local existe déjà !\n\n Essayez une autre désignation.");
            }
        }else
        {
            if((m_localSauvegarde == m_local.designation())
                ||((m_localSauvegarde != m_local.designation())
                && !m_installation->possedeUnLocalConnecte(m_local.designation())))
            {
                m_installation->remplacerUnLocal(m_localSauvegarde, m_local);
                accept();
            }else
            {
                QMessageBox::information(this, "Erreur sur la désignation", "La désignation du local existe déjà !\n\n Essayez une autre désignation.");
            }
        }
    }
}
