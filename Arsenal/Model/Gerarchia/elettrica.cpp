#include "elettrica.h"

Elettrica::Elettrica(const std::string & m, float c, const std::string & n, bool disp, const string& f, bool ric, float v, float a, float dur, int dist): Arma_non_letale(m,c,n,disp,f,ric), voltaggio(v), amperaggio(a), durata_scarica(dur), distanza_max(dist)
{}

Elettrica* Elettrica::clone() const
{
    return new Elettrica(*this);
}

string Elettrica::classe() const
{
    return string("Elettrica");
}

float Elettrica::CalcolaCosto() const
{
    float c=getCosto()+SovraPrezzo;
    if(distanza_max>=5)
    {
        c=c+SovraPrezzoDistanza*distanza_max;
    }
    return c;
}

float Elettrica::getVoltaggio() const
{
    return voltaggio;
}

float Elettrica::getAmperaggio() const
{
    return amperaggio;
}

float Elettrica::getDurata_scarica() const
{
    return durata_scarica;
}

int Elettrica::getDistanza_max() const
{
    return distanza_max;
}

void Elettrica::setAmperaggio(float a)
{
    amperaggio=a;
}
void Elettrica::setVoltaggio(float v)
{
    voltaggio=v;
}
void Elettrica::setDurata(float dur)
{
    durata_scarica=dur;
}
void Elettrica::setDistanza(int dist)
{
    distanza_max=dist;
}

float Elettrica::SovraPrezzo=50.0;
float Elettrica::SovraPrezzoDistanza=20.0;
