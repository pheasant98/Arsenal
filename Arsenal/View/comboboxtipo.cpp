#include "comboboxtipo.h"

comboboxTipo::comboboxTipo(QWidget *parent)
    : QComboBox(parent)
{
    addItem("");
    addItem("Arma da fuoco");
    addItem("Arma non letale");
}

