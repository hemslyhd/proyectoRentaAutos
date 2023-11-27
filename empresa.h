#ifndef EMPRESA_H
#define EMPRESA_H

#include <QDialog>

namespace Ui {
class Empresa;
}

class Empresa : public QDialog
{
    Q_OBJECT

public:
    explicit Empresa(QWidget *parent = 0);
    ~Empresa();

private slots:
    void on_pushButtonContinuar_clicked();

private:
    Ui::Empresa *ui;

};

#endif // EMPRESA_H
