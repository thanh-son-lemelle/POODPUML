#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "Application started";

    MainWindow w;
    qDebug() << "MainWindow created";
    w.show();
    qDebug() << "MainWindow shown";

    return a.exec();
}
