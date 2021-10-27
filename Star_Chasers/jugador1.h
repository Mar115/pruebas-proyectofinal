#ifndef JUGADOR1_H
#define JUGADOR1_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QList>
#include "enemigo1.h"
#include <QGraphicsScene>

#define tam 50

class jugador1 : public QObject, public QGraphicsPixmapItem //Herencia
{
    Q_OBJECT
public:
    jugador1(bool modo);
    ~jugador1();

    void set_imagen();
    void set_scale(int a, int b);
    void movimientoJugador(bool band);

    bool activar_enemigos(QList<enemigo1 *> *lista_enemigos, QGraphicsScene *escena);

public slots:
    void tiempo_mov();

private:
    QPixmap img;
    QTimer *time;

    int scalex = 1, scaley=1;
    bool bandera = false;
    bool controla = false;

};

#endif // JUGADOR1_H

