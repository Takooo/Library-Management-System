#ifndef ROOTUSER_H
#define ROOTUSER_H

#include <QDialog>

namespace Ui {
class RootUser;
}

class RootUser : public QDialog
{
    Q_OBJECT

public:
    explicit RootUser(QWidget *parent = 0);
    ~RootUser();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::RootUser *ui;
};

#endif // ROOTUSER_H
