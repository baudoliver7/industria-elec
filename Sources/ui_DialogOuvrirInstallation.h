/********************************************************************************
** Form generated from reading UI file 'DialogOuvrirInstallation.ui'
**
** Created: Mon 3. Oct 20:44:50 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOUVRIRINSTALLATION_H
#define UI_DIALOGOUVRIRINSTALLATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DialogOuvrirInstallation
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QComboBox *comboBoxTheme;
    QLabel *label_2;
    QComboBox *comboBoxNomDeInstallation;

    void setupUi(QDialog *DialogOuvrirInstallation)
    {
        if (DialogOuvrirInstallation->objectName().isEmpty())
            DialogOuvrirInstallation->setObjectName(QString::fromUtf8("DialogOuvrirInstallation"));
        DialogOuvrirInstallation->resize(266, 201);
        buttonBox = new QDialogButtonBox(DialogOuvrirInstallation);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(40, 160, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(DialogOuvrirInstallation);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 101, 16));
        comboBoxTheme = new QComboBox(DialogOuvrirInstallation);
        comboBoxTheme->setObjectName(QString::fromUtf8("comboBoxTheme"));
        comboBoxTheme->setGeometry(QRect(10, 30, 251, 51));
        label_2 = new QLabel(DialogOuvrirInstallation);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 100, 111, 16));
        comboBoxNomDeInstallation = new QComboBox(DialogOuvrirInstallation);
        comboBoxNomDeInstallation->setObjectName(QString::fromUtf8("comboBoxNomDeInstallation"));
        comboBoxNomDeInstallation->setGeometry(QRect(10, 130, 251, 21));

        retranslateUi(DialogOuvrirInstallation);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogOuvrirInstallation, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogOuvrirInstallation, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogOuvrirInstallation);
    } // setupUi

    void retranslateUi(QDialog *DialogOuvrirInstallation)
    {
        DialogOuvrirInstallation->setWindowTitle(QApplication::translate("DialogOuvrirInstallation", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogOuvrirInstallation", "Th\303\250me du m\303\251moire :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DialogOuvrirInstallation", "Nom de l'installation :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogOuvrirInstallation: public Ui_DialogOuvrirInstallation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOUVRIRINSTALLATION_H
