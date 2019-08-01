#ifndef MODEL_H
#define MODEL_H
#include "dptr.h"
#include "qontainer.h"
#include "xmlio.h"
#include "Gerarchia/arma.h"
#include "Gerarchia/arma_da_fuoco.h"
#include "Gerarchia/arma_non_letale.h"
#include "Model/Gerarchia/pistola.h"
#include "Model/Gerarchia/fucile_a_pompa.h"
#include "Model/Gerarchia/fucile_a_precisione.h"
#include "Model/Gerarchia/elettrica.h"
#include "Model/Gerarchia/gas_oc.h"
#include <algorithm>
#include <QDebug>
#include <iostream>

using std::string;

class Model
{
private:
   Qontainer<DPtr<Arma>> Qcont;
public:

    Model()=default;
    void SalvaFile(const string&) const;//salva le modifiche fatte nel file dove sono salvati i dati
    void CaricaFile(const string&);//carica il file dove sono salvati i dati
    void Aggiungi(Arma*); // inserisci un nuovo oggetto Arma
    void Rimuovi(unsigned int); // Rimuove un oggetto Arma che si trova in certo indice del contenitore(Qcont)
    Arma* getArma(unsigned int) const; //restituisce un puntatore a un oggetto arma in posizione indicata nel parametro di input
    Arma* operator[] (unsigned int) const; // utilizzando l' operatore di dereferenziazione restituisce un puntatore a un oggetto arma in posizione indicata nel parametro di input
    bool RicercaMinore(unsigned int, float, const string&) const;//verifica che un certo oggetto in una certa posizione sia minore di un certo valore in certo parametro
    bool RicercaMinore(unsigned int, int, const string& ) const;
    bool RicercaMaggiore(unsigned int, float, const string&) const;//verifica che un certo oggetto in una certa posizione sia maggiore di un certo valore in certo parametro
    bool RicercaMaggiore(unsigned int, int, const string&) const;
    unsigned int Dimensione() const;//ritorna la dimensione del conteiner
    float TotCosto() const; //calcola il costo totale
    ~Model()=default;
};

#endif // MODEL_H
