#include "rectangle.h"

Rectangle::Rectangle()
{

}

void Rectangle::build(double a, double b)
{
    canDraw = false;
    canMovePoint = true;
    v.resize(4);
    v[0] = {-b/2, -a/2};
    v[1] = {b/2 , -a/2};
    v[2] = {b/2 ,  a/2};
    v[3] = {-b/2,  a/2};
    repaint();
}

QPointF Rectangle::H(QPointF a, QPointF b, QPointF c)
{
    qreal A1, B1, C1, A2, B2, C2, d;
    A1 = a.y() - b.y();
    B1 = b.x() - a.x();
    C1 = a.x() * b.y() - a.y() * b.x();

    A2 = B1;
    B2 = -A1;
    C2 = - A2 * c.x() - B2 * c.y();

    d = A1 * B2 - A2 * B1;
    if (d == 0) {

    }
    return {(B1 * C2 - B2 * C1) / d,(A2 * C1 - A1 * C2) / d};
}

void Rectangle::movePoint(int numMovePoint, qreal dx, qreal dy)
{
    v[numMovePoint] = {v[numMovePoint].x() + dx, v[numMovePoint].y() + dy};
    if (v[numMovePoint].x() == v[(numMovePoint + 2) % 4].x())
        v[numMovePoint] = {v[numMovePoint].x() + 0.1,v[numMovePoint].y()};
    if (v[numMovePoint].y() == v[(numMovePoint + 2) % 4].y())
        v[numMovePoint] = {v[numMovePoint].x(),v[numMovePoint].y() + 0.1};
    v[(numMovePoint - 1 + 4) % 4] = H(v[(numMovePoint - 1 + 4) % 4], v[(numMovePoint - 2 + 4) % 4], v[numMovePoint]);
    v[(numMovePoint + 1 + 4) % 4] = H(v[(numMovePoint + 1 + 4) % 4], v[(numMovePoint + 2 + 4) % 4], v[numMovePoint]);
}

