#ifndef CHANGECIPHER_H
#define CHANGECIPHER_H

#include <QDialog>

namespace Ui {
class ChangeCipher;
}

class ChangeCipher : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeCipher(QWidget *parent = 0);
    ~ChangeCipher();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ChangeCipher *ui;
};

#endif // CHANGECIPHER_H
