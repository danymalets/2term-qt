#include "polygon.h"
#include "math.h"

Polygon::Polygon()
{
}


void Polygon::build(int n, double R)
{
    canMovePoint = true;
    canDraw = false;
    for (int i = 0; i < n; i++){
        v.push_back(buildPoint(i * 2 * M_PI / n + M_PI / n, R));

    }
    repaint();
}


QPointF Polygon::buildPoint(double a, int r)
{
    return {r * sin(a), r * cos(a)};
}

void Polygon::movePoint(int numMovePoint, qreal dx, qreal dy)
{
    v[numMovePoint] = {v[numMovePoint].x() + dx, v[numMovePoint].y() + dy};
}


