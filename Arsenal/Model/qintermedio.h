#ifndef QINTERMEDIO_H
#define QINTERMEDIO_H
#include <QComboBox>
#include <QSortFilterProxyModel>
#include "qgestionetabella.h"
#include "Model/Gerarchia/arma.h"
#include "QCheckBox"

class Qintermedio:public QSortFilterProxyModel
{  
private:
    QComboBox* cerca; //usato per avere il filtro della ricerca
    QCheckBox* Rcerca;//usato per avere il filtro della ricerca solo per bool e numeri
public:
    Qintermedio(QObject* = nullptr, QComboBox* =nullptr, QCheckBox* =nullptr);
    bool insertRows(int, int = 1, const QModelIndex& = QModelIndex()) override;
    void mostra(const QModelIndex&) const;
    void mostra2(const QModelIndex&) const;
    void Pulisci();
protected:
    bool filterAcceptsRow(int, const QModelIndex&) const override;
};


#endif // INTERMEDIO_H
