#include "nosotros.h"
#include "ui_nosotros.h"

Nosotros::Nosotros(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nosotros)
{
    ui->setupUi(this);
}

Nosotros::~Nosotros()
{
    delete ui;
}

void Nosotros::on_pushButton_clicked()
{
    this->parentWidget()->show();
    this->close();
}
