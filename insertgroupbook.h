#ifndef INSERTGROUPBOOK_H
#define INSERTGROUPBOOK_H

#include <QDialog>

namespace Ui {
class InsertGroupBook;
}

class InsertGroupBook : public QDialog
{
    Q_OBJECT

public:
    explicit InsertGroupBook(QWidget *parent = 0);
    ~InsertGroupBook();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::InsertGroupBook *ui;
};

#endif // INSERTGROUPBOOK_H
