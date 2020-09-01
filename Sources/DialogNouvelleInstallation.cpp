#include "DialogNouvelleInstallation.h"
#include "ui_DialogNouvelleInstallation.h"

DialogNouvelleInstallation::DialogNouvelleInstallation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNouvelleInstallation)
{
    ui->setupUi(this);
    gererActivationDeBtnOK();
    m_themes = InfosSurBD::themes();
    m_nomsDesInstallations = InfosSurBD::nomsDesInstallations();

    ui->comboBoxThemes->addItems(m_themes);
}

DialogNouvelleInstallation::~DialogNouvelleInstallation()
{
    delete ui;
}

void DialogNouvelleInstallation::changeEvent(QEvent *e)
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

void DialogNouvelleInstallation::gererActivationDeBtnOK()
{
    QString theme = ui->comboBoxThemes->currentText();

    if((ui->lineEditAuteur->text().isEmpty()&&(!m_themes.contains(theme)))||
       ui->lineEditNomInstallation->text().isEmpty()||theme.isEmpty())
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }else
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
}

void DialogNouvelleInstallation::on_lineEditNomInstallation_textChanged(QString )
{
    gererActivationDeBtnOK();

    QString nom = ui->lineEditNomInstallation->text();

    if(m_nomsDesInstallations.contains(nom))
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
}

void DialogNouvelleInstallation::on_lineEditAuteur_textChanged(QString )
{
    gererActivationDeBtnOK();
}

QString DialogNouvelleInstallation::nomDeInstallation()const
{
    return ui->lineEditNomInstallation->text();
}

QStringList DialogNouvelleInstallation::infosInstallation()const
{
    QStringList l;
    l << ui->lineEditNomInstallation->text()
      << ui->comboBoxThemes->currentText()
      << ui->lineEditAuteur->text()
      << ui->lineEditNiveauScolaire->text()
      << ui->lineEditAnnee->text()
      << ui->lineEditNbPages->text();

    return l;
}


void DialogNouvelleInstallation::on_comboBoxThemes_editTextChanged(QString theme)
{
    gererActivationDeBtnOK();

    bool activer = !m_themes.contains(theme);

    ui->lineEditAnnee->setEnabled(activer);
    ui->lineEditAuteur->setEnabled(activer);
    ui->lineEditNiveauScolaire->setEnabled(activer);
    ui->lineEditNbPages->setEnabled(activer);
}

