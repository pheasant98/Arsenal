#ifndef ARMA_DA_FUOCO_H
#define ARMA_DA_FUOCO_H
#include "arma.h"

class Arma_da_fuoco: public Arma
{
private:
    float calibro; //in mm
    int cadenza_di_fuoco; //num colpi per minuto
    static float SovraPrezzoCal;
    static float SovraPrezzoCad;

public:
    Arma_da_fuoco(const string& ="Sconosciuto", float=0, const string& ="Sconosciuto", bool=false, const string& ="Sconosciuto", float=0.0, int=0);
    virtual bool Armadafuoco() const final override;
    virtual float CalcolaCosto() const override;
    //Get
    float getCalibro() const;
    int getCad() const;


    //Set
    void setCalibro(float =0);
    void setCad(int=0);

};

#endif // ARMA_DA_FUOCO_H
