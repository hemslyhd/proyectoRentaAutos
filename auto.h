#ifndef AUTO_H
#define AUTO_H
#include<QString>
#include<misexcepciones.h>
using namespace std;
class Auto
{
private:
    QString marca;
    QString modelo;
    QString chapa;
    float kilometrosRecorridos=0;
    int cantMantenimientos=0;
    float precioRenta;
    int estadoAlquilado;
    int estadoMantenimiento;
    int diasAlquilados;
public:
    Auto();
    ~Auto();
    Auto(QString,QString,QString,float,int,float,int,int,int);
    //set
    void setMarca(QString);
    void setModelo(QString);
    void setChapa(QString);
    void setKilometrosRecorridos(float);
    void setCantMantenimientos(int);
    void setPrecioRenta(float);
    void setEstadoAlquilado(int);
    void setEstadoMantenimiento(int);
    void setDiasAlquilados(int);
    //get
    QString getMarca(){return this->marca;}
    QString getModelo(){return this->modelo;}
    QString getChapa(){return this->chapa;}
    float  getKilometrosRecorridos(){return this->kilometrosRecorridos;}
    int    getCantMantenimientos(){return this->cantMantenimientos;}
    float  getPrecioRenta(){return this->precioRenta;}
    int    getEstadoAlquilado(){return this->estadoAlquilado;}
    int    getEstadoMantenimiento(){return this->estadoMantenimiento;}
    int    getDiasAlquilado(){return this->diasAlquilados;}
    void mostrarInfo();

};

#endif // AUTO_H
