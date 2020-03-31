#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <stack>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_7->setReadOnly(1);
    ui->lineEdit_8->setReadOnly(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


int MainWindow::level(QChar sign)
{
    if (sign == ')') return 0;
    if (sign == '-' || sign == '+') return 1;
    if (sign == '*' || sign == '/') return 2;
    if (sign == '(') return 3;
}

QString MainWindow::infixToPostfix(QString s)
{
    stack<QChar> sign;
    QString ans;
    for (QChar c: s){
        if (c >= 'a' && c <= 'e'){
            ans += c;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){
            while (!sign.empty() && level(sign.top()) >= level(c) && sign.top() != '('){
                ans += sign.top();
                sign.pop();
            }

            sign.push(c);

            if (!sign.empty() && sign.top() == ')') {
                sign.pop();
                if (sign.empty() || sign.top() != '(') return "Error!";
                sign.pop();
            }
        }
        else{
            return "Error!";
        }
    }
    while (!sign.empty()){
        if (sign.top() == '(' || sign.top() == ')') return "Error!";
        ans += sign.top();
        sign.pop();
    }
    return ans;
}

double MainWindow::solvePostfix(QString s, double a, double b, double c, double d, double e)
{
    stack<double> num;
    for (QChar ch: s){
        if (ch >= 'a' && ch <= 'e'){
            if (ch == 'a') num.push(a);
            else if (ch == 'b') num.push(b);
            else if (ch == 'c') num.push(c);
            else if (ch == 'd') num.push(d);
            else num.push(e);
        }
        else {
            double x, y;
            y = num.top(); num.pop();
            x = num.top(); num.pop();
            if (ch == '+') num.push(x + y);
            else if (ch == '-') num.push(x - y);
            else if (ch == '*') num.push(x * y);
            else num.push(x / y);
        }
    }
    return num.top();
}

void MainWindow::on_pushButton_clicked()
{
    QString s = infixToPostfix(ui->lineEdit->text());
    ui->lineEdit_7->setText(s);
    if (s == "Error!") ui->lineEdit_8->setText("Error!");
    else ui->lineEdit_8->setText(QString::number(solvePostfix(s,
                                    ui->lineEdit_2->text().toDouble(),
                                    ui->lineEdit_3->text().toDouble(),
                                    ui->lineEdit_4->text().toDouble(),
                                    ui->lineEdit_5->text().toDouble(),
                                    ui->lineEdit_6->text().toDouble())));
}


