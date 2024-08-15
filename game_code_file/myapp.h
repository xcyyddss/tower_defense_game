#ifndef MYAPP_H
#define MYAPP_H

#include<game.h>
#include<frontboard.h>
#include<levelboard.h>
#include<mapload_board.h>
#include<mapmake_board.h>
#include<levelmake_board.h>

class myapp: public QObject{
    Q_OBJECT
private:
    game* g;
    frontboard* f;
    levelboard* l;
    mapload_board* m;
    mapmake_board* mm;
    levelmake_board* lm;
public:
    myapp(QWidget* ws){w=ws;g=NULL;f=NULL;l=NULL;m=NULL;mm=NULL;lm=NULL;}
    QWidget* w;
    void work();
public slots:
    void to_game(int);
    void to_frontboard();
    void to_levelboard();
    void to_mapload_board();
    void to_mapmake_board();
    void to_levelmake_board();
    void quit_send();
signals:
    void quit();
};

#endif // MYAPP_H
