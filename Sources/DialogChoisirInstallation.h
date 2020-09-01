#ifndef DIALOGCHOISIRINSTALLATION_H
#define DIALOGCHOISIRINSTALLATION_H

#include <QDialog>

namespace Ui {
    class DialogChoisirInstallation;
}

class DialogChoisirInstallation : public QDialog {
    Q_OBJECT
public:
    DialogChoisirInstallation(QWidget *parent = 0);
    ~DialogChoisirInstallation();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogChoisirInstallation *ui;
};

#endif // DIALOGCHOISIRINSTALLATION_H
