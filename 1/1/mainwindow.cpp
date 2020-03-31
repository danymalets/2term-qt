#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1100,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    for (int i = 0; i < 50; i++){
        QTimer::singleShot(i * 10, this, SLOT(L()));
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    for (int i = 0; i < 50; i++){
        QTimer::singleShot(i * 10, this, SLOT(R()));
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    m->HandUp();
    repaint();
}

void MainWindow::on_pushButton_4_clicked()
{
    m->HandDown();
    repaint();
}

void MainWindow::L()
{
    m->Left();
    repaint();
}

void MainWindow::R()
{
    m->Rigth();
    repaint();
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    m->DrawMan(&painter);
}



