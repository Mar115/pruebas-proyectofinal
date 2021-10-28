#include "jugador1.h"

jugador1::jugador1(bool modo, int a, int b)
{
    if(modo){
    img.load(":/new/prefix1/images/personaje1.png");
    }
    else{
        img.load(":/new/prefix1/images/personaje2_.png");
    }
    time = new QTimer;
    connect(time,SIGNAL(timeout()),this,SLOT(tiempo_mov()));

    inferior = a;
    derecho = b;
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

void jugador1::movimientoJugador_AD(bool band)
{
    bandera2 = band;
    if(controla2 == false){
        time->start(70);
        controla2 = true;
    }
}

bool jugador1::activar_enemigos(QList<enemigo1 *> *lista_enemigos, QGraphicsScene *escena)
{
    bool bandera = false;
        for(int i=0; i<lista_enemigos->size(); i++){
            if(collidesWithItem(lista_enemigos->at(i))){
                escena->removeItem(lista_enemigos->at(i));
                // se elimina de la escena
                delete lista_enemigos->at(i);
                lista_enemigos->removeAt(i); //se elimina del contenedor
                bandera = true;
            }
        }
        return bandera;
}

void jugador1::tiempo_mov()
{
    if(bandera && y()>0 ){
           setY(y()-5);        
    }
    else if (y()+(tam) < inferior) {
        setY(y()+5);}
    if(bandera2 && x()>0){
           setX(x()-5);
    }
    else if(x()+tam < derecho){
        setX(x()+5);
    }
}
