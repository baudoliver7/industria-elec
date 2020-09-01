#include "BDChoixDeMoteur.h"
#include "ui_BDChoixDeMoteur.h"

BDChoixDeMoteur::BDChoixDeMoteur(QString dbName, const Recepteur &r, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDChoixDeMoteur)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::database(dbName);
    modelMono = new QSqlTableModel(0,db);
    modelTri = new QSqlTableModel(0,db);
    model = new QSqlTableModel(0,db);

    setWindowTitle("Catalogue des moteurs");
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    modelMono->setTable("MAS_mono");
    modelMono->select();

    modelTri->setTable("MAS_tri_a_cage");
    modelTri->select();

    for(int i = 0; i < modelMono->rowCount(); i++)
    {
        QString type = modelMono->record(i).value("Type_de_moteur").toString();
        if(!m_typesMono.contains(type))
        {
            m_typesMono << type;
        }
    }

    for(int i = 0; i < modelTri->rowCount(); i++)
    {
        QString type = modelTri->record(i).value("Type_de_moteur").toString();
        if(!m_typesTri.contains(type))
        {
            m_typesTri << type;
        }
    }

    m_typesDeMoteur << m_typesMono
                    << m_typesTri;

    ui->KW->setChecked(true);

    connect(ui->tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this, SLOT(updateBtnOK(QModelIndex)));

    ui->comboBoxTypeDeMoteur->addItems(m_typesDeMoteur);
    m_recepteur = r;
    m_recepteur.setTypeDeRecepteur(Recepteur::ForceMotrice);
}

BDChoixDeMoteur::~BDChoixDeMoteur()
{
    delete ui;

    delete model;
    delete modelMono;
    delete modelTri;
}

void BDChoixDeMoteur::changeEvent(QEvent *e)
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

void BDChoixDeMoteur::on_comboBoxTypeDeMoteur_currentIndexChanged(QString type)
{
    selectionnerMoteurs(type);
}

void BDChoixDeMoteur::updateBtnOK(QModelIndex index)
{
    if(index.isValid())
    {
        ui->btn_OK->setEnabled(true);

        if(m_typesTri.contains(ui->comboBoxTypeDeMoteur->currentText()))
        {
            ui->groupBoxTypeDeRendement->setEnabled(true);
            ui->RQuatreQuart->setChecked(true);
        }else
        {
            ui->groupBoxTypeDeRendement->setEnabled(false);
        }
    }else
    {
        ui->btn_OK->setEnabled(false);
        ui->groupBoxTypeDeRendement->setEnabled(false);
    }
}

void BDChoixDeMoteur::selectionnerMoteurs(QString type)
{
    type.replace("'","''");

    QString tableName;
    QString filter;

    QString typeIdMono = "Type_de_moteur";
    QString typeIdTri = "Type_de_moteur";
    int idType;

    modelMono->setFilter(tr("%1 = '%2'").arg(typeIdMono).arg(type));
    modelMono->select();

    if(modelMono->rowCount() != 0)
    {
        tableName = modelMono->tableName();
        filter = tr("%1 = '%2'").arg(typeIdMono).arg(type);
        idType = 8;
    }else
    {
        tableName = modelTri->tableName();
        filter = tr("%1 = '%2'").arg(typeIdTri).arg(type);
        idType = 12;
    }

    model->setTable(tableName);
    model->setFilter(filter);
    model->select();

    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(idType, true);

    updateBtnOK(model->index(-1, -1)); // pour enhiber OK
}

void BDChoixDeMoteur::setMoteurTri()
{
    int currentRow = ui->tableView->currentIndex().row();

    QSqlRecord record = model->record(currentRow);

    m_recepteur.setDesignation(record.value(1).toString());
    m_recepteur.setTypeDeDonneesEntre(Recepteur::PUtileEtRendement);

    if(ui->KW->isChecked())
    {
        m_recepteur.setUnitePU(Recepteur::KW);
        m_recepteur.setPUtileUnitaireKW(record.value(2).toFloat());
    }else
    {
        m_recepteur.setUnitePU(Recepteur::CH);
        m_recepteur.setPUtileUnitaireCh(record.value(3).toFloat());
    }

    float rendement;
    float ku;
    float cosPhi;
    if(ui->RQuatreQuart->isChecked())
    {
        rendement = record.value(7).toFloat() / 100.0; // c'est en pourcentage
        ku = 1.0;
        cosPhi = record.value(10).toFloat();
    }else
    {
        if(ui->RTroisQuart->isChecked())
        {
            rendement = record.value(6).toFloat() / 100.0; // c'est en pourcentage
            ku = 0.75;
            cosPhi = record.value(9).toFloat();
        }else
        {
            // r un demi
            rendement = record.value(5).toFloat() / 100.0; // c'est en pourcentage
            ku = 0.5;
            cosPhi = record.value(8).toFloat();
        }
    }
    m_recepteur.setRendement(rendement);
    m_recepteur.setKu(ku);
    m_recepteur.setCosPhi(cosPhi);

    m_recepteur.setTension(400);
    m_recepteur.setCourant(record.value(4).toFloat());

    m_recepteur.setMonophase(false); // triphasé
}

void BDChoixDeMoteur::setMoteurMono()
{
    int currentRow = ui->tableView->currentIndex().row();

    QSqlRecord record = model->record(currentRow);

    m_recepteur.setDesignation(record.value(1).toString());
    m_recepteur.setTypeDeDonneesEntre(Recepteur::PUtileEtRendement);

    if(ui->KW->isChecked())
    {
        m_recepteur.setUnitePU(Recepteur::KW);
        m_recepteur.setPUtileUnitaireKW(record.value(2).toFloat());
    }else
    {
        m_recepteur.setUnitePU(Recepteur::CH);
        m_recepteur.setPUtileUnitaireCh(record.value(3).toFloat());
    }

    m_recepteur.setRendement(record.value(4).toFloat()/100.0);
    m_recepteur.setKUParDefaut();
    m_recepteur.setCosPhi(record.value(5).toFloat());

    m_recepteur.setTension(231);
    m_recepteur.setCourant(record.value(7).toFloat());

    m_recepteur.setMonophase(true); // monophasé
}

void BDChoixDeMoteur::on_btn_OK_clicked()
{
    if(m_typesMono.contains(ui->comboBoxTypeDeMoteur->currentText()))
    {
        setMoteurMono();
    }else
    {
        setMoteurTri();
    }

    accept();
}

void BDChoixDeMoteur::on_btn_Annuler_clicked()
{
    reject();
}
