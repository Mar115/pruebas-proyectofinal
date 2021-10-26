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

#include "jugador1.h"
#include "jugador2.h"
#include "enemigo1.h"
#include "window2.h"
#include "proyectil.h"
#include "asteroide.h"

#define tam 50
#define cantidad_enemigos 1
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
     void nivel();
     void vidas();
     void puntaje();

     int contador = 180;
     int puntaje1 =  0;
     int puntaje2 =  0;
     int vida     =  6;
     bool cambiar = false;

    ~inicio();

private slots:
   void movimientos_enemigos();
   void ActivarMov_proyectil();
   void ActivarMov_proyectil_JF();

   //void activar_jefe();
   void tiempo();

   void movimiento_jefe();
   void movimientoProyectil_jefe();
   void movimientos_asteroides();

public slots:
   void colisiones(QList<proyectil *> &l, int a);

private:
    Ui::inicio *ui;
    QGraphicsScene *scene1, *scene2;

    window2 *mapa_1, *mapa_2;
    jugador1 *personaje_;  //Jugador 1
    jugador1 *personaje2_; //Jugador 2

    QList<enemigo1*> lista_enemigos;        //Lista de enemigos
    QList<proyectil *> lista_proyectiles;   //Lista de proyectiles Jugador 1
    QList<proyectil *> lista_proyectilesJ2; //Lista de proyectiles Jugador 2
    QList<proyectil *> lista_proyectilesJF; //Lista de proyectiles jefe final
    QList <jugador1 *> jugadores;

    enemigo1 *jefe_final;

    proyectil *proyect_; //Proyectil Jugador 1
    proyectil *proyect2; //Proyectil Jugador 2
    proyectil *proyect3; //Proyectil jefe final


    QList<asteroide*> lista_asteroides;    

    //timers usados en esta clase:
    QTimer *time_enemy1, *time_enemyFinal;
    QTimer *Time_Proyec, *Time_ProyecJF;
    QTimer *tempo;

    float xo,yo, vxo = 4.5, vyo = 5, g = 1, T = 1; //velocidad(x,y) y gravedad constantes, posicion(x,y) varían
    unsigned long long n=0;
    float x,y;

    bool vivo=true;
    short cambio=1;



    };

#endif // INICIO_H
