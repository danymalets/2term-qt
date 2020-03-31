#ifndef INFO_H
#define INFO_H

#include <QString>

class Info
{
public:
    int number;
    QString airplane, point, time;
    Info *next;

    Info(int number, QString airplane, QString point, QString time);

    bool isEqual(Info input);
};

#endif // INFO_H
