#include "qintermedio.h"

Qintermedio::Qintermedio(QObject *parent, QComboBox *c, QCheckBox *r):  QSortFilterProxyModel(parent), cerca(c), Rcerca(r) {}

bool Qintermedio::insertRows(int inizio, int c, const QModelIndex& parent)//inserimento, ritorna true se l'inserimento è avvenuto correttamente
{
    bool result = sourceModel()->insertRows(inizio, c, parent);
    invalidateFilter();
    return result;
}

bool Qintermedio::filterAcceptsRow(int riga, const QModelIndex&) const //ritorna true se l'oggetto matcha, usato per la ricerca
{
    return static_cast<QGestioneTabella*>(sourceModel())->matcha(static_cast<unsigned int>(riga), filterRegExp(), cerca->currentText(), Rcerca->isChecked());
}

void Qintermedio::mostra(const QModelIndex& i) const //mostra la finestra per la modifica
{
    QModelIndex indice = mapToSource(i);
    static_cast<QGestioneTabella*>(sourceModel())->mostraM(indice);
}

void Qintermedio::mostra2(const QModelIndex& i) const// mostra la finestra per la visualizza dettagli
{
    QModelIndex indice = mapToSource(i);
    static_cast<QGestioneTabella*>(sourceModel())->mostraV(indice);
}

void Qintermedio::Pulisci() //pulisce la tabella
{
    while(rowCount())
    {
        removeRows(0,1);
    }
}

