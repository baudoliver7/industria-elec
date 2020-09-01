/********************************************************************************
** Form generated from reading UI file 'BDApropos.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDAPROPOS_H
#define UI_BDAPROPOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BDApropos
{
public:
    QLabel *logo;
    QLabel *label;
    QLabel *label_8;
    QLabel *label_12;
    QLabel *label_9;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_3;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_14;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_15;
    QLabel *label_16;

    void setupUi(QDialog *BDApropos)
    {
        if (BDApropos->objectName().isEmpty())
            BDApropos->setObjectName(QStringLiteral("BDApropos"));
        BDApropos->resize(398, 315);
        BDApropos->setMinimumSize(QSize(398, 315));
        BDApropos->setMaximumSize(QSize(398, 315));
        logo = new QLabel(BDApropos);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(9, 9, 123, 79));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label = new QLabel(BDApropos);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(138, 9, 238, 16));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_8 = new QLabel(BDApropos);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(70, 290, 319, 16));
        QFont font1;
        font1.setPointSize(7);
        font1.setBold(true);
        font1.setWeight(75);
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_12 = new QLabel(BDApropos);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 160, 71, 16));
        QFont font2;
        font2.setBold(true);
        font2.setUnderline(true);
        font2.setWeight(75);
        label_12->setFont(font2);
        label_9 = new QLabel(BDApropos);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 260, 371, 16));
        QFont font3;
        font3.setPointSize(8);
        label_9->setFont(font3);
        label_9->setOpenExternalLinks(false);
        label_9->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);
        widget = new QWidget(BDApropos);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(138, 44, 261, 53));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font3);
        label_2->setLineWidth(10);

        verticalLayout->addWidget(label_2);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font3);
        label_5->setLineWidth(10);

        verticalLayout->addWidget(label_5);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font3);

        verticalLayout->addWidget(label_3);

        widget1 = new QWidget(BDApropos);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(9, 103, 387, 34));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font3);

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(widget1);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font3);

        verticalLayout_2->addWidget(label_7);

        widget2 = new QWidget(BDApropos);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(90, 160, 305, 53));
        verticalLayout_3 = new QVBoxLayout(widget2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(widget2);
        label_11->setObjectName(QStringLiteral("label_11"));
        QFont font4;
        font4.setBold(false);
        font4.setWeight(50);
        label_11->setFont(font4);

        verticalLayout_3->addWidget(label_11);

        label_13 = new QLabel(widget2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font4);

        verticalLayout_3->addWidget(label_13);

        label_14 = new QLabel(widget2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font4);

        verticalLayout_3->addWidget(label_14);

        widget3 = new QWidget(BDApropos);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(30, 220, 357, 15));
        horizontalLayout = new QHBoxLayout(widget3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(widget3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font2);

        horizontalLayout->addWidget(label_15);

        label_16 = new QLabel(widget3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font4);

        horizontalLayout->addWidget(label_16);


        retranslateUi(BDApropos);

        QMetaObject::connectSlotsByName(BDApropos);
    } // setupUi

    void retranslateUi(QDialog *BDApropos)
    {
        BDApropos->setWindowTitle(QApplication::translate("BDApropos", "Dialog", 0));
        logo->setText(QString());
        label->setText(QApplication::translate("BDApropos", "Industria Elec v1.0  (Version d'\303\251valuation)", 0));
        label_8->setText(QApplication::translate("BDApropos", "Copyright (C) 2011 - 2012 Industria Elec, Tous droits r\303\251serv\303\251s", 0));
        label_12->setText(QApplication::translate("BDApropos", "Concepteur :", 0));
        label_9->setText(QApplication::translate("BDApropos", "Se r\303\251f\303\251rer \303\240 la Licence.txt pour les conditions de distribution et d'utilisation.", 0));
        label_2->setText(QApplication::translate("BDApropos", "La version de ce logiciel est une version d'\303\251valuation ", 0));
        label_5->setText(QApplication::translate("BDApropos", "qui ne  doit  ni \303\252tre  d\303\251compil\303\251e, ni \303\252tre modifi\303\251e,  ni", 0));
        label_3->setText(QApplication::translate("BDApropos", "\303\252tre  vendue,  ni servir \303\240 un quelconque but lucratif. ", 0));
        label_6->setText(QApplication::translate("BDApropos", "Tout   acte  visant  donc  \303\240 enfreindre ces   r\303\250gles   pourrait   faire  l'objet d'une", 0));
        label_7->setText(QApplication::translate("BDApropos", " poursuite judiciaire, allant jusqu'\303\240 l'emprisonnement.", 0));
        label_11->setText(QApplication::translate("BDApropos", "M. OURA  Olivier B.,  El\303\250ve  Ing\303\251nieur en  Electrotechnique fin", 0));
        label_13->setText(QApplication::translate("BDApropos", "de cycle \303\240 l'Institut  National Polytechnique  Houphou\303\253t-Boigny", 0));
        label_14->setText(QApplication::translate("BDApropos", "de Yamoussoukro", 0));
        label_15->setText(QApplication::translate("BDApropos", "Contacts :", 0));
        label_16->setText(QApplication::translate("BDApropos", "baudolivier@yahoo.fr /+225 44-34-86-57/+225 57-21-87-32", 0));
    } // retranslateUi

};

namespace Ui {
    class BDApropos: public Ui_BDApropos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDAPROPOS_H
