#ifndef MYLIST_H
#define MYLIST_H

#include <QString>

#include "node.h"

class MyList
{
public:

    Node* first = nullptr;

    void add(int key, QString value);

    void remove(int key);

    Node* remove(Node *root, int key);

    QString getValue(int key);

    QString output();

    void clear();
};

#endif // MYLIST_H
