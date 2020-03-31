#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "firstdialog.h"
#include "seconddialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyQueue<int> q;
    q.addLeft(2);
    q.addRight(4);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    FirstDialog dialog;
    //dialog.setModal(true);
    dialog.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    SecondDialog dialog;
    //dialog.setModal(true);
    dialog.exec();
}
