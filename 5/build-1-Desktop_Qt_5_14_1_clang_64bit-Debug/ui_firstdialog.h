/********************************************************************************
** Form generated from reading UI file 'firstdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRSTDIALOG_H
#define UI_FIRSTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FirstDialog
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_6;
    QLabel *label;

    void setupUi(QDialog *FirstDialog)
    {
        if (FirstDialog->objectName().isEmpty())
            FirstDialog->setObjectName(QString::fromUtf8("FirstDialog"));
        FirstDialog->resize(820, 325);
        lineEdit = new QLineEdit(FirstDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 30, 700, 50));
        QFont font;
        font.setPointSize(25);
        lineEdit->setFont(font);
        lineEdit->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(FirstDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(20, 310, 0, 0));
        pushButton_2 = new QPushButton(FirstDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 160, 100, 50));
        pushButton_3 = new QPushButton(FirstDialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(330, 160, 100, 50));
        pushButton_4 = new QPushButton(FirstDialog);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(480, 110, 100, 100));
        pushButton_5 = new QPushButton(FirstDialog);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(630, 110, 100, 100));
        lineEdit_2 = new QLineEdit(FirstDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(190, 120, 80, 30));
        QFont font1;
        font1.setPointSize(17);
        lineEdit_2->setFont(font1);
        lineEdit_2->setAlignment(Qt::AlignCenter);
        lineEdit_3 = new QLineEdit(FirstDialog);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(340, 120, 80, 30));
        lineEdit_3->setFont(font1);
        lineEdit_3->setAlignment(Qt::AlignCenter);
        pushButton_6 = new QPushButton(FirstDialog);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setEnabled(true);
        pushButton_6->setGeometry(QRect(30, 110, 100, 100));
        label = new QLabel(FirstDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 250, 58, 16));

        retranslateUi(FirstDialog);

        QMetaObject::connectSlotsByName(FirstDialog);
    } // setupUi

    void retranslateUi(QDialog *FirstDialog)
    {
        FirstDialog->setWindowTitle(QCoreApplication::translate("FirstDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("FirstDialog", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214\n"
"\321\201\320\273\320\265\320\262\320\260", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FirstDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214\n"
"\321\201\320\273\320\265\320\262\320\260", nullptr));
        pushButton_3->setText(QCoreApplication::translate("FirstDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214\n"
"\321\201\320\277\321\200\320\260\320\262\320\260", nullptr));
        pushButton_4->setText(QCoreApplication::translate("FirstDialog", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214\n"
"\321\201\320\277\321\200\320\260\320\262\320\260", nullptr));
        pushButton_5->setText(QCoreApplication::translate("FirstDialog", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("FirstDialog", "0", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("FirstDialog", "0", nullptr));
        pushButton_6->setText(QCoreApplication::translate("FirstDialog", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214\n"
"\321\201\320\273\320\265\320\262\320\260", nullptr));
        label->setText(QCoreApplication::translate("FirstDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FirstDialog: public Ui_FirstDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRSTDIALOG_H
