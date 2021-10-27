#include "asteroide.h"

asteroide::asteroide()
{
    asteroide_.load(":/new/prefix1/images/asteroide.png");
}

asteroide::~asteroide()
{ 
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
