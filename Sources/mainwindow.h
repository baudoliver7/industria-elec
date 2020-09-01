#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QCloseEvent>
#include <QSettings>
#include <QDesktopServices>
#include <QUrl>
#include <QProcess>
#include <qprinter.h>
#include <QPrintPreviewDialog>

#include "EvPuissMethod1.h"
#include "BDProprietesDesCpts.h"
#include "Transformateur.h"
#include "BDParamTransfo.h"
#include "EvPuissMethod2.h"
#include "BDApropos.h"
#include "FrmAccueil.h"

#include "ncreport.h"
#include "ncreportoutput.h"
#include "ncreportpreviewoutput.h"
#include "ncreportpreviewwindow.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void agrandir();
    void reduire();
    void creerUnTableau(QString parent, Tableau::TypeDeTableau type);
    void creerUnRecepteur(QString parent, Recepteur::TypeDeRecepteur type);
    void creerUnLocal(QString parent);

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *);

private:
    Ui::MainWindow *ui;
    bool m_FenMethod1Affichee;
    BDProprietesDesCpts * m_bdProprietesDesCpts;
    FrmAccueil * m_frmAccueil;
    QString m_elementACopier;
    QString m_elementSelectionne;
    QString m_typeElementAcopier;
    QString m_typeElementSelectionne;    
    bool m_copier;
    QString m_repertoirePrecedent;
    EvPuissMethod1 * m_evPuissMethod1;

    EvPuissMethod1 * activeMdiBilanDePuissanceMethod1();
    EvPuissMethod2 * activeMdiBilanDePuissanceMethod2();

    void ouvrir();
    void enregistrer();
    void enregistrerSous();
    void fermer();
    EvPuissMethod1 * creerMdiEvPuissMethod1();
    EvPuissMethod2 * creerMdiEvPuissMethod2();
    FrmAccueil * initFrmAccueil();
    QString repertoireDuFichier(QString fileName);
    NCReport * createReportM2(EvPuissMethod2 * ev2, NCReportOutput * output);

private slots:    
    void on_actionAideSurIndustriaElec_triggered();
    void on_actionApropos_triggered();
    void on_actionMethodeIndustrielle_triggered();
    void on_actionEnregistrerSous_triggered();
    void on_actionEnregistrer_triggered();
    void on_actionOuvrirUnFichier_triggered();
    void on_actionFermerFichierEnCours_triggered();
    void on_actionMethodeUsuelle_triggered();
    void setEnabledAllerEnArriere(bool enabled);
    void setEnabledAllerEnAvant(bool enabled);
    void on_actionAllerEnArriere_triggered();
    void on_actionAllerEnAvant_triggered();
    void on_actionD_finir_extension_triggered();
    void on_actionQuitter_triggered();
    void on_actionEditer_triggered();
    void on_actionSupprimer_triggered();
    void on_actionCouper_triggered();
    void on_actionCopier_triggered();
    void on_actionColler_triggered();
    void on_actionZoomMoins_triggered();
    void on_actionZoomPlus_triggered();
    void afficherBDProprietes(bool afficher);
    void fermerBDProprietes();
    void newMdiBilanDePuissanceMethod1();
    void updateEtatsBtns(bool, QString);
    void preparerCopie();
    void preparerCouper();
    void initialiserEtatsBtns();    
    void newFrmAccueil();
    void on_actionPage_demarrage_triggered();
    void terminerFrmAccueil();
    void on_actionTransformateur_triggered();
    void changerCurseur(QString fileName);
    void on_actionTGBT_triggered();
    void on_actionTableau_divisionnaire_triggered();
    void on_actionTableau_secondaire_triggered();
    void on_actionTerminal_triggered();
    void on_actionRecepteur_simple_triggered();
    void on_actionEclairage_triggered();
    void on_actionChauffage_triggered();
    void on_actionConditionneur_air_triggered();
    void on_actionForce_motrice_triggered();
    void on_actionPrise_de_courant_triggered();
    void on_actionLocal_triggered();
    void on_actionFleche_triggered();
    void on_actionCable_triggered();
    void on_actionGomme_triggered();
    void updateEtatsActionTransfo();
    void updateEtatsActionCptsTGBT();
    void updateEtatsActionCptsTS();
    void updateEtatsActionCptsTD();
    void updateEtatsActionCptsTer();
    void updateEtatsActionCptsRecepteur();
    void disabledEtatsActionCpts(bool isItemSelected);
    void on_actionImprimerInstallation_triggered();
    void printBilanMethod1(QPrinter * printer);
    void on_actionApercu_avant_impression_triggered();
};

#endif // MAINWINDOW_H
