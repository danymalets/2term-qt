#ifndef MYMAP_H
#define MYMAP_H

#include <QString>
#include <QTreeWidget>

#include "mylist.h"

class MyMap
{
protected:
    int size;
    MyList* *a;
public:
    MyMap(int size);

    void add(int key, QString value);

    void remove(int key);

    QString getValue(int key);

    void clear();

    QString output();
};

#endif // MYMAP_H
