#include "mymap.h"

MyMap::MyMap(int size)
{
    this->size = size;
    a = new MyList*[size];
    for (int i = 0; i < size; i++){
        a[i] = new MyList();
    }
}

void MyMap::add(int key, QString value)
{
    a[key % size]->add(key, value);
}

void MyMap::remove(int key)
{
    a[key % size]->remove(key);
}

QString MyMap::getValue(int key)
{
    return a[key % size]->getValue(key);
}

void MyMap::clear()
{
    for (int i = 0; i < size; i++){
        a[i]->clear();
    }
}

QString MyMap::output()
{
    QString s;
    for (int i = 0; i < size; i++){
        s += QString::number(i) + ":   " + a[i]->output() + '\n';
    }
    return s;
}
