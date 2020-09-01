/********************************************************************************
** Form generated from reading UI file 'BDParamTransfo.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDPARAMTRANSFO_H
#define UI_BDPARAMTRANSFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_BDParamTransfo
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBoxExtension;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBoxTempAmb;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEditKI;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *lineEditFacteurDePuiss;
    QFrame *line;
    QSplitter *splitter;
    QPushButton *btn_Annuler;
    QPushButton *btn_OK;

    void setupUi(QDialog *BDParamTransfo)
    {
        if (BDParamTransfo->objectName().isEmpty())
            BDParamTransfo->setObjectName(QStringLiteral("BDParamTransfo"));
        BDParamTransfo->resize(240, 162);
        BDParamTransfo->setMinimumSize(QSize(240, 162));
        BDParamTransfo->setMaximumSize(QSize(240, 162));
        gridLayout = new QGridLayout(BDParamTransfo);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(67);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(BDParamTransfo);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        doubleSpinBoxExtension = new QDoubleSpinBox(BDParamTransfo);
        doubleSpinBoxExtension->setObjectName(QStringLiteral("doubleSpinBoxExtension"));
        doubleSpinBoxExtension->setMinimum(1.2);
        doubleSpinBoxExtension->setMaximum(1.4);
        doubleSpinBoxExtension->setSingleStep(0.1);

        horizontalLayout->addWidget(doubleSpinBoxExtension);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(BDParamTransfo);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBoxTempAmb = new QSpinBox(BDParamTransfo);
        spinBoxTempAmb->setObjectName(QStringLiteral("spinBoxTempAmb"));
        spinBoxTempAmb->setMaximum(50);
        spinBoxTempAmb->setSingleStep(10);

        horizontalLayout_2->addWidget(spinBoxTempAmb);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        label_3 = new QLabel(BDParamTransfo);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(BDParamTransfo);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEditKI = new QLineEdit(BDParamTransfo);
        lineEditKI->setObjectName(QStringLiteral("lineEditKI"));
        lineEditKI->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditKI->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEditKI);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(32);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(BDParamTransfo);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        lineEditFacteurDePuiss = new QLineEdit(BDParamTransfo);
        lineEditFacteurDePuiss->setObjectName(QStringLiteral("lineEditFacteurDePuiss"));
        lineEditFacteurDePuiss->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditFacteurDePuiss->setReadOnly(true);

        horizontalLayout_4->addWidget(lineEditFacteurDePuiss);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 2);

        line = new QFrame(BDParamTransfo);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 4, 0, 1, 2);

        splitter = new QSplitter(BDParamTransfo);
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

        gridLayout->addWidget(splitter, 5, 0, 1, 2);


        retranslateUi(BDParamTransfo);

        QMetaObject::connectSlotsByName(BDParamTransfo);
    } // setupUi

    void retranslateUi(QDialog *BDParamTransfo)
    {
        BDParamTransfo->setWindowTitle(QApplication::translate("BDParamTransfo", "Dialog", 0));
        label->setText(QApplication::translate("BDParamTransfo", "Extension:", 0));
        label_2->setText(QApplication::translate("BDParamTransfo", "Temp\303\251rature ambiante:", 0));
        label_3->setText(QApplication::translate("BDParamTransfo", "\302\260C", 0));
        label_4->setText(QApplication::translate("BDParamTransfo", "Correction de temp\303\251rature:", 0));
        label_5->setText(QApplication::translate("BDParamTransfo", "Facteur de puissance:", 0));
        btn_Annuler->setText(QApplication::translate("BDParamTransfo", "Annuler", 0));
        btn_OK->setText(QApplication::translate("BDParamTransfo", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class BDParamTransfo: public Ui_BDParamTransfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDPARAMTRANSFO_H
