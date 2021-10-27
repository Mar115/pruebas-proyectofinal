#include "siguiente.h"
#include "ui_siguiente.h"

siguiente::siguiente(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::siguiente)
{
    ui->setupUi(this);
}

siguiente::~siguiente()
{
    delete ui;
}

