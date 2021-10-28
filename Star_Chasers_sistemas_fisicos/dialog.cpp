#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    imagen();
}

Dialog::~Dialog()
{
    delete ui;
    delete dialogos;
    delete scena;
}

void Dialog::imagen()
{
    scena = new QGraphicsScene;
    dialogos = new cuadros_de_dialogo(ui->graphicsView->width(),ui->graphicsView->height());
    scena->setSceneRect(0,0,ui->graphicsView->width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scena);
    scena->addItem(dialogos);
}

void Dialog::on_buttonBox_accepted()
{
    fin = true;
}
