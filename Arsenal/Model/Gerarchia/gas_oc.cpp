#include "gas_oc.h"

Gas_OC::Gas_OC(const string& m, float c, const string& n, bool disp, const string& f, bool ric, float cap): Arma_non_letale(m,c,n,disp,f,ric), capacita(cap){}

Gas_OC* Gas_OC::clone() const
{
    return new Gas_OC(*this);
}

string Gas_OC::classe() const
{
    return string("Gas OC");
}

float Gas_OC::CalcolaCosto() const
{
    return getCosto();
}

float Gas_OC::getCapacita() const
{
    return capacita;
}

void Gas_OC::setCapacita(float c)
{
    capacita=c;
}
