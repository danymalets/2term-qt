#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <QString>



template<typename T>
class MyQueue
{
protected:
    struct Node{
        Node *left, *right;
        T value;

        Node(Node *left, Node *right, T value){
            this->left = left;
            this->right = right;
            this->value = value;
        }
    };

    Node *first = new Node(nullptr, last, 0),
             *last = new Node(first, nullptr, 0);

public:
    MyQueue(){
        first->right = last;
        last->left = first;
    };

    ~MyQueue(){
        clear();
    }

    QString output(){
        QString res = " ";
        Node *node = first->right;
        while(node != last){
            res += node->value + " ";
            node = node->right;
        }
        return res;
    };

    void addLeft(T value)
    {
        Node *node = new Node(first, first->right, value);
        node->right->left = node;
        node->left->right = node;
    }

    void addRight(T value){
        Node *node = new Node(last->left, last, value);
        node->right->left = node;
        node->left->right = node;
    }

    void deleteLeft(){
        delete first->right;
        first->right = first->right->right;
        first->right->left = first;
    }

    void deleteRight(){
        delete last->left;
        last->left = last->left->left;
        last->left->right = last;
    }

    bool empty(){
        return first->right == last;
    }

    void clear(){
        while (!empty()) deleteLeft();
    }
};

#endif // MYQUEUE_H
