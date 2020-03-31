/********************************************************************************
** Form generated from reading UI file 'seconddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDDIALOG_H
#define UI_SECONDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SecondDialog
{
public:
    QListWidget *listWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_2;

    void setupUi(QDialog *SecondDialog)
    {
        if (SecondDialog->objectName().isEmpty())
            SecondDialog->setObjectName(QString::fromUtf8("SecondDialog"));
        SecondDialog->resize(765, 564);
        listWidget = new QListWidget(SecondDialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(50, 50, 435, 464));
        QFont font;
        font.setPointSize(17);
        listWidget->setFont(font);
        lineEdit = new QLineEdit(SecondDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(540, 100, 100, 30));
        lineEdit->setFont(font);
        pushButton = new QPushButton(SecondDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(780, 410, 16, 16));
        label = new QLabel(SecondDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(540, 50, 131, 50));
        label->setFont(font);
        label_2 = new QLabel(SecondDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(540, 180, 131, 50));
        label_2->setFont(font);
        lineEdit_2 = new QLineEdit(SecondDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(540, 230, 100, 30));
        lineEdit_2->setFont(font);
        label_3 = new QLabel(SecondDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(540, 310, 171, 50));
        label_3->setFont(font);
        lineEdit_3 = new QLineEdit(SecondDialog);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(540, 360, 100, 30));
        lineEdit_3->setFont(font);
        pushButton_2 = new QPushButton(SecondDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(530, 430, 181, 81));

        retranslateUi(SecondDialog);

        QMetaObject::connectSlotsByName(SecondDialog);
    } // setupUi

    void retranslateUi(QDialog *SecondDialog)
    {
        SecondDialog->setWindowTitle(QCoreApplication::translate("SecondDialog", "Dialog", nullptr));
        lineEdit->setText(QCoreApplication::translate("SecondDialog", "14", nullptr));
        pushButton->setText(QCoreApplication::translate("SecondDialog", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("SecondDialog", "\320\233\320\265\320\262\320\260\321\217 \320\263\321\200\320\260\320\275\320\270\321\206\320\260\n"
"(\320\262\320\272\320\273\321\216\321\207\320\270\321\202\320\265\320\273\321\214\320\275\320\276):", nullptr));
        label_2->setText(QCoreApplication::translate("SecondDialog", "\320\237\321\200\320\260\320\262\320\260\321\217 \320\263\321\200\320\260\320\275\320\270\321\206\320\260\n"
"(\320\262\320\272\320\273\321\216\321\207\320\270\321\202\320\265\320\273\321\214\320\275\320\276):", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("SecondDialog", "15", nullptr));
        label_3->setText(QCoreApplication::translate("SecondDialog", "\320\237\320\276\321\201\320\273\320\265 \320\272\320\260\320\272\320\276\320\271\n"
"\321\201\321\202\321\200\320\276\321\207\320\272\320\270 \320\262\321\201\321\202\320\260\320\262\320\270\321\202\321\214:", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("SecondDialog", "11", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SecondDialog", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondDialog: public Ui_SecondDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDDIALOG_H
