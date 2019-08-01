#ifndef QLISTMODELADAPTER_H
#define QLISTMODELADAPTER_H

#include "model.h"
#include "Model/Gerarchia/arma.h"
#include "Model/Gerarchia/pistola.h"
#include "Model/Gerarchia/fucile_a_pompa.h"
#include "Model/Gerarchia/fucile_a_precisione.h"
#include "Model/Gerarchia/elettrica.h"
#include "Model/Gerarchia/gas_oc.h"
#include "View/linserisci.h"
#include "View/gestioneimg.h"
#include "View/modifica.h"
#include "View/visualizzaoggetto.h"
#include <QFont>
#include <iostream>
#include <QAbstractTableModel>

using std::string;
class QGestioneTabella: public QAbstractTableModel
{
private:
     Model* model;//usato per poter fare le operazioni nel container
     const LInserisci* inserisci; //mi serve per poter aggiungere il nuovo oggetto alla tabella
public:

    QGestioneTabella(QObject* = nullptr, const LInserisci* = nullptr);
    ~QGestioneTabella() override;
    int rowCount(const QModelIndex& = QModelIndex()) const override;
    int columnCount(const QModelIndex& = QModelIndex()) const override;
    QVariant headerData(int, Qt::Orientation, int) const override;
    QVariant data(const QModelIndex&, int = Qt::DisplayRole) const override;
    bool insertRows(int, int = 1, const QModelIndex& = QModelIndex()) override;
    bool removeRows(int, int = 1, const QModelIndex& = QModelIndex()) override;
    void mostraV(const QModelIndex&) const;
    void mostraM(const QModelIndex&);
    bool matcha(unsigned int, const QRegExp&, const QString&, bool) const;
    void salvaNelFile(const string&) const;
    void caricaDalFile(const string&);
    float totale() const;


};

#endif // QLISTMODELADAPTER_H
