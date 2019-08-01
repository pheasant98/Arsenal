#ifndef MENU_H
#define MENU_H

#include <QMenuBar>
#include <qmenubar.h>
#include <QMenu>
#include <qwidget.h>
#include <QWidget>

class Menu: public QMenuBar
{
     Q_OBJECT
private:
    QWidget* p;
    QMenu* menu;
    QAction* salva;
    QAction* salvaConNome;
    QAction* carica;
    QAction* esci;
    QAction* inserisci;
    QAction* visualizza;
public:
    Menu(QWidget *parent=nullptr);
    QMenu *getMenu() const;
    QAction *getSalva() const;
    QAction *getCarica() const;
    QAction *getEsci() const;
    QAction *getSalvaConNome() const;
};

#endif // MENU_H
