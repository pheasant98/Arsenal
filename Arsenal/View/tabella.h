#ifndef TABELLA_H
#define TABELLA_H

#include <QTableView>
#include <QMouseEvent>
class Tabella:public QTableView
{
public:
   Tabella(QWidget* = nullptr);
    QSize sizeHint() const;
    void DimCol();
    void Visible(int);
    void mousePressEvent(QMouseEvent*);
};

#endif // TABELLA_H
