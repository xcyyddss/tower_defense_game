#include<QDebug>
#include "tower.h"

tower::tower(int tower_type,int xx,int yy,block* blo,QWidget* w,int time):life(tower_life_array[tower_type]),total_life(tower_life_array[tower_type]),atk(tower_atk_array[tower_type]),
    atk_interval(tower_atk_interval_array[tower_type]),atk_range(tower_atk_range_array[tower_type]),x(xx),y(yy),b(blo),gw(w),is_thrower(tower_type-1),born_time(time){
    plus1=0;
    plus2=0;
    new_shape_label=NULL;
    impact_label=NULL;
    plus_text=NULL;
    plus_label=NULL;
    shape_time=0;
    impact_time=0;
    b->set_tower(this);
    b->get_setted();
    b->set();
    shape_label=new lable(w,this);
    shape_label->setGeometry(xx,yy,block__wid,block__hei);
    shape_label->setMovie(tower_movie_array[tower_type]);
    shape_label->setScaledContents(true);
    tower_movie_array[tower_type]->start();
    shape_label->show();
    hp=new lable(w,this);
    hp->setGeometry(xx+block__wid/8,yy-block__hei/10,block__wid*0.75,block__hei/10);
    hp->setStyleSheet("background-color: Red");
    hp->show();
}

bool tower::permit_up(int up_type){
    if(up_type>5&&is_thrower==false)return false;
    if(up_type<6&&is_thrower==true)return false;
    if(plus1&&plus2)return false;
    if(plus1==up_type||plus2==up_type)return false;
    return true;
}

int tower::act(int t_u,bool per){
    target=t_u;
    if(plus1==7||plus2==7)life+=2;
    if(life>total_life)life=total_life;
    hp->setGeometry(x+block__wid/8,y-block__hei/10,(double)(block__wid*0.75*life/total_life),block__hei/10);
    if(target==-1){
        return -2;
    }
    if(per){
        if(!is_thrower)
            return -1;
        else{
            if(plus1==6||plus2==6)return 2;
            if(plus1==8||plus2==8)return 3;
            return 1;
        }
    }
    return -3;
}
int tower::get_atk(int hurt){
    life-=hurt;
    hp->setGeometry(x+block__wid/8,y-block__hei/10,(double)(block__wid*0.75*life/total_life),block__hei/10);
    if(life<=0){
        return 1;
    }
    return 0;
}


void tower::shape_change(int time,QMovie* m){
    if(shape_time)return;
    shape_time=time;
    shape_label->hide();
    new_shape_label=new lable(gw,this);
    new_shape_label->setGeometry(shape_label->x(),shape_label->y(),shape_label->width(),shape_label->height());
    new_shape_label->setMovie(m);
    new_shape_label->setScaledContents(true);
    m->start();
    new_shape_label->show();
}

void tower::impact_change(int time,QMovie* m){
    if(impact_time)return;
    impact_time=time;
    impact_label=new lable(gw,this);
    impact_label->setGeometry(x,y,block__wid,block__hei);
    impact_label->setMovie(m);
    impact_label->setScaledContents(true);
    m->start();
    impact_label->show();
}

void tower::label_moniter(){
    if(shape_time){
        shape_time--;
        if(shape_time==0){
            delete new_shape_label;
            new_shape_label=NULL;
            shape_label->show();
        }
    }
    if(impact_time){
        impact_time--;
        if(impact_time==3){
            int pre_num=impact_num;
            this->get_atk(pre_num);
            impact_num=0;
        }
        if(impact_time==0){
            delete impact_label;
            impact_label=NULL;
        }
    }
}

void tower::up_grade1(int tower_type){
    plus1=tower_type;
    if(tower_type==3){
        atk*=3;
        atk_interval*=2;
    }
    delete shape_label;
    shape_label=new lable(gw,this);
    shape_label->setGeometry(x,y,block__wid,block__hei);
    shape_label->setMovie(tower_movie_array[tower_type]);
    shape_label->setScaledContents(true);
    tower_movie_array[tower_type]->start();
    shape_label->show();
}

void tower::up_grade2(int up_type){
    if(plus2)return;
    if(up_type==plus1)return;
    if(up_type==3){
        atk*=3;
        atk_interval*=2;
    }
    plus2=up_type;

    plus_label=new lable(gw,this);
    plus_label->setGeometry(x,y,block__wid,block__hei);
    plus_label->setMovie(tower_movie_array[10]);
    plus_label->setScaledContents(true);
    tower_movie_array[10]->start();
    plus_label->show();

    QFont f("黑体",block__hei/8);
    if(up_type==3){
        plus_text=new lable(gw,this,"附加狂暴");
        plus_text->setGeometry(x,y-block__hei/5-block__hei/10-2,block__wid,block__hei/5);
        plus_text->show();
        plus_text->setFont(f);
        return;
    }
    if(up_type==4){
        plus_text=new lable(gw,this,"附加冰冻");
        plus_text->setGeometry(x,y-block__hei/5-block__hei/10-2,block__wid,block__hei/5);
        plus_text->show();
        plus_text->setFont(f);
        return;
    }
    if(up_type==5){
        plus_text=new lable(gw,this,"附加群伤");
        plus_text->setGeometry(x,y-block__hei/5-block__hei/10-2,block__wid,block__hei/5);
        plus_text->show();
        plus_text->setFont(f);
        return;

    }
    if(up_type==6){
        plus_text=new lable(gw,this,"附加放血");
        plus_text->setGeometry(x,y-block__hei/5-block__hei/10-2,block__wid,block__hei/5);
        plus_text->show();
        plus_text->setFont(f);
        return;
    }
    if(up_type==7){
        plus_text=new lable(gw,this,"附加治疗");
        plus_text->setGeometry(x,y-block__hei/5-block__hei/10-2,block__wid,block__hei/5);
        plus_text->show();
        plus_text->setFont(f);
        return;
    }
    if(up_type==8){
        plus_text=new lable(gw,this,"附加净化");
        plus_text->setGeometry(x,y-block__hei/5-block__hei/10-2,block__wid,block__hei/5);
        plus_text->show();
        plus_text->setFont(f);
        return;
    }
}

