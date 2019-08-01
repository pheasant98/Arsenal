#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QBuffer>
#include <iostream>
#include <string>
#include "linserisci.h"
#include "menu.h"
#include "Model/model.h"
#include "Model/qintermedio.h"
#include "Model/qgestionetabella.h"
#include "visualizzaoggetto.h"
#include "tabella.h"
#include "View/visualizza.h"
#include "visualizzaoggetto.h"
#include "modifica.h"
#include "ricerca.h"
#include "Model/Gerarchia/arma.h"
#include "Model/Gerarchia/arma_da_fuoco.h"
#include "Model/Gerarchia/arma_non_letale.h"
#include "Model/Gerarchia/elettrica.h"
#include "Model/Gerarchia/fucile_a_pompa.h"
#include "Model/Gerarchia/fucile_a_precisione.h"
#include "Model/Gerarchia/pistola.h"
#include "Model/Gerarchia/gas_oc.h"

class MainWindow : public QWidget
{
    Q_OBJECT
private:

   Menu* menuBar;//layout barra del menu
   QString file; //nome file
   QHBoxLayout* MainL;// layout principale
   LInserisci* InserisciL;//layout inserisci
   Visualizza* VisL;//layout visualizza
   Ricerca *RicL;//layout ricerca

public:
   MainWindow(QWidget *parent = nullptr, bool load=true);
   virtual void closeEvent (QCloseEvent* ) override;
   ~MainWindow()override = default;

private slots:

   void SSalva();
   void SSalvaConNome();
   void SCarica();
   void SMostraInserisci()const;
   void SMostraVisualizza()const;
   void SAggiungi();
   void SVisualizza() const;
   void SModifica() const;
   void SRimuovi() const;
   void SRicerca() const;
   void SOrdinaAsd() const;
   void SOrdinaDesc() const;
   void SCostoTot();
};

#endif // MAINWINDOW_H
