#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <math.h>
#include <QTimer>
#include <QDebug>

class asteroide : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT   
public:
    asteroide();
    ~asteroide();   
    void set_imagen();
    void set_scale(int a, int b);
    //void movimiento_circular(int Xo, int Yo, int r);

    int size;

public slots:
    void generar_movimiento(QList<asteroide *> lista_asteroides, int Xo, int Yo, int r);

private:
    QPixmap asteroide_;
    QTimer *time_asteroide;

    int scalex =1, scaley= 1;
    int N=1, R, T=1, posX, posY, X, Y, w=1; //w frecuencia angular

};

#endif // ASTEROIDE_H
