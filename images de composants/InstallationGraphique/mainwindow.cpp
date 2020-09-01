#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_scale = 0.5;
    m_scene = new QGraphicsScene();

    m_item = new Composant(QPixmap(":images/rectangle.png"),0, new QGraphicsScene(), m_scene);
    m_item->setScale(0.5);
    m_item->setText("ITEM 0");

    m_item1 = new Composant(QPixmap(":images/rectangle.png"),0, new QGraphicsScene(), m_scene);
    m_item1->setScale(0.5);
    m_item1->setText("ITEM 1");

    m_item2 = new Composant(QPixmap(":images/rectangle.png"),0, new QGraphicsScene(), m_scene);
    m_item2->setScale(0.5);
    m_item2->setText("ITEM 2");

    m_item3 = new Composant(QPixmap(":images/rectangle.png"),0, new QGraphicsScene(), m_scene);
    m_item3->setScale(0.5);
    m_item3->setText("ITEM 3");

    m_item4 = new Composant(QPixmap(":images/rectangle.png"),0, new QGraphicsScene(), m_scene);
    m_item4->setScale(0.5);
    m_item4->setText("ITEM 4");

    m_item5 = new Composant(QPixmap(":images/rectangle.png"),0, new QGraphicsScene(), m_scene);
    m_item5->setScale(0.5);
    m_item5->setText("ITEM 5");


    m_scene->addItem(m_item);
    m_scene->addItem(m_item1);
    m_scene->addItem(m_item2);
    m_scene->addItem(m_item3);
//    m_scene->addItem(m_item4);
//    m_scene->addItem(m_item5);

    ui->graphicsView->setScene(m_scene);
    //m_scene->setSceneRect(10,10, ui->graphicsView->width() - 10, ui->graphicsView->height() -10);
    m_item->setPos(250,100);
    m_item2->setPos(10,80);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_item;
    delete m_item1;
    delete m_item2;
    delete m_item3;
    delete m_item4;
    delete m_item5;
    delete m_scene;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_btn_executer_clicked()
{
    GroupeDeComposants group;
    group.setY(m_item->y());
    group.ajouterUnComposant(m_item2);
    group.ajouterUnComposant(m_item);
    group.ajouterUnComposant(m_item3);
//    group.ajouterUnComposant(m_item4);
//    group.ajouterUnComposant(m_item5);
//    group.ajouterUnEltFictif(3);
//
//    group.centrerH(m_item1, m_item->y(), 30);
//

    Cable * cable  = new Cable(m_scene);
    m_scene->addItem(cable);
    cable->connecter(m_item1, group, 10.0);
    //m_item1->connecterA(group, 10, true, m_item->y());
}

void MainWindow::on_btn_zoomPlus_clicked()
{
    if(m_scale < 1.0)
    {
        m_scale += 0.25;
        m_item->setScale(m_scale);
        m_item1->setScale(m_scale);;
        m_item2->setScale(m_scale);;
        m_item3->setScale(m_scale);;
        m_item4->setScale(m_scale);;
        m_item5->setScale(m_scale);;

        on_btn_executer_clicked();
    }
}

void MainWindow::on_btn_zoomMoins_clicked()
{
    if(m_scale > 0.25)
    {
        m_scale -= 0.25;
        m_item->setScale(m_scale);
        m_item1->setScale(m_scale);;
        m_item2->setScale(m_scale);;
        m_item3->setScale(m_scale);;
        m_item4->setScale(m_scale);;
        m_item5->setScale(m_scale);;

        on_btn_executer_clicked();
    }
}
