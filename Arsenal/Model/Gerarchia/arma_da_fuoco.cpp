#include "arma_da_fuoco.h"

Arma_da_fuoco::Arma_da_fuoco(const string& m, float c, const string& n, bool disp, const string& f, float cal, int cad):Arma(m,c,n, disp,f), calibro(cal), cadenza_di_fuoco(cad)
{}

bool Arma_da_fuoco::Armadafuoco() const
{
    return true;
}

float Arma_da_fuoco::CalcolaCosto() const
{
    float c=0.0;
    if(calibro>5.7)
    {
        c=c+(calibro-5.7)*SovraPrezzoCal;
    }
    if(cadenza_di_fuoco>1000)
    {
        c=c+(cadenza_di_fuoco/100)*SovraPrezzoCad;
    }
   return c;
}

float Arma_da_fuoco::getCalibro() const
{
    return calibro;
}

int Arma_da_fuoco::getCad() const
{
    return cadenza_di_fuoco;
}

void Arma_da_fuoco::setCalibro(float c)
{
    calibro=c;
}

void Arma_da_fuoco::setCad(int c)
{
    cadenza_di_fuoco=c;
}

float Arma_da_fuoco::SovraPrezzoCal=5.0;
float Arma_da_fuoco::SovraPrezzoCad=10.0;
