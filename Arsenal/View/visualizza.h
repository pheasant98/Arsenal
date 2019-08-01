#ifndef VISUALIZZAERICERCA_H
#define VISUALIZZAERICERCA_H

#include <QWidget>
#include "linserisci.h"
#include "menu.h"
#include "Model/model.h"
#include "Model/qintermedio.h"
#include "Model/qgestionetabella.h"
#include "visualizzaoggetto.h"
#include "tabella.h"
#include "comboboxricerca.h"
#include "ricerca.h"

class Visualizza : public QWidget
{
    Q_OBJECT
private:
    LInserisci *ins;//usato per gestire la tabella
    Ricerca *ric;//usato per gestire le funzionalita di ricerca della tabella
    Qintermedio* intermedioL;//proxy tra gestionetabella e tabella
    QGestioneTabella* model;
    Tabella* tab;
    QPushButton* bVisualizza;
    QPushButton* bModifica;
    QPushButton *bElimina;
    QPushButton *bCostoTot;

public:
   Visualizza(QWidget * = nullptr, LInserisci* =nullptr, Ricerca* =nullptr);

   LInserisci *getIns() const;
   Qintermedio *getIntermedioL() const;
   QGestioneTabella *getModel() const;
   Tabella *getTab() const;
   QPushButton *getbVisualizza() const;
   QPushButton *getbModifica() const;
   QPushButton *getBElimina() const;
   Ricerca *getRic() const;
   QPushButton *getBCostoTot() const;

signals:
   void SGMostra();
   void SGModifica();
   void SGElimina();
   void SGCostoTot();
};

#endif // VISUALIZZAERICERCA_H
