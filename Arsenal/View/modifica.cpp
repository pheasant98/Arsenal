#include "modifica.h"
#include <QValidator>
using std::cout;

Modifica::Modifica(Arma *arma1, const QModelIndex &i, const QModelIndex &f, QWidget *parent ): QWidget(parent),
  a(arma1), inizio(i), fine(f)
{
    //All'inizio carico i dati nelle qlineEdit per mostarli all'utente
    QVBoxLayout* Mainform = new QVBoxLayout(this);

    QHBoxLayout* tipoform = new QHBoxLayout();
    tipoform->addWidget(new QLabel("Classe ",this));
    tipoform->addWidget(ltipo = new QLabel(QString::fromStdString(a->classe()), this));

    QGridLayout* infoform = new QGridLayout();
    infoform->addWidget(new QLabel("Marca ", this));
    infoform->addWidget(marca= new QLineEdit(QString::fromStdString(a->getMarca()), this));
    infoform->addWidget(new QLabel("Costo Base ", this));
    infoform->addWidget(costo= new QLineEdit(QString::fromStdString(std::to_string(a->getCosto())).replace(QRegExp(","), "."), this));
    costo->setValidator(new QDoubleValidator(100,1,5,this));
    infoform->addWidget(new QLabel("Nome ", this));
    infoform->addWidget(nome= new QLineEdit(QString::fromStdString(a->getNome()), this));
    infoform->addWidget(new QLabel("Disponibilita ", this));
    if(a->getDisponibilita())
    {
        infoform->addWidget(disp= new QLineEdit(QString::fromStdString("true"), this));
    }
    else
    {
        infoform->addWidget(disp= new QLineEdit(QString::fromStdString("false"), this));
    }
    QHBoxLayout* imgform = new QHBoxLayout();
    img=new QLabel(this);
    img->setPixmap(GestioneImg::getImg(a->getFoto()));//inserisco l'immagine salvata, l'immagine e salvata sotto forma di stringa, la trasformo in img e la carico
    imgform->addWidget(img);
    imgform->addWidget(bimg= new QPushButton("Cambia Foto", this));

    Mainform->addLayout(tipoform);
    Mainform->addLayout(infoform);
    Mainform->addLayout(imgform);

    if(a->Armadafuoco())
    {
        QHBoxLayout* infoform2 = new QHBoxLayout();
        infoform2->addWidget(new QLabel("Calibro ", this));
        std::cout<<"calibro"<<static_cast<Arma_da_fuoco*>(a)->getCalibro()<<std::endl;
        calibro=new QLineEdit(QString::fromStdString(std::to_string(static_cast<Arma_da_fuoco*>(a)->getCalibro())).replace(QRegExp(","), "."), this);
        calibro->setValidator(new QDoubleValidator(100,1,5,this));
        infoform2->addWidget(calibro);
        infoform2->addWidget(new QLabel("Cadenza di fuoco ", this));
        infoform2->addWidget(cadenza= new QLineEdit(QString::fromStdString(std::to_string(static_cast<Arma_da_fuoco*>(a)->getCad())), this));
        cadenza->setValidator(new QDoubleValidator(100,1,5,this));
        Mainform->addLayout(infoform2);
        if(a->classe()=="Pistola")
        {
            QGridLayout* infoform4 = new QGridLayout();
            infoform4->addWidget(new QLabel("Torcia ", this));
            if(static_cast<Pistola*>(a)->getTorcia())
            {
                infoform4->addWidget(torcia= new QLineEdit(QString::fromStdString("true"), this));
            }
            else
            {
                 infoform4->addWidget(torcia= new QLineEdit(QString::fromStdString("false"), this));
            }

            infoform4->addWidget(new QLabel("Silenziatore ", this));

            if(static_cast<Pistola*>(a)->getSilenziatore())
            {
                infoform4->addWidget(sil= new QLineEdit(QString::fromStdString("true"), this));
            }
            else
            {
                 infoform4->addWidget(sil= new QLineEdit(QString::fromStdString("false"), this));
            }
            infoform4->addWidget(new QLabel("Automatica ", this));

            if(static_cast<Pistola*>(a)->getAutomatica())
            {
                infoform4->addWidget(automatica= new QLineEdit(QString::fromStdString("true"), this));
            }
            else
            {
                 infoform4->addWidget(automatica= new QLineEdit(QString::fromStdString("false"), this));
            }

            Mainform->addLayout(infoform4);
        }
        else
        {
            if(a->classe()=="Fucile a pompa")
            {
                QGridLayout* infoform5 = new QGridLayout();
                infoform5->addWidget(new QLabel("Doppia canna ", this));
                if(static_cast<Fucile_a_pompa*>(a)->getDoppia_canna())
                {
                    infoform5->addWidget(doppia= new QLineEdit(QString::fromStdString("true"), this));
                }
                else
                {
                    infoform5->addWidget(doppia= new QLineEdit(QString::fromStdString("false"), this));
                }

                Mainform->addLayout(infoform5);
            }
            else
            {
                if(a->classe()=="Fucile a precisione")
                {
                    QGridLayout* infoform6 = new QGridLayout();
                    infoform6->addWidget(new QLabel("Tipo di mirino ", this));
                    infoform6->addWidget(mirino= new QLineEdit(QString::fromStdString(static_cast<Fucile_a_precisione*>(a)->getMirino()), this));
                    infoform6->addWidget(new QLabel("Silenziatore ", this));
                    if(static_cast<Fucile_a_precisione*>(a)->getSilenziatore())
                    {
                        infoform6->addWidget(sil2= new QLineEdit(QString::fromStdString("true"), this));
                    }
                    else
                    {
                        infoform6->addWidget(sil2= new QLineEdit(QString::fromStdString("false"), this));
                    }

                    Mainform->addLayout(infoform6);
                }
            }
        }
    }
    else
    {
        QHBoxLayout* infoform3 = new QHBoxLayout();
        infoform3->addWidget(new QLabel("Ricaricabile ", this));

        if(static_cast<Arma_non_letale*>(a)->GetRicaricabile())
        {
            infoform3->addWidget(ric= new QLineEdit(QString::fromStdString("true"), this));
        }
        else
        {
            infoform3->addWidget(ric= new QLineEdit(QString::fromStdString("false"), this));
        }

        Mainform->addLayout(infoform3);
        if(a->classe()=="Elettrica")
        {
            QGridLayout* infoform7 = new QGridLayout();
            infoform7->addWidget(new QLabel("Voltaggio ", this));
            infoform7->addWidget(voltaggio= new QLineEdit(QString::fromStdString(std::to_string(static_cast<Elettrica*>(a)->getVoltaggio())).replace(QRegExp(","), "."), this));
            voltaggio->setValidator(new QDoubleValidator(100,1,5,this));
            infoform7->addWidget(new QLabel("Amperaggio ", this));
            infoform7->addWidget(ampereggio= new QLineEdit(QString::fromStdString(std::to_string(static_cast<Elettrica*>(a)->getAmperaggio())).replace(QRegExp(","), "."), this));
            ampereggio->setValidator(new QDoubleValidator(100,1,5,this));
            infoform7->addWidget(new QLabel("Durata scarica ", this));
            infoform7->addWidget(durataScarica= new QLineEdit(QString::fromStdString(std::to_string(static_cast<Elettrica*>(a)->getDurata_scarica())).replace(QRegExp(","), "."), this));
            durataScarica->setValidator(new QDoubleValidator(100,1,5,this));
            infoform7->addWidget(new QLabel("Distanza massima ", this));
            infoform7->addWidget(distanza= new QLineEdit(QString::fromStdString(std::to_string(static_cast<Elettrica*>(a)->getDistanza_max())), this));
            distanza->setValidator(new QDoubleValidator(100,1,5,this));
            Mainform->addLayout(infoform7);
        }
        else
        {
            if(a->classe()=="Gas OC")
            {
                QHBoxLayout* infoform8 = new QHBoxLayout();
                infoform8->addWidget(new QLabel("Capacita ", this));
                infoform8->addWidget(capacita= new QLineEdit(QString::fromStdString(std::to_string(static_cast<Gas_OC*>(a)->getCapacita())).replace(QRegExp(","), "."), this));
                capacita->setValidator(new QDoubleValidator(100,1,5,this));
                Mainform->addLayout(infoform8);
            }
        }
    }

    QPushButton* bsalva = new QPushButton("Salva", this);
    Mainform->addWidget(bsalva);
    connect(bsalva, SIGNAL(clicked()), this, SLOT(SSalvaImpostazioni()));//salva i dati
    connect(bsalva, SIGNAL(clicked()), this, SLOT(close()));//chiudi la finestra
    connect(bimg, SIGNAL(clicked()), this, SLOT(SCambiaFoto()));//cambia l'immagine
    setLayout(Mainform);
}

void Modifica::SSalvaImpostazioni()//prendo dalle qlineEdit i dati caricati(che possono essere stati modificati dall'utente) e li salvo
{
    a->setMarca(marca->text().toStdString());
    a->setCosto(costo->text().toFloat());
    a->setNome(nome->text().toStdString());
    if(disp->text().toStdString()=="true")
    {
        a->setDisponibilita(true);
    }
    else
    {
         a->setDisponibilita(false);
    }
    a->setFoto(GestioneImg::getCodice(img->pixmap()->toImage()));//prendo l'img la trasformo in stringa e la salvo
    if(a->Armadafuoco())
    {
        static_cast<Arma_da_fuoco*>(a)->setCalibro(calibro->text().toFloat());
        static_cast<Arma_da_fuoco*>(a)->setCad(cadenza->text().toUInt());
        if(a->classe()=="Pistola")
        {
            if(torcia->text().toStdString()=="true")
            {
                static_cast<Pistola*>(a)->setTorcia(true);
            }
            else
            {
                static_cast<Pistola*>(a)->setTorcia(false);
            }
            if(sil->text().toStdString()=="true")
            {
                static_cast<Pistola*>(a)->setSilenziatore(true);
            }
            else
            {
                static_cast<Pistola*>(a)->setSilenziatore(false);
            }
            if(automatica->text().toStdString()=="true")
            {
                static_cast<Pistola*>(a)->setAutomatica(true);
            }
            else
            {
                static_cast<Pistola*>(a)->setAutomatica(false);
            }
            static_cast<Pistola*>(a)->CalcolaCosto();
        }
        else
        {
            if(a->classe()=="Fucile a pompa")
            {
                if(doppia->text().toStdString()=="true")
                {
                    static_cast<Fucile_a_pompa*>(a)->SetDoppia_canna(true);
                }
                else
                {
                    static_cast<Fucile_a_pompa*>(a)->SetDoppia_canna(false);
                }
                static_cast<Fucile_a_pompa*>(a)->CalcolaCosto();
            }
            else
            {
                if(a->classe()=="Fucile a precisione")
                {
                    if(sil2->text().toStdString()=="true")
                    {
                        static_cast<Fucile_a_precisione*>(a)->setSilenziatore(true);     
                    }
                    else
                    {
                        static_cast<Fucile_a_precisione*>(a)->setSilenziatore(false);
                    }

                    static_cast<Fucile_a_precisione*>(a)->setMirino(mirino->text().toStdString());
                    static_cast<Fucile_a_precisione*>(a)->CalcolaCosto();
                }
            }
        }
    }
    else
    {
        if(ric->text().toStdString()=="true")
        {
            static_cast<Arma_non_letale*>(a)->SetRicaricabile(true);
        }
        else
        {
            static_cast<Arma_non_letale*>(a)->SetRicaricabile(false);
        }
        if(a->classe()=="Elettrica")
        {
            static_cast<Elettrica*>(a)->setVoltaggio(voltaggio->text().toFloat());
            static_cast<Elettrica*>(a)->setAmperaggio(ampereggio->text().toFloat());
            static_cast<Elettrica*>(a)->setDurata(durataScarica->text().toFloat());
            static_cast<Elettrica*>(a)->setDistanza(distanza->text().toInt());
            static_cast<Elettrica*>(a)->CalcolaCosto();
        }
        else
        {
            if(a->classe()=="Gas OC")
            {
                static_cast<Gas_OC*>(a)->setCapacita(capacita->text().toFloat());
            }
        }
    }
    //emit SGCambia(inizio, fine);//invio segnale per aggiornare i dati
}

void Modifica::SCambiaFoto()//gestione cambio foto
{
    QString file= QFileDialog::getOpenFileName(this,tr("Inserisci immagine"),"../progetto/.","Image file (*.jpg *.png *.jpeg)");


           if(file!="")
           {
               img->setPixmap(file);
           }
}
