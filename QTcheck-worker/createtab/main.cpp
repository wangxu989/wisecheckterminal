#include "mainwindow.h"
#include<QtCore>
#include <QApplication>
#include<form.h>

int main(int argc, char *argv[])
{
    //qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
    QApplication a(argc, argv);
    //QApplication::addLibraryPath("~/");
    MainWindow w;
    w.show();
    return a.exec();
}
