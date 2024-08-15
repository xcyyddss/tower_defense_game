



#include "myapp.h"



void myapp::work(){
    if(!f){
        f=new frontboard;
        f->setGeometry(80,80,1780,880);
        QObject::connect(f->b1,SIGNAL(clicked()),this,SLOT(to_levelboard()));
        QObject::connect(f->b2,SIGNAL(clicked()),this,SLOT(to_mapload_board()));
        QObject::connect(f->b3,SIGNAL(clicked()),this,SLOT(quit_send()));
    }
    f->show();
}

void myapp::to_frontboard(){
    if(l)
        l->hide();
    if(m)
        m->hide();
    if(mm)
        mm->hide();
    if(lm)
        lm->hide();
    if(!f){
        f=new frontboard;
        f->setGeometry(80,80,1780,880);
        QObject::connect(f->b1,SIGNAL(clicked()),this,SLOT(to_levelboard()));
        QObject::connect(f->b2,SIGNAL(clicked()),this,SLOT(to_mapload_board()));
        QObject::connect(f->b3,SIGNAL(clicked()),this,SLOT(quit_send()));
    }
    f->show();
}

void myapp::quit_send(){
    emit quit();
}

void myapp::to_levelboard(){
    f->hide();
    if(!l){
        l=new levelboard;
        l->setGeometry(80,80,1780,880);
        QObject::connect(l->bs[0],SIGNAL(clicked()),this,SLOT(to_frontboard()));
        QObject::connect(l,SIGNAL(send()),this,SLOT(to_frontboard()));
    }
    l->renew();
    l->show();
}

void myapp::to_mapload_board(){
    f->hide();
    if(!m){
        m=new mapload_board;
        m->setGeometry(80,80,1780,880);
        QObject::connect(m->b1,SIGNAL(clicked()),this,SLOT(to_mapmake_board()));
        QObject::connect(m->b2,SIGNAL(clicked()),this,SLOT(to_levelmake_board()));
        QObject::connect(m->b3,SIGNAL(clicked()),this,SLOT(to_frontboard()));
    }
    m->show();
}

void myapp::to_game(int level_choose){

}

void myapp::to_mapmake_board(){
    m->hide();
    if(!mm){
        mm=new mapmake_board;
        mm->setGeometry(80,80,1780,880);
        QObject::connect(mm->b4,SIGNAL(clicked()),this,SLOT(to_frontboard()));
    }
    mm->show();
}

void myapp::to_levelmake_board(){
    m->hide();
    if(!lm){
        lm=new levelmake_board;
        lm->setGeometry(80,80,1780,880);
        QObject::connect(lm->b2,SIGNAL(clicked()),this,SLOT(to_frontboard()));
    }
    lm->show();
}
