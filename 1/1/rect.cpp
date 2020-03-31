#include "rect.h"

Rect::Rect()
{

}

void Rect::DrawRect(QPainter *painter){
    painter->setPen(QPen(Qt::green, 4, Qt::SolidLine, Qt::FlatCap));
    painter->fillRect(x, y, 100, 150, Qt::green);
}

void Rect::Left(){
    if (x > 100) x -= 2;
}

void Rect::Rigth(){
   if (x < 900) x += 2;
}
