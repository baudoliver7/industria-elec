#ifndef BDPARAMTRANSFO_H
#define BDPARAMTRANSFO_H

#include <QDialog>
#include "installation.h"
#include "Transformateur.h"

namespace Ui {
    class BDParamTransfo;
}

class BDParamTransfo : public QDialog {
    Q_OBJECT
public:
    BDParamTransfo(Installation * i, QWidget *parent = 0);
    BDParamTransfo(const Transformateur & transfo, QWidget *parent = 0);
    ~BDParamTransfo();

    inline bool isModified(){return m_modified;};
    inline Transformateur transformateur()const{return *transfo;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDParamTransfo *ui;
    Installation * m_installation;
    Transformateur * transfo;
    bool m_affichage;
    bool m_modified;

    void afficherProprietes();

private slots:
    void on_btn_Annuler_clicked();
    void on_btn_OK_clicked();
    void on_spinBoxTempAmb_valueChanged(int );
    void on_doubleSpinBoxExtension_valueChanged(double );
};

#endif // BDPARAMTRANSFO_H
