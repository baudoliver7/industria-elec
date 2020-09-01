/********************************************************************************
** Form generated from reading UI file 'EvPuissMethod2.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVPUISSMETHOD2_H
#define UI_EVPUISSMETHOD2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EvPuissMethod2
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_4;
    QFormLayout *formLayout_7;
    QFormLayout *formLayout_6;
    QLabel *label_3;
    QComboBox *comboBoxType1;
    QFormLayout *formLayout_4;
    QLabel *label_7;
    QComboBox *comboBoxNature1;
    QLabel *labelPhoto;
    QGroupBox *groupBoxDescripttion;
    QFormLayout *formLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QComboBox *comboBoxTableauParent;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEditDesignation;
    QFormLayout *formLayout;
    QLabel *label_2;
    QTextEdit *textEditDescription;
    QPushButton *btn_predefini;
    QGroupBox *groupBoxCaracteristiques;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout_15;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_10;
    QLabel *labelPU;
    QDoubleSpinBox *doubleSpinBoxPUtile;
    QHBoxLayout *horizontalLayout_14;
    QLabel *labelCourant;
    QSpinBox *spinBoxCourant;
    QHBoxLayout *horizontalLayout_15;
    QLabel *labelTension;
    QComboBox *comboBoxTension;
    QComboBox *comboBoxUnite;
    QFormLayout *formLayout_5;
    QLabel *label_5;
    QSpinBox *spinBoxNbre;
    QCheckBox *checkBoxAtelier;
    QLabel *label_4;
    QFrame *line;
    QHBoxLayout *horizontalLayout_11;
    QLabel *labelRend;
    QDoubleSpinBox *doubleSpinBoxRend;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBoxCosPhi;
    QFormLayout *formLayout_2;
    QPushButton *btn_enregistrer;
    QPushButton *btn_initialiser;
    QTabWidget *tabWidget_2;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout_10;
    QFormLayout *formLayout_9;
    QLabel *label_9;
    QComboBox *comboBoxType2;
    QFormLayout *formLayout_8;
    QLabel *label_10;
    QComboBox *comboBoxNature2;
    QTableWidget *tableWidgetDesCpts;
    QFormLayout *formLayout_11;
    QPushButton *btn_modifier;
    QPushButton *btn_supprimer;
    QPushButton *btn_VoirTransfoAdapte;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_3;
    QFormLayout *formLayout_12;
    QLabel *label_11;
    QLineEdit *lineEditPinstallee;
    QFormLayout *formLayout_13;
    QLabel *label_12;
    QLineEdit *lineEditPUtilisee;
    QFormLayout *formLayout_14;
    QLabel *label_13;
    QLineEdit *lineEditCosPhi;

    void setupUi(QWidget *EvPuissMethod2)
    {
        if (EvPuissMethod2->objectName().isEmpty())
            EvPuissMethod2->setObjectName(QStringLiteral("EvPuissMethod2"));
        EvPuissMethod2->resize(1194, 730);
        gridLayout = new QGridLayout(EvPuissMethod2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(EvPuissMethod2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMaximumSize(QSize(1070, 280));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_4 = new QGridLayout(tab);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        formLayout_7 = new QFormLayout();
        formLayout_7->setObjectName(QStringLiteral("formLayout_7"));
        formLayout_7->setHorizontalSpacing(38);
        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName(QStringLiteral("formLayout_6"));
        formLayout_6->setHorizontalSpacing(15);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(27, 16777215));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_3);

        comboBoxType1 = new QComboBox(tab);
        comboBoxType1->setObjectName(QStringLiteral("comboBoxType1"));
        comboBoxType1->setMaximumSize(QSize(16777215, 16777215));
        comboBoxType1->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, comboBoxType1);


        formLayout_7->setLayout(0, QFormLayout::LabelRole, formLayout_6);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setHorizontalSpacing(15);
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(37, 16777215));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_7);

        comboBoxNature1 = new QComboBox(tab);
        comboBoxNature1->setObjectName(QStringLiteral("comboBoxNature1"));
        comboBoxNature1->setMinimumSize(QSize(120, 0));
        comboBoxNature1->setMaximumSize(QSize(150, 16777215));
        comboBoxNature1->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, comboBoxNature1);


        formLayout_7->setLayout(0, QFormLayout::FieldRole, formLayout_4);


        gridLayout_4->addLayout(formLayout_7, 0, 0, 1, 1);

        labelPhoto = new QLabel(tab);
        labelPhoto->setObjectName(QStringLiteral("labelPhoto"));
        labelPhoto->setMinimumSize(QSize(260, 200));
        labelPhoto->setMaximumSize(QSize(260, 200));
        labelPhoto->setPixmap(QPixmap(QString::fromUtf8(":/images/moteur_photo.png")));
        labelPhoto->setScaledContents(true);

        gridLayout_4->addWidget(labelPhoto, 0, 2, 3, 1);

        groupBoxDescripttion = new QGroupBox(tab);
        groupBoxDescripttion->setObjectName(QStringLiteral("groupBoxDescripttion"));
        formLayout_3 = new QFormLayout(groupBoxDescripttion);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(groupBoxDescripttion);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        comboBoxTableauParent = new QComboBox(groupBoxDescripttion);
        comboBoxTableauParent->setObjectName(QStringLiteral("comboBoxTableauParent"));

        horizontalLayout_4->addWidget(comboBoxTableauParent);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(groupBoxDescripttion);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        lineEditDesignation = new QLineEdit(groupBoxDescripttion);
        lineEditDesignation->setObjectName(QStringLiteral("lineEditDesignation"));

        horizontalLayout_3->addWidget(lineEditDesignation);


        verticalLayout_2->addLayout(horizontalLayout_3);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(groupBoxDescripttion);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        textEditDescription = new QTextEdit(groupBoxDescripttion);
        textEditDescription->setObjectName(QStringLiteral("textEditDescription"));

        formLayout->setWidget(0, QFormLayout::FieldRole, textEditDescription);


        verticalLayout_2->addLayout(formLayout);

        btn_predefini = new QPushButton(groupBoxDescripttion);
        btn_predefini->setObjectName(QStringLiteral("btn_predefini"));
        btn_predefini->setMaximumSize(QSize(75, 23));
        btn_predefini->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_2->addWidget(btn_predefini);


        formLayout_3->setLayout(0, QFormLayout::LabelRole, verticalLayout_2);


        gridLayout_4->addWidget(groupBoxDescripttion, 1, 0, 2, 1);

        groupBoxCaracteristiques = new QGroupBox(tab);
        groupBoxCaracteristiques->setObjectName(QStringLiteral("groupBoxCaracteristiques"));
        gridLayout_2 = new QGridLayout(groupBoxCaracteristiques);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        formLayout_15 = new QFormLayout();
        formLayout_15->setObjectName(QStringLiteral("formLayout_15"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        labelPU = new QLabel(groupBoxCaracteristiques);
        labelPU->setObjectName(QStringLiteral("labelPU"));

        horizontalLayout_10->addWidget(labelPU);

        doubleSpinBoxPUtile = new QDoubleSpinBox(groupBoxCaracteristiques);
        doubleSpinBoxPUtile->setObjectName(QStringLiteral("doubleSpinBoxPUtile"));
        doubleSpinBoxPUtile->setDecimals(3);
        doubleSpinBoxPUtile->setMaximum(1000);

        horizontalLayout_10->addWidget(doubleSpinBoxPUtile);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        labelCourant = new QLabel(groupBoxCaracteristiques);
        labelCourant->setObjectName(QStringLiteral("labelCourant"));

        horizontalLayout_14->addWidget(labelCourant);

        spinBoxCourant = new QSpinBox(groupBoxCaracteristiques);
        spinBoxCourant->setObjectName(QStringLiteral("spinBoxCourant"));
        spinBoxCourant->setMaximum(120);

        horizontalLayout_14->addWidget(spinBoxCourant);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        labelTension = new QLabel(groupBoxCaracteristiques);
        labelTension->setObjectName(QStringLiteral("labelTension"));

        horizontalLayout_15->addWidget(labelTension);

        comboBoxTension = new QComboBox(groupBoxCaracteristiques);
        comboBoxTension->setObjectName(QStringLiteral("comboBoxTension"));

        horizontalLayout_15->addWidget(comboBoxTension);


        verticalLayout->addLayout(horizontalLayout_15);


        formLayout_15->setLayout(0, QFormLayout::LabelRole, verticalLayout);

        comboBoxUnite = new QComboBox(groupBoxCaracteristiques);
        comboBoxUnite->setObjectName(QStringLiteral("comboBoxUnite"));
        comboBoxUnite->setMaximumSize(QSize(50, 16777215));

        formLayout_15->setWidget(0, QFormLayout::FieldRole, comboBoxUnite);


        gridLayout_2->addLayout(formLayout_15, 0, 0, 1, 3);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        label_5 = new QLabel(groupBoxCaracteristiques);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_5);

        spinBoxNbre = new QSpinBox(groupBoxCaracteristiques);
        spinBoxNbre->setObjectName(QStringLiteral("spinBoxNbre"));
        spinBoxNbre->setMinimum(1);
        spinBoxNbre->setMaximum(1000);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, spinBoxNbre);


        gridLayout_2->addLayout(formLayout_5, 0, 3, 1, 1);

        checkBoxAtelier = new QCheckBox(groupBoxCaracteristiques);
        checkBoxAtelier->setObjectName(QStringLiteral("checkBoxAtelier"));

        gridLayout_2->addWidget(checkBoxAtelier, 1, 0, 1, 1);

        label_4 = new QLabel(groupBoxCaracteristiques);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        line = new QFrame(groupBoxCaracteristiques);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 2, 1, 1, 3);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        labelRend = new QLabel(groupBoxCaracteristiques);
        labelRend->setObjectName(QStringLiteral("labelRend"));

        horizontalLayout_11->addWidget(labelRend);

        doubleSpinBoxRend = new QDoubleSpinBox(groupBoxCaracteristiques);
        doubleSpinBoxRend->setObjectName(QStringLiteral("doubleSpinBoxRend"));
        doubleSpinBoxRend->setDecimals(3);
        doubleSpinBoxRend->setMinimum(0.01);
        doubleSpinBoxRend->setMaximum(1);
        doubleSpinBoxRend->setSingleStep(0.01);
        doubleSpinBoxRend->setValue(1);

        horizontalLayout_11->addWidget(doubleSpinBoxRend);


        gridLayout_2->addLayout(horizontalLayout_11, 3, 0, 1, 2);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_8 = new QLabel(groupBoxCaracteristiques);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_12->addWidget(label_8);

        doubleSpinBoxCosPhi = new QDoubleSpinBox(groupBoxCaracteristiques);
        doubleSpinBoxCosPhi->setObjectName(QStringLiteral("doubleSpinBoxCosPhi"));
        doubleSpinBoxCosPhi->setMinimum(0.01);
        doubleSpinBoxCosPhi->setMaximum(1);
        doubleSpinBoxCosPhi->setSingleStep(0.01);
        doubleSpinBoxCosPhi->setValue(1);

        horizontalLayout_12->addWidget(doubleSpinBoxCosPhi);


        gridLayout_2->addLayout(horizontalLayout_12, 3, 2, 1, 2);


        gridLayout_4->addWidget(groupBoxCaracteristiques, 1, 1, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_2->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_2->setHorizontalSpacing(6);
        formLayout_2->setContentsMargins(-1, -1, 9, -1);
        btn_enregistrer = new QPushButton(tab);
        btn_enregistrer->setObjectName(QStringLiteral("btn_enregistrer"));
        btn_enregistrer->setMaximumSize(QSize(75, 23));
        btn_enregistrer->setLayoutDirection(Qt::RightToLeft);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, btn_enregistrer);

        btn_initialiser = new QPushButton(tab);
        btn_initialiser->setObjectName(QStringLiteral("btn_initialiser"));
        btn_initialiser->setMaximumSize(QSize(75, 23));
        btn_initialiser->setLayoutDirection(Qt::RightToLeft);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, btn_initialiser);


        gridLayout_4->addLayout(formLayout_2, 2, 1, 1, 1);

        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        tabWidget_2 = new QTabWidget(EvPuissMethod2);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setMinimumSize(QSize(0, 0));
        tabWidget_2->setMaximumSize(QSize(1070, 16777215));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        formLayout_10 = new QFormLayout();
        formLayout_10->setObjectName(QStringLiteral("formLayout_10"));
        formLayout_10->setHorizontalSpacing(30);
        formLayout_9 = new QFormLayout();
        formLayout_9->setObjectName(QStringLiteral("formLayout_9"));
        formLayout_9->setHorizontalSpacing(15);
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMaximumSize(QSize(27, 16777215));

        formLayout_9->setWidget(0, QFormLayout::LabelRole, label_9);

        comboBoxType2 = new QComboBox(tab_2);
        comboBoxType2->setObjectName(QStringLiteral("comboBoxType2"));
        comboBoxType2->setMaximumSize(QSize(16777215, 16777215));
        comboBoxType2->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        formLayout_9->setWidget(0, QFormLayout::FieldRole, comboBoxType2);


        formLayout_10->setLayout(0, QFormLayout::LabelRole, formLayout_9);

        formLayout_8 = new QFormLayout();
        formLayout_8->setObjectName(QStringLiteral("formLayout_8"));
        formLayout_8->setHorizontalSpacing(15);
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMaximumSize(QSize(37, 16777215));

        formLayout_8->setWidget(0, QFormLayout::LabelRole, label_10);

        comboBoxNature2 = new QComboBox(tab_2);
        comboBoxNature2->setObjectName(QStringLiteral("comboBoxNature2"));
        comboBoxNature2->setMaximumSize(QSize(150, 16777215));
        comboBoxNature2->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        formLayout_8->setWidget(0, QFormLayout::FieldRole, comboBoxNature2);


        formLayout_10->setLayout(0, QFormLayout::FieldRole, formLayout_8);


        verticalLayout_3->addLayout(formLayout_10);

        tableWidgetDesCpts = new QTableWidget(tab_2);
        if (tableWidgetDesCpts->columnCount() < 10)
            tableWidgetDesCpts->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetDesCpts->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetDesCpts->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetDesCpts->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetDesCpts->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetDesCpts->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetDesCpts->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetDesCpts->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetDesCpts->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetDesCpts->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetDesCpts->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        tableWidgetDesCpts->setObjectName(QStringLiteral("tableWidgetDesCpts"));
        tableWidgetDesCpts->setMaximumSize(QSize(16777215, 16777215));
        tableWidgetDesCpts->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetDesCpts->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetDesCpts->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetDesCpts->horizontalHeader()->setDefaultSectionSize(125);
        tableWidgetDesCpts->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_3->addWidget(tableWidgetDesCpts);

        formLayout_11 = new QFormLayout();
        formLayout_11->setObjectName(QStringLiteral("formLayout_11"));
        formLayout_11->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_11->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_11->setContentsMargins(-1, -1, 8, -1);
        btn_modifier = new QPushButton(tab_2);
        btn_modifier->setObjectName(QStringLiteral("btn_modifier"));
        btn_modifier->setMaximumSize(QSize(75, 23));
        btn_modifier->setLayoutDirection(Qt::LeftToRight);

        formLayout_11->setWidget(0, QFormLayout::LabelRole, btn_modifier);

        btn_supprimer = new QPushButton(tab_2);
        btn_supprimer->setObjectName(QStringLiteral("btn_supprimer"));
        btn_supprimer->setMaximumSize(QSize(75, 23));

        formLayout_11->setWidget(0, QFormLayout::FieldRole, btn_supprimer);


        verticalLayout_3->addLayout(formLayout_11);

        btn_VoirTransfoAdapte = new QPushButton(tab_2);
        btn_VoirTransfoAdapte->setObjectName(QStringLiteral("btn_VoirTransfoAdapte"));
        btn_VoirTransfoAdapte->setMinimumSize(QSize(0, 0));
        btn_VoirTransfoAdapte->setMaximumSize(QSize(150, 23));

        verticalLayout_3->addWidget(btn_VoirTransfoAdapte);

        tabWidget_2->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget_2, 1, 0, 1, 1);

        groupBox_5 = new QGroupBox(EvPuissMethod2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setMaximumSize(QSize(1070, 16777215));
        gridLayout_3 = new QGridLayout(groupBox_5);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        formLayout_12 = new QFormLayout();
        formLayout_12->setObjectName(QStringLiteral("formLayout_12"));
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMaximumSize(QSize(121, 16777215));

        formLayout_12->setWidget(0, QFormLayout::LabelRole, label_11);

        lineEditPinstallee = new QLineEdit(groupBox_5);
        lineEditPinstallee->setObjectName(QStringLiteral("lineEditPinstallee"));
        lineEditPinstallee->setMaximumSize(QSize(90, 16777215));
        lineEditPinstallee->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditPinstallee->setReadOnly(true);

        formLayout_12->setWidget(0, QFormLayout::FieldRole, lineEditPinstallee);


        gridLayout_3->addLayout(formLayout_12, 0, 0, 1, 1);

        formLayout_13 = new QFormLayout();
        formLayout_13->setObjectName(QStringLiteral("formLayout_13"));
        formLayout_13->setLabelAlignment(Qt::AlignCenter);
        formLayout_13->setFormAlignment(Qt::AlignCenter);
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMaximumSize(QSize(121, 16777215));

        formLayout_13->setWidget(0, QFormLayout::LabelRole, label_12);

        lineEditPUtilisee = new QLineEdit(groupBox_5);
        lineEditPUtilisee->setObjectName(QStringLiteral("lineEditPUtilisee"));
        lineEditPUtilisee->setMaximumSize(QSize(90, 16777215));
        lineEditPUtilisee->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditPUtilisee->setReadOnly(true);

        formLayout_13->setWidget(0, QFormLayout::FieldRole, lineEditPUtilisee);


        gridLayout_3->addLayout(formLayout_13, 0, 1, 1, 1);

        formLayout_14 = new QFormLayout();
        formLayout_14->setObjectName(QStringLiteral("formLayout_14"));
        formLayout_14->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_14->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_14->setContentsMargins(-1, -1, 10, -1);
        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMaximumSize(QSize(105, 16777215));

        formLayout_14->setWidget(0, QFormLayout::LabelRole, label_13);

        lineEditCosPhi = new QLineEdit(groupBox_5);
        lineEditCosPhi->setObjectName(QStringLiteral("lineEditCosPhi"));
        lineEditCosPhi->setMaximumSize(QSize(44, 16777215));
        lineEditCosPhi->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditCosPhi->setReadOnly(true);

        formLayout_14->setWidget(0, QFormLayout::FieldRole, lineEditCosPhi);


        gridLayout_3->addLayout(formLayout_14, 0, 2, 1, 1);


        gridLayout->addWidget(groupBox_5, 2, 0, 1, 1);


        retranslateUi(EvPuissMethod2);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EvPuissMethod2);
    } // setupUi

    void retranslateUi(QWidget *EvPuissMethod2)
    {
        EvPuissMethod2->setWindowTitle(QApplication::translate("EvPuissMethod2", "Form", 0));
        label_3->setText(QApplication::translate("EvPuissMethod2", "Type:", 0));
        comboBoxType1->clear();
        comboBoxType1->insertItems(0, QStringList()
         << QApplication::translate("EvPuissMethod2", "R\303\251cepteur", 0)
         << QApplication::translate("EvPuissMethod2", "Tableau", 0)
        );
        label_7->setText(QApplication::translate("EvPuissMethod2", "Nature:", 0));
        labelPhoto->setText(QString());
        groupBoxDescripttion->setTitle(QApplication::translate("EvPuissMethod2", "Description", 0));
        label_6->setText(QApplication::translate("EvPuissMethod2", "Tableau parent:", 0));
        label->setText(QApplication::translate("EvPuissMethod2", "D\303\251signation:", 0));
        label_2->setText(QApplication::translate("EvPuissMethod2", "Description:", 0));
        btn_predefini->setText(QApplication::translate("EvPuissMethod2", "Pr\303\251d\303\251fini", 0));
        groupBoxCaracteristiques->setTitle(QApplication::translate("EvPuissMethod2", "Caract\303\251ristiques", 0));
        labelPU->setText(QApplication::translate("EvPuissMethod2", "Puissance utile:", 0));
        labelCourant->setText(QApplication::translate("EvPuissMethod2", "Courant (A):", 0));
        labelTension->setText(QApplication::translate("EvPuissMethod2", "Tension (V):", 0));
        comboBoxTension->clear();
        comboBoxTension->insertItems(0, QStringList()
         << QApplication::translate("EvPuissMethod2", "127", 0)
         << QApplication::translate("EvPuissMethod2", "220", 0)
         << QApplication::translate("EvPuissMethod2", "231", 0)
         << QApplication::translate("EvPuissMethod2", "381", 0)
         << QApplication::translate("EvPuissMethod2", "400", 0)
         << QApplication::translate("EvPuissMethod2", "415", 0)
         << QApplication::translate("EvPuissMethod2", "500", 0)
         << QApplication::translate("EvPuissMethod2", "660", 0)
        );
        comboBoxUnite->clear();
        comboBoxUnite->insertItems(0, QStringList()
         << QApplication::translate("EvPuissMethod2", "kW", 0)
         << QApplication::translate("EvPuissMethod2", "W", 0)
         << QApplication::translate("EvPuissMethod2", "ch", 0)
        );
        label_5->setText(QApplication::translate("EvPuissMethod2", "Nombre:", 0));
        checkBoxAtelier->setText(QApplication::translate("EvPuissMethod2", "Atelier", 0));
        label_4->setText(QApplication::translate("EvPuissMethod2", "A remplir au choix", 0));
        labelRend->setText(QApplication::translate("EvPuissMethod2", "Rendement:", 0));
        label_8->setText(QApplication::translate("EvPuissMethod2", "Facteur de puissance:", 0));
        btn_enregistrer->setText(QApplication::translate("EvPuissMethod2", "Enregistrer", 0));
        btn_initialiser->setText(QApplication::translate("EvPuissMethod2", "Initialiser", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("EvPuissMethod2", "Editer un composant", 0));
        label_9->setText(QApplication::translate("EvPuissMethod2", "Type:", 0));
        comboBoxType2->clear();
        comboBoxType2->insertItems(0, QStringList()
         << QApplication::translate("EvPuissMethod2", "R\303\251cepteur", 0)
         << QApplication::translate("EvPuissMethod2", "Tableau", 0)
        );
        label_10->setText(QApplication::translate("EvPuissMethod2", "Nature:", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetDesCpts->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("EvPuissMethod2", "D\303\251signation", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetDesCpts->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("EvPuissMethod2", "Description", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetDesCpts->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("EvPuissMethod2", "P utile unitaire (kW)", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetDesCpts->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("EvPuissMethod2", "Facteur de puissance", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetDesCpts->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("EvPuissMethod2", "Nombre", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetDesCpts->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("EvPuissMethod2", "P install\303\251e (kW)", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetDesCpts->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("EvPuissMethod2", "Q install\303\251e (kVAR)", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetDesCpts->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("EvPuissMethod2", "P utilis\303\251e (kW)", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetDesCpts->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("EvPuissMethod2", "Q utilis\303\251e (kVAR)", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetDesCpts->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("EvPuissMethod2", "Parent", 0));
        btn_modifier->setText(QApplication::translate("EvPuissMethod2", "Modifier", 0));
        btn_supprimer->setText(QApplication::translate("EvPuissMethod2", "Supprimer", 0));
        btn_VoirTransfoAdapte->setText(QApplication::translate("EvPuissMethod2", "Voir transformateur adapt\303\251", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("EvPuissMethod2", "Votre installation", 0));
        groupBox_5->setTitle(QApplication::translate("EvPuissMethod2", "Informations g\303\251n\303\251rales sur l'installation", 0));
        label_11->setText(QApplication::translate("EvPuissMethod2", "Puissance install\303\251e (kW):", 0));
        label_12->setText(QApplication::translate("EvPuissMethod2", "Puissance utilis\303\251e (kW):", 0));
        label_13->setText(QApplication::translate("EvPuissMethod2", "Facteur de puissance:", 0));
    } // retranslateUi

};

namespace Ui {
    class EvPuissMethod2: public Ui_EvPuissMethod2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVPUISSMETHOD2_H
