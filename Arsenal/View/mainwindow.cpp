#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent, bool flag) :QWidget(parent), menuBar(new Menu(this)), file(QString()),MainL(new QHBoxLayout(this)),
    InserisciL(new LInserisci(this)),RicL(new Ricerca(this))
{
    setWindowTitle(tr("Arsenal - Progetto"));
    setWindowIcon(QIcon(":/icon.png"));
    VisL = new Visualizza(this,InserisciL,RicL);
    MainL->setMenuBar(menuBar);
    MainL->addWidget(InserisciL);
    MainL->addWidget(VisL);
    if(flag)
    {
        SCarica();
    }
    VisL->getTab()->DimCol();//imposta la dimensione delle colonne
    VisL->getTab()->Visible(RicL->getRicerca()->currentIndex());//mostra le colonne corrette
    SMostraInserisci();
    setLayout(MainL);

    //Gestione eventi completa
    connect(InserisciL, SIGNAL(SGInserisci()), this, SLOT(SAggiungi()));//gestione inserisci
    connect(VisL, SIGNAL(SGMostra()), this, SLOT(SVisualizza()));//gestione visualizza
    connect(VisL, SIGNAL(SGModifica()), this, SLOT(SModifica()));//gestione modifica
    connect(VisL, SIGNAL(SGElimina()), this, SLOT(SRimuovi()));//gestione eliminazione
    connect(VisL, SIGNAL(SGCostoTot()), this, SLOT(SCostoTot()));//gestione calcolo costo totale
    connect(RicL, SIGNAL(SGRicerca()), this, SLOT(SRicerca()));//gestione ricerca
    connect(RicL, SIGNAL(SGOrdinaAsc()), this, SLOT(SOrdinaAsd()));//gestione ordina asc
    connect(RicL, SIGNAL(SGOrdinaDesc()), this, SLOT(SOrdinaDesc()));//gestione ordina desc

}

void MainWindow::closeEvent(QCloseEvent *e)//gestione della chiusura dell'applicazione, chiede all'utente se salvare i dati oppure no
{
    QMessageBox::StandardButton mxChiusura = QMessageBox::question(this, tr("Conferma la chiusura"),tr("Sta per uscire dall'applicazione, vuoi salvare i dati?\n"), QMessageBox::Save | QMessageBox::No | QMessageBox::Cancel, QMessageBox::Save);
    if(mxChiusura==QMessageBox::Save)
    {
        SSalva();
        e->accept();
    }
    else
    {
        if(mxChiusura==QMessageBox::Cancel)
        {
                e->ignore();
        }
        else//No
        {
            e->accept();
        }
    }
}

void MainWindow::SSalva()//slot per il salvattaggio dati nel file xml
{   
    if(!file.isEmpty())//se il file esiste sovvrascrivi
    {
        try
        {
            VisL->getModel()->salvaNelFile(file.toStdString());
        }
        catch (std::exception)
        {
            QMessageBox box(QMessageBox::Warning, "Errore di salvataggio", "Non è stato possibile scrivere sul file", QMessageBox::Ok);
            box.exec();
        }
    }
    else//se non  esiste creane uno nuovo
    {
        SSalvaConNome();
    }

}

void MainWindow::SSalvaConNome()//crea un nuovo file xml e salva i dati
{
    file = QFileDialog::getSaveFileName(this, tr("Save to a file"), "", tr("XML (*.xml);;All Files (*)"));
    if(!file.contains(".xml"))
    {
        file.append(".xml");
    }
    if(!file.isEmpty())
    {
        setWindowTitle(QFileInfo(file).fileName() + tr(" - Arsenal - Progetto"));
        try {
            VisL->getModel()->salvaNelFile(file.toStdString());
        } catch (std::exception) {
            QMessageBox box(QMessageBox::Warning, "Errore di salvataggio", "Non è stato possibile scrivere sul file", QMessageBox::Ok);
            box.exec();
        }
    }
}
void MainWindow::SCarica()//carica i dati salvati in un file xml inserito dall'utente
{
    file = QFileDialog::getOpenFileName(this,tr("Caricamento da file"), "", tr("XML (*.xml);;All Files (*)"));
    if(!file.isEmpty())
    {
        setWindowTitle(QFileInfo(file).fileName() + tr(" - Arsenal - Progetto"));
        VisL->getModel()->caricaDalFile(file.toStdString());
    }
    VisL->getIntermedioL()->setSourceModel(VisL->getModel());
    VisL->getTab()->setModel(VisL->getIntermedioL());//aggiorna la tabella inserendo i dati del file xml scelto
}

void MainWindow::SMostraInserisci() const//mostra tab inserisci
{
    VisL->hide();
    InserisciL->show();
}

void MainWindow::SMostraVisualizza() const//mostra la tab visualizza-modifica-ricerca-elimina
{
    VisL->show();
    InserisciL->hide();
}

void MainWindow::SAggiungi()
{
    if(InserisciL->getMarca()->text()!="" && InserisciL->getCosto()->text()!="" && InserisciL->getNome()->text()!="")
    {
        if(InserisciL->getTipo()=="Arma da fuoco")
        {
            if(InserisciL->getCalibro()->text()!="" && InserisciL->getCadenza()->text()!="" && InserisciL->getCat1()!="")
            {
                if(InserisciL->getCat1()!="Fucile a precisione")
                {
                    VisL->getIntermedioL()->insertRows(VisL->getIntermedioL()->rowCount(), 1);//inserisce nella riga correta
                    QMessageBox::information(this,tr("Inserimento"), tr("Inserita arma\n"), QMessageBox::Ok);
                }
                else
                {
                    if(InserisciL->getMirino()!="")
                    {
                        VisL->getIntermedioL()->insertRows(VisL->getIntermedioL()->rowCount(), 1);//inserisce nella riga correta
                        QMessageBox::information(this,tr("Inserimento"), tr("Inserita arma\n"), QMessageBox::Ok);
                    }
                    else
                    {
                         QMessageBox::warning(this,tr("Errore"), tr("Inserire tutti i dati nei campi\n"), QMessageBox::Ok);
                    }
                }

            }
            else
            {
                QMessageBox::warning(this,tr("Errore"), tr("Inserire tutti i dati nei campi\n"), QMessageBox::Ok);
            }
        }
        else
        {
            if(InserisciL->getTipo()=="Arma non letale")
            {
                if(InserisciL->getCat2()=="Elettrica")
                {
                    if(InserisciL->getVoltaggio()->text()!="" && InserisciL->getAmperaggio()->text()!="" && InserisciL->getDurata()->text()!="" && InserisciL->getDistanza()->text()!="")
                    {
                        VisL->getIntermedioL()->insertRows(VisL->getIntermedioL()->rowCount(), 1);
                        QMessageBox::information(this,tr("Inserimento"), tr("Inserita arma\n"), QMessageBox::Ok);
                    }
                    else
                    {
                        QMessageBox::warning(this,tr("Errore"), tr("Inserire tutti i dati nei campi\n"), QMessageBox::Ok);
                    }
                }
                else
                {
                    if(InserisciL->getCat2()=="GAS OC")
                    {
                        if(InserisciL->getCapacita()->text()!="")
                        {
                            VisL->getIntermedioL()->insertRows(VisL->getIntermedioL()->rowCount(), 1);
                            QMessageBox::information(this,tr("Inserimento"), tr("Inserita arma\n"), QMessageBox::Ok);
                        }
                        else
                        {
                            QMessageBox::warning(this,tr("Errore"), tr("Inserire tutti i dati nei campi\n"), QMessageBox::Ok);
                        }
                    }
                    else
                    {
                        QMessageBox::warning(this,tr("Errore"), tr("Inserire tutti i dati nei campi\n"), QMessageBox::Ok);
                    }
                }
            }
            else
            {
                QMessageBox::warning(this,tr("Errore"), tr("Inserire tutti i dati nei campi\n"), QMessageBox::Ok);
            }
        }
    }
    else
    {
        QMessageBox::warning(this,tr("Errore"), tr("Inserire tutti i dati nei campi\n"), QMessageBox::Ok);
    }

}

void MainWindow::SVisualizza() const
{

    const QModelIndexList selection=VisL->getTab()->selectionModel()->selectedIndexes();//seleziona la riga da usare
    if(selection.size()>0)
    {
        VisL->getIntermedioL()->mostra2(selection.at(0));
    }
}

void MainWindow::SModifica() const
{
    const QModelIndexList selection=VisL->getTab()->selectionModel()->selectedIndexes();
    if(selection.size()>0)
    {
        VisL->getIntermedioL()->mostra(selection.at(0));
    }

}

void MainWindow::SRimuovi() const
{
    const QModelIndexList selection=VisL->getTab()->selectionModel()->selectedIndexes();
    if(selection.size()>0)
    {
        VisL->getIntermedioL()->removeRows(selection.at(0).row(), 1);
    }
}

void MainWindow::SRicerca() const
{
    QString str=RicL->getRicerca()->currentText();//prendo il filtro per la ricerca dalla comboBox
    VisL->getTab()->Visible(RicL->getRicerca()->currentIndex());// mostra le colonne corrette

    if(str=="Marca" || str=="Nome" || str=="Classe")//gestione stringe
    {
        QRegExp strRicerca(RicL->getBarradiricerca()->text(), Qt::CaseInsensitive, QRegExp::Wildcard);//estraggo la stringa da cercare
        VisL->getIntermedioL()->setFilterRegExp(strRicerca);//ricerca
    }
    else
    {
        if(str=="Disponibilita" || str=="Ricaricabile" || str=="Torcia" ||str=="Silenziatore" || str=="Automatica" || str=="Doppia canna" )//gestione bool
        {
            if(RicL->getVero()->isChecked())
            {

                QRegExp strRicerca(QString::fromStdString("1"), Qt::CaseInsensitive, QRegExp::Wildcard);
                VisL->getIntermedioL()->setFilterRegExp(strRicerca);
            }
            else
            {
                QRegExp strRicerca(QString::fromStdString("0"), Qt::CaseInsensitive, QRegExp::Wildcard);
                VisL->getIntermedioL()->setFilterRegExp(strRicerca);
            }
        }
        else
        {
            if(str=="Mirino")
            {
                QRegExp strRicerca(RicL->getMirino()->currentText(), Qt::CaseInsensitive, QRegExp::Wildcard);
                VisL->getIntermedioL()->setFilterRegExp(strRicerca);
            }
            else
            {
                if(str=="Costo" || str=="Calibro" || str=="Cadenza di fuoco" || str=="Voltaggio" || str=="Amperaggio" || str=="Durata scarica" || str=="Distanza massima" || str=="Capacita")
                {
                    QRegExp strRicerca(RicL->getBarradiricerca()->text(), Qt::CaseInsensitive, QRegExp::Wildcard);
                    VisL->getIntermedioL()->setFilterRegExp(strRicerca);
                }
            }
        }
    }
}

void MainWindow::SOrdinaAsd() const
{
    SRicerca();
    VisL->getTab()->sortByColumn(RicL->getRicerca()->currentIndex(), Qt::AscendingOrder);//ordina in base l'indice della comboBox ricerca
}

void MainWindow::SOrdinaDesc() const
{
    SRicerca();
    VisL->getTab()->sortByColumn(RicL->getRicerca()->currentIndex(), Qt::DescendingOrder);
}

void MainWindow::SCostoTot()
{
    float f=VisL->getModel()->totale();

    QMessageBox::information(this,tr("Calcolo Totale"), QString::fromStdString(std::to_string(f).append(" € ")), QMessageBox::Ok);
}

