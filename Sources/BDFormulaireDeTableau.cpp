#include "BDFormulaireDeTableau.h"
#include "ui_BDFormulaireDeTableau.h"

int BDFormulaireDeTableau::nbTableauCrees = 0;
int BDFormulaireDeTableau::idTD = 0;
int BDFormulaireDeTableau::idTS = 0;
int BDFormulaireDeTableau::idTER = 0;

BDFormulaireDeTableau::BDFormulaireDeTableau(QWidget *parent, QString title, Installation *i, QString pere, Tableau::TypeDeTableau type, bool editer, Tableau t) :
    QDialog(parent),
    ui(new Ui::BDFormulaireDeTableau)
{
    ui->setupUi(this);
    setWindowTitle(title);
    EditerTableau(editer);
    m_installation = i;
    m_modifie = false;
    m_nomSauvegarder = t.designation();
    m_pere = pere;

    if(m_editer)
    {
        m_tableau = t;
    }else
    {
        nbTableauCrees++;
        QString designation;

        if(type == Tableau::TableauSecondaire)
        {
            idTS++;
            designation = "TS " + QString::number(idTS);
        }else
        {
            if(type == Tableau::CoffretDivisionnaire)
            {
                idTD++;
                designation = "TD " + QString::number(idTD);
            }else
            {
                if(type == Tableau::Terminal)
                {
                    idTER++;
                    designation = "TER " + QString::number(idTER);
                }
            }
        }

        m_tableau = Tableau(type, 1.0, designation);
    }

    m_nomSauvegarder = m_tableau.designation();
    afficherTableau(m_tableau);
}

BDFormulaireDeTableau::~BDFormulaireDeTableau()
{
    delete ui;
}

void BDFormulaireDeTableau::changeEvent(QEvent *e)
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

void BDFormulaireDeTableau::on_btn_OK_clicked()
{
    QString designation = m_tableau.designation();
    if(designation.isEmpty())
    {
         QMessageBox::warning(this, "Désignation du tableau", "Le tableau n'a aucune désignation!\n\n Vous devez lui donner une désignation.");
    }else
    {
        if(m_editer)
        {
            if((m_nomSauvegarder != designation) && m_installation->possedeUnTableauConnecte(designation))
            {
                QMessageBox::warning(this, "Désignation du tableau", "La désignation de votre tableau existe déjà !\n\n Vous devez donner une désignation différente.");
            }else
            {
                if(isModified())
                {
                     m_installation->remplacerUnTableau(m_nomSauvegarder, m_tableau);
                }
                accept();
            }

        }else
        {
            if(m_installation->possedeUnTableauConnecte(designation))
            {
                QMessageBox::warning(this, "Désignation du tableau", "La désignation de votre tableau existe déjà !\n\n Vous devez donner une désignation différente.");
            }else
            {
                m_installation->installerUnTableau(m_tableau, m_pere);
                accept();
            }
        }
    }
}

void BDFormulaireDeTableau::on_btn_annuler_clicked()
{
    if(!m_editer)
    {
        if(m_tableau.estUnCD())
            idTD--;
        else if(m_tableau.estUnTS())
                idTS--;
             else
                idTER--;
    }

    reject();
}

Tableau BDFormulaireDeTableau::tableau() const
{
    return m_tableau;
}

void BDFormulaireDeTableau::afficherTableau(const Tableau & tableau)
{
    m_affichage = true;
    ui->lineEditTypeDuTableau->setText(tableau.typeDeTableauStr());
    ui->lineEditDesignation->setText(tableau.designation());
    ui->doubleSpinBoxKs->setValue(tableau.ks());
    m_affichage = false;
}

void BDFormulaireDeTableau::on_lineEditDesignation_textChanged(QString designation)
{
    if(!m_affichage)
    {
        m_tableau.setDesignation(designation);
        modifierFormulaire(true);
    }
}

void BDFormulaireDeTableau::on_doubleSpinBoxKs_valueChanged(double ks)
{
    if(!m_affichage)
    {
        m_tableau.setKs(ks);
        modifierFormulaire(true);
    }
}

