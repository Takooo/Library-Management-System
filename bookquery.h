#ifndef BOOKQUERY_H
#define BOOKQUERY_H

#include <QDialog>

namespace Ui {
class BookQuery;
}

class BookQuery : public QDialog
{
    Q_OBJECT

public:
    explicit BookQuery(QWidget *parent = 0);
    ~BookQuery();

private slots:
    void on_pushButton_clicked();

    void on_radioButton_4_clicked(bool checked);

    void on_radioButton_3_clicked(bool checked);

    void on_radioButton_2_clicked(bool checked);

    void on_radioButton_clicked(bool checked);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_pushButton_5_clicked();


    void on_radioButton_5_clicked(bool checked);

private:
    Ui::BookQuery *ui;
};

#endif // BOOKQUERY_H
