#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inicio.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    h=ui->View2->height();
    setup_scene2();

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
    delete datos_vida_score;
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
    Window2 = new QMainWindow(this);//el this depende de la clase mainwindow
    View2 = new QGraphicsView(scene2,Window2);
    View2->setGeometry(0,0,800,600);
}

void MainWindow::crear_txt(string name)
{
    fstream text(name+".txt", fstream::out );
    text.close();
}

void MainWindow::escribir_txt(string nombre, string user, string pass)
{

    fstream text(nombre, fstream::out | fstream::app);
    //text << user << "," << pass << "\n";
    text << user << "," << pass << "," << 0 << 0<< "\n";
    text.close();
}

void MainWindow::reescribir_txt(string nombre, string user, string pass, int life, int puntaje)
{
    fstream text(nombre, fstream::out | fstream::app);
    text << user << "," << pass << "," << life << puntaje << "\n";
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
        datos.pop_back(); //elimina el ultimo caracter
    }
    else cout << "el archivo no pudo ser abierto";
    return datos;
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

    escribir_txt(DataBase,usuario_.toStdString(),contrasena_.toStdString());
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
    int coma = 0;

    datos = leer_usuario(DataBase);
    usuario_ = ui->usuario->text();
    contrasena_ = ui->contrasenia->text();
    complete = usuario_.toStdString() + "," + contrasena_.toStdString();
    //cout << complete << endl;
    //cout << datos << endl;
    posicion = datos.find(usuario_.toStdString());
    for (int i = posicion; i<datos.length(); ++i) {
        if(datos[i]==44){
            coma++;
        }
        else if(coma>=1 && coma<2){
            copia += datos[i];
        }
        else if(datos[i] == 10){
            break;
        }
    }

    if(ui->usuario->text().isEmpty() || ui->contrasenia->text().isEmpty()){//Si usuario o contraseña está en blanco, no pase (Doble condicional)
        cout << "¡Lo sentimos!, usuario o clave incorrecta. Vuelve a intentarlo." << endl;
        ui->usuario->clear();
        ui->contrasenia->clear();
        ui->usuario->setEnabled(true);
        ui->contrasenia->setEnabled(true);
        usuario_.clear();
        contrasena_.clear();
        complete.clear();

    }
    //TENGO QUE MEJORAR ESTE CONDICIONAL YA QUE NO ESTÁ FUNCIONANDO.
    else if(datos.find(complete)!=string::npos){//Si es diferente, pertenece al string (npos)
        if(contrasena_.toStdString() == copia){
            cout << "Bienvenido..." << endl;

            //Llamar a la clase que contiene la escena del juego
            inicio * Inicio = new inicio ();
            Inicio-> show();
            //ui->View2->hide();
            close();
        }
        else{
            cout << "Lo sentimos!, usuario o clave incorrecta. Vuelve a intentarlo."  << endl;
            ui->usuario->clear();
            ui->contrasenia->clear();
            ui->usuario->setEnabled(true);
            ui->contrasenia->setEnabled(true);
            usuario_.clear();
            contrasena_.clear();
            complete.clear();
        }
    }
    else{
        cout << "Lo sentimos!, usuario o clave incorrecta. Vuelve a intentarlo." << endl;
        ui->usuario->clear();
        ui->contrasenia->clear();
        ui->usuario->setEnabled(true);
        ui->contrasenia->setEnabled(true);
        usuario_.clear();
        contrasena_.clear();
        complete.clear();
    }
}
