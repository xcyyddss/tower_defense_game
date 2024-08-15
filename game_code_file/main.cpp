#include "widget.h"
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QObject>
#include<myapp.h>


QMovie* bullet_movie_array[7];
QMovie* unit_movie_array[20];
QMovie* tower_movie_array[20];
QMovie* tower_weapon_movie_array[7];
extern lable* grade_lable;
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget* w=new QWidget;
    myapp* m=new myapp(w);
    QObject::connect(m,SIGNAL(quit()),&app,SLOT(quit()));
    m->work();

    unit_movie_array[1]=new QMovie("./project2_movie/unit/u_n_1.gif");
    unit_movie_array[2]=new QMovie("./project2_movie/unit/u_n_2.gif");
    unit_movie_array[3]=new QMovie("./project2_movie/unit/u_n_3.gif");
    unit_movie_array[4]=new QMovie("./project2_movie/unit/u_n_4.gif");
    unit_movie_array[5]=new QMovie("./project2_movie/unit/u_f_1.gif");
    unit_movie_array[6]=new QMovie("./project2_movie/unit/u_f_2.gif");
    unit_movie_array[7]=new QMovie("./project2_movie/unit/u_f_boss.gif");

    unit_movie_array[17]=new QMovie("./project2_movie/unit/u_f_boss_1.gif");
    unit_movie_array[16]=new QMovie("./project2_movie/unit/u_f_boss_2.gif");
    unit_movie_array[11]=new QMovie("./project2_movie/unit/hps.gif");
    unit_movie_array[12]=new QMovie("./project2_movie/unit/hp.gif");
    unit_movie_array[13]=new QMovie("./project2_movie/unit/bomb.gif");

    tower_movie_array[1]=new QMovie("./project2_movie/tower_near/t_n_00.gif");
    tower_movie_array[11]=new QMovie("./project2_movie/tower_near/t_n_01.gif");


    tower_movie_array[3]=new QMovie("./project2_movie/tower_near/t_n_10.gif");
    tower_movie_array[13]=new QMovie("./project2_movie/tower_near/t_n_11.gif");

    tower_movie_array[4]=new QMovie("./project2_movie/tower_near/t_n_20.gif");
    tower_movie_array[14]=new QMovie("./project2_movie/tower_near/t_n_21.gif");

    tower_movie_array[5]=new QMovie("./project2_movie/tower_near/t_n_30.gif");
    tower_movie_array[15]=new QMovie("./project2_movie/tower_near/t_n_31.gif");

    tower_movie_array[2]=new QMovie("./project2_movie/tower_far/t_f_00.gif");
    tower_movie_array[12]=new QMovie("./project2_movie/tower_far/t_f_01.gif");

    tower_movie_array[6]=new QMovie("./project2_movie/tower_far/t_f_10.gif");
    tower_movie_array[16]=new QMovie("./project2_movie/tower_far/t_f_11.gif");

    tower_movie_array[7]=new QMovie("./project2_movie/tower_far/t_f_20.gif");
    tower_movie_array[17]=new QMovie("./project2_movie/tower_far/t_f_21.gif");

    tower_movie_array[8]=new QMovie("./project2_movie/tower_far/t_f_30.gif");
    tower_movie_array[18]=new QMovie("./project2_movie/tower_far/t_f_31.gif");

    tower_movie_array[9]=new QMovie("./project2_movie/texiao/grade_front.gif");
    tower_movie_array[10]=new QMovie("./project2_movie/weapon/up.gif");

    bullet_movie_array[1]=new QMovie("./project2_movie/tower_far/t_f_0_b.gif");
    bullet_movie_array[2]=new QMovie("./project2_movie/tower_far/t_f_1_b.gif");
    bullet_movie_array[3]=new QMovie("./project2_movie/tower_far/t_f_2_b.gif");
    bullet_movie_array[4]=new QMovie("./project2_movie/unit/u_f_1_b.gif");
    bullet_movie_array[6]=new QMovie("./project2_movie/tower_far/boss.gif");

    tower_weapon_movie_array[1]=new QMovie("./project2_movie/weapon/w_1.gif");
    tower_weapon_movie_array[2]=new QMovie("./project2_movie/weapon/w_2.gif");
    tower_weapon_movie_array[3]=new QMovie("./project2_movie/weapon/w_3.gif");
    tower_weapon_movie_array[4]=new QMovie("./project2_movie/weapon/w_4.gif");
    tower_weapon_movie_array[5]=new QMovie("./project2_movie/weapon/w_5.gif");
    tower_weapon_movie_array[6]=new QMovie("./project2_movie/weapon/w_6.gif");


    return app.exec();
}
