/********************************************************************************
** Form generated from reading UI file 'BDParamTransfo.ui'
**
** Created: Sun 25. Aug 17:53:58 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDPARAMTRANSFO_H
#define UI_BDPARAMTRANSFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QSplitter>

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
            BDParamTransfo->setObjectName(QString::fromUtf8("BDParamTransfo"));
        BDParamTransfo->resize(240, 162);
        BDParamTransfo->setMinimumSize(QSize(240, 162));
        BDParamTransfo->setMaximumSize(QSize(240, 162));
        gridLayout = new QGridLayout(BDParamTransfo);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(67);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(BDParamTransfo);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        doubleSpinBoxExtension = new QDoubleSpinBox(BDParamTransfo);
        doubleSpinBoxExtension->setObjectName(QString::fromUtf8("doubleSpinBoxExtension"));
        doubleSpinBoxExtension->setMinimum(1.2);
        doubleSpinBoxExtension->setMaximum(1.4);
        doubleSpinBoxExtension->setSingleStep(0.1);

        horizontalLayout->addWidget(doubleSpinBoxExtension);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(BDParamTransfo);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBoxTempAmb = new QSpinBox(BDParamTransfo);
        spinBoxTempAmb->setObjectName(QString::fromUtf8("spinBoxTempAmb"));
        spinBoxTempAmb->setMaximum(50);
        spinBoxTempAmb->setSingleStep(10);

        horizontalLayout_2->addWidget(spinBoxTempAmb);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        label_3 = new QLabel(BDParamTransfo);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(BDParamTransfo);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEditKI = new QLineEdit(BDParamTransfo);
        lineEditKI->setObjectName(QString::fromUtf8("lineEditKI"));
        lineEditKI->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditKI->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEditKI);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(32);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(BDParamTransfo);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        lineEditFacteurDePuiss = new QLineEdit(BDParamTransfo);
        lineEditFacteurDePuiss->setObjectName(QString::fromUtf8("lineEditFacteurDePuiss"));
        lineEditFacteurDePuiss->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditFacteurDePuiss->setReadOnly(true);

        horizontalLayout_4->addWidget(lineEditFacteurDePuiss);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 2);

        line = new QFrame(BDParamTransfo);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 4, 0, 1, 2);

        splitter = new QSplitter(BDParamTransfo);
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

        gridLayout->addWidget(splitter, 5, 0, 1, 2);


        retranslateUi(BDParamTransfo);

        QMetaObject::connectSlotsByName(BDParamTransfo);
    } // setupUi

    void retranslateUi(QDialog *BDParamTransfo)
    {
        BDParamTransfo->setWindowTitle(QApplication::translate("BDParamTransfo", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDParamTransfo", "Extension:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDParamTransfo", "Temp\303\251rature ambiante:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDParamTransfo", "\302\260C", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDParamTransfo", "Correction de temp\303\251rature:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BDParamTransfo", "Facteur de puissance:", 0, QApplication::UnicodeUTF8));
        btn_Annuler->setText(QApplication::translate("BDParamTransfo", "Annuler", 0, QApplication::UnicodeUTF8));
        btn_OK->setText(QApplication::translate("BDParamTransfo", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDParamTransfo: public Ui_BDParamTransfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDPARAMTRANSFO_H
