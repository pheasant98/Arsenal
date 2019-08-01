#include "fucile_a_precisione.h"

Fucile_a_precisione::Fucile_a_precisione(const string &m, float c, const string & n, bool disp, const string& f, float cal, int cad, const string & mir, bool sil): Arma_da_fuoco(m,c,n,disp,f,cal,cad), mirino(mir), silenziatore(sil)
{
    if(!mirino.compare("laser") && !mirino.compare("telescopico") && !mirino.compare("termico"))
    {
        mirino="telescopico";
    }
}

Fucile_a_precisione* Fucile_a_precisione::clone() const
{
    return new Fucile_a_precisione(*this);
}

string Fucile_a_precisione::classe() const
{
    return string("Fucile a precisione");
}

float Fucile_a_precisione::CalcolaCosto() const
{
    float c=getCosto()+SovraPrezzo;
    if(silenziatore)
    {
        c=c+SovraPrezzoSilenziatore;
    }
    if(mirino=="laser")
    {
        c=c+SovraPrezzoTipoMirino;
    }
    if(mirino=="termico")
    {
        c=c+SovraPrezzoTipoMirino*2;
    }
    return Arma_da_fuoco::CalcolaCosto()+c;
}

string Fucile_a_precisione::getMirino() const
{
    return mirino;
}

bool Fucile_a_precisione::getSilenziatore() const
{
    return silenziatore;
}

void Fucile_a_precisione::setMirino(const string & mir)
{
    if(!mir.compare("laser") && !mir.compare("telescopico") && !mir.compare("termico"))
    {
        mirino="laser";
    }
    else
    {
        mirino=mir;
    }
}

void Fucile_a_precisione::setSilenziatore(bool sil)
{
    silenziatore=sil;
}

float Fucile_a_precisione::SovraPrezzo=100.0;
float Fucile_a_precisione::SovraPrezzoSilenziatore=30.0;
float Fucile_a_precisione::SovraPrezzoTipoMirino=50.0;
