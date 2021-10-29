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
    void movimientos_asteroides();
    void setCenter(int a, int b);
    int size;

private:
    QPixmap asteroide_;
    int scalex =1, scaley= 1;
    int aleatX, aleatY, N;

};

#endif // ASTEROIDE_H
