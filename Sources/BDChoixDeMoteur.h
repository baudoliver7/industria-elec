#ifndef BDCHOIXDEMOTEUR_H
#define BDCHOIXDEMOTEUR_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QString>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QModelIndex>

#include "Recepteur.h"

namespace Ui {
    class BDChoixDeMoteur;
}

class BDChoixDeMoteur : public QDialog {
    Q_OBJECT
public:
    BDChoixDeMoteur(QString dbName, const Recepteur & r, QWidget *parent = 0);
    ~BDChoixDeMoteur();

    inline Recepteur recepteurChoisi()const{return m_recepteur;};
    inline void setRecepteur(const Recepteur & r){m_recepteur = r;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDChoixDeMoteur *ui;
    Recepteur m_recepteur;
    QStringList m_typesDeMoteur;
    QStringList m_typesMono;
    QStringList m_typesTri;
    QSqlTableModel * modelMono;
    QSqlTableModel * modelTri;
    QSqlTableModel * model;

    void setMoteurTri();
    void setMoteurMono();


private slots:
    void on_btn_Annuler_clicked();
    void on_btn_OK_clicked();
    void on_comboBoxTypeDeMoteur_currentIndexChanged(QString );
    void selectionnerMoteurs(QString type);
    void updateBtnOK(QModelIndex);
};

#endif // BDCHOIXDEMOTEUR_H
