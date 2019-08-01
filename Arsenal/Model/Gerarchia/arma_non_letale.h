#ifndef ARMA_NON_LETALE_H
#define ARMA_NON_LETALE_H
#include "arma.h"

class Arma_non_letale:public Arma
{
private:
    bool ricaricabile;
public:
    Arma_non_letale(const string& ="Sconosciuto", float =0.0, const string& ="Sconosciuto", bool=false, const string& ="Sconosciuto", bool=false);

    bool GetRicaricabile() const;
    virtual bool Armadafuoco() const final override;

    void SetRicaricabile(bool=false);

};

#endif // ARMA_NON_LETALE_H
