#ifndef MYMAP2_H
#define MYMAP2_H

#include "mymap.h"

class MyMap2 : public MyMap
{
private:

public:
    MyMap2(int size) : MyMap(size){};
    QString getMaxKey();
};

#endif // MYMAP2_H
