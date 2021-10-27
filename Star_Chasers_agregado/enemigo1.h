#ifndef ENEMIGO1_H
#define ENEMIGO1_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>


class enemigo1  : public QObject, public QGraphicsPixmapItem
{
public:
    enemigo1();
    void set_imagen(int a);
    void set_scale(int a, int b); //función que me permite modificar la escala de una imagen
    int size;
    //Generar movimiento del jefe en esta clase
private:
    QPixmap enemy1, imgn, enemy2, jefe_final;
    int scalex = 1, scaley=1;
};

#endif // ENEMIGO1_H
