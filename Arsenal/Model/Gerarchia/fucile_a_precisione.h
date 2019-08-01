#ifndef FUCILE_A_PRECISIONE_H
#define FUCILE_A_PRECISIONE_H

#include "arma_da_fuoco.h"

class Fucile_a_precisione: public Arma_da_fuoco
{
private:
    string mirino;
    static float SovraPrezzo;
    static float SovraPrezzoTipoMirino;
    static float SovraPrezzoSilenziatore;
    bool silenziatore;

public:
    Fucile_a_precisione(const string& ="Sconosciuto", float=0, const string& ="Sconosciuto", bool=false, const string& ="Sconosciuto", float =0.0, int=0, const string& ="Standard", bool=false);

    virtual Fucile_a_precisione* clone() const override;
    virtual string classe() const override;
    virtual float CalcolaCosto() const override;

    string getMirino() const;
    bool getSilenziatore() const;

    void setMirino(const string& ="telescopico");
    void setSilenziatore(bool =false);
};

#endif // FUCILE_A_PRECISIONE_H
