#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "cuadros_de_dialogo.h"
#include <QGraphicsScene>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void imagen();
    bool fin = false;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;
    cuadros_de_dialogo *dialogos;
    QGraphicsScene *scena;
};

#endif // DIALOG_H
