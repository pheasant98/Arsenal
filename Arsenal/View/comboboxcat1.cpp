#include "comboboxcat1.h"

comboboxCat1::comboboxCat1(QWidget *parent)
    : QComboBox(parent)
{
    addItem("");
    addItem("Pistola");
    addItem("Fucile a pompa");
    addItem("Fucile a precisione");
}

