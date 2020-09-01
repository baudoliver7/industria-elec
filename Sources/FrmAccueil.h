#ifndef FRMACCUEIL_H
#define FRMACCUEIL_H

#include <QWidget>

namespace Ui {
class FrmAccueil;
}

class FrmAccueil : public QWidget
{
    Q_OBJECT
    
public:
    explicit FrmAccueil(QWidget *parent = 0);
    ~FrmAccueil();

signals:
    void createNewMI();
    void createNewMT();
    void openProject();
    
private slots:

    void on_btn_new_mt_clicked();

    void on_btn_new_mi_clicked();

    void on_btn_open_project_clicked();

private:
    Ui::FrmAccueil *ui;
};

#endif // FRMACCUEIL_H
