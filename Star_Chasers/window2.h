#ifndef WINDOW2_H
#define WINDOW2_H

#include <QObject>
#include <QGraphicsPixmapItem>
//#define PATH_1 "../Star_Chasers/images/level2.jpeg"

class window2: QObject, public QGraphicsPixmapItem //Herencia
{
public:
    window2(int width, int heigth, int a);
    int get_h();

private:
    int w,h;
};

#endif // WINDOW2_H
