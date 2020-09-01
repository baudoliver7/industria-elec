/********************************************************************************
** Form generated from reading UI file 'DialogChoisirInstallation.ui'
**
** Created: Mon 3. Oct 20:44:50 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCHOISIRINSTALLATION_H
#define UI_DIALOGCHOISIRINSTALLATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_DialogChoisirInstallation
{
public:
    QDialogButtonBox *buttonBox;
    QTableView *tableViewInstallation;

    void setupUi(QDialog *DialogChoisirInstallation)
    {
        if (DialogChoisirInstallation->objectName().isEmpty())
            DialogChoisirInstallation->setObjectName(QString::fromUtf8("DialogChoisirInstallation"));
        DialogChoisirInstallation->resize(330, 320);
        buttonBox = new QDialogButtonBox(DialogChoisirInstallation);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(90, 270, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tableViewInstallation = new QTableView(DialogChoisirInstallation);
        tableViewInstallation->setObjectName(QString::fromUtf8("tableViewInstallation"));
        tableViewInstallation->setGeometry(QRect(5, 11, 321, 261));

        retranslateUi(DialogChoisirInstallation);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogChoisirInstallation, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogChoisirInstallation, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogChoisirInstallation);
    } // setupUi

    void retranslateUi(QDialog *DialogChoisirInstallation)
    {
        DialogChoisirInstallation->setWindowTitle(QApplication::translate("DialogChoisirInstallation", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogChoisirInstallation: public Ui_DialogChoisirInstallation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCHOISIRINSTALLATION_H
