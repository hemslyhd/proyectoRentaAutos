#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QMessageBox>
#include<QStringList>
#include<bienvenida.h>
#include<nosotros.h>
#include<auto.h>
#include<renta.h>
#include<controlador.h>
#include<math.h>
#include<misexcepciones.h>
#include<QString>
#include <QSqlDatabase>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //Orddenar por la cantidad de dias rentados
     void ordenarCantDias( QVector<Auto>& lista);
     void ordenarCantKm(QVector<Auto>& lista);
     void separarDatos(QString,QString &,QString &,QString &);

private slots:


    void on_pushButtonAgregar_clicked();





    void on_pushButtonRentar_clicked();



    void on_pushButtonMostrar_clicked();


    void on_pushButtonRecibir_clicked();

    void on_actionBorrar_datos_del_sistema_triggered();

    void on_radioButtonSacarMantenimiento_clicked();

    void on_radioButtonMandarMantenimiento_clicked();

    void on_radioButtonDarBaja_clicked();

    void on_pushButtonAceptarMantenimiento_clicked();

    void on_tabWidget_tabBarClicked(int index);



    void on_actionQuienes_Somos_triggered();

private:
      Ui::MainWindow *ui;
      //Bienvenida *pantallaBienvenida = new Bienvenida(this);
      QVector<Auto>listado;

      Controlador  controlador;
      //QVector<Renta> empresa;
      Renta empresa;
      Bienvenida  *pantallaBienvenida = new Bienvenida (empresa,controlador,this);

      Nosotros *pantallaNosotros= new Nosotros(this);

      QString nombreEmpresa;
      long long dineroEmpresa;
      int contador=0;



};


#endif // MAINWINDOW_H
