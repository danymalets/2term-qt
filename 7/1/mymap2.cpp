#include "mymap2.h"

const int INF = (int)2e9;

QString MyMap2::getMaxKey()
{
    QString s;
    int max = -INF;
    for (int i = 0; i < size; i++){
        Node* node = a[i]->first;
        while (node != nullptr){
            if (node->key > max){
                max = node->key;
                s = "[" + QString::number(node->key) + "]" + node->value;
            }
            node = node->next;
        }
    }
    return s;
}
