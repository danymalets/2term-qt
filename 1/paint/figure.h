#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>
#include <vector>

#include <QGraphicsView>

class Figure : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Figure(QObject *parent = 0);
    ~Figure();

    bool canDraw = true;
    std::vector<QPointF> v;

    virtual qreal P();
    virtual qreal S();

    void  moveToPointO();
    void changeShowC(bool checked);
    void changeShowGrid(bool checked);
    void changeShowPoint(bool checked);
    void build();
    bool showC = false;
    bool waitO = false;
    bool showO = false;
    void delO();
    void move(qreal dx, qreal dy);
    QPointF pointO, pointC;
    void zoom(double a);
    virtual void rotate(double da);
    void delPointO();
    QPointF previousPoint, startPoint;
    double St(QPointF a, QPointF b, QPointF c);
    qreal R(QPointF a, QPointF b);
    QPointF rotatePoint(QPointF base, QPointF point, double da);
    QPointF C();
    bool canMovePoint = false;
    bool movePointNow = false;
    int numMovePoint;
    bool grid;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    virtual void movePoint(int numMovePoint, qreal dx,qreal dy);
    virtual void repaint();
private:

};


#endif
