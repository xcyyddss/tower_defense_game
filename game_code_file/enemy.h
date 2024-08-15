#ifndef ENEMY_H
#define ENEMY_H

#include<tower.h>
#include<bullet.h>
#include<map.h>

class tower;

extern int unit_life_array[];
extern int unit_atk_array[];
extern int unit_speed_array[];
extern int unit_atk_interval_array[];
extern int unit_atk_range_array[];
extern bool unit_is_thrower_array[];
extern int unit_bullet_type_array[];
extern QMovie* unit_movie_array[];
extern int block__wid;
extern int block__hei;

struct Condition_of_unit{
    unsigned int is_alive:1;
    unsigned int is_thrower:1;
    unsigned int is_frosen:1;
    unsigned int is_fired:1;
    unsigned int bullet_type:3;
    unsigned int frosen_time:12;
    unsigned int fire_hurt:13;
};
class unit: public QObject{
    Q_OBJECT
private:
    int life,atk,speed;
    int total_life;
    int atk_interval;
    int atk_range;
    int x,y;
    int shape_time;
    int skill_interval;
    int skill_time;
    int type;
    int plus1;
    int plus2;
    int born_time;
    bool boomed;
    int boom_time;
    int hp_up_time;
    Condition_of_unit condition;
    QLabel* shape_label;
    QLabel* new_shape_label;
    QLabel* boom_label;
    QLabel* hp_up_label;
    int target;
    block* b;
    QWidget* gw;
public:
    unit(){}
    unit(int xx,int yy,block* blo,QWidget* w,int);
    ~unit(){delete shape_label;delete hp;if(new_shape_label)delete new_shape_label;if(plus_text)delete plus_text;if(boom_label)delete boom_label;if(hp_up_label)delete hp_up_label;}
    QLabel* hp;
    QLabel* plus_text;
    int get_born(){return born_time;}
    int get_atk_num(){return atk;}
    int get_atk_range(){return atk_range;}
    int get_atk_interval(){return atk_interval;}
    int get_skill_time(){return skill_time;}
    int get_target(){return target;}
    int get_x(){return x;}
    int get_y(){return y;}
    int get_type(){return type;}
    int get_plus_num(){return (bool)plus1+(bool)plus2;}
    int get_s(){return speed;}
    int get_bullet_type(){return condition.bullet_type;}
    bool get_boomed(){return boomed;}
    int get_shape_time(){return shape_time;}
    int get_boom_time(){return boom_time;}
    virtual int act(int a,int b,int t_t,bool per);
    virtual int get_atk(int hurt,int con,int num);
    bool is_bomb(){
        if(plus1==3||plus2==3)return true;
        return false;
    }
    bool is_flash(){
        if(plus1==2||plus2==2)return true;
        return false;
    }
    bool is_boss(){
        if(plus1==7||plus2==7)return true;
        return false;
    }
    bool is_doctor(){
        if(plus1==6||plus2==6)return true;
        return false;
    }
    bool permit_up(int);

    bool injured(){return life<total_life;}
    void up_grade1(int);
    void up_grade2(int);
    void dec_skill_time(){skill_time--;}
    void set_skill_time(){skill_time=skill_interval;}
    void shape_change(int time,QMovie* m);
    void boom(int time,QMovie* m);
    void hp_up(int time,QMovie* m);
    void shape_moniter();
    void send(){emit death(this);}
signals:
    void death(unit*);
};



#endif // ENEMY_H
