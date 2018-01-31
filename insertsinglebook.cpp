#include "insertsinglebook.h"
#include "ui_insertsinglebook.h"
#include <QSqlQuery>
#include <QMessageBox>

InsertSingleBook::InsertSingleBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertSingleBook)
{
    ui->setupUi(this);
}

InsertSingleBook::~InsertSingleBook()
{
    delete ui;
}

void InsertSingleBook::on_pushButton_2_clicked()
{
    close();
}

void InsertSingleBook::on_pushButton_clicked()
{
    QSqlQuery query;
    query.prepare("insert into book values (?,?,?,?,?,?,?,?,?,now())");
    query.addBindValue(ui->BookNo->text());
    query.addBindValue(ui->BoonType->text());
    query.addBindValue(ui->BookName->text());
    query.addBindValue(ui->Publisher->text());
    query.addBindValue(ui->Year->text().toInt());
    query.addBindValue(ui->Author->text());
    query.addBindValue(ui->Price->text().toFloat());
    query.addBindValue(ui->Storage_total->text().toInt());
    query.addBindValue(ui->Storage_current->text().toInt());
    if(query.exec()){
        QMessageBox::about(NULL, "Success", "Insert Success!");
        close();
    }
    else{
        QMessageBox::warning(this, "Warning", "Insert Fail!\nCheck Your Input!", QMessageBox::Yes);
    }
}
