#include "book.h"

Book::Book(QString author, QString title, int publicationYear, QString publisher, int pages)
{
    this->author = author;
    this->title = title;
    this->publicationYear = publicationYear;
    this->publisher = publisher;
    this->pages = pages;
}
