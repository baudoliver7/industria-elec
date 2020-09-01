#ifndef INSTALLATIONGRAPHICDRIVER_H
#define INSTALLATIONGRAPHICDRIVER_H

#include "ComposantsInstallationElect_global.h"

#include <QGraphicsView>
#include <QAction>
#include <QMenu>
#include <QObject>
#include <QGraphicsSceneContextMenuEvent>

#include "installation.h"
#include "GroupeDeComposants.h"
#include "Cable.h"
#include "Composant.h"
#include "Constantes.h"

#define ESPACE 10.0

class GroupeDeComposants;
class Composant;
class Cable;

class COMPOSANTSINSTALLATIONELECTSHARED_EXPORT InstallationGraphicDriver : public QObject
{
    Q_OBJECT
signals:
    void creerNouveauTableau(const QString & designationParent, Tableau::TypeDeTableau type, int nombre);
    void editerTableau(const QString & designation);
    void supprimerTableau(const QString & designation);

    void creerNouveauRecepteur(const QString & designationParent, int nombre);
    void editerRecepteur(const QString & designation);
    void supprimerRecepteur(const QString & designation);

    void creerNouveauLocal(const QString & designationParent, int nombre);
    void editerLocal(const QString & designation);
    void supprimerLocal(const QString & designation);

    void editerTransfo();

    void definirExtension(bool definir);
    void itemIsSelected(bool selected, QString itemName = QString());
    void copierItem(QString designation);
    void collerItem(QString designation);
    void couperItem(QString designation);

    void clickSurTableauSec();
    void clickSurTableauDiv();
    void clickSurTableauTer();
    void clickSurTGBT();
    void clickSurRecepteur();
    void clickSurTransfo();

public:
    enum Canal
    {
        canalTranfo = 0, canalTGBT = 1, canalTS = 2, canalTD = 3, canalTerminal = 4, canalRecepteur = 5
    };

public:
    InstallationGraphicDriver(QGraphicsView * graphicsView, Installation * i);

    inline QGraphicsView * graphicsView(){return m_graphicsView;};

    void afficher();
    Composant * afficher(cstes::TypeDeComposant type, QString designation, float x, float y);
    void agrandir();
    void reduire();
    void afficherMenuContextuel(const Composant * cpt, QGraphicsSceneContextMenuEvent * e);
    Composant * composantSelectionne()const;
    void selectionnerUnComposant(QString designation);
    bool composantEnCoursCopiable()const;
    bool composantEnCoursEstUnTransfo()const;
    bool composantACopierEstCompatible()const;
    QString typeDeComposantEnCours()const;

    void setElementACopier(QString designation, QString typeDeComposant);
    QString ElementACopier()const;
    QString typeDeEltACopier()const;

public slots:
    void lancerSignalCreerNouveauTableau(const QString & designationParent, Tableau::TypeDeTableau type, int nombre = 1);
    void lancerSignalEditerTableau(const QString & designation);
    void lancerSignalSupprimerTableau(const QString & designation);

    void lancerSignalCreerNouveauRecepteur(const QString & designationParent, int nombre = 1);
    void lancerSignalEditerRecepteur(const QString & designation);
    void lancerSignalSupprimerRecepteur(const QString & designation);

    void lancerSignalCreerNouveauLocal(const QString & designationParent, int nombre = 1);
    void lancerSignalEditerLocal(const QString & designation);
    void lancerSignalSupprimerLocal(const QString & designation);

    void lancerSignalDefinirExtension(bool definir);
    void lancerSignalItemIsSelected(bool selected, QString itemName = QString());
    void lancerSignalCopierItem(QString designation);
    void lancerSignalCollerItem(QString designation);
    void lancerSignalCouperItem(QString designation);
    void lancerSignalEditerTransfo();

    void lancerSignalClickSurTableauSec();
    void lancerSignalClickSurTableauDiv();
    void lancerSignalClickSurTableauTer();
    void lancerSignalClickSurTGBT();
    void lancerSignalClickSurRecepteur();
    void lancerSignalClickSurTransfo();

private:
    Installation * m_installation;
    QGraphicsScene * m_scene;
    QList<float> m_niveaux;
    QGraphicsView * m_graphicsView;
    float m_scale;
    QString m_elementACopier;
    QString m_typeDeEltACopier;

    QMenu menu;
    QAction * actionAjouter;
    QMenu menuAjouter;
    QAction * actionTS;
    QAction * actionTD;
    QAction * actionTER;
    QAction * actionRecepteur;
    QAction * actionLocal;
    QAction * actionEditer;
    QAction * actionCopier;
    QAction * actionCouper;
    QAction * actionColler;
    QAction * actionSupprimer;

    void sousMenuDeQuantite(QAction * action, QString suffixe);
    QString accorderSuffixe(int nombre, QString suffixe);
    int nombre(QAction * actionQuantite);
    void initialiserActions();
    void mettreAjourEtatsActions(const Composant * cpt);
    void choisirActionTableau(QAction * actionSelected, const Composant * cpt);
    void choisirActionRecepteur(QAction * actionSelected, const Composant * cpt);
    void choisirActionLocal(QAction * actionSelected, const Composant * cpt);
    void connecter(Composant * pere, Composant * fils);
    void connecter(Composant * pere, GroupeDeComposants fils, float espacement);
    void connecter(Composant * pere, GroupeDeComposants fils, QList<float> espacements);

    Composant * composant(const Tableau & t);
    Composant * composant(const Recepteur & r);
    Composant * composant(const Local & l);

    Composant * afficherTGBT(Composant * transfo);
    Composant * afficherTransfo();

    void afficherSousInstallation(const Tableau & pere, Composant * pereCpt);

    GroupeDeComposants group(const QList<Tableau> & lt);
    GroupeDeComposants group(const QList<Recepteur> & lr);
    GroupeDeComposants group(const QList<Local> &ll);

    float Li(const Tableau & t);
    float Li(const Recepteur & r);
    float Li(const Local & l);

    float largeurDeSousInstallation(const Tableau & pere);
    QList<float> espacementsFils(const Tableau & t);

    float espacement(Tableau t1, Tableau t2);
    float espacement(Tableau t, Local l);
    float espacement(Tableau t, Recepteur r);
    float espacement(Local l1, Local l2);
    float espacement(Recepteur r, Local l);
    float espacement(Recepteur r1, Recepteur r2);

    QList<float> longueurs(QList<Tableau> lt);
    QList<float> longueurs(QList<Recepteur> lr);
    QList<float> longueurs(QList<Local> ll);

    float espace(); // espace sous échelle

    void mettreAjourNiveaux();

private slots:
    void preparerEtLancerSignalItemIsSelected();
};

#endif // INSTALLATIONGRAPHICDRIVER_H
