#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "bookquery.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(width(),height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QDialog *dlg = new BookQuery(this);
    dlg->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    QDialog *dlg = new Login(this);
    dlg->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    close();
}
