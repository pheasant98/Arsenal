#ifndef MODIFICA_H
#define MODIFICA_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QModelIndex>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "Model/Gerarchia/arma.h"
#include "View/gestioneimg.h"
#include "Model/Gerarchia/arma_da_fuoco.h"
#include "Model/Gerarchia/arma_non_letale.h"
#include "Model/Gerarchia/elettrica.h"
#include "Model/Gerarchia/fucile_a_pompa.h"
#include "Model/Gerarchia/fucile_a_precisione.h"
#include "Model/Gerarchia/pistola.h"
#include "Model/Gerarchia/gas_oc.h"
#include <QGridLayout>
#include <iostream>
#include <QMessageBox>


class Modifica : public QWidget
{
    Q_OBJECT
private:
    Arma* a;
    const QModelIndex inizio;
    const QModelIndex fine;

    QLabel *ltipo;

    QLineEdit *marca;
    QLineEdit *costo;
    QLineEdit *nome;
    QLineEdit *calibro;
    QLineEdit *cadenza;
    QLineEdit *voltaggio;
    QLineEdit *ampereggio;
    QLineEdit *durataScarica;
    QLineEdit *distanza;
    QLineEdit *capacita;
    QLineEdit *disp;
    QLineEdit *ric;
    QLineEdit *torcia;
    QLineEdit *sil;
    QLineEdit *automatica;
    QLineEdit *doppia;
    QLineEdit *sil2;
    QLineEdit *mirino;
    QLabel *img;
    QPushButton *bimg;
public:
    Modifica(Arma *, const QModelIndex& , const QModelIndex& , QWidget *parent =nullptr);
signals:
    void SGCambia(const QModelIndex&, const QModelIndex&);
private slots:
    void SSalvaImpostazioni();
    void SCambiaFoto();

};

#endif // MODIFICA_H
