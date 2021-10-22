#include "enemigo1.h"
#include <QTimer>

enemigo1::enemigo1()
{
     enemy1.load(":/new/prefix1/images/enemigo1.png");
}

void enemigo1::set_imagen()
{
    setPixmap(enemy1.scaled(scalex,scaley));
}

void enemigo1::set_scale(int a, int b)
{
    size=a;
    scalex=a;
    scaley=b;
}

#include "enemigo1.h"

