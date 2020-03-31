#include "mymap2.h"


void MyMap2::dfs(Node *root, int *h, int th)
{
    if (root == nullptr) return;
    h[th]++;
    dfs(root->left, h, th + 1);
    dfs(root->right, h, th + 1);
}

QString MyMap2::geth()
{
    int h[1000];
    for (int i = 0; i < 1000; i++)
        h[i] = 0;
    dfs(root, h, 0);
    QString s;
    int i = 0;
    while (h[i] > 0){
        s += QString::number(i) + "-" + QString::number(h[i]) + "  ";
        i++;
    }
    return s;
}
