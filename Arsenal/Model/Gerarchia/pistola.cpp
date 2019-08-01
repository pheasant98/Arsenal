#include "pistola.h"

Pistola::Pistola(const string &m, float c, const string & n, bool disp, const string& f, float cal, int cad, bool tor, bool sil, bool aut): Arma_da_fuoco(m,c,n,disp,f,cal,cad), torcia(tor), silenziatore(sil), automatica(aut)
{}


Pistola* Pistola::clone() const
{
    return new Pistola(*this);
}

string Pistola::classe() const
{
    return string("Pistola");
}

float Pistola::CalcolaCosto() const
{
    float c=getCosto();
    if(torcia)
    {
       c=c+SovraPrezzoTorcia;
    }
    if(silenziatore)
    {
       c=c+SovraPrezzoSilenziatore;
    }
    return Arma_da_fuoco::CalcolaCosto()+c;
}

bool Pistola::getTorcia() const
{
    return torcia;
}

bool Pistola::getSilenziatore() const
{
    return silenziatore;
}

bool Pistola::getAutomatica() const
{
    return automatica;
}

void Pistola::setTorcia(bool tor)
{
    torcia=tor;
}
void Pistola::setSilenziatore(bool sil)
{
    silenziatore=sil;
}

void Pistola::setAutomatica(bool aut)
{
    automatica=aut;
}

float Pistola::SovraPrezzoSilenziatore=40.0;
float Pistola::SovraPrezzoTorcia=30.0;
