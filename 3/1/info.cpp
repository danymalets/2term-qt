#include "info.h"

Info::Info(int number, QString airplane, QString point, QString time)
{
    this->number = number;
    this->airplane = airplane;
    this->point = point;
    this->time = time;
}

bool Info::isEqual(Info input)
{
    return (input.number == 0 || input.number == number) &&
            (input.airplane == "" || input.airplane == airplane) &&
            (input.point == "" || input.point == point) &&
            (input.time == "" || input.time == time);
}
