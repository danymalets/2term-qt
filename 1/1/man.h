#ifndef MAN_H
#define MAN_H
#include <QPainter>
#include <rect.h>

class Man: public Rect{
public:
    Man(int x0, int y0);

    void HandDown();

    void HandUp();

    void DrawMan(QPainter *painter);
private:
    bool IsHandUp = false;
};
#endif // MAN_H
