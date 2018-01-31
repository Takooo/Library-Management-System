#include <QtGui>
#include <QCoreApplication>
#include "connection.h"
#include "mainwindow.h"


QString user;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    createConnection();
    w.show();
    return a.exec();
}
