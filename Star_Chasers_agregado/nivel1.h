#ifndef NIVEL1_H
#define NIVEL1_H

#include <QObject>
#include <QGraphicsPixmapItem>

class nivel1 : QObject, public QGraphicsPixmapItem //Herencia
{

public:
    nivel1(int width, int heigth);
    int get_h();

private:
    int w,h;
};

#endif // NIVEL1_H

