#ifndef NORMALUSER_H
#define NORMALUSER_H

#include <QDialog>

namespace Ui {
class NormalUser;
}

class NormalUser : public QDialog
{
    Q_OBJECT

public:
    explicit NormalUser(QWidget *parent = 0);
    ~NormalUser();



private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::NormalUser *ui;
};

#endif // NORMALUSER_H
