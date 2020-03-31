#ifndef SECONDDIALOG_H
#define SECONDDIALOG_H

#include <QDialog>

#include <QString>

#include "code.h"

namespace Ui {
class SecondDialog;
}

class SecondDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecondDialog(QWidget *parent = nullptr);
    ~SecondDialog();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::SecondDialog *ui;

    QString CODE[21] = {
    "#include <iostream>",
    "using namespace std;",
    "",
    "long long fact(int n)",
    "{",
    "    long long res = 1;",
    "    for (int i = 2; i <= n; i++){",
    "        res *= i;",
    "    }",
    "    return res;",
    "}",
    "",
    "int main() {",
    "    int n;",
    "    long long res;",
    "    cout << \"Введите число:\" << endl;",
    "    cin >> n;",
    "    res = fact(n);",
    "    cout << \"Факториал равен \" << res << endl;",
    "    return 0;",
    "}"
    };

    Code *code = new Code();

    void write();

    QString numToStr(int num);
};

#endif // SECONDDIALOG_H
