#include "insertgroupbook.h"
#include "ui_insertgroupbook.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QTextStream>
#include <QStringList>
#include <QString>
#include <QDebug>

InsertGroupBook::InsertGroupBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertGroupBook)
{
    ui->setupUi(this);
}

InsertGroupBook::~InsertGroupBook()
{
    delete ui;
}

void InsertGroupBook::on_pushButton_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this, NULL, NULL, tr("*.txt"));
    QFile f(fileName);
    int flag = 0;
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
        QMessageBox::warning(this, "Warning", "File Open Error!", QMessageBox::Yes);
    else
    {
        QSqlQuery query;
        query.prepare("insert into book values (?,?,?,?,?,?,?,?,?,now())");
        QTextStream txtInput(&f);
        QString lineStr;
        while(!txtInput.atEnd())
        {
            lineStr = txtInput.readLine();
            QStringList strlist=lineStr.split(",");
            query.addBindValue(strlist.at(0));
            query.addBindValue(strlist.at(1));
            query.addBindValue(strlist.at(2));
            query.addBindValue(strlist.at(3));
            query.addBindValue(strlist.at(4));
            query.addBindValue(strlist.at(5));
            query.addBindValue(strlist.at(6));
            query.addBindValue(strlist.at(7));
            query.addBindValue(strlist.at(8));
            if(!query.exec())
                flag = 1;
        }
        if(!flag)
        {
            QMessageBox::about(NULL, "Success", "Insert Success!");
            close();
        }
        else
        {
            QMessageBox::warning(this, "Warning", "Insert Fail!\nCheck Your Input!", QMessageBox::Yes);
        }
        f.close();
    }
}

void InsertGroupBook::on_pushButton_2_clicked()
{
    close();
}
