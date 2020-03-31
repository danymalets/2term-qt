#include "firstdialog.h"
#include "ui_firstdialog.h"

FirstDialog::FirstDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstDialog)
{
    ui->setupUi(this);

    ui->lineEdit->setReadOnly(true);
}

FirstDialog::~FirstDialog()
{
    delete ui;
}

void FirstDialog::output()
{
    ui->lineEdit->setText(q->output());
    if (q->empty()) ui->label->setText("true");
    else ui->label->setText("false");
}

void FirstDialog::on_pushButton_2_clicked()
{
    q->addLeft(ui->lineEdit_2->text());

    output();

}

void FirstDialog::on_pushButton_3_clicked()
{
    q->addRight(ui->lineEdit_3->text());
    output();
}

void FirstDialog::on_pushButton_6_clicked()
{
    if (!q->empty()) q->deleteLeft();
    output();
}

void FirstDialog::on_pushButton_4_clicked()
{
    if (!q->empty()) q->deleteRight();
    output();
}

void FirstDialog::on_pushButton_5_clicked()
{
    q->clear();
    output();
}
