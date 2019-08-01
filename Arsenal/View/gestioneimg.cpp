#include "gestioneimg.h"

GestioneImg::GestioneImg(){}

string GestioneImg::getCodice(const QImage & f)//trasforma l'img passata per parametro d'ingresso nella sua stringa corrispondente
{
    QByteArray qba;
    QBuffer b(&qba);
    f.save(&b, "JPG");
    return QString(qba.toBase64()).toStdString();//conversione
}

QPixmap GestioneImg::getImg(const string & s)// trasforma la stringa in ingresso nella sua corrispondente img
{
    QImage* img= new QImage;
    QByteArray qba= QByteArray(s.data());
    img->loadFromData(QByteArray::fromBase64(qba), "JPG");//conversione
    QPixmap p=QPixmap::fromImage(*img);
    delete img;
    return p.scaled(200,300,Qt::AspectRatioMode::KeepAspectRatio);//imposto la dim dell'img e la ritorno
}
