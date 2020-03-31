#ifndef CIRCLE_H
#define CIRCLE_H
#include "figure.h"

class Circle : public Figure
{
public:
    Circle();
    void build(double r);
    qreal P();
    qreal S();
    void rotate(double da);
private:

    void movePoint(int numMovePoint, qreal dx, qreal dy);
protected:
    void repaint();
};

#endif // CIRCLE_H
