#include "regist.h"
#include "ui_regist.h"
#include <QMessageBox>
#include <QSqlQuery>
Regist::Regist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Regist)
{
    ui->setupUi(this);
}

Regist::~Regist()
{
    delete ui;
}

void Regist::on_pushButton_2_clicked()
{
    QString account,password,password1;
    account = ui->userlineEdit->text();
    password = ui->pwdlineEdit->text();
    password1 = ui->pwdlineEdit_1->text();
    QSqlQuery quser;
    int flag = 0;
    quser.exec("select * from user");
    if(account == "" || password == "" || password1 == "")
    {
        QMessageBox::warning(this, "Warning", "Please input all information", QMessageBox::Yes);
        ui->userlineEdit->clear();
        ui->pwdlineEdit->clear();
        ui->pwdlineEdit_1->clear();
        ui->userlineEdit->setFocus();
    }
    else
    {
        while(quser.next())
        {
            if(quser.value(0)==account)
            {
                QMessageBox::warning(this, "Warning", "This account has been registed!", QMessageBox::Yes);
                ui->userlineEdit->clear();
                ui->pwdlineEdit->clear();
                ui->pwdlineEdit_1->clear();
                ui->userlineEdit->setFocus();
                flag = 1;
                break;
            }
        }
        if(!flag)
        {
            if(password == "")
                QMessageBox::warning(this, "Warning", "Password can not be blank!", QMessageBox::Yes);
            else
            {
                if(password!=password1)
                {
                    QMessageBox::warning(this, "Warning", "Passwords are not consistent!", QMessageBox::Yes);
                    ui->userlineEdit->clear();
                    ui->pwdlineEdit->clear();
                    ui->pwdlineEdit_1->clear();
                    ui->userlineEdit->setFocus();
                }
                if(password==password1)
                {
                    QSqlQuery query;
                    query.prepare("insert into user values (?,?)");
                    query.addBindValue(account);
                    query.addBindValue(password);
                    query.exec();
                    QMessageBox::about(NULL, "Success", "Regsiter Success!");
                    close();
                }
            }
        }
    }

}

void Regist::on_pushButton_clicked()
{
    close();
}
