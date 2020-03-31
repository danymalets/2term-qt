#ifndef FIRSTDIALOG_H
#define FIRSTDIALOG_H

#include <QDialog>

#include "myqueue.h"

namespace Ui {
class FirstDialog;
}

class FirstDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FirstDialog(QWidget *parent = nullptr);
    ~FirstDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::FirstDialog *ui;

    MyQueue<QString> *q = new MyQueue<QString>();

    void output();
};

#endif // FIRSTDIALOG_H
