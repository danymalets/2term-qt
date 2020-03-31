#ifndef POLYGON_H
#define POLYGON_H

#include <figure.h>

class Polygon: public Figure
{
public:
    Polygon();
    void build(int n, double R);
private:
    QPointF buildPoint(double a, int r);
private:
    void movePoint(int numMovePoint, qreal dx, qreal dy);
};

#endif // POLYGON_H
