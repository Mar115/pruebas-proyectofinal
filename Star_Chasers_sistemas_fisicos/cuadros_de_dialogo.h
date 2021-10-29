#ifndef CUADROS_DE_DIALOGO_H
#define CUADROS_DE_DIALOGO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>


class cuadros_de_dialogo: public QObject, public QGraphicsPixmapItem
{
public:
    cuadros_de_dialogo(int width, int heigth);
    int get_h();

private:
    int w,h;
};

#endif // CUADROS_DE_DIALOGO_H
