#include "renta.h"

Renta::Renta()
{

}
Renta::Renta(QString nombre,double dinero){

    setNombreEmpresa(nombre);
    ;
    setDineroTotal(dinero);
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

