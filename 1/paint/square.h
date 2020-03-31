#ifndef SQUARE_H
#define SQUARE_H
#include "rectangle.h"

class Square : public Rectangle
{
public:
    Square();
    void build(double a);


private:
    void movePoint(int numMovePoint, qreal dx, qreal dy);

};

#endif // SQUARE_H
