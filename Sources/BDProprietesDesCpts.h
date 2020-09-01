#ifndef BDPROPRIETESDESCPTS_H
#define BDPROPRIETESDESCPTS_H

#include <QDialog>
#include "installation.h"
#include "Transformateur.h"

#define TRANSFO 0
#define TABLEAU 1
#define MATERIEL_PA 2
#define MATERIEL_PU 3
#define MATERIEL_CT 4
#define LOCAL 5

namespace Ui {
    class BDProprietesDesCpts;
}

class BDProprietesDesCpts : public QDialog {
    Q_OBJECT
public:
    BDProprietesDesCpts(QWidget *parent = 0);
    BDProprietesDesCpts(Installation *i, QWidget *parent = 0);
    ~BDProprietesDesCpts();

public slots:
    void afficherProprietes(bool afficher, QString designation);
    void afficherProprietes(const Transformateur & transfo);

protected:
    void changeEvent(QEvent *e);

    void afficherTableau(Tableau t);
    void afficherTransfo(Transformateur t);
    void afficherLocal(Local l);
    void afficherMateriel(Recepteur r);

private:
    Ui::BDProprietesDesCpts *ui;
    Installation * m_installation;
    QStringList m_tabText;
    bool monophase;

    void afficherOnglet(int index);
    QWidget * tab(int index);


private slots:
    void on_Triphase_clicked();
    void on_Monophase_clicked();
};

#endif // BDPROPRIETESDESCPTS_H
