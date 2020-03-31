#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_4->setReadOnly(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int key = ui->lineEdit->text().toInt();
    QString value = ui->lineEdit_2->text();

    m.insert(key, value);
    output();
}


void MainWindow::on_pushButton_2_clicked()
{
    int key = ui->lineEdit_3->text().toInt();
    ui->lineEdit_4->setText(m.getValue(key));
    output();
}

void MainWindow::output()
{
    m.output(ui->treeWidget);
    ui->lineEdit_5->setText(m.dfs1(m.root));
    ui->lineEdit_6->setText(m.dfs2(m.root));
    ui->lineEdit_7->setText(m.dfs3(m.root));
    ui->lineEdit_8->setText(m.geth());
}

void MainWindow::on_pushButton_3_clicked()
{
    int key = ui->lineEdit_10->text().toInt();
    m.remove(key);
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
    m.clear();
    for (int i = 0; i < ui->tableWidget->rowCount(); i++){
        int key = ui->tableWidget->item(i,0)->text().toInt();
        QString value = ui->tableWidget->item(i,1)->text();
        m.insert(key, value);
    }
    output();
}

void MainWindow::on_pushButton_7_clicked()
{
    m.clear();
    output();
}
