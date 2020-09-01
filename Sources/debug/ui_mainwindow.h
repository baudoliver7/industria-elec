/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionProprietesDesCpts;
    QAction *actionCopier;
    QAction *actionColler;
    QAction *actionZoomPlus;
    QAction *actionZoomMoins;
    QAction *actionCouper;
    QAction *actionSupprimer;
    QAction *actionEditer;
    QAction *actionMethodeUsuelle;
    QAction *actionMethodeIndustrielle;
    QAction *actionOuvrirUnFichier;
    QAction *actionImprimerInstallation;
    QAction *actionFermerFichierEnCours;
    QAction *actionQuitter;
    QAction *actionEnregistrer;
    QAction *actionEnregistrerSous;
    QAction *actionD_finir_extension;
    QAction *actionAideSurIndustriaElec;
    QAction *actionApropos;
    QAction *actionAllerEnAvant;
    QAction *actionAllerEnArriere;
    QAction *actionPage_demarrage;
    QAction *actionTransformateur;
    QAction *actionTGBT;
    QAction *actionTableau_secondaire;
    QAction *actionTableau_divisionnaire;
    QAction *actionTerminal;
    QAction *actionRecepteur_simple;
    QAction *actionEclairage;
    QAction *actionChauffage;
    QAction *actionConditionneur_air;
    QAction *actionForce_motrice;
    QAction *actionPrise_de_courant;
    QAction *actionLocal;
    QAction *actionFleche;
    QAction *actionCable;
    QAction *actionGomme;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuNouveau;
    QMenu *menuEdition;
    QMenu *menuAffichage;
    QMenu *menuAide;
    QMenu *menuParametres;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(783, 480);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionProprietesDesCpts = new QAction(MainWindow);
        actionProprietesDesCpts->setObjectName(QStringLiteral("actionProprietesDesCpts"));
        actionProprietesDesCpts->setCheckable(true);
        actionCopier = new QAction(MainWindow);
        actionCopier->setObjectName(QStringLiteral("actionCopier"));
        actionColler = new QAction(MainWindow);
        actionColler->setObjectName(QStringLiteral("actionColler"));
        actionZoomPlus = new QAction(MainWindow);
        actionZoomPlus->setObjectName(QStringLiteral("actionZoomPlus"));
        actionZoomMoins = new QAction(MainWindow);
        actionZoomMoins->setObjectName(QStringLiteral("actionZoomMoins"));
        actionCouper = new QAction(MainWindow);
        actionCouper->setObjectName(QStringLiteral("actionCouper"));
        actionSupprimer = new QAction(MainWindow);
        actionSupprimer->setObjectName(QStringLiteral("actionSupprimer"));
        actionEditer = new QAction(MainWindow);
        actionEditer->setObjectName(QStringLiteral("actionEditer"));
        actionMethodeUsuelle = new QAction(MainWindow);
        actionMethodeUsuelle->setObjectName(QStringLiteral("actionMethodeUsuelle"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/new_mt2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMethodeUsuelle->setIcon(icon1);
        actionMethodeIndustrielle = new QAction(MainWindow);
        actionMethodeIndustrielle->setObjectName(QStringLiteral("actionMethodeIndustrielle"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/new_mi_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMethodeIndustrielle->setIcon(icon2);
        actionOuvrirUnFichier = new QAction(MainWindow);
        actionOuvrirUnFichier->setObjectName(QStringLiteral("actionOuvrirUnFichier"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/open_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOuvrirUnFichier->setIcon(icon3);
        actionImprimerInstallation = new QAction(MainWindow);
        actionImprimerInstallation->setObjectName(QStringLiteral("actionImprimerInstallation"));
        actionFermerFichierEnCours = new QAction(MainWindow);
        actionFermerFichierEnCours->setObjectName(QStringLiteral("actionFermerFichierEnCours"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionEnregistrer = new QAction(MainWindow);
        actionEnregistrer->setObjectName(QStringLiteral("actionEnregistrer"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnregistrer->setIcon(icon4);
        actionEnregistrerSous = new QAction(MainWindow);
        actionEnregistrerSous->setObjectName(QStringLiteral("actionEnregistrerSous"));
        actionD_finir_extension = new QAction(MainWindow);
        actionD_finir_extension->setObjectName(QStringLiteral("actionD_finir_extension"));
        actionAideSurIndustriaElec = new QAction(MainWindow);
        actionAideSurIndustriaElec->setObjectName(QStringLiteral("actionAideSurIndustriaElec"));
        actionApropos = new QAction(MainWindow);
        actionApropos->setObjectName(QStringLiteral("actionApropos"));
        actionAllerEnAvant = new QAction(MainWindow);
        actionAllerEnAvant->setObjectName(QStringLiteral("actionAllerEnAvant"));
        actionAllerEnArriere = new QAction(MainWindow);
        actionAllerEnArriere->setObjectName(QStringLiteral("actionAllerEnArriere"));
        actionPage_demarrage = new QAction(MainWindow);
        actionPage_demarrage->setObjectName(QStringLiteral("actionPage_demarrage"));
        actionTransformateur = new QAction(MainWindow);
        actionTransformateur->setObjectName(QStringLiteral("actionTransformateur"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/transfo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTransformateur->setIcon(icon5);
        actionTGBT = new QAction(MainWindow);
        actionTGBT->setObjectName(QStringLiteral("actionTGBT"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/TGBT.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTGBT->setIcon(icon6);
        actionTableau_secondaire = new QAction(MainWindow);
        actionTableau_secondaire->setObjectName(QStringLiteral("actionTableau_secondaire"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/TS.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTableau_secondaire->setIcon(icon7);
        actionTableau_divisionnaire = new QAction(MainWindow);
        actionTableau_divisionnaire->setObjectName(QStringLiteral("actionTableau_divisionnaire"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/TD.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTableau_divisionnaire->setIcon(icon8);
        actionTerminal = new QAction(MainWindow);
        actionTerminal->setObjectName(QStringLiteral("actionTerminal"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/TER.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTerminal->setIcon(icon9);
        actionRecepteur_simple = new QAction(MainWindow);
        actionRecepteur_simple->setObjectName(QStringLiteral("actionRecepteur_simple"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/autre r\303\251cepteur.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRecepteur_simple->setIcon(icon10);
        actionEclairage = new QAction(MainWindow);
        actionEclairage->setObjectName(QStringLiteral("actionEclairage"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/images/eclairage.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEclairage->setIcon(icon11);
        actionChauffage = new QAction(MainWindow);
        actionChauffage->setObjectName(QStringLiteral("actionChauffage"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/images/Chauffage.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChauffage->setIcon(icon12);
        actionConditionneur_air = new QAction(MainWindow);
        actionConditionneur_air->setObjectName(QStringLiteral("actionConditionneur_air"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/images/climatiseur.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConditionneur_air->setIcon(icon13);
        actionForce_motrice = new QAction(MainWindow);
        actionForce_motrice->setObjectName(QStringLiteral("actionForce_motrice"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/images/moteur.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionForce_motrice->setIcon(icon14);
        actionPrise_de_courant = new QAction(MainWindow);
        actionPrise_de_courant->setObjectName(QStringLiteral("actionPrise_de_courant"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/images/prise de courant.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrise_de_courant->setIcon(icon15);
        actionLocal = new QAction(MainWindow);
        actionLocal->setObjectName(QStringLiteral("actionLocal"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/images/Local_ecl.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLocal->setIcon(icon16);
        actionFleche = new QAction(MainWindow);
        actionFleche->setObjectName(QStringLiteral("actionFleche"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/images/fleche.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        actionFleche->setIcon(icon17);
        actionCable = new QAction(MainWindow);
        actionCable->setObjectName(QStringLiteral("actionCable"));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/images/liaison.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCable->setIcon(icon18);
        actionGomme = new QAction(MainWindow);
        actionGomme->setObjectName(QStringLiteral("actionGomme"));
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/images/gomme.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGomme->setIcon(icon19);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 783, 21));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuNouveau = new QMenu(menuFichier);
        menuNouveau->setObjectName(QStringLiteral("menuNouveau"));
        menuEdition = new QMenu(menubar);
        menuEdition->setObjectName(QStringLiteral("menuEdition"));
        menuAffichage = new QMenu(menubar);
        menuAffichage->setObjectName(QStringLiteral("menuAffichage"));
        menuAide = new QMenu(menubar);
        menuAide->setObjectName(QStringLiteral("menuAide"));
        menuParametres = new QMenu(menubar);
        menuParametres->setObjectName(QStringLiteral("menuParametres"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setIconSize(QSize(32, 32));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuEdition->menuAction());
        menubar->addAction(menuParametres->menuAction());
        menubar->addAction(menuAffichage->menuAction());
        menubar->addAction(menuAide->menuAction());
        menuFichier->addAction(menuNouveau->menuAction());
        menuFichier->addAction(actionOuvrirUnFichier);
        menuFichier->addSeparator();
        menuFichier->addAction(actionEnregistrer);
        menuFichier->addAction(actionEnregistrerSous);
        menuFichier->addSeparator();
        menuFichier->addAction(actionFermerFichierEnCours);
        menuFichier->addSeparator();
        menuFichier->addAction(actionImprimerInstallation);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuNouveau->addAction(actionMethodeUsuelle);
        menuNouveau->addAction(actionMethodeIndustrielle);
        menuEdition->addAction(actionAllerEnAvant);
        menuEdition->addAction(actionAllerEnArriere);
        menuEdition->addSeparator();
        menuEdition->addAction(actionCopier);
        menuEdition->addAction(actionCouper);
        menuEdition->addAction(actionColler);
        menuEdition->addAction(actionSupprimer);
        menuEdition->addSeparator();
        menuEdition->addAction(actionEditer);
        menuEdition->addSeparator();
        menuEdition->addAction(actionZoomPlus);
        menuEdition->addAction(actionZoomMoins);
        menuAffichage->addAction(actionProprietesDesCpts);
        menuAffichage->addAction(actionPage_demarrage);
        menuAide->addAction(actionAideSurIndustriaElec);
        menuAide->addSeparator();
        menuAide->addAction(actionApropos);
        menuParametres->addAction(actionD_finir_extension);
        toolBar->addAction(actionMethodeUsuelle);
        toolBar->addAction(actionMethodeIndustrielle);
        toolBar->addAction(actionOuvrirUnFichier);
        toolBar->addAction(actionEnregistrer);
        toolBar->addSeparator();
        toolBar->addAction(actionTableau_secondaire);
        toolBar->addAction(actionTableau_divisionnaire);
        toolBar->addAction(actionTerminal);
        toolBar->addAction(actionRecepteur_simple);
        toolBar->addAction(actionEclairage);
        toolBar->addAction(actionChauffage);
        toolBar->addAction(actionConditionneur_air);
        toolBar->addAction(actionForce_motrice);
        toolBar->addAction(actionPrise_de_courant);
        toolBar->addAction(actionLocal);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Industria Elec 2012 [Version d'\303\251valuation]", 0));
        actionProprietesDesCpts->setText(QApplication::translate("MainWindow", "Propri\303\251t\303\251s des composants", 0));
        actionProprietesDesCpts->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0));
        actionCopier->setText(QApplication::translate("MainWindow", "Copier", 0));
        actionCopier->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0));
        actionColler->setText(QApplication::translate("MainWindow", "Coller", 0));
#ifndef QT_NO_TOOLTIP
        actionColler->setToolTip(QApplication::translate("MainWindow", "Coller le composant copi\303\251", 0));
#endif // QT_NO_TOOLTIP
        actionColler->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0));
        actionZoomPlus->setText(QApplication::translate("MainWindow", "Agrandir l'installation", 0));
#ifndef QT_NO_TOOLTIP
        actionZoomPlus->setToolTip(QApplication::translate("MainWindow", "Agrandir l'installation", 0));
#endif // QT_NO_TOOLTIP
        actionZoomPlus->setShortcut(QApplication::translate("MainWindow", "Ctrl+G", 0));
        actionZoomMoins->setText(QApplication::translate("MainWindow", "R\303\251duire l'installation", 0));
#ifndef QT_NO_TOOLTIP
        actionZoomMoins->setToolTip(QApplication::translate("MainWindow", "R\303\251duire l'installation", 0));
#endif // QT_NO_TOOLTIP
        actionZoomMoins->setShortcut(QApplication::translate("MainWindow", "Ctrl+M", 0));
        actionCouper->setText(QApplication::translate("MainWindow", "Couper", 0));
#ifndef QT_NO_TOOLTIP
        actionCouper->setToolTip(QApplication::translate("MainWindow", "Couper le composant s\303\251lectionn\303\251", 0));
#endif // QT_NO_TOOLTIP
        actionCouper->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0));
        actionSupprimer->setText(QApplication::translate("MainWindow", "Supprimer", 0));
#ifndef QT_NO_TOOLTIP
        actionSupprimer->setToolTip(QApplication::translate("MainWindow", "Supprimer le composant s\303\251lectionn\303\251", 0));
#endif // QT_NO_TOOLTIP
        actionSupprimer->setShortcut(QApplication::translate("MainWindow", "Del", 0));
        actionEditer->setText(QApplication::translate("MainWindow", "Editer", 0));
#ifndef QT_NO_TOOLTIP
        actionEditer->setToolTip(QApplication::translate("MainWindow", "Editer le composant s\303\251lectionn\303\251", 0));
#endif // QT_NO_TOOLTIP
        actionEditer->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0));
        actionMethodeUsuelle->setText(QApplication::translate("MainWindow", "Par la m\303\251thode th\303\251orique", 0));
#ifndef QT_NO_TOOLTIP
        actionMethodeUsuelle->setToolTip(QApplication::translate("MainWindow", "Nouveau bilan de puissance avec la m\303\251thode usuelle", 0));
#endif // QT_NO_TOOLTIP
        actionMethodeUsuelle->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", 0));
        actionMethodeIndustrielle->setText(QApplication::translate("MainWindow", "Par la m\303\251thode industrielle", 0));
#ifndef QT_NO_TOOLTIP
        actionMethodeIndustrielle->setToolTip(QApplication::translate("MainWindow", "Nouveau bilan de puissance avec la m\303\251thode industrielle", 0));
#endif // QT_NO_TOOLTIP
        actionMethodeIndustrielle->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", 0));
        actionOuvrirUnFichier->setText(QApplication::translate("MainWindow", "Ouvrir un fichier", 0));
        actionOuvrirUnFichier->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionImprimerInstallation->setText(QApplication::translate("MainWindow", "Imprimer...", 0));
        actionFermerFichierEnCours->setText(QApplication::translate("MainWindow", "Fermer fichier en cours", 0));
#ifndef QT_NO_TOOLTIP
        actionFermerFichierEnCours->setToolTip(QApplication::translate("MainWindow", "Fermer le fichier en cours", 0));
#endif // QT_NO_TOOLTIP
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
#ifndef QT_NO_TOOLTIP
        actionQuitter->setToolTip(QApplication::translate("MainWindow", "Quitter l'application", 0));
#endif // QT_NO_TOOLTIP
        actionQuitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionEnregistrer->setText(QApplication::translate("MainWindow", "Enregistrer", 0));
        actionEnregistrer->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionEnregistrerSous->setText(QApplication::translate("MainWindow", "Enregistrer sous...", 0));
        actionD_finir_extension->setText(QApplication::translate("MainWindow", "Transformateur", 0));
        actionAideSurIndustriaElec->setText(QApplication::translate("MainWindow", "Aide sur Industria Elec", 0));
        actionAideSurIndustriaElec->setShortcut(QApplication::translate("MainWindow", "F1", 0));
        actionApropos->setText(QApplication::translate("MainWindow", "A propos de Industria Elec...", 0));
#ifndef QT_NO_TOOLTIP
        actionApropos->setToolTip(QApplication::translate("MainWindow", "A propos de Industria Elec", 0));
#endif // QT_NO_TOOLTIP
        actionAllerEnAvant->setText(QApplication::translate("MainWindow", "Aller en avant", 0));
#ifndef QT_NO_TOOLTIP
        actionAllerEnAvant->setToolTip(QApplication::translate("MainWindow", "Aller en avant", 0));
#endif // QT_NO_TOOLTIP
        actionAllerEnAvant->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0));
        actionAllerEnArriere->setText(QApplication::translate("MainWindow", "Aller en arri\303\250re", 0));
#ifndef QT_NO_TOOLTIP
        actionAllerEnArriere->setToolTip(QApplication::translate("MainWindow", "Aller en arri\303\250re", 0));
#endif // QT_NO_TOOLTIP
        actionAllerEnArriere->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0));
        actionPage_demarrage->setText(QApplication::translate("MainWindow", "Page de d\303\251marrage", 0));
        actionTransformateur->setText(QApplication::translate("MainWindow", "Transformateur", 0));
        actionTGBT->setText(QApplication::translate("MainWindow", "TGBT", 0));
        actionTableau_secondaire->setText(QApplication::translate("MainWindow", "Tableau secondaire", 0));
        actionTableau_divisionnaire->setText(QApplication::translate("MainWindow", "Tableau divisionnaire", 0));
        actionTerminal->setText(QApplication::translate("MainWindow", "Terminal", 0));
        actionRecepteur_simple->setText(QApplication::translate("MainWindow", "R\303\251cepteur simple", 0));
        actionEclairage->setText(QApplication::translate("MainWindow", "Eclairage", 0));
        actionChauffage->setText(QApplication::translate("MainWindow", "Chauffage", 0));
        actionConditionneur_air->setText(QApplication::translate("MainWindow", "Conditionneur d'air", 0));
        actionForce_motrice->setText(QApplication::translate("MainWindow", "Force motrice", 0));
        actionPrise_de_courant->setText(QApplication::translate("MainWindow", "Prise de courant", 0));
        actionLocal->setText(QApplication::translate("MainWindow", "Local", 0));
        actionFleche->setText(QApplication::translate("MainWindow", "Fl\303\250che", 0));
#ifndef QT_NO_TOOLTIP
        actionFleche->setToolTip(QApplication::translate("MainWindow", "Fl\303\250che", 0));
#endif // QT_NO_TOOLTIP
        actionFleche->setShortcut(QApplication::translate("MainWindow", "Esc", 0));
        actionCable->setText(QApplication::translate("MainWindow", "C\303\242ble", 0));
#ifndef QT_NO_TOOLTIP
        actionCable->setToolTip(QApplication::translate("MainWindow", "C\303\242ble", 0));
#endif // QT_NO_TOOLTIP
        actionGomme->setText(QApplication::translate("MainWindow", "Gomme", 0));
#ifndef QT_NO_TOOLTIP
        actionGomme->setToolTip(QApplication::translate("MainWindow", "Gomme", 0));
#endif // QT_NO_TOOLTIP
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menuNouveau->setTitle(QApplication::translate("MainWindow", "Nouveau bilan de puissance", 0));
        menuEdition->setTitle(QApplication::translate("MainWindow", "Edition", 0));
        menuAffichage->setTitle(QApplication::translate("MainWindow", "Fen\303\252tre", 0));
        menuAide->setTitle(QApplication::translate("MainWindow", "Aide", 0));
        menuParametres->setTitle(QApplication::translate("MainWindow", "Param\303\250tres", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
