#include "proyectil.h"

proyectil::proyectil(int a)
{
    if(a == 1) proyectil_.load(":/new/prefix1/images/proyectil_.jpg");
    else if(a == 2) proyectil_.load(":/new/prefix1/images/shoot_2.png");
    else if (a==3) proyectil_.load(":/new/prefix1/images/proyectil_Jf.png");
}

void proyectil::set_imagen()
{
    setPixmap(proyectil_.scaled(scalex,scaley));
}

void proyectil::set_scale(int a, int b)
{
    scalex = a;
    scaley = b;
}

void proyectil::movimiento_parabolico()
{
    float x,y;

    x = xo+vxo*n*(0.001*T);
    y = yo+vyo*n*(0.001*T)-0.5*g*n*(0.001*T)*n*(0.001*T);

    //p->setPos(int(x),int(h-y-p->get_h()));
    n++;
}

bool proyectil::activar(QList<enemigo1 *> *lista_enemigos, QGraphicsScene *escena)
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

bool proyectil::activar_JF(QList<jugador1 *> *lista_jugadores, QGraphicsScene *escena)
{
    bool bandera=false;
    for (int i=0; i<lista_jugadores->size(); i++){
        if(collidesWithItem(lista_jugadores->at(i))){
            /*escena->removeItem(lista_jugadores->at(i));
            delete lista_jugadores->at(i);
            lista_jugadores-> removeAt(i);*/
            bandera=true;
        }
    }
    return bandera;
}

void proyectil::movimiento_proyectil(QList<proyectil *> lista_proyectiles, int a)
{
    if (a==1){
        for(int i = 0; i<lista_proyectiles.size(); i++){
            lista_proyectiles[i]->setX(lista_proyectiles[i]->x()+5);  //SE MUEVE DE MANERA RECTILINEA
        }
    }
    else if (a==2) {
        for(int i = 0; i<lista_proyectiles.size(); i++){
            lista_proyectiles[i]->setX(lista_proyectiles[i]->x()-5);  //SE MUEVE DE MANERA RECTILINEA
        }
    }

}

void proyectil::generar_movParabolico()
{
    float x,y;
    x = xo+vxo*n*(0.001*T);
    y = yo+vyo*n*(0.001*T)-0.5*g*n*(0.001*T)*n*(0.001*T);
    n++;
}




