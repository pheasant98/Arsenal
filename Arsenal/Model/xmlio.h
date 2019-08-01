#ifndef XMLIO_H
#define XMLIO_H

#include "Model/Gerarchia/arma.h"
#include "Model/Gerarchia/pistola.h"
#include "Model/Gerarchia/fucile_a_pompa.h"
#include "Model/Gerarchia/fucile_a_precisione.h"
#include "Model/Gerarchia/elettrica.h"
#include "Model/Gerarchia/gas_oc.h"
#include "qontainer.h"
#include "dptr.h"
#include <QFile>
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QMessageBox>
#include <QDebug>

using std::string;

class xmlio
{
private:
    string file;
public:
    xmlio(const string&);
    Qontainer<DPtr<Arma>> read() const;
    void write(const Qontainer<DPtr<Arma>>&) const;  
};

#endif // XMLIO_H
