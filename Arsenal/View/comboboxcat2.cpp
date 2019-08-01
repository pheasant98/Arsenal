#include "comboboxcat2.h"

comboboxCat2::comboboxCat2(QWidget *parent)
    : QComboBox(parent)
{
    addItem("");
    addItem("Elettrica");
    addItem("GAS OC");
}

