#include "fucile_a_pompa.h"

Fucile_a_pompa::Fucile_a_pompa(const string &m, float c, const string & n, bool disp, const string& f, float cal, int cad, bool dc): Arma_da_fuoco(m,c,n,disp,f,cal,cad), doppia_canna(dc)
{}

Fucile_a_pompa* Fucile_a_pompa::clone() const
{
    return new Fucile_a_pompa(*this);
}

string Fucile_a_pompa::classe() const
{
    return string("Fucile a pompa");
}

float Fucile_a_pompa::CalcolaCosto() const
{
    if(doppia_canna)
    {
        return Arma_da_fuoco::CalcolaCosto()+getCosto()+SovraPrezzoDoppiaCanna;
    }
    return Arma_da_fuoco::CalcolaCosto()+getCosto();
}

bool Fucile_a_pompa::getDoppia_canna() const
{
    return doppia_canna;
}

void Fucile_a_pompa::SetDoppia_canna(bool dc)
{
    doppia_canna=dc;
}

float Fucile_a_pompa::SovraPrezzoDoppiaCanna=100.0;
