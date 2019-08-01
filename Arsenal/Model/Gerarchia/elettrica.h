#ifndef ELETTRICA_H
#define ELETTRICA_H
#include "arma_non_letale.h"

class Elettrica:public Arma_non_letale
{
private:
    static float SovraPrezzo;
    static float SovraPrezzoDistanza;
    float voltaggio;
    float amperaggio;
    float durata_scarica;
    int distanza_max;

public:
    Elettrica(const string& ="Sconosciuto", float=0.0, const string& ="Sconosciuto", bool=false, const string& ="Sconosciuto", bool=false, float=0.0, float=0.0, float=0.0, int=0);

    float getVoltaggio() const;
    float getAmperaggio() const;
    float getDurata_scarica() const;
    int getDistanza_max() const;

    virtual Elettrica* clone() const override;
    virtual string classe() const override;
    virtual float CalcolaCosto() const override;

    void setVoltaggio(float=0.0);
    void setAmperaggio(float=0.0);
    void setDurata(float=0.0);
    void setDistanza(int=0);
};

#endif // ELETTRICA_H
