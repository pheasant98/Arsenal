#include "xmlio.h"

xmlio::xmlio(const string& f) : file(f) {}

Qontainer<DPtr<Arma>> xmlio::read() const
{
    Qontainer<DPtr<Arma>> app;
    QFile qfile(QString::fromStdString(file));
    if(!qfile.open(QIODevice::ReadOnly))//apro in lettura il file XML
    {
        qWarning() << "Errore, non è stato possibile aprire il file" << qfile.errorString();
        return app;
    }
    QXmlStreamReader reader(&qfile); // QIODevice*
    if(reader.readNextStartElement() && reader.name() == "root")//legge tag principale
    {
        while(reader.readNextStartElement())//legge il tag <Arma> di ogni oggetto arma se non trova più tag arma allora non ci sono più oggetti da leggere e si ferma
        { 
            if(reader.name() == "Arma")//verifica se quello che ha letto dopo il tag <root> è il tag <Arma>
            {
                const QString classe = reader.attributes().value("Classe").toString();//legge il valore classe contenuto come sttributo del tag
                string marca=" ",nome=" ", mirino=" ",foto=" ";
                bool disp=false, ric=false, torcia=false, silenziatore=false, automatica=false, dopcan=false;
                float costo=0.0, cal=0.0, volt=0.0, amp=0.0, durata=0.0, cap=0.0;
                int cad=0, distanza=0;
                //legge in ordine i vari tag a seconda della classe salvata nel tag arma
                if(reader.readNextStartElement() && reader.name()=="Marca")
                {
                    marca=reader.readElementText().toStdString();
                }
                if(reader.readNextStartElement() && reader.name()=="Costo")
                {
                    costo=reader.readElementText().toFloat();
                }
                if(reader.readNextStartElement() && reader.name()=="Nome")
                {
                    nome=reader.readElementText().toStdString();
                }
                if(reader.readNextStartElement() && reader.name()=="Disponibilita")
                {
                    disp=reader.readElementText().toInt();
                }
                if(reader.readNextStartElement() && reader.name()=="Foto")
                {
                    foto=reader.readElementText().toStdString();
                }

                if(classe=="Pistola")
                {
                    if(reader.readNextStartElement() && reader.name()=="Calibro")
                    {
                        cal=reader.readElementText().toFloat();
                    }
                    if(reader.readNextStartElement() && reader.name()=="Cadenza_di_fuoco")
                    {
                        cad=reader.readElementText().toInt();
                    }
                    if(reader.readNextStartElement() && reader.name()=="Torcia")
                    {
                        torcia=reader.readElementText().toInt();
                    }
                    if(reader.readNextStartElement() && reader.name()=="Silenziatore")
                    {
                        silenziatore=reader.readElementText().toInt();
                    }
                    if(reader.readNextStartElement() && reader.name()=="Automatica")
                    {
                        automatica=reader.readElementText().toInt();
                    }
                    try
                    {//crea l'oggetto se tutto corretto
                        Pistola *a=new Pistola(marca, costo, nome, disp, foto, cal, cad, torcia, silenziatore, automatica);
                        app.push_back(a); //carico l'oggetto letto dal file XML
                        delete a;
                    }
                    catch(string s)
                    {
                        QMessageBox box(QMessageBox::Warning, "Errore in lettura", "Errore in lettura", QMessageBox::Ok);
                    }
                }
                else
                {
                    if(classe=="Fucile a pompa")
                    {
                        if(reader.readNextStartElement() && reader.name()=="Calibro")
                        {
                            cal=reader.readElementText().toFloat();
                        }
                        if(reader.readNextStartElement() && reader.name()=="Cadenza_di_fuoco")
                        {
                            cad=reader.readElementText().toInt();
                        }
                        if(reader.readNextStartElement() && reader.name()=="Doppia_canna")
                        {
                            dopcan=reader.readElementText().toInt();
                        }
                        try
                        {
                            Fucile_a_pompa *a=new Fucile_a_pompa(marca, costo, nome, disp, foto, cal, cad, dopcan);
                            app.push_back(a); //carico l'oggetto letto dal file XML
                            delete a;
                        }
                        catch(string s)
                        {
                            QMessageBox box(QMessageBox::Warning, "Errore in lettura", "Errore in lettura", QMessageBox::Ok);
                        }
                    }
                    else
                    {
                        if(classe=="Fucile a precisione")
                        {
                            if(reader.readNextStartElement() && reader.name()=="Calibro")
                            {
                                cal=reader.readElementText().toFloat();
                            }
                            if(reader.readNextStartElement() && reader.name()=="Cadenza_di_fuoco")
                            {
                                cad=reader.readElementText().toInt();
                            }
                            if(reader.readNextStartElement() && reader.name()=="Mirino")
                            {
                                mirino=reader.readElementText().toStdString();
                            }
                            if(reader.readNextStartElement() && reader.name()=="Silenziatore")
                            {
                                silenziatore=reader.readElementText().toInt();
                            }
                            try
                            {
                                Fucile_a_precisione *a=new Fucile_a_precisione(marca, costo, nome, disp, foto, cal, cad, mirino, silenziatore);
                                app.push_back(a); //carico l'oggetto letto dal file XML
                                delete a;
                            }
                            catch(string s)
                            {
                                QMessageBox box(QMessageBox::Warning, "Errore in lettura", "Errore in lettura", QMessageBox::Ok);
                            }
                        }
                        else
                        {
                            if(classe=="Elettrica")
                            {
                                if(reader.readNextStartElement() && reader.name()=="Ricaricabile")
                                {
                                    ric=reader.readElementText().toInt();
                                }
                                if(reader.readNextStartElement() && reader.name()=="Voltaggio")
                                {
                                    volt=reader.readElementText().toFloat();
                                }
                                if(reader.readNextStartElement() && reader.name()=="Amperaggio")
                                {
                                    amp=reader.readElementText().toFloat();
                                }
                                if(reader.readNextStartElement() && reader.name()=="Durata_scarica")
                                {
                                    durata=reader.readElementText().toFloat();
                                }
                                if(reader.readNextStartElement() && reader.name()=="Distanza_massima")
                                {
                                    distanza=reader.readElementText().toInt();
                                }
                                try
                                {
                                    Elettrica *a=new Elettrica(marca, costo, nome, disp, foto, ric, volt, amp, durata, distanza);
                                    app.push_back(a); //carico l'oggetto letto dal file XML
                                    delete a;
                                }
                                catch(string s)
                                {
                                    QMessageBox box(QMessageBox::Warning, "Errore in lettura", "Errore in lettura", QMessageBox::Ok);
                                }
                            }
                            else
                            {
                                if(classe=="Gas OC")
                                {
                                    if(reader.readNextStartElement() && reader.name()=="Ricaricabile")
                                    {
                                        ric=reader.readElementText().toInt();
                                    }
                                    if(reader.readNextStartElement() && reader.name()=="Capacita")
                                    {
                                        cap=reader.readElementText().toFloat();
                                    }
                                    try
                                    {
                                        Gas_OC *a=new Gas_OC(marca, costo, nome, disp, foto, ric, cap);
                                        app.push_back(a); //carico l'oggetto letto dal file XML
                                        delete a;
                                    }
                                    catch(string s)
                                    {
                                        QMessageBox box(QMessageBox::Warning, "Errore in lettura", "Errore in lettura", QMessageBox::Ok);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
               reader.skipCurrentElement();//salta l'elemento letto se il tag non è corretto
            }
            reader.readNextStartElement();//il ciclo ha finito di leggere tutti gli attributi dell'oggetto arma, legge </Arma>, il ciclo prosegue leggendo il successivo tag <Arma> se esiste altrimenti si ferma
        }
    }
    qfile.close();//chiude il file
    return app;// ritorna il container
}


void xmlio::write(const Qontainer<DPtr<Arma>>& Qont) const
{

    QSaveFile sfile(QString::fromStdString(file));
    if(!sfile.open(QIODevice::WriteOnly)) //apro in scrittura il file XML
    {
        throw std::exception();
    }
    QXmlStreamWriter writer(&sfile);
    writer.setAutoFormatting(true); // Per leggibilità del file XML
    writer.writeStartDocument();    // Scrive le intestazioni XML
    writer.writeComment("Non modificare!");
    writer.writeStartElement("root");//apre tag principale
    Qontainer<DPtr<Arma> >::const_iterator cit=Qont.begin();
    while(cit != Qont.end())
    {  

        const Arma *app=(*cit)->clone();
        writer.writeStartElement("Arma");//apre tag <Arma>
        writer.writeAttribute("Classe", QString::fromStdString(app->classe()));//imposta a <Arma> un attributo(Classe)
        writer.writeStartElement("Marca");
        writer.writeCharacters(QString::fromStdString((app->getMarca())));
        writer.writeEndElement();
        writer.writeStartElement("Costo");
        writer.writeCharacters(QString::fromStdString(std::to_string(static_cast<int>(app->getCosto()))));
        writer.writeEndElement();
        writer.writeStartElement("Nome");
        writer.writeCharacters(QString::fromStdString((*cit)->getNome()));
        writer.writeEndElement();
        writer.writeStartElement("Disponibilita");
        writer.writeCharacters(QString::fromStdString(std::to_string(app->getDisponibilita())));
        writer.writeEndElement();
        writer.writeStartElement("Foto");
        writer.writeCharacters(QString::fromStdString((app->getFoto())));
        writer.writeEndElement();
        if((*cit)->Armadafuoco())
        {
            writer.writeStartElement("Calibro");
            writer.writeCharacters(QString::fromStdString(std::to_string(static_cast<int>(static_cast<const Arma_da_fuoco*>(app)->getCalibro()))));
            writer.writeEndElement();
            writer.writeStartElement("Cadenza_di_fuoco");
            writer.writeCharacters(QString::fromStdString(std::to_string(static_cast<const Arma_da_fuoco*>(app)->getCad())));
            writer.writeEndElement();
            if((*cit)->classe()=="Pistola")
            {
                writer.writeStartElement("Torcia");
                writer.writeCharacters(QString::fromStdString(std::to_string(static_cast<const Pistola*>(app)->getTorcia())));
                writer.writeEndElement();
                writer.writeStartElement("Silenziatore");
                writer.writeCharacters(QString::fromStdString(std::to_string(static_cast<const Pistola*>(app)->getSilenziatore())));
                writer.writeEndElement();
                writer.writeStartElement("Automatica");
                writer.writeCharacters(QString::fromStdString(std::to_string(static_cast<const Pistola*>(app)->getAutomatica())));
                writer.writeEndElement();
            }
            else
            {
                if((*cit)->classe()=="Fucile a pompa")
                {
                    writer.writeStartElement("Doppia_canna");
                    writer.writeCharacters(QString::fromStdString(std::to_string(static_cast<const Fucile_a_pompa*>(app)->getDoppia_canna())));
                    writer.writeEndElement();
                }
                else
                {
                    if((*cit)->classe()=="Fucile a precisione")
                    {
                        writer.writeStartElement("Mirino");
                        writer.writeCharacters(QString::fromStdString(static_cast<const Fucile_a_precisione*>(app)->getMirino()));
                        writer.writeEndElement();
                        writer.writeStartElement("Silenziatore");
                        writer.writeCharacters(QString::fromStdString(std::to_string(static_cast<const Fucile_a_precisione*>(app)->getSilenziatore())));
                        writer.writeEndElement();
                    }
                }
            }
        }
        else
        {
            writer.writeStartElement("Ricaricabile");
            writer.writeCharacters(QString::fromStdString(std::to_string(static_cast<const Arma_non_letale*>(app)->GetRicaricabile())));
            writer.writeEndElement();
            if((*cit)->classe()=="Elettrica")
            {
                writer.writeStartElement("Voltaggio");
                writer.writeCharacters(QString::fromStdString(std::to_string(static_cast<int>(static_cast<const Elettrica*>(app)->getVoltaggio()))));
                writer.writeEndElement();
                writer.writeStartElement("Amperaggio");
                writer.writeCharacters(QString::fromStdString(std::to_string(static_cast<int>(static_cast<const Elettrica*>(app)->getAmperaggio()))));
                writer.writeEndElement();
                writer.writeStartElement("Durata_scarica");
                writer.writeCharacters(QString::fromStdString(std::to_string(static_cast<int>(static_cast<const Elettrica*>(app)->getDurata_scarica()))));
                writer.writeEndElement();
                writer.writeStartElement("Distanza_massima");
                writer.writeCharacters(QString::fromStdString(std::to_string(static_cast<const Elettrica*>(app)->getDistanza_max())));
                writer.writeEndElement();
            }
            else
            {
                if((*cit)->classe()=="Gas OC")
                {
                    writer.writeStartElement("Capacita");
                    writer.writeCharacters(QString::fromStdString(std::to_string(static_cast<int>(static_cast<const Gas_OC*>(app)->getCapacita()))));
                    writer.writeEndElement();
                }
            }
        }
        writer.writeEndElement();//chiude tag </Arma>
        if(writer.hasError())//se avviene un errore esci
        {
            throw std::exception();
        }
        cit++;
        delete app;
    }


    writer.writeEndElement();  // chiusura tag </root>
    writer.writeEndDocument();  // chiude eventuali tag lasciati aperti e aggiunge una riga vuota alla fine
    sfile.commit(); // Scrive il file temporaneo su disco
}
