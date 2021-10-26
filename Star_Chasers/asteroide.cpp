#include "asteroide.h"

asteroide::asteroide()
{
    asteroide_.load(":/new/prefix1/images/asteoroide.jpeg");
}

void asteroide::set_imagen()
{
    setPixmap(asteroide_.scaled(scalex,scaley));
}

void asteroide::set_scale(int a, int b)
{
    size=a;
    scalex = a;
    scaley = b;
}

void asteroide::movimiento_circular(int Xo, int Yo, int R)
{
    X = R*cos(w*N*T) + Xo;
    Y = R*sin(w*N*T) + Yo;
}


/*
    X= R(circulo)*Cos(wNT)+ Xo
    Y= R(circulo)*Sen(wNT)+ Yo
    N-->contador --- > trabajarlo como entero
    */
