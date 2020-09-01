#ifndef BDFORMULAIREDELOCAL_H
#define BDFORMULAIREDELOCAL_H

#include <QDialog>
#include <QString>

#include "Local.h"
#include "installation.h"

#define INITIAL "local "

namespace Ui {
    class BDFormulaireDeLocal;
}

class BDFormulaireDeLocal : public QDialog {
    Q_OBJECT
public:
    BDFormulaireDeLocal(QWidget * parent, QString title, Installation * i, QString pere, bool editer = false, Local local = Local());
    ~BDFormulaireDeLocal();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDFormulaireDeLocal *ui;
    Installation * m_installation;
    bool m_editer;
    bool m_afficher;
    Local m_local;
    QString m_localSauvegarde;
    QString m_pere;

    void afficherLocal(Local l);

private:
    static int sm_index;

private slots:
    void on_btn_OK_clicked();
    void on_btn_Annuler_clicked();
    void on_doubleSpinBoxSuperficie_valueChanged(double );
    void on_spinBoxPEstimee_valueChanged(int );
    void on_comboBoxTypeUtil_currentIndexChanged(QString );
    void on_comboBoxTypeLocal_currentIndexChanged(QString );
    void on_lineEditDesignation_textChanged(QString );
};

#endif // BDFORMULAIREDELOCAL_H
