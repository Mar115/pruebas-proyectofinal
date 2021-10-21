#include "enemigo1.h"
#include <QTimer>

enemigo1::enemigo1()
{
     enemy1.load(":/new/prefix1/images/enemigo1.png");

     /* time_enemy1 = new QTimer; //timer para el enemigo
     connect(time_enemy1,SIGNAL(timeout()),this,SLOT(move()));
     time_enemy1->start(50);*/
}

void enemigo1::set_imagen()
{
    setPixmap(enemy1.scaled(scalex,scaley));
}

void enemigo1::set_scale(int a, int b)
{
    scalex=a;
    scaley=b;
}

#include "enemigo1.h"

