#ifndef GESTIONEIMG_H
#define GESTIONEIMG_H

#include <QPixmap>
#include <QBuffer>
#include <QByteArray>
#include <QFileInfo>
#include <QFileDialog>

using std::string;

class GestioneImg
{
public:
    GestioneImg();
    static string getCodice(const QImage&);
    static QPixmap getImg(const string&);
};

#endif // GESTIONEIMG_H
