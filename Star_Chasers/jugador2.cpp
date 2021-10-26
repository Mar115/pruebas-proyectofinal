#include "jugador2.h"

jugador2::jugador2()
{
    img.load(":/new/prefix1/images/personaje2_.png");
}

void jugador2::set_imagen()
{
    setPixmap(img.scaled(scalex,scaley));
}

void jugador2::set_scale(int a, int b)
{
    scalex=a; //cantidad de pixeles
    scaley=b;
}
