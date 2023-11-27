#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <QVariant>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "auto.h"
#include <stdexcept>
#include <QString>
#include<QDebug>
#include<QtSql/qsqlerror.h>


class Controlador
{
private:
    QSqlDatabase db;
public:

    ~Controlador();
    Controlador();
    void exportarVector(QVector<Auto>& listado);
    void agregarAuto(Auto &autoNuevo);
    void limpiarBaseDato();
    void modificarRentarAuto( QString marca , QString modelo,QString chapa,int dias);
    void modificarRecibirAuto(QString marca , QString modelo,QString chapa,int cantKm);
    void sacarAutoMantenimiento(QString marca , QString modelo,QString chapa);
    void mandarAutoMantenimiento(QString marca , QString modelo,QString chapa , int cantMant);
    void darBajaAuto(QString marca , QString modelo,QString chapa);
    //agregar nombre de empresa y dinero
    void agregarNombreDineroCantidadEmpresa(QString nombre, int dinero,int cantidad);
    bool verificarEmpresa();
    void limpiarTablaEmpresa();
    void exportarDineroEmpresa(long long &dineroEmpresa);
    void exportarNombreEmpresa(QString &nombre);
    void modificarDineroEmpresa(long long valor , QString nombre);
    void exportarCantAutos(int &cant);
};

#endif // CONTROLADOR_H
