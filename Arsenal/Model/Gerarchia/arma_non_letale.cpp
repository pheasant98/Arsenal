#include "arma_non_letale.h"

Arma_non_letale::Arma_non_letale(const string& m, float c, const string& n, bool disp, const string& f, bool ric): Arma(m,c,n, disp,f), ricaricabile(ric){}

bool Arma_non_letale::Armadafuoco() const
{
    return false;
}

bool Arma_non_letale::GetRicaricabile() const
{
    return ricaricabile;
}

void Arma_non_letale::SetRicaricabile(bool ric)
{
    ricaricabile=ric;
}


