#include "rootuser.h"
#include "ui_rootuser.h"
#include "bookquery.h"
#include "changecipher.h"
#include "insertsinglebook.h"
#include "insertgroupbook.h"

RootUser::RootUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RootUser)
{
    ui->setupUi(this);
}

RootUser::~RootUser()
{
    delete ui;
}

void RootUser::on_pushButton_clicked()
{
    QDialog *dlg = new BookQuery(this);
    dlg->show();
}

void RootUser::on_pushButton_4_clicked()
{
    QDialog *dlg = new ChangeCipher(this);
    dlg->show();
}

void RootUser::on_pushButton_5_clicked()
{
    close();
}

void RootUser::on_pushButton_2_clicked()
{
    QDialog *dlg = new InsertSingleBook(this);
    dlg->show();
}

void RootUser::on_pushButton_3_clicked()
{
    QDialog *dlg = new InsertGroupBook(this);
    dlg->show();
}
