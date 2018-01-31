#ifndef CONNECTION
#define CONNECTION
//#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QObject>
#include <QApplication>

static bool createConnection()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("LibraryManagement");
    db.setUserName("root");
    db.setPassword("pl05013379");
    if (!db.open())
    {
        //提示出错
        QMessageBox::critical(0,QObject::tr("Cannot open database"),QObject::tr("Unable to establish a database connection."),QMessageBox::Cancel);
        return false;
    }
    else
    {
        //qDebug()<<"open success";
        return true;
    }

}

#endif // CONNECTION

