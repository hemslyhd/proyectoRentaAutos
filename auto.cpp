#include "auto.h"

Auto::Auto()
{

}
Auto::Auto(QString marca,QString modelo,QString chapa,float km,int cantMant,float Prenta,int estadoAlquilado,int estadoMant,int dias)
{
   setMarca(marca);
   setModelo(modelo);
   setChapa(chapa);
   setKilometrosRecorridos(km);
   setCantMantenimientos(cantMant);
   setPrecioRenta(Prenta);
   setEstadoAlquilado(estadoAlquilado);
   setEstadoMantenimiento(estadoMant);
   setDiasAlquilados(dias);
}
Auto::~Auto()
{

}
void Auto::setMarca(QString marca){
    if(marca==""){
        throw marca_invalida(); //lanzo una excepion
    }
    else{
    this->marca=marca;
   }
}
void Auto::setModelo(QString modelo){
    this->modelo=modelo;
}
void Auto::setChapa(QString chapa){
    if(chapa==""){
        throw chapa_invalida(); //lanzo una excepcion
    }
    else{


    for(int i=0; i<chapa.size();i++){
        if( (chapa[i] >= 'A' and chapa[i] <= 'Z')|| (chapa[i] >= '0' and chapa[i] <= '9') ){
            continue;
        }
        else{

            throw chapa_invalida(); //lanzo una excepcion
            break;
        }
    }

   this->chapa=chapa;

}
}
void Auto::setKilometrosRecorridos(float km){
    this->kilometrosRecorridos=km;
}

void Auto::setCantMantenimientos(int cantmant){
    this->cantMantenimientos=cantmant;
}

void Auto::setPrecioRenta(float precio){
    this->precioRenta=precio;
}

void Auto::setEstadoAlquilado(int alquilado){
    this->estadoAlquilado=alquilado;
}

void Auto::setEstadoMantenimiento(int mantenimiento){
    this->estadoMantenimiento=mantenimiento;
}

void Auto::setDiasAlquilados(int dias){
    this->diasAlquilados=dias;
}
void Auto::mostrarInfo(){

}
