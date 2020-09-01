#ifndef EVPUISSMETHOD1_H
#define EVPUISSMETHOD1_H

#include <QWidget>
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFileDialog>
#include <QProcess>

#include "InstallationGraphicDriver.h"
#include "BDFormulaireDeTableau.h"
#include "BDFormulaireDeRecepteur.h"
#include "installation.h"
#include "DialogNbDeElement.h"
#include "BDFormulaireDeLocal.h"
#include "MesConstantes.h"

#define PLEINE_FENETRE "Pleine fenêtre"
#define RETRECIR "Rétrécir"
#define NBMAX_SAUVEGARDE 10

using namespace DbName;

namespace Ui {
    class EvPuissMethod1;
}

class EvPuissMethod1 : public QWidget {
    Q_OBJECT

signals:
    void closed();
    void etatChanged();
    void enableAllerEnArriere(bool enabled);
    void enableAllerEnAvant(bool enabled);
    void windowIsModified(bool modified);

public:
    EvPuissMethod1(QWidget *parent = 0);
    ~EvPuissMethod1();

    Installation * installation();
    InstallationGraphicDriver * driverGraphics(){return m_driverGraphicsView;};
    void afficherTout();    
    void dupliquerSousInstallation(QString pere, QString sousPere);
    bool debrancherUnComposant(QString element);
    bool brancherUnComposant(QString element, QString pere);
    void supprimerUnComposant(QString element);
    void editerUnComposant(QString element);
    QStringList donnees()const;
    bool setDonnees(const QStringList data);
    void allerEnAvant();
    void allerEnArriere();

    void nouveauFichier();
    bool enregistrerSous(const QString & repertoire);
    bool enregistrer(const QString & repertoire);
    bool enregistrerFichier(const QString & fileName);
    bool chargerFichier(const QString & fileName);
    bool fermer();
    bool sauvegarder();
    QString currentFile() { return m_curFile; }
    QString getFullFileName();

public slots:
    void setInstallation(const Installation & i);
    void agrandirInstallationGraphic();
    void reduireInstallationGraphic();
    void supprimerUnTableau(const QString & designation);
    void supprimerUnRecepteur(const QString & designation);
    void supprimerUnLocal(const QString & designation);

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *e);

private:
    Ui::EvPuissMethod1 *ui;
    Installation * m_installation;
    QGraphicsScene * m_scene;
    QList<Recepteur> m_recepteurs;
    InstallationGraphicDriver * m_driverGraphicsView;
    bool m_bdLocauxConnectee;     
    int m_indexSauvegardeEnCours;
    QList<Installation> m_sauvegardes;
    QString m_curFile;
    bool m_isUntitled;
    QString m_dirBD;

    void initialiserGraphisme();
    void initialiserTGBT();
    QList<Tableau> tableaux() const;
    QList<Recepteur> recepteurs() const;

    void dupliquerUnTableau(QString pere, QString designation);
    void dupliquerUnRecepteur(QString pere, QString designation);
    void dupliquerUnLocal(QString pere, QString designation);
    QString designationDupliquee(QString designation);
    int indexMAX(QString initial);
    void supprimerFinal(QString & designation);
    bool finalExisteDans(QString designation);
    void reconstruireSousInstallation(QString tableauFils, QString pere);
    bool seConnecterABDLocaux();
    bool seConnecterABDChoixRecepteur();
    void fermerBDLocaux();
    void fermerBDChoixRecepteur();
    void setFichierEnCours(const QString & fileName);
    QString userFriendlyCurrentFile();
    QString strippedName(const QString & fullFileName);

private slots:
    void sauvegarderEtat();
    void editerUnTableau(const QString & designation);

    bool creerUnNouveauTableau(QString title, QString designationParent, Tableau::TypeDeTableau type);
    void creerDirectUnNouveauTableau(QString designationParent, Tableau::TypeDeTableau type);
    void creerDesNouveauxTableaux(const QString &designationParent, Tableau::TypeDeTableau type, int nombre = 1);

    bool creerUnNouveauRecepteur(QString title, QString designationParent);
    void creerDirectUnNouveauRecepteur(QString designationParent, Recepteur::TypeDeRecepteur type);
    void creerDesNouveauxRecepteurs(const QString &designationParent, int nombre = 1);
    void editerUnRecepteur(const QString &designation);

    bool creerUnNouveauLocal(QString title, QString designationParent);
    void creerDirectUnNouveauLocal(QString designationParent);
    void creerDesNouveauxLocaux(QString designationParent, int nombre = 1);
    void editerUnLocal(QString designation);    

private:    
    static bool m_bdChoixRecepteurConnectee;
};

#endif // EVPUISSMETHOD1_H
