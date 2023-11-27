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
    void agregarNombreDineroEmpresa(QString nombre, int dinero);
    bool verificarEmpresa();
    void limpiarTablaEmpresa();
    void exportarDineroEmpresa(long long &dineroEmpresa);
    void exportarNombreEmpresa(QString &nombre);
    void modificarDineroEmpresa(long long valor , QString nombre);
};

#endif // CONTROLADOR_H
