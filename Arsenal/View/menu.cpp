#include "menu.h"

Menu::Menu(QWidget *m):
    p(m), menu(new QMenu("Menu", this)), salva( new QAction("Salva", menu)), salvaConNome(new QAction("Salva con nome", menu)), carica( new QAction("Carica", menu)),
     esci(new QAction("Esci", menu)),inserisci(new QAction("Inserisci",m)),visualizza(new QAction("Visualizza-Modifica-Ricerca-Elimina",p))
{
    QList<QAction*>Lista;//menu a tendina
    Lista.push_back(salva);
    Lista.push_back(salvaConNome);
    Lista.push_back(carica);
    Lista.push_back(esci);
    menu->addActions(Lista);
    Lista.clear();
    addMenu(menu);
    addAction(inserisci);//tab inserisci
    addAction(visualizza);//tab visualizza ricerca modifica elimina

    connect(salva,SIGNAL(triggered()),p,SLOT(SSalva()));//gestito in MainWindow
    connect(salvaConNome,SIGNAL(triggered()),p,SLOT(SSalvaConNome()));//gestito in MainWindow
    connect(carica,SIGNAL(triggered()),p, SLOT(SCarica()));//gestito in MainWindow
    connect(esci,SIGNAL(triggered()),p, SLOT(close()));
    connect(inserisci, SIGNAL(triggered()), p,SLOT(SMostraInserisci()));//gestito in MainWindow
    connect(visualizza, SIGNAL(triggered()), p,SLOT(SMostraVisualizza()));//gestito in MainWindow
}

QMenu *Menu::getMenu() const
{
    return menu;
}

QAction *Menu::getSalva() const
{
    return salva;
}

QAction *Menu::getSalvaConNome() const
{
    return salvaConNome;
}

QAction *Menu::getCarica() const
{
    return carica;
}
QAction *Menu::getEsci() const
{
    return esci;
}
