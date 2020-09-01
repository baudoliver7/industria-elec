/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 15. Aug 09:12:52 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QPushButton *btn_executer;
    QPushButton *btn_zoomPlus;
    QPushButton *btn_zoomMoins;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 581, 192));
        btn_executer = new QPushButton(centralWidget);
        btn_executer->setObjectName(QString::fromUtf8("btn_executer"));
        btn_executer->setGeometry(QRect(260, 280, 75, 23));
        btn_zoomPlus = new QPushButton(centralWidget);
        btn_zoomPlus->setObjectName(QString::fromUtf8("btn_zoomPlus"));
        btn_zoomPlus->setGeometry(QRect(360, 280, 75, 23));
        btn_zoomMoins = new QPushButton(centralWidget);
        btn_zoomMoins->setObjectName(QString::fromUtf8("btn_zoomMoins"));
        btn_zoomMoins->setGeometry(QRect(460, 280, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        btn_executer->setText(QApplication::translate("MainWindow", "Ex\303\251cuter", 0, QApplication::UnicodeUTF8));
        btn_zoomPlus->setText(QApplication::translate("MainWindow", "zoom +", 0, QApplication::UnicodeUTF8));
        btn_zoomMoins->setText(QApplication::translate("MainWindow", "zoom -", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
