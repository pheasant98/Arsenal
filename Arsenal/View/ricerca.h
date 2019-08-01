#ifndef RICERCA_H
#define RICERCA_H

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include "Model/model.h"
#include "Model/qintermedio.h"
#include "Model/qgestionetabella.h"
#include "comboboxricerca.h"
#include "comboboxmirino.h"
#include <QButtonGroup>

class Ricerca : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *Barradiricerca;
    QCheckBox *Vero;
    QCheckBox *Falso;
    QCheckBox* Maggiore;
    QCheckBox* Minore;
    QPushButton* bPulisciRicerca;
    QPushButton* bOrdinaAsc;
    QPushButton* bOrdinaDesc;
    comboboxRicerca* ricerca;
    comboboxMirino* Mirino;
public:
    Ricerca(QWidget *parent = nullptr);

    QLineEdit *getBarradiricerca() const;
    QCheckBox *getVero() const;
    QCheckBox *getFalso() const;
    QCheckBox *getMaggiore() const;
    QCheckBox *getMinore() const;
    QPushButton *getBPulisciRicerca() const;
    comboboxRicerca *getRicerca() const;
    comboboxMirino *getMirino() const;
    QPushButton *getBOrdinaAsc() const;
    QPushButton *getBOrdinaDesc() const;

signals:
    void SGRicerca();
    void SGOrdinaAsc();
    void SGOrdinaDesc();
public slots:
    void SVisible(int);
};

#endif // RICERCA_H
