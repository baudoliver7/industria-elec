/********************************************************************************
** Form generated from reading UI file 'BDApropos.ui'
**
** Created: Sun 25. Aug 17:53:58 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDAPROPOS_H
#define UI_BDAPROPOS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BDApropos
{
public:
    QLabel *logo;
    QLabel *label;
    QLabel *label_8;
    QLabel *label_12;
    QLabel *label_9;
    QTextEdit *textEdit;
    QLabel *label_11;
    QLabel *label_6;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_16;
    QLabel *label_15;

    void setupUi(QDialog *BDApropos)
    {
        if (BDApropos->objectName().isEmpty())
            BDApropos->setObjectName(QString::fromUtf8("BDApropos"));
        BDApropos->resize(398, 300);
        BDApropos->setMinimumSize(QSize(398, 300));
        BDApropos->setMaximumSize(QSize(398, 300));
        logo = new QLabel(BDApropos);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(0, 9, 123, 79));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label = new QLabel(BDApropos);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 10, 238, 16));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_8 = new QLabel(BDApropos);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(70, 280, 319, 16));
        QFont font1;
        font1.setPointSize(7);
        font1.setBold(true);
        font1.setWeight(75);
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_12 = new QLabel(BDApropos);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 209, 51, 16));
        QFont font2;
        font2.setBold(true);
        font2.setUnderline(true);
        font2.setWeight(75);
        label_12->setFont(font2);
        label_9 = new QLabel(BDApropos);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 260, 371, 16));
        QFont font3;
        font3.setPointSize(8);
        label_9->setFont(font3);
        label_9->setOpenExternalLinks(false);
        label_9->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);
        textEdit = new QTextEdit(BDApropos);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 110, 381, 81));
        textEdit->setReadOnly(true);
        label_11 = new QLabel(BDApropos);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(60, 209, 321, 16));
        QFont font4;
        font4.setBold(false);
        font4.setWeight(50);
        label_11->setFont(font4);
        label_6 = new QLabel(BDApropos);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 90, 171, 16));
        label_6->setFont(font);
        widget = new QWidget(BDApropos);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(120, 30, 268, 34));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font3);
        label_2->setLineWidth(10);

        verticalLayout->addWidget(label_2);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font3);
        label_5->setLineWidth(10);

        verticalLayout->addWidget(label_5);

        label_16 = new QLabel(BDApropos);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(73, 230, 293, 16));
        label_16->setFont(font4);
        label_15 = new QLabel(BDApropos);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(11, 230, 56, 16));
        label_15->setFont(font2);

        retranslateUi(BDApropos);

        QMetaObject::connectSlotsByName(BDApropos);
    } // setupUi

    void retranslateUi(QDialog *BDApropos)
    {
        BDApropos->setWindowTitle(QApplication::translate("BDApropos", "Dialog", 0, QApplication::UnicodeUTF8));
        logo->setText(QString());
        label->setText(QApplication::translate("BDApropos", "Industria Elec v1.1", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("BDApropos", "Copyright (C) 2011 - 2013 Industria Elec, Tous droits r\303\251serv\303\251s", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("BDApropos", "Auteur :", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("BDApropos", "Se r\303\251f\303\251rer \303\240 la Licence.txt pour les conditions de distribution et d'utilisation.", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("BDApropos", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Professeur LOUM Georges Laussane </span></p>\n"
"<p align=\"justify\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; text-decoration: underline;\">Ma\303\256tre de Conf\303\251rences, Enseignant au DFR GEE de l\342\200\231INPHB</span><span style=\" font-size:8pt;\"> </span><span style=\" font-size:8pt; font-style:italic;\"><br />Equipe de Recherche Signaux et Syst\303\250mes Electriques (2SE) du Laboratoi"
                        "re d\342\200\231Electricit\303\251 et d\342\200\231Electronique Appliqu\303\251es (LEEA) de l\342\200\231INPHB </span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("BDApropos", "M. OURA  Olivier B.,  Ing\303\251nieur de conception en  Electrotechnique", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("BDApropos", "Tous nos remerciements \303\240 : ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDApropos", "Ce logiciel est une application d'aide \303\240 la conception des", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BDApropos", "installations \303\251lectriques domestiques et industrielles", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("BDApropos", "baudolivier@yahoo.fr /+225 61-26-74-00/+225 04-10-99-96", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("BDApropos", "Contacts :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDApropos: public Ui_BDApropos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDAPROPOS_H
