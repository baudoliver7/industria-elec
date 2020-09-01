/********************************************************************************
** Form generated from reading UI file 'BDFormulaireDeLocal.ui'
**
** Created: Sun 25. Aug 17:53:58 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDFORMULAIREDELOCAL_H
#define UI_BDFORMULAIREDELOCAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_BDFormulaireDeLocal
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLineEdit *lineEditDesignation;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBoxTypeUtil;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBoxTypeLocal;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spinBoxPEstimee;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBoxSuperficie;
    QLabel *label_6;
    QSplitter *splitter;
    QPushButton *btn_Annuler;
    QPushButton *btn_OK;

    void setupUi(QDialog *BDFormulaireDeLocal)
    {
        if (BDFormulaireDeLocal->objectName().isEmpty())
            BDFormulaireDeLocal->setObjectName(QString::fromUtf8("BDFormulaireDeLocal"));
        BDFormulaireDeLocal->resize(279, 258);
        gridLayout_3 = new QGridLayout(BDFormulaireDeLocal);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_2 = new QGroupBox(BDFormulaireDeLocal);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_5->addWidget(label_7);

        lineEditDesignation = new QLineEdit(groupBox_2);
        lineEditDesignation->setObjectName(QString::fromUtf8("lineEditDesignation"));

        horizontalLayout_5->addWidget(lineEditDesignation);


        gridLayout_2->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBoxTypeUtil = new QComboBox(groupBox_2);
        comboBoxTypeUtil->setObjectName(QString::fromUtf8("comboBoxTypeUtil"));

        horizontalLayout->addWidget(comboBoxTypeUtil);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBoxTypeLocal = new QComboBox(groupBox_2);
        comboBoxTypeLocal->setObjectName(QString::fromUtf8("comboBoxTypeLocal"));

        horizontalLayout_2->addWidget(comboBoxTypeLocal);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(BDFormulaireDeLocal);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        spinBoxPEstimee = new QSpinBox(groupBox);
        spinBoxPEstimee->setObjectName(QString::fromUtf8("spinBoxPEstimee"));
        spinBoxPEstimee->setMinimum(0);
        spinBoxPEstimee->setMaximum(1000);

        horizontalLayout_3->addWidget(spinBoxPEstimee);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        doubleSpinBoxSuperficie = new QDoubleSpinBox(groupBox);
        doubleSpinBoxSuperficie->setObjectName(QString::fromUtf8("doubleSpinBoxSuperficie"));
        doubleSpinBoxSuperficie->setMaximum(2000);

        horizontalLayout_4->addWidget(doubleSpinBoxSuperficie);


        gridLayout->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 1);

        splitter = new QSplitter(BDFormulaireDeLocal);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setMaximumSize(QSize(155, 23));
        splitter->setLayoutDirection(Qt::RightToLeft);
        splitter->setOrientation(Qt::Horizontal);
        btn_Annuler = new QPushButton(splitter);
        btn_Annuler->setObjectName(QString::fromUtf8("btn_Annuler"));
        btn_Annuler->setMaximumSize(QSize(75, 23));
        splitter->addWidget(btn_Annuler);
        btn_OK = new QPushButton(splitter);
        btn_OK->setObjectName(QString::fromUtf8("btn_OK"));
        btn_OK->setMaximumSize(QSize(75, 23));
        splitter->addWidget(btn_OK);

        gridLayout_3->addWidget(splitter, 2, 0, 1, 1);


        retranslateUi(BDFormulaireDeLocal);

        QMetaObject::connectSlotsByName(BDFormulaireDeLocal);
    } // setupUi

    void retranslateUi(QDialog *BDFormulaireDeLocal)
    {
        BDFormulaireDeLocal->setWindowTitle(QApplication::translate("BDFormulaireDeLocal", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("BDFormulaireDeLocal", "Caract\303\251ristiques", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("BDFormulaireDeLocal", "D\303\251signation: ", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDFormulaireDeLocal", "Type d'utilisation: ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDFormulaireDeLocal", "Type de local:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDFormulaireDeLocal", "Puissance estim\303\251e", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDFormulaireDeLocal", "Puissance estim\303\251e:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDFormulaireDeLocal", "VA/m\302\262", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BDFormulaireDeLocal", "Superficie:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("BDFormulaireDeLocal", "m\302\262", 0, QApplication::UnicodeUTF8));
        btn_Annuler->setText(QApplication::translate("BDFormulaireDeLocal", "Annuler", 0, QApplication::UnicodeUTF8));
        btn_OK->setText(QApplication::translate("BDFormulaireDeLocal", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDFormulaireDeLocal: public Ui_BDFormulaireDeLocal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDFORMULAIREDELOCAL_H
