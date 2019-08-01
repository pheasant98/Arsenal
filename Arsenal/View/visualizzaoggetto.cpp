#include "visualizzaoggetto.h"


VisualizzaOggetto::VisualizzaOggetto(Arma *arma1, QWidget *parent ): QWidget(parent), a(arma1)
{
    DPtr<Arma> app=a;
    QHBoxLayout* MainForm = new QHBoxLayout(this);
    QVBoxLayout* Dxform = new QVBoxLayout();
    QHBoxLayout* imgform = new QHBoxLayout();
    img=new QLabel();
    img->setPixmap(GestioneImg::getImg(a->getFoto()));
    imgform->addWidget(img);
    QHBoxLayout* tipoform = new QHBoxLayout();
    tipoform->addWidget(new QLabel("Tipo ", this));
    tipoform->addWidget(tipo = new QLabel(QString::fromStdString(a->classe()), this));
    QHBoxLayout* infoform = new QHBoxLayout();
    infoform->addWidget(new QLabel("Marca: ", this));
    infoform->addWidget(marca= new QLabel(QString::fromStdString(a->getMarca()), this));
    QHBoxLayout* infoform0_1 = new QHBoxLayout();
    infoform0_1->addWidget(new QLabel("Costo base: ", this));
    infoform0_1->addWidget(costo= new QLabel(QString::fromStdString(std::to_string(a->getCosto())).replace(QRegExp(","), "."), this));
    QHBoxLayout* infoform0_2 = new QHBoxLayout();
    infoform0_2->addWidget(new QLabel("Nome: ", this));
    infoform0_2->addWidget(nome= new QLabel(QString::fromStdString(a->getNome()), this));
    QVBoxLayout* infoform0_3 = new QVBoxLayout();
    infoform0_3->addWidget(new QLabel("Disponibilita: ", this));
    if(a->getDisponibilita())
    {
        infoform0_3->addWidget(disp= new QLabel("Si", this));
    }
    else
    {
        infoform0_3->addWidget(disp= new QLabel("No", this));
    }

    Dxform->addLayout(tipoform);
    Dxform->addLayout(infoform);
    Dxform->addLayout(infoform0_1);
    Dxform->addLayout(infoform0_2);
    Dxform->addLayout(infoform0_3);

    if(a->Armadafuoco())
    {
        QHBoxLayout* infoform2 = new QHBoxLayout();
        infoform2->addWidget(new QLabel("Calibro: ", this));
        infoform2->addWidget(calibro= new QLabel(QString::fromStdString(std::to_string(static_cast<Arma_da_fuoco*>(a)->getCalibro())).replace(QRegExp(","), "."), this));
        QHBoxLayout* infoform2_1 = new QHBoxLayout();
        infoform2_1->addWidget(new QLabel("Cadenza di fuoco: ", this));
        infoform2_1->addWidget(cadenza= new QLabel(QString::fromStdString(std::to_string(static_cast<Arma_da_fuoco*>(a)->getCad())), this));
        Dxform->addLayout(infoform2);
        Dxform->addLayout(infoform2_1);
        if(a->classe()=="Pistola")
        {
            QGridLayout* infoform4 = new QGridLayout();
            infoform4->addWidget(new QLabel("Torcia: ", this));
            if(static_cast<Pistola*>(a)->getTorcia())
            {
                infoform4->addWidget(torcia= new QLabel("Si", this));
            }
            else
            {
                 infoform4->addWidget(torcia= new QLabel("No", this));
            }

            infoform4->addWidget(new QLabel("Silenziatore: ", this));

            if(static_cast<Pistola*>(a)->getSilenziatore())
            {
                infoform4->addWidget(sil= new QLabel("Si", this));
            }
            else
            {
                 infoform4->addWidget(sil= new QLabel("No", this));
            }
            infoform4->addWidget(new QLabel("Automatica: ", this));

            if(static_cast<Pistola*>(a)->getAutomatica())
            {
                infoform4->addWidget(automatica= new QLabel("Si", this));
            }
            else
            {
                 infoform4->addWidget(automatica= new QLabel("No", this));
            }

            Dxform->addLayout(infoform4);
        }
        else
        {
            if(a->classe()=="Fucile a pompa")
            {
                QGridLayout* infoform5 = new QGridLayout();
                infoform5->addWidget(new QLabel("Doppia canna: ", this));
                if(static_cast<Fucile_a_pompa*>(a)->getDoppia_canna())
                {
                    infoform5->addWidget(doppia= new QLabel("Si", this));
                }
                else
                {
                    infoform5->addWidget(doppia= new QLabel("No", this));
                }

                Dxform->addLayout(infoform5);
            }
            else
            {
                if(a->classe()=="Fucile a precisione")
                {
                    QHBoxLayout* infoform6_1 = new QHBoxLayout();
                    infoform6_1->addWidget(new QLabel("Tipo di mirino: ", this));
                    infoform6_1->addWidget(mirino= new QLabel(QString::fromStdString(static_cast<Fucile_a_precisione*>(a)->getMirino()), this));
                    QGridLayout* infoform6_2 = new QGridLayout();
                    infoform6_2->addWidget(new QLabel("Silenziatore: ", this));
                    if(static_cast<Fucile_a_precisione*>(a)->getSilenziatore())
                    {
                        infoform6_2->addWidget(sil2= new QLabel("Si", this));
                    }
                    else
                    {
                        infoform6_2->addWidget(sil2= new QLabel("No", this));
                    }
                    Dxform->addLayout(infoform6_1);
                    Dxform->addLayout(infoform6_2);
                }
            }
        }
    }
    else
    {
        QGridLayout* infoform3 = new QGridLayout();
        infoform3->addWidget(new QLabel("Ricaricabile: ", this));

        if(static_cast<Arma_non_letale*>(a)->GetRicaricabile())
        {
            infoform3->addWidget(ric= new QLabel("Si", this));
        }
        else
        {
            infoform3->addWidget(ric= new QLabel("No", this));
        }

        Dxform->addLayout(infoform3);
        if(a->classe()=="Elettrica")
        {
            QHBoxLayout* infoform7_1 = new QHBoxLayout();
            infoform7_1->addWidget(new QLabel("Voltaggio: ", this));
            infoform7_1->addWidget(voltaggio= new QLabel(QString::fromStdString(std::to_string(static_cast<Elettrica*>(a)->getVoltaggio())).replace(QRegExp(","), "."), this));
            QHBoxLayout* infoform7_2 = new QHBoxLayout();
            infoform7_2->addWidget(new QLabel("Amperaggio: ", this));
            infoform7_2->addWidget(ampereggio= new QLabel(QString::fromStdString(std::to_string(static_cast<Elettrica*>(a)->getAmperaggio())), this));
            QHBoxLayout* infoform7_3 = new QHBoxLayout();
            infoform7_3->addWidget(new QLabel("Durata scarica: ", this));
            infoform7_3->addWidget(durataScarica= new QLabel(QString::fromStdString(std::to_string(static_cast<Elettrica*>(a)->getDurata_scarica())).replace(QRegExp(","), "."), this));
            QHBoxLayout* infoform7_4 = new QHBoxLayout();
            infoform7_4->addWidget(new QLabel("Distanza massima: ", this));
            infoform7_4->addWidget(distanza= new QLabel(QString::fromStdString(std::to_string(static_cast<Elettrica*>(a)->getDistanza_max())), this));
            Dxform->addLayout(infoform7_1);
            Dxform->addLayout(infoform7_2);
            Dxform->addLayout(infoform7_3);
            Dxform->addLayout(infoform7_4);
        }
        else
        {
            if(a->classe()=="Gas OC")
            {
                QHBoxLayout* infoform8 = new QHBoxLayout();
                infoform8->addWidget(new QLabel("Capacita: ", this));
                infoform8->addWidget(capacita= new QLabel(QString::fromStdString(std::to_string(static_cast<Gas_OC*>(a)->getCapacita())).replace(QRegExp(","), "."), this));
                Dxform->addLayout(infoform8);
            }
        }
    }
    MainForm->addLayout(Dxform);
    MainForm->addLayout(imgform);
    setLayout(MainForm);
}
QSize VisualizzaOggetto::sizeHint() const
{
    return QSize(500, 500);
}
