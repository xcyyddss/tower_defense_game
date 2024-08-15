#include "bullet.h"
#include<QDebug>

bullet::bullet(bool e_o_t,int bullet_type,int xx,int yy,int ut,QWidget* ws):enemy_or_tower(e_o_t),atk(bullet_atk_array[bullet_type]),speed(bullet_speed_array[bullet_type]),
    atk_condition(bullet_atk_condition_array[bullet_type]),atk_condition_num(bullet_atk_condition_num_array[bullet_type]),x(xx+block__wid/2),y(yy+block__hei/2)
{
    if(e_o_t){
        t_u=-1;t_t=ut;
    }
    else{
        t_u=ut;t_t=-1;
    }
    label=new QLabel(ws);
    label->setGeometry(xx+block__wid/2,yy+block__hei/2,block__wid/4,block__hei/4);
    label->setMovie(bullet_movie_array[bullet_type]);
    label->setScaledContents(true);
    bullet_movie_array[bullet_type]->start();
    label->show();
}


void bullet::act(int a,int b){
        x+=a;
        y+=b;
        if(label!=NULL)
        label->move(x,y);
}
