#ifndef LINSERISCI_H
#define LINSERISCI_H

#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QFormLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QString>
#include <iostream>
#include <QFileDialog>
#include <QFileInfo>
#include <QBuffer>

#include "comboboxtipo.h"
#include "comboboxcat1.h"
#include "comboboxcat2.h"
#include "comboboxmirino.h"

using std::string;

class LInserisci : public QWidget
{
    Q_OBJECT
private:

    QLabel *lmarca;
    QLabel *lcosto;
    QLabel *lnome;
    QLabel *ltipo;
    QLabel *lcalibro;
    QLabel *lcadenza;
    QLabel *lcat1;
    QLabel *lcat2;
    QLabel *lvoltaggio;
    QLabel *lamperaggio;
    QLabel *ldurataScarica;
    QLabel *ldistanza;
    QLabel *lcapacita;
    QLabel *lmirino;
    QLabel *Sfoto;

    QLineEdit *marca;   
    QLineEdit *costo;  
    QLineEdit *nome;
    QLineEdit *calibro;
    QLineEdit *cadenza;
    QLineEdit *voltaggio;
    QLineEdit *ampereggio;
    QLineEdit *durataScarica;
    QLineEdit *distanza;
    QLineEdit *capacita;

    QCheckBox *disp;
    QCheckBox *ricaricabile;
    QCheckBox *torcia;
    QCheckBox *silenziatore;
    QCheckBox *automatica;
    QCheckBox *doppiaCanna;
    QCheckBox *silenziatore2;

    comboboxTipo *tipo;
    comboboxCat1 *cat1;
    comboboxCat2 *cat2;
    comboboxMirino *mirino;

    QPushButton *bimg;
    QPushButton *binserisci; 
    QPushButton *breset;

public:

    LInserisci(QWidget * =nullptr);

    QLineEdit *getMarca() const;
    QLineEdit *getCosto() const;
    QLineEdit *getNome() const;
    string getTipo() const;
    string getCat1() const;
    string getCat2() const;
    QLineEdit *getCalibro() const;
    QLineEdit *getCadenza() const;
    bool getRicaricabile() const;
    bool getTorcia() const;
    bool getSilenziatore() const;
    bool getSilenziatore2() const;
    bool getAutomatica() const;
    bool getDoppiaCanna() const;
    string getMirino() const;
    QLineEdit *getVoltaggio() const;
    QLineEdit *getAmperaggio() const;
    QLineEdit *getDurata() const;
    QLineEdit *getDistanza() const;
    QLineEdit *getCapacita() const;
    QPushButton *getBImg() const;
    QPushButton *getBInserisci() const;
    QPushButton *getBReset() const;
    bool getDisp() const;
    QLabel *getSFoto() const;

private slots:
    void SReset() const;
public slots:
    void SVisible(int) const;
    void SVisible2(int) const;
    void SVisible3(int) const;
    void SImg();
signals:
    void SGInserisci();

};

#endif // LINSERISCI_H
