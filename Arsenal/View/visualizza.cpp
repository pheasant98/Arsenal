#include "visualizza.h"

Visualizza::Visualizza(QWidget *parent, LInserisci *i, Ricerca *r) : QWidget(parent), ins(i), ric(r)
{
    QVBoxLayout* MainL=new QVBoxLayout(this);
    QHBoxLayout* BottoniL=new QHBoxLayout();
    bVisualizza= new QPushButton("Visualizza dettagli",this);
    bVisualizza->setToolTip("Selezione una riga e clicca il bottone per visualizzare i dettagli dell'arma selezionata");
    bVisualizza->setToolTipDuration(5000);
    bModifica= new QPushButton("Modifica",this);
    bModifica->setToolTip("Selezione una riga e clicca il bottone per modificare l'arma selezionata");
    bModifica->setToolTipDuration(5000);
    bElimina= new QPushButton("Elimina",this);
    bElimina->setToolTip("Selezione una riga e clicca il bottone per eliminare l'arma selezionata");
    bElimina->setToolTipDuration(5000);
    bCostoTot= new QPushButton("Calcola Costo totale",this);
    BottoniL->addWidget(bVisualizza);
    BottoniL->addWidget(bModifica);
    BottoniL->addWidget(bElimina);
    BottoniL->addWidget(bCostoTot);

    intermedioL= new Qintermedio(this,ric->getRicerca(), ric->getMaggiore());
    model= new QGestioneTabella(this, ins);
    tab=new Tabella(this);
    intermedioL->setSourceModel(model); //imposto cosa deve deve gestire
    tab->setModel(intermedioL);//inserisco il proxy nella tabella

    MainL->addWidget(ric);
    MainL->addWidget(tab, 0, Qt::AlignCenter);
    MainL->addLayout(BottoniL);

    setLayout(MainL);

    connect(bVisualizza, SIGNAL(clicked()), this, SIGNAL(SGMostra()));
    connect(bModifica, SIGNAL(clicked()), this, SIGNAL(SGModifica()));
    connect(bElimina, SIGNAL(clicked()), this, SIGNAL(SGElimina()));
    connect(bCostoTot, SIGNAL(clicked()), this, SIGNAL(SGCostoTot()));
}



Ricerca *Visualizza::getRic() const
{
    return ric;
}

LInserisci *Visualizza::getIns() const
{
    return ins;
}

Qintermedio *Visualizza::getIntermedioL() const
{
    return intermedioL;
}

QGestioneTabella *Visualizza::getModel() const
{
    return model;
}

Tabella *Visualizza::getTab() const
{
    return tab;
}

QPushButton *Visualizza::getbVisualizza() const
{
    return bVisualizza;
}

QPushButton *Visualizza::getbModifica() const
{
    return bModifica;
}

QPushButton *Visualizza::getBElimina() const
{
    return bElimina;
}

QPushButton *Visualizza::getBCostoTot() const
{
    return bCostoTot;
}
