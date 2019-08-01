#include "linserisci.h"

using std::string;
LInserisci::LInserisci(QWidget* i):
    QWidget(i),lmarca(new QLabel("Marca",this)),lcosto(new QLabel("Costo base",this)), lnome(new QLabel("Nome", this)),
    ltipo(new QLabel("Tipo Arma", this)), lcalibro(new QLabel("Calibro", this)), lcadenza(new QLabel("Cadenza di fuoco", this)),
    lcat1(new QLabel("Categoria arma da fuoco", this)), lcat2(new QLabel("Categoria arma non letale", this)),
    lvoltaggio(new QLabel("Voltaggio", this)),lamperaggio(new QLabel("Amperaggio", this)),ldurataScarica(new QLabel("Durata scarica", this)),
    ldistanza(new QLabel("Distanza massima", this)), lcapacita(new QLabel("Capacita", this)), lmirino(new QLabel("Tipo di mirino",this)),
    Sfoto(new QLabel(this)),
    marca(new QLineEdit(this)), costo(new QLineEdit(this)), nome(new QLineEdit(this)), calibro(new QLineEdit(this)),
    cadenza(new QLineEdit(this)), voltaggio(new QLineEdit(this)), ampereggio(new QLineEdit(this)),
    durataScarica(new QLineEdit(this)), distanza(new QLineEdit(this)), capacita(new QLineEdit(this)),
    disp(new QCheckBox("Disponibilita", this)), ricaricabile(new QCheckBox("Ricaricabile", this)),
    torcia(new QCheckBox("Torcia", this)), silenziatore(new QCheckBox("Silenziatore", this)),
    automatica(new QCheckBox("Automatica", this)), doppiaCanna(new QCheckBox("Doppia canna", this)),
    silenziatore2(new QCheckBox("Silenziatore", this)),
    tipo(new comboboxTipo(this)),cat1(new comboboxCat1(this)),cat2(new comboboxCat2(this)),
    mirino(new comboboxMirino(this)),
    bimg(new QPushButton("Cambia mmagine", this)),binserisci(new QPushButton("Inserisci", this)),breset(new QPushButton("Reset", this))
{
    QVBoxLayout *MainForm= new QVBoxLayout(this);
    QHBoxLayout *SubForm= new QHBoxLayout();
    QVBoxLayout *SXForm= new QVBoxLayout();
    QVBoxLayout *DXForm= new QVBoxLayout();
    QHBoxLayout *form1= new QHBoxLayout();
    QHBoxLayout *form2= new QHBoxLayout();
    QHBoxLayout *form3= new QHBoxLayout();
    QHBoxLayout *form4= new QHBoxLayout();
    QHBoxLayout *form5= new QHBoxLayout();
    QHBoxLayout *form6= new QHBoxLayout();
    QHBoxLayout *form7= new QHBoxLayout();
    QHBoxLayout *form8= new QHBoxLayout();
    QHBoxLayout *form9= new QHBoxLayout();
    QHBoxLayout *form10= new QHBoxLayout();
    QHBoxLayout *form11= new QHBoxLayout();
    QHBoxLayout *form12= new QHBoxLayout();
    QHBoxLayout *form13= new QHBoxLayout();
    QHBoxLayout *form14= new QHBoxLayout();

    form1->addWidget(lmarca);
    form1->addWidget(marca);
    form2->addWidget(lcosto);
    costo->setPlaceholderText("€");
    costo->setValidator(new QDoubleValidator(100,1,5,this));
    form2->addWidget(costo);
    form3->addWidget(lnome);
    form3->addWidget(nome);
    
    form4->addWidget(disp);

    QPixmap pix(":/img_non_disponibile.jpg");
    Sfoto->setPixmap(pix);
    DXForm->addWidget(Sfoto);
    DXForm->addWidget(bimg);

    form5->addWidget(ltipo);
    form5->addWidget(tipo);
    form5->addWidget(lcat1);
    form5->addWidget(cat1);
    form5->addWidget(lcat2);
    form5->addWidget(cat2);
    
    form6->addWidget(lcalibro);
    calibro->setPlaceholderText("mm");
    calibro->setValidator(new QDoubleValidator(100,1,5,this));
    form6->addWidget(calibro);
    form7->addWidget(lcadenza);
    cadenza->setPlaceholderText("per minuto");
    cadenza->setValidator(new QDoubleValidator(100,1,5,this));
    form7->addWidget(cadenza);
     
    form8->addWidget(ricaricabile);

    form9->addWidget(torcia);
    form9->addWidget(silenziatore);
    form9->addWidget(automatica);

    form9->addWidget(doppiaCanna);

    form9->addWidget(silenziatore2);
    form9->addWidget(lmirino);
    form9->addWidget(mirino);


    form10->addWidget(lvoltaggio);
    voltaggio->setPlaceholderText("V");
    voltaggio->setValidator(new QDoubleValidator(100,1,5,this));
    form10->addWidget(voltaggio);
    form11->addWidget(lamperaggio);
    ampereggio->setPlaceholderText("A");
    ampereggio->setValidator(new QDoubleValidator(100,1,5,this));
    form11->addWidget(ampereggio);
    form12->addWidget(ldurataScarica);
    durataScarica->setPlaceholderText("sec");
    durataScarica->setValidator(new QDoubleValidator(100,1,5,this));
    form12->addWidget(durataScarica);
    form13->addWidget(ldistanza);
    distanza->setPlaceholderText("m");
    distanza->setValidator(new QDoubleValidator(100,1,5,this));
    form13->addWidget(distanza);
    
    form10->addWidget(lcapacita);
    capacita->setPlaceholderText("ml");
    capacita->setValidator(new QDoubleValidator(100,1,5,this));
    form10->addWidget(capacita);
    
    form14->addWidget(binserisci);
    form14->addWidget(breset);

    SXForm->addLayout(form1);
    SXForm->addLayout(form2);
    SXForm->addLayout(form3);
    SXForm->addLayout(form4);
    SXForm->addLayout(form5);
    SXForm->addLayout(form6);
    SXForm->addLayout(form7);
    SXForm->addLayout(form8);
    SXForm->addLayout(form9);
    SXForm->addLayout(form10);
    SXForm->addLayout(form11);
    SXForm->addLayout(form12);
    SXForm->addLayout(form13);

    SubForm->addLayout(SXForm);
    SubForm->addLayout(DXForm);

    MainForm->addLayout(SubForm);
    MainForm->addLayout(form14);

    setLayout(MainForm);

    SVisible(0);
    connect(tipo,SIGNAL(activated(int)),this,SLOT(SVisible(int)));
    connect(cat1,SIGNAL(activated(int)),this,SLOT(SVisible2(int)));
    connect(cat2,SIGNAL(activated(int)),this,SLOT(SVisible3(int)));
    connect(bimg,SIGNAL(clicked()), this, SLOT(SImg()));
    connect(breset,SIGNAL(clicked()),this,SLOT(SReset()));
    connect(binserisci, SIGNAL(clicked()), this, SIGNAL(SGInserisci()));
    connect(binserisci, SIGNAL(clicked()), this, SLOT(SReset()));

}



QLineEdit *LInserisci::getMarca() const
{
    return marca;
}

QLineEdit *LInserisci::getCosto() const
{
    return costo;
}

QLineEdit *LInserisci::getNome() const
{
    return nome;
}

string LInserisci::getTipo() const
{
    return tipo->currentText().toStdString();
}

string LInserisci::getCat1() const
{
    return cat1->currentText().toStdString();
}

string LInserisci::getCat2() const
{
    return cat2->currentText().toStdString();
}

QLineEdit *LInserisci::getCalibro() const
{
    return calibro;
}

QLineEdit *LInserisci::getCadenza() const
{
    return cadenza;
}

bool LInserisci::getRicaricabile() const
{
    return ricaricabile->isChecked();
}

bool LInserisci::getTorcia() const
{
    return torcia->isChecked();
}

bool LInserisci::getSilenziatore() const
{
    return silenziatore->isChecked();
}

bool LInserisci::getSilenziatore2() const
{
    return silenziatore2->isChecked();
}

bool LInserisci::getAutomatica() const
{
    return automatica->isChecked();
}

bool LInserisci::getDoppiaCanna() const
{
   return doppiaCanna->isChecked();
}

string LInserisci::getMirino() const
{
    return mirino->currentText().toStdString();
}

QLineEdit *LInserisci::getVoltaggio() const
{
    return voltaggio;
}

QLineEdit *LInserisci::getAmperaggio() const
{
    return ampereggio;
}

QLineEdit *LInserisci::getDurata() const
{
    return durataScarica;
}

QLineEdit *LInserisci::getDistanza() const
{
    return distanza;
}

QLineEdit *LInserisci::getCapacita() const
{
    return capacita;
}

QPushButton *LInserisci::getBImg() const
{
    return bimg;
}

QPushButton *LInserisci::getBInserisci() const
{
    return binserisci;
}

QPushButton *LInserisci::getBReset() const
{
    return breset;
}

bool LInserisci::getDisp() const
{
    return disp->isChecked();
}

QLabel *LInserisci::getSFoto() const
{
    return Sfoto;
}

void LInserisci::SReset() const//SLOT che pulisce i campi
{
    marca->setText("");
    costo->setText("");
    nome->setText("");
    disp->setChecked(false);
    calibro->setText("");
    cadenza->setText("");
    voltaggio->setText("");
    ampereggio->setText("");
    durataScarica->setText("");
    distanza->setText("");
    capacita->setText("");
    ricaricabile->setChecked(false);
    torcia->setChecked(false);
    silenziatore->setChecked(false);
    silenziatore2->setChecked(false);
    automatica->setChecked(false);
    doppiaCanna->setChecked(false);
    QPixmap pix(":/img_non_disponibile.jpg");
    Sfoto->setPixmap(pix);
    tipo->setCurrentIndex(0);
    cat1->setCurrentIndex(0);
    cat2->setCurrentIndex(0);
    mirino->setCurrentIndex(0);
    SVisible(0);
}

void LInserisci::SVisible(int i) const //imposta quali componenti grafici mostrare per arma da fuoco e per arma non letale
{
    switch (i) {
    case 0://inizio

        cat1->setEnabled(false);
        cat2->setEnabled(false);
        lcalibro->setVisible(false);
        calibro->setVisible(false);
        lcadenza->setVisible(false);
        cadenza->setVisible(false);
        lvoltaggio->setVisible(false);
        voltaggio->setVisible(false);
        lamperaggio->setVisible(false);
        ampereggio->setVisible(false);
        ldurataScarica->setVisible(false);
        durataScarica->setVisible(false);
        ldistanza->setVisible(false);
        distanza->setVisible(false);
        lcapacita->setVisible(false);
        capacita->setVisible(false);
        ricaricabile->setVisible(false);
        torcia->setVisible(false);
        silenziatore->setVisible(false);
        silenziatore2->setVisible(false);
        automatica->setVisible(false);
        doppiaCanna->setVisible(false);
        lmirino->setVisible(false);
        mirino->setVisible(false);

        break;
    case 1://scelto arma da fuoco

        cat1->setEnabled(true);
        cat2->setEnabled(false);
        cat2->setCurrentIndex(0);
        lcalibro->setVisible(true);
        calibro->setVisible(true);
        lcadenza->setVisible(true);
        cadenza->setVisible(true);
        lvoltaggio->setVisible(false);
        voltaggio->setVisible(false);
        lamperaggio->setVisible(false);
        ampereggio->setVisible(false);
        ldurataScarica->setVisible(false);
        durataScarica->setVisible(false);
        ldistanza->setVisible(false);
        distanza->setVisible(false);
        lcapacita->setVisible(false);
        capacita->setVisible(false);
        ricaricabile->setVisible(false);
        torcia->setVisible(false);
        silenziatore->setVisible(false);
        silenziatore2->setVisible(false);
        automatica->setVisible(false);
        doppiaCanna->setVisible(false);
        lmirino->setVisible(false);
        mirino->setVisible(false);
        break;
    case 2://scelto arma non letale

        cat1->setEnabled(false);
        cat2->setEnabled(true);
        cat1->setCurrentIndex(0);
        lcalibro->setVisible(false);
        calibro->setVisible(false);
        lcadenza->setVisible(false);
        cadenza->setVisible(false);
        lvoltaggio->setVisible(false);
        voltaggio->setVisible(false);
        lamperaggio->setVisible(false);
        ampereggio->setVisible(false);
        ldurataScarica->setVisible(false);
        durataScarica->setVisible(false);
        ldistanza->setVisible(false);
        distanza->setVisible(false);
        lcapacita->setVisible(false);
        capacita->setVisible(false);
        ricaricabile->setVisible(true);
        torcia->setVisible(false);
        silenziatore->setVisible(false);
        silenziatore2->setVisible(false);
        automatica->setVisible(false);
        doppiaCanna->setVisible(false);
        lmirino->setVisible(false);
        mirino->setVisible(false);

        break;
    }
}

void LInserisci::SVisible2(int i) const //classi arma da fuoco
{
    switch (i)
    {
    case 0://inizio

        cat1->setEnabled(false);
        cat2->setEnabled(false);
        lcalibro->setVisible(false);
        calibro->setVisible(false);
        lcadenza->setVisible(false);
        cadenza->setVisible(false);
        lvoltaggio->setVisible(false);
        voltaggio->setVisible(false);
        lamperaggio->setVisible(false);
        ampereggio->setVisible(false);
        ldurataScarica->setVisible(false);
        durataScarica->setVisible(false);
        ldistanza->setVisible(false);
        distanza->setVisible(false);
        lcapacita->setVisible(false);
        capacita->setVisible(false);
        ricaricabile->setVisible(false);
        torcia->setVisible(false);
        silenziatore->setVisible(false);
        silenziatore2->setVisible(false);
        automatica->setVisible(false);
        doppiaCanna->setVisible(false);
        lmirino->setVisible(false);
        mirino->setVisible(false);

        break;
    case 1://scelto pistola

        cat1->setEnabled(true);
        cat2->setEnabled(false);
        lcalibro->setVisible(true);
        calibro->setVisible(true);
        lcadenza->setVisible(true);
        cadenza->setVisible(true);
        lvoltaggio->setVisible(false);
        voltaggio->setVisible(false);
        lamperaggio->setVisible(false);
        ampereggio->setVisible(false);
        ldurataScarica->setVisible(false);
        durataScarica->setVisible(false);
        ldistanza->setVisible(false);
        distanza->setVisible(false);
        lcapacita->setVisible(false);
        capacita->setVisible(false);
        ricaricabile->setVisible(false);
        torcia->setVisible(true);
        silenziatore->setVisible(true);
        silenziatore2->setVisible(false);
        automatica->setVisible(true);
        doppiaCanna->setVisible(false);
        lmirino->setVisible(false);
        mirino->setVisible(false);
        break;
    case 2://scelto fucile a pompa

        cat1->setEnabled(true);
        cat2->setEnabled(false);
        lcalibro->setVisible(true);
        calibro->setVisible(true);
        lcadenza->setVisible(true);
        cadenza->setVisible(true);
        lvoltaggio->setVisible(false);
        voltaggio->setVisible(false);
        lamperaggio->setVisible(false);
        ampereggio->setVisible(false);
        ldurataScarica->setVisible(false);
        durataScarica->setVisible(false);
        ldistanza->setVisible(false);
        distanza->setVisible(false);
        lcapacita->setVisible(false);
        capacita->setVisible(false);
        ricaricabile->setVisible(false);
        torcia->setVisible(false);
        silenziatore->setVisible(false);
        silenziatore2->setVisible(false);
        automatica->setVisible(false);
        doppiaCanna->setVisible(true);
        lmirino->setVisible(false);
        mirino->setVisible(false);
        break;
    case 3://scelto fucile a precisione

        cat1->setEnabled(true);
        cat2->setEnabled(false);
        lcalibro->setVisible(true);
        calibro->setVisible(true);
        lcadenza->setVisible(true);
        cadenza->setVisible(true);
        lvoltaggio->setVisible(false);
        voltaggio->setVisible(false);
        lamperaggio->setVisible(false);
        ampereggio->setVisible(false);
        ldurataScarica->setVisible(false);
        durataScarica->setVisible(false);
        ldistanza->setVisible(false);
        distanza->setVisible(false);
        lcapacita->setVisible(false);
        capacita->setVisible(false);
        ricaricabile->setVisible(false);
        torcia->setVisible(false);
        silenziatore->setVisible(false);
        silenziatore2->setVisible(true);
        automatica->setVisible(false);
        doppiaCanna->setVisible(false);
        lmirino->setVisible(true);
        mirino->setVisible(true);
        break;
     }
}

void LInserisci::SVisible3(int i) const //classi arma non letale
{
    switch (i) {
    case 0://inizio

        cat1->setEnabled(false);
        cat2->setEnabled(false);
        lcalibro->setVisible(false);
        calibro->setVisible(false);
        lcadenza->setVisible(false);
        cadenza->setVisible(false);
        lvoltaggio->setVisible(false);
        voltaggio->setVisible(false);
        lamperaggio->setVisible(false);
        ampereggio->setVisible(false);
        ldurataScarica->setVisible(false);
        durataScarica->setVisible(false);
        ldistanza->setVisible(false);
        distanza->setVisible(false);
        lcapacita->setVisible(false);
        capacita->setVisible(false);
        ricaricabile->setVisible(false);
        torcia->setVisible(false);
        silenziatore->setVisible(false);
        silenziatore2->setVisible(false);
        automatica->setVisible(false);
        doppiaCanna->setVisible(false);
        lmirino->setVisible(false);
        mirino->setVisible(false);

        break;

    case 1://elettrica

        cat1->setEnabled(false);
        cat2->setEnabled(true);
        lcalibro->setVisible(false);
        calibro->setVisible(false);
        lcadenza->setVisible(false);
        cadenza->setVisible(false);
        lvoltaggio->setVisible(true);
        voltaggio->setVisible(true);
        lamperaggio->setVisible(true);
        ampereggio->setVisible(true);
        ldurataScarica->setVisible(true);
        durataScarica->setVisible(true);
        ldistanza->setVisible(true);
        distanza->setVisible(true);
        lcapacita->setVisible(false);
        capacita->setVisible(false);
        ricaricabile->setVisible(true);
        torcia->setVisible(false);
        silenziatore->setVisible(false);
        silenziatore2->setVisible(false);
        automatica->setVisible(false);
        doppiaCanna->setVisible(false);
        lmirino->setVisible(false);
        mirino->setVisible(false);
       break;
    case 2://gas_oc

        cat1->setEnabled(false);
        cat2->setEnabled(true);
        lcalibro->setVisible(false);
        calibro->setVisible(false);
        lcadenza->setVisible(false);
        cadenza->setVisible(false);
        lvoltaggio->setVisible(false);
        voltaggio->setVisible(false);
        lamperaggio->setVisible(false);
        ampereggio->setVisible(false);
        ldurataScarica->setVisible(false);
        durataScarica->setVisible(false);
        ldistanza->setVisible(false);
        distanza->setVisible(false);
        lcapacita->setVisible(true);
        capacita->setVisible(true);
        ricaricabile->setVisible(true);
        torcia->setVisible(false);
        silenziatore->setVisible(false);
        silenziatore2->setVisible(false);
        automatica->setVisible(false);
        doppiaCanna->setVisible(false);
        lmirino->setVisible(false);
        mirino->setVisible(false);

       break;
    }
}

void LInserisci::SImg() //gestione dell'inserimento di una img
{
    QString file= QFileDialog::getOpenFileName(this,tr("Inserisci immagine"),"../progetto/.","Image file (*.jpg *.png *.jpeg) ");//chiedo all'utente l'img
    QFileInfo relativePath(file);

    if(file!="")// se carica qualcosa lo inserisco
    {
        QImage img(file);
        QByteArray  ba;
        QBuffer b(&ba);
        img.save(&b,"JPG");
        Sfoto->setPixmap(QPixmap::fromImage(img)); //inserisco l'img
    }           
}


