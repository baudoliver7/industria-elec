#ifndef INSTALLATIONGRAPHIQUE_H
#define INSTALLATIONGRAPHIQUE_H

#include "ComposantsInstallationElect_global.h"

#include <QGraphicsView>

#include "installation.h"
#include "GroupeDeComposants.h"
#include "Cable.h"
#include "Composant.h"

#define ESPACE 10.0

class GroupeDeComposants;
class Composant;
class Cable;

class COMPOSANTSINSTALLATIONELECTSHARED_EXPORT InstallationGraphique : public QGraphicsView
{
    Q_OBJECT
signals:
    void creerNouveauTableau(const QString & designationParent, Tableau::TypeDeTableau type, int nombre);
    void editerTableau(const QString & designation);
    void supprimerTableau(const QString & designation);

    void creerNouveauRecepteur(const QString & designationParent, int nombre);
    void editerRecepteur(const QString & designation);
    void supprimerRecepteur(const QString & designation);
    //void dupliquerRecepteur(const QString & designation);
    void definirExtension(bool definir);
    void itemIsSelected(bool selected, QString itemName = QString());

public:
    enum Canal
    {
        canalTranfo = 0, canalTGBT = 1, canalTS = 2, canalTD = 3, canalTerminal = 4, canalRecepteur = 5
    };

public:
    InstallationGraphique(Installation * i);

    void afficher();

    void agrandir();
    void reduire();

public slots:
    void lancerSignalCreerNouveauTableau(const QString & designationParent, Tableau::TypeDeTableau type, int nombre = 1);
    void lancerSignalEditerTableau(const QString & designation);
    void lancerSignalSupprimerTableau(const QString & designation);

    void lancerSignalCreerNouveauRecepteur(const QString & designationParent, int nombre = 1);
    void lancerSignalEditerRecepteur(const QString & designation);
    void lancerSignalSupprimerRecepteur(const QString & designation);
    //void lancerSignalDupliquerRecepteur(const QString & designation);
    void lancerSignalDefinirExtension(bool definir);
    void lancerSignalItemIsSelected(bool selected, QString itemName = QString());

private:
    Installation * m_installation;
    QGraphicsScene * m_scene;
    QList<float> m_niveaux;
    float m_scale;

    void connecter(Composant * pere, Composant * fils);
    void connecter(Composant * pere, GroupeDeComposants fils, float espacement);
    void connecter(Composant * pere, GroupeDeComposants fils, QList<float> espacements);

    Composant * composant(const Tableau & t);
    Composant * composant(const Recepteur & r);
//    Composant * composant(Composant::TypeDeComposant type, const QString & designation = QString(), Composant::PositionDeTexte position = Composant::TextCentre);
    //inline void affiche(Composant::PositionDeTexte type){};

    Composant * afficherTGBT(Composant * transfo);
    Composant * afficherTransfo();

    void construireSousInstallation(const Tableau & pere, Composant * ref);

    GroupeDeComposants group(const QList<Tableau> & lt);
    GroupeDeComposants group(const QList<Recepteur> & lr);

    float Li(const Tableau & t);
    float Li(const Recepteur & r);

    float largeurDeSousInstallation(const Tableau & pere);
    QList<float> espacementFils(const Tableau & t);

    void initialiserNiveaux();
};

#endif // INSTALLATIONGRAPHIQUE_H
