#ifndef BIENVENIDA_H
#define BIENVENIDA_H
#include<controlador.h>
#include <QDialog>
#include<renta.h>
#include<qmessagebox.h>
#include<QString>
namespace Ui {
class Bienvenida;
}

class Bienvenida : public QDialog
{
    Q_OBJECT

public:
    explicit Bienvenida(Renta &empresa, Controlador & controlador,QWidget *parent = nullptr);
    ~Bienvenida();
    //QVector<Renta>registro;

private slots:
    void on_pushButtonEntrar_clicked();

    void on_pushButtonCerrar_clicked();

private:
    Ui::Bienvenida *ui;
    Controlador &controladorPantallaBienvenida;
    //QVector<Renta> &empresa;
    Renta &empresa;


};

#endif // BIENVENIDA_H
