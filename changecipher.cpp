#include "changecipher.h"
#include "ui_changecipher.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QString>

ChangeCipher::ChangeCipher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeCipher)
{
    ui->setupUi(this);
}

ChangeCipher::~ChangeCipher()
{
    delete ui;
}
extern QString user;


void ChangeCipher::on_pushButton_clicked()
{
    QString Old_password,New_password,New_password1;
    Old_password = ui->OpwdlineEdit->text();
    New_password = ui->NpwdlineEdit->text();
    New_password1 = ui->NpwdlineEdit1->text();
    QSqlQuery query_user;
    query_user.exec(tr("select Password from user where UserName = '%1'").arg(user));
    query_user.next();
    if(Old_password != query_user.value(0).toString())
    {
        QMessageBox::warning(this, "Warning", "Old password is wrong!", QMessageBox::Yes);
        ui->OpwdlineEdit->clear();
        ui->NpwdlineEdit->clear();
        ui->NpwdlineEdit1->clear();
        ui->OpwdlineEdit->setFocus();
    }
    else
    {
        if(New_password!=New_password1)
        {
            QMessageBox::warning(this, "Warning", "Two paswords are not consistent!", QMessageBox::Yes);
            ui->OpwdlineEdit->clear();
            ui->NpwdlineEdit->clear();
            ui->NpwdlineEdit1->clear();
            ui->OpwdlineEdit->setFocus();
        }
        else
        {
            QSqlQuery Management, Update;
            Management.exec("select UserName from Manager");
            while(Management.next())
            {
                if(Management.value(0).toString() == user)
                {
                    Management.exec(tr("update user set Password = '%1' where UserName = '%2'").arg(New_password).arg(user));
                    QMessageBox::about(NULL, "Success", "Password Change Success!");
                    close();
                    break;
                }
            }
            QSqlQuery NormalUser, Update1;
            NormalUser.exec("select UserName from user");
            while(NormalUser.next())
            {
                if(NormalUser.value(0).toString() == user)
                {
                    NormalUser.exec(tr("update user set Password = '%1' where UserName = '%2'").arg(New_password).arg(user));
                    QMessageBox::about(NULL, "Success", "Password Change Success!");
                    close();
                    break;
                }
            }
        }
    }
}

void ChangeCipher::on_pushButton_2_clicked()
{
    close();
}
