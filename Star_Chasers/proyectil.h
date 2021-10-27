#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "enemigo1.h"
#include "jugador1.h"

#include <QList>
#include <QGraphicsScene>

class proyectil: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    proyectil(int a);

    void set_imagen();
    void set_scale(int a, int b);
    void movimiento_parabolico();

public slots:
    bool activar(QList <enemigo1 *> *lista_enemigos, QGraphicsScene *escena);
    bool activar_JF (QList<jugador1 *> *lista_jugadores, QGraphicsScene *escena);

    void movimiento_proyectil(QList<proyectil *> lista_proyectiles, int a );
    void generar_movParabolico();

private:
    QPixmap proyectil_;
    int scalex =1, scaley= 1;

    //Variables para las ecuaciones de movimiento parabólico
    float xo,yo, vxo = 4.5, vyo = 5, g = 1, T = 1; //velocidad(x,y) y gravedad constantes, posicion(x,y) varían
    unsigned long long n=0;
};

#endif // PROYECTIL_H
