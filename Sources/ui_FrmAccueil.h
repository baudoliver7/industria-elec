/********************************************************************************
** Form generated from reading UI file 'FrmAccueil.ui'
**
** Created: Sun 25. Aug 17:53:58 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMACCUEIL_H
#define UI_FRMACCUEIL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

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
            FrmAccueil->setObjectName(QString::fromUtf8("FrmAccueil"));
        FrmAccueil->resize(601, 350);
        FrmAccueil->setMaximumSize(QSize(16777215, 16777215));
        FrmAccueil->setAutoFillBackground(true);
        gridLayout = new QGridLayout(FrmAccueil);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(FrmAccueil);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QString::fromUtf8("image: url(:/images/background-app.jpg);"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        btn_new_mt = new QCommandLinkButton(tab);
        btn_new_mt->setObjectName(QString::fromUtf8("btn_new_mt"));
        btn_new_mt->setGeometry(QRect(80, 170, 371, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/new_mt.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_new_mt->setIcon(icon);
        btn_new_mi = new QCommandLinkButton(tab);
        btn_new_mi->setObjectName(QString::fromUtf8("btn_new_mi"));
        btn_new_mi->setGeometry(QRect(80, 220, 371, 41));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/new_mi.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_new_mi->setIcon(icon1);
        btn_open_project = new QCommandLinkButton(tab);
        btn_open_project->setObjectName(QString::fromUtf8("btn_open_project"));
        btn_open_project->setGeometry(QRect(80, 270, 371, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/open_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_open_project->setIcon(icon2);
        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(FrmAccueil);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FrmAccueil);
    } // setupUi

    void retranslateUi(QWidget *FrmAccueil)
    {
        FrmAccueil->setWindowTitle(QApplication::translate("FrmAccueil", "Form", 0, QApplication::UnicodeUTF8));
        btn_new_mt->setText(QApplication::translate("FrmAccueil", "Cr\303\251er une nouvelle installation par la m\303\251thode th\303\251orique", 0, QApplication::UnicodeUTF8));
        btn_new_mi->setText(QApplication::translate("FrmAccueil", "Cr\303\251er une nouvelle installation par la m\303\251thode industrielle", 0, QApplication::UnicodeUTF8));
        btn_open_project->setText(QApplication::translate("FrmAccueil", "Ouvrir un projet", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("FrmAccueil", "Page de d\303\251marrage", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FrmAccueil: public Ui_FrmAccueil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMACCUEIL_H
