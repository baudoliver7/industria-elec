#include "FrmAccueil.h"
#include "ui_FrmAccueil.h"

FrmAccueil::FrmAccueil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmAccueil)
{
    ui->setupUi(this);
}

FrmAccueil::~FrmAccueil()
{
    delete ui;
}

void FrmAccueil::on_btn_new_mt_clicked()
{
    emit createNewMT();
}

void FrmAccueil::on_btn_new_mi_clicked()
{
    emit createNewMI();
}

void FrmAccueil::on_btn_open_project_clicked()
{
    emit openProject();
}
