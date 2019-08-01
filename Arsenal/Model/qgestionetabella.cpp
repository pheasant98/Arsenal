#include "qgestionetabella.h"

QGestioneTabella::QGestioneTabella(QObject *parent, const LInserisci* i): QAbstractTableModel(parent), model(new Model()), inserisci(i){}

QGestioneTabella::~QGestioneTabella()
{
    delete model;

}

int QGestioneTabella::rowCount(const QModelIndex &) const //ritorna il numero di righe del modello
{
    return model->Dimensione();
}

int QGestioneTabella::columnCount(const QModelIndex &) const//ritorna il numero di colonne neccesarie
{
    return 18;//Marca,costo,nome,disponibilita,classe ecc...
}
QVariant QGestioneTabella::headerData(int i, Qt::Orientation o, int r) const//formattazione dell'intestazione della tabella
{
    if(r!=Qt::DisplayRole)
    {
        return QVariant();
    }  
    if(o==Qt::Horizontal)//inserisce le colonne
    {
        switch (i)
        {
        case 0:
            return QString("Marca");
            break;
        case 1:
            return QString("Costo Finale");
            break;
        case 2:
            return QString("Nome");
            break;
        case 3:
            return QString("Disponibilita");
            break;
        case 4:
            return QString("Classe");
            break;
        case 5:
            return QString("Calibro");
            break;
        case 6:
            return QString("Cadenza di fuoco");
            break;
        case 7:
            return QString("Ricaricabile");
            break;
        case 8:
            return QString("Torcia");
            break;
        case 9:
            return QString("Silenziatore");
            break;
        case 10:
            return QString("Automatica");
            break;
        case 11:
            return QString("Doppia canna");
            break;
        case 12:
            return QString("Mirino");
            break;
        case 13:
            return QString("Voltaggio");
            break;
        case 14:
            return QString("Amperaggio");
            break;
        case 15:
            return QString("Durata scarica");
            break;
        case 16:
            return QString("Distanza massima");
            break;
        case 17:
            return QString("Capacita");
            break;
        default:       
            return QVariant();
            break;
        }
    }

    return QVariant();
}

QVariant QGestioneTabella::data(const QModelIndex& i, int r) const //formatazione del testo nella tabella
{
    if (!i.isValid() || static_cast<unsigned int>(i.row()) >= model->Dimensione() || i.row()<0)
    {
        return QVariant();
    }
    switch(r)
    {
        case Qt::DisplayRole://inserisci i dati delle armi
        {
            switch(i.column())
            {
                case 0:
                    return QString::fromStdString(model->getArma(static_cast<unsigned int>(i.row()))->getMarca());
                    break;
                case 1:
                   return model->getArma(static_cast<unsigned int>(i.row()))->CalcolaCosto();
                    break;
                case 2:
                    return QString::fromStdString(model->getArma(static_cast<unsigned int>(i.row()))->getNome());
                    break;
                case 3:
                    return model->getArma(static_cast<unsigned int>(i.row()))->getDisponibilita();
                    break;
                case 4:
                    return QString::fromStdString(model->getArma(static_cast<unsigned int>(i.row()))->classe());
                    break;
                case 5:
                    if(model->getArma(static_cast<unsigned int>(i.row()))->Armadafuoco())
                    {
                        return static_cast<Arma_da_fuoco*>(model->getArma(static_cast<unsigned int>(i.row())))->getCalibro();
                    }
                    return QVariant();
                    break;
                case 6:
                    if(model->getArma(static_cast<unsigned int>(i.row()))->Armadafuoco())
                    {
                        return static_cast<Arma_da_fuoco*>(model->getArma(static_cast<unsigned int>(i.row())))->getCad();
                    }
                    return QVariant();

                    break;
                case 7:
                    if(!model->getArma(static_cast<unsigned int>(i.row()))->Armadafuoco())
                    {
                        return static_cast<Arma_non_letale*>(model->getArma(static_cast<unsigned int>(i.row())))->GetRicaricabile();
                    }
                    return QVariant();
                    break;
                case 8:
                    if(model->getArma(static_cast<unsigned int>(i.row()))->classe()=="Pistola")
                    {
                        return static_cast<Pistola*>(model->getArma(static_cast<unsigned int>(i.row())))->getTorcia();
                    }
                    return QVariant();
                    break;
                case 9:
                    if(model->getArma(static_cast<unsigned int>(i.row()))->classe()=="Pistola")
                    {
                        return static_cast<Pistola*>(model->getArma(static_cast<unsigned int>(i.row())))->getSilenziatore();
                    }
                    if(model->getArma(static_cast<unsigned int>(i.row()))->classe()=="Fucile a precisione")
                    {
                        return static_cast<Fucile_a_precisione*>(model->getArma(static_cast<unsigned int>(i.row())))->getSilenziatore();
                    }
                    return QVariant();
                    break;
                case 10:
                    if(model->getArma(static_cast<unsigned int>(i.row()))->classe()=="Pistola")
                    {
                        return static_cast<Pistola*>(model->getArma(static_cast<unsigned int>(i.row())))->getAutomatica();
                    }
                    return QVariant();
                    break;
                case 11:
                    if(model->getArma(static_cast<unsigned int>(i.row()))->classe()=="Fucile a pompa")
                    {
                        return static_cast<Fucile_a_pompa*>(model->getArma(static_cast<unsigned int>(i.row())))->getDoppia_canna();
                    }
                    return QVariant();
                break;
                case 12:
                    if(model->getArma(static_cast<unsigned int>(i.row()))->classe()=="Fucile a precisione")
                    {
                        return QString::fromStdString(static_cast<Fucile_a_precisione*>(model->getArma(static_cast<unsigned int>(i.row())))->getMirino());
                    }
                    return QVariant();
                case 13:
                    if(model->getArma(static_cast<unsigned int>(i.row()))->classe()=="Elettrica")
                    {
                        return static_cast<Elettrica*>(model->getArma(static_cast<unsigned int>(i.row())))->getVoltaggio();
                    }
                    return QVariant();
                break;
                case 14:
                    if(model->getArma(static_cast<unsigned int>(i.row()))->classe()=="Elettrica")
                    {
                        return static_cast<Elettrica*>(model->getArma(static_cast<unsigned int>(i.row())))->getAmperaggio();
                    }
                    return QVariant();
                break;
                case 15:
                    if(model->getArma(static_cast<unsigned int>(i.row()))->classe()=="Elettrica")
                    {
                        return static_cast<Elettrica*>(model->getArma(static_cast<unsigned int>(i.row())))->getDurata_scarica();
                    }
                    return QVariant();
                break;
                case 16:
                    if(model->getArma(static_cast<unsigned int>(i.row()))->classe()=="Elettrica")
                    {
                        return static_cast<Elettrica*>(model->getArma(static_cast<unsigned int>(i.row())))->getDistanza_max();
                    }
                    return QVariant();
                break;
                case 17:
                    if(model->getArma(static_cast<unsigned int>(i.row()))->classe()=="Gas OC")
                    {
                        return static_cast<Gas_OC*>(model->getArma(static_cast<unsigned int>(i.row())))->getCapacita();
                    }
                    return QVariant();
                break;
                default:
                    return QVariant();
                    break;
            }
        }
        case Qt::TextAlignmentRole://imposta come allineare il testo
            return QVariant (Qt::AlignVCenter | Qt::AlignHCenter);
            break;
        case Qt::SizeHintRole://dim
            return QSize( 500, 200 );
            break;
        case Qt::ForegroundRole://imposta il colore del testo
            if (model->getArma(static_cast<unsigned int>(i.row()))->Armadafuoco())
            {
                return QVariant (QColor(Qt::darkCyan));
            }
            else
            {
                return QVariant (QColor(Qt::darkYellow));
            }
            break;
        case Qt::FontRole://imposta il tipo di carattere del testo
            if (model->getArma(static_cast<unsigned int>(i.row()))->Armadafuoco())
            {  
                return QFont("Roboto", 18, QFont::Bold);
            }
            else
            {
                return QFont("Arial", 18, QFont::Black);
            }
           break;

    }
    return QVariant();
}

bool QGestioneTabella::insertRows(int inizio, int c, const QModelIndex& parent)//inserisce una nuova riga nella tabella
{
    beginInsertRows(parent, inizio, inizio+c-1);//indico da dove inizio ad inserire e fino a dove
    string s = inserisci->getTipo();
    if(s=="Arma da fuoco")
    {
        s=inserisci->getCat1();
    }
    else
    {
        s=inserisci->getCat2();
    }
    if(s=="Pistola")
    {
        Pistola *a=new Pistola(inserisci->getMarca()->text().toStdString(), inserisci->getCosto()->text().toFloat(), inserisci->getNome()->text().toStdString(),inserisci->getDisp(), GestioneImg::getCodice(inserisci->getSFoto()->pixmap()->toImage()), inserisci->getCalibro()->text().toFloat(), inserisci->getCadenza()->text().toUInt(),inserisci->getTorcia(),inserisci->getSilenziatore(),inserisci->getAutomatica());
        model->Aggiungi(a);
        delete a;
    }
    else
    {
        if (s=="Fucile a pompa")
        {
            Fucile_a_pompa *a=new Fucile_a_pompa(inserisci->getMarca()->text().toStdString(), inserisci->getCosto()->text().toFloat(), inserisci->getNome()->text().toStdString(),inserisci->getDisp(), GestioneImg::getCodice(inserisci->getSFoto()->pixmap()->toImage()), inserisci->getCalibro()->text().toFloat(), inserisci->getCadenza()->text().toUInt(),inserisci->getDoppiaCanna());
            model->Aggiungi(a);
            delete a;
        }

        else
        {
          if (s=="Fucile a precisione")
          {
             Fucile_a_precisione *a=new Fucile_a_precisione(inserisci->getMarca()->text().toStdString(), inserisci->getCosto()->text().toFloat(), inserisci->getNome()->text().toStdString(),inserisci->getDisp(), GestioneImg::getCodice(inserisci->getSFoto()->pixmap()->toImage()), inserisci->getCalibro()->text().toFloat(), inserisci->getCadenza()->text().toUInt(), inserisci->getMirino(),inserisci->getSilenziatore2());
             model->Aggiungi(a);
             delete a;
          }
          else
          {
             if (s=="Elettrica")
             {
                 Elettrica *a=new Elettrica(inserisci->getMarca()->text().toStdString(), inserisci->getCosto()->text().toFloat(), inserisci->getNome()->text().toStdString(),inserisci->getDisp(), GestioneImg::getCodice(inserisci->getSFoto()->pixmap()->toImage()), inserisci->getRicaricabile(),inserisci->getVoltaggio()->text().toFloat(),inserisci->getAmperaggio()->text().toFloat(),inserisci->getDurata()->text().toFloat(),inserisci->getDistanza()->text().toInt());
                 model->Aggiungi(a);
                 delete a;
             }
             else
             {
                 Gas_OC *a=new Gas_OC(inserisci->getMarca()->text().toStdString(), inserisci->getCosto()->text().toFloat(), inserisci->getNome()->text().toStdString(),inserisci->getDisp(), GestioneImg::getCodice(inserisci->getSFoto()->pixmap()->toImage()), inserisci->getRicaricabile(),inserisci->getCapacita()->text().toDouble());
                 model->Aggiungi(a);
                 delete a;
             }
          }
        }
     }
    endInsertRows();//indico che è stato completato l'inserimento
    return true;

}

bool QGestioneTabella::removeRows(int inizio, int c, const QModelIndex& parent)//rimuove la colonna da eliminare dalla tabella
{
    beginRemoveRows(parent, inizio, inizio+c-1);
    model->Rimuovi(inizio);
    endRemoveRows();
    return true;
}

void QGestioneTabella::mostraV(const QModelIndex & i) const//apre la finestra visualizza oggetti
{
    if (i.isValid() && i.row()< rowCount() && i.column()<columnCount())
    {
        VisualizzaOggetto* v = new VisualizzaOggetto(model->getArma(static_cast<unsigned int>(i.row())));//crea la nuova finestra indicando gli dati da mostare
        v->setAttribute(Qt::WA_DeleteOnClose);//pulizia
        v->show();
    }
}

void QGestioneTabella::mostraM(const QModelIndex & i)//apre la finestra modifica
{
    if (i.isValid() && i.row() < rowCount() && i.column()<columnCount())
    {
        Modifica* v = new Modifica(model->getArma(static_cast<unsigned int>(i.row())), QAbstractTableModel::createIndex(i.row(), 0), QAbstractTableModel::createIndex(i.row(), columnCount()-1));//crea la nuova finestra indicando gli dati da mostare
        //connect(v, SIGNAL(SGCambia(QModelIndex, QModelIndex)), this, SIGNAL(datachanged(const QModelIndex&, const QModelIndex&)));//invio un segnale per indicare alla tabella di aggiornare i dati
        v->setAttribute(Qt::WA_DeleteOnClose);
        v->show();
    }
}

bool QGestioneTabella::matcha(unsigned int r, const QRegExp& str, const QString& sceltaC, bool sceltaR) const //ricerca, ritorna true se matcha
{
    if(sceltaC=="Marca")
    {

        return QString::fromStdString(model->getArma(r)->getMarca()).contains(str);//controlla se la stringa e contenuta nel campo
    }
    else
    {
        if(sceltaC=="Nome")
        {
            return QString::fromStdString(model->getArma(r)->getNome()).contains(str);
        }
        else
        {
            if(sceltaC=="Classe")
            {
                return QString::fromStdString(model->getArma(r)->classe()).contains(str);
            }
            else
            {
                if(sceltaC=="Disponibilita")
                {
                    return QString::fromStdString(std::to_string(model->getArma(r)->getDisponibilita())).contains(str);
                }
                else
                {
                    if(sceltaC=="Costo")
                    {
                        if(sceltaR)//controllo se ricerco per maggiore o minore
                        {

                            return model->RicercaMaggiore(r,str.pattern().toFloat(), sceltaC.toStdString());//ricerco se un valore di un oggetto[r] è maggiore di un certo valore pattern nel campo sceltaC
                        }
                        else
                        {
                            return model->RicercaMinore(r,str.pattern().toFloat(), sceltaC.toStdString());
                        }
                    }
                    else
                    {
                        if(sceltaC=="Calibro")
                        {
                            if(sceltaR)
                            {
                                return model->RicercaMaggiore(r,str.pattern().toFloat(), sceltaC.toStdString());
                            }
                            else
                            {
                                return model->RicercaMinore(r,str.pattern().toFloat(), sceltaC.toStdString());
                            }

                        }
                        else
                        {
                            if(sceltaC=="Cadenza di fuoco")
                            {
                                if(sceltaR)
                                {
                                    return model->RicercaMaggiore(r,str.pattern().toFloat(), sceltaC.toStdString());
                                }
                                else
                                {
                                    return model->RicercaMinore(r,str.pattern().toFloat(), sceltaC.toStdString());
                                }
                            }
                            else
                            {
                                if(sceltaC=="Ricaricabile")
                                {
                                    if(!model->getArma(r)->Armadafuoco())
                                    {
                                        return QString::fromStdString(std::to_string(static_cast<Arma_non_letale*>(model->getArma(r))->GetRicaricabile())).contains(str);
                                    }
                                    else
                                    {
                                        return false;
                                    }
                                }
                                else
                                {
                                    if(sceltaC=="Torcia")
                                    {
                                        if(model->getArma(r)->classe()=="Pistola")
                                        {
                                            return QString::fromStdString(std::to_string(static_cast<Pistola*>(model->getArma(r))->getTorcia())).contains(str);
                                        }
                                        else
                                        {
                                            return false;
                                        }
                                    }
                                    else
                                    {
                                        if(sceltaC=="Silenziatore")
                                        {
                                            if(model->getArma(r)->classe()=="Pistola")
                                            {
                                                return QString::fromStdString(std::to_string(static_cast<Pistola*>(model->getArma(r))->getSilenziatore())).contains(str);
                                            }
                                            else
                                            {
                                                if(model->getArma(r)->classe()=="Fucile a precisione")
                                                {
                                                    return QString::fromStdString(std::to_string(static_cast<Fucile_a_precisione*>(model->getArma(r))->getSilenziatore())).contains(str);
                                                }
                                                else
                                                {
                                                    return false;
                                                }
                                            }
                                        }
                                        else
                                        {
                                            if(sceltaC=="Automatica")
                                            {
                                                if(model->getArma(r)->classe()=="Pistola")
                                                {
                                                    return QString::fromStdString(std::to_string(static_cast<Pistola*>(model->getArma(r))->getAutomatica())).contains(str);
                                                }
                                                else
                                                {
                                                    return false;
                                                }
                                            }
                                            else
                                            {
                                                if(sceltaC=="Doppia canna")
                                                {
                                                    if(model->getArma(r)->classe()=="Fucile a pompa")
                                                    {
                                                        return QString::fromStdString(std::to_string(static_cast<Fucile_a_pompa*>(model->getArma(r))->getDoppia_canna())).contains(str);
                                                    }
                                                    else
                                                    {
                                                        return false;
                                                    }
                                                }
                                                else
                                                {
                                                    if(sceltaC=="Mirino")
                                                    {
                                                        if(model->getArma(r)->classe()=="Fucile a precisione")
                                                        {
                                                            return QString::fromStdString(static_cast<Fucile_a_precisione*>(model->getArma(r))->getMirino()).contains(str);
                                                        }
                                                        else
                                                        {
                                                            return false;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        if(sceltaC=="Voltaggio")
                                                        {
                                                            if(sceltaR)
                                                            {
                                                                return model->RicercaMaggiore(r,str.pattern().toFloat(), sceltaC.toStdString());
                                                            }
                                                            else
                                                            {
                                                                return model->RicercaMinore(r,str.pattern().toFloat(), sceltaC.toStdString());
                                                            }
                                                        }
                                                        else
                                                        {
                                                            if(sceltaC=="Amperaggio")
                                                            {
                                                                if(sceltaR)
                                                                {
                                                                    return model->RicercaMaggiore(r,str.pattern().toFloat(), sceltaC.toStdString());
                                                                }
                                                                else
                                                                {
                                                                    return model->RicercaMinore(r,str.pattern().toFloat(), sceltaC.toStdString());
                                                                }
                                                            }
                                                            else
                                                            {
                                                                if(sceltaC=="Durata scarica")
                                                                {
                                                                    if(sceltaR)
                                                                    {
                                                                        return model->RicercaMaggiore(r,str.pattern().toFloat(), sceltaC.toStdString());
                                                                    }
                                                                    else
                                                                    {
                                                                        return model->RicercaMinore(r,str.pattern().toFloat(), sceltaC.toStdString());
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    if(sceltaC=="Distanza massima")
                                                                    {
                                                                        if(sceltaR)
                                                                        {
                                                                            return model->RicercaMaggiore(r,str.pattern().toInt(), sceltaC.toStdString());
                                                                        }
                                                                        else
                                                                        {
                                                                            return model->RicercaMinore(r,str.pattern().toInt(), sceltaC.toStdString());
                                                                        }
                                                                    }
                                                                    else
                                                                    {
                                                                        if(sceltaC=="Capacita")
                                                                        {
                                                                            if(sceltaR)
                                                                            {
                                                                                return model->RicercaMaggiore(r,str.pattern().toFloat(), sceltaC.toStdString());
                                                                            }
                                                                            else
                                                                            {
                                                                                return model->RicercaMinore(r,str.pattern().toFloat(), sceltaC.toStdString());
                                                                            }
                                                                        }
                                                                        else
                                                                        {
                                                                            return false;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void QGestioneTabella::salvaNelFile(const string& file) const
{
    model->SalvaFile(file);
}
void QGestioneTabella::caricaDalFile(const string& file)
{
    model->CaricaFile(file);
}

float QGestioneTabella::totale() const
{
    return model->TotCosto();
}
