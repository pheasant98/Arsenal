#include "comboboxmirino.h"

comboboxMirino::comboboxMirino(QWidget *parent)
    : QComboBox(parent)
{
    addItem("");
    addItem("laser");
    addItem("telescopico");
    addItem("termico");
}

