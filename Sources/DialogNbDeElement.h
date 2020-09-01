#ifndef DIALOGNBDEELEMENT_H
#define DIALOGNBDEELEMENT_H

#include <QDialog>

namespace Ui {
    class DialogNbDeElement;
}

class DialogNbDeElement : public QDialog {
    Q_OBJECT
public:
    DialogNbDeElement(QWidget *parent = 0, QString title = QString(), int nombre = 1);
    ~DialogNbDeElement();

    int nombre()const;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogNbDeElement *ui;

private slots:
    void on_btn_Annuler_clicked();
    void on_btn_OK_clicked();
};

#endif // DIALOGNBDEELEMENT_H
