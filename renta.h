#ifndef RENTA_H
#define RENTA_H
#include<QString>
#include<misexcepciones.h>
class Renta
{
private:
    QString nombreEmpresa;
    double dineroTotal;

public:
    Renta();
    Renta(QString,double);
    ~Renta();
    void setNombreEmpresa(QString);

    void setDineroTotal(double);
    QString getNombreEmpresa(){return this->nombreEmpresa;}

    double getDineroTotal(){return this->dineroTotal;}
};

#endif // RENTA_H
