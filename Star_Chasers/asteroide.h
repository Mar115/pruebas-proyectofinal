#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <math.h>

class asteroide : public QObject, public QGraphicsPixmapItem
{
public:
    asteroide();
    void set_imagen();
    void set_scale(int a, int b);
    void movimiento_circular(int Xo, int Yo, int R);
    int size;

private:
    QPixmap asteroide_;
    int scalex =1, scaley= 1;
    int N=1, R=1, T=1, X, Y, w=1; //w frecuencia angular
};

#endif // ASTEROIDE_H
