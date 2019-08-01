#ifndef PISTOLA_H
#define PISTOLA_H
#include "arma_da_fuoco.h"


class Pistola:public Arma_da_fuoco
{
private:
    bool torcia;
    bool silenziatore;
    bool automatica;
    static float SovraPrezzoTorcia;
    static float SovraPrezzoSilenziatore;

public:
    Pistola(const string& ="Sconosciuto", float=0, const string& ="Sconosciuto", bool=false, const string& ="Sconosciuto", float =0.0, int=0, bool =false, bool =false, bool =false);

    virtual Pistola* clone() const override;
    virtual string classe() const override;
    virtual float CalcolaCosto() const override;

    bool getTorcia() const;
    bool getSilenziatore() const;
    bool getAutomatica() const;

    void setTorcia(bool=false);
    void setSilenziatore(bool=false);
    void setAutomatica(bool=false);
};

#endif // PISTOLA_H
