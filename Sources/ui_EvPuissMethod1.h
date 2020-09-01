/********************************************************************************
** Form generated from reading UI file 'EvPuissMethod1.ui'
**
** Created: Sun 25. Aug 17:53:58 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVPUISSMETHOD1_H
#define UI_EVPUISSMETHOD1_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EvPuissMethod1
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *EvPuissMethod1)
    {
        if (EvPuissMethod1->objectName().isEmpty())
            EvPuissMethod1->setObjectName(QString::fromUtf8("EvPuissMethod1"));
        EvPuissMethod1->resize(840, 620);
        EvPuissMethod1->setMinimumSize(QSize(0, 0));
        EvPuissMethod1->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(EvPuissMethod1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(EvPuissMethod1);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 2);


        retranslateUi(EvPuissMethod1);

        QMetaObject::connectSlotsByName(EvPuissMethod1);
    } // setupUi

    void retranslateUi(QWidget *EvPuissMethod1)
    {
        EvPuissMethod1->setWindowTitle(QApplication::translate("EvPuissMethod1", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EvPuissMethod1: public Ui_EvPuissMethod1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVPUISSMETHOD1_H
