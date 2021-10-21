#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "siguiente.h"
//#include "inicio.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    h=ui->View2->height();
    setup_scene2();

    //ui->View3->setEnabled(false);
    ui->AgregarDatos->setEnabled(false);
    ui->usuario->setEnabled(false);
    ui->contrasenia->setEnabled(false);
    ui->Start->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene1;
    delete scene2;
    delete Window2;
}

void MainWindow::setup_scene1()
{
    srand(time(NULL)); //crear la semilla para el # aleatorio

    time_enemy1 = new QTimer; //timer para el enemigo
    connect(time_enemy1,SIGNAL(timeout()),this,SLOT(movimientos_enemigos()));
    //time_enemy1->start(50);


     scene1 = new QGraphicsScene;
     mapa_1 = new nivel1(ui->View2->width()-2,ui->View2->height()-2);
     scene1->setSceneRect(0,0,ui->View2->width()-2,ui->View2->height()-2);
     ui->View2->setScene(scene1);
     scene1->addItem(mapa_1);

     personaje_ = new jugador1;
     personaje_->set_scale(tam,tam);
     personaje_->setPos(0 ,0);
     personaje_->set_imagen();
     scene1->addItem(personaje_);

     for (int i=0;i<cantidad_enemigos;i++){//generar los enemigos
            enemy1[i] = new enemigo1;
            generar_enemy( enemy1[i]);
        }
     time_enemy1->start(50);


    /*scene1 = new QGraphicsScene;
    wind2 = new window2(600,800,2);
    scene1->setSceneRect(0,0,600,800);
    ui->View2->setScene(scene1);
    scene1->addItem(wind2);*/

}

void MainWindow::setup_scene2()
{
    scene2 = new QGraphicsScene;
    wind2 = new window2(ui->View2->width()-2,ui->View2->height()-2,1);
    scene2->setSceneRect(0,0,ui->View2->width()-2,ui->View2->height()-2);
    ui->View2->setScene(scene2);
    scene2->addItem(wind2);
}

void MainWindow::setup_window2()
{

    //PASOS: 1.Configurar la escena
    //       2.Configurar la

    Window2 = new QMainWindow(this);//el this depende de la clase mainwindow
    //esta ventana va depender de la principal

    View2 = new QGraphicsView(scene2,Window2);
    View2->setGeometry(0,0,800,600);
}

void MainWindow::crear_txt(string name)
{
    fstream text(name+".txt", fstream::out );
    text.close();
}

void MainWindow::escribir_txt(string nombre, string user, string pass, int vidas)
{

    fstream text(nombre, fstream::out | fstream::app);
    text << "{" << user << "," << pass << "," << vidas << "}" << "\n";
    text.close();
}

string MainWindow::leer_usuario(string name)
{
    string datos;
    fstream text;
    text.open(name, fstream::in);    
    if(text.is_open()){
        while(!text.eof()){
            datos.push_back(text.get());
        }
    }
    else cout << "el archivo no pudo ser abierto";
    return datos;
    //

}

void MainWindow::on_AgregarDatos_clicked()
{
    QString usuario_;
    QString contrasena_;
    string complete;
    usuario_ = ui->usuario->text();
    contrasena_ = ui->contrasenia->text();    

    ui->usuario->setEnabled(false);
    ui->contrasenia->setEnabled(false);

    ui->Registrar->setEnabled(false);
    ui->Start->setEnabled(false);
    ui->IniciarSesion->setEnabled(true);

    escribir_txt(DataBase,usuario_.toStdString(),contrasena_.toStdString(), vidas);
}

void MainWindow::on_Registrar_clicked()
{
    ui->IniciarSesion->setEnabled(false);
    ui->usuario->setEnabled(true);
    ui->contrasenia->setEnabled(true);
    ui->AgregarDatos->setEnabled(true);
}


void MainWindow::on_IniciarSesion_clicked()
{
    ui->Registrar->setEnabled(false);
    ui->usuario->clear();
    ui->contrasenia->clear();
    ui->usuario->setEnabled(true);
    ui->contrasenia->setEnabled(true);
    ui->AgregarDatos->setEnabled(false);
    ui->Start->setEnabled(true);
    ui->IniciarSesion->setEnabled(false);
}

void MainWindow::on_Start_clicked()
{
    QString usuario_;
    QString contrasena_;
    string complete, datos, copia;
    size_t posicion;
    bool control = true;
    //int coma = 0;
    datos = leer_usuario(DataBase);
   // while (control) {
        usuario_ = ui->usuario->text();
        contrasena_ = ui->contrasenia->text();
        //variables
        complete = usuario_.toStdString() + "," + contrasena_.toStdString();

        if(datos.find(complete)!=string::npos){//Si es diferente, pertenece al string (npos)
            cout << "Bienvenido..." << endl;

            control = false;
            //posicion = datos.find(complete);
            /*
            for(unsigned long c = posicion; c < datos.size(); c++){
                copia += datos[c];
            }

            for(unsigned long int i=0; i < copia.length(); ++i){
                if(copia[i]==44){
                    coma++;
                }
                if(coma==2){

                }
            }*/
        }
        else{
            cout << "El usuario ingresado no esta registrado en la base de datos..." << endl;
            ui->usuario->clear();
            ui->contrasenia->clear();
            ui->usuario->setEnabled(true);
            ui->contrasenia->setEnabled(true);
            usuario_.clear();
            contrasena_.clear();
            complete.clear();
        }
        //this->hide();
       // ui->View2->hide();

       //creacion de la otra ventana
        /*siguiente * mainWindow = new siguiente ();
        mainWindow-> show();
        close();*/

        /*borra los botones pero no las letras
        ui->AgregarDatos->hide();
        ui->Registrar->hide();
        ui->usuario->hide();
        ui->contrasenia->hide();
        ui->Start->hide();
        ui->IniciarSesion->hide();*/

       /* inicio * Inicio = new inicio ();
        Inicio-> show();
        close();*/

        setup_scene1();

    //}
}

void MainWindow::keyPressEvent(QKeyEvent *tecla) //movimiento del jugador
{
   //el movimiento de un solo jugador se da con las teclas W S y se dispara con la tecla R
   //int x =personaje_->x(), y=personaje_->y(); //posicion xy del personaje (esto se usa para el disparo)

   if (tecla-> key() == Qt:: Key_W) {  //movimiento hacia arriba
       if ( personaje_->y()-(tam)>0){
           personaje_-> setY(personaje_->y()-5);
       }

   }
   if (tecla-> key() == Qt:: Key_S) { //movimiento hacia abajo
       if (personaje_->y()+(tam)<ui->View2->height()-2){
           personaje_-> setY(personaje_->y()+5);
       }

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


void MainWindow::generar_enemy(enemigo1 *enemigo) //crea los puntos xy aleatorios de cada enemigo
{

    int aleatorioX=(rand()%941) +1000 , aleatorioY = rand()%(562-2*tam)+tam;  //cambiar//941
    enemigo->set_scale(tam,tam);
    enemigo->setPos(aleatorioX, aleatorioY);
    enemigo->set_imagen();
    scene1->addItem(enemigo);
}



void MainWindow::movimientos_enemigos()
{
    //si el personaje toca al enemigo -> eliminar personaje
    for (int i=0; i<cantidad_enemigos; i++){

        //int posX= enemy1[i]->x();// posY=enemy1[i]->y();
        enemy1[i]-> setX(enemy1[i]->x()-5);//PARA LA IZQUIERDA

       /* esto lanza error
            if(posX<0){
            scene1->removeItem( enemy1[i]);
           // enemy1[i]->remove();

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
