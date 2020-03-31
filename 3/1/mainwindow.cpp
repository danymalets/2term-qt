#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, new QTableWidgetItem());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, new QTableWidgetItem());
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() - 1);
}

void MainWindow::on_pushButton_6_clicked()
{
    for (int i = 0; i < ui->tableWidget->rowCount(); i++){
        int number;
        QString airplane, point, time;
        number = ui->tableWidget->item(i,0)->text().toInt();
        airplane = ui->tableWidget->item(i,1)->text();
        point = ui->tableWidget->item(i,2)->text();
        time = ui->tableWidget->item(i,3)->text();
        list.add(new Info(number, airplane, point, time));
    }
    ui->textEdit->setText(list.output());
}

int MainWindow::getnum(QString s)
{
    if (s == "") return 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] < '0' || s[i] > '9'){
            return -1;
        }
    }
    int num = s.toInt();
    if (num <= 0) return -1;
    return num;
}

void MainWindow::on_pushButton_clicked()
{
    int number;
    QString airplane, point, time;
    number = getnum(ui->lineEdit->text());
    if (number == -1) {
        QMessageBox::information(this, "", "Ошибка!\nНомер должен быть числом больше 0");
        return;
    }
    airplane = ui->lineEdit_2->text();
    if (airplane == "") {
        QMessageBox::information(this, "", "Ошибка!\nВведите что-нибудь");
        return;
    }
    point = ui->lineEdit_3->text();
    if (point == "") {
        QMessageBox::information(this, "", "Ошибка!\nВведите что-нибудь");
        return;
    }
    time = ui->lineEdit_4->text();
    if (time == "") {
        QMessageBox::information(this, "", "Ошибка!\nВведите что-нибудь");
        return;
    }
    list.add(new Info(number, airplane, point, time));
    ui->textEdit->setText(list.output());
}

void MainWindow::on_pushButton_2_clicked()
{
    int number;
    QString airplane, point, time;
    number = getnum(ui->lineEdit->text());
    if (number == -1) {
        QMessageBox::information(this, "", "Ошибка!\nНомер должен быть числом больше 0");
        return;
    }
    airplane = ui->lineEdit_2->text();
    point = ui->lineEdit_3->text();
    time = ui->lineEdit_4->text();
    ui->textEdit->setText(list.find(Info(number, airplane, point, time)));
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->textEdit->setText(list.output());
}

void MainWindow::on_pushButton_4_clicked()
{
    int number;
    QString airplane, point, time;
    number = getnum(ui->lineEdit->text());
    if (number == -1) {
        QMessageBox::information(this, "", "Ошибка!\nНомер должен быть числом больше 0");
        return;
    }
    airplane = ui->lineEdit_2->text();
    point = ui->lineEdit_3->text();
    time = ui->lineEdit_4->text();
    list.remove(Info(number, airplane, point, time));
    ui->textEdit->setText(list.output());
}
