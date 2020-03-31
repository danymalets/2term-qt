#ifndef MYMAP_H
#define MYMAP_H

#include <QString>
#include <QTreeWidget>

struct Node{
    Node *left, *right;
    int hight;
    int key;
    QString value;

    Node(int k, QString v){
        key = k;
        value = v;
        left = right = nullptr;
        hight = 1;
    }
};

class MyMap
{
protected:
    int getHight(Node *root);

    int getBalanceValue(Node *root);

    void fixHight(Node *root);

    Node* rotateLeft(Node *root);

    Node* rotateRight(Node *root);

    Node* balance(Node *root);

    Node* add(Node *root, int key, QString value);

    void rec(QTreeWidget *tree, QTreeWidgetItem *p, Node *r, bool b);

    QString getValue(Node *r, int key);

    Node* findmin(Node *root){
        return (root->left == nullptr) ? root : findmin(root->left);
    }

    Node* removemin(Node *root);

    Node *remove(Node *root, int key);

    void clear(Node *root);
public:
    Node *root = nullptr;

    void output(QTreeWidget *tree);

    void insert(int key, QString value);

    QString getValue(int key);

    void remove(int key);

    void clear();

    QString dfs1(Node *root);

    QString dfs2(Node *root);

    QString dfs3(Node *root);
};

#endif // MYMAP_H
