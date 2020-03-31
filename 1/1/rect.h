#ifndef RECT_H
#define RECT_H
#include <QPainter>

class Rect
{
public:
    Rect();

    void Left();

    void Rigth();
protected:
    int x, y;

    void DrawRect(QPainter *painter);
};

#endif // RECT_H
