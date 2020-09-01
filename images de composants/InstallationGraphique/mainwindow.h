#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPixmap>

#include "Composant.h"
#include "GroupeDeComposants.h"
#include "Cable.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow * ui;
     Composant * m_item;
     Composant * m_item1;
     Composant * m_item2;
     Composant * m_item3;
     Composant * m_item4;
     Composant * m_item5;
     QGraphicsScene * m_scene;
     float m_scale;

private slots:
    void on_btn_zoomMoins_clicked();
    void on_btn_zoomPlus_clicked();
    void on_btn_executer_clicked();
};

#endif // MAINWINDOW_H
