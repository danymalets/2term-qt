#include "mylist.h"


void MyList::add(int key, QString value)
{
    Node *node = new Node();
    node->key = key;
    node->value = value;
    node->next = first;
    first = node;
}

void MyList::remove(int key)
{
    first = remove(first, key);
}

Node* MyList::remove(Node *node, int key)
{
    if (node == nullptr) return nullptr;
    if (node->key == key) return remove(node->next, key);
    else {
        node->next = remove(node->next, key);
        return node;
    }
}

QString MyList::getValue(int key)
{
    QString s;
    Node *node = first;
    while(node != nullptr){
        if (node->key == key){
            return node->value;
        }
        node = node->next;
    }
    return "";
}

QString MyList::output()
{
    QString s;
    Node *node = first;
    while(node != nullptr){
        s += "[" + QString::number(node->key) + "]" + node->value + "  ";
        node = node->next;
    }
    return s;
}

void MyList::clear()
{
    first = nullptr;
}


