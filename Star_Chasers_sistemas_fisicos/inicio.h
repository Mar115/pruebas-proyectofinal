#ifndef INICIO_H
#define INICIO_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QString>
#include <iostream>
#include <fstream>
#include <QList>
#include <math.h>
#include <QObject>
#include<QGraphicsItem>

//#include<QSoundEffect>
#include <QMediaPlayer>

#include "jugador1.h"
#include "enemigo1.h"
#include "window2.h"
#include "proyectil.h"
#include "asteroide.h"

#include  "dialog.h"


//#include "variables_globales.h"

#define tam 50
#define cantidad_enemigos 10
#define cantidad_asteroides 3

namespace Ui {
class inicio;
}

class inicio : public QMainWindow
{
    Q_OBJECT

public:
     explicit inicio(QWidget *parent = nullptr);
     void setup_scene1();
     void setup_scene2();
     void keyPressEvent(QKeyEvent *tecla);
     void KeyReleaseEvent(QKeyEvent *tecla);
     void generar_asteroide(QList<asteroide *> lista_asteroide);
     void generar_enemy(QList<enemigo1*> lista_enemigos);
     void generar_proyectil_JF();
     void puntaje();

     int contador = 180;
     int puntaje1 =  0;
     int contadorJF = 0;
     int puntaje2 = 0;
     int vida     = 6;
     int nivel_   = 1;
     int contador_jefe=0;

     bool cambiar = false;
     bool vivo=true;
     bool escena_de_disparos = true;

     short cambio=1;

    ~inicio();

private slots:
   void movimientos_enemigos();
   void ActivarMov_proyectil();
   void activar_colisiones();
   void tiempo();
   void movimiento_jefe();
   void movimientoProyectil_jefe();
   void movimientos_asteroides();

public slots:
   void colisiones(QList<proyectil *> &l, int a);
   void colisiones_enemigos (QList<jugador1 *> &l);

private:
    Ui::inicio *ui;
    QGraphicsScene *scene1, *scene2;

    QList<enemigo1*> lista_enemigos;        //Lista de enemigos
    QList<proyectil *> lista_proyectiles;   //Lista de proyectiles Jugador 1
    QList<proyectil *> lista_proyectilesJ2; //Lista de proyectiles Jugador 2
    QList<proyectil *> lista_proyectilesJF; //Lista de proyectiles jefe final
    QList<asteroide*> lista_asteroides;     //Lista de asteroides
    QList <jugador1 *> jugadores;

    window2 *mapa_1, *mapa_2;
    jugador1 *personaje_;  //Jugador 1
    jugador1 *personaje2_; //Jugador 2
    enemigo1 *jefe_final;
    proyectil *proyect_; //Proyectil Jugador 1
    proyectil *proyect2; //Proyectil Jugador 2
    proyectil *proyect3; //Proyectil jefe final
    asteroide *asteroide_;   

    //timers usados en esta clase:
    QTimer *time_enemy1, *time_enemyFinal;
    QTimer *Time_Proyec, *Time_ProyecJF;
    QTimer *tempo, *timer_prueba, *timer_colision;

    //sonido
    QMediaPlayer *bsound;

    };

#endif // INICIO_H
