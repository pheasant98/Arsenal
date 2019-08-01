#include "arma.h"

Arma::Arma(const string& m, float c, const string& n, bool disp, const string& f): marca(m), costo(c), nome(n), disponibilita(disp), foto(f){}

float Arma::getCosto() const
{
    return costo;
}
string Arma::getMarca() const
{
    return marca;
}
string Arma::getNome() const
{
    return nome;
}
bool Arma::getDisponibilita() const
{
    return disponibilita;
}
void Arma::setCosto(float c)
{
    costo=c;
}
void Arma::setMarca(const string& m)
{
    marca=m;
}
void Arma::setNome(const string& n)
{
    nome=n;
}
void Arma::setDisponibilita(bool disp)
{
    disponibilita=disp;
}
string Arma::getFoto() const
{
    return foto;
}
void Arma::setFoto(const string &value)
{
    foto = value;
}
