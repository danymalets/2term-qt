#include "seconddialog.h"
#include "ui_seconddialog.h"

SecondDialog::SecondDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondDialog)
{
    ui->setupUi(this);

    for (int i = 0; i < 21; i++){
        code->addRight(CODE[i]);
    }

    write();
}

SecondDialog::~SecondDialog()
{
    delete ui;
}

void SecondDialog::on_pushButton_2_clicked()
{
    int l, r, n;

    l = ui->lineEdit->text().toInt();
    r = ui->lineEdit_2->text().toInt();
    n = ui->lineEdit_3->text().toInt();

    if (l < 1 || l > 21) return;
    if (r < 1 || r > 21) return;
    if (n < 0 || n > 21) return;
    if (n >= l && n <= r) return;
    code->move(l, r, n);
    write();
}

void SecondDialog::write()
{
    ui->listWidget->clear();
    QString* s = code->write();
    for (int i = 0; i < 21; i++){
        ui->listWidget->addItem(numToStr(i + 1) + "    |    " + s[i]);
    }
}

QString SecondDialog::numToStr(int num)
{
    if (num < 10) return " " + QString::number(num);
    else return QString::number(num);
}
