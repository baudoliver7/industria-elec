#ifndef DIALOGNOUVELLEINSTALLATION_H
#define DIALOGNOUVELLEINSTALLATION_H

#include <QDialog>
#include <QPushButton>
#include <QMessageBox>

#include "InfosSurBD.h"

namespace Ui {
    class DialogNouvelleInstallation;
}

class DialogNouvelleInstallation : public QDialog {
    Q_OBJECT
public:
    enum InfosInstIndex
    {
        NomDeInst = 0, Theme = 1, Auteur = 2, NiveauScolaire = 3, Annee = 4, NbPages = 5
    };

public:
    DialogNouvelleInstallation(QWidget *parent = 0);
    ~DialogNouvelleInstallation();

   QString nomDeInstallation()const;
   QStringList infosInstallation()const;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogNouvelleInstallation *ui;
    QStringList m_themes;
    QStringList m_nomsDesInstallations;

    void gererActivationDeBtnOK();

private slots:
    void on_comboBoxThemes_editTextChanged(QString );
    void on_lineEditAuteur_textChanged(QString );
    void on_lineEditNomInstallation_textChanged(QString );
};

#endif // DIALOGNOUVELLEINSTALLATION_H
