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

void asteroide::movimientos_asteroides()
{
    //asteroide_->movimiento_circular(asteroide_->x(),asteroide_->y(),1);
    //asteroide_->generar_movimiento(lista_asteroides);
    //asteroide_->movimiento_circular();
    //asteroide_->generar_movimiento(lista_asteroides,asteroide_->x(),asteroide_->y(),20);
    float  T=0.04, X, Y, w=15;
    int R = 100;

    X = R*cos(w*N*T) + aleatX;
    Y = R*sin(w*N*T) + aleatY;
    N++;
    setPos(int(X),int(Y));
    /*for (int i =0 ;i<lista_asteroides.size() ;i++ ) {
       // posX = lista_asteroides[i]->x();
        //posY = lista_asteroides[i]->y();
        X = R*cos(w*N*T) + centroX;
        Y = R*sin(w*N*T) + centroY;
        N++;
        lista_asteroides[i]->setX(int(X));
        lista_asteroides[i]->setY(int(Y));
    }*/
}

void asteroide::setCenter(int a, int b)
{
    aleatX = a;
    aleatY = b;
}
