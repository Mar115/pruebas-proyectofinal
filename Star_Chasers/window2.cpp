#include "window2.h"

window2::window2(int width, int heigth, int a)
{
    h = heigth;
    w = width;

    if (a==1){
    QPixmap entrada(":/new/prefix1/images/presentacion.jpeg");
    setPixmap(entrada.scaled(w,h));
    }

    if (a==2){
    QPixmap entrada(":/new/prefix1/images/mapa1.png");
    setPixmap(entrada.scaled(w,h));
    }

    if (a==3){
    QPixmap entrada(":/new/prefix1/images/level2.jpeg");
    setPixmap(entrada.scaled(w,h));
    }


}
int window2::get_h()
{
    return h;
}

