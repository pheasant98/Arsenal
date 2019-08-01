#include "model.h"


void Model::SalvaFile(const string &file) const
{
    xmlio xmlIO(file);
    xmlIO.write(Qcont);
}

void Model::CaricaFile(const string& file)
{
    xmlio xmlIO(file);
    Qcont = xmlIO.read();
}

void Model::Aggiungi(Arma* a)
{
    Qcont.push_back(DPtr<Arma>(a));
   // delete a;
}
void Model::Rimuovi(unsigned int i)
{
    Qcont.elimina(Qcont.begin()+i);
}
Arma* Model::getArma(unsigned int i) const
{
    return Qcont[i].operator ->();
}

Arma* Model::operator[](unsigned int i) const
{   
    return Qcont[i].operator ->();
}

bool Model::RicercaMinore(unsigned int ind, float i, const string& filtro) const
{
    Arma* it=Qcont[ind].operator ->();
    if(filtro == "Costo")
    {
        if(it->CalcolaCosto()<=i)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(filtro== "Calibro")
        {
            if(it->Armadafuoco())
            {
                if(static_cast<Arma_da_fuoco*>(it)->getCalibro()<=i)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(filtro=="Cadenza di fuoco")
            {
                if(it->Armadafuoco())
                {
                    if(static_cast<Arma_da_fuoco*>(it)->getCad()<=i)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(filtro== "Voltaggio")
                {
                    if(it->classe()=="Elettrica")
                    {
                        if(static_cast<Elettrica*>(it)->getVoltaggio()<=i)
                        {
                              return true;
                        }
                        else
                        {
                              return false;
                        }
                    }
                    else
                    {
                           return false;
                    }
                }
                else
                {
                    if(filtro== "Amperaggio")
                    {
                        if(it->classe()=="Elettrica")
                        {
                            if(static_cast<Elettrica*>(it)->getAmperaggio()<=i)
                            {
                                  return true;
                            }
                            else
                            {
                                  return false;
                            }
                        }
                        else
                        {
                               return false;
                        }
                    }
                    else
                    {
                        if(filtro== "Durata scarica")
                        {
                            if(it->classe()=="Elettrica")
                            {
                                if(static_cast<Elettrica*>(it)->getDurata_scarica()<=i)
                                {
                                      return true;
                                }
                                else
                                {
                                      return false;
                                }
                            }
                            else
                            {
                                   return false;
                            }
                        }
                        else
                        {
                                if(filtro== "Capacita")
                                {
                                    if(it->classe()=="Gas OC")
                                    {
                                        if(static_cast<Gas_OC*>(it)->getCapacita()<=i)
                                        {
                                              return true;
                                        }
                                        else
                                        {
                                              return false;
                                        }
                                    }
                                    else
                                    {
                                           return false;
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

bool Model::RicercaMinore(unsigned int ind, int i, const string& filtro) const
{
    Arma* it=Qcont[ind].operator ->();
    if(filtro== "Distanza massima")
    {
        if(it->classe()=="Elettrica")
        {
            if(static_cast<Elettrica*>(it)->getDistanza_max()<=i)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool Model::RicercaMaggiore(unsigned int ind, float i, const string& filtro) const
{
    Arma* it=Qcont[ind].operator ->();//estraggo l'oggetto che mi interessa verificare
    if(filtro == "Costo")
    {
        if(it->CalcolaCosto()>=i)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(filtro== "Calibro")
        {
            if(it->Armadafuoco())
            {
                if(static_cast<Arma_da_fuoco*>(it)->getCalibro()>=i)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(filtro=="Cadenza di fuoco")
            {
                if(it->Armadafuoco())
                {
                    if(static_cast<Arma_da_fuoco*>(it)->getCad()>=i)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(filtro== "Voltaggio")
                {
                    if(it->classe()=="Elettrica")
                    {
                        if(static_cast<Elettrica*>(it)->getVoltaggio()>=i)
                        {
                              return true;
                        }
                        else
                        {
                              return false;
                        }
                    }
                    else
                    {
                           return false;
                    }
                }
                else
                {
                    if(filtro== "Amperaggio")
                    {
                        if(it->classe()=="Elettrica")
                        {
                            if(static_cast<Elettrica*>(it)->getAmperaggio()>=i)
                            {
                                  return true;
                            }
                            else
                            {
                                  return false;
                            }
                        }
                        else
                        {
                               return false;
                        }
                    }
                    else
                    {
                        if(filtro== "Durata scarica")
                        {
                            if(it->classe()=="Elettrica")
                            {
                                if(static_cast<Elettrica*>(it)->getDurata_scarica()>=i)
                                {
                                      return true;
                                }
                                else
                                {
                                      return false;
                                }
                            }
                            else
                            {
                                   return false;
                            }
                        }
                        else
                        {
                                if(filtro== "Capacita")
                                {
                                    if(it->classe()=="Gas OC")
                                    {
                                        if(static_cast<Gas_OC*>(it)->getCapacita()>=i)
                                        {
                                              return true;
                                        }
                                        else
                                        {
                                              return false;
                                        }
                                    }
                                    else
                                    {
                                           return false;
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

bool Model::RicercaMaggiore(unsigned int ind, int i, const string& filtro) const
{
    Arma* it=Qcont[ind].operator ->();
    if(filtro== "Distanza massima")
    {
        if(it->classe()=="Elettrica")
        {
            if(static_cast<Elettrica*>(it)->getDistanza_max()>=i)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
unsigned int Model::Dimensione() const
{
    return Qcont.getDimensione();
}

float Model::TotCosto() const
{
   float totale=0.0;
   auto cit=Qcont.begin();
   while(cit != Qcont.end())
   {
       totale=totale+(*cit)->CalcolaCosto();
       cit++;
   }
   return totale;
}
