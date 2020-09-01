#include "EvPuissMethod2.h"
#include "ui_EvPuissMethod2.h"

EvPuissMethod2::EvPuissMethod2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EvPuissMethod2)
{
    ui->setupUi(this);

    // trouver le repertoire des bds
    QStringList env = QProcess::systemEnvironment();
    int i = 0;
    while(!(env.at(i).contains("Common Files")||env.at(i).contains("Fichiers communs")))
    {
        i++;
    }
    QString cf32 = QDir::fromNativeSeparators(QString(env.at(i)).split("=").last());
    m_dirBD = cf32 + "/Industria Elec/data";

    m_afficher = false;
    m_bdChoixRecepteurConnectee = false;
    ui->btn_enregistrer->setEnabled(false);
    ui->btn_enregistrer->setText(ENREGISTRER);
    ui->btn_modifier->setEnabled(false);
    ui->btn_supprimer->setEnabled(false);
    afficherPtesCourantTension(false);
    afficherPtesPUtile(true);

    // création du transformateur
    m_transformateur = new Transformateur(1.2, 40);

    // création du TGBT
    Tableau t(Tableau::TGBT,1.0, "TGBT");
    t.setDescription("Tableau général basse tension");
    ajouterUnTableau(t);

    // initialiser type et nature du  tableau et TGBT
    ui->comboBoxType1->setCurrentIndex(1);
    ui->comboBoxNature1->clear();
    QStringList types = Tableau::listeDeTypeTableau();
    types.removeFirst(); // supprimer aucun type
    types.removeFirst(); // supprimer tgbt
    ui->comboBoxNature1->addItems(types);

    connect(ui->tableWidgetDesCpts->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            ,this, SLOT(updateEtatModifierSupprimer(QModelIndex)));
}

EvPuissMethod2::~EvPuissMethod2()
{
    delete ui;
    fermerBDChoixRecepteur();
}

void EvPuissMethod2::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void EvPuissMethod2::closeEvent(QCloseEvent *e)
{
    if(!sauvegarder())
    {
        e->ignore();
    }else
    {
        fermerBDChoixRecepteur();
        emit closed();
        e->accept();
    }
}

void EvPuissMethod2::on_comboBoxType1_currentIndexChanged(int index)
{
    if(index == 0)
    {
        // Récepteur
        m_afficher = true;
        ui->comboBoxNature1->clear();
        m_afficher = false;
        ui->comboBoxNature1->addItems(Recepteur::listeDesTypes());

        if(ui->comboBoxTableauParent->currentText().isEmpty())
        {
            ui->groupBoxCaracteristiques->setEnabled(false);
        }else
        {
            ui->groupBoxCaracteristiques->setEnabled(true);
        }

    }else
    {
        // Tableau
        QStringList types = Tableau::listeDeTypeTableau();
        types.removeFirst(); // supprimer "Aucun type"
        types.removeFirst(); // supprimer TGBT

        m_afficher = true;
        ui->comboBoxNature1->clear();
        m_afficher = false;
        ui->comboBoxNature1->addItems(types);

        ui->groupBoxCaracteristiques->setEnabled(false);
    }
}

void EvPuissMethod2::on_comboBoxType2_currentIndexChanged(int index)
{
    if(index == 0)
    {
        // Récepteur
        ui->comboBoxNature2->clear();
        ui->comboBoxNature2->addItems(Recepteur::listeDesTypes());
    }else
    {
        // Tableau
        ui->comboBoxNature2->clear();
        QStringList types = Tableau::listeDeTypeTableau();
        types.removeFirst(); // supprimer "Aucun type"
        ui->comboBoxNature2->addItems(types);
    }
}

void EvPuissMethod2::ajouterUnTableau(const Tableau & t)
{
    ui->comboBoxType2->setCurrentIndex(1);
    ui->comboBoxNature2->setCurrentIndex(t.typeDeTableau() - 1);

    Tableau t1 = t;
    m_tableaux << t1;

    // afficher dans tableau
    ui->tableWidgetDesCpts->setRowCount(ui->tableWidgetDesCpts->rowCount() + 1);
    int idAjout = ui->tableWidgetDesCpts->rowCount() - 1;
    afficherUneLigne(idAjout, t1);

    afficherInfosInst();
}

void EvPuissMethod2::ajouterUnRecepteur(const Recepteur & r)
{
    ui->comboBoxType2->setCurrentIndex(0);
    ui->comboBoxNature2->setCurrentIndex(r.typeDeRecepteur());

    Recepteur r1 = r;
    m_recepteurs << r1;

    // afficher dans tableau
    ui->tableWidgetDesCpts->setRowCount(ui->tableWidgetDesCpts->rowCount() + 1);
    int idAjout = ui->tableWidgetDesCpts->rowCount() - 1;
    afficherUneLigne(idAjout, r1);

    afficherInfosInst();
}

QStringList EvPuissMethod2::nomsDesTableaux()
{
    QStringList noms;
    for(int i = 0; i < m_tableaux.count(); i++)
    {
        noms << m_tableaux.at(i).designation();
    }

    return noms;
}

QStringList EvPuissMethod2::nomsDesTableaux(QList<Tableau>lt)
{
    QStringList noms;
    for(int i = 0; i < lt.count(); i++)
    {
        noms << lt.at(i).designation();
    }

    return noms;
}

QStringList EvPuissMethod2::nomsDesRecepteurs()
{
    QStringList noms;
    for(int i = 0; i < m_recepteurs.count(); i++)
    {
        noms << m_recepteurs.at(i).designation();
    }

    return noms;
}

void EvPuissMethod2::on_btn_enregistrer_clicked()
{
        if(ui->comboBoxType1->currentIndex() == 0)
        {
            if(ui->btn_enregistrer->text() == MODIFIER)
            {
                // supprimer
                supprimer(m_recepteurSauvegarde);
            }

            if(nomsDesRecepteurs().contains(ui->lineEditDesignation->text()))
            {
                QMessageBox::information(this
                                         , "Existence de la désignation"
                                         , "La désignation existe déjà !\n Entrez une désignation différente.");
                return;
            }

            // Récepteur
            Recepteur r;
            r.setDescription(ui->textEditDescription->toPlainText());
            r.setDesignation(ui->lineEditDesignation->text());
            r.setTypeDeRecepteur(ui->comboBoxNature1->currentText());
            r.setDesignationDuParent(ui->comboBoxTableauParent->currentText());

            // caractéristiques
            if(ui->comboBoxNature1->currentIndex() == (int)Recepteur::PriseDeCourant)
            {
                r.setTypeDeDonneesEntre(Recepteur::CourantTension);
                r.setCourant(ui->spinBoxCourant->value());
                r.setTension(ui->comboBoxTension->currentText().toFloat());
            }else
            {
                r.setTypeDeDonneesEntre(Recepteur::PUtileEtRendement);
                r.setUnitePU((Recepteur::Unite)ui->comboBoxUnite->currentIndex());
                r.setPUtileUnitaire(ui->doubleSpinBoxPUtile->value(), r.unitePU());
                r.setRendement(ui->doubleSpinBoxRend->value());
            }
            r.setCosPhi(ui->doubleSpinBoxCosPhi->value());
            r.setQuantite(ui->spinBoxNbre->value());

            if(r.estPriseDeCourant())
            {
                if(ui->checkBoxAtelier->isChecked())
                {
                    r.setKu(1.0);
                }else
                {
                    r.setKu(0.5);
                }
            }else
            {
                ui->checkBoxAtelier->setEnabled(false);
                if(r.estConditionneurAir()||r.estUnMoteur())
                {
                    r.setKu(0.8);
                }else
                {
                    r.setKu(1.0);
                }
            }

            r.actualiserCalculs();
            // afficher recepteur
            ajouterUnRecepteur(r);

            initialiser();
        }else
        {
            if(ui->btn_enregistrer->text() == MODIFIER)
            {
                // supprimer
                supprimer(m_tableauSauvegarde);
            }

            if(nomsDesTableaux().contains(ui->lineEditDesignation->text()))
            {
                QMessageBox::information(this
                                         , "Existence de la désignation"
                                         , "La désignation existe déjà !\n Entrez une désignation différente.");
                return;
            }else
            {
                if(ui->lineEditDesignation->text() == Tableau().designationDuParent()) //  ne contient pas aucun tableau
                {
                    QMessageBox::information(this
                                             , "Mot réservé"
                                             , "La désignation que vous venez d'entrer est un mot réservé!\n Entrez une désignation différente.");
                    return;
                }
            }

            // Tableau
            Tableau t;
            t.setDesignation(ui->lineEditDesignation->text());
            t.setDescription(ui->textEditDescription->toPlainText());
            t.setTypeDeTableau(ui->comboBoxNature1->currentText());

            QString parent;
            if(ui->comboBoxTableauParent->currentText() == INCONNU)
            {
                parent = Recepteur().designationDuParent(); // aucun parent
            }else
            {
                parent = ui->comboBoxTableauParent->currentText();
            }

            t.setDesignationDuParent(parent);

            // afficher tableau
            ajouterUnTableau(t);

            initialiser();
        }

        setWindowModified(true);
        emit windowIsModified(true);
}

float EvPuissMethod2::kcPCTD(Recepteur r)
{
    if(r.ku() == 0.5)
    {
        if(r.quantite() == 1)
        {
            return 0.5;
        }else
        {
            if(r.quantite()>= 2 && r.quantite() <= 3)
            {
                return 0.25;
            }else
            {
                if(r.quantite()>= 4 && r.quantite() <= 5)
                {
                    return 0.17;
                }else
                {
                    if(r.quantite()>= 6 && r.quantite() <= 9)
                    {
                        return 0.12;
                    }else
                    {
                        return 0.1;
                    }
                }
            }
        }
    }else
    {
        if(r.quantite() == 1)
        {
            return 1.0;
        }else
        {
            if(r.quantite()>= 2 && r.quantite() <= 3)
            {
                return 0.5;
            }else
            {
                if(r.quantite()>= 4 && r.quantite() <= 5)
                {
                    return 0.33;
                }else
                {
                    if(r.quantite()>= 6 && r.quantite() <= 9)
                    {
                        return 0.25;
                    }else
                    {
                        return 0.2;
                    }
                }
            }
        }
    }
}

float EvPuissMethod2::kcPCTS(Recepteur r)
{
    if(r.ku() == 0.5)
    {
        if(r.quantite() == 1)
        {
            return 0.45;
        }else
        {
            if(r.quantite()>= 2 && r.quantite() <= 3)
            {
                return 0.22;
            }else
            {
                if(r.quantite()>= 4 && r.quantite() <= 5)
                {
                    return 0.15;
                }else
                {
                    if(r.quantite()>= 6 && r.quantite() <= 9)
                    {
                        return 0.1;
                    }else
                    {
                        return 0.09;
                    }
                }
            }
        }
    }else
    {
        if(r.quantite() == 1)
        {
            return 0.9;
        }else
        {
            if(r.quantite()>= 2 && r.quantite() <= 3)
            {
                return 0.45;
            }else
            {
                if(r.quantite()>= 4 && r.quantite() <= 5)
                {
                    return 0.3;
                }else
                {
                    if(r.quantite()>= 6 && r.quantite() <= 9)
                    {
                        return 0.2;
                    }else
                    {
                        return 0.18;
                    }
                }
            }
        }
    }
}

float EvPuissMethod2::kcPCTGBT(Recepteur r)
{
    if(r.ku() == 0.5)
    {
        if(r.quantite() == 1)
        {
            return 0.36;
        }else
        {
            if(r.quantite()>= 2 && r.quantite() <= 3)
            {
                return 0.18;
            }else
            {
                if(r.quantite()>= 4 && r.quantite() <= 5)
                {
                    return 0.11;
                }else
                {
                    if(r.quantite()>= 6 && r.quantite() <= 9)
                    {
                        return 0.09;
                    }else
                    {
                        return 0.07;
                    }
                }
            }
        }
    }else
    {
        if(r.quantite() == 1)
        {
            return 0.72;
        }else
        {
            if(r.quantite()>= 2 && r.quantite() <= 3)
            {
                return 0.35;
            }else
            {
                if(r.quantite()>= 4 && r.quantite() <= 5)
                {
                    return 0.22;
                }else
                {
                    if(r.quantite()>= 6 && r.quantite() <= 9)
                    {
                        return 0.18;
                    }else
                    {
                        return 0.15;
                    }
                }
            }
        }
    }
}

float EvPuissMethod2::kc(Tableau::TypeDeTableau typeT, Recepteur r)
{
    if(typeT == Tableau::Terminal)
    {
        // appliquer ks
        if(r.estPriseDeCourant())
        {
            return kcPCTD(r);
        }else
        {
            return 1.0;
        }
    }

    if(typeT == Tableau::CoffretDivisionnaire)
    {
        if((r.typeDeRecepteur() == Recepteur::AucunType)
            ||r.estEclairage()
            ||r.estChauffage())
        {
            if(r.estChauffage())
            {
                return 0.9;
            }else
            {
                return 1.0;
            }

        }else
        {
            if(r.estPriseDeCourant())
            {
                return kcPCTD(r);
            }else
            {
                // conditionneur d'air et force motrice
                return 0.85;
            }
        }
    }else
    {
        if(typeT == Tableau::TableauSecondaire)
        {
            if((r.typeDeRecepteur() == Recepteur::AucunType)
                ||r.estEclairage()
                ||r.estChauffage())
            {
                if(r.estChauffage())
                {
                    return 0.8;
                }else
                {
                    return 0.9;
                }
            }else
            {
                if(r.estPriseDeCourant())
                {
                    return kcPCTS(r);
                }else
                {
                    // conditionneur d'air et force motrice
                    return 0.75;
                }
            }
        }else
        {
            if(typeT == Tableau::TGBT)
            {
                if((r.typeDeRecepteur() == Recepteur::AucunType)
                    ||r.estEclairage()
                    ||r.estChauffage())
                {
                    if(r.estChauffage())
                    {
                        return 0.65;
                    }else
                    {
                        return 0.72;
                    }

                }else
                {
                    if(r.estPriseDeCourant())
                    {
                        return kcPCTGBT(r);
                    }else
                    {
                        // conditionneur d'air et force motrice
                        return 0.6;
                    }
                }
            }
        }
    }

    return 1; // pour éviter avertissement
}

void EvPuissMethod2::initialiser()
{    
    ui->comboBoxType1->setEnabled(true);
    ui->comboBoxNature1->setEnabled(true);    
    //on_comboBoxNature1_currentIndexChanged(ui->comboBoxNature1->currentIndex());
    ui->lineEditDesignation->setText(QString());
    ui->textEditDescription->setText(QString());
}

void EvPuissMethod2::on_comboBoxNature1_currentIndexChanged(int index)
{
    if(!m_afficher)
    {
        // afficher un élément par défaut
        if(ui->comboBoxType1->currentIndex() == 0)
        {
           // récepteur
            Recepteur r;
            r.setDesignation(ui->lineEditDesignation->text());
            r.setDescription(ui->textEditDescription->toPlainText());
            r.setDesignationDuParent(ui->comboBoxTableauParent->currentText());
            r.setTypeDeRecepteur(Recepteur::listeDesTypes().at(index));

            r.setCosPhiParDefaut();
            if(r.estPriseDeCourant())
            {
                r.setKu(1.0); // atelier par défaut
                r.setTypeDeDonneesEntre(Recepteur::CourantTension);
                afficherPtesCourantTension(true);
                afficherPtesPUtile(false);
            }else
            {
                r.setRendementParDefaut();
                r.setUnitePU(Recepteur::KW);
                r.setTypeDeDonneesEntre(Recepteur::PUtileEtRendement);
                afficherPtesCourantTension(false);
                afficherPtesPUtile(true);
            }

            afficher(r);
            ui->btn_enregistrer->setText(ENREGISTRER);
        }else
        {
            // tableau
            Tableau t;
            t.setDesignation(ui->lineEditDesignation->text());
            t.setDescription(ui->textEditDescription->toPlainText());
            t.setDesignationDuParent(ui->comboBoxTableauParent->currentText());
            t.setTypeDeTableau(Tableau::listeDeTypeTableau().at(index + 2));

            afficher(t);
            ui->btn_enregistrer->setText(ENREGISTRER);
        }
    }
}

void EvPuissMethod2::afficher(const Recepteur & r)
{
    m_afficher = true;
    ui->comboBoxType1->setCurrentIndex(0);
    ui->comboBoxNature1->setCurrentIndex(r.typeDeRecepteur());

    ui->groupBoxCaracteristiques->setEnabled(true);
    ui->doubleSpinBoxCosPhi->setValue(r.cosPhi());
    ui->spinBoxNbre->setValue(r.quantite());

    ui->lineEditDesignation->setText(r.designation());
    ui->textEditDescription->setText(r.description());
    if(r.estChauffage() || r.estEclairage() || r.estPriseDeCourant())
    {
        ui->doubleSpinBoxRend->setEnabled(false);
        ui->comboBoxUnite->removeItem(2); // ch
    }else
    {
        ui->doubleSpinBoxRend->setEnabled(true);

        QStringList unites;
        unites << "kW" << "W" << "ch";
        ui->comboBoxUnite->clear();
        ui->comboBoxUnite->addItems(unites);
    }

    if(r.estPriseDeCourant())
    {
        ui->checkBoxAtelier->setEnabled(true);
        if(r.ku() == 1.0)
        {
            ui->checkBoxAtelier->setChecked(true);
        }else
        {
            ui->checkBoxAtelier->setChecked(false);
        }

        ui->spinBoxCourant->setValue(r.courant());
        int indexTension = ui->comboBoxTension->findText(QString::number(r.tension()));
        ui->comboBoxTension->setCurrentIndex(indexTension);
        afficherPtesCourantTension(true);
        afficherPtesPUtile(false);
    }else
    {
        ui->comboBoxUnite->setCurrentIndex(r.unitePU());
        ui->doubleSpinBoxPUtile->setValue(r.pUtileUnitaire(r.unitePU()));
        ui->doubleSpinBoxRend->setValue(r.rendement());
        ui->checkBoxAtelier->setEnabled(false);
        afficherPtesCourantTension(false);
        afficherPtesPUtile(true);
    }

    if(r.estUnMoteur())
    {
        ui->btn_predefini->setEnabled(true);
    }else
    {
        ui->btn_predefini->setEnabled(false);
    }

    QList<Tableau> lt;
    lt << tableaux(Tableau::TGBT);
    lt << tableaux(Tableau::TableauSecondaire);
    lt << tableaux(Tableau::CoffretDivisionnaire);
    lt << tableaux(Tableau::Terminal);

    int indexTP = ui->comboBoxTableauParent->currentIndex();
    ui->comboBoxTableauParent->clear();
    ui->comboBoxTableauParent->addItems(nomsDesTableaux(lt));

    if(indexTP >= 0) ui->comboBoxTableauParent->setCurrentIndex(indexTP);

    m_afficher = false;
}

void EvPuissMethod2::afficher(QList<Recepteur> lr)
{
    ui->tableWidgetDesCpts->setRowCount(0);

    for(int i = 0; i < lr.count(); i++)
    {
        Recepteur r1 = lr.at(i);
        // afficher dans tableau
        ui->tableWidgetDesCpts->setRowCount(i + 1);
        afficherUneLigne(i, r1);
    }
}

void EvPuissMethod2::afficher(QList<Tableau> lt)
{
    ui->tableWidgetDesCpts->setRowCount(0);

    for(int i = 0; i < lt.count(); i++)
    {
        Tableau t = lt.at(i);
        // afficher dans tableau
        ui->tableWidgetDesCpts->setRowCount(i + 1);
        afficherUneLigne(i, t);
    }
}

void EvPuissMethod2::afficherInfosInst()
{
    Tableau tgbt = m_tableaux.at(0);
    ui->lineEditPinstallee->setText(QString::number(PInstalleeKW(tgbt), 'f', 2));
    float pUtilisee = PUtiliseeKW(tgbt);
    ui->lineEditPUtilisee->setText(QString::number(pUtilisee, 'f', 2));
    ui->lineEditCosPhi->setText(QString::number(cosPhi(tgbt), 'f', 2));

    m_transformateur->setPUtilisation(pUtilisee);
}

void EvPuissMethod2::afficher(const Tableau & t)
{
    m_afficher = true;
    ui->comboBoxType1->setCurrentIndex(1);
    int index = Tableau::listeDeTypeTableau().indexOf(t.typeDeTableauStr());
    ui->comboBoxNature1->setCurrentIndex(index - 2);

    ui->groupBoxCaracteristiques->setEnabled(false);
    ui->doubleSpinBoxCosPhi->setValue(1.0);
    ui->doubleSpinBoxPUtile->setValue(0);
    ui->comboBoxUnite->setCurrentIndex((int)Recepteur::KW);
    ui->doubleSpinBoxRend->setValue(1.0);
    ui->spinBoxNbre->setValue(1);

    ui->lineEditDesignation->setText(t.designation());
    ui->textEditDescription->setText(t.description());

    QList<Tableau> lt;

    if(t.estUnTS())
    {
        lt << m_tableaux.at(0); // tgbt
    }else
    {
        if(t.estUnCD())
        {
            lt << tableaux(Tableau::TableauSecondaire);
        }else
        {
            // terminal car on affiche pas TGBT
            lt << tableaux(Tableau::TableauSecondaire);
            lt << tableaux(Tableau::CoffretDivisionnaire);
        }
    }

    ui->comboBoxTableauParent->clear();
    if(!t.estUnTS() && !t.estUnTGBT())
    {
        ui->comboBoxTableauParent->addItem(INCONNU);
    }
    ui->comboBoxTableauParent->addItems(nomsDesTableaux(lt));

    ui->btn_predefini->setEnabled(false);

    m_afficher = false;
}


void EvPuissMethod2::on_lineEditDesignation_textChanged(QString designation)
{
    if(designation.isEmpty())
    {
        ui->btn_enregistrer->setEnabled(false);
    }else
    {
        ui->btn_enregistrer->setEnabled(true);
    }
}

void EvPuissMethod2::on_btn_initialiser_clicked()
{
    initialiser();
}

void EvPuissMethod2::afficherUneLigne(int row, const Recepteur & r)
{
    afficherUneCase(row, DESIGNATION, r.designation());
    afficherUneCase(row, DESCRIPTION, r.description());
    if(r.estPriseDeCourant())
    {
        afficherUneCase(row, PUTILE, QString::number(r.pAbsorbeeUnitaireKW(), 'f', 2));
    }else
    {
        afficherUneCase(row, PUTILE, QString::number(r.pUtileUnitaireKW(), 'f', 2));
    }

    afficherUneCase(row, COSPHI, QString::number(r.cosPhi(), 'f', 2));
    afficherUneCase(row, NOMBRE, QString::number(r.quantite()));
    afficherUneCase(row, PINSTALLEE, QString::number(r.PInstalleeKW(), 'f', 2));
    afficherUneCase(row, _QINSTALLEE, QString::number(r._QInstalleeKW(), 'f', 2));
    afficherUneCase(row, PUTILISEE, QString::number(r.PUtiliseeKW(), 'f', 2));
    afficherUneCase(row, _QUTILISEE, QString::number(r._QUtiliseeKW(), 'f', 2));
    afficherUneCase(row, PARENT, r.designationDuParent());

    ui->tableWidgetDesCpts->setColumnHidden(PUTILE, false);
    ui->tableWidgetDesCpts->setColumnHidden(NOMBRE, false);
    ui->tableWidgetDesCpts->setColumnHidden(_QUTILISEE, true);
    ui->tableWidgetDesCpts->setColumnHidden(PUTILISEE, true);
}

void EvPuissMethod2::afficherUneLigne(int row,  const Tableau & r)
{
    afficherUneCase(row, DESIGNATION, r.designation());
    afficherUneCase(row, DESCRIPTION, r.description());
    afficherUneCase(row, COSPHI, QString::number(cosPhi(r), 'f', 2));
    afficherUneCase(row, PINSTALLEE, QString::number(PInstalleeKW(r), 'f', 2));
    afficherUneCase(row, _QINSTALLEE, QString::number(_QInstalleeKW(r), 'f', 2));
    afficherUneCase(row, PUTILISEE, QString::number(PUtiliseeKW(r), 'f', 2));
    afficherUneCase(row, _QUTILISEE, QString::number(_QUtiliseeKW(r), 'f', 2));
    afficherUneCase(row, PARENT, r.designationDuParent());

    ui->tableWidgetDesCpts->setColumnHidden(PUTILE, true);
    ui->tableWidgetDesCpts->setColumnHidden(NOMBRE, true);
    ui->tableWidgetDesCpts->setColumnHidden(_QUTILISEE, false);
    ui->tableWidgetDesCpts->setColumnHidden(PUTILISEE, false);
}

void EvPuissMethod2::afficherUneCase(int row, int column, QString text)
{
    QTableWidgetItem * cases = new QTableWidgetItem(text);
    cases->setTextAlignment(Qt::AlignCenter);

    ui->tableWidgetDesCpts->setItem(row, column, cases);
}

float EvPuissMethod2::PInstalleeKW(const Tableau &pere)
{
    return (PAucunTypeKW(pere, true)
            + PChauffageKW(pere, true)
            + PConditionneurAirKW(pere, true)
            + PForceMotriceKW(pere, true)
            + PPriseCourantKW(pere, true)
            + PEclairageKW(pere, true));
}

float EvPuissMethod2::PUtiliseeKW(const Tableau &pere)
{
    return (PAucunTypeKW(pere, false)
            + PChauffageKW(pere, false)
            + PConditionneurAirKW(pere, false)
            + PForceMotriceKW(pere, false)
            + PPriseCourantKW(pere, false)
            + PEclairageKW(pere, false));
}

float EvPuissMethod2::_QInstalleeKW(const Tableau &pere)
{
    return (_QAucunTypeKW(pere, true)
            + _QChauffageKW(pere, true)
            + _QConditionneurAirKW(pere, true)
            + _QForceMotriceKW(pere, true)
            + _QPriseCourantKW(pere, true)
            + _QEclairageKW(pere, true));
}

float EvPuissMethod2::_QUtiliseeKW(const Tableau &pere)
{
    return (_QAucunTypeKW(pere, false)
            + _QChauffageKW(pere, false)
            + _QConditionneurAirKW(pere, false)
            + _QForceMotriceKW(pere, false)
            + _QPriseCourantKW(pere, false)
            + _QEclairageKW(pere, false));
}

float EvPuissMethod2::cosPhi(const Tableau &pere)
{
    float putilisee = PUtiliseeKW(pere);

    if(putilisee == 0)
    {
        return 1.0;
    }

    float qutilisee = _QUtiliseeKW(pere);

    float S = sqrt(putilisee * putilisee + qutilisee * qutilisee);

    return (putilisee / S);
}

float EvPuissMethod2::PAucunTypeKW(const Tableau &pere, bool installee)
{
    QList<Recepteur> lr;
    lr << recepteurs(pere, Recepteur::AucunType);

    if(installee)
    {
        return puissanceInstalleeKW(lr);
    }else
    {
        return puissanceUtiliseeKW(lr, pere.typeDeTableau());
    }
}

float EvPuissMethod2::PEclairageKW(const Tableau &pere, bool installee)
{
    QList<Recepteur> lr;
    lr << recepteurs(pere, Recepteur::Eclairage);

    if(installee)
    {
        return puissanceInstalleeKW(lr);
    }else
    {
        return puissanceUtiliseeKW(lr, pere.typeDeTableau());
    }
}

float EvPuissMethod2::PConditionneurAirKW(const Tableau &pere, bool installee)
{
    QList<Recepteur> lr;
    lr << recepteurs(pere, Recepteur::ConditionnementAir);

    if(installee)
    {
        return puissanceInstalleeKW(lr);
    }else
    {
        return puissanceUtiliseeKW(lr, pere.typeDeTableau());
    }
}

float EvPuissMethod2::PChauffageKW(const Tableau &pere, bool installee)
{
    QList<Recepteur> lr;
    lr << recepteurs(pere, Recepteur::Chauffage);

    if(installee)
    {
        return puissanceInstalleeKW(lr);
    }else
    {
        return puissanceUtiliseeKW(lr, pere.typeDeTableau());
    }
}

float EvPuissMethod2::PPriseCourantKW(const Tableau &pere, bool installee)
{
    QList<Recepteur> lr;
    lr << recepteurs(pere, Recepteur::PriseDeCourant);

    if(installee)
    {
        return puissanceInstalleeKW(lr);
    }else
    {
        return puissanceUtiliseeKW(lr, pere.typeDeTableau());
    }
}

float EvPuissMethod2::PForceMotriceKW(const Tableau &pere, bool installee)
{
    QList<Recepteur> lr;
    lr << recepteurs(pere, Recepteur::ForceMotrice);

    if(installee)
    {
        return puissanceInstalleeKW(lr);
    }else
    {
        return puissanceUtiliseeKW(lr, pere.typeDeTableau());
    }
}

float EvPuissMethod2::_QAucunTypeKW(const Tableau &pere, bool installee)
{
    QList<Recepteur> lr;
    lr << recepteurs(pere, Recepteur::AucunType);

    if(installee)
    {
        return qInstalleeKW(lr);
    }else
    {
        return qUtiliseeKW(lr, pere.typeDeTableau());
    }
}

float EvPuissMethod2::_QChauffageKW(const Tableau &pere, bool installee)
{
    QList<Recepteur> lr;
    lr << recepteurs(pere, Recepteur::Chauffage);

    if(installee)
    {
        return qInstalleeKW(lr);
    }else
    {
        return qUtiliseeKW(lr, pere.typeDeTableau());
    }
}

float EvPuissMethod2::_QEclairageKW(const Tableau &pere, bool installee)
{
    QList<Recepteur> lr;
    lr << recepteurs(pere, Recepteur::Eclairage);

    if(installee)
    {
        return qInstalleeKW(lr);
    }else
    {
        return qUtiliseeKW(lr, pere.typeDeTableau());
    }
}

float EvPuissMethod2::_QConditionneurAirKW(const Tableau &pere, bool installee)
{
    QList<Recepteur> lr;
    lr << recepteurs(pere, Recepteur::ConditionnementAir);

    if(installee)
    {
        return qInstalleeKW(lr);
    }else
    {
        return qUtiliseeKW(lr, pere.typeDeTableau());
    }
}

float EvPuissMethod2::_QPriseCourantKW(const Tableau &pere, bool installee)
{
    QList<Recepteur> lr;
    lr << recepteurs(pere, Recepteur::PriseDeCourant);

    if(installee)
    {
        return qInstalleeKW(lr);
    }else
    {
        return qUtiliseeKW(lr, pere.typeDeTableau());
    }
}

float EvPuissMethod2::_QForceMotriceKW(const Tableau &pere, bool installee)
{
    QList<Recepteur> lr;
    lr << recepteurs(pere, Recepteur::ForceMotrice);

    if(installee)
    {
        return qInstalleeKW(lr);
    }else
    {
        return qUtiliseeKW(lr, pere.typeDeTableau());
    }
}

QList<Recepteur> EvPuissMethod2::recepteurs(const Tableau &pere, Recepteur::TypeDeRecepteur type)
{
    if(pere.estUnTGBT())
    {
        return recepteurs(type);
    }else
    {
        QList<Recepteur> lr;
        for(int i = 0; i < m_recepteurs.count(); i++)
        {
            Recepteur r = m_recepteurs.at(i);
            if((pere.designation() == r.designationDuParent())
                && (r.typeDeRecepteur() == type))
            {
                lr << r;
            }
        }

        for(int i = 0; i < m_tableaux.count(); i++)
        {
            Tableau t = m_tableaux.at(i);
            if(pere.designation() == t.designationDuParent())
                // les appareils sous un tableau fils appartiennent au père
            {
                lr << recepteurs(t, type);

            }
        }

        return lr;
    }
}

float EvPuissMethod2::qInstalleeKW(QList<Recepteur>lr)
{
    float som = 0;
    for(int i = 0; i < lr.count(); i++)
    {
        som += lr.at(i)._QInstalleeKW();
    }

    return som;
}

float EvPuissMethod2::qUtiliseeKW(QList<Recepteur>lr, Tableau::TypeDeTableau type)
{
    float som = 0;
    for(int i = 0; i < lr.count(); i++)
    {
        float tangente = lr.at(i)._QUtiliseeKW() / lr.at(i).PUtiliseeKW();
        som += lr.at(i).pUtileUnitaireKW() * lr.at(i).quantite()* kc(type, lr.at(i)) * tangente;
    }

    return som;
}

float EvPuissMethod2::puissanceInstalleeKW(QList<Recepteur> lr)
{
    float som = 0;
    for(int i = 0; i < lr.count(); i++)
    {
        som += lr.at(i).PInstalleeKW();
    }

    return som;
}

float EvPuissMethod2::puissanceUtileKW(QList<Recepteur>lr)
{
    float som = 0;
    for(int i = 0; i < lr.count(); i++)
    {
        if(lr.at(i).estPriseDeCourant())
        {
            som += lr.at(i).pAbsorbeeUnitaireKW() * lr.at(i).quantite();
        }else
        {
            som += lr.at(i).pUtileUnitaireKW() * lr.at(i).quantite();
        }
    }

    return som;
}

float EvPuissMethod2::puissanceUtiliseeKW(QList<Recepteur>lr, Tableau::TypeDeTableau type)
{
    if(lr.isEmpty())
        return 0;

    Recepteur r = lr.at(0);
    if(r.estPriseDeCourant())
    {
        float som = 0;
        for(int i = 0; i < lr.count(); i++)
        {
            Recepteur r1 = lr.at(i);
            som += lr.at(i).PInstalleeKW() * kc(type, r1);
        }

        return som;
    }

    // autre type
    return puissanceUtileKW(lr) * kc(type, r);
}

void EvPuissMethod2::on_comboBoxNature2_currentIndexChanged(int index)
{
    if(ui->comboBoxType2->currentIndex() == 0)
    {
        // récepteur
        afficher(recepteurs((Recepteur::TypeDeRecepteur)index));
    }else
    {
        // tableau
        afficher(tableaux((Tableau::TypeDeTableau)(index + 1)));
    }
}

QList<Recepteur> EvPuissMethod2::recepteurs(Recepteur::TypeDeRecepteur type)
{
    QList<Recepteur> lr;
    for(int i = 0; i < m_recepteurs.count(); i++)
    {
        Recepteur r = m_recepteurs.at(i);
        if(r.typeDeRecepteur() == type)
        {
            lr << r;
        }
    }

    return lr;
}

QList<Tableau> EvPuissMethod2::tableaux(Tableau::TypeDeTableau type)
{
    QList<Tableau> lr;
    for(int i = 0; i < m_tableaux.count(); i++)
    {
        Tableau r = m_tableaux.at(i);
        if(r.typeDeTableau() == type)
        {
            lr << r;
        }
    }

    return lr;
}

void EvPuissMethod2::on_btn_modifier_clicked()
{
    int row = ui->tableWidgetDesCpts->currentRow();
    QString parent;

    if(ui->comboBoxType1->currentIndex() == 0)
    {
        Recepteur r = (recepteurs((Recepteur::TypeDeRecepteur)ui->comboBoxNature2->currentIndex())).at(row);
        afficher(r);
        m_recepteurSauvegarde = r;
        parent = r.designationDuParent();
    }else
    {
        Tableau t = (tableaux((Tableau::TypeDeTableau)(ui->comboBoxNature2->currentIndex() + 1))).at(row);
        afficher(t);

        m_tableauSauvegarde = t;
        parent = t.designationDuParent();
    }

    bool trouve = false;
    for(int i = 0; i < ui->comboBoxTableauParent->count(); i++)
    {
        if(ui->comboBoxTableauParent->itemText(i) == parent)
        {
            ui->comboBoxTableauParent->setCurrentIndex(i);
            trouve = true;
        }
    }

    if(!trouve)
    {
        ui->comboBoxTableauParent->setCurrentIndex(0); // aucun parent
    }

    ui->btn_enregistrer->setText(MODIFIER);
    ui->comboBoxType1->setEnabled(false);
    ui->comboBoxNature1->setEnabled(false);
}

void EvPuissMethod2::updateEtatModifierSupprimer(QModelIndex index)
{
    if(index.isValid())
    {
        if(ui->comboBoxNature2->currentText() != Tableau::typeToString(Tableau::TGBT))
        {
            ui->btn_modifier->setEnabled(true);
            ui->btn_supprimer->setEnabled(true);
        }
    }else
    {
        ui->btn_modifier->setEnabled(false);
        ui->btn_supprimer->setEnabled(false);
    }
}

void EvPuissMethod2::supprimer(Recepteur r)
{
    if(m_recepteurs.removeOne(r))
    {
        afficher(recepteurs(r.typeDeRecepteur()));
        afficherInfosInst();
    }
}

void EvPuissMethod2::supprimer(Tableau t)
{
    if(m_tableaux.removeOne(t))
    {
        afficher(tableaux(t.typeDeTableau()));
        afficherInfosInst();
    }
}


void EvPuissMethod2::on_btn_supprimer_clicked()
{
    int row = ui->tableWidgetDesCpts->currentRow();
    QString designation = ui->tableWidgetDesCpts->item(row, DESIGNATION)->text();

    if(QMessageBox::question(this, "Suppression d'un composant"
                             , tr("Désirez-vous supprimer %1?").arg(designation), "oui", "non") == 0)
    {
        if(ui->comboBoxType2->currentIndex() == 0)
        {
            QList<Recepteur> lr;
            lr << recepteurs((Recepteur::TypeDeRecepteur)ui->comboBoxNature2->currentIndex());
            Recepteur r = lr.at(row);
            lr.removeOne(r);

            supprimer(r);
        }else
        {
            QList<Tableau> lr;
            lr << tableaux((Tableau::TypeDeTableau)(ui->comboBoxNature2->currentIndex() + 1));
            Tableau r = lr.at(row);
            lr.removeOne(r);

            supprimer(r);
        }
    }
}

bool EvPuissMethod2::seConnecterABDChoixRecepteur()
{
    // connection
    QString chemin = tr("%1/catalogue_de_recepteurs.mdb").arg(m_dirBD);
    QSqlDatabase dbChoixRecepteur = QSqlDatabase::addDatabase("QODBC", BD_RECEPTEUR_NAME);
    dbChoixRecepteur.setDatabaseName(tr("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=%1").arg(chemin));
    dbChoixRecepteur.setPassword("aigleroyal7");

    m_bdChoixRecepteurConnectee = dbChoixRecepteur.open();
    if(!m_bdChoixRecepteurConnectee)
    {
        QMessageBox::warning(this, "Base de données indisponible", QObject::tr("La base de données du catalogue des matériels est indisponible! : %1").arg(dbChoixRecepteur.lastError().text()));
    }

    return m_bdChoixRecepteurConnectee;
}

void EvPuissMethod2::fermerBDChoixRecepteur()
{
    if(m_bdChoixRecepteurConnectee)
    {
        QSqlDatabase::database(BD_RECEPTEUR_NAME).close();
        QSqlDatabase::removeDatabase(BD_RECEPTEUR_NAME);
        m_bdChoixRecepteurConnectee = false;
    }
}

void EvPuissMethod2::on_btn_predefini_clicked()
{
    if(!m_bdChoixRecepteurConnectee)
    {
        seConnecterABDChoixRecepteur();
    }

    if(m_bdChoixRecepteurConnectee)
    {
        BDChoixDeMoteur * choixRecepteur = new BDChoixDeMoteur(BD_RECEPTEUR_NAME, Recepteur(), this);
        if(choixRecepteur->exec() == QDialog::Accepted) // si oui
        {
            Recepteur r = choixRecepteur->recepteurChoisi();
            if(!ui->lineEditDesignation->text().isEmpty())
                r.setDesignation(ui->lineEditDesignation->text());

            r.setDescription(ui->textEditDescription->toPlainText());
            r.setQuantite(ui->spinBoxNbre->value());
            r.setDesignationDuParent(ui->comboBoxTableauParent->currentText());

            afficher(r);
        }

        delete choixRecepteur;
    }
}

void EvPuissMethod2::afficherPtesCourantTension(bool afficher)
{
    ui->labelCourant->setVisible(afficher);
    ui->spinBoxCourant->setVisible(afficher);
    ui->labelTension->setVisible(afficher);
    ui->comboBoxTension->setVisible(afficher);
}

void EvPuissMethod2::afficherPtesPUtile(bool afficher)
{
    ui->labelPU->setVisible(afficher);
    ui->doubleSpinBoxPUtile->setVisible(afficher);
    ui->comboBoxUnite->setVisible(afficher);
    ui->labelRend->setVisible(afficher);
    ui->doubleSpinBoxRend->setVisible(afficher);
}

Transformateur EvPuissMethod2::transformateur()const
{
    return *m_transformateur;
}

void EvPuissMethod2::setPptesDuTransfo(const Transformateur &transfo)
{
    float pUtiliseKW = m_transformateur->pUtilisation();
    *m_transformateur = transfo;
    m_transformateur->setPUtilisation(pUtiliseKW);

    setWindowModified(true);
    emit windowIsModified(true);
}

void EvPuissMethod2::on_btn_VoirTransfoAdapte_clicked()
{
    BDProprietesDesCpts * pptesDesCpts = new BDProprietesDesCpts(this);

    pptesDesCpts->setWindowTitle("Transformateur adapté");
    pptesDesCpts->afficherProprietes(*m_transformateur);
    pptesDesCpts->exec();

    delete pptesDesCpts;
}

bool EvPuissMethod2::fermer()
{
    if(sauvegarder())
    {
        fermerBDChoixRecepteur();
        close();
        return true;
    }else
    {
        return false;
    }
}

bool EvPuissMethod2::sauvegarder()
{
    if(isWindowModified())
    {
        int sortie = QMessageBox::warning(this, "Enregistrer le fichier en cours"
                             , "Désirez-vous enregistrer les dernières modifications apportées?", "Oui", "Non", "Annuler");
        switch(sortie)
        {
        case 0:
            return enregistrer(m_curFile);
            break;
        case 1:
            setWindowModified(false); // pour encourager la ferméture
            return true; // sans enregistrer
            break;
        case 2:
            return false;
            break;
        default:
            return false;
        }
    }else
    {
        return true;
    }
}

void EvPuissMethod2::nouveauFichier()
{
    static int sequenceNumber = 1;

    m_isUntitled = true;
    m_curFile = tr("document%1.iei").arg(sequenceNumber++);
    setWindowTitle(m_curFile + "[*]");
}

bool EvPuissMethod2::enregistrer(const QString &repertoire)
{
    if (m_isUntitled) {
        return enregistrerSous(repertoire);
    } else {
        return enregistrerFichier(m_curFile);
    }
}

bool EvPuissMethod2::enregistrerSous(const QString &repertoire)
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Enregistrer Sous"),
                                                    repertoire,tr("Documents Industria Elec 2012(*.iei)"));
    if (fileName.isEmpty())
        return false;

    return enregistrerFichier(fileName);
}

bool EvPuissMethod2::enregistrerFichier(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, tr("Industria Elec 2012"),
                             tr("Ne peut enregistrer le fichier %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QApplication::setOverrideCursor(Qt::WaitCursor);
    QDataStream out(&file);
    out << donnees();
    QApplication::restoreOverrideCursor();

    setFichierEnCours(fileName);
    return true;
}

QString EvPuissMethod2::currentFile()
{
    return m_curFile;
}

QStringList EvPuissMethod2::donnees()
{
    QStringList donnees;

    // transfo d'abord
    donnees << MOTCLE_TRANSFO
            << m_transformateur->infosDuTransfo()
            << MOTCLE_TRANSFO;

    // Tableau ensuite
    donnees << MOTCLE_TABLEAU // TGBT
            << m_tableaux.at(0).infosDuTableau()
            << MOTCLE_TABLEAU;

    QList<Tableau> l_ts;
    l_ts << tableaux(Tableau::TableauSecondaire);
    for(int i = 0; i < l_ts.count(); i++)
    {
        donnees << MOTCLE_TABLEAU
                << l_ts.at(i).infosDuTableau()
                << MOTCLE_TABLEAU;
    }

    QList<Tableau> l_td;
    l_td << tableaux(Tableau::CoffretDivisionnaire);
    for(int i = 0; i < l_td.count(); i++)
    {
        donnees << MOTCLE_TABLEAU
                << l_td.at(i).infosDuTableau()
                << MOTCLE_TABLEAU;
    }

    QList<Tableau> l_ter;
    l_ter << tableaux(Tableau::Terminal);
    for(int i = 0; i < l_ter.count(); i++)
    {
        donnees << MOTCLE_TABLEAU
                << l_ter.at(i).infosDuTableau()
                << MOTCLE_TABLEAU;
    }

    // enfin les récepteurs
    QList<Recepteur> l_re;
    l_re << m_recepteurs;
    for(int i = 0; i < l_re.count(); i++)
    {
        donnees << MOTCLE_RECEPTEUR
                << l_re.at(i).infosDuRecepteur()
                << MOTCLE_RECEPTEUR;
    }

    return donnees;
}

void EvPuissMethod2::setFichierEnCours(const QString &fileName)
{
    m_curFile = QFileInfo(fileName).canonicalFilePath();
    m_isUntitled = false;

    setWindowModified(false);
    setWindowTitle(userFriendlyCurrentFile() + "[*]");

    emit windowIsModified(false);
}

QString EvPuissMethod2::userFriendlyCurrentFile()
{
    return  QFileInfo(m_curFile).fileName();
}

bool EvPuissMethod2::chargerFichier(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text))
        return false;

    QDataStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    QStringList d;
    in >> d;

    if(!this->setDonnees(d))
    {
        QApplication::restoreOverrideCursor();
        return false;
    }

    QApplication::restoreOverrideCursor();

    setFichierEnCours(fileName);

    return true;
}

bool EvPuissMethod2::setDonnees(QStringList infos)
{
    int indexEnCours = 0;
    m_tableaux.clear();

    // transfo d'abord
    if(infos.at(indexEnCours) == MOTCLE_TRANSFO)
    {
        indexEnCours++;
        int indexFin = indexEnCours + Transformateur(1.2, 40).infosDuTransfo().count() - 1;

        QStringList info;
        for(int i = indexEnCours; i <= indexFin; i++)
        {
            info << infos.at(i);
        }

        if(Transformateur::infosTransfoValides(info))
        {
            *m_transformateur = *(new Transformateur(info));
        }else
            return 0;
        indexEnCours = indexFin++;
    }else
        return 0;

    int lgrInfosTableau = (new Tableau())->infosDuTableau().count();

    // le TGBT
    indexEnCours++;
    if(infos.at(indexEnCours) == MOTCLE_TABLEAU)
    {
        indexEnCours++;
        int indexFin = indexEnCours + lgrInfosTableau - 1;

        QStringList info;
        for(int i = indexEnCours; i <= indexFin; i++)
        {
            info << infos.at(i);
        }

        if(Tableau::infosTableauValides(info))
        {
            Tableau t = Tableau::infosToTableau(info);
            m_tableaux << t; // tgbt
        }else
            return 0;

        indexEnCours = indexFin;
        indexEnCours++;
    }

    // les tableaux ensuite
    indexEnCours++;
    while((infos.count() > indexEnCours) && (infos.at(indexEnCours) == MOTCLE_TABLEAU))
    {
        indexEnCours++;
        int indexFin = indexEnCours + lgrInfosTableau - 1;

        QStringList info;
        for(int i = indexEnCours; i <= indexFin; i++)
        {
            info << infos.at(i);
        }

        if(Tableau::infosTableauValides(info))
        {
            Tableau t = Tableau::infosToTableau(info);
            m_tableaux << t;
        }else
            return 0;

        indexEnCours = indexFin;
        indexEnCours += 2;
    }

    // recepteurs enfin
    int lgrInfosRe = (new Recepteur())->infosDuRecepteur().count();
    while((indexEnCours < infos.count()) &&  (infos.at(indexEnCours) == MOTCLE_RECEPTEUR))
    {
        indexEnCours++;
        int indexFin = indexEnCours + lgrInfosRe - 1;

        QStringList info;
        for(int i = indexEnCours; i <= indexFin; i++)
        {
            info << infos.at(i);
        }

        if(Recepteur::infosRecepteurValides(info))
        {
            Recepteur r(info);
            m_recepteurs << r;
        }else
            return 0;

        indexEnCours = indexFin;
        indexEnCours +=2;
    }

    afficher(m_recepteurs);
    afficher(m_tableaux);
    afficherInfosInst();

    on_comboBoxType2_currentIndexChanged(1); // TGBT

    on_comboBoxNature1_currentIndexChanged(0); // pour actualiser les parents
    return true;
}
