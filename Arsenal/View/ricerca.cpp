#include "ricerca.h"

Ricerca::Ricerca(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout* RicercaL=new QHBoxLayout();
    Barradiricerca= new QLineEdit(this);
    Barradiricerca->setPlaceholderText("Ricerca");
    ricerca= new comboboxRicerca(this);
    Vero= new QCheckBox("Vero", this);
    Falso= new QCheckBox("Falso", this);
    Vero->setChecked(true);
    QButtonGroup *vf=new QButtonGroup(this);
    vf->addButton(Vero);
    vf->addButton(Falso);
    Maggiore= new QCheckBox(">=", this);
    Minore= new QCheckBox("<=", this);
    Maggiore->setChecked(true);
    QButtonGroup *Mm=new QButtonGroup(this);
    Mm->addButton(Maggiore);
    Mm->addButton(Minore);
    bPulisciRicerca= new QPushButton("Reset",this);
    bOrdinaAsc= new QPushButton("Ordina ↓", this);
    bOrdinaAsc->setToolTip("Seleziona secondo quale colonna vuoi ordinare e clicca il bottone per ordinare in modo ascedente");
    bOrdinaAsc->setToolTipDuration(5000);
    bOrdinaDesc= new QPushButton("Ordina ↑", this);
    bOrdinaDesc->setToolTip("Seleziona secondo quale colonna vuoi ordinare e clicca il bottone per ordinare in modo discedente");
    bOrdinaDesc->setToolTipDuration(5000);
    Mirino=new comboboxMirino(this);
    RicercaL->addWidget(bOrdinaAsc);
    RicercaL->addWidget(bOrdinaDesc);
    RicercaL->addWidget(Barradiricerca);
    RicercaL->addWidget(Vero);
    RicercaL->addWidget(Falso);
    RicercaL->addWidget(Maggiore);
    RicercaL->addWidget(Minore);
    RicercaL->addWidget(Mirino);
    RicercaL->addWidget(ricerca);
    RicercaL->addWidget(bPulisciRicerca);

    Vero->setVisible(false);
    Falso->setVisible(false);
    Maggiore->setVisible(false);
    Minore->setVisible(false);
    Mirino->setVisible(false);

    setLayout(RicercaL);

    connect(Barradiricerca, SIGNAL(textChanged(const QString&)), this, SIGNAL(SGRicerca()));//per la ricerca di stringhe e numeri
    connect(Vero, SIGNAL(stateChanged(int)), this, SIGNAL(SGRicerca())); //per la ricerca di bool
    connect(ricerca,SIGNAL(activated(int)),this,SLOT(SVisible(int)));//imposta la grafica per la ricerca
    connect(ricerca, SIGNAL(currentTextChanged(const QString&)), this, SIGNAL(SGRicerca()));//invia il segnale di effettuare la ricerca che viene gestito dal MainWindow
    connect(Mirino, SIGNAL(activated(int)), this, SIGNAL(SGRicerca()));
    connect(Maggiore, SIGNAL(stateChanged(int)), this, SIGNAL(SGRicerca()));//per la ricerca di valori maggiore
    connect(bPulisciRicerca, SIGNAL(clicked()), Barradiricerca, SLOT(clear()));
    connect(bOrdinaAsc, SIGNAL(clicked()), this, SIGNAL(SGOrdinaAsc()));//ordina gestita dal MainWindow, ordinamento ascendente
    connect(bOrdinaDesc, SIGNAL(clicked()), this, SIGNAL(SGOrdinaDesc()));//ordina gestita dal MainWindow, ordinamento discendente
}
void Ricerca::SVisible(int i)
{
    switch (i)
    {
    case 0://marca
        Barradiricerca->setVisible(true);
        Vero->setVisible(false);
        Falso->setVisible(false);
        Maggiore->setVisible(false);
        Minore->setVisible(false);
        Mirino->setVisible(false);
        break;
    case 1://costo
        Barradiricerca->setVisible(true);
        Vero->setVisible(false);
        Falso->setVisible(false);
        Maggiore->setVisible(true);
        Minore->setVisible(true);
        Mirino->setVisible(false);
        break;
    case 2://nome
        Barradiricerca->setVisible(true);
        Vero->setVisible(false);
        Falso->setVisible(false);
        Maggiore->setVisible(false);
        Minore->setVisible(false);
        Mirino->setVisible(false);
        break;
    case 3://disponibilita
        Barradiricerca->setVisible(false);
        Vero->setVisible(true);
        Falso->setVisible(true);
        Maggiore->setVisible(false);
        Minore->setVisible(false);
        Mirino->setVisible(false);
        break;
    case 4://classe
        Barradiricerca->setVisible(true);
        Vero->setVisible(false);
        Falso->setVisible(false);
        Maggiore->setVisible(false);
        Minore->setVisible(false);
        Mirino->setVisible(false);
        break;
    case 5://calibro
        Barradiricerca->setVisible(true);
        Vero->setVisible(false);
        Falso->setVisible(false);
        Maggiore->setVisible(true);
        Minore->setVisible(true);
        Mirino->setVisible(false);
        break;
    case 6://cadenza
        Barradiricerca->setVisible(true);
        Vero->setVisible(false);
        Falso->setVisible(false);
        Maggiore->setVisible(true);
        Minore->setVisible(true);
        Mirino->setVisible(false);
        break;
    case 7://ricaricabile
        Barradiricerca->setVisible(false);
        Vero->setVisible(true);
        Falso->setVisible(true);
        Maggiore->setVisible(false);
        Minore->setVisible(false);
        Mirino->setVisible(false);
        break;
    case 8://torcia
        Barradiricerca->setVisible(false);
        Vero->setVisible(true);
        Falso->setVisible(true);
        Maggiore->setVisible(false);
        Minore->setVisible(false);
        Mirino->setVisible(false);
        break;
    case 9://silenziatore
        Barradiricerca->setVisible(false);
        Vero->setVisible(true);
        Falso->setVisible(true);
        Maggiore->setVisible(false);
        Minore->setVisible(false);
        Mirino->setVisible(false);
        break;
    case 10://automatica
        Barradiricerca->setVisible(false);
        Vero->setVisible(true);
        Falso->setVisible(true);
        Maggiore->setVisible(false);
        Minore->setVisible(false);
        break;
    case 11://doppia canna
        Barradiricerca->setVisible(false);
        Vero->setVisible(true);
        Falso->setVisible(true);
        Maggiore->setVisible(false);
        Minore->setVisible(false);
        Mirino->setVisible(false);
        break;
    case 12:  //mirino
        Barradiricerca->setVisible(false);
        Vero->setVisible(false);
        Falso->setVisible(false);
        Maggiore->setVisible(false);
        Minore->setVisible(false);
        Mirino->setVisible(true);
        break;
    case 13:// voltaggio
        Barradiricerca->setVisible(true);
        Vero->setVisible(false);
        Falso->setVisible(false);
        Maggiore->setVisible(true);
        Minore->setVisible(true);
        Mirino->setVisible(false);
        break;
    case 14://amperaggio
        Barradiricerca->setVisible(true);
        Vero->setVisible(false);
        Falso->setVisible(false);
        Maggiore->setVisible(true);
        Minore->setVisible(true);
        Mirino->setVisible(false);
        break;
    case 15://durata scarica
        Barradiricerca->setVisible(true);
        Vero->setVisible(false);
        Falso->setVisible(false);
        Maggiore->setVisible(true);
        Minore->setVisible(true);
        Mirino->setVisible(false);
        break;
    case 16://distanza max
        Barradiricerca->setVisible(true);
        Vero->setVisible(false);
        Falso->setVisible(false);
        Maggiore->setVisible(true);
        Minore->setVisible(true);
        Mirino->setVisible(false);
        break;
    case 17://capacita
        Barradiricerca->setVisible(true);
        Vero->setVisible(false);
        Falso->setVisible(false);
        Maggiore->setVisible(true);
        Minore->setVisible(true);
        Mirino->setVisible(false);
        break;
    }
}

comboboxMirino *Ricerca::getMirino() const
{
    return Mirino;
}

QLineEdit *Ricerca::getBarradiricerca() const
{
    return Barradiricerca;
}

QCheckBox *Ricerca::getVero() const
{
    return Vero;
}

QCheckBox *Ricerca::getFalso() const
{
    return Falso;
}

QCheckBox *Ricerca::getMaggiore() const
{
    return Maggiore;
}

QCheckBox *Ricerca::getMinore() const
{
    return Minore;
}

QPushButton *Ricerca::getBPulisciRicerca() const
{
    return bPulisciRicerca;
}

comboboxRicerca *Ricerca::getRicerca() const
{
    return ricerca;
}

QPushButton *Ricerca::getBOrdinaAsc() const
{
    return bOrdinaAsc;
}

QPushButton *Ricerca::getBOrdinaDesc() const
{
    return bOrdinaDesc;
}
