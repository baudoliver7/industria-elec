﻿#ifndef BDAPROPOS_H
#define BDAPROPOS_H

#include <QDialog>

namespace Ui {
    class BDApropos;
}

class BDApropos : public QDialog {
    Q_OBJECT
public:
    BDApropos(QWidget *parent = 0);
    ~BDApropos();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDApropos *ui;
};

#endif // BDAPROPOS_H
