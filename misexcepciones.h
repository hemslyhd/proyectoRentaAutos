#ifndef MISEXCEPCIONES
#define MISEXCEPCIONES

#include<stdexcept>
#include<QString>
using namespace std;
//chapa invalida
class chapa_invalida:public invalid_argument {
public:
    chapa_invalida( string mensaje="La chapa introducida no es correcta"):invalid_argument(mensaje){}
};

//marca invalida
class marca_invalida:public invalid_argument {
public:
    marca_invalida( string mensaje="La marca introducida no es correcta"):invalid_argument(mensaje){}
};

//marca invalida
class valor_invalido:public invalid_argument {
public:
    valor_invalido( string mensaje="El valor introducido no es correcto"):invalid_argument(mensaje){}
};

//Excepcion cuando no se abre la base de datos
class data_Base_Not_Open : public runtime_error
{
public:
 data_Base_Not_Open(string info = "Base de datos no abrio")
 : runtime_error(info) {}
};

//Excepcion cuando verifico el dinero de empresa
class modificar_dinero_empresa : public runtime_error
{
public:
 modificar_dinero_empresa(string info = "No se pudo modificar el dinero")
 : runtime_error(info) {}
};

//Excepcion cuando verifico el nombre la empresa
class data_base_nombre_empresa : public runtime_error
{
public:
 data_base_nombre_empresa(string info = "No se pudo acceder al nombre de la empresa")
 : runtime_error(info) {}
};

//Excepcion cuando no se limpia la base de dato
class data_base_borrar : public runtime_error
{
public:
 data_base_borrar(string info = "la base de dato no se pudo borrar")
 : runtime_error(info) {}
};

//Excepcion cuando se modifica la base de dato
class data_base_actualizar : public runtime_error
{
public:
 data_base_actualizar(string info = "no se pudo actualizr la base de dato ")
 : runtime_error(info) {}
};

//exportar dinero de empresa
class data_base_error_acceso : public runtime_error
{
public:
 data_base_error_acceso(string info = "no se pudo acceder a la base de dato ")
 : runtime_error(info) {}
};

//exportar info a vector
class data_base_exportar_vector : public runtime_error
{
public:
 data_base_exportar_vector(string info = "no se pudo de la base de dato al vector")
 : runtime_error(info) {}
};

#endif // MISEXCEPCIONES

