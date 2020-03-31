#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "polygon.h"

class Rectangle : public Polygon
{
public:
    Rectangle();
    void build(double a, double b);
    QPointF H(QPointF a, QPointF b, QPointF c);
private:
    void movePoint(int numMovePoint, qreal dx, qreal dy);
};

#endif // RECTANGLE_H
