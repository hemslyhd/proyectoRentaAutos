#include "renta.h"

Renta::Renta()
{

}
Renta::Renta(QString nombre, double dinero, int cantAutos){

    setNombreEmpresa(nombre);

    setDineroTotal(dinero);
    setCantTotalAutos(cantAutos);
}

Renta::~Renta()
{

}
void Renta::setNombreEmpresa(QString nombre){
    if(nombre==""){
        throw valor_invalido();
    }
    this->nombreEmpresa=nombre;
}

void Renta::setDineroTotal(double dinero){
    if(dinero>0){
        this->dineroTotal=dinero;
    }
    else{
        throw valor_invalido();
    }
}
void Renta::setCantTotalAutos(int cantAutos){
    this->cantTotalAuto=cantAutos;
}
