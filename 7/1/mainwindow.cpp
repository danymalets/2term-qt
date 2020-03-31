#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_4->setReadOnly(true);
    output();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int key = ui->lineEdit->text().toInt();
    QString value = ui->lineEdit_2->text();

    m->remove(key);
    m->add(key, value);
    output();

}


void MainWindow::on_pushButton_2_clicked()
{
    int key = ui->lineEdit_3->text().toInt();
    ui->lineEdit_4->setText(m->getValue(key));
    output();
}

void MainWindow::output()
{
    ui->textEdit->setText(m->output());
    ui->lineEdit_5->setText(m->getMaxKey());
}

void MainWindow::on_pushButton_3_clicked()
{
    int key = ui->lineEdit_10->text().toInt();
    m->remove(key);
    output();

}

// +
void MainWindow::on_pushButton_4_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem());
}

// -
void MainWindow::on_pushButton_5_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() - 1);
}

void MainWindow::on_pushButton_6_clicked()
{
    m->clear();
    for (int i = 0; i < ui->tableWidget->rowCount(); i++){
        int key = ui->tableWidget->item(i,0)->text().toInt();
        QString value = ui->tableWidget->item(i,1)->text();
        m->add(key, value);
    }
    output();
}

void MainWindow::on_pushButton_7_clicked()
{
    m->clear();
    output();
}

void MainWindow::on_pushButton_8_clicked()
{
    int n, cnt, l, r;
    n = ui->lineEdit_6->text().toInt();
    cnt = ui->lineEdit_7->text().toInt();
    l = ui->lineEdit_8->text().toInt();
    r = ui->lineEdit_9->text().toInt();
    m = new MyMap2(n);
    for (int i = 0; i < cnt; i++){
        int key = rand() % (r - l + 1) + l;
        QString s;
        s += (char)('a' + i % 26);
        s += (char)('a' + i % 26);
        s += (char)('a' + i % 26);
        m->add(key, s);
    }
    output();
}
