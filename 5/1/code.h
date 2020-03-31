#ifndef CODE_H
#define CODE_H

#include <QString>

#include "myqueue.h"

class Code: public MyQueue<QString>
{
public:
    Code();

    Node* find(int i){
        Node *node = first;
        while(i > 0){
            node = node->right;
            i--;
        }
        return node;
    }

    void move(int l, int r, int n){
        Node *node_l = find(l);
        Node *node_r = find(r);
        Node *node_n = find(n);

        node_l->left->right = node_r->right;
        node_r->right->left = node_l->left;

        node_r->right = node_n->right;
        node_n->right->left = node_r;

        node_n->right = node_l;

        node_l->left = node_n;
    }

    QString* write(){
        QString *s = new QString[21];
        Node *node = first->right;
        int i = 0;
        while(node != last){
            s[i] = node->value;
            node = node->right;
            i++;
        }
        return s;
    }
};

#endif // CODE_H
