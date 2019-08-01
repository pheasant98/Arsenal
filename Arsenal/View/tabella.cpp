#include "tabella.h"

Tabella::Tabella(QWidget* parent) : QTableView(parent)
{
    setSelectionBehavior(QAbstractItemView::SelectRows);
}
QSize Tabella::sizeHint() const //imposta dimensione della tabella
{
    return QSize(1200, 700);
}

void Tabella::DimCol()//imposta dimensione delle colonne principali
{
    setColumnWidth(0,200);
    setColumnWidth(1,200);
    setColumnWidth(2,200);
    setColumnWidth(3,200);
    setColumnWidth(4,200);
}

void Tabella::Visible(int i)//in base al parametro i visualizza la giusta colonna
{
    setColumnWidth(i,200);
    switch (i)
    {
    case 0:
        setColumnHidden(5,true);
        setColumnHidden(6,true);
        setColumnHidden(7,true);
        setColumnHidden(8,true);
        setColumnHidden(9,true);
        setColumnHidden(10,true);
        setColumnHidden(11,true);
        setColumnHidden(12,true);
        setColumnHidden(13,true);
        setColumnHidden(14,true);
        setColumnHidden(15,true);
        setColumnHidden(16,true);
        setColumnHidden(17,true);
        break;
    case 1:
        setColumnHidden(5,true);
        setColumnHidden(6,true);
        setColumnHidden(7,true);
        setColumnHidden(8,true);
        setColumnHidden(9,true);
        setColumnHidden(10,true);
        setColumnHidden(11,true);
        setColumnHidden(12,true);
        setColumnHidden(13,true);
        setColumnHidden(14,true);
        setColumnHidden(15,true);
        setColumnHidden(16,true);
        setColumnHidden(17,true);
        break;
    case 2:
        setColumnHidden(5,true);
        setColumnHidden(6,true);
        setColumnHidden(7,true);
        setColumnHidden(8,true);
        setColumnHidden(9,true);
        setColumnHidden(10,true);
        setColumnHidden(11,true);
        setColumnHidden(12,true);
        setColumnHidden(13,true);
        setColumnHidden(14,true);
        setColumnHidden(15,true);
        setColumnHidden(16,true);
        setColumnHidden(17,true);
        break;
    case 3:
        setColumnHidden(5,true);
        setColumnHidden(6,true);
        setColumnHidden(7,true);
        setColumnHidden(8,true);
        setColumnHidden(9,true);
        setColumnHidden(10,true);
        setColumnHidden(11,true);
        setColumnHidden(12,true);
        setColumnHidden(13,true);
        setColumnHidden(14,true);
        setColumnHidden(15,true);
        setColumnHidden(16,true);
        setColumnHidden(17,true);
        break;
    case 4:
        setColumnHidden(5,true);
        setColumnHidden(6,true);
        setColumnHidden(7,true);
        setColumnHidden(8,true);
        setColumnHidden(9,true);
        setColumnHidden(10,true);
        setColumnHidden(11,true);
        setColumnHidden(12,true);
        setColumnHidden(13,true);
        setColumnHidden(14,true);
        setColumnHidden(15,true);
        setColumnHidden(16,true);
        setColumnHidden(17,true);
        break;
    case 5:
        setColumnHidden(5,false);
        setColumnHidden(6,true);
        setColumnHidden(7,true);
        setColumnHidden(8,true);
        setColumnHidden(9,true);
        setColumnHidden(10,true);
        setColumnHidden(11,true);
        setColumnHidden(12,true);
        setColumnHidden(13,true);
        setColumnHidden(14,true);
        setColumnHidden(15,true);
        setColumnHidden(16,true);
        setColumnHidden(17,true);
        break;
    case 6:
        setColumnHidden(5,true);
        setColumnHidden(6,false);
        setColumnHidden(7,true);
        setColumnHidden(8,true);
        setColumnHidden(9,true);
        setColumnHidden(10,true);
        setColumnHidden(11,true);
        setColumnHidden(12,true);
        setColumnHidden(13,true);
        setColumnHidden(14,true);
        setColumnHidden(15,true);
        setColumnHidden(16,true);
        setColumnHidden(17,true);
        break;
    case 7:
        setColumnHidden(5,true);
        setColumnHidden(6,true);
        setColumnHidden(7,false);
        setColumnHidden(8,true);
        setColumnHidden(9,true);
        setColumnHidden(10,true);
        setColumnHidden(11,true);
        setColumnHidden(12,true);
        setColumnHidden(13,true);
        setColumnHidden(14,true);
        setColumnHidden(15,true);
        setColumnHidden(16,true);
        setColumnHidden(17,true);
        break;
    case 8:
        setColumnHidden(5,true);
        setColumnHidden(6,true);
        setColumnHidden(7,true);
        setColumnHidden(8,false);
        setColumnHidden(9,true);
        setColumnHidden(10,true);
        setColumnHidden(11,true);
        setColumnHidden(12,true);
        setColumnHidden(13,true);
        setColumnHidden(14,true);
        setColumnHidden(15,true);
        setColumnHidden(16,true);
        setColumnHidden(17,true);
        break;
    case 9:
        setColumnHidden(5,true);
        setColumnHidden(6,true);
        setColumnHidden(7,true);
        setColumnHidden(8,true);
        setColumnHidden(9,false);
        setColumnHidden(10,true);
        setColumnHidden(11,true);
        setColumnHidden(12,true);
        setColumnHidden(13,true);
        setColumnHidden(14,true);
        setColumnHidden(15,true);
        setColumnHidden(16,true);
        setColumnHidden(17,true);
        break;
    case 10:
        setColumnHidden(5,true);
        setColumnHidden(6,true);
        setColumnHidden(7,true);
        setColumnHidden(8,true);
        setColumnHidden(9,true);
        setColumnHidden(10,false);
        setColumnHidden(11,true);
        setColumnHidden(12,true);
        setColumnHidden(13,true);
        setColumnHidden(14,true);
        setColumnHidden(15,true);
        setColumnHidden(16,true);
        setColumnHidden(17,true);
        break;
    case 11:
        setColumnHidden(5,true);
        setColumnHidden(6,true);
        setColumnHidden(7,true);
        setColumnHidden(8,true);
        setColumnHidden(9,true);
        setColumnHidden(10,true);
        setColumnHidden(11,false);
        setColumnHidden(12,true);
        setColumnHidden(13,true);
        setColumnHidden(14,true);
        setColumnHidden(15,true);
        setColumnHidden(16,true);
        setColumnHidden(17,true);
        break;
    case 12:
        setColumnHidden(5,true);
        setColumnHidden(6,true);
        setColumnHidden(7,true);
        setColumnHidden(8,true);
        setColumnHidden(9,true);
        setColumnHidden(10,true);
        setColumnHidden(11,true);
        setColumnHidden(12,false);
        setColumnHidden(13,true);
        setColumnHidden(14,true);
        setColumnHidden(15,true);
        setColumnHidden(16,true);
        setColumnHidden(17,true);
        break;
    case 13:
        setColumnHidden(5,true);
        setColumnHidden(6,true);
        setColumnHidden(7,true);
        setColumnHidden(8,true);
        setColumnHidden(9,true);
        setColumnHidden(10,true);
        setColumnHidden(11,true);
        setColumnHidden(12,true);
        setColumnHidden(13,false);
        setColumnHidden(14,true);
        setColumnHidden(15,true);
        setColumnHidden(16,true);
        setColumnHidden(17,true);
        break;
    case 14:
        setColumnHidden(5,true);
        setColumnHidden(6,true);
        setColumnHidden(7,true);
        setColumnHidden(8,true);
        setColumnHidden(9,true);
        setColumnHidden(10,true);
        setColumnHidden(11,true);
        setColumnHidden(12,true);
        setColumnHidden(13,true);
        setColumnHidden(14,false);
        setColumnHidden(15,true);
        setColumnHidden(16,true);
        setColumnHidden(17,true);
        break;
    case 15:
        setColumnHidden(5,true);
        setColumnHidden(6,true);
        setColumnHidden(7,true);
        setColumnHidden(8,true);
        setColumnHidden(9,true);
        setColumnHidden(10,true);
        setColumnHidden(11,true);
        setColumnHidden(12,true);
        setColumnHidden(13,true);
        setColumnHidden(14,true);
        setColumnHidden(15,false);
        setColumnHidden(16,true);
        setColumnHidden(17,true);
        break;
    case 16:
        setColumnHidden(5,true);
        setColumnHidden(6,true);
        setColumnHidden(7,true);
        setColumnHidden(8,true);
        setColumnHidden(9,true);
        setColumnHidden(10,true);
        setColumnHidden(11,true);
        setColumnHidden(12,true);
        setColumnHidden(13,true);
        setColumnHidden(14,true);
        setColumnHidden(15,true);
        setColumnHidden(16,false);
        setColumnHidden(17,true);
        break;
    case 17:
        setColumnHidden(5,true);
        setColumnHidden(6,true);
        setColumnHidden(7,true);
        setColumnHidden(8,true);
        setColumnHidden(9,true);
        setColumnHidden(10,true);
        setColumnHidden(11,true);
        setColumnHidden(12,true);
        setColumnHidden(13,true);
        setColumnHidden(14,true);
        setColumnHidden(15,true);
        setColumnHidden(16,true);
        setColumnHidden(17,false);
        break;
    default:
        break;
    }
}

void Tabella::mousePressEvent(QMouseEvent* e)//gestione del evento click del mause
{
     if (!indexAt(e->pos()).isValid())
     {
        clearSelection();
        selectionModel()->clearCurrentIndex();
    }
    QTableView::mousePressEvent(e);

}

