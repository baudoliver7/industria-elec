/********************************************************************************
** Form generated from reading UI file 'FrmAccueil.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMACCUEIL_H
#define UI_FRMACCUEIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmAccueil
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QCommandLinkButton *btn_new_mt;
    QCommandLinkButton *btn_new_mi;
    QCommandLinkButton *btn_open_project;

    void setupUi(QWidget *FrmAccueil)
    {
        if (FrmAccueil->objectName().isEmpty())
            FrmAccueil->setObjectName(QStringLiteral("FrmAccueil"));
        FrmAccueil->resize(601, 350);
        FrmAccueil->setMaximumSize(QSize(16777215, 16777215));
        FrmAccueil->setAutoFillBackground(true);
        gridLayout = new QGridLayout(FrmAccueil);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(FrmAccueil);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QStringLiteral("image: url(:/images/background-app.jpg);"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        btn_new_mt = new QCommandLinkButton(tab);
        btn_new_mt->setObjectName(QStringLiteral("btn_new_mt"));
        btn_new_mt->setGeometry(QRect(80, 170, 371, 41));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/new_mt2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_new_mt->setIcon(icon);
        btn_new_mi = new QCommandLinkButton(tab);
        btn_new_mi->setObjectName(QStringLiteral("btn_new_mi"));
        btn_new_mi->setGeometry(QRect(80, 220, 371, 41));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/new_mi_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_new_mi->setIcon(icon1);
        btn_open_project = new QCommandLinkButton(tab);
        btn_open_project->setObjectName(QStringLiteral("btn_open_project"));
        btn_open_project->setGeometry(QRect(80, 270, 371, 41));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/open_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_open_project->setIcon(icon2);
        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(FrmAccueil);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FrmAccueil);
    } // setupUi

    void retranslateUi(QWidget *FrmAccueil)
    {
        FrmAccueil->setWindowTitle(QApplication::translate("FrmAccueil", "Form", 0));
        btn_new_mt->setText(QApplication::translate("FrmAccueil", "Cr\303\251er une nouvelle installation par la m\303\251thode th\303\251orique", 0));
        btn_new_mi->setText(QApplication::translate("FrmAccueil", "Cr\303\251er une nouvelle installation par la m\303\251thode industrielle", 0));
        btn_open_project->setText(QApplication::translate("FrmAccueil", "Ouvrir un projet", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("FrmAccueil", "Page de d\303\251marrage", 0));
    } // retranslateUi

};

namespace Ui {
    class FrmAccueil: public Ui_FrmAccueil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMACCUEIL_H
