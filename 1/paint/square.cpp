#include "square.h"
#include <QtMath>

Square::Square()
{

}

void Square::build(double a)
{
    canDraw = false;
    canMovePoint = true;
    v.resize(4);
    v[0] = {-a/2, -a/2};
    v[1] = {a/2 , -a/2};
    v[2] = {a/2 ,  a/2};
    v[3] = {-a/2,  a/2};
    repaint();
}

void Square::movePoint(int numMovePoint, qreal dx, qreal dy)
{
    qreal ndx, ndy, dx0, dy0;
    ndx = v[numMovePoint].x() - v[(numMovePoint + 2) % 4].x();
    ndy = v[numMovePoint].y() - v[(numMovePoint + 2) % 4].y();
    if ((v[numMovePoint].x() < pointC.x())^(v[numMovePoint].y() > pointC.y())){
        dx0 = (dx + dy) * ndx / (ndx + ndy);
        dy0 = (dx + dy) * ndy / (ndx + ndy);
    }
    else{
        dx0 = (dx - dy) * ndx / (ndx - ndy);
        dy0 = (dx - dy) * ndy / (ndx - ndy);
    }
    dx = dx0;
    dy = dy0;
    v[numMovePoint] = {v[numMovePoint].x() + dx, v[numMovePoint].y() + dy};
    if (v[numMovePoint].x() == v[(numMovePoint + 2) % 4].x())
        v[numMovePoint] = {v[numMovePoint].x() + 0.1,v[numMovePoint].y() + 0.1};
    if (v[numMovePoint].y() == v[(numMovePoint + 2) % 4].y())
        v[numMovePoint] = {v[numMovePoint].x() + 0.1,v[numMovePoint].y() + 0.1};
    v[(numMovePoint - 1 + 4) % 4] = H(v[(numMovePoint - 1 + 4) % 4], v[(numMovePoint - 2 + 4) % 4], v[numMovePoint]);
    v[(numMovePoint + 1 + 4) % 4] = H(v[(numMovePoint + 1 + 4) % 4], v[(numMovePoint + 2 + 4) % 4], v[numMovePoint]);
}



