#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <figure.h>
#include <polygon.h>
#include <rectangle.h>
#include <square.h>
#include <circle.h>
#include <QTimer>
#include <QObject>
#include <QGraphicsItem>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Ui::MainWindow *ui;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_pushButton_clicked();

    void on_radioButton_clicked(bool checked);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_radioButton_2_clicked(bool checked);

private:
    //QTimer *timer;
    Figure *figure;
    Polygon *polygon;
    Rectangle *rectangle;
    Square *square;
    Circle *circle;
    void paintEvent(QPaintEvent *event);
    //void resizeEvent(QResizeEvent * event);
    enum picture{
        _figure,
        _polygon,
        _rectangle,
        _square,
        _circle
    };
    double DA, A;
    picture now = _figure;;
public slots:
     void onTimeOut();
     void timeOutDa();
     void timeOutA();
};
#endif // MAINWINDOW_H
