#ifndef BDFORMULAIREDETABLEAU_H
#define BDFORMULAIREDETABLEAU_H

#include <QDialog>
#include <QString>
#include <QStringList>
#include <QList>
#include <QMessageBox>

#include "Tableau.h"
#include "installation.h"
#include "MesTypes.h"

using namespace cstesRecepteur;

namespace Ui {
    class BDFormulaireDeTableau;
}

class BDFormulaireDeTableau : public QDialog {
    Q_OBJECT
public:
    BDFormulaireDeTableau(QWidget *parent, QString title, Installation * i, QString pere, Tableau::TypeDeTableau type, bool editer = false, Tableau tableau = Tableau());
    ~BDFormulaireDeTableau();

    Tableau tableau()const;
    inline bool isModified()const{return m_modifie;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDFormulaireDeTableau *ui;
    bool m_editer;
    bool m_modifie;
    QString m_nomSauvegarder;
    Tableau m_tableau;
    bool m_affichage;
    QString m_pere;
    Installation * m_installation;

    inline void modifierFormulaire(bool modifie){m_modifie = modifie;};

private slots:
    void on_doubleSpinBoxKs_valueChanged(double );
    void on_lineEditDesignation_textChanged(QString );
    void on_btn_annuler_clicked();
    void on_btn_OK_clicked();

private:
    inline void EditerTableau(bool editer){m_editer = editer;};
    void afficherTableau(const Tableau & tableau);

private:
    static int nbTableauCrees;
    static int idTS;
    static int idTD;
    static int idTER;
};

#endif // BDFORMULAIREDETABLEAU_H
