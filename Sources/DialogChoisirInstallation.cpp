#include "DialogChoisirInstallation.h"
#include "ui_DialogChoisirInstallation.h"

DialogChoisirInstallation::DialogChoisirInstallation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogChoisirInstallation)
{
    ui->setupUi(this);
}

DialogChoisirInstallation::~DialogChoisirInstallation()
{
    delete ui;
}

void DialogChoisirInstallation::changeEvent(QEvent *e)
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
