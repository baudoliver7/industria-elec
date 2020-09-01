#include "BDParamTransfo.h"
#include "ui_BDParamTransfo.h"

BDParamTransfo::BDParamTransfo(Installation *i, QWidget *parent):
    QDialog(parent),
    ui(new Ui::BDParamTransfo)
{
    ui->setupUi(this);
    setWindowTitle("Paramètres du transfo");
    m_installation = i;
    transfo = new Transformateur(m_installation->transformateur());
    m_affichage = false;
    m_modified = false;

    afficherProprietes();
}

BDParamTransfo::BDParamTransfo(const Transformateur & l_transfo, QWidget *parent):
    QDialog(parent),
    ui(new Ui::BDParamTransfo)
{
    ui->setupUi(this);
    setWindowTitle("Paramètres du transfo");
    m_installation = 0;
    transfo = new Transformateur(l_transfo);
    m_affichage = false;
    m_modified = false;

    afficherProprietes();
}

BDParamTransfo::~BDParamTransfo()
{
    delete ui;
    delete transfo;
}

void BDParamTransfo::changeEvent(QEvent *e)
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

void BDParamTransfo::on_doubleSpinBoxExtension_valueChanged(double ka)
{
    if(!m_affichage)
    {
        transfo->setKa(ka);
        m_modified = true;
    }
}

void BDParamTransfo::on_spinBoxTempAmb_valueChanged(int temp)
{
    if(!m_affichage)
    {
        transfo->setTemperature(temp); // vérification interne
        m_modified = true;
        afficherProprietes();
    }
}

void BDParamTransfo::afficherProprietes()
{
    m_affichage = true;
    ui->spinBoxTempAmb->setValue(transfo->temperature());
    ui->doubleSpinBoxExtension->setValue(transfo->ka());
    ui->lineEditFacteurDePuiss->setText(QString::number(transfo->cosPhi()));
    ui->lineEditKI->setText(QString::number(transfo->ki()));
    m_affichage = false;
}


void BDParamTransfo::on_btn_OK_clicked()
{
    if(m_modified  && m_installation) m_installation->setTransformateur(*transfo);

    accept();
}

void BDParamTransfo::on_btn_Annuler_clicked()
{
    reject();
}
