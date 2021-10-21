#ifndef JUGADOR1_H
#define JUGADOR1_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include <QPixmap>

class jugador1 : public QObject, public QGraphicsPixmapItem //Herencia
{
public:
    jugador1();
    void set_imagen();
    void set_scale(int a, int b);

private:
    QPixmap img;
    int scalex = 1, scaley=1;
};

#endif // JUGADOR1_H





