#include "bienvenida.h"
#include "ui_bienvenida.h"

Bienvenida::Bienvenida(Renta &empresa,Controlador & controlador,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bienvenida),controladorPantallaBienvenida(controlador),empresa(empresa)
{
    ui->setupUi(this);
}

Bienvenida::~Bienvenida()
{
    delete ui;
}

void Bienvenida::on_pushButtonEntrar_clicked()
{
    if(ui->lineEditNombreEmpresa->text()!=""){
        int opcion=QMessageBox::question(this,"Confirmar?"," El nombre de la empresa es "+ui->lineEditNombreEmpresa->text()+" y la cantidad de dinero inicial es "+ QString::number( ui->spinBoxCantDinero->value()) + "el numero maximo de autos es "+ QString::number(ui->spinBoxCantAutos->value()),QMessageBox::Yes|QMessageBox::No);
        if(opcion==QMessageBox::Yes){
            this->close();
            this->parentWidget()->show();
            QString nombre;
            int cantAutos;
            double dinero;
            nombre=ui->lineEditNombreEmpresa->text();
            cantAutos=ui->spinBoxCantAutos->value();
            dinero=ui->spinBoxCantDinero->value();
            //controladorPantallaBienvenida.agregarNombreDineroCantidadEmpresa(nombre,dinero,cantAutos);
            controladorPantallaBienvenida.agregarNombreDineroCantidadEmpresa(nombre,dinero,cantAutos);
            empresa.setNombreEmpresa(nombre);
            empresa.setDineroTotal(dinero);
            empresa.setCantTotalAutos(cantAutos);
        }
    }
    else{
         QMessageBox::information(this,"Error","Debe poner el nombre de la empresa");
    }
}

void Bienvenida::on_pushButtonCerrar_clicked()
{
    this->parentWidget()->close();
    this->close();
}

