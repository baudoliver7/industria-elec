/********************************************************************************
** Form generated from reading UI file 'DialogNbDeElement.ui'
**
** Created: Sun 25. Aug 17:53:58 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGNBDEELEMENT_H
#define UI_DIALOGNBDEELEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogNbDeElement
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBoxNombre;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_OK;
    QPushButton *btn_Annuler;

    void setupUi(QDialog *DialogNbDeElement)
    {
        if (DialogNbDeElement->objectName().isEmpty())
            DialogNbDeElement->setObjectName(QString::fromUtf8("DialogNbDeElement"));
        DialogNbDeElement->resize(179, 90);
        DialogNbDeElement->setMinimumSize(QSize(179, 90));
        DialogNbDeElement->setMaximumSize(QSize(179, 90));
        layoutWidget = new QWidget(DialogNbDeElement);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 20, 94, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinBoxNombre = new QSpinBox(layoutWidget);
        spinBoxNombre->setObjectName(QString::fromUtf8("spinBoxNombre"));
        spinBoxNombre->setMinimum(1);
        spinBoxNombre->setMaximum(50);

        horizontalLayout->addWidget(spinBoxNombre);

        layoutWidget1 = new QWidget(DialogNbDeElement);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 50, 158, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_OK = new QPushButton(layoutWidget1);
        btn_OK->setObjectName(QString::fromUtf8("btn_OK"));

        horizontalLayout_2->addWidget(btn_OK);

        btn_Annuler = new QPushButton(layoutWidget1);
        btn_Annuler->setObjectName(QString::fromUtf8("btn_Annuler"));

        horizontalLayout_2->addWidget(btn_Annuler);


        retranslateUi(DialogNbDeElement);

        QMetaObject::connectSlotsByName(DialogNbDeElement);
    } // setupUi

    void retranslateUi(QDialog *DialogNbDeElement)
    {
        DialogNbDeElement->setWindowTitle(QApplication::translate("DialogNbDeElement", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogNbDeElement", "Nombre :", 0, QApplication::UnicodeUTF8));
        btn_OK->setText(QApplication::translate("DialogNbDeElement", "OK", 0, QApplication::UnicodeUTF8));
        btn_Annuler->setText(QApplication::translate("DialogNbDeElement", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogNbDeElement: public Ui_DialogNbDeElement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGNBDEELEMENT_H
