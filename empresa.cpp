#include "empresa.h"
#include "ui_empresa.h"

Empresa::Empresa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Empresa)
{
    ui->setupUi(this);
}

Empresa::~Empresa()
{
    delete ui;
}

void Empresa::on_pushButtonContinuar_clicked()
{

}
