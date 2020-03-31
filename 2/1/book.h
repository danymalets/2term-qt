#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book
{
public:
    Book(QString author, QString title, int publicationYear, QString publisher, int pages);

    QString author;
    QString title;
    int     publicationYear;
    QString publisher;
    int     pages;
};

#endif // BOOK_H
