#include "cuadros_de_dialogo.h"

cuadros_de_dialogo::cuadros_de_dialogo(int width, int heigth)
{
    h = heigth;
    w = width;
    QPixmap gameOver(":/new/prefix1/images/game_over.jpg");
    setPixmap(gameOver.scaled(w,h));
}

int cuadros_de_dialogo::get_h()
{
    return h;
}

