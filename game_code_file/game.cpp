#include "game.h"
#include<QDebug>



game::game(int level,QWidget *parent) :
    QWidget(parent)
{



    stoped=0;
    drag=0;
    label=NULL;
    new_level(level,this);
    execed=1;
    ga=this;

    for(int i{};i<30;i++)u[i]=NULL;
    for(int i{};i<20;i++)t[i]=NULL;
    for(int i{};i<40;i++)b[i]=NULL;
    for(int i{};i<9;i++)tower_plus_stock[i]=0;


    QFont f("黑体",18);
    ql0=new QLabel(this);
    ql0->setGeometry(1520,20,240,100);
    ql0->setText("剩余能量:"+helper(now_source));
    ql0->setFont(f);

    ql9=new QLabel(this);
    ql9->setGeometry(1520,740,240,100);
    ql9->setText("剩余生命:"+helper(life));
    ql9->setFont(f);

    QPushButton* p1=new QPushButton(this);
    p1->setGeometry(1520,120,100,100);b1=p1;
    b1->setIcon(QIcon("./project2_movie/icon/g_1.png"));
    b1->setIconSize(QSize(100,100));
    ql1=new QLabel(this);
    ql1->setGeometry(1520,230,100,20);
    ql1->setText("消耗能量：50");

    QPushButton* p3=new QPushButton(this);
    p3->setGeometry(1520,280,100,100);b3=p3;
    b3->setIcon(QIcon("./project2_movie/icon/g_3.png"));
    b3->setIconSize(QSize(100,100));
    ql3=new QLabel(this);
    ql3->setGeometry(1520,390,100,20);
    ql3->setText("狂暴,余量:"+helper(tower_plus_stock[3]));

    QPushButton* p4=new QPushButton(this);
    p4->setGeometry(1520,440,100,100);b4=p4;
    b4->setIcon(QIcon("./project2_movie/icon/g_4.png"));
    b4->setIconSize(QSize(100,100));
    ql4=new QLabel(this);
    ql4->setGeometry(1520,550,100,20);
    ql4->setText("冰冻,余量:"+helper(tower_plus_stock[4]));

    QPushButton* p5=new QPushButton(this);
    p5->setGeometry(1520,600,100,100);b5=p5;
    b5->setIcon(QIcon("./project2_movie/icon/g_5.png"));
    b5->setIconSize(QSize(100,100));
    ql5=new QLabel(this);
    ql5->setGeometry(1520,710,100,20);
    ql5->setText("群伤,余量:"+helper(tower_plus_stock[5]));

    QPushButton* p2=new QPushButton(this);
    p2->setGeometry(1660,120,100,100);b2=p2;
    b2->setIcon(QIcon("./project2_movie/icon/g_2.png"));
    b2->setIconSize(QSize(100,100));
    ql2=new QLabel(this);
    ql2->setGeometry(1660,230,100,20);
    ql2->setText("消耗能量：50");

    QPushButton* p6=new QPushButton(this);
    p6->setGeometry(1660,280,100,100);b6=p6;
    b6->setIcon(QIcon("./project2_movie/icon/g_6.png"));
    b6->setIconSize(QSize(100,100));
    ql6=new QLabel(this);
    ql6->setGeometry(1660,390,100,20);
    ql6->setText("放血,余量:"+helper(tower_plus_stock[6]));

    QPushButton* p7=new QPushButton(this);
    p7->setGeometry(1660,440,100,100);b7=p7;
    b7->setIcon(QIcon("./project2_movie/icon/g_7.png"));
    b7->setIconSize(QSize(100,100));
    ql7=new QLabel(this);
    ql7->setGeometry(1660,550,100,20);
    ql7->setText("治疗,余量:"+helper(tower_plus_stock[7]));

    QPushButton* p8=new QPushButton(this);
    p8->setGeometry(1660,600,100,100);b8=p8;
    b8->setIcon(QIcon("./project2_movie/icon/g_8.png"));
    b8->setIconSize(QSize(100,100));
    ql8=new QLabel(this);
    ql8->setGeometry(1660,710,100,20);
    ql8->setText("净化,余量:"+helper(tower_plus_stock[8]));

    this->setMouseTracking(true);
    time=new QTime;
    timer=new QTimer(this);
    timer->start(80);
    time->start();



    QObject::connect(this->b1,SIGNAL(clicked()),this,SLOT(set_t1()));
    QObject::connect(this->b2,SIGNAL(clicked()),this,SLOT(set_t2()));
    QObject::connect(this->b3,SIGNAL(clicked()),this,SLOT(upgrade3()));
    QObject::connect(this->b4,SIGNAL(clicked()),this,SLOT(upgrade4()));
    QObject::connect(this->b5,SIGNAL(clicked()),this,SLOT(upgrade5()));
    QObject::connect(this->b6,SIGNAL(clicked()),this,SLOT(upgrade6()));
    QObject::connect(this->b7,SIGNAL(clicked()),this,SLOT(upgrade7()));
    QObject::connect(this->b8,SIGNAL(clicked()),this,SLOT(upgrade8()));
    QObject::connect(this->timer,SIGNAL(timeout()),this,SLOT(act_all()));

}

game::~game(){

    for(int i{};i<30;i++)if(u[i])delete u[i];
    for(int i{};i<20;i++)if(t[i])delete t[i];
    for(int i{};i<40;i++)if(b[i])delete b[i];
    if(l)
    delete l;
    if(label)delete label;
    delete ql0;
    delete b1;
    delete ql1;
    delete b2;
    delete ql2;
    delete b3;
    delete ql3;
    delete b4;
    delete ql4;
    delete b5;
    delete ql5;
    delete b6;
    delete ql6;
    delete b7;
    delete ql7;
    delete b8;
    delete ql8;
    delete time;
    delete timer;
}

void game::paintEvent(QPaintEvent *){

    QPainter* painter=new QPainter(this);

    if(l)
    painter->drawPixmap(0,0,l->get_map()->block_width*l->get_map()->block_x_nums,l->get_map()->block_height*l->get_map()->block_y_nums,QPixmap("./project2_movie/map/back2.jpg"));
    for(int i{};i<l->get_map()->block_x_nums;i++){
        for(int j{};j<l->get_map()->block_y_nums;j++){
            block* now_b=l->get_map()->all_blocks[i][j];
            if(now_b->get_direction()==1||now_b->get_direction()==-1){
                painter->drawPixmap(now_b->get_x(),now_b->get_y(),now_b->get_wid(),now_b->get_hei(),QPixmap("./project2_movie/map/b1.jpg"));
            }
            if(now_b->get_direction()==2||now_b->get_direction()==-2){
                painter->drawPixmap(now_b->get_x(),now_b->get_y(),now_b->get_wid(),now_b->get_hei(),QPixmap("./project2_movie/map/b3.jpg"));
            }
            if(now_b->get_direction()==3||now_b->get_direction()==-4){
                painter->drawPixmap(now_b->get_x(),now_b->get_y(),now_b->get_wid(),now_b->get_hei(),QPixmap("./project2_movie/map/b3or-4.jpg"));
            }
            if(now_b->get_direction()==-3||now_b->get_direction()==4){
                painter->drawPixmap(now_b->get_x(),now_b->get_y(),now_b->get_wid(),now_b->get_hei(),QPixmap("./project2_movie/map/b-3or4.jpg"));
            }
            if(now_b->get_direction()==5||now_b->get_direction()==-6){
                painter->drawPixmap(now_b->get_x(),now_b->get_y(),now_b->get_wid(),now_b->get_hei(),QPixmap("./project2_movie/map/b5or-6.jpg"));
            }
            if(now_b->get_direction()==-5||now_b->get_direction()==6){
                painter->drawPixmap(now_b->get_x(),now_b->get_y(),now_b->get_wid(),now_b->get_hei(),QPixmap("./project2_movie/map/b-5or6.jpg"));
            }
            if(now_b->get_end()){
                painter->drawPixmap(now_b->get_x(),now_b->get_y(),now_b->get_wid(),now_b->get_hei(),QPixmap("./project2_movie/map/be.jpg"));
            }
        }
    }

    delete painter;
}

void game::set_t1(){
    drag=1;
    lab* la=new lab(this);
    la->setGeometry(1460,120,l->get_map()->block_width,l->get_map()->block_height);
    la->setMovie(tower_movie_array[1]);
    la->setScaledContents(true);
    tower_movie_array[1]->start();
    la->show();
    label=la;
    set_type=1;
}

void game::set_t2(){
    drag=2;
    lab* la=new lab(this);
    la->setGeometry(1600,120,l->get_map()->block_width,l->get_map()->block_height);
    la->setMovie(tower_movie_array[2]);
    la->setScaledContents(true);
    tower_movie_array[2]->start();
    la->show();
    label=la;
    set_type=2;
}

void game::upgrade3(){
    drag=3;
    lab* la=new lab(this);
    la->setGeometry(1460,280,l->get_map()->block_width,l->get_map()->block_height);
    la->setMovie(tower_weapon_movie_array[1]);
    la->setScaledContents(true);
    tower_weapon_movie_array[1]->start();
    la->show();
    label=la;
    set_type=3;
}

void game::upgrade4(){
    drag=4;
    lab* la=new lab(this);
    la->setGeometry(1460,440,l->get_map()->block_width,l->get_map()->block_height);
    la->setMovie(tower_weapon_movie_array[2]);
    la->setScaledContents(true);
    tower_weapon_movie_array[2]->start();
    la->show();
    label=la;
    set_type=4;
}

void game::upgrade5(){
    drag=5;
    lab* la=new lab(this);
    la->setGeometry(1460,600,l->get_map()->block_width,l->get_map()->block_height);
    la->setMovie(tower_weapon_movie_array[3]);
    la->setScaledContents(true);
    tower_weapon_movie_array[3]->start();
    la->show();
    label=la;
    set_type=5;
}

void game::upgrade6(){
    drag=6;
    lab* la=new lab(this);
    la->setGeometry(1600,280,l->get_map()->block_width,l->get_map()->block_height);
    la->setMovie(tower_weapon_movie_array[4]);
    la->setScaledContents(true);
    tower_weapon_movie_array[4]->start();
    la->show();
    label=la;
    set_type=6;
}

void game::upgrade7(){
    drag=7;
    lab* la=new lab(this);
    la->setGeometry(1600,440,l->get_map()->block_width,l->get_map()->block_height);
    la->setMovie(tower_weapon_movie_array[5]);
    la->setScaledContents(true);
    tower_weapon_movie_array[5]->start();
    la->show();
    label=la;
    set_type=7;
}

void game::upgrade8(){
    drag=8;
    lab* la=new lab(this);
    la->setGeometry(1600,600,l->get_map()->block_width,l->get_map()->block_height);
    la->setMovie(tower_weapon_movie_array[6]);
    la->setScaledContents(true);
    tower_weapon_movie_array[6]->start();
    la->show();
    label=la;
    set_type=8;
}

void game::mouseMoveEvent(QMouseEvent *event){
    if(drag){
        if(event->x()-label->block_x>=l->get_map()->block_width||event->y()-label->block_y>=l->get_map()->block_height||event->x()<label->block_x||event->y()<label->block_y){
            label->block_x=event->x()-event->x()%l->get_map()->block_width;
            label->block_y=event->y()-event->y()%l->get_map()->block_height;
            label->move(label->block_x+label->x_displace,label->block_y+label->y_displace);
        }
    }
}

void game::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key() == Qt::Key_Escape)
    {
       timer->stop();
       emit back();
       return;
    }
    if(ev->key() == Qt::Key_P)
    {
       if(stoped){
           timer->start();
           stoped=0;
       }
       else{
           timer->stop();
           stoped=1;
       }
       return;
    }

    QWidget::keyPressEvent(ev);
}

void game::upgrade_button(int up_b){
    if(up_b==1){
        ql0->setText("剩余能量:"+helper(now_source));
    }
    if(up_b==3){
        ql3->setText("狂暴,余量:"+helper(tower_plus_stock[3]));
    }
    if(up_b==4){
        ql4->setText("冰冻,余量:"+helper(tower_plus_stock[4]));
    }
    if(up_b==5){
        ql5->setText("群伤,余量:"+helper(tower_plus_stock[5]));
    }
    if(up_b==6){
        ql6->setText("放血,余量:"+helper(tower_plus_stock[6]));
    }
    if(up_b==7){
        ql7->setText("治疗,余量:"+helper(tower_plus_stock[7]));
    }
    if(up_b==8){
        ql8->setText("净化,余量:"+helper(tower_plus_stock[8]));
    }
}

void game::mousePressEvent(QMouseEvent *event){
    if(!drag)return ;
    if(label->x()>=block__wid*l->get_map()->block_x_nums||label->y()>=block__hei*l->get_map()->block_y_nums){
        drag=0;
        if(label)delete label;
        label=NULL;
        return;
    }
    block* now_block=l->get_map()->all_blocks[label->block_x/l->get_map()->block_width][label->block_y/l->get_map()->block_height];
    if(drag==1){
        if(now_source<50){
            if(label)delete label;
            label=NULL;
            drag=0;
            emit add_fail();
            return;
        }
        if(!now_block->if_settable()&&!now_block->get_tower()){
            add_tower(drag,label->block_x,label->block_y);
            now_source-=50;
            upgrade_button(1);
        }
        else emit add_fail();
        if(label)delete label;
        label=NULL;
        drag=0;
    }
    if(drag==2){
        if(now_source<50){
            if(label)delete label;
            label=NULL;
            drag=0;
            emit add_fail();
            return;
        }
        if(now_block->if_settable()&&!now_block->get_tower()){
            add_tower(drag,label->block_x,label->block_y);
            now_source-=50;
            upgrade_button(1);
        }
        else emit add_fail();
        if(label)delete label;
        label=NULL;
        drag=0;
    }
    if(drag==3||drag==4||drag==5){
        if(!tower_plus_stock[drag]){
            if(label)delete label;
            label=NULL;
            drag=0;
            emit add_fail();
            return;
        }
        if(now_block->get_tower()&&now_block->get_tower()->permit_up(drag)){
            upgrade_tower(now_block->get_tower());
            tower_plus_stock[drag]--;
            upgrade_button(drag);
        }
        else emit add_fail();
        if(label)delete label;
        label=NULL;
        drag=0;
    }
    if(drag==6||drag==7||drag==8){
        if(!tower_plus_stock[drag]){
            if(label)delete label;
            label=NULL;
            drag=0;
            emit add_fail();
            return;
        }
        if(now_block->get_tower()&&now_block->get_tower()->permit_up(drag)){
            upgrade_tower(now_block->get_tower());
            tower_plus_stock[drag]--;
            upgrade_button(drag);
        }
        else emit add_fail();
        if(label)delete label;
        label=NULL;
        drag=0;
    }
}

void game::delete_unit(unit* d_u){
    for(int i{};i<30;i++){
        if(u[i]==d_u){
            u[i]=NULL;
        }
    }
    delete d_u;
    int ii=rand()%6;
    ii+=3;
    tower_plus_stock[ii]++;
    upgrade_button(ii);
    present_enemy_nums--;
}

void game::delete_tower(tower* d_t){
    for(int i{};i<20;i++){
        if(t[i]==d_t){
            t[i]=NULL;
        }
    }
    delete d_t;
}

void game::delete_bullet(bullet* d_b){
    for(int i{};i<40;i++){
        if(b[i]==d_b){
            b[i]=NULL;
        }
    }
    delete d_b;
}

void game::add_unit(int xx,int yy){
    for(int i{};i<30;i++){
        if(u[i]==NULL){
            u[i]=new unit(xx,yy,l->get_map()->all_blocks[xx/l->get_map()->block_width][yy/l->get_map()->block_height],this,time->elapsed());
            return;
        }
    }
}

void game::add_tower(int type,int xx,int yy){
    for(int i{};i<20;i++){
        if(t[i]==NULL){
            t[i]=new tower(type,xx,yy,l->get_map()->all_blocks[xx/l->get_map()->block_width][yy/l->get_map()->block_height],this,time->elapsed());
            return;
        }
    }
}


void game::upgrade_close(){
    label->hide();
}

void game::upgrade_tower(tower* up_tower){
    if(up_tower){
        for(int i{};i<20;i++){
            if(t[i]==up_tower){
                if(t[i]->get_plus_num()==1){
                    t[i]->up_grade2(set_type);
                }
                else t[i]->up_grade1(set_type);
                return;
            }
        }
    }
}

void game::add_bullet(bool e_o_t,int type,int xx,int yy,int tar){
    for(int i{};i<40;i++){
        if(b[i]==NULL){
            b[i]=new bullet(e_o_t,type,xx,yy,tar,this);
            return;
        }
    }
}


bool game::if_blocked(int xx,int yy){
    int new_x,new_y;
    new_x=xx-xx%l->get_map()->block_width;
    new_y=yy-yy%l->get_map()->block_height;
    return (l->get_map()->all_blocks[new_x/l->get_map()->block_width][new_y/l->get_map()->block_height]->get_next()->get_setted()||l->get_map()->all_blocks[new_x/l->get_map()->block_width][new_y/l->get_map()->block_height]->get_setted())&&xx-new_x==0&&new_y-yy==0;
}

int game::move_strategy_x(int a,int b,int c){
    if(if_blocked(a,b))return 0;
    int new_x,new_y;
    new_x=a-a%l->get_map()->block_width;
    new_y=b-b%l->get_map()->block_height;
    int wid=l->get_map()->block_width;
    int hei=l->get_map()->block_height;
    block* now_block=l->get_map()->all_blocks[new_x/wid][new_y/hei];
    int next_direct=now_block->next_x_direct(a,b);
    if(next_direct==1){
        if(next_direct*c<wid-a%wid)return next_direct*c;
        return wid-a%wid;
    }
    if(next_direct==-1){
        if(next_direct*c>-a%wid||a%wid==0){return next_direct*c;}
        return -a%wid;
    }
    return 0;
}

int game::move_strategy_y(int a,int b,int c){
    if(if_blocked(a,b))return 0;
    int new_x,new_y;
    new_x=a-a%l->get_map()->block_width;
    new_y=b-b%l->get_map()->block_height;
    int wid=l->get_map()->block_width;
    int hei=l->get_map()->block_height;
    block* now_block=l->get_map()->all_blocks[new_x/wid][new_y/hei];
    int next_direct=now_block->next_y_direct(a,b);
    if(next_direct==1){
        if(next_direct*c<hei-b%hei)return next_direct*c;
        return hei-b%hei;
    }
    if(next_direct==-1){
        if(next_direct*c>-b%hei||b%hei==0)return next_direct*c;
        return -(b%hei);
    }
    return 0;
}

int game::get_unittarget(int a,int b,int c){
    int now_int{c};
    int now_index{-1};
    for(int i{};i<30;i++){
        if(u[i]!=NULL){
            if(abs(a-u[i]->get_x())+abs(b-u[i]->get_y())<=now_int){
                now_int=abs(a-u[i]->get_x())+abs(b-u[i]->get_y());
                now_index=i;
            }
        }
    }
    return now_index;
}

int game::get_unittarget2(int a,int b,int c){
    for(int i{};i<30;i++){
        if(u[i]!=NULL){
            if(abs(a-u[i]->get_x())+abs(b-u[i]->get_y())<=c){
                if(u[i]->injured())return i;
            }
        }
    }
    return -1;
}


int game::get_towertarget(int a,int b,int c){
    int now_int{c};
    int now_index{-1};
    for(int i{};i<20;i++){
        if(t[i]!=NULL){
            if(abs(a-t[i]->get_x())+abs(b-t[i]->get_y())<=now_int){
                now_int=abs(a-t[i]->get_x())+abs(b-t[i]->get_y());
                now_index=i;
            }
        }
    }
    return now_index;
}


int game::fly_strategy_x(bullet* but,int t_u){
    if(t_u==-1){
        delete_bullet(but);return 0;
    }
    if(!but->get_tartype()){
        int X=l->get_map()->block_width/2;
        int Y=l->get_map()->block_height/2;
        if(u[t_u]==NULL){delete_bullet(but);return -200000000;}
        if(but==NULL)return -200000000;
        if(but->get_x()>=u[t_u]->get_x()&&but->get_y()>=u[t_u]->get_y()&&(abs(but->get_x()-u[t_u]->get_x()-X)+abs(but->get_y()-u[t_u]->get_y()-Y)<20)){
            if(u[t_u]&&u[t_u]->get_atk(but->get_atk_num(),but->get_atk_conditon(),but->get_atk_condition_num()))
                delete_unit(u[t_u]);
            delete_bullet(but);
            return -200000000;
        }
        int len=abs(u[t_u]->get_x()-but->get_x()+X)+abs(u[t_u]->get_y()-but->get_y()+Y);
        double r_x=(double)abs(u[t_u]->get_x()-(double)but->get_x()+(double)X)/len;
        if(but->get_x()<u[t_u]->get_x()+X)
        return but->get_s()*r_x;
        return but->get_s()*r_x*(-1);
    }
    else{
        int t_t=t_u;
        int X=l->get_map()->block_width/2;
        int Y=l->get_map()->block_height/2;
        if(t[t_t]==NULL){delete_bullet(but);return -200000000;}
        if(but==NULL)return -200000000;
        if(but->get_x()>=t[t_t]->get_x()&&but->get_y()>=t[t_t]->get_y()&&(abs(but->get_x()-t[t_t]->get_x()-X)+abs(but->get_y()-t[t_t]->get_y()-Y)<20)){
            if(t[t_t]&&t[t_t]->get_atk(but->get_atk_num()))
                delete_tower(t[t_t]);
            delete_bullet(but);
            return -200000000;
        }
        int len=abs(t[t_t]->get_x()-but->get_x()+X)+abs(t[t_t]->get_y()-but->get_y()+Y);
        double r_x=(double)abs(t[t_t]->get_x()-(double)but->get_x()+(double)X)/len;
        if(but->get_x()<t[t_t]->get_x()+X)
        return but->get_s()*r_x;
        return but->get_s()*r_x*(-1);
    }
}

int game::fly_strategy_y(bullet* but,int t_u){
    if(t_u==-1){
        delete_bullet(but);return 0;
    }
    if(!but->get_tartype()){
        int X=l->get_map()->block_width/2;
        int Y=l->get_map()->block_height/2;
        if(u[t_u]==NULL){delete_bullet(but);return -200000000;}
        if(but==NULL)return -200000000;
        if(but->get_x()>=u[t_u]->get_x()&&but->get_y()>=u[t_u]->get_y()&&(abs(but->get_x()-u[t_u]->get_x()-X)+abs(but->get_y()-u[t_u]->get_y()-Y)<20)){
            if(u[t_u]&&u[t_u]->get_atk(but->get_atk_num(),but->get_atk_conditon(),but->get_atk_condition_num()))
                delete_unit(u[t_u]);
            delete_bullet(but);
            return -200000000;
        }
        int len=abs(u[t_u]->get_x()-but->get_x()+X)+abs(u[t_u]->get_y()-but->get_y()+Y);
        double r_y=(double)abs(u[t_u]->get_y()-(double)but->get_y()+(double)Y)/len;
        if(but->get_y()<u[t_u]->get_y()+Y)
        return but->get_s()*r_y;
        return but->get_s()*r_y*(-1);
    }
    else{
        int t_t=t_u;
        int X=l->get_map()->block_width/2;
        int Y=l->get_map()->block_height/2;
        if(t[t_t]==NULL){delete_bullet(but);return -200000000;}
        if(but==NULL)return -200000000;
        if(but->get_x()>=t[t_t]->get_x()&&but->get_y()>=t[t_t]->get_y()&&(abs(but->get_x()-t[t_t]->get_x()-X)+abs(but->get_y()-t[t_t]->get_y()-Y)<20)){
            if(t[t_t]&&t[t_t]->get_atk(but->get_atk_num()))
                delete_tower(t[t_t]);
            delete_bullet(but);
            return -200000000;
        }
        int len=abs(t[t_t]->get_x()-but->get_x()+X)+abs(t[t_t]->get_y()-but->get_y()+Y);
        double r_y=(double)abs(t[t_t]->get_y()-(double)but->get_y()+(double)Y)/len;
        if(but->get_y()<t[t_t]->get_y()+Y)
        return but->get_s()*r_y;
        return but->get_s()*r_y*(-1);
    }
}


bool game::in_endblock(int a,int b){
    for(int i{};i<l->get_map()->endblock_num;i++){
        if(a==l->get_map()->end_block[i]->get_x()&&b==l->get_map()->end_block[i]->get_y())return true;
    }
    return false;
}


int allocat(int shu[],int start,int end){
    int total{};
    for(int i{start};i<end;i++)total+=shu[i];
    int rad=rand()%total;
    int tmp{};
    for(int i{start};i<end;i++){
        tmp+=shu[i];
        if(rad<tmp)return i;
    }
    return end-1;
}

void game::emerge_enemy(){
    if(!rest_enemy_nums)return;
    int multiple{};
    if(total_enemy_nums/rest_enemy_nums<2)multiple=1;
    else{
        if(total_enemy_nums/rest_enemy_nums<3)multiple=2;
        else multiple=3;
    }
    if(time->elapsed()%(l->enemies[1]/multiple)<80){
        int y=rand()%l->get_map()->start_blocks_num;
        add_unit(l->get_map()->start_blocks[y]->get_x(),l->get_map()->start_blocks[y]->get_y());
        rest_enemy_nums--;
        present_enemy_nums++;
    }
}

void game::upgrade_enemy(){
    if(time->elapsed()%plus_speed>=80)return;
    int multiple{};
    if(rest_enemy_nums&&total_enemy_nums/rest_enemy_nums<2)multiple=1;
    else{
        if(rest_enemy_nums&&total_enemy_nums/rest_enemy_nums<3)multiple=2;
        else multiple=3;
    }
    for(int k{};k<multiple;k++){
        int index=allocat(l->enemies,2,8);
        for(int i{};i<30;i++){
            if(u[i]&&u[i]->permit_up(index)){
                if(u[i]->get_plus_num()==1)u[i]->up_grade2(index);
                else u[i]->up_grade1(index);
                break;
            }
        }
    }
}

void game::act_all(){
    if(!execed)return;
    execed=0;
    emerge_enemy();
    upgrade_enemy();
    if(time->elapsed()%1000<80){
        now_source+=source_speed;
        ql0->setText("剩余能量:"+helper(now_source));
    }
    for(int i{};i<30;i++){
        if(u[i]){
            u[i]->shape_moniter();
            if(u[i]->is_bomb()&&u[i]->get_boom_time())continue;
            int x{},y{},atk_act{};
            int z{-1};
            if(u[i])
            x=move_strategy_x(u[i]->get_x(),u[i]->get_y(),u[i]->get_s());
            if(u[i])
            y=move_strategy_y(u[i]->get_x(),u[i]->get_y(),u[i]->get_s());
            if(u[i]->is_flash()){
                if(x==0&&y==0&&u[i]->get_skill_time()==0){
                    block* next_b=l->get_map()->all_blocks[u[i]->get_x()/block__wid][u[i]->get_y()/block__hei]->get_next();
                    if(next_b->get_end())goto here1;
                    if(next_b->get_direction()==1)x+=2*block__wid;
                    if(next_b->get_direction()==-1)x-=2*block__wid;
                    if(next_b->get_direction()==2)y+=2*block__hei;
                    if(next_b->get_direction()==-2)y-=2*block__hei;
                    if(next_b->get_direction()==-3||next_b->get_direction()==-4){x+=block__wid;y-=block__hei;}
                    if(next_b->get_direction()==5||next_b->get_direction()==6){x+=block__wid;y+=block__hei;}
                    if(next_b->get_direction()==3||next_b->get_direction()==4){x-=block__wid;y+=block__hei;}
                    if(next_b->get_direction()==-5||next_b->get_direction()==-6){x-=block__wid;y-=block__hei;}
                    u[i]->set_skill_time();
                }
                if(u[i]->get_skill_time())u[i]->dec_skill_time();
            }
            here1:;
            if(u[i])
            z=get_towertarget(u[i]->get_x(),u[i]->get_y(),u[i]->get_atk_range());
            if(u[i])
            atk_act=u[i]->act(x,y,z,(time->elapsed()-u[i]->get_born())%u[i]->get_atk_interval()<80);

            if(u[i]->is_doctor()){
                if((time->elapsed()-u[i]->get_born())%unit_atk_interval_array[6]<80){
                    int now_unit=get_unittarget2(u[i]->get_x(),u[i]->get_y(),u[i]->get_atk_range());
                    if(now_unit!=-1&&now_unit!=i){
                        u[i]->shape_change(16,unit_movie_array[11]);
                        u[now_unit]->hp_up(18,unit_movie_array[12]);
                        u[now_unit]->get_atk(-20,0,0);
                    }
                }
            }
            if(atk_act==-3){
                delete_unit(u[i]);
                continue;
            }
            if(u[i]&&in_endblock(u[i]->get_x(),u[i]->get_y())){
                life--;
                ql9->setText("剩余生命:"+helper(life));
                delete_unit(u[i]);
                if(!life){
                    fail();
                    return;
                }
                continue;
            }
            if(u[i]->is_bomb()){
                if(rand()%300==70){
                    u[i]->boom(11,unit_movie_array[13]);
                    u[i]->hp->hide();
                    if(u[i]->plus_text)
                        u[i]->plus_text->hide();
                    for(int j{};j<20;j++){
                        if(!t[j])continue;
                        if(abs(u[i]->get_x()-t[j]->get_x())+abs(u[i]->get_y()-t[j]->get_y())<=unit_atk_range_array[3]){
                            t[j]->get_atk(unit_atk_array[3]);
                        }
                    }
                    continue;
                }
                if(u[i]->get_boomed()){
                    delete_unit(u[i]);
                    continue;
                }
            }
            if(atk_act==-2)continue;
            if(atk_act==-1){
                if(u[i]->is_boss()){
                    u[i]->shape_change(11,unit_movie_array[16]);
                    t[u[i]->get_target()]->set_impact_num(unit_atk_array[7]);
                    t[u[i]->get_target()]->impact_change(18,unit_movie_array[17]);
                    continue;
                }
                if(u[i]&&t[u[i]->get_target()]->get_atk(u[i]->get_atk_num())){
                    delete_tower(t[u[i]->get_target()]);
                }
            }
            if(atk_act>=0){
                if(u[i])
                add_bullet(1,u[i]->get_bullet_type(),u[i]->get_x(),u[i]->get_y(),u[i]->get_target());
            }
        }
    }
    for(int i{};i<20;i++){
        if(t[i]){
            if(t[i]->get_life()<=0){
                delete_tower(t[i]);continue;
            }
            t[i]->label_moniter();
            if(t[i]->if_aoe()){
                for(int j{};j<40;j++){
                    if(!u[j])continue;
                    if(abs(t[i]->get_x()-u[j]->get_x())+abs(t[i]->get_y()-u[j]->get_y())<=t[i]->get_atk_range()){
                        int atk_act=t[i]->act(j,(time->elapsed()-t[i]->get_born())%t[i]->get_atk_interval()<80);
                        if(atk_act==-2)continue;
                        if(atk_act==-1){
                            t[i]->shape_change(10,tower_movie_array[10+t[i]->get_type()]);
                            if(u[j]->get_atk(t[i]->get_atk_num(),t[i]->get_atk_condition(),t[i]->get_atk_condition_num())){
                                delete_unit(u[j]);
                            }
                        }
                        if(atk_act>=0){
                            t[i]->shape_change(7,tower_movie_array[10+t[i]->get_type()]);
                            add_bullet(0,t[i]->get_bullet_type(),t[i]->get_x(),t[i]->get_y(),j);
                        }
                    }
                }
                continue;
            }
            int atk_act=t[i]->act(get_unittarget(t[i]->get_x(),t[i]->get_y(),t[i]->get_atk_range()),(time->elapsed()-t[i]->get_born())%t[i]->get_atk_interval()<80);
            if(atk_act==-2)continue;
            if(atk_act==-1){
                t[i]->shape_change(10,tower_movie_array[10+t[i]->get_type()]);
                if(u[t[i]->get_target()]->get_atk(t[i]->get_atk_num(),t[i]->get_atk_condition(),t[i]->get_atk_condition_num())){
                    delete_unit(u[t[i]->get_target()]);
                }
            }
            if(atk_act>=0){
                t[i]->shape_change(7,tower_movie_array[10+t[i]->get_type()]);
                add_bullet(0,t[i]->get_bullet_type(),t[i]->get_x(),t[i]->get_y(),t[i]->get_target());
            }
        }
    }
    for(int i{};i<40;i++){
        if(b[i]){
            int x{0},y{0};
            if(b[i]&&b[i]->get_tartype()){
                if(b[i])
                x=fly_strategy_x(b[i],b[i]->get_target_t());
                if(x==-200000000){continue;}
                if(b[i])
                y=fly_strategy_y(b[i],b[i]->get_target_t());
                if(y==-200000000){continue;}
            }
            if(b[i]&&!b[i]->get_tartype()){
                if(b[i])
                x=fly_strategy_x(b[i],b[i]->get_target_u());
                if(x==-200000000){continue;}
                if(b[i])
                y=fly_strategy_y(b[i],b[i]->get_target_u());
                if(y==-200000000){continue;}
            }
            if(b[i])b[i]->act(x,y);
        }
    }
    execed=1;
    if(!rest_enemy_nums&&!present_enemy_nums)vectory();
}



void game::fail(){
    timer->stop();
    dial("      真遗憾，失败了");
    emit back();
}

void game::vectory(){
    timer->stop();
    dial("      恭喜您，过关！");
    emit back();
}

