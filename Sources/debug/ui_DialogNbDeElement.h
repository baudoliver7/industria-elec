/********************************************************************************
** Form generated from reading UI file 'DialogNbDeElement.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGNBDEELEMENT_H
#define UI_DIALOGNBDEELEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

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
            DialogNbDeElement->setObjectName(QStringLiteral("DialogNbDeElement"));
        DialogNbDeElement->resize(179, 90);
        DialogNbDeElement->setMinimumSize(QSize(179, 90));
        DialogNbDeElement->setMaximumSize(QSize(179, 90));
        layoutWidget = new QWidget(DialogNbDeElement);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 20, 94, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spinBoxNombre = new QSpinBox(layoutWidget);
        spinBoxNombre->setObjectName(QStringLiteral("spinBoxNombre"));
        spinBoxNombre->setMinimum(1);
        spinBoxNombre->setMaximum(50);

        horizontalLayout->addWidget(spinBoxNombre);

        layoutWidget1 = new QWidget(DialogNbDeElement);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 50, 158, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_OK = new QPushButton(layoutWidget1);
        btn_OK->setObjectName(QStringLiteral("btn_OK"));

        horizontalLayout_2->addWidget(btn_OK);

        btn_Annuler = new QPushButton(layoutWidget1);
        btn_Annuler->setObjectName(QStringLiteral("btn_Annuler"));

        horizontalLayout_2->addWidget(btn_Annuler);


        retranslateUi(DialogNbDeElement);

        QMetaObject::connectSlotsByName(DialogNbDeElement);
    } // setupUi

    void retranslateUi(QDialog *DialogNbDeElement)
    {
        DialogNbDeElement->setWindowTitle(QApplication::translate("DialogNbDeElement", "Dialog", 0));
        label->setText(QApplication::translate("DialogNbDeElement", "Nombre :", 0));
        btn_OK->setText(QApplication::translate("DialogNbDeElement", "OK", 0));
        btn_Annuler->setText(QApplication::translate("DialogNbDeElement", "Annuler", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogNbDeElement: public Ui_DialogNbDeElement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGNBDEELEMENT_H
