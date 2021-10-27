#include "enemigo1.h"
#include <QTimer>

enemigo1::enemigo1()
{
    enemy1.load(":/new/prefix1/images/enemigo1.png");
    enemy2.load(":/new/prefix1/images/enemigo2.png");
    jefe_final.load(":/new/prefix1/images/jefe.png");
}

void enemigo1::set_imagen(int a)
{
    if (a==1) setPixmap(enemy1.scaled(scalex,scaley));
    if (a==2) setPixmap(enemy2.scaled(scalex,scaley));
    if (a==3) setPixmap(jefe_final.scaled(scalex,scaley));
}

void enemigo1::set_scale(int a, int b)
{
    size=a;
    scalex=a;
    scaley=b;
}

#include "enemigo1.h"

