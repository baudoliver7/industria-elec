/********************************************************************************
** Form generated from reading UI file 'DialogNouvelleInstallation.ui'
**
** Created: Mon 3. Oct 20:44:49 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGNOUVELLEINSTALLATION_H
#define UI_DIALOGNOUVELLEINSTALLATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogNouvelleInstallation
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditNomInstallation;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBoxThemes;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEditAuteur;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *lineEditNiveauScolaire;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *lineEditAnnee;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *lineEditNbPages;

    void setupUi(QDialog *DialogNouvelleInstallation)
    {
        if (DialogNouvelleInstallation->objectName().isEmpty())
            DialogNouvelleInstallation->setObjectName(QString::fromUtf8("DialogNouvelleInstallation"));
        DialogNouvelleInstallation->resize(240, 221);
        buttonBox = new QDialogButtonBox(DialogNouvelleInstallation);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 180, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(DialogNouvelleInstallation);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 11, 221, 164));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditNomInstallation = new QLineEdit(widget);
        lineEditNomInstallation->setObjectName(QString::fromUtf8("lineEditNomInstallation"));

        horizontalLayout->addWidget(lineEditNomInstallation);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBoxThemes = new QComboBox(widget);
        comboBoxThemes->setObjectName(QString::fromUtf8("comboBoxThemes"));
        comboBoxThemes->setEditable(true);

        horizontalLayout_2->addWidget(comboBoxThemes);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(66);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEditAuteur = new QLineEdit(widget);
        lineEditAuteur->setObjectName(QString::fromUtf8("lineEditAuteur"));

        horizontalLayout_3->addWidget(lineEditAuteur);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(27);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        lineEditNiveauScolaire = new QLineEdit(widget);
        lineEditNiveauScolaire->setObjectName(QString::fromUtf8("lineEditNiveauScolaire"));

        horizontalLayout_4->addWidget(lineEditNiveauScolaire);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(68);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        lineEditAnnee = new QLineEdit(widget);
        lineEditAnnee->setObjectName(QString::fromUtf8("lineEditAnnee"));

        horizontalLayout_5->addWidget(lineEditAnnee);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(15);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        lineEditNbPages = new QLineEdit(widget);
        lineEditNbPages->setObjectName(QString::fromUtf8("lineEditNbPages"));

        horizontalLayout_6->addWidget(lineEditNbPages);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(DialogNouvelleInstallation);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogNouvelleInstallation, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogNouvelleInstallation, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogNouvelleInstallation);
    } // setupUi

    void retranslateUi(QDialog *DialogNouvelleInstallation)
    {
        DialogNouvelleInstallation->setWindowTitle(QApplication::translate("DialogNouvelleInstallation", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogNouvelleInstallation", "Nom de l'installation : ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DialogNouvelleInstallation", "Th\303\250me du m\303\251moire : ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DialogNouvelleInstallation", "Auteur : ", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DialogNouvelleInstallation", "Niveau scolaire : ", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DialogNouvelleInstallation", "Ann\303\251e : ", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DialogNouvelleInstallation", "Nombre de pages : ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogNouvelleInstallation: public Ui_DialogNouvelleInstallation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGNOUVELLEINSTALLATION_H
