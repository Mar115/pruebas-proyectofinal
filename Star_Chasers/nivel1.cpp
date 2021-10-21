#include "nivel1.h"

nivel1::nivel1(int width, int heigth)
{
    h = heigth;
    w = width;

    QPixmap entrada(":/new/prefix1/images/mapa1.png");
    setPixmap(entrada.scaled(w,h));

}

int nivel1::get_h()
{
    return h;
}

