#include "login.h"
#include "ui_login.h"
#include "normaluser.h"
#include "rootuser.h"
#include "regist.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QString>
#include <QLabel>
#include <QLayout>
#include <QFont>
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    int flag = 0;
    int flag_n = 0;
    extern QString user;
    //read input
    QString usr_input, pwd_input;
    usr_input = ui->usrLineEdit->text();
    pwd_input = ui->pwdLineEdit->text();
    //usr exits?
    QSqlQuery query_login_root;
    query_login_root.exec("select * from manager");
    while(query_login_root.next()){
        if(usr_input == query_login_root.value(0).toString()){
            flag = 1;
            break;
        }
    }
    if(flag&&(pwd_input==query_login_root.value(1).toString()))
    {
        QDialog *dlg;
        user = query_login_root.value(0).toString();
        dlg = new RootUser(this);
        QLabel *lable  = new QLabel(dlg);
        lable->setText(QString("Hi,Admin: %1").arg(user));
        QFont ft;
        ft.setPointSize(24);
        lable->setFont(ft);
        dlg->show();
        close();
    }
    else
    {
        QSqlQuery query_login_normal;
        query_login_normal.exec("select * from user");
        while(query_login_normal.next()){
            if(usr_input == query_login_normal.value(0).toString()){
                flag_n = 1;
                break;
            }
        }
        if(!flag_n){
            QMessageBox::warning(this, "Warning", "User doesn't exit!", QMessageBox::Yes);
            ui->usrLineEdit->clear();
            ui->pwdLineEdit->clear();
            ui->usrLineEdit->setFocus();
        }
        else{
            if(pwd_input != query_login_normal.value(1).toString()){
                QMessageBox::warning(this, "Warning", "Wrong Password!", QMessageBox::Yes);
                ui->pwdLineEdit->clear();
                ui->pwdLineEdit->setFocus();
            }
            else{
                QDialog *dlg;
                user = query_login_normal.value(0).toString();
                dlg = new NormalUser(this);
                QLabel *lable  = new QLabel(dlg);
                lable->setText(QString("Hi,%1").arg(user));
                QFont ft;
                ft.setPointSize(24);
                lable->setFont(ft);
                dlg->show();
                close();
            }
        }
    }

}

void Login::on_pushButton_2_clicked()
{
    QDialog *dlg = new Regist(this);
    dlg->show();
}

void Login::on_pushButton_3_clicked()
{
    close();
}
