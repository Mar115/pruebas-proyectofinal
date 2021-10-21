#include "jugador1.h"

jugador1::jugador1()
{
    img.load(":/new/prefix1/images/nave.png");
}


void jugador1::set_imagen()
{
     setPixmap(img.scaled(scalex,scaley));
}


void jugador1::set_scale(int a, int b)
{
    scalex=a; //cantidad de pixeles
    scaley=b;
}


