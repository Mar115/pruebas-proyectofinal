#include "inicio.h"
#include "ui_inicio.h"
//#include "mainwindow.h"

inicio::inicio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::inicio)
{
    ui->setupUi(this);    
    tempo = new QTimer(this);
    connect(tempo, SIGNAL(timeout()),this,SLOT(tiempo()));
    tempo->start(1000);
    setWindowTitle("Star Chasers");

    srand(time(NULL)); //crear la semilla para el # aleatorio
    setup_scene1();
    //activar_jefe();
}

inicio::~inicio()
{
    delete ui;
    delete scene1;
    delete proyect_;
    delete Time_Proyec;
    delete tempo;
    delete personaje_;
    delete personaje2_;
    delete proyect2;
    delete proyect3;
    delete Time_ProyecJF;
   // delete asteroide;
}

void inicio::setup_scene1()
{
    //Funcion que se encarga de añadir objetos a la escena

    time_enemy1 = new QTimer; //timer para el enemigo
    connect(time_enemy1,SIGNAL(timeout()),this,SLOT(movimientos_enemigos()));

    Time_Proyec = new QTimer; // timer para el proyectil
    connect(Time_Proyec,SIGNAL(timeout()),this,SLOT(ActivarMov_proyectil()));

     scene1 = new QGraphicsScene;
     mapa_1 = new window2(ui->View2->width()-2,ui->View2->height()-2,2);
     scene1->setSceneRect(0,0,ui->View2->width()-2,ui->View2->height()-2);
     ui->View2->setScene(scene1);
     scene1->addItem(mapa_1);

     //creacion del personaje
     personaje_ = new jugador1(true);
     personaje_->set_scale(tam,tam);
     personaje_->setPos(0 ,0);
     personaje_->set_imagen();
     scene1->addItem(personaje_);

     jugadores.push_back(personaje_);

     //creacion personaje2
     personaje2_ = new jugador1(false);
     personaje2_->set_scale(tam,tam);
     personaje2_->setPos(0, ui->View2->height()-tam);
     personaje2_->set_imagen();
     scene1->addItem(personaje2_);

     jugadores.push_back(personaje2_);

     //creacion de los enemigos
     enemigo1 *enemigo;
     for (int i=0;i<cantidad_enemigos;i++){
            enemigo=new enemigo1;
            lista_enemigos.push_back(enemigo);
     }
     generar_enemy( lista_enemigos);
     time_enemy1->start(30);

     //creacion de los asteroides
     asteroide *asteroide_;
     for (int j=0;j<cantidad_asteroides;j++ ) {
         asteroide_=new asteroide;
         lista_asteroides.push_back(asteroide_);
     }
     generar_asteroide( lista_asteroides);

}

void inicio::setup_scene2()
{
    time_enemyFinal = new QTimer; //timer para el jefe final
    connect(time_enemyFinal,SIGNAL(timeout()),this,SLOT(movimiento_jefe()));

    Time_ProyecJF = new QTimer; // timer para el proyectil del jefe final
    connect(Time_ProyecJF,SIGNAL(timeout()),this,SLOT(ActivarMov_proyectil_JF()));

    scene2 = new QGraphicsScene;
    mapa_2 = new window2(ui->View2->width()-2,ui->View2->height()-2,3);
    scene2->setSceneRect(0,0,ui->View2->width()-2,ui->View2->height()-2);
    ui->View2->setScene(scene2);
    scene2->addItem(mapa_2);
    ui->View2->show();

    personaje_ = new jugador1(true);
    personaje_->set_scale(tam,tam);
    personaje_->setPos(0 ,0);
    personaje_->set_imagen();
    scene2->addItem(personaje_);

    //creacion personaje2
    personaje2_ = new jugador1(false);
    personaje2_->set_scale(tam,tam);
    personaje2_->setPos(0, ui->View2->height()-tam);
    personaje2_->set_imagen();
    scene2->addItem(personaje2_);

    jefe_final = new enemigo1;
    jefe_final->set_scale(tam,tam);
    jefe_final->setPos((ui->View2->width()-2)/2,(ui->View2->height()-2)/2);
    jefe_final->set_imagen(3);
    scene2->addItem(jefe_final);
    time_enemyFinal->start(30);

}

void inicio::keyPressEvent(QKeyEvent *tecla)
{
    //posicion xy del personaje (esto se usa para el disparo)
    /*Funcion para generar el movimiento del personaje a partir de las teclas
    el movimiento de un solo jugador se da con las teclas W S y se dispara con la tecla R*/

    if (tecla-> key() == Qt:: Key_W) {  //movimiento hacia arriba
        if(personaje_->y()>0){
            personaje_->movimientoJugador(true);}
    }

    else if (tecla-> key() == Qt:: Key_S) { //movimiento hacia abajo

        if (personaje_->y()+(tam) < ui->View2->height()-2){
            personaje_->movimientoJugador(false);
        }
    }

    else if ( tecla-> key() == Qt::Key_8){

        if ( personaje2_->y()>0){
            personaje2_->movimientoJugador(true);
        }
    }

    else if ( tecla->key() == Qt::Key_5){
        if (personaje2_->y()+(tam)<ui->View2->height()-2){
            personaje2_->movimientoJugador(false);
        }
    }

    else if (tecla-> key() == Qt::Key_R){ //aqui se anade el objeto de la clase disparo
        proyect_ = new proyectil(1);
        proyect_->set_scale(tam/3,tam/3);
        proyect_->setPos(personaje_->x()+tam*0.38, personaje_->y()+tam*0.38); //Se ubica el proyectil en la posición del personaje
        proyect_->set_imagen();
        scene1->addItem(proyect_);
        lista_proyectiles.push_back(proyect_);
        Time_Proyec->start(40);
    }

    else if ( tecla-> key() == Qt::Key_P){        
        proyect2 = new proyectil(2);
        proyect2->set_scale(tam/3,tam/3);
        proyect2->setPos(personaje2_->x()+tam*0.38, personaje2_->y()+tam*0.38); //Se ubica el proyectil en la posición del personaje
        proyect2->set_imagen();
        scene1->addItem(proyect2);
        lista_proyectilesJ2.push_back(proyect2);
        Time_Proyec->start(40);
    }
    //el movimiento del segundo jugador se da con las flechas de arriba y abajo y se dispara con la tecla P
}

void inicio::ActivarMov_proyectil()
{
    proyect_->movimiento_proyectil(lista_proyectiles,1);
    proyect2->movimiento_proyectil(lista_proyectilesJ2,1);
    //2 casos

    colisiones(lista_proyectiles,1);
    colisiones(lista_proyectilesJ2,1);
}

void inicio::ActivarMov_proyectil_JF()
{
    generar_proyectil_JF();
    proyect3->movimiento_proyectil(lista_proyectilesJF,2);
    colisiones(lista_proyectilesJF,2);
}

void inicio::generar_enemy(QList<enemigo1*> lista_enemigos)
{
    //Funcion que se encarga de generar las posiciones aleatorias de (x,y) para ubicar los enemigos en el juego

    bool bandera=true;
    int aleatorioX, aleatorioY;
    for (int i=0; i<lista_enemigos.size();i++ ){
        lista_enemigos[i]->set_scale(tam,tam);

        //se generarn los numeros aleatorios
        aleatorioX=(rand()%(ui->View2->width()-2))+1000;
        aleatorioY = rand()%((ui->View2->height()-2)-2*tam);

        for (int j=0; j<i ;j++){ //j son los objetos ya creados
           float w=(lista_enemigos[i]->size)*0.5;
           // coordenadas de los centros
           float x1=lista_enemigos[j]->x()+w,x2=aleatorioX+w;
           float y1=lista_enemigos[j]->y()+w,y2=aleatorioY+w;
           float dist=sqrt(pow((x1-x2),2)+pow((y1-y2),2)); //formula de la distancia entre los centros
           //comprobar que las imagenes no esten una encima de otra
           if (dist<=sqrt(2)*lista_enemigos[i]->size) bandera=false;
        }
        if (!bandera) i--; //vuelve a repetir todo el proceso con el mismo elemento
        else {
            lista_enemigos[i]->setPos(aleatorioX, aleatorioY);
            lista_enemigos[i]->set_imagen(1);
            scene1->addItem( lista_enemigos[i]);
        }
        bandera=true;
    }
}

void inicio::generar_proyectil_JF()
{
    proyect3 = new proyectil(3);
    proyect3->set_scale(tam,tam);
    proyect3->setPos(jefe_final->x()+tam*0.38, jefe_final->y()+tam*0.38); //Se ubica el proyectil en la posición del jefe //
    proyect3->set_imagen();
    scene2->addItem(proyect3);
    lista_proyectilesJF.push_back(proyect3);
    Time_ProyecJF->start(40);

}

void inicio::generar_asteroide(QList<asteroide*> lista_asteroides)
{
    //Funcion que se encarga de generar las posiciones aleatorias de (x,y) para ubicar los asteroides en el juego

    bool bandera=true;
    int aleatorioX, aleatorioY;
    for (int i=0; i<lista_asteroides.size();i++ ){
        lista_asteroides[i]->set_scale(tam,tam);

        //se generarn los numeros aleatorios
        aleatorioX=(rand()%(ui->View2->width()-2));
        aleatorioY = rand()%((ui->View2->height()-2)-2*tam);

        for (int j=0; j<i ;j++){ //j son los objetos ya creados
           float w=(lista_asteroides[i]->size)*0.5;
           // coordenadas de los centros
           float x1=lista_asteroides[j]->x()+w,x2=aleatorioX+w;
           float y1=lista_asteroides[j]->y()+w,y2=aleatorioY+w;
           float dist=sqrt(pow((x1-x2),2)+pow((y1-y2),2)); //formula de la distancia entre los centros
           //comprobar que las imagenes no esten una encima de otra
           if (dist<=sqrt(2)*lista_asteroides[i]->size) bandera=false;
        }
        if (!bandera) i--; //vuelve a repetir todo el proceso con el mismo elemento
        else {
            lista_asteroides[i]->setPos(aleatorioX, aleatorioY);
            lista_asteroides[i]->set_imagen();
            scene1->addItem( lista_asteroides[i]);
        }
        bandera=true;
    }
}

void inicio::nivel()
{
    //Condicional para cada vez que pase de nivel aumentar en 1
}

void inicio::vidas()
{
    //Reducir las vidas cada vez que el enemigo toca al jugador o las balas del jefe final tocan al jugador
}

void inicio::colisiones(QList<proyectil *> &l, int a)
{
    if (a==1){
        for (int j=0;j<l.size() ;j++ ) {
            if(l[j]->activar(&lista_enemigos,scene1)){
                scene1->removeItem(l[j]);
                delete l[j];
                l.removeAt(j);
                puntaje1+=100;
            }
        };
        ui->lcdNumber_2->display(puntaje1);
        }

    else {

       for (int i=0; i< l.size(); i++){
           if (l[i]->activar_JF(&jugadores, scene2)){
               scene2->removeItem(l[i]);
               delete l[i];
               l.removeAt(i);
               vida-=1;
           }
       }
       ui->lcdNumber_3->display(vida);
    }
}

void inicio::tiempo()
{
    ui->lcdNumber->display(contador);
    contador -=1;
}

void inicio::movimientos_enemigos()
{
    //Funcion que se encarga de crear los puntos (x,y) aleatorios de cada enemigo


    /*CORREGIR
      for (int i=0; i<lista_enemigos.size(); i++){
        lista_enemigos[i]->set_scale(tam,tam);
        personaje_->set_scale(tam,tam);

        lista_enemigos[i]-> setX(lista_enemigos[i]->x()-5);//PARA LA IZQUIERDA

        float w=(lista_enemigos[i]->size)*0.5;
        float x1=personaje_->x()+w,x2= lista_enemigos[i]->x()+w;
        float y1=personaje_->y()+w,y2= lista_enemigos[i]->y()+w;
        float dist=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
        if (dist<=sqrt(2)*lista_enemigos[i]->size) {
            scene1->removeItem(personaje_);
            vivo=false;
        }*/

    for (int i=0; i<lista_enemigos.size(); i++){
       // bool vivo=true;
        int posX= lista_enemigos[i]->x();// posY=enemy1[i]->y();
        lista_enemigos[i]-> setX(lista_enemigos[i]->x()-5);//PARA LA IZQUIERDA

        if ((personaje_->x()+tam >= lista_enemigos[i]->x()+tam && personaje_->x()-tam <= lista_enemigos[i]->x()+tam) && ((personaje_->y()-tam<=lista_enemigos[i]->y()+tam && personaje_->y()+tam >= lista_enemigos[i]->y()+tam ) || ( personaje_->y()+tam >=  lista_enemigos[i]->y()-tam &&  personaje_->y()+tam <= lista_enemigos[i]->y()+tam))){
            //scene1->removeItem(personaje_);
            //TERMINAR JUEGO, mostrar un cuadro de dialogo de que perdio

            //delete personaje_;//preguntar pq se muere el programa y pq no se pone esto en el destructor!!

            vida-=1;
            ui->lcdNumber_3->display(vida);
            vivo=false;

            //AGREGAR CONDICIONAL

           /* MainWindow * mainwindow = new MainWindow ();
            mainwindow -> show();*/

           // MainWindow w;
           // w.show();

           // close();

        }
        if(posX<0){ //lista_enemigos[i]->x()
            scene1->removeItem( lista_enemigos[i]);
            delete lista_enemigos[i];
            lista_enemigos.removeAt(i);
     }
   }
   if (lista_enemigos.size()==0 && vivo==true){
            //crear un cuadro de dialogo (fase jefe final)
            cambiar = true;
            ui->View2->hide();
            //scene1->removeItem(personaje_);
            //delete personaje_;
            setup_scene2(); // funcion para la fase de jefe final
            vivo=false;
   }
}

void inicio::movimiento_jefe()
{
    //Funcion para generar el movimiento vertical del jefe final
    if ( jefe_final->y()<=0) cambio=1;
    else if ( jefe_final->y()+(tam)>ui->View2->height()-2)cambio=-1;
    jefe_final-> setY(jefe_final->y()+5*cambio);

}

void inicio::movimientoProyectil_jefe()
{
    //definir el movimiento parabólico del jefe final

}

void inicio::movimientos_asteroides()
{
    //Movimiento de manera pedular?

}

/*

//    ECUACIONES DE MOV CIRCULAR UNIFORME:
//    X(n)=(X(n-1)-Cx)*cos(wT)-(Y(n-1)-cy)*sen(wT)+cx
//    Y(n)=(Y(n-1)-Cy)*cos(wT)+(X(n-1)-cx)*sen(wT)+cy
    float aux,auxy;
    aux=posx-cx;
    auxy=posy-cy;
    posx=(aux)*cos(w*t)-(auxy)*sin(w*t)+cx;
    posy=(auxy)*cos(w*t)+(aux)*sin(w*t)+cy;
   // posx=posx+100;

    setPos(int(posx),int(posy));


    X= R(circulo)*Cos(wNT)+ Xo
    Y= R(circulo)*Sen(wNT)+ Yo
    N-->contador --- > trabajarlo como entero
    */


/* ECUACIONES DE MOV PARABOLICO:
 *     float x,y;

    x = xo+vxo*n*(0.001*T);
    y = yo+vyo*n*(0.001*T)-0.5*g*n*(0.001*T)*n*(0.001*T);
    */
