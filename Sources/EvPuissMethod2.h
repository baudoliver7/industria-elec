#ifndef EVPUISSMETHOD2_H
#define EVPUISSMETHOD2_H

#include <QWidget>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <math.h>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFileDialog>
#include <QCloseEvent>
#include <QProcess>

#include "Recepteur.h"
#include "Tableau.h"
#include "BDChoixDeMoteur.h"
#include "Transformateur.h"
#include "BDProprietesDesCpts.h"
#include "MesConstantes.h"

#define DESIGNATION 0
#define DESCRIPTION 1
#define PUTILE 2
#define COSPHI 3
#define NOMBRE 4
#define PINSTALLEE 5
#define _QINSTALLEE 6
#define PUTILISEE 7
#define _QUTILISEE 8
#define PARENT 9

#define INCONNU "Inconnu"

#define MODIFIER "Modifier"
#define ENREGISTRER "Ajouter"

using namespace cstesRecepteur;
using namespace DbName;

namespace Ui {
    class EvPuissMethod2;
}

class EvPuissMethod2 : public QWidget {
    Q_OBJECT
public:
    EvPuissMethod2(QWidget *parent = 0);
    ~EvPuissMethod2();

    Transformateur transformateur()const;
    void setPptesDuTransfo(const Transformateur & transfo);
    bool fermer();
    bool sauvegarder();
    void nouveauFichier();
    bool enregistrer(const QString & repertoire);
    bool enregistrerSous(const QString & repertoire);
    bool enregistrerFichier(const QString & fileName);
    QString currentFile();
    bool chargerFichier(const QString &fileName);
    QList<Tableau> getAllTableaux()const{return m_tableaux;};
    QList<Recepteur> getAllRecepteurs()const{return m_recepteurs;};

    float PUtiliseeKW(const Tableau & pere);
    float PInstalleeKW(const Tableau & pere);
    float _QUtiliseeKW(const Tableau & pere);
    float _QInstalleeKW(const Tableau & pere);
    float cosPhi(const Tableau & pere);

signals:
    void closed();
    void windowIsModified(bool modified);

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *e);

private:
    Ui::EvPuissMethod2 *ui;

    QList<Tableau> m_tableaux;
    QList<Recepteur> m_recepteurs;
    bool m_afficher;
    bool m_bdChoixRecepteurConnectee;
    Recepteur m_recepteurSauvegarde;
    Tableau m_tableauSauvegarde;    
    Transformateur * m_transformateur;
    bool m_isUntitled;
    QString m_curFile;
    QString m_dirBD;

private slots:
    void on_btn_VoirTransfoAdapte_clicked();
    void on_btn_predefini_clicked();
    void on_btn_supprimer_clicked();
    void updateEtatModifierSupprimer(QModelIndex);
    void on_btn_modifier_clicked();
    void on_comboBoxNature2_currentIndexChanged(int index);
    void on_btn_initialiser_clicked();
    void on_lineEditDesignation_textChanged(QString );
    void on_comboBoxNature1_currentIndexChanged(int index);
    void on_btn_enregistrer_clicked();
    void on_comboBoxType2_currentIndexChanged(int index);
    void on_comboBoxType1_currentIndexChanged(int index);

private:
    void ajouterUnTableau(const Tableau & t);
    void ajouterUnRecepteur(const Recepteur & r);
    void afficherUneCase(int row, int column, QString text);
    void afficherUneLigne(int row, const Tableau & t);
    void afficherUneLigne(int row, const Recepteur & r);
    QStringList nomsDesTableaux();
    QStringList nomsDesRecepteurs();
    QStringList nomsDesTableaux(QList<Tableau> lt);
    float kc(Tableau::TypeDeTableau typeT, Recepteur r);
    float kcPCTD(Recepteur r);
    float kcPCTS(Recepteur r);
    float kcPCTGBT(Recepteur r);
    void initialiser();
    void afficher(const Tableau & t);
    void afficher(const Recepteur & r);
    void afficher(QList<Tableau> lt);
    void afficher(QList<Recepteur> lr);
    void afficherInfosInst();
    void supprimer(Recepteur r);
    void supprimer(Tableau t);
    QList<Recepteur> recepteurs(const Tableau & pere, Recepteur::TypeDeRecepteur type);
    QList<Recepteur> recepteurs(Recepteur::TypeDeRecepteur type);
    QList<Tableau> tableaux(Tableau::TypeDeTableau type);
    float puissanceUtileKW(QList<Recepteur> lr);
    float puissanceUtiliseeKW(QList<Recepteur> lr, Tableau::TypeDeTableau type);
    float puissanceInstalleeKW(QList<Recepteur> lr);
    float qUtiliseeKW(QList<Recepteur> lr, Tableau::TypeDeTableau type);
    float qInstalleeKW(QList<Recepteur> lr);
    bool seConnecterABDChoixRecepteur();
    void fermerBDChoixRecepteur();

    float PAucunTypeKW(const Tableau & pere, bool installee);
    float PEclairageKW(const Tableau & pere, bool installee);
    float PChauffageKW(const Tableau & pere, bool installee);
    float PConditionneurAirKW(const Tableau & pere, bool installee);
    float PForceMotriceKW(const Tableau & pere, bool installee);
    float PPriseCourantKW(const Tableau & pere, bool installee);

    float _QAucunTypeKW(const Tableau & pere, bool installee);
    float _QEclairageKW(const Tableau & pere, bool installee);
    float _QChauffageKW(const Tableau & pere, bool installee);
    float _QConditionneurAirKW(const Tableau & pere, bool installee);
    float _QForceMotriceKW(const Tableau & pere, bool installee);
    float _QPriseCourantKW(const Tableau & pere, bool installee);    

    void afficherPtesCourantTension(bool afficher);
    void afficherPtesPUtile(bool afficher);

    QStringList donnees();
    bool setDonnees(QStringList d);
    void setFichierEnCours(const QString &fileName);
    QString userFriendlyCurrentFile();


};

#endif // EVPUISSMETHOD2_H
