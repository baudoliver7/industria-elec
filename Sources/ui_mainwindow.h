/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 25. Aug 17:53:58 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

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
    QAction *actionApercu_avant_impression;
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
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(783, 480);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionProprietesDesCpts = new QAction(MainWindow);
        actionProprietesDesCpts->setObjectName(QString::fromUtf8("actionProprietesDesCpts"));
        actionProprietesDesCpts->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/proprietes_composant.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionProprietesDesCpts->setIcon(icon1);
        actionCopier = new QAction(MainWindow);
        actionCopier->setObjectName(QString::fromUtf8("actionCopier"));
        actionColler = new QAction(MainWindow);
        actionColler->setObjectName(QString::fromUtf8("actionColler"));
        actionZoomPlus = new QAction(MainWindow);
        actionZoomPlus->setObjectName(QString::fromUtf8("actionZoomPlus"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/zoom plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomPlus->setIcon(icon2);
        actionZoomMoins = new QAction(MainWindow);
        actionZoomMoins->setObjectName(QString::fromUtf8("actionZoomMoins"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/zoom moins.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomMoins->setIcon(icon3);
        actionCouper = new QAction(MainWindow);
        actionCouper->setObjectName(QString::fromUtf8("actionCouper"));
        actionSupprimer = new QAction(MainWindow);
        actionSupprimer->setObjectName(QString::fromUtf8("actionSupprimer"));
        actionEditer = new QAction(MainWindow);
        actionEditer->setObjectName(QString::fromUtf8("actionEditer"));
        actionMethodeUsuelle = new QAction(MainWindow);
        actionMethodeUsuelle->setObjectName(QString::fromUtf8("actionMethodeUsuelle"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/new_mt.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMethodeUsuelle->setIcon(icon4);
        actionMethodeIndustrielle = new QAction(MainWindow);
        actionMethodeIndustrielle->setObjectName(QString::fromUtf8("actionMethodeIndustrielle"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/new_mi.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMethodeIndustrielle->setIcon(icon5);
        actionOuvrirUnFichier = new QAction(MainWindow);
        actionOuvrirUnFichier->setObjectName(QString::fromUtf8("actionOuvrirUnFichier"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/open_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOuvrirUnFichier->setIcon(icon6);
        actionImprimerInstallation = new QAction(MainWindow);
        actionImprimerInstallation->setObjectName(QString::fromUtf8("actionImprimerInstallation"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionImprimerInstallation->setIcon(icon7);
        actionFermerFichierEnCours = new QAction(MainWindow);
        actionFermerFichierEnCours->setObjectName(QString::fromUtf8("actionFermerFichierEnCours"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionEnregistrer = new QAction(MainWindow);
        actionEnregistrer->setObjectName(QString::fromUtf8("actionEnregistrer"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnregistrer->setIcon(icon8);
        actionEnregistrerSous = new QAction(MainWindow);
        actionEnregistrerSous->setObjectName(QString::fromUtf8("actionEnregistrerSous"));
        actionD_finir_extension = new QAction(MainWindow);
        actionD_finir_extension->setObjectName(QString::fromUtf8("actionD_finir_extension"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/transfo_choisi.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionD_finir_extension->setIcon(icon9);
        actionAideSurIndustriaElec = new QAction(MainWindow);
        actionAideSurIndustriaElec->setObjectName(QString::fromUtf8("actionAideSurIndustriaElec"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/aide.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAideSurIndustriaElec->setIcon(icon10);
        actionApropos = new QAction(MainWindow);
        actionApropos->setObjectName(QString::fromUtf8("actionApropos"));
        actionAllerEnAvant = new QAction(MainWindow);
        actionAllerEnAvant->setObjectName(QString::fromUtf8("actionAllerEnAvant"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAllerEnAvant->setIcon(icon11);
        actionAllerEnArriere = new QAction(MainWindow);
        actionAllerEnArriere->setObjectName(QString::fromUtf8("actionAllerEnArriere"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAllerEnArriere->setIcon(icon12);
        actionPage_demarrage = new QAction(MainWindow);
        actionPage_demarrage->setObjectName(QString::fromUtf8("actionPage_demarrage"));
        actionPage_demarrage->setIcon(icon5);
        actionTransformateur = new QAction(MainWindow);
        actionTransformateur->setObjectName(QString::fromUtf8("actionTransformateur"));
        actionTransformateur->setIcon(icon9);
        actionTGBT = new QAction(MainWindow);
        actionTGBT->setObjectName(QString::fromUtf8("actionTGBT"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/TGBT.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTGBT->setIcon(icon13);
        actionTableau_secondaire = new QAction(MainWindow);
        actionTableau_secondaire->setObjectName(QString::fromUtf8("actionTableau_secondaire"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/ts_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTableau_secondaire->setIcon(icon14);
        actionTableau_divisionnaire = new QAction(MainWindow);
        actionTableau_divisionnaire->setObjectName(QString::fromUtf8("actionTableau_divisionnaire"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/td_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTableau_divisionnaire->setIcon(icon15);
        actionTerminal = new QAction(MainWindow);
        actionTerminal->setObjectName(QString::fromUtf8("actionTerminal"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/ter_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTerminal->setIcon(icon16);
        actionRecepteur_simple = new QAction(MainWindow);
        actionRecepteur_simple->setObjectName(QString::fromUtf8("actionRecepteur_simple"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/images/autre r\303\251cepteur.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRecepteur_simple->setIcon(icon17);
        actionEclairage = new QAction(MainWindow);
        actionEclairage->setObjectName(QString::fromUtf8("actionEclairage"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/images/eclairage.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEclairage->setIcon(icon18);
        actionChauffage = new QAction(MainWindow);
        actionChauffage->setObjectName(QString::fromUtf8("actionChauffage"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/images/Chauffage.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChauffage->setIcon(icon19);
        actionConditionneur_air = new QAction(MainWindow);
        actionConditionneur_air->setObjectName(QString::fromUtf8("actionConditionneur_air"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/images/climatiseur.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConditionneur_air->setIcon(icon20);
        actionForce_motrice = new QAction(MainWindow);
        actionForce_motrice->setObjectName(QString::fromUtf8("actionForce_motrice"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/images/moteur.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionForce_motrice->setIcon(icon21);
        actionPrise_de_courant = new QAction(MainWindow);
        actionPrise_de_courant->setObjectName(QString::fromUtf8("actionPrise_de_courant"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/images/prise de courant.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrise_de_courant->setIcon(icon22);
        actionLocal = new QAction(MainWindow);
        actionLocal->setObjectName(QString::fromUtf8("actionLocal"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/images/Local_ecl.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLocal->setIcon(icon23);
        actionFleche = new QAction(MainWindow);
        actionFleche->setObjectName(QString::fromUtf8("actionFleche"));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/images/fleche.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        actionFleche->setIcon(icon24);
        actionCable = new QAction(MainWindow);
        actionCable->setObjectName(QString::fromUtf8("actionCable"));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/images/liaison.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCable->setIcon(icon25);
        actionGomme = new QAction(MainWindow);
        actionGomme->setObjectName(QString::fromUtf8("actionGomme"));
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/images/gomme.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGomme->setIcon(icon26);
        actionApercu_avant_impression = new QAction(MainWindow);
        actionApercu_avant_impression->setObjectName(QString::fromUtf8("actionApercu_avant_impression"));
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/images/print_preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionApercu_avant_impression->setIcon(icon27);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 783, 21));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuNouveau = new QMenu(menuFichier);
        menuNouveau->setObjectName(QString::fromUtf8("menuNouveau"));
        menuEdition = new QMenu(menubar);
        menuEdition->setObjectName(QString::fromUtf8("menuEdition"));
        menuAffichage = new QMenu(menubar);
        menuAffichage->setObjectName(QString::fromUtf8("menuAffichage"));
        menuAide = new QMenu(menubar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        menuParametres = new QMenu(menubar);
        menuParametres->setObjectName(QString::fromUtf8("menuParametres"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setIconSize(QSize(32, 32));
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        toolBar_2->setIconSize(QSize(32, 32));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);

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
        menuFichier->addAction(actionApercu_avant_impression);
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
        toolBar_2->addAction(actionMethodeUsuelle);
        toolBar_2->addAction(actionMethodeIndustrielle);
        toolBar_2->addAction(actionOuvrirUnFichier);
        toolBar_2->addAction(actionEnregistrer);
        toolBar_2->addAction(actionApercu_avant_impression);
        toolBar_2->addSeparator();
        toolBar_2->addAction(actionAllerEnArriere);
        toolBar_2->addAction(actionAllerEnAvant);
        toolBar_2->addSeparator();
        toolBar_2->addAction(actionZoomMoins);
        toolBar_2->addAction(actionZoomPlus);
        toolBar_2->addSeparator();
        toolBar_2->addAction(actionD_finir_extension);
        toolBar_2->addAction(actionProprietesDesCpts);
        toolBar_2->addSeparator();
        toolBar_2->addAction(actionAideSurIndustriaElec);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Industria Elec 2013", 0, QApplication::UnicodeUTF8));
        actionProprietesDesCpts->setText(QApplication::translate("MainWindow", "Propri\303\251t\303\251s des composants", 0, QApplication::UnicodeUTF8));
        actionProprietesDesCpts->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionCopier->setText(QApplication::translate("MainWindow", "Copier", 0, QApplication::UnicodeUTF8));
        actionCopier->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        actionColler->setText(QApplication::translate("MainWindow", "Coller", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionColler->setToolTip(QApplication::translate("MainWindow", "Coller le composant copi\303\251", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionColler->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        actionZoomPlus->setText(QApplication::translate("MainWindow", "Agrandir l'installation", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionZoomPlus->setToolTip(QApplication::translate("MainWindow", "Agrandir l'installation", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionZoomPlus->setShortcut(QApplication::translate("MainWindow", "Ctrl+G", 0, QApplication::UnicodeUTF8));
        actionZoomMoins->setText(QApplication::translate("MainWindow", "R\303\251duire l'installation", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionZoomMoins->setToolTip(QApplication::translate("MainWindow", "R\303\251duire l'installation", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionZoomMoins->setShortcut(QApplication::translate("MainWindow", "Ctrl+M", 0, QApplication::UnicodeUTF8));
        actionCouper->setText(QApplication::translate("MainWindow", "Couper", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCouper->setToolTip(QApplication::translate("MainWindow", "Couper le composant s\303\251lectionn\303\251", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionCouper->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        actionSupprimer->setText(QApplication::translate("MainWindow", "Supprimer", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSupprimer->setToolTip(QApplication::translate("MainWindow", "Supprimer le composant s\303\251lectionn\303\251", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSupprimer->setShortcut(QApplication::translate("MainWindow", "Del", 0, QApplication::UnicodeUTF8));
        actionEditer->setText(QApplication::translate("MainWindow", "Editer", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionEditer->setToolTip(QApplication::translate("MainWindow", "Editer le composant s\303\251lectionn\303\251", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionEditer->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0, QApplication::UnicodeUTF8));
        actionMethodeUsuelle->setText(QApplication::translate("MainWindow", "Par la m\303\251thode th\303\251orique", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionMethodeUsuelle->setToolTip(QApplication::translate("MainWindow", "Nouveau bilan de puissance avec la m\303\251thode th\303\251orique", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionMethodeUsuelle->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", 0, QApplication::UnicodeUTF8));
        actionMethodeIndustrielle->setText(QApplication::translate("MainWindow", "Par la m\303\251thode industrielle", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionMethodeIndustrielle->setToolTip(QApplication::translate("MainWindow", "Nouveau bilan de puissance avec la m\303\251thode industrielle", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionMethodeIndustrielle->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", 0, QApplication::UnicodeUTF8));
        actionOuvrirUnFichier->setText(QApplication::translate("MainWindow", "Ouvrir un fichier", 0, QApplication::UnicodeUTF8));
        actionOuvrirUnFichier->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionImprimerInstallation->setText(QApplication::translate("MainWindow", "Imprimer...", 0, QApplication::UnicodeUTF8));
        actionFermerFichierEnCours->setText(QApplication::translate("MainWindow", "Fermer fichier en cours", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionFermerFichierEnCours->setToolTip(QApplication::translate("MainWindow", "Fermer le fichier en cours", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionQuitter->setToolTip(QApplication::translate("MainWindow", "Quitter l'application", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionQuitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionEnregistrer->setText(QApplication::translate("MainWindow", "Enregistrer", 0, QApplication::UnicodeUTF8));
        actionEnregistrer->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionEnregistrerSous->setText(QApplication::translate("MainWindow", "Enregistrer sous...", 0, QApplication::UnicodeUTF8));
        actionD_finir_extension->setText(QApplication::translate("MainWindow", "Transformateur", 0, QApplication::UnicodeUTF8));
        actionAideSurIndustriaElec->setText(QApplication::translate("MainWindow", "Aide sur Industria Elec", 0, QApplication::UnicodeUTF8));
        actionAideSurIndustriaElec->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        actionApropos->setText(QApplication::translate("MainWindow", "A propos de Industria Elec...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionApropos->setToolTip(QApplication::translate("MainWindow", "A propos de Industria Elec", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAllerEnAvant->setText(QApplication::translate("MainWindow", "Aller en avant", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAllerEnAvant->setToolTip(QApplication::translate("MainWindow", "Aller en avant", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAllerEnAvant->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        actionAllerEnArriere->setText(QApplication::translate("MainWindow", "Aller en arri\303\250re", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAllerEnArriere->setToolTip(QApplication::translate("MainWindow", "Aller en arri\303\250re", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAllerEnArriere->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionPage_demarrage->setText(QApplication::translate("MainWindow", "Page de d\303\251marrage", 0, QApplication::UnicodeUTF8));
        actionTransformateur->setText(QApplication::translate("MainWindow", "Transformateur", 0, QApplication::UnicodeUTF8));
        actionTGBT->setText(QApplication::translate("MainWindow", "TGBT", 0, QApplication::UnicodeUTF8));
        actionTableau_secondaire->setText(QApplication::translate("MainWindow", "Tableau secondaire", 0, QApplication::UnicodeUTF8));
        actionTableau_divisionnaire->setText(QApplication::translate("MainWindow", "Tableau divisionnaire", 0, QApplication::UnicodeUTF8));
        actionTerminal->setText(QApplication::translate("MainWindow", "Terminal", 0, QApplication::UnicodeUTF8));
        actionRecepteur_simple->setText(QApplication::translate("MainWindow", "R\303\251cepteur simple", 0, QApplication::UnicodeUTF8));
        actionEclairage->setText(QApplication::translate("MainWindow", "Eclairage", 0, QApplication::UnicodeUTF8));
        actionChauffage->setText(QApplication::translate("MainWindow", "Chauffage", 0, QApplication::UnicodeUTF8));
        actionConditionneur_air->setText(QApplication::translate("MainWindow", "Conditionneur d'air", 0, QApplication::UnicodeUTF8));
        actionForce_motrice->setText(QApplication::translate("MainWindow", "Force motrice", 0, QApplication::UnicodeUTF8));
        actionPrise_de_courant->setText(QApplication::translate("MainWindow", "Prise de courant", 0, QApplication::UnicodeUTF8));
        actionLocal->setText(QApplication::translate("MainWindow", "Local", 0, QApplication::UnicodeUTF8));
        actionFleche->setText(QApplication::translate("MainWindow", "Fl\303\250che", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionFleche->setToolTip(QApplication::translate("MainWindow", "Fl\303\250che", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionFleche->setShortcut(QApplication::translate("MainWindow", "Esc", 0, QApplication::UnicodeUTF8));
        actionCable->setText(QApplication::translate("MainWindow", "C\303\242ble", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCable->setToolTip(QApplication::translate("MainWindow", "C\303\242ble", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionGomme->setText(QApplication::translate("MainWindow", "Gomme", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionGomme->setToolTip(QApplication::translate("MainWindow", "Gomme", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionApercu_avant_impression->setText(QApplication::translate("MainWindow", "Aper\303\247u avant impression", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menuNouveau->setTitle(QApplication::translate("MainWindow", "Nouveau bilan de puissance", 0, QApplication::UnicodeUTF8));
        menuEdition->setTitle(QApplication::translate("MainWindow", "Edition", 0, QApplication::UnicodeUTF8));
        menuAffichage->setTitle(QApplication::translate("MainWindow", "Fen\303\252tre", 0, QApplication::UnicodeUTF8));
        menuAide->setTitle(QApplication::translate("MainWindow", "Aide", 0, QApplication::UnicodeUTF8));
        menuParametres->setTitle(QApplication::translate("MainWindow", "Param\303\250tres", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
