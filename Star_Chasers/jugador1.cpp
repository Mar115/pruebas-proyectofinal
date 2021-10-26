#include "jugador1.h"

jugador1::jugador1(bool modo)
{
    if(modo){
    img.load(":/new/prefix1/images/personaje1.png");
    }
    else{
        img.load(":/new/prefix1/images/personaje2_.png");
    }
    time = new QTimer;
    connect(time,SIGNAL(timeout()),this,SLOT(tiempo_mov()));
}

jugador1::~jugador1()
{
    delete time;
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

void jugador1::movimientoJugador(bool band)
{

    bandera = band;
    if(controla == false){
        time->start(70);
        controla = true;
    }
}

void jugador1::tiempo_mov()
{
    if(bandera){
        if(y()>0){
           setY(y()-5);
        }
    }
    else setY(y()+5);
}

