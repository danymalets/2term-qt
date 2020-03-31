#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::write(Book* *a, int size)
{
    ui->textEdit->clear();
    for (int i = 0; i < size; i++){
        Book *book = a[i];
        ui->textEdit->append("    " +
                             QString::number(i + 1) + ".  " +
                             book->author + "   \"" +
                             book->title + "\"    " +
                             QString::number(book->publicationYear) + " г.    " +
                             book->publisher + "    " +
                             QString::number(book->pages) + " стр.");
    }
}



// open
void MainWindow::on_pushButton_clicked()
{
    file_name = QFileDialog::getOpenFileName(this, "",
                                                     "/Users/danielmalec/Desktop/c++/2/1/database/",
                                                     "Text file (*.txt)");
    QFile file(file_name);
    file.open(QFile::ReadOnly);

    QTextStream in(&file);
    int n = in.readLine().toInt();
    size = n;
    for (int i = 0; i < n; i++){
        in.readLine();
        QString author = in.readLine();
        QString title = in.readLine();
        int publicationYear = in.readLine().toInt();
        QString publisher = in.readLine();
        int pages = in.readLine().toInt();
        Book *book = new Book(author, title, publicationYear, publisher, pages);
        a[i] = book;
    }
    file.close();
    write(a, size);
}

// save
void MainWindow::on_pushButton_3_clicked()
{
    QFile file(file_name);
    file.open(QFile::WriteOnly);
    QTextStream out(&file);
    out << size << '\n';
    for (int i = 0; i < size; i++){
        Book *book = a[i];
        out << '\n';
        out << book->author << '\n';
        out << book->title << '\n';
        out << book->publicationYear << '\n';
        out << book->publisher << '\n';
        out << book->pages << '\n';
    }
    file.close();
}

// add
void MainWindow::on_pushButton_4_clicked()
{
    QString author = ui->lineEdit->text();
    if (author == "") return;

    QString title = ui->lineEdit_2->text();
    if (title == "") return;

    int publicationYear = ui->lineEdit_3->text().toInt();
    if (publicationYear == 0) return;

    QString publisher = ui->comboBox->currentText();
    if (publisher == "") return;

    int pages = ui->lineEdit_5->text().toInt();
    if (pages == 0) return;

    Book *book = new Book(author, title, publicationYear, publisher, pages);
    a[size] = book;
    size++;
    write(a, size);
}

// show
void MainWindow::on_pushButton_9_clicked()
{
    write(a, size);
}

// find
void MainWindow::on_pushButton_5_clicked()
{
    int tsize = 0;
    Book* *ta = new Book*[10000];

    QString author = ui->lineEdit->text();
    QString title = ui->lineEdit_2->text();
    int publicationYear = ui->lineEdit_3->text().toInt();
    QString publisher = ui->comboBox->currentText();
    int pages = ui->lineEdit_5->text().toInt();

    for (int i = 0; i < size; i++){
        Book *book = a[i];
        if ((author == "" || author == book->author) &&
                (title == "" || title  == book->title ) &&
                (publicationYear == 0 || publicationYear == book->publicationYear) &&
                (publisher == "" || publisher == book->publisher) &&
                (pages == 0 || pages == book->pages)){
            ta[tsize] = a[i];
            tsize++;
        }
    }

    write(ta, tsize);
}


bool MainWindow::isSubStr(QString subs, QString s)
{
    for (int i = 0; i <= (int)s.length() - subs.length(); i++){
        bool ok = true;
        for (int j = 0; j < subs.length(); j++){
            if (s[i + j].toLower() != subs[j].toLower()){
                ok = false;
                break;
            }
        }
        if (ok) return true;
    }
    return false;
}

// find by key
void MainWindow::on_pushButton_6_clicked()
{
    int tsize = 0;
    Book* *ta = new Book*[10000];
    for (int i = 0; i < size; i++){
        if (isSubStr(ui->lineEdit_6->text(), a[i]->title)){
            ta[tsize] = a[i];
            tsize++;
        }
    }
    write(ta, tsize);
}

bool cmp(Book* a, Book* b){
    return a->publicationYear < b->publicationYear;
}

// sort
void MainWindow::on_pushButton_7_clicked()
{
    sort(a, a + size, cmp);
    write(a, size);
}

void MainWindow::on_pushButton_8_clicked()
{
    int tsize = 0;
    Book* *ta = new Book*[10000];

    QString author = ui->lineEdit->text();
    QString title = ui->lineEdit_2->text();
    int publicationYear = ui->lineEdit_3->text().toInt();
    QString publisher = ui->comboBox->currentText();
    int pages = ui->lineEdit_5->text().toInt();

    for (int i = 0; i < size; i++){
        Book *book = a[i];
        if (!((author == "" || author == book->author) &&
                (title == "" || title  == book->title ) &&
                (publicationYear == 0 || publicationYear == book->publicationYear) &&
                (publisher == "" || publisher == book->publisher) &&
                (pages == 0 || pages == book->pages))){
            ta[tsize] = a[i];
            tsize++;
        }

    }
    delete[] ta;
    a = ta;
    size = tsize;
    write(a, size);
}
