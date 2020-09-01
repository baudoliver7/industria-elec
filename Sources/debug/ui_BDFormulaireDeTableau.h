/********************************************************************************
** Form generated from reading UI file 'BDFormulaireDeTableau.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDFORMULAIREDETABLEAU_H
#define UI_BDFORMULAIREDETABLEAU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BDFormulaireDeTableau
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBoxKs;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditTypeDuTableau;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditDesignation;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_OK;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDFormulaireDeTableau)
    {
        if (BDFormulaireDeTableau->objectName().isEmpty())
            BDFormulaireDeTableau->setObjectName(QStringLiteral("BDFormulaireDeTableau"));
        BDFormulaireDeTableau->resize(316, 100);
        BDFormulaireDeTableau->setMinimumSize(QSize(316, 100));
        BDFormulaireDeTableau->setMaximumSize(QSize(316, 100));
        layoutWidget = new QWidget(BDFormulaireDeTableau);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 70, 69, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        doubleSpinBoxKs = new QDoubleSpinBox(layoutWidget);
        doubleSpinBoxKs->setObjectName(QStringLiteral("doubleSpinBoxKs"));
        doubleSpinBoxKs->setMinimum(0.01);
        doubleSpinBoxKs->setMaximum(1);
        doubleSpinBoxKs->setSingleStep(0.1);
        doubleSpinBoxKs->setValue(1);

        horizontalLayout_3->addWidget(doubleSpinBoxKs);

        layoutWidget1 = new QWidget(BDFormulaireDeTableau);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 211, 54));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditTypeDuTableau = new QLineEdit(layoutWidget1);
        lineEditTypeDuTableau->setObjectName(QStringLiteral("lineEditTypeDuTableau"));
        lineEditTypeDuTableau->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditTypeDuTableau->setReadOnly(true);

        horizontalLayout->addWidget(lineEditTypeDuTableau);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(26);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEditDesignation = new QLineEdit(layoutWidget1);
        lineEditDesignation->setObjectName(QStringLiteral("lineEditDesignation"));

        horizontalLayout_4->addWidget(lineEditDesignation);


        verticalLayout->addLayout(horizontalLayout_4);

        layoutWidget2 = new QWidget(BDFormulaireDeTableau);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(230, 10, 77, 54));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_OK = new QPushButton(layoutWidget2);
        btn_OK->setObjectName(QStringLiteral("btn_OK"));

        verticalLayout_2->addWidget(btn_OK);

        btn_annuler = new QPushButton(layoutWidget2);
        btn_annuler->setObjectName(QStringLiteral("btn_annuler"));

        verticalLayout_2->addWidget(btn_annuler);


        retranslateUi(BDFormulaireDeTableau);

        QMetaObject::connectSlotsByName(BDFormulaireDeTableau);
    } // setupUi

    void retranslateUi(QDialog *BDFormulaireDeTableau)
    {
        BDFormulaireDeTableau->setWindowTitle(QApplication::translate("BDFormulaireDeTableau", "Dialog", 0));
        label_3->setText(QApplication::translate("BDFormulaireDeTableau", "Ks :", 0));
        label->setText(QApplication::translate("BDFormulaireDeTableau", "Type de tableau :", 0));
        label_4->setText(QApplication::translate("BDFormulaireDeTableau", "D\303\251signation :", 0));
        btn_OK->setText(QApplication::translate("BDFormulaireDeTableau", "OK", 0));
        btn_annuler->setText(QApplication::translate("BDFormulaireDeTableau", "Annuler", 0));
    } // retranslateUi

};

namespace Ui {
    class BDFormulaireDeTableau: public Ui_BDFormulaireDeTableau {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDFORMULAIREDETABLEAU_H
