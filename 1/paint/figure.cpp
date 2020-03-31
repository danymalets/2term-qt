#include "figure.h"
#include <math.h>

Figure::Figure(QObject *parent) : QGraphicsScene(parent)
{

}

Figure::~Figure()
{

}

void Figure::build(){
    repaint();
}

void Figure::moveToPointO()
{
    move(pointO.x() - pointC.x(), pointO.y() - pointC.y());
}

void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    // При нажатии кнопки мыши отрисовываем эллипс
    QPointF point = event->scenePos();
    if (canDraw) {
        v.push_back(point);
        addEllipse(point.x(), point.y(), 5, 5, QPen(Qt::NoPen), QBrush(Qt::red));
    }
    else{
        if (canMovePoint){
            for (int i = 0; i < (int)v.size(); i++){
                if (R(point, v[i]) <= 9) {
                    movePointNow = true;
                    numMovePoint = i;
                    break;
                }
            }
        }
    }
    startPoint = event->scenePos();
    previousPoint = event->scenePos();
}


void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qreal dx = event->scenePos().x() - previousPoint.x();
    qreal dy = event->scenePos().y() - previousPoint.y();
    if (movePointNow){
        movePoint(numMovePoint, dx, dy);

        pointC = C();
        repaint();
    }
    else if (canDraw) {
        QPointF point = event->scenePos();
        v.push_back(point);
        addLine(previousPoint.x(), previousPoint.y(), point.x(), point.y(), QPen(Qt::red, 5, Qt::SolidLine, Qt::RoundCap));
    }
    else{

        move(dx, dy);
    }
    previousPoint = event->scenePos();
}


void Figure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    movePointNow = false;
    if (event->scenePos() == startPoint && !canDraw && previousPoint == event->scenePos()){
        pointO = startPoint;
        showO = true;
    }
    else{
        canDraw = false;
        pointC = C();
    }
    repaint();
}

void Figure::movePoint(int numMovePoint, qreal dx, qreal dy)
{
    //v[numMovePoint] = {v[numMovePoint].x() + dx, v[numMovePoint].y() + dy};
}

void Figure::move(qreal dx, qreal dy){
    for (int i = 0; i < (int)v.size(); i++){
        v[i] = {v[i].x() + dx, v[i].y() + dy};
    }
    pointC = {pointC.x() + dx, pointC.y() + dy};
    repaint();
}

void Figure::zoom(double a)
{
    for (int i = 0; i < (int)v.size(); i++){
        v[i] = {pointO.x() + (v[i].x() - pointO.x()) * a, pointO.y() + (v[i].y() - pointO.y()) * a};
    }
    pointC = {pointO.x() + (pointC.x() - pointO.x()) * a, pointO.y() + (pointC.y() - pointO.y()) * a};
    repaint();
}

void Figure::rotate(double da)
{
    for (int i = 0; i < (int)v.size(); i++){
        v[i] = rotatePoint(pointO, v[i], da);
    }
    pointC = rotatePoint(pointO, pointC, da);
    repaint();
}

void Figure::delPointO()
{
    showO = false;
    pointO = {0,0};
    repaint();
}



qreal Figure::R(QPointF a, QPointF b){
    return sqrt((a.x() - b.x()) * (a.x() - b.x()) +  (a.y() - b.y()) * (a.y() - b.y()));
}

QPointF Figure::rotatePoint(QPointF base, QPointF point, double da)
{
    double dx, dy, ndx, ndy;
    dx = point.x() - base.x();
    dy = point.y() - base.y();
    ndx = dx * cos(da) - dy * sin(da);
    ndy = dx * sin(da) + dy * cos(da);
    return {base.x() + ndx, base.y() + ndy};
}

double Figure::P(){
    double res = 0;
    for (int i = 0; i < (int)v.size(); i++){
        res += R(v[i], v[(i + 1) % v.size()]);
    }
    return res / 50;
}

double Figure::S(){
    double res = 0;
    for (int i = 0; i < (int)v.size(); i++){
        res += (v[i].x() - v[(i + 1) % v.size()].x()) * (v[i].y() + v[(i + 1) % v.size()].y());
    }
    res = abs(res) / 2;
    return res / (50 * 50);
}

void Figure::changeShowC(bool checked)
{
    showC = checked;
    repaint();
}

void Figure::changeShowGrid(bool checked)
{
    grid = checked;
    repaint();
}

double Figure::St(QPointF A, QPointF B, QPointF C){
    double a, b, c, p;
    a = R(A, B);
    b = R(B, C);
    c = R(C, A);
    p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

QPointF Figure::C(){
    double S = 0, x = 0, y = 0;
    for (int i = 0; i < (int)v.size(); i++){
        //if (i%((v.size()+50)/50) != 0 && i != (int)v.size() - 1) continue;
        double s = St(v[0], v[i], v[(i + 1) % int(v.size())]);
        S += s;
        x += s * (v[0].x() + v[i].x() + v[(i + 1) % v.size()].x()) / 3;
        y += s * (v[0].y() + v[i].y() + v[(i + 1) % v.size()].y()) / 3;
    }
    if (S == 0) return v[0];
    x /= S;
    y /= S;
    return {x,y};
}

void Figure::repaint(){
    clear();
    if (!grid){
        for (int i = -800; i <= 800; i+=50){
            addLine(i, -600, i, 600, (QPen(Qt::gray, 1, Qt::SolidLine, Qt::RoundCap)));
        }
        for (int i = -600; i <= 600; i+=50){
            addLine(-800, i, 800, i,(QPen(Qt::gray, 1, Qt::SolidLine, Qt::RoundCap)));
        }
    }

    for (int i = 0; i < (int)v.size(); i++){
        addLine(v[i].x(), v[i].y(), v[(i + 1) % v.size()].x(), v[(i + 1) % v.size()].y(),(QPen(Qt::red, 5, Qt::SolidLine, Qt::RoundCap)));
    }
    if (canMovePoint){
        for (int i = 0; i < (int)v.size(); i++){
            addEllipse(v[i].x() - 5, v[i].y()-5, 9, 9, QPen(Qt::blue, 4), QBrush(Qt::red));
        }
    }
    if (v.size() == 1){
         addEllipse(v[0].x(), v[0].y(), 5, 5, QPen(Qt::NoPen), QBrush(Qt::red));
    }
    if (showO) addEllipse(pointO.x()-5, pointO.y()-5, 9, 9, QPen(Qt::yellow, 3), QBrush(Qt::green));
    if (showC) addEllipse(pointC.x()-4, pointC.y()-4, 7, 7, QPen(Qt::white, 3), QBrush(Qt::black));
    //addEllipse(0-4, 0-4, 70, 70, QPen(Qt::white, 3), QBrush(Qt::black));
}





