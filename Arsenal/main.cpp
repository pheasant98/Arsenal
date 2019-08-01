#include "View/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication Qapp(argc, argv);
    MainWindow w;
    w.show();
    return Qapp.exec();
}
