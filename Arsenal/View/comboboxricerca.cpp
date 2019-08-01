#include "comboboxricerca.h"

comboboxRicerca::comboboxRicerca(QWidget *parent): QComboBox(parent)
{
    addItem("Marca");
    addItem("Costo");
    addItem("Nome");
    addItem("Disponibilita");
    addItem("Classe");
    addItem("Calibro");
    addItem("Cadenza di fuoco");
    addItem("Ricaricabile");
    addItem("Torcia");
    addItem("Silenziatore");
    addItem("Automatica");
    addItem("Doppia canna");
    addItem("Mirino");
    addItem("Voltaggio");
    addItem("Amperaggio");
    addItem("Durata scarica");
    addItem("Distanza massima");
    addItem("Capacita");
}
