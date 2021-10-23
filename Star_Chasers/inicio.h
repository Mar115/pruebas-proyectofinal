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

#include "jugador1.h"
#include "enemigo1.h"
#include "window2.h"

#define tam 50
#define cantidad_enemigos 3

namespace Ui {
class inicio;
}

class inicio : public QMainWindow
{
    Q_OBJECT

public:
    explicit inicio(QWidget *parent = nullptr);
     void setup_scene1();
     void setup_scene2();//jefe final
     void keyPressEvent(QKeyEvent *tecla);
     void generar_enemy(QList<enemigo1*> lista_enemigos);

    ~inicio();

private slots:
   void movimientos_enemigos();
   void movimiento_jefe();

private:
    Ui::inicio *ui;
    QGraphicsScene *scene1, *scene2;
    //QGraphicsView *View2;

    int h;
    window2 *mapa_1, *mapa_2;
    jugador1 *personaje_;
    QTimer *time_enemy1, *time_enemyFinal;
    QList<enemigo1*> lista_enemigos;
    enemigo1 *jefe_final;

};

#endif // INICIO_H
