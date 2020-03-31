#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Paint");
    setFixedSize(1125,780);

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
    timer->start(300);



    figure = new Figure();
    figure->showC = ui->radioButton->isChecked();
    figure->grid = ui->radioButton_2->isChecked();
    ui->graphicsView->setScene(figure);
    figure->build();
    figure->setSceneRect(0, 0, 1, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    figure = new Figure();
    figure->showC = ui->radioButton->isChecked();
    figure->changeShowGrid(ui->radioButton_2->isChecked());
    ui->graphicsView->setScene(figure);
    figure->setSceneRect(0, 0, 1, 1);
    ui->label->setText("Периметр:  -");
    ui->label_2->setText("Площадь:  -");
    figure->build();
    now = _figure;

}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setPen(QPen(Qt::gray, 3, Qt::SolidLine, Qt::FlatCap));
    painter.drawLine(850, 40, 900, 40);
    painter.drawLine(850, 33, 850, 47);
    painter.drawLine(900, 33, 900, 47);
    painter.setPen(QPen(Qt::gray, 5, Qt::SolidLine, Qt::FlatCap));
    painter.drawLine(25,22,25,628);
    painter.drawLine(22,25,828,25);
    painter.drawLine(22,625,828,625);
    painter.drawLine(825,22,825,628);
    painter.drawRect(850,90,250,105);
    QFont font;
    font.setPixelSize(16);
    painter.setFont(font);
    //painter.drawText(915, 45, "1 см = 50 пикселей");
}

void MainWindow::onTimeOut()
{
    switch(now){
        case _figure:
            if (!figure->canDraw) {
                ui->label->setText("Периметр:  " + QString::number(figure->P()) + "  см");
                ui->label_2->setText("Площадь:  " + QString::number(figure->S()) + "  см^2");
            }
        break;
        case _polygon:
            if (!polygon->canDraw) {
                ui->label->setText("Периметр:  " + QString::number(polygon->P()) + "  см");
                ui->label_2->setText("Площадь:  " + QString::number(polygon->S()) + "  см^2");
            }
            break;
        case _rectangle:
            if (!rectangle->canDraw) {
                ui->label->setText("Периметр:  " + QString::number(rectangle->P()) + "  см");
                ui->label_2->setText("Площадь:  " + QString::number(rectangle->S()) + "  см^2");
            }
            break;
        case _square:
            if (!square->canDraw) {
                ui->label->setText("Периметр:  " + QString::number(square->P()) + "  см");
                ui->label_2->setText("Площадь:  " + QString::number(square->S()) + "  см^2");
            }
            break;
        case _circle:
            if (!circle->canDraw) {
                ui->label->setText("Периметр:  " + QString::number(circle->P()) + "  см");
                ui->label_2->setText("Площадь:  " + QString::number(circle->S()) + "  см^2");
            }
            break;
    }


}

void MainWindow::on_radioButton_clicked(bool checked)
{
    switch(now){
    case _figure:
        figure->changeShowC(checked);
        break;
    case _polygon:
        polygon->changeShowC(checked);
        break;
    case _rectangle:
        rectangle->changeShowC(checked);
        break;
    case _square:
        square->changeShowC(checked);
        break;
    case _circle:
        circle->changeShowC(checked);
        break;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    switch(now){
    case _figure:
        figure->delPointO();
        break;
    case _polygon:
        polygon->delPointO();
        break;
    case _rectangle:
        rectangle->delPointO();
        break;
    case _square:
        square->delPointO();
        break;
    case _circle:
        circle->delPointO();
        break;
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    switch(now){
    case _figure:
        figure->moveToPointO();
        break;
    case _polygon:
        polygon->moveToPointO();
        break;
    case _rectangle:
        rectangle->moveToPointO();
        break;
    case _square:
        square->moveToPointO();
        break;
    case _circle:
        circle->moveToPointO();
        break;
    }

}

void MainWindow::on_pushButton_4_clicked()
{
    double a = ui->lineEdit->text().toDouble();
    a = (100 + a) / 100;
    for (int i = 0; i < 100; i++){
        A = pow(a, (double)1/100);
        QTimer::singleShot(i * 5, this, SLOT(timeOutA()));
    }

}

void MainWindow::on_pushButton_5_clicked()
{
    double a = ui->lineEdit->text().toDouble();
    a = 100 / (100 + a);
    for (int i = 0; i < 100; i++){
        A = pow(a, (double)1/100);
        QTimer::singleShot(i * 5, this, SLOT(timeOutA()));
    }
}

void MainWindow::timeOutA(){
    switch(now){
        case _figure:
            figure->zoom(A);
            break;
        case _polygon:
            polygon->zoom(A);
            break;
        case _rectangle:
            rectangle->zoom(A);
            break;
        case _square:
            square->zoom(A);
            break;
        case _circle:
            circle->zoom(A);
            break;
    }
}
void MainWindow::on_pushButton_6_clicked()
{
    double da = ui->lineEdit_2->text().toDouble();
    da = da * M_PI / 180;


    for (int i = 0; i < 100; i++){
        DA = da / 100;
        QTimer::singleShot(i * 3, this, SLOT(timeOutDa()));
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    double da = ui->lineEdit_2->text().toDouble();
    da = -da * M_PI / 180;


    for (int i = 0; i < 100; i++){
        DA = da / 100;
        QTimer::singleShot(i * 3, this, SLOT(timeOutDa()));
    }
}

void MainWindow::timeOutDa(){
    switch(now){
        case _figure:
            figure->rotate(DA);
            break;
        case _polygon:
            polygon->rotate(DA);
            break;
        case _rectangle:
            rectangle->rotate(DA);
            break;
        case _square:
            square->rotate(DA);
            break;
        case _circle:
            circle->rotate(DA);
            break;
    }
}



void MainWindow::on_pushButton_8_clicked()
{
    polygon = new Polygon();
    polygon->showC = ui->radioButton->isChecked();
    polygon->grid = ui->radioButton_2->isChecked();
    ui->graphicsView->setScene(polygon);
    polygon->setSceneRect(0, 0, 1, 1);
    polygon->build(ui->lineEdit_8->text().toInt(), ui->lineEdit_9->text().toDouble() * 50);
    now = _polygon;
}

void MainWindow::on_pushButton_9_clicked()
{
    rectangle = new Rectangle();
    rectangle->showC = ui->radioButton->isChecked();
    rectangle->grid = ui->radioButton_2->isChecked();
    ui->graphicsView->setScene(rectangle);
    rectangle->setSceneRect(0, 0, 1, 1);
    rectangle->build(ui->lineEdit_6->text().toDouble() * 50, ui->lineEdit_7->text().toDouble() * 50);
    now = _rectangle;
}

void MainWindow::on_pushButton_10_clicked()
{
    square = new Square();
    square->showC = ui->radioButton->isChecked();
    square->grid = ui->radioButton_2->isChecked();
    ui->graphicsView->setScene(square);
    square->setSceneRect(0, 0, 1, 1);
    square->build(ui->lineEdit_5->text().toDouble() * 50);
    now = _square;
}

void MainWindow::on_pushButton_12_clicked()
{
    circle = new Circle();
    circle->showC = ui->radioButton->isChecked();
    circle->grid = ui->radioButton_2->isChecked();
    ui->graphicsView->setScene(circle);
    circle->setSceneRect(0, 0, 1, 1);
    circle->build(ui->lineEdit_4->text().toDouble() * 50);
    now = _circle;
}

void MainWindow::on_radioButton_2_clicked(bool checked)
{
    switch(now){
    case _figure:
        figure->changeShowGrid(checked);
        break;
    case _polygon:
        polygon->changeShowGrid(checked);
        break;
    case _rectangle:
        rectangle->changeShowGrid(checked);
        break;
    case _square:
        square->changeShowGrid(checked);
        break;
    case _circle:
        circle->changeShowGrid(checked);
        break;
    }
}
