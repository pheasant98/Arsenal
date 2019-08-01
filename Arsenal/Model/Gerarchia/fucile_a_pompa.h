#ifndef FUCILE_A_POMPA_H
#define FUCILE_A_POMPA_H
#include "arma_da_fuoco.h"

class Fucile_a_pompa: public Arma_da_fuoco
{
private:
    static float SovraPrezzoDoppiaCanna;
    bool doppia_canna;

public:
    Fucile_a_pompa(const string& ="Sconosciuto", float=0, const string& ="Sconosciuto", bool=false, const string& ="Sconosciuto", float =0.0, int=0, bool=false);

    virtual Fucile_a_pompa* clone() const override;
    virtual string classe() const override;
    virtual float CalcolaCosto() const override;
    bool getDoppia_canna() const;

    void SetDoppia_canna(bool =false);

};

#endif // FUCILE_A_POMPA_H
