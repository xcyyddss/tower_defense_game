#include "gameboard.h"
#include "ui_gameboard.h"

game::game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
}

game::~game()
{
    delete ui;
}

void game::delete_unit(unit* d_u){
    d_u->get_block()->clear();
    delete d_u;
}

void game::delete_tower(tower* d_t){
    d_t->get_block()->clear();
    delete d_t;
}

void game::delete_bullet(bullet* d_b){
    delete d_b;
}

void game::add_unit(int type,int xx,int yy){
    for(int i{};i<30;i++){
        if(u[i]==NULL){
            u[i]=new unit(type,xx,yy,l->get_map()->all_blocks[xx/l->get_map()->block_width][yy/l->get_map()->block_height],w);
            return;
        }
    }
}

void game::add_tower(int type,int xx,int yy){
    for(int i{};i<20;i++){
        if(t[i]==NULL){
            t[i]=new tower(type,xx,yy,l->get_map()->all_blocks[xx/l->get_map()->block_width][yy/l->get_map()->block_height],w);
            return;
        }
    }
}

void game::add_bullet(bool e_o_t,int type,int xx,int yy,unit* u_tar){
    for(int i{};i<40;i++){
        if(b[i]==NULL){
            b[i]=new bullet(e_o_t,type,xx,yy,u_tar,w);
            return;
        }
    }
}

void game::add_bullet(bool e_o_t,int type,int xx,int yy,tower* t_tar){
    for(int i{};i<40;i++){
        if(b[i]==NULL){
            b[i]=new bullet(e_o_t,type,xx,yy,t_tar,w);
            return;
        }
    }
}

bool game::if_blocked(int xx,int yy){
    int new_x,new_y;
    new_x=xx-xx%l->get_map()->block_width;
    new_y=yy-yy%l->get_map()->block_height;
    return l->get_map()->all_blocks[new_x/l->get_map()->block_width][new_y/l->get_map()->block_height]->get_setted();
}

int game::move_strategy_x(int a,int b,int c){
    if(if_blocked(a,b))return 0;
    int new_x,new_y;
    new_x=a-a%l->get_map()->block_width;
    new_y=b-b%l->get_map()->block_height;
    return l->get_map()->all_blocks[new_x/l->get_map()->block_width][new_y/l->get_map()->block_height]->next_x_direct()*c;
}

int game::move_strategy_y(int a,int b,int c){
    if(if_blocked(a,b))return 0;
    int new_x,new_y;
    new_x=a-a%l->get_map()->block_width;
    new_y=b-b%l->get_map()->block_height;
    return l->get_map()->all_blocks[new_x/l->get_map()->block_width][new_y/l->get_map()->block_height]->next_y_direct()*c;
}

unit* game::get_unittarget(int a,int b,int c){
    for(int i{};i<30;i++){
        if(u[i]!=NULL){
            if(abs(a-u[i]->get_x())+abs(b-u[i]->get_y())<=c){
                return u[i];
            }
        }
    }
}

tower* game::get_towertarget(int a,int b,int c){
    for(int i{};i<20;i++){
        if(t[i]!=NULL){
            if(abs(a-t[i]->get_x())+abs(b-t[i]->get_y())<=c){
                return t[i];
            }
        }
    }
}

int game::fly_strategy_x(bullet* but,unit* t_u){
    if(t_u==NULL)delete but;
    if(but->get_x()>=t_u->get_x()&&but->get_y()>=t_u->get_y()&&(abs(but->get_x()-t_u->get_x())+abs(but->get_y()-t_u->get_y())<20)){
        t_u->get_atk(but->get_atk_num(),but->get_atk_conditon(),but->get_atk_condition_num());
        delete but;
        return 0;
    }
    int len=abs(t_u->get_x()-but->get_x())+abs(t_u->get_y()-but->get_y());
    double r_x=(double)abs(t_u->get_x()-(double)but->get_x())/len;
    if(but->get_x()<t_u->get_x())
    return but->get_s()*r_x;
    return but->get_s()*r_x*(-1);
}

int game::fly_strategy_y(bullet* but,unit* t_u){
    if(t_u==NULL)delete but;
    if(but->get_x()>=t_u->get_x()&&but->get_y()>=t_u->get_y()&&(abs(but->get_x()-t_u->get_x())+abs(but->get_y()-t_u->get_y())<20)){
        t_u->get_atk(but->get_atk_num(),but->get_atk_conditon(),but->get_atk_condition_num());
        delete but;
        return 0;
    }
    int len=abs(t_u->get_x()-but->get_x())+abs(t_u->get_y()-but->get_y());
    double r_y=(double)abs(t_u->get_y()-(double)but->get_y())/len;
    if(but->get_y()<t_u->get_y())
    return but->get_s()*r_y;
    return but->get_s()*r_y*(-1);
}

int game::fly_strategy_x(bullet* but,tower* t_t){
    if(t_t==NULL)delete but;
    if(but->get_x()>=t_t->get_x()&&but->get_y()>=t_t->get_y()&&(abs(but->get_x()-t_t->get_x())+abs(but->get_y()-t_t->get_y())<20)){
        t_t->get_atk(but->get_atk_num());
        delete but;
        return 0;
    }
    int len=abs(t_t->get_x()-but->get_x())+abs(t_t->get_y()-but->get_y());
    double r_x=(double)abs(t_t->get_x()-(double)but->get_x())/len;
    if(but->get_x()<t_t->get_x())
    return but->get_s()*r_x;
    return but->get_s()*r_x*(-1);
}

int game::fly_strategy_y(bullet* but,tower* t_t){
    if(t_t==NULL)delete but;
    if(but->get_x()>=t_t->get_x()&&but->get_y()>=t_t->get_y()&&(abs(but->get_x()-t_t->get_x())+abs(but->get_y()-t_t->get_y())<20)){
        t_t->get_atk(but->get_atk_num());
        delete but;
        return 0;
    }
    int len=abs(t_t->get_x()-but->get_x())+abs(t_t->get_y()-but->get_y());
    double r_y=(double)abs(t_t->get_y()-(double)but->get_y())/len;
    if(but->get_y()<t_t->get_y())
    return but->get_s()*r_y;
    return but->get_s()*r_y*(-1);
}


void game::act_all(){
    for(int i{};i<30;i++){
        if(u[i]){
            int x=move_strategy_x(u[i]->get_x(),u[i]->get_y(),u[i]->get_s());
            int y=move_strategy_y(u[i]->get_x(),u[i]->get_y(),u[i]->get_s());
            tower* z=get_towertarget(u[i]->get_x(),u[i]->get_y(),u[i]->get_atk_range());
            int atk_act=u[i]->act(x,y,z,time->msec()%u[i]->get_atk_interval()==0);
            if(atk_act==-2)continue;
            if(atk_act==-1){
                u[i]->get_target()->get_atk(u[i]->get_atk_num());
            }
            if(atk_act>=0){
                add_bullet(1,u[i]->get_bullet_type(),u[i]->get_x(),u[i]->get_y(),u[i]->get_target());
            }
        }
    }
    for(int i{};i<20;i++){
        if(t[i]){
            int atk_act=t[i]->act(get_unittarget(t[i]->get_x(),t[i]->get_y(),t[i]->get_atk_range()),time->msec()%t[i]->get_atk_interval()==0);
            if(atk_act==-2)continue;
            if(atk_act==-1){
                t[i]->get_target()->get_atk(t[i]->get_atk_num(),t[i]->get_atk_condition(),t[i]->get_atk_condition_num());
            }
            if(atk_act>=0){
                add_bullet(0,t[i]->get_bullet_type(),t[i]->get_x(),t[i]->get_y(),t[i]->get_target());
            }
        }
    }
    for(int i{};i<40;i++){
        if(b[i]){
            int x,y;
            if(b[i]->get_target_t()){
                x=fly_strategy_x(b[i],b[i]->get_target_t());
                y=fly_strategy_y(b[i],b[i]->get_target_t());
            }
            else{
                x=fly_strategy_x(b[i],b[i]->get_target_u());
                y=fly_strategy_y(b[i],b[i]->get_target_u());
            }
            if(b[i])b[i]->act(x,y);
        }
    }
}

int game::work(int argc, char *argv[]){
    QApplication app(argc, argv);
    QWidget* w=new QWidget;
    w->setGeometry(80,100,1780,880);

    time=new QTime;
    timer=new QTimer();
    timer->setInterval(100);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(act_all()));
    return app.exec();
}
