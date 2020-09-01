#ifndef DIALOGOUVRIRINSTALLATION_H
#define DIALOGOUVRIRINSTALLATION_H

#include <QDialog>
#include <QStringList>
#include <QPushButton>

#include "InfosSurBD.h"

namespace Ui {
    class DialogOuvrirInstallation;
}

class DialogOuvrirInstallation : public QDialog {
    Q_OBJECT
public:
    DialogOuvrirInstallation(QWidget *parent = 0);
    ~DialogOuvrirInstallation();

    QString nomDeInstallation()const;
    QString theme()const;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogOuvrirInstallation *ui;
    QStringList m_themes;

private slots:
    void on_comboBoxTheme_currentIndexChanged(QString );
};

#endif // DIALOGOUVRIRINSTALLATION_H
