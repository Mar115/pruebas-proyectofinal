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

#include "nivel1.h"
#include "jugador1.h"
#include "enemigo1.h"
#include "window2.h"

#define tam 50
#define cantidad_enemigos 10

namespace Ui {
class inicio;
}

class inicio : public QMainWindow
{
    Q_OBJECT

public:
    explicit inicio(QWidget *parent = nullptr);
     void setup_scene1();
     void keyPressEvent(QKeyEvent *tecla);
     void generar_enemy(QList<enemigo1*> lista_enemigos);

    ~inicio();

private slots:
   void movimientos_enemigos();

private:
    Ui::inicio *ui;
    QGraphicsScene *scene1;
    //QGraphicsView *View2;

    int h;    
    window2 *mapa_1;
    jugador1 *personaje_;    
    QTimer *time_enemy1;
    QList<enemigo1*> lista_enemigos;

};

#endif // INICIO_H
