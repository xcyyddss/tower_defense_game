#ifndef LEVELBOARD_H
#define LEVELBOARD_H
#include "widget.h"
#include <QPixmap>
#include<game.h>

class levelboard: public QWidget{
    Q_OBJECT
private:
public:
    levelboard(QWidget *parent = 0);
    but* bs[80];
    game* g;
    void renew();
signals:
    void send();
public slots:
    void game_begin(int);
    void sender(){delete g;emit send();}
};

#endif // LEVELBOARD_H
