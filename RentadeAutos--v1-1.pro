#-------------------------------------------------
#
# Project created by QtCreator 2023-11-10T19:48:27
#
#-------------------------------------------------

QT       += core gui sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RentadeAutos--v1-1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    renta.cpp \
    auto.cpp \
    bienvenida.cpp \
    controlador.cpp \
    nosotros.cpp

HEADERS  += mainwindow.h \
    renta.h \
    auto.h \
    bienvenida.h \
    controlador.h \
    misexcepciones.h \
    nosotros.h

FORMS    += mainwindow.ui \
    bienvenida.ui \
    nosotros.ui

RESOURCES += \
    imagen.qrc

DISTFILES += \
    imagenes/Alugando um carro para ter uma renda extra_.jpg \
    imagenes/Buying A Car Clipart Transparent Background, Car Seller Deals Buying And Sale Flat Illustration, Flat, Design, Illustrations PNG Image For Free Download.jpg \
    imagenes/Cambio o compra de carro, pago de dinero por compra _ Vector Premium.jpg \
    imagenes/207c670d4d429105749f0c2df7832a39 (1).png \
    imagenes/378e87745b5a89d6e8c0fee1ff38c025.jpg \
    imagenes/458bd8685e81196031824521470f2ba5.jpg \
    imagenes/eb719c24c9b428adb9a1df9f4a3ad640.jpg \
    imagenes/207c670d4d429105749f0c2df7832a39 (1).png

QMAKE_CXXFLAGS += -std=gnu++14
