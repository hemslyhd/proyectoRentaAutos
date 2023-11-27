#ifndef NOSOTROS_H
#define NOSOTROS_H

#include <QDialog>

namespace Ui {
class Nosotros;
}

class Nosotros : public QDialog
{
    Q_OBJECT

public:
    explicit Nosotros(QWidget *parent = 0);
    ~Nosotros();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Nosotros *ui;
};

#endif // NOSOTROS_H
