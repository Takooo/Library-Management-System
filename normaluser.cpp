#include "normaluser.h"
#include "ui_normaluser.h"
#include "bookquery.h"
#include "changecipher.h"
#include <QLabel>
NormalUser::NormalUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NormalUser)
{
    ui->setupUi(this);
    ui->pushButton_7->setFocus();
}

NormalUser::~NormalUser()
{
    delete ui;
}
extern QString user;

void NormalUser::on_pushButton_7_clicked()
{
    QDialog *dlg = new BookQuery(this);
    dlg->show();
}

void NormalUser::on_pushButton_4_clicked()
{
    QDialog *dlg = new ChangeCipher(this);
    dlg->show();
}

void NormalUser::on_pushButton_5_clicked()
{
    user = "";
    close();
}
