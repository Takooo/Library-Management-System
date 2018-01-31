#ifndef INSERTSINGLEBOOK_H
#define INSERTSINGLEBOOK_H

#include <QDialog>

namespace Ui {
class InsertSingleBook;
}

class InsertSingleBook : public QDialog
{
    Q_OBJECT

public:
    explicit InsertSingleBook(QWidget *parent = 0);
    ~InsertSingleBook();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::InsertSingleBook *ui;
};

#endif // INSERTSINGLEBOOK_H
