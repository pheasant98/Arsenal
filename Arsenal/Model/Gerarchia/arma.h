#ifndef ARMA_H
#define ARMA_H

#include <string>
#include <iostream>
#include <QDebug>

using std::string;

class Arma
{
private:
    string marca;
    float costo;
    string nome;
    bool disponibilita;
    string foto;
public:
    Arma(const string& ="Sconosciuto", float=0.0, const string& ="Sconosciuto", bool=false, const string& ="Sconosciuto");

    virtual Arma* clone() const=0;
    virtual bool Armadafuoco() const =0;
    virtual string classe() const =0;
    virtual float CalcolaCosto() const = 0;
    virtual ~Arma() =default;

    //Get
    string getMarca() const;
    float getCosto() const;
    string getNome() const;
    bool getDisponibilita() const;
    string getFoto() const;

    //Set
    void setMarca(const string& ="Sconosciuto");
    void setCosto(float =0.0);
    void setNome(const string& ="Sconosciuto");
    void setDisponibilita(bool = true);  
    void setFoto(const string &value ="Sconosciuto");
};

#endif // ARMA_H
