#include "DialogOuvrirInstallation.h"
#include "ui_DialogOuvrirInstallation.h"

DialogOuvrirInstallation::DialogOuvrirInstallation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogOuvrirInstallation)
{
    ui->setupUi(this);

    m_themes = InfosSurBD::themes();
    ui->comboBoxTheme->addItems(m_themes);
}

DialogOuvrirInstallation::~DialogOuvrirInstallation()
{
    delete ui;
}

void DialogOuvrirInstallation::changeEvent(QEvent *e)
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

void DialogOuvrirInstallation::on_comboBoxTheme_currentIndexChanged(QString theme)
{
    ui->comboBoxNomDeInstallation->clear();
    ui->comboBoxNomDeInstallation->addItems(InfosSurBD::nomsDesInstallations(theme));

    if(ui->comboBoxNomDeInstallation->currentText().isEmpty())
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }else
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
}

QString DialogOuvrirInstallation::nomDeInstallation()const
{
    return ui->comboBoxNomDeInstallation->currentText();
}

QString DialogOuvrirInstallation::theme()const
{
    return ui->comboBoxTheme->currentText();
}
