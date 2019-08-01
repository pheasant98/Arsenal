#ifndef GAS_OC_H
#define GAS_OC_H

#include"arma_non_letale.h"


class Gas_OC: public Arma_non_letale
{
private:
    float capacita;

public:
    Gas_OC(const string& ="Sconosciuto", float =0.0, const string& ="Sconosciuto", bool=false, const string& ="Sconosciuto", bool=false, float=0.0);

    virtual Gas_OC* clone() const override;
    virtual string classe() const override;
    virtual float CalcolaCosto() const override;

    float getCapacita() const;

    void setCapacita(float=0.0);

};

#endif // GAS_OC_H
