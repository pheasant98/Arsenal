#-------------------------------------------------
#
# Project created by QtCreator 2019-02-10T14:40:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Arsenal
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    Model/model.cpp \
    Model/Gerarchia/arma.cpp \
    Model/Gerarchia/arma_da_fuoco.cpp \
    Model/Gerarchia/arma_non_letale.cpp \
    Model/Gerarchia/pistola.cpp \
    Model/Gerarchia/fucile_a_pompa.cpp \
    Model/Gerarchia/fucile_a_precisione.cpp \
    Model/Gerarchia/elettrica.cpp \
    Model/Gerarchia/gas_oc.cpp \
    View/comboboxtipo.cpp \
    View/comboboxcat1.cpp \
    View/comboboxcat2.cpp \
    View/comboboxmirino.cpp \
    View/linserisci.cpp \
    View/menu.cpp \
    View/mainwindow.cpp \
    View/visualizzaoggetto.cpp \
    View/tabella.cpp \
    View/comboboxricerca.cpp \
    Model/qintermedio.cpp \
    View/modifica.cpp \
    Model/qgestionetabella.cpp \
    View/ricerca.cpp \
    View/visualizza.cpp \
    Model/xmlio.cpp \
    View/gestioneimg.cpp

HEADERS += \
    Model/model.h \
    Model/Gerarchia/arma.h \
    Model/dptr.h \
    Model/Gerarchia/arma_da_fuoco.h \
    Model/Gerarchia/arma_non_letale.h \
    Model/Gerarchia/pistola.h \
    Model/Gerarchia/fucile_a_pompa.h \
    Model/Gerarchia/fucile_a_precisione.h \
    Model/Gerarchia/elettrica.h \
    Model/Gerarchia/gas_oc.h \
    Model/qontainer.h \
    View/comboboxtipo.h \
    View/comboboxcat1.h \
    View/comboboxcat2.h \
    View/comboboxmirino.h \
    View/linserisci.h \
    View/menu.h \
    View/mainwindow.h \
    View/visualizzaoggetto.h \
    View/tabella.h \
    View/comboboxricerca.h \
    Model/qintermedio.h \
    View/modifica.h \
    Model/qgestionetabella.h \
    View/ricerca.h \
    View/visualizza.h \
    Model/xmlio.h \
    View/gestioneimg.h

FORMS +=

RESOURCES += \
    resource.qrc

DISTFILES +=
