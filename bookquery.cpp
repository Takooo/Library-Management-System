#include "bookquery.h"
#include "ui_bookquery.h"
#include <QSqlQuery>
#include <QTime>
#include <QMessageBox>
#include <QDebug>

BookQuery::BookQuery(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookQuery)
{
    ui->setupUi(this);
}

BookQuery::~BookQuery()
{
    delete ui;
}
static bool check1, check2, check3, check4, check5;
static bool check1_1, check2_2, check3_3, check4_4, check5_5;
QString BNo;
extern QString user;
void BookQuery::on_pushButton_clicked()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);;
    int FL = 0;
    //construct predicate
    QString predicate;
    if(check1)
    {
        predicate = QString("book.BookName = '%1'").arg(ui->lineEdit->text());
        check1 = 0;
        check1_1 = 1;
        check2_2 = 0;
        check3_3 = 0;
        check4_4 = 0;
        check5_5 = 0;
    }

    else if(check2)
    {
        predicate = QString("book.BookNo = '%1'").arg(ui->lineEdit->text());
        check2 = 0;
        check1_1 = 0;
        check2_2 = 1;
        check3_3 = 0;
        check4_4 = 0;
        check5_5 = 0;
    }

    else if(check3)
    {
        predicate = QString("book.Author = '%1'").arg(ui->lineEdit->text());
        check3 = 0;
        check1_1 = 0;
        check2_2 = 0;
        check3_3 = 1;
        check4_4 = 0;
        check5_5 = 0;
    }

    else if(check4)
    {
        predicate = QString("book.BookType = '%1'").arg(ui->lineEdit->text());
        check4 = 0;
        check1_1 = 0;
        check2_2 = 0;
        check3_3 = 0;
        check4_4 = 1;
        check5_5 = 0;
    }

    else if(check5)
    {
        FL = 1;
        check5 = 0;
        check1_1 = 0;
        check2_2 = 0;
        check3_3 = 0;
        check4_4 = 0;
        check5_5 = 1;
    }
    if(FL)
    {
        int i = 0;
        QSqlQuery query;
        query.exec("select * from book order by BookName");
        while(query.next())
        {
            int row_count = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row_count);
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(query.value(3).toString()));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(query.value(4).toString()));
            ui->tableWidget->setItem(i,5,new QTableWidgetItem(query.value(5).toString()));
            ui->tableWidget->setItem(i,6,new QTableWidgetItem(query.value(6).toString()));
            ui->tableWidget->setItem(i,7,new QTableWidgetItem(query.value(7).toString()));
            ui->tableWidget->setItem(i,8,new QTableWidgetItem(query.value(8).toString()));
            ui->tableWidget->setItem(i,9,new QTableWidgetItem(query.value(9).toString()));
            i++;
        }
    }
    else
    {
        QSqlQuery query;
        query.exec(tr("select * from book where %1 order by BookName").arg(predicate));
        int i=0;
        while(query.next())
        {
            int row_count = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row_count);
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(query.value(3).toString()));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(query.value(4).toString()));
            ui->tableWidget->setItem(i,5,new QTableWidgetItem(query.value(5).toString()));
            ui->tableWidget->setItem(i,6,new QTableWidgetItem(query.value(6).toString()));
            ui->tableWidget->setItem(i,7,new QTableWidgetItem(query.value(7).toString()));
            ui->tableWidget->setItem(i,8,new QTableWidgetItem(query.value(8).toString()));
            ui->tableWidget->setItem(i,9,new QTableWidgetItem(query.value(9).toString()));
            i++;
        }
    }

}

void BookQuery::on_radioButton_4_clicked(bool checked)    //type
{
    if(checked) check4 = 1;
    else check4 = 0;
}

void BookQuery::on_radioButton_3_clicked(bool checked)    //zuo
{
    if(checked) check3 = 1;
    else check3 = 0;
}

void BookQuery::on_radioButton_2_clicked(bool checked)    //hao
{
    if(checked) check2 = 1;
    else check2 = 0;
}

void BookQuery::on_radioButton_clicked(bool checked)    //ming
{
    if(checked) check1 = 1;
    else check1 = 0;
}

void BookQuery::on_pushButton_2_clicked()
{

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);;
    QString predicate;
    if(check1_1)
    {
        predicate = QString("book.BookName = '%1'").arg(ui->lineEdit->text());
        check1_1 = 0;
    }

    if(check2_2)
    {
        predicate = QString("book.BookNo = '%1'").arg(ui->lineEdit->text());
        check2_2 = 0;
    }

    if(check3_3)
    {
        predicate = QString("book.Author = '%1'").arg(ui->lineEdit->text());
        check3_3 = 0;
    }

    if(check4_4)
    {
        predicate = QString("book.BookType = '%1'").arg(ui->lineEdit->text());
        check4_4 = 0;
    }

    if(check5_5)
    {
        predicate = QString("1=1");
        check5_5 = 0;
    }

        int i = 0;
        QSqlQuery query;
        query.exec(tr("select * from book where %1 and book.BookNo not in (select BookNo from book where Storage_current <= 0) order by book.BookName").arg(predicate));
        while(query.next())
        {
            int row_count = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row_count);
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(query.value(3).toString()));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(query.value(4).toString()));
            ui->tableWidget->setItem(i,5,new QTableWidgetItem(query.value(5).toString()));
            ui->tableWidget->setItem(i,6,new QTableWidgetItem(query.value(6).toString()));
            ui->tableWidget->setItem(i,7,new QTableWidgetItem(query.value(7).toString()));
            ui->tableWidget->setItem(i,8,new QTableWidgetItem(query.value(8).toString()));
            ui->tableWidget->setItem(i,9,new QTableWidgetItem(query.value(9).toString()));
            i++;
        }

}

void BookQuery::on_pushButton_3_clicked()
{

    if(user == "")
        QMessageBox::warning(this, "Warning", "You can't borrow because you haven't logged in!", QMessageBox::Yes);
    else
    {
        QSqlQuery B;
        B.exec("select book.BookNo from book");
        int F = 0;
        while(B.next())
        {
            if(BNo == B.value(0))
            {
               F = 1;
               break;
            }
        }
        if(!F)
            QMessageBox::warning(this, "Warning", "Please choose Book No!", QMessageBox::Yes);
        else
        {

            QSqlQuery num;
            num.exec(tr("select book.Storage_current from book where BookNo = '%1'").arg(BNo));
            num.next();
            if(num.value(0) <= 0)
            {
                QMessageBox::warning(this, "Warning", "All these books has been borrowed!", QMessageBox::Yes);
            }
            else
            {
                QSqlQuery bo;
                bo.exec(tr("insert into loan values('%1','%2',default,now())").arg(user).arg(BNo));
                bo.exec(tr("update book set Storage_current = Storage_current - 1 where BookNo = '%1'").arg(BNo));
            }
        }
    }

}

void BookQuery::on_pushButton_4_clicked()
{
    if(user == "")
        QMessageBox::warning(this, "Warning", "You can't query because you haven't logged in!", QMessageBox::Yes);
    else
    {
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    QSqlQuery query;
    query.exec("select * from book,loan where book.BookNo = loan.BookNo order by book.BookName");
    int i = 0;
    while(query.next())
    {
        int row_count = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row_count);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(query.value(5).toString()));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(query.value(6).toString()));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(query.value(7).toString()));
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(query.value(8).toString()));
        ui->tableWidget->setItem(i,9,new QTableWidgetItem(query.value(9).toString()));
        i++;
    }
    }
}

void BookQuery::on_tableWidget_cellClicked(int row, int column)
{
    BNo = ui->tableWidget->item(row,column)->text();
}

void BookQuery::on_pushButton_5_clicked()
{
    if(user == "")
        QMessageBox::warning(this, "Warning", "You can't borrow because you haven't logged in!", QMessageBox::Yes);
    else
    {
        QSqlQuery B;
        B.exec("select loan.BookNo from loan");
        int F = 0;
        while(B.next())
        {
            if(BNo == B.value(0))
            {
               F = 1;
               break;
            }
        }
        if(!F)
            QMessageBox::warning(this, "Warning", "Please choose Book No!", QMessageBox::Yes);
        else
        {
            QSqlQuery query;
            int flag = 0;
            query.exec("select loan.BookNo from loan");
            while(query.next())
            {
                if(BNo == query.value(0))
                {
                    flag = 1;
                    break;
                }
            }
            if(!flag)
                QMessageBox::warning(this, "Warning", "The book has been returned!", QMessageBox::Yes);
            else
            {
                QSqlQuery bo;
                bo.exec(tr("delete from loan where loan.BookNo = '%1'").arg(BNo));
                bo.exec(tr("update book set Storage_current = Storage_current + 1 where BookNo = '%1'").arg(BNo));
            }
        }
    }
}

void BookQuery::on_radioButton_5_clicked(bool checked)
{
    if(checked) check5 = 1;
    else check5 = 0;
}

