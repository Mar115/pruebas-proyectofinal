#include "inicio.h"
#include "ui_inicio.h"
#include "mainwindow.h"

inicio::inicio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::inicio)
{
    ui->setupUi(this);
   // QGraphicsView *View3;
   // h=ui->View3->height();
    setup_scene1();
}

void inicio::setup_scene1()
{
    srand(time(NULL)); //crear la semilla para el # aleatorio

    time_enemy1 = new QTimer; //timer para el enemigo
    connect(time_enemy1,SIGNAL(timeout()),this,SLOT(movimientos_enemigos()));
    //time_enemy1->start(50);


     scene1 = new QGraphicsScene;
    /* mapa_1 = new nivel1(ui->View2->width()-2,ui->View2->height()-2);
     scene1->setSceneRect(0,0,ui->View2->width()-2,ui->View2->height()-2);
     ui->View2->setScene(scene1);
     scene1->addItem(mapa_1);*/

     personaje_ = new jugador1;
     personaje_->set_scale(tam,tam);
     personaje_->setPos(0 ,0);
     personaje_->set_imagen();
     scene1->addItem(personaje_);

     for (int i=0;i<cantidad_enemigos;i++){//generar los enemigos
            enemy1[i] = new enemigo1;
            generar_enemy( enemy1[i]);
        }
     time_enemy1->start(10000);
}

void inicio::keyPressEvent(QKeyEvent *tecla)
{
    //el movimiento de un solo jugador se da con las teclas W S y se dispara con la tecla R
    //int x =personaje_->x(), y=personaje_->y(); //posicion xy del personaje (esto se usa para el disparo)

    if (tecla-> key() == Qt:: Key_W) {  //movimiento hacia arriba
     personaje_-> setY(personaje_->y()-5);
    }
    if (tecla-> key() == Qt:: Key_S) { //movimiento hacia abajo
        personaje_-> setY(personaje_->y()+5);
    }

    if (tecla-> key() == Qt::Key_R){ //aqui se anade el objeto de la clase disparo
       /* bombX->set_scale(tam,tam);
        bombX->setPos(x,y); //xy del personaje
        scene->addItem(bombX);
        timer->start(3000);//eliminar la bomba
        bombX->timer-> start (250);// empezar a palpitar*/
    }

    //el movimiento del segundo jugador se da con las flechas de arriba y abajo y se dispara con la tecla P
}

void inicio::generar_enemy(enemigo1 *enemigo)
{
    int aleatorioY = rand()%562;  //cambiar
    enemigo->set_scale(tam,tam);
    enemigo->setPos(900, aleatorioY);
    enemigo->set_imagen();
    scene1->addItem(enemigo);
}

void inicio::movimientos_enemigos()
{
    //si el personaje toca al enemigo -> eliminar personaje
    for (int i=0; i<cantidad_enemigos; i++){

        int posX= enemy1[i]->x();// posY=enemy1[i]->y();
        enemy1[i]-> setX(enemy1[i]->x()-5);//PARA LA IZQUIERDA

       /* esto lanza error
            if(posX<0){
            scene1->removeItem( enemy1[i]);
           // delete this;
        }*/

        //si el personaje toca al enemigo -> eliminar personaje
        if (enemy1[i]->x()+tam >= personaje_->x() && enemy1[i]->x()-tam <=personaje_->x() && enemy1[i]->y()== personaje_->y()){
            scene1->removeItem(personaje_);
           //TERMINAR JUEGO, mostrar un cuadro de dialogo de que perdio
        }
        if (enemy1[i]->y()+tam >= personaje_->y() && enemy1[i]->y()-tam <=personaje_->y() && enemy1[i]->x()== personaje_->x()){
            scene1->removeItem(personaje_);
           //TERMINAR JUEGO

        }
    }
}

inicio::~inicio()
{
    delete ui;
}
