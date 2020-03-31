#ifndef MYMAP2_H
#define MYMAP2_H

#include "mymap.h"

class MyMap2 : public MyMap
{
private:
    void dfs(Node *root, int *h, int th);
public:
    QString geth();
};

#endif // MYMAP2_H
