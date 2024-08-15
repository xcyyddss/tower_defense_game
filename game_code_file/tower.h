#ifndef TOWER_H
#define TOWER_H

#include<QRect>
#include<QFont>
#include<bullet.h>
#include<map.h>

class unit;


extern int tower_life_array[];
extern int tower_atk_array[];
extern int tower_atk_interval_array[];
extern int tower_atk_range_array[];
extern int tower_atk_condition_array[];
extern int tower_atk_condition_num_array[];
extern bool tower_is_thrower_array[];
extern int tower_bullet_type_array[];
extern QMovie* tower_movie_array[];
extern int block__wid;
extern int block__hei;
extern int grade_sig;


class tower: public QObject {
    Q_OBJECT
private:
    int life,atk;
    int total_life;
    int atk_interval;
    int atk_range;
    int x,y;
    int shape_time;
    int impact_time;
    int impact_num;
    bool is_thrower;
    int plus1;
    int plus2;
    int born_time;
    int target;
    lable* new_shape_label;
    QWidget* gw;
    block* b;
public:
    lable* shape_label;
    lable* impact_label;
    lable* plus_label;
    lable* plus_text;
    lable* hp;
    tower(){}
    ~tower(){shape_label->close();delete shape_label;delete hp;if(plus_label)delete plus_label;if(plus_text)delete plus_text;if(new_shape_label)delete new_shape_label;if(impact_label)delete impact_label;b->clear_tower();b->clear();}
    tower(int tower_type,int xx,int yy,block* blo,QWidget* w,int);
    int get_plus_num(){return (bool)plus1+(bool)plus2;}
    int get_type(){if(!plus1)return is_thrower+1;return plus1;}
    int get_born(){return born_time;}
    int get_life(){return life;}
    int get_shape(){return plus1;}
    int get_atk_num(){return atk;}
    int get_atk_range(){return atk_range;}
    int get_atk_interval(){return atk_interval;}
    int get_x(){return x;}
    int get_y(){return y;}
    block* get_block(){return b;}
    int get_target(){return target;}
    int get_bullet_type(){
        if(is_thrower){
            if(plus1*plus2==48)return 6;
            if(plus1==6||plus2==6)return 2;
            if(plus1==8||plus2==8)return 3;
            return 1;
        }
        return 0;
    }
    int get_atk_condition(){
        if(plus1==4||plus2==4){
            return 1;
        }
        return 0;
    }
    int get_atk_condition_num(){
        if(plus1==4||plus2==4){
            return 60;
        }
        return 0;
    }
    bool permit_up(int up_type);
    int act(int t_u,bool per);
    int get_atk(int);
    void set_impact_num(int xxxx){impact_num=xxxx;}
    bool if_aoe(){return plus1==5||plus2==5;}
    void shape_change(int time,QMovie* m);
    void impact_change(int time,QMovie* m);
    void label_moniter();
    void up_grade1(int);
    void up_grade2(int);
};

#endif // TOWER_H
