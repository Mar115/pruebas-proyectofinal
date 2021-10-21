#ifndef SIGUIENTE_H
#define SIGUIENTE_H

#include <QWidget>

namespace Ui {
class siguiente;
}

class siguiente : public QWidget
{
    Q_OBJECT

public:
    explicit siguiente(QWidget *parent = nullptr);
    ~siguiente();

private:
    Ui::siguiente *ui;

};

#endif // SIGUIENTE_H
