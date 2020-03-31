#include "circle.h"
#include <QtMath>

Circle::Circle()
{

}

void Circle::build(double r)
{
    canDraw = false;
    canMovePoint = true;
    v.resize(4);
    v[0] = {0, -r};
    v[1] = {r, 0};
    v[2] = {0,  r};
    v[3] = {-r,  0};
    repaint();
}

void Circle::movePoint(int numMovePoint, qreal dx, qreal dy)
{
    int dr;
    switch(numMovePoint){
    case 0:
        if (v[0].y() < v[2].y()){
            dr = -dy;
            v[0] = {v[0].x(), v[0].y() - dr};
            v[2] = {v[0].x(), v[2].y() + dr};
        }
        else{
            dr = dy;
            v[0] = {v[0].x(), v[0].y() + dr};
            v[2] = {v[0].x(), v[2].y() - dr};
        }
        if (v[1].x() < v[3].x()){
            v[1] = {v[1].x() - dr, v[1].y()};
            v[3] = {v[3].x() + dr, v[3].y()};
        }
        else{
            v[1] = {v[1].x() + dr, v[1].y()};
            v[3] = {v[3].x() - dr, v[3].y()};
        }
        break;
    case 1:
        if (v[1].x() < v[3].x()){
            dr = -dx;
            v[1] = {v[1].x() - dr, v[1].y()};
            v[3] = {v[3].x() + dr, v[3].y()};
        }
        else{
            dr = dx;
            v[1] = {v[1].x() + dr, v[1].y()};
            v[3] = {v[3].x() - dr, v[3].y()};
        }
        if (v[0].y() < v[2].y()){
            v[0] = {v[0].x(), v[0].y() - dr};
            v[2] = {v[0].x(), v[2].y() + dr};
        }
        else{
            v[0] = {v[0].x(), v[0].y() + dr};
            v[2] = {v[0].x(), v[2].y() - dr};
        }
        break;
    case 2:
        if (v[0].y() < v[2].y()){
            dr = dy;
            v[0] = {v[0].x(), v[0].y() - dr};
            v[2] = {v[0].x(), v[2].y() + dr};
        }
        else{
            dr = -dy;
            v[0] = {v[0].x(), v[0].y() + dr};
            v[2] = {v[0].x(), v[2].y() - dr};
        }
        if (v[1].x() < v[3].x()){
            v[1] = {v[1].x() - dr, v[1].y()};
            v[3] = {v[3].x() + dr, v[3].y()};
        }
        else{
            v[1] = {v[1].x() + dr, v[1].y()};
            v[3] = {v[3].x() - dr, v[3].y()};
        }
        break;
    case 3:
        if (v[1].x() < v[3].x()){
            dr = -dx;
            v[1] = {v[1].x() + dr, v[1].y()};
            v[3] = {v[3].x() - dr, v[3].y()};
        }
        else{
            dr = dx;
            v[1] = {v[1].x() - dr, v[1].y()};
            v[3] = {v[3].x() + dr, v[3].y()};
        }
        if (v[0].y() < v[2].y()){
            v[0] = {v[0].x(), v[0].y() + dr};
            v[2] = {v[0].x(), v[2].y() - dr};
        }
        else{
            v[0] = {v[0].x(), v[0].y() - dr};
            v[2] = {v[0].x(), v[2].y() + dr};
        }
        break;
    }
}

void Circle::repaint(){
    clear();
    if (!grid){
        for (int i = -800; i <= 800; i+=50){
            addLine(i, -600, i, 600, (QPen(Qt::gray, 1, Qt::SolidLine, Qt::RoundCap)));
        }
        for (int i = -600; i <= 600; i+=50){
            addLine(-800, i, 800, i,(QPen(Qt::gray, 1, Qt::SolidLine, Qt::RoundCap)));
        }
    }
    qreal r = R(v[0],v[2]) / 2;
    addEllipse(pointC.x() - r, pointC.y() - r,2 * r,2 * r,QPen(Qt::red, 3));
    if (canMovePoint){
        for (int i = 0; i < (int)v.size(); i++){
            addEllipse(v[i].x() - 5, v[i].y()-5, 9, 9, QPen(Qt::blue, 4), QBrush(Qt::red));
        }
    }
    if (showO) addEllipse(pointO.x()-5, pointO.y()-5, 9, 9, QPen(Qt::yellow, 3), QBrush(Qt::green));
    if (showC) addEllipse(pointC.x()-4, pointC.y()-4, 7, 7, QPen(Qt::white, 3), QBrush(Qt::black));
}

qreal Circle::P()
{
    qreal r = R(v[0], v[2]) / 2;
    return 2 * M_PI * r / 50;
}

qreal Circle::S()
{
    qreal r = R(v[0], v[2]) / 2;
    return r * r * M_PI / (50 * 50);
}

void Circle::rotate(double da)
{
    for (int i = 0; i < (int)v.size(); i++){
        //v[i] = rotatePoint(pointO, v[i], da);
    }
    qreal r = R(v[0], v[2]) / 2;
    pointC = rotatePoint(pointO, pointC, da);
    v[0] = {pointC.x(), pointC.y()-r};
    v[1] = {pointC.x() + r,pointC.y()};
    v[2] = {pointC.x(), pointC.y()+r};
    v[3] = {pointC.x()-r,pointC.y()};
    repaint();
}
