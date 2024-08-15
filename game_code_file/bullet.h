#ifndef BULLET_H
#define BULLET_H

#include<QWidget>
#include<QObject>
#include<QLabel>
#include<QRect>
#include<QMovie>

class unit;
class tower;


extern int bullet_atk_array[];
extern int bullet_speed_array[];
extern int bullet_atk_condition_array[];
extern int bullet_atk_condition_num_array[];
extern QMovie* bullet_movie_array[];
extern int block__wid;
extern int block__hei;

class bullet: public QObject{
    Q_OBJECT
private:
    int x,y,atk;
    int atk_condition;
    int atk_condition_num;
    int speed;
    bool enemy_or_tower;
    QLabel* label;
    int t_u;
    int t_t;
public:
    bullet(){}
    ~bullet(){delete label;}
    bullet(bool e_o_t,int bullet_type,int xx,int yy,int ut,QWidget* w);
    bool get_tartype(){return enemy_or_tower;}
    int get_atk_num(){return atk;}
    int get_atk_conditon(){return atk_condition;}
    int get_atk_condition_num(){return atk_condition_num;}
    int get_x(){return x;}
    int get_y(){return y;}
    int get_s(){return speed;}
    int get_target_u(){return t_u;}
    int get_target_t(){return t_t;}
    void set_target_u(int tu){t_u=tu;}
    void set_target_t(int tt){t_t=tt;}
    void act(int,int);
};

#endif // BULLET_H
