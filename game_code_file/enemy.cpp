#include "enemy.h"
#include<QDebug>

unit::unit(int xx,int yy,block* blo,QWidget* w,int time):life(unit_life_array[1]),total_life(unit_life_array[1]),atk(unit_atk_array[1]),speed(unit_speed_array[1]),
    atk_range(unit_atk_range_array[1]),x(xx),y(yy),b(blo),born_time(time),gw(w),atk_interval(5000){
    skill_time=0;
    boomed=0;
    boom_time=0;
    hp_up_time=0;
    shape_time=0;
    plus1=0;
    plus2=0;
    condition.is_alive=1;
    condition.is_thrower=unit_is_thrower_array[1];
    condition.is_frosen=0;
    condition.is_fired=0;
    condition.bullet_type=unit_bullet_type_array[1];
    condition.frosen_time=0;
    condition.fire_hurt=0;
    shape_label=new QLabel(w);
    shape_label->setGeometry(xx,yy,block__wid,block__hei);
    shape_label->setMovie(unit_movie_array[1]);
    shape_label->setScaledContents(true);
    unit_movie_array[1]->start();
    shape_label->show();
    new_shape_label=NULL;
    boom_label=NULL;
    hp_up_label=NULL;
    plus_text=NULL;
    hp=new QLabel(w);
    hp->setGeometry(xx+block__wid/8,yy-block__hei/10,block__wid*0.75,block__hei/10);
    hp->setStyleSheet("background-color: Red");
    hp->show();
    shape_label ->setAttribute(Qt::WA_TransparentForMouseEvents,  true );
}

int unit::act(int a,int b,int t_t,bool per){
    if(condition.is_frosen){
        condition.frosen_time--;
        if(condition.frosen_time==0)condition.is_frosen=0;
        return -2;
    }
    if(condition.is_fired){
        life-=condition.fire_hurt;
        if(life<=0){
            emit death(this);
            return -3;
        }
    }
    x+=a;
    y+=b;
    if(shape_label)
        shape_label->move(x,y);
    if(new_shape_label)
        new_shape_label->move(x,y);
    if(plus_text)
        plus_text->move(x,y-block__hei/5-block__hei/10-2);
    if(hp_up_label)
        hp_up_label->move(x,y);
    hp->setGeometry(x+block__wid/8,y-block__hei/10,(double)(block__wid*0.75*life/total_life),block__hei/10);
    target=t_t;
    if(target==-1){
        return -2;
    }
    if(per){
        if(!condition.is_thrower)
            return -1;
        else{
            return condition.bullet_type;
        }
    }
    return -4;
}
int unit::get_atk(int hurt,int con,int num){
    life-=hurt;
    if(life>total_life)life=total_life;
    hp->setGeometry(x+block__wid/8,y-block__hei/10,(double)(block__wid*0.75*life/total_life),block__hei/10);
    if(life<=0){
        return 1;
    }
    else{
        if(con==1){
            condition.is_frosen=1;
            condition.frosen_time=num;
        }
        if(con%2==0&&con){
            condition.is_fired=1;
            condition.fire_hurt=num;
        }
        if(con%3==0&&con){
            if(plus1==3||plus2==3){
                atk_range=unit_atk_range_array[1];
            }
            if(plus1==4||plus2==4){
                speed=unit_speed_array[1];
            }
            if(plus1==5||plus2==5){
                condition.is_thrower=0;
                condition.bullet_type=0;
                atk_range=unit_atk_range_array[1];
            }
            delete shape_label;
            shape_label=new QLabel(gw);
            shape_label->setGeometry(x,y,block__wid,block__hei);
            shape_label->setMovie(unit_movie_array[1]);
            shape_label->setScaledContents(true);
            unit_movie_array[1]->start();
            shape_label->show();
            plus1=0;
            plus2=0;
            if(plus_text)delete plus_text;
            plus_text=NULL;
        }
        return 0;
    }
}

void unit::shape_change(int time,QMovie* m){
    if(shape_time)return;
    shape_time=time;
    new_shape_label=new QLabel(gw);
    new_shape_label->setGeometry(shape_label->x(),shape_label->y(),shape_label->width(),shape_label->height());
    new_shape_label->setMovie(m);
    new_shape_label->setScaledContents(true);
    m->start();
    new_shape_label->show();
    new_shape_label ->setAttribute(Qt::WA_TransparentForMouseEvents,  true );
}

void unit::boom(int time,QMovie* m){
    if(boom_time)return;
    boom_time=time;
    boom_label=new QLabel(gw);
    boom_label->setGeometry(shape_label->x(),shape_label->y(),shape_label->width(),shape_label->height());
    boom_label->setMovie(m);
    boom_label->setScaledContents(true);
    m->start();
    boom_label->show();
    boom_label ->setAttribute(Qt::WA_TransparentForMouseEvents,  true );
    shape_label->hide();
}

void unit::hp_up(int time,QMovie* m){
    if(hp_up_time)return;
    hp_up_time=time;
    hp_up_label=new QLabel(gw);
    hp_up_label->setGeometry(shape_label->x(),shape_label->y(),shape_label->width(),shape_label->height());
    hp_up_label->setMovie(m);
    hp_up_label->setScaledContents(true);
    m->start();
    hp_up_label->show();
    hp_up_label ->setAttribute(Qt::WA_TransparentForMouseEvents,  true );
}


void unit::shape_moniter(){
    if(shape_time&&!boom_time){
        shape_time--;
        if(shape_time==0){
            delete new_shape_label;
            new_shape_label=NULL;
        }
    }
    if(boom_time){
        boom_time--;
        if(boom_time==0){
            delete boom_label;
            boom_label=NULL;
            boomed=1;
        }
    }
    if(hp_up_time){
        hp_up_time--;
        if(hp_up_time==0){
            delete hp_up_label;
            hp_up_label=NULL;
        }
    }
}



void unit::up_grade1(int up_type){
    if(boomed)return;
    if(up_type==7&&plus1!=7&&plus2!=7){
        if(plus1==3||plus2==3){
            atk_range=unit_atk_range_array[1];
        }
        if(plus1==4||plus2==4){
            speed=unit_speed_array[1];
        }
        if(plus1==5||plus2==5){
            condition.is_thrower=0;
            condition.bullet_type=0;
            atk_range=unit_atk_range_array[1];
        }
        plus1=7;
        plus2=7;
        atk_range=unit_atk_range_array[7];

        life=unit_life_array[7];
        total_life=life;
        speed/=2;

        if(plus_text)
        delete plus_text;

        plus_text=new QLabel("boss",gw);
        plus_text->setGeometry(x,y-20-block__hei/10,block__wid,20);
        plus_text->show();

        delete shape_label;
        shape_label=new QLabel(gw);
        shape_label->setGeometry(x,y,block__wid,block__hei);
        shape_label->setMovie(unit_movie_array[up_type]);
        shape_label->setScaledContents(true);
        unit_movie_array[up_type]->start();
        shape_label->show();
        return;
    }
    if(up_type==7)return;
    plus1=up_type;
    if(up_type==2){
        skill_interval=300;
    }
    if(up_type==3){
        atk_range=unit_atk_range_array[3];
    }
    if(up_type==4){
        speed*=2;
    }
    if(up_type==5){
        condition.is_thrower=1;
        condition.bullet_type=4;
        atk_range=unit_atk_range_array[5];
    }
    delete shape_label;
    shape_label=new QLabel(gw);
    shape_label->setGeometry(x,y,block__wid,block__hei);
    shape_label->setMovie(unit_movie_array[up_type]);
    shape_label->setScaledContents(true);
    unit_movie_array[up_type]->start();
    shape_label->show();
}

void unit::up_grade2(int up_type){
    if(boomed)return;
    if(up_type==7&&plus1!=7&&plus2!=7){
        if(plus1==3||plus2==3){
            atk_range=unit_atk_range_array[1];
        }
        if(plus1==4||plus2==4){
            speed=unit_speed_array[1];
        }
        if(plus1==5||plus2==5){
            condition.is_thrower=0;
            condition.bullet_type=0;
            atk_range=unit_atk_range_array[1];
        }
        plus1=7;
        plus2=7;
        atk_range=unit_atk_range_array[7];

        life=unit_life_array[7];
        total_life=life;
        speed/=2;

        if(plus_text)
        delete plus_text;

        QFont f("黑体",block__hei/8);
        plus_text=new QLabel("boss",gw);
        plus_text->setGeometry(x,y-block__hei/5-block__hei/10-2,block__wid,block__hei/5);
        plus_text->show();
        plus_text->setFont(f);

        delete shape_label;
        shape_label=new QLabel(gw);
        shape_label->setGeometry(x,y,block__wid,block__hei);
        shape_label->setMovie(unit_movie_array[up_type]);
        shape_label->setScaledContents(true);
        unit_movie_array[up_type]->start();
        shape_label->show();
        return;
    }
    if(up_type==7)return;
    if(plus2)return;
    if(up_type==plus1)return;
    if(up_type==3){
        atk_range=unit_atk_range_array[3];
    }
    if(up_type==4){
        speed*=2;
    }
    if(up_type==5){
        condition.is_thrower=1;
        condition.bullet_type=4;
        atk_range=unit_atk_range_array[5];
    }
    plus2=up_type;


    QFont f("黑体",block__hei/8);
    if(up_type==2){
        skill_interval=300;
        plus_text=new QLabel("附加闪现",gw);
        plus_text->setGeometry(x,y-block__hei/5-block__hei/10-2,block__wid,block__hei/5);
        plus_text->show();
        plus_text->setFont(f);
        return;
    }
    if(up_type==3){
        plus_text=new QLabel("附加自爆",gw);
        plus_text->setGeometry(x,y-block__hei/5-block__hei/10-2,block__wid,block__hei/5);
        plus_text->show();
        plus_text->setFont(f);
        return;
    }
    if(up_type==4){
        plus_text=new QLabel("附加神速",gw);
        plus_text->setGeometry(x,y-block__hei/5-block__hei/10-2,block__wid,block__hei/5);
        plus_text->show();
        plus_text->setFont(f);
        return;
    }
    if(up_type==5){
        plus_text=new QLabel("附加远攻",gw);
        plus_text->setGeometry(x,y-block__hei/5-block__hei/10-2,block__wid,block__hei/5);
        plus_text->show();
        plus_text->setFont(f);
        return;
    }
    if(up_type==6){
        plus_text=new QLabel("附加治疗",gw);
        plus_text->setGeometry(x,y-block__hei/5-block__hei/10-2,block__wid,block__hei/5);
        plus_text->show();
        plus_text->setFont(f);
        return;
    }
}

bool unit::permit_up(int up_type){
    if(boom_time||boomed)return false;
    if(up_type==7&&plus1!=7&&plus2!=7)return true;
    if(up_type==7)return false;
    if(plus1&&plus2)return false;
    if(up_type==plus1||up_type==plus2)return false;
    return true;
}
