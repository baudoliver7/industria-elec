/********************************************************************************
** Form generated from reading UI file 'BDFormulaireDeRecepteur.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDFORMULAIREDERECEPTEUR_H
#define UI_BDFORMULAIREDERECEPTEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BDFormulaireDeRecepteur
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBoxTypeDeRecepteur;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEditDesignation;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_12;
    QSpinBox *spinBoxQuantite;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_predefini;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBoxKu;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBoxCosPhi;
    QRadioButton *radioButtonPutile;
    QFrame *line;
    QLabel *label_18;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBoxPutile;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBoxRendement;
    QComboBox *comboBoxUnitePU;
    QRadioButton *radioButtonCourant_Tension;
    QFrame *line_2;
    QFormLayout *formLayout_2;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_14;
    QDoubleSpinBox *doubleSpinBoxCourant;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_16;
    QComboBox *comboBoxTension;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_15;
    QLabel *label_17;
    QGroupBox *groupBoxNPhase;
    QGridLayout *gridLayout;
    QRadioButton *Monophase;
    QRadioButton *Triphase;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBoxPabsorbee;
    QComboBox *comboBoxUnitePA;
    QRadioButton *radioButtonPabsorbee;
    QSplitter *splitter;
    QPushButton *btn_Annuler;
    QPushButton *btn_OK;

    void setupUi(QDialog *BDFormulaireDeRecepteur)
    {
        if (BDFormulaireDeRecepteur->objectName().isEmpty())
            BDFormulaireDeRecepteur->setObjectName(QStringLiteral("BDFormulaireDeRecepteur"));
        BDFormulaireDeRecepteur->resize(278, 462);
        BDFormulaireDeRecepteur->setMinimumSize(QSize(278, 462));
        BDFormulaireDeRecepteur->setMaximumSize(QSize(278, 462));
        gridLayout_4 = new QGridLayout(BDFormulaireDeRecepteur);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox_3 = new QGroupBox(BDFormulaireDeRecepteur);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBoxTypeDeRecepteur = new QComboBox(groupBox_3);
        comboBoxTypeDeRecepteur->setObjectName(QStringLiteral("comboBoxTypeDeRecepteur"));

        horizontalLayout->addWidget(comboBoxTypeDeRecepteur);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(60);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEditDesignation = new QLineEdit(groupBox_3);
        lineEditDesignation->setObjectName(QStringLiteral("lineEditDesignation"));

        horizontalLayout_3->addWidget(lineEditDesignation);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 3);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_14->addWidget(label_12);

        spinBoxQuantite = new QSpinBox(groupBox_3);
        spinBoxQuantite->setObjectName(QStringLiteral("spinBoxQuantite"));
        spinBoxQuantite->setMinimum(1);
        spinBoxQuantite->setMaximum(9999);

        horizontalLayout_14->addWidget(spinBoxQuantite);


        gridLayout_3->addLayout(horizontalLayout_14, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 1, 1, 1, 1);

        btn_predefini = new QPushButton(groupBox_3);
        btn_predefini->setObjectName(QStringLiteral("btn_predefini"));
        btn_predefini->setMaximumSize(QSize(75, 23));
        btn_predefini->setLayoutDirection(Qt::RightToLeft);

        gridLayout_3->addWidget(btn_predefini, 1, 2, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox = new QGroupBox(BDFormulaireDeRecepteur);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_6->addWidget(label_8);

        doubleSpinBoxKu = new QDoubleSpinBox(groupBox);
        doubleSpinBoxKu->setObjectName(QStringLiteral("doubleSpinBoxKu"));
        doubleSpinBoxKu->setDecimals(3);
        doubleSpinBoxKu->setMinimum(0.01);
        doubleSpinBoxKu->setMaximum(1);
        doubleSpinBoxKu->setSingleStep(0.1);
        doubleSpinBoxKu->setValue(1);

        horizontalLayout_6->addWidget(doubleSpinBoxKu);


        horizontalLayout_11->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_8->addWidget(label_11);

        doubleSpinBoxCosPhi = new QDoubleSpinBox(groupBox);
        doubleSpinBoxCosPhi->setObjectName(QStringLiteral("doubleSpinBoxCosPhi"));
        doubleSpinBoxCosPhi->setDecimals(3);
        doubleSpinBoxCosPhi->setMinimum(0.01);
        doubleSpinBoxCosPhi->setMaximum(1);
        doubleSpinBoxCosPhi->setSingleStep(0.1);
        doubleSpinBoxCosPhi->setValue(1);

        horizontalLayout_8->addWidget(doubleSpinBoxCosPhi);


        horizontalLayout_11->addLayout(horizontalLayout_8);


        gridLayout_2->addLayout(horizontalLayout_11, 0, 0, 1, 3);

        radioButtonPutile = new QRadioButton(groupBox);
        radioButtonPutile->setObjectName(QStringLiteral("radioButtonPutile"));
        radioButtonPutile->setChecked(false);
        radioButtonPutile->setAutoRepeat(false);

        gridLayout_2->addWidget(radioButtonPutile, 1, 0, 2, 1);

        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 1, 1, 2, 3);

        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_2->addWidget(label_18, 2, 2, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        doubleSpinBoxPutile = new QDoubleSpinBox(groupBox);
        doubleSpinBoxPutile->setObjectName(QStringLiteral("doubleSpinBoxPutile"));
        doubleSpinBoxPutile->setDecimals(3);
        doubleSpinBoxPutile->setMaximum(1000);
        doubleSpinBoxPutile->setSingleStep(0.5);

        horizontalLayout_2->addWidget(doubleSpinBoxPutile);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(20);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_5->addWidget(label_7);

        doubleSpinBoxRendement = new QDoubleSpinBox(groupBox);
        doubleSpinBoxRendement->setObjectName(QStringLiteral("doubleSpinBoxRendement"));
        doubleSpinBoxRendement->setDecimals(3);
        doubleSpinBoxRendement->setMinimum(0.01);
        doubleSpinBoxRendement->setMaximum(1);
        doubleSpinBoxRendement->setSingleStep(0.1);
        doubleSpinBoxRendement->setValue(1);

        horizontalLayout_5->addWidget(doubleSpinBoxRendement);


        verticalLayout_2->addLayout(horizontalLayout_5);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout_2);

        comboBoxUnitePU = new QComboBox(groupBox);
        comboBoxUnitePU->setObjectName(QStringLiteral("comboBoxUnitePU"));
        comboBoxUnitePU->setMinimumSize(QSize(41, 20));
        comboBoxUnitePU->setMaximumSize(QSize(41, 20));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBoxUnitePU);


        gridLayout_2->addLayout(formLayout, 3, 0, 1, 4);

        radioButtonCourant_Tension = new QRadioButton(groupBox);
        radioButtonCourant_Tension->setObjectName(QStringLiteral("radioButtonCourant_Tension"));
        radioButtonCourant_Tension->setChecked(true);

        gridLayout_2->addWidget(radioButtonCourant_Tension, 4, 0, 1, 1);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 4, 1, 1, 3);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_4->addWidget(label_14);

        doubleSpinBoxCourant = new QDoubleSpinBox(groupBox);
        doubleSpinBoxCourant->setObjectName(QStringLiteral("doubleSpinBoxCourant"));
        doubleSpinBoxCourant->setMaximum(1000);

        horizontalLayout_4->addWidget(doubleSpinBoxCourant);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_7->addWidget(label_16);

        comboBoxTension = new QComboBox(groupBox);
        comboBoxTension->setObjectName(QStringLiteral("comboBoxTension"));

        horizontalLayout_7->addWidget(comboBoxTension);


        verticalLayout_3->addLayout(horizontalLayout_7);


        horizontalLayout_10->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_4->addWidget(label_15);

        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QStringLiteral("label_17"));

        verticalLayout_4->addWidget(label_17);


        horizontalLayout_10->addLayout(verticalLayout_4);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, horizontalLayout_10);

        groupBoxNPhase = new QGroupBox(groupBox);
        groupBoxNPhase->setObjectName(QStringLiteral("groupBoxNPhase"));
        gridLayout = new QGridLayout(groupBoxNPhase);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Monophase = new QRadioButton(groupBoxNPhase);
        Monophase->setObjectName(QStringLiteral("Monophase"));

        gridLayout->addWidget(Monophase, 0, 0, 1, 1);

        Triphase = new QRadioButton(groupBoxNPhase);
        Triphase->setObjectName(QStringLiteral("Triphase"));

        gridLayout->addWidget(Triphase, 1, 0, 1, 1);


        formLayout_2->setWidget(0, QFormLayout::FieldRole, groupBoxNPhase);


        gridLayout_2->addLayout(formLayout_2, 5, 0, 1, 4);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_3, 6, 1, 1, 3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_9->addWidget(label_6);

        doubleSpinBoxPabsorbee = new QDoubleSpinBox(groupBox);
        doubleSpinBoxPabsorbee->setObjectName(QStringLiteral("doubleSpinBoxPabsorbee"));
        doubleSpinBoxPabsorbee->setDecimals(3);
        doubleSpinBoxPabsorbee->setMaximum(10000);
        doubleSpinBoxPabsorbee->setSingleStep(0.5);

        horizontalLayout_9->addWidget(doubleSpinBoxPabsorbee);


        gridLayout_2->addLayout(horizontalLayout_9, 7, 0, 1, 3);

        comboBoxUnitePA = new QComboBox(groupBox);
        comboBoxUnitePA->setObjectName(QStringLiteral("comboBoxUnitePA"));
        comboBoxUnitePA->setMinimumSize(QSize(41, 20));
        comboBoxUnitePA->setMaximumSize(QSize(41, 20));

        gridLayout_2->addWidget(comboBoxUnitePA, 7, 3, 1, 1);

        radioButtonPabsorbee = new QRadioButton(groupBox);
        radioButtonPabsorbee->setObjectName(QStringLiteral("radioButtonPabsorbee"));
        radioButtonPabsorbee->setChecked(false);

        gridLayout_2->addWidget(radioButtonPabsorbee, 6, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 1, 0, 1, 1);

        splitter = new QSplitter(BDFormulaireDeRecepteur);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setLayoutDirection(Qt::RightToLeft);
        splitter->setOrientation(Qt::Horizontal);
        btn_Annuler = new QPushButton(splitter);
        btn_Annuler->setObjectName(QStringLiteral("btn_Annuler"));
        btn_Annuler->setMinimumSize(QSize(75, 23));
        btn_Annuler->setMaximumSize(QSize(75, 23));
        splitter->addWidget(btn_Annuler);
        btn_OK = new QPushButton(splitter);
        btn_OK->setObjectName(QStringLiteral("btn_OK"));
        btn_OK->setMinimumSize(QSize(75, 23));
        btn_OK->setMaximumSize(QSize(75, 23));
        splitter->addWidget(btn_OK);

        gridLayout_4->addWidget(splitter, 2, 0, 1, 1);


        retranslateUi(BDFormulaireDeRecepteur);

        QMetaObject::connectSlotsByName(BDFormulaireDeRecepteur);
    } // setupUi

    void retranslateUi(QDialog *BDFormulaireDeRecepteur)
    {
        BDFormulaireDeRecepteur->setWindowTitle(QApplication::translate("BDFormulaireDeRecepteur", "Dialog", 0));
        groupBox_3->setTitle(QApplication::translate("BDFormulaireDeRecepteur", "Description", 0));
        label->setText(QApplication::translate("BDFormulaireDeRecepteur", "Type de r\303\251cepteur :", 0));
        label_2->setText(QApplication::translate("BDFormulaireDeRecepteur", "D\303\251signation : ", 0));
        label_12->setText(QApplication::translate("BDFormulaireDeRecepteur", "Quantit\303\251 :", 0));
        btn_predefini->setText(QApplication::translate("BDFormulaireDeRecepteur", "Pr\303\251d\303\251fini", 0));
        groupBox->setTitle(QApplication::translate("BDFormulaireDeRecepteur", "Caract\303\251ristiques", 0));
        label_8->setText(QApplication::translate("BDFormulaireDeRecepteur", "Ku :", 0));
        label_11->setText(QApplication::translate("BDFormulaireDeRecepteur", "cos Phi :", 0));
        radioButtonPutile->setText(QApplication::translate("BDFormulaireDeRecepteur", "Puissance utile", 0));
        label_18->setText(QString());
        label_3->setText(QApplication::translate("BDFormulaireDeRecepteur", "Puissance utile :", 0));
        label_7->setText(QApplication::translate("BDFormulaireDeRecepteur", "Rendement :", 0));
        comboBoxUnitePU->clear();
        comboBoxUnitePU->insertItems(0, QStringList()
         << QApplication::translate("BDFormulaireDeRecepteur", "kW", 0)
         << QApplication::translate("BDFormulaireDeRecepteur", "W", 0)
         << QApplication::translate("BDFormulaireDeRecepteur", "ch", 0)
        );
        radioButtonCourant_Tension->setText(QApplication::translate("BDFormulaireDeRecepteur", "Courant / Tension", 0));
        label_14->setText(QApplication::translate("BDFormulaireDeRecepteur", "Courant :", 0));
        label_16->setText(QApplication::translate("BDFormulaireDeRecepteur", "Tension :", 0));
        comboBoxTension->clear();
        comboBoxTension->insertItems(0, QStringList()
         << QApplication::translate("BDFormulaireDeRecepteur", "127", 0)
         << QApplication::translate("BDFormulaireDeRecepteur", "220", 0)
         << QApplication::translate("BDFormulaireDeRecepteur", "231", 0)
         << QApplication::translate("BDFormulaireDeRecepteur", "381", 0)
         << QApplication::translate("BDFormulaireDeRecepteur", "400", 0)
         << QApplication::translate("BDFormulaireDeRecepteur", "415", 0)
         << QApplication::translate("BDFormulaireDeRecepteur", "500", 0)
         << QApplication::translate("BDFormulaireDeRecepteur", "660", 0)
        );
        label_15->setText(QApplication::translate("BDFormulaireDeRecepteur", "A", 0));
        label_17->setText(QApplication::translate("BDFormulaireDeRecepteur", "V", 0));
        groupBoxNPhase->setTitle(QApplication::translate("BDFormulaireDeRecepteur", "N-phas\303\251", 0));
        Monophase->setText(QApplication::translate("BDFormulaireDeRecepteur", "monophas\303\251", 0));
        Triphase->setText(QApplication::translate("BDFormulaireDeRecepteur", "triphas\303\251", 0));
        label_6->setText(QApplication::translate("BDFormulaireDeRecepteur", "Puissance absorb\303\251e :", 0));
        comboBoxUnitePA->clear();
        comboBoxUnitePA->insertItems(0, QStringList()
         << QApplication::translate("BDFormulaireDeRecepteur", "kW", 0)
         << QApplication::translate("BDFormulaireDeRecepteur", "W", 0)
        );
        radioButtonPabsorbee->setText(QApplication::translate("BDFormulaireDeRecepteur", "Puissance absorb\303\251e", 0));
        btn_Annuler->setText(QApplication::translate("BDFormulaireDeRecepteur", "Annuler", 0));
        btn_OK->setText(QApplication::translate("BDFormulaireDeRecepteur", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class BDFormulaireDeRecepteur: public Ui_BDFormulaireDeRecepteur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDFORMULAIREDERECEPTEUR_H
