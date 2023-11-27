#include "controlador.h"

Controlador::Controlador()
{
    //USAR SQLITE v3
    db=QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("C:/Users/hemslyhd/Documents/RentadeAutos--v1-1/carros.db");
    if(!db.open()){
        throw data_Base_Not_Open();
       // qDebug()<<"No de abrio la base dato";
    }
}

Controlador::~Controlador()
{
    db.close();
}
//Funcion para agregar un auto a la base de dato
void Controlador::agregarAuto(Auto &autoNuevo)
{
    QSqlQuery query(this->db);
    query.prepare("INSERT INTO ListadoAutos(Marca,Modelo,Chapa,KmRecorridos,CantMantenimiento,"
                  "PrecioRenta,EstadoAlquilado,DiasAlquilado,EstadoMantenimiento)"
                  "VALUES (:Marca,:Modelo,:Chapa,:KmRecorridos,:CantMantenimiento,:PrecioRenta,:EstadoAlquilado,"
                  ":DiasAlquilado,:EstadoMantenimiento)");
    query.bindValue(":Marca",autoNuevo.getMarca());
    query.bindValue(":Modelo",autoNuevo.getModelo());
    query.bindValue(":Chapa",autoNuevo.getChapa());
    query.bindValue(":KmRecorridos",autoNuevo.getKilometrosRecorridos());
    query.bindValue(":CantMantenimiento",autoNuevo.getCantMantenimientos());
    query.bindValue(":PrecioRenta",autoNuevo.getPrecioRenta());
    query.bindValue(":EstadoAlquilado",autoNuevo.getEstadoAlquilado());
    query.bindValue(":DiasAlquilado",autoNuevo.getDiasAlquilado());
    query.bindValue(":EstadoMantenimiento",autoNuevo.getEstadoMantenimiento());
    if(query.exec()){
        qDebug()<<"se introdujo un auto correctamente";
    }
    else{
        qDebug()<<"no se introdujo un auto correctamente";
    }

}


//FUNCION PARA LIMPIAR LA BASE DE DATO con excepcion
void Controlador::limpiarBaseDato()
{
    QSqlQuery query(this->db);
    query.prepare("DELETE FROM ListadoAutos");
    if(query.exec()){

    }
    else{
        throw data_base_borrar();
    }

}


//funcion para modificar parametro en auto rentado con excepcion
//ojo ver lo de varios parametros
void Controlador::modificarRentarAuto( QString marca , QString modelo,QString chapa,int dias)
{
    QSqlQuery query(this->db);
    query.prepare("UPDATE ListadoAutos SET EstadoAlquilado=:EstadoAlquilado,"
                  "DiasAlquilado=:DiasAlquilado WHERE Chapa=:Chapa");/*
    query.bindValue(":Marca",marca); AND Modelo=:Modelo AND Chapa=:Chapa
    query.bindValue(":Modelo",modelo);*/
    query.bindValue(":Chapa",chapa);
    query.bindValue(":DiasAlquilado",dias);
    int aux=1;
    query.bindValue(":EstadoAlquilado",aux);
    if(query.exec()){

    }
    else{
         throw data_base_actualizar();

    }
}


//funcion para modificar parametro en auto recibido con excepcion
void Controlador::modificarRecibirAuto(QString marca, QString modelo, QString chapa, int cantKm)
{
     QSqlQuery query(this->db);
    query.prepare("UPDATE ListadoAutos SET EstadoAlquilado=:EstadoAlquilado,"
                  "KmRecorridos=:KmRecorridos WHERE Marca=:Marca ");
    query.bindValue(":Marca",marca);
    query.bindValue(":KmRecorridos",cantKm);
    int aux=0;
    query.bindValue(":EstadoAlquilado",aux);

    if(query.exec()){

    }
    else{
         //qDebug()<<" No Se modifico el auto recibido"<<query.lastError().text();
         throw data_base_actualizar();
    }
}

//funcion para sacar un auto de mantenimiento con excepcion
void Controlador::sacarAutoMantenimiento(QString marca, QString modelo, QString chapa)
{      QSqlQuery query(this->db);
       query.prepare("UPDATE ListadoAutos SET EstadoMantenimiento=:EstadoMantenimiento WHERE Marca=:Marca");

       query.bindValue(":Marca",marca);
       int aux=0;
       query.bindValue(":EstadoMantenimiento",aux);
          if(query.exec()){

          }
          else{
               throw data_base_actualizar();

          }

}


//mandar un auto a mantenimiento con excepion
void Controlador::mandarAutoMantenimiento(QString marca, QString modelo, QString chapa, int cantMant)
{    QSqlQuery query(this->db);
     query.prepare("UPDATE ListadoAutos SET EstadoMantenimiento=:EstadoMantenimiento,"
                   "KmRecorridos=:KmRecorridos,CantMantenimiento=:CantMantenimiento WHERE Marca=:Marca");
     query.bindValue(":Marca",marca);
     int aux=1,aux_1=0;
     query.bindValue(":EstadoMantenimiento",aux);
     query.bindValue(":KmRecorridos",aux_1);
     query.bindValue(":CantMantenimiento",cantMant);
        if(query.exec()){

        }
        else{
             //qDebug()<<" No Se pudo mandar el auto del mantenimiento"<<query.lastError().text();
             throw data_base_actualizar();
        }

}


//funcion para elimianr auto de la tabla con excepcion
void Controlador::darBajaAuto(QString marca, QString modelo, QString chapa)
{
    QSqlQuery query(this->db);
      query.prepare("DELETE FROM ListadoAutos WHERE Marca=:Marca");
      query.bindValue(":Marca",marca);
      if(query.exec()){

      }
      else{
          throw data_base_actualizar();
      }


}

//Agregar nombre empresa y dinero a tabla empresa
void Controlador::agregarNombreDineroCantidadEmpresa(QString nombre, int dinero ,int valor)
{
    QSqlQuery query(this->db);
    query.prepare("INSERT INTO Empresa(Nombre,Dinero,CantidadAutos) VALUES (:Nombre,:Dinero,:CantidadAutos)");
    query.bindValue(":Nombre",nombre);
    query.bindValue(":Dinero",dinero);
    query.bindValue(":CantidadAutos",valor);
    if(query.exec()){
        qDebug()<<"se introdujo info de la empresa ";
    }
    else{
        qDebug()<<"no se introdujo info de la empresa"<<query.lastError().text();
    }
}

//verificar empresa
bool Controlador::verificarEmpresa()
{
    QSqlQuery query(this->db);
    query.prepare("SELECT * FROM Empresa");
    if(query.exec()){
        if(query.first()){
            return true;
        }
        else{
            return false;

        }
    }
    else {
        return false;
    }

}


//limpiar tabla de la empresa con excepcion
void Controlador::limpiarTablaEmpresa()
{
    QSqlQuery query(this->db);
    query.prepare("DELETE FROM Empresa");
    if(query.exec()){

    }
    else{
        throw data_base_borrar();
    }
}


//exportar dinero con excepcion
void Controlador::exportarDineroEmpresa(long long &dineroEmpresa)
{
    QSqlQuery query(this->db);
           if(query.exec("SELECT * FROM Empresa") == false)
                  {

               throw data_base_error_acceso();
                  }
           else{
               while(query.next()){
                  dineroEmpresa=query.value("Dinero").toInt();
               }
           }
}


//exportar nombre con excepcion
void Controlador::exportarNombreEmpresa(QString &nombre)
{
    QSqlQuery query(this->db);
           if(query.exec("SELECT * FROM Empresa") == false)
                  {
               throw data_base_nombre_empresa();
                  }
           else{
               while(query.next()){
                  nombre=query.value("Nombre").toString();
               }
           }
}

//modificar dinero empresa con excepcion
void Controlador::modificarDineroEmpresa(long long valor, QString nombre)
{
    QSqlQuery query(this->db);
         query.prepare("UPDATE Empresa SET Dinero=:Dinero WHERE Nombre=:Nombre");
         query.bindValue(":Dinero",valor);
         query.bindValue(":Nombre",nombre);

            if(query.exec()){

            }
            else{
//                 qDebug()<<" no se modifico el dinero"<<query.lastError().text();
                throw modificar_dinero_empresa();
            }
}
//exportar cantidad de autos
void Controlador::exportarCantAutos(int &cant)
{
    QSqlQuery query(this->db);
           if(query.exec("SELECT * FROM Empresa") == false)
                  {
               throw data_base_error_cantAutos();
                  }
           else{
               while(query.next()){
                  cant=query.value("CantidadAutos").toInt();
               }
           }
}


//fUNCION PARA EXPORTAR LA INFO DE LA TABLA PARA EL VECTOR con excepion
void Controlador::exportarVector(QVector<Auto> &listado)
{
     QSqlQuery query(this->db);
            if(query.exec("SELECT * FROM ListadoAutos") == false)
                   {

                throw data_base_exportar_vector();
                   }
            else{

                while(query.next()){
                QString marca=query.value("Marca").toString();
                QString modelo=query.value("Modelo").toString();
                QString chapa=query.value("Chapa").toString();
                float kilometrosRecorridos=query.value("KmRecorridos").toInt();
                int cantMantenimientos=query.value("CantMantenimiento").toInt();
                float precioRenta=query.value("PrecioRenta").toInt();
                int estadoAlquilado=query.value("EstadoAlquilado").toInt();
                int diasAlquilados=query.value("DiasAlquilado").toInt();
                int estadoMantenimiento=query.value("EstadoMantenimiento").toInt();
                Auto temp(marca,modelo,chapa,kilometrosRecorridos,cantMantenimientos,precioRenta,estadoAlquilado,estadoMantenimiento,diasAlquilados);
                listado.append(temp);
                }
         }
}


