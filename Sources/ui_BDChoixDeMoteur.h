/********************************************************************************
** Form generated from reading UI file 'BDChoixDeMoteur.ui'
**
** Created: Sun 25. Aug 17:53:58 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDCHOIXDEMOTEUR_H
#define UI_BDCHOIXDEMOTEUR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSplitter>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

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
            BDChoixDeMoteur->setObjectName(QString::fromUtf8("BDChoixDeMoteur"));
        BDChoixDeMoteur->resize(719, 429);
        verticalLayout = new QVBoxLayout(BDChoixDeMoteur);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter_2 = new QSplitter(BDChoixDeMoteur);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(82, 16777215));
        splitter_2->addWidget(label);
        comboBoxTypeDeMoteur = new QComboBox(splitter_2);
        comboBoxTypeDeMoteur->setObjectName(QString::fromUtf8("comboBoxTypeDeMoteur"));
        comboBoxTypeDeMoteur->setMaximumSize(QSize(16777215, 16777215));
        splitter_2->addWidget(comboBoxTypeDeMoteur);

        verticalLayout->addWidget(splitter_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(23);
        groupBoxTypeDeRendement = new QGroupBox(BDChoixDeMoteur);
        groupBoxTypeDeRendement->setObjectName(QString::fromUtf8("groupBoxTypeDeRendement"));
        groupBoxTypeDeRendement->setMaximumSize(QSize(323, 50));
        gridLayout = new QGridLayout(groupBoxTypeDeRendement);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        RUnDemi = new QRadioButton(groupBoxTypeDeRendement);
        RUnDemi->setObjectName(QString::fromUtf8("RUnDemi"));

        gridLayout->addWidget(RUnDemi, 0, 0, 1, 1);

        RTroisQuart = new QRadioButton(groupBoxTypeDeRendement);
        RTroisQuart->setObjectName(QString::fromUtf8("RTroisQuart"));

        gridLayout->addWidget(RTroisQuart, 0, 1, 1, 1);

        RQuatreQuart = new QRadioButton(groupBoxTypeDeRendement);
        RQuatreQuart->setObjectName(QString::fromUtf8("RQuatreQuart"));

        gridLayout->addWidget(RQuatreQuart, 0, 2, 1, 1);


        formLayout->setWidget(0, QFormLayout::LabelRole, groupBoxTypeDeRendement);

        groupBox = new QGroupBox(BDChoixDeMoteur);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(175, 50));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        KW = new QRadioButton(groupBox);
        KW->setObjectName(QString::fromUtf8("KW"));

        gridLayout_2->addWidget(KW, 0, 0, 1, 1);

        ch = new QRadioButton(groupBox);
        ch->setObjectName(QString::fromUtf8("ch"));

        gridLayout_2->addWidget(ch, 0, 1, 1, 1);


        formLayout->setWidget(0, QFormLayout::FieldRole, groupBox);


        verticalLayout->addLayout(formLayout);

        tableView = new QTableView(BDChoixDeMoteur);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(tableView);

        splitter = new QSplitter(BDChoixDeMoteur);
        splitter->setObjectName(QString::fromUtf8("splitter"));
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

        verticalLayout->addWidget(splitter);


        retranslateUi(BDChoixDeMoteur);

        QMetaObject::connectSlotsByName(BDChoixDeMoteur);
    } // setupUi

    void retranslateUi(QDialog *BDChoixDeMoteur)
    {
        BDChoixDeMoteur->setWindowTitle(QApplication::translate("BDChoixDeMoteur", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDChoixDeMoteur", "Type de moteur: ", 0, QApplication::UnicodeUTF8));
        groupBoxTypeDeRendement->setTitle(QApplication::translate("BDChoixDeMoteur", "Type de rendement", 0, QApplication::UnicodeUTF8));
        RUnDemi->setText(QApplication::translate("BDChoixDeMoteur", "Rendement 1/2", 0, QApplication::UnicodeUTF8));
        RTroisQuart->setText(QApplication::translate("BDChoixDeMoteur", "Rendement 3/4", 0, QApplication::UnicodeUTF8));
        RQuatreQuart->setText(QApplication::translate("BDChoixDeMoteur", "Rendement 4/4", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDChoixDeMoteur", "Unit\303\251 de puissance \303\240 consid\303\251rer", 0, QApplication::UnicodeUTF8));
        KW->setText(QApplication::translate("BDChoixDeMoteur", "KW", 0, QApplication::UnicodeUTF8));
        ch->setText(QApplication::translate("BDChoixDeMoteur", "ch", 0, QApplication::UnicodeUTF8));
        btn_Annuler->setText(QApplication::translate("BDChoixDeMoteur", "Annuler", 0, QApplication::UnicodeUTF8));
        btn_OK->setText(QApplication::translate("BDChoixDeMoteur", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDChoixDeMoteur: public Ui_BDChoixDeMoteur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDCHOIXDEMOTEUR_H
