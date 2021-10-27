#ifndef JUGADOR2_H
#define JUGADOR2_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include <QPixmap>

class jugador2 : public QObject, public QGraphicsPixmapItem //Herencia
{
public:
    jugador2();

    void set_imagen();
    void set_scale(int a, int b);

private:
    QPixmap img;
    int scalex = 1, scaley=1;
};

#endif // JUGADOR2_H
