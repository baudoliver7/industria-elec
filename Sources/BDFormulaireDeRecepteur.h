#ifndef BDFORMULAIREDERECEPTEUR_H
#define BDFORMULAIREDERECEPTEUR_H

#include <QDialog>
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <QRadioButton>
#include <QSqlDatabase>

#include "Tableau.h"
#include "Recepteur.h"
#include "MesTypes.h"
#include "installation.h"
#include "BDChoixDeMoteur.h"

using namespace cstesRecepteur;

namespace Ui {
    class BDFormulaireDeRecepteur;
}

class BDFormulaireDeRecepteur : public QDialog {
    Q_OBJECT
public:
    BDFormulaireDeRecepteur(QWidget *parent = 0);
    BDFormulaireDeRecepteur(QWidget *parent, QString dbName, QString title, Installation * i, QString pere, bool editer = false, Recepteur r = Recepteur());
    ~BDFormulaireDeRecepteur();

    inline Recepteur recepteur()const{return m_recepteur;};
    inline bool isModified()const{return m_modifie;};
    inline void setEtatConnection(bool connected){ m_connected = connected;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDFormulaireDeRecepteur *ui;
    bool m_modifie;
    bool m_editer;
    bool m_affichage;
    QString m_pere;
    QString m_nomSauvegarder;
    Recepteur m_recepteur;
    Installation * m_installation;
    BDChoixDeMoteur * m_bdChoixDeMoteur;    
    bool m_connected;    
    QString m_dbName;

    void initialiserBtnPredefini();
    void initialiserTypeDeRecepteur();
    Recepteur::TypeDeDonneesAEntrer actualiserRadioButtonPuissanceUnitaire();
    void afficherRecepteur(const Recepteur & r);
    inline void modifierFormulaire(bool modifie){m_modifie = modifie;};

private slots:
    void on_btn_predefini_clicked();
    void on_radioButtonPutile_toggled(bool);
    void on_radioButtonPabsorbee_toggled(bool);
    void on_radioButtonCourant_Tension_toggled(bool);
    void on_Triphase_clicked();
    void on_Monophase_clicked();
    void on_comboBoxUnitePA_currentIndexChanged(int index);
    void on_comboBoxUnitePU_currentIndexChanged(int index);
    void on_comboBoxTypeDeRecepteur_currentIndexChanged(QString );
    void on_comboBoxTension_currentIndexChanged(QString );
    void on_doubleSpinBoxCourant_valueChanged(double );
    void on_radioButtonCourant_Tension_clicked();
    void on_radioButtonPabsorbee_clicked();
    void on_radioButtonPutile_clicked();
    void on_doubleSpinBoxKu_valueChanged(double );
    void on_doubleSpinBoxCosPhi_valueChanged(double );
    void on_doubleSpinBoxPabsorbee_valueChanged(double );
    void on_doubleSpinBoxRendement_valueChanged(double );
    void on_doubleSpinBoxPutile_valueChanged(double );
    void on_lineEditDesignation_textChanged(QString );
    void on_spinBoxQuantite_valueChanged(int );
    void on_btn_Annuler_clicked();
    void on_btn_OK_clicked();

    void setPUtileEnabled(bool);
    void setCourantTensionEnabled(bool);
    void setPAbsorbeeEnabled(bool);

private:
    static int nbRecepteursCrees;
};

#endif // BDFORMULAIREDERECEPTEUR_H
