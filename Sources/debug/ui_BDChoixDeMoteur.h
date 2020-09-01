/********************************************************************************
** Form generated from reading UI file 'BDChoixDeMoteur.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDCHOIXDEMOTEUR_H
#define UI_BDCHOIXDEMOTEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BDChoixDeMoteur
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_2;
    QLabel *label;
    QComboBox *comboBoxTypeDeMoteur;
    QFormLayout *formLayout;
    QGroupBox *groupBoxTypeDeRendement;
    QGridLayout *gridLayout;
    QRadioButton *RUnDemi;
    QRadioButton *RTroisQuart;
    QRadioButton *RQuatreQuart;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *KW;
    QRadioButton *ch;
    QTableView *tableView;
    QSplitter *splitter;
    QPushButton *btn_Annuler;
    QPushButton *btn_OK;

    void setupUi(QDialog *BDChoixDeMoteur)
    {
        if (BDChoixDeMoteur->objectName().isEmpty())
            BDChoixDeMoteur->setObjectName(QStringLiteral("BDChoixDeMoteur"));
        BDChoixDeMoteur->resize(719, 429);
        verticalLayout = new QVBoxLayout(BDChoixDeMoteur);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter_2 = new QSplitter(BDChoixDeMoteur);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(82, 16777215));
        splitter_2->addWidget(label);
        comboBoxTypeDeMoteur = new QComboBox(splitter_2);
        comboBoxTypeDeMoteur->setObjectName(QStringLiteral("comboBoxTypeDeMoteur"));
        comboBoxTypeDeMoteur->setMaximumSize(QSize(16777215, 16777215));
        splitter_2->addWidget(comboBoxTypeDeMoteur);

        verticalLayout->addWidget(splitter_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(23);
        groupBoxTypeDeRendement = new QGroupBox(BDChoixDeMoteur);
        groupBoxTypeDeRendement->setObjectName(QStringLiteral("groupBoxTypeDeRendement"));
        groupBoxTypeDeRendement->setMaximumSize(QSize(323, 50));
        gridLayout = new QGridLayout(groupBoxTypeDeRendement);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        RUnDemi = new QRadioButton(groupBoxTypeDeRendement);
        RUnDemi->setObjectName(QStringLiteral("RUnDemi"));

        gridLayout->addWidget(RUnDemi, 0, 0, 1, 1);

        RTroisQuart = new QRadioButton(groupBoxTypeDeRendement);
        RTroisQuart->setObjectName(QStringLiteral("RTroisQuart"));

        gridLayout->addWidget(RTroisQuart, 0, 1, 1, 1);

        RQuatreQuart = new QRadioButton(groupBoxTypeDeRendement);
        RQuatreQuart->setObjectName(QStringLiteral("RQuatreQuart"));

        gridLayout->addWidget(RQuatreQuart, 0, 2, 1, 1);


        formLayout->setWidget(0, QFormLayout::LabelRole, groupBoxTypeDeRendement);

        groupBox = new QGroupBox(BDChoixDeMoteur);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(175, 50));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        KW = new QRadioButton(groupBox);
        KW->setObjectName(QStringLiteral("KW"));

        gridLayout_2->addWidget(KW, 0, 0, 1, 1);

        ch = new QRadioButton(groupBox);
        ch->setObjectName(QStringLiteral("ch"));

        gridLayout_2->addWidget(ch, 0, 1, 1, 1);


        formLayout->setWidget(0, QFormLayout::FieldRole, groupBox);


        verticalLayout->addLayout(formLayout);

        tableView = new QTableView(BDChoixDeMoteur);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(tableView);

        splitter = new QSplitter(BDChoixDeMoteur);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setLayoutDirection(Qt::RightToLeft);
        splitter->setOrientation(Qt::Horizontal);
        btn_Annuler = new QPushButton(splitter);
        btn_Annuler->setObjectName(QStringLiteral("btn_Annuler"));
        btn_Annuler->setMaximumSize(QSize(75, 23));
        splitter->addWidget(btn_Annuler);
        btn_OK = new QPushButton(splitter);
        btn_OK->setObjectName(QStringLiteral("btn_OK"));
        btn_OK->setMaximumSize(QSize(75, 23));
        splitter->addWidget(btn_OK);

        verticalLayout->addWidget(splitter);


        retranslateUi(BDChoixDeMoteur);

        QMetaObject::connectSlotsByName(BDChoixDeMoteur);
    } // setupUi

    void retranslateUi(QDialog *BDChoixDeMoteur)
    {
        BDChoixDeMoteur->setWindowTitle(QApplication::translate("BDChoixDeMoteur", "Dialog", 0));
        label->setText(QApplication::translate("BDChoixDeMoteur", "Type de moteur: ", 0));
        groupBoxTypeDeRendement->setTitle(QApplication::translate("BDChoixDeMoteur", "Type de rendement", 0));
        RUnDemi->setText(QApplication::translate("BDChoixDeMoteur", "Rendement 1/2", 0));
        RTroisQuart->setText(QApplication::translate("BDChoixDeMoteur", "Rendement 3/4", 0));
        RQuatreQuart->setText(QApplication::translate("BDChoixDeMoteur", "Rendement 4/4", 0));
        groupBox->setTitle(QApplication::translate("BDChoixDeMoteur", "Unit\303\251 de puissance \303\240 consid\303\251rer", 0));
        KW->setText(QApplication::translate("BDChoixDeMoteur", "KW", 0));
        ch->setText(QApplication::translate("BDChoixDeMoteur", "ch", 0));
        btn_Annuler->setText(QApplication::translate("BDChoixDeMoteur", "Annuler", 0));
        btn_OK->setText(QApplication::translate("BDChoixDeMoteur", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class BDChoixDeMoteur: public Ui_BDChoixDeMoteur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDCHOIXDEMOTEUR_H
