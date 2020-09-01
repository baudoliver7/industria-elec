#include "DialogNbDeElement.h"
#include "ui_DialogNbDeElement.h"

DialogNbDeElement::DialogNbDeElement(QWidget *parent, QString title, int nombre) :
    QDialog(parent),
    ui(new Ui::DialogNbDeElement)
{
    ui->setupUi(this);
    setWindowTitle(title);
    ui->spinBoxNombre->setValue(nombre);
}

DialogNbDeElement::~DialogNbDeElement()
{
    delete ui;
}

void DialogNbDeElement::changeEvent(QEvent *e)
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

void DialogNbDeElement::on_btn_OK_clicked()
{
    accept();
}

void DialogNbDeElement::on_btn_Annuler_clicked()
{
    reject();
}

int DialogNbDeElement::nombre()const
{
    return ui->spinBoxNombre->value();
}
