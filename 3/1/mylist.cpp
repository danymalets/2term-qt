#include "mylist.h"

MyList::MyList()
{

}

void MyList::add(Info *info)
{
    info->next = first;
    first = info;
}

void MyList::remove(Info input)
{
    first = remove(first, input);
}

Info* MyList::remove(Info *info, Info input)
{
    if (info == nullptr) return nullptr;
    if (info->isEqual(input)) return remove(info->next, input);
    else {
        info->next = remove(info->next, input);
        return info;
    }
}

QString MyList::find(Info input)
{
    QString s;
    Info *info = first;
    while(info != nullptr){
        if (info->isEqual(input)){
            s = QString::number(info->number) + "  " + info->airplane + "  " +
                    info->point + "  " + info->time + "\n" + s;
        }
        info = info->next;
    }
    return s;
}

QString MyList::output()
{
    QString s;
    Info *info = first;
    while(info != nullptr){
        s = QString::number(info->number) + "  " + info->airplane + "  " +
                info->point + "  " + info->time + "\n" + s;
        info = info->next;
    }
    return s;
}


