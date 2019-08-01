#ifndef VISUALIZZAOGGETTO_H
#define VISUALIZZAOGGETTO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include "Model/Gerarchia/arma.h"
#include "View/gestioneimg.h"
#include "Model/Gerarchia/arma_da_fuoco.h"
#include "Model/Gerarchia/arma_non_letale.h"
#include "Model/Gerarchia/elettrica.h"
#include "Model/Gerarchia/fucile_a_pompa.h"
#include "Model/Gerarchia/fucile_a_precisione.h"
#include "Model/Gerarchia/pistola.h"
#include "Model/Gerarchia/gas_oc.h"
#include "Model/dptr.h"


class VisualizzaOggetto : public QWidget
{
    Q_OBJECT
private:
    Arma* a;

    QLabel *tipo;
    QLabel *marca;
    QLabel *costo;
    QLabel *nome;
    QLabel *calibro;
    QLabel *cadenza;
    QLabel *voltaggio;
    QLabel *ampereggio;
    QLabel *durataScarica;
    QLabel *distanza;
    QLabel *capacita;
    QLabel *disp;
    QLabel *ric;
    QLabel *torcia;
    QLabel *sil;
    QLabel *automatica;
    QLabel *doppia;
    QLabel *sil2;
    QLabel *mirino;
    QLabel *img;

public:
    VisualizzaOggetto(Arma *, QWidget *parent =nullptr);
    QSize  sizeHint() const;
};

#endif // VISUALIZZAOGGETTO_H
