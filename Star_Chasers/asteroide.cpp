#include "asteroide.h"

asteroide::asteroide()
{
    asteroide_.load(":/new/prefix1/images/asteoroide.jpeg");
}

asteroide::~asteroide()
{
    delete time_asteroide;
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

/*void asteroide::movimiento_circular()
{



    time_asteroide = new QTimer;
    connect(time_asteroide, SIGNAL(timeout()), this, SLOT(generar_movimiento()));
    time_asteroide->start(70);
}*/

void asteroide::generar_movimiento(QList<asteroide *> lista_asteroides, int Xo, int Yo, int r)
{
    //posX = Xo;
    //posY = Yo;
    //R = r;

    //X = R*cos(w*N*T) + posX;
    //Y = R*sin(w*N*T) + posY;
    N++;
    qDebug() << "ok" ;

    for(int i=0; i<lista_asteroides.size(); i++){
        //(lista_asteroides[i]->setX(lista_asteroides[i]->X),lista_asteroides[i]->setY(lista_asteroides[i]->Y));
        //lista_asteroides[i]->setX(lista_asteroides[i]->X);
        //lista_asteroides[i]->setY(lista_asteroides[i]->Y);
        //setPos(X,Y);
        //setPos(X,Y);
        //setY(lista_asteroides.y());
        lista_asteroides[i]->setX(lista_asteroides[i]->x()-5);

    }
}


/*
    X= R(circulo)*Cos(wNT)+ Xo
    Y= R(circulo)*Sen(wNT)+ Yo
    N-->contador --- > trabajarlo como entero
    */
