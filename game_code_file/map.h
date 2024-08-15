#ifndef MAP_H
#define MAP_H

#include<QLabel>
#include<QWidget>
#include <QApplication>
#include<QObject>
#include<QPixmap>
#include<QPainter>
#include<QPaintEvent>
#include<lab.h>
#include<helper_func.h>

extern int start_block_num;
extern int end_block_life;
extern int block__wid;
extern int block__hei;
extern int block_x_num;
extern int block_y_num;
extern int block_type[50][50];
extern int unit_atk_range_array[8];
extern int tower_atk_range_array[7];

class tower;

class block{
private:
    bool start_block;
    bool end_block;
    bool settable;
    bool setted;
    int x,y;
    int wid,hei;
    block* next;
    QLabel* label;
    tower* tow;
    QWidget* ws;
public:
    block():x(0),y(0),tow(NULL),ws(NULL){}
    block(bool s,bool e,bool ble,int a,int b,QWidget* ww):start_block(s),end_block(e),settable(ble),x(a),y(b),setted(0),next(NULL),tow(NULL),label(NULL),ws(ww),wid(block__wid),hei(block__hei){}
    block(block* s):start_block(s->get_start()),end_block(s->get_end()),settable(s->get_settable()),x(s->get_x()),y(s->get_y()),setted(0),next(NULL),label(NULL),tow(NULL){}
    bool get_setted(){return setted;}
    int direction;
    int get_direction(){return direction;}
    void set(){setted=true;}
    void clear(){setted=false;}
    int get_x(){return x;}
    int get_y(){return y;}
    int get_wid(){return wid;}
    int get_hei(){return hei;}
    bool get_start(){return start_block;}
    bool get_end(){return end_block;}
    bool get_settable(){return settable;}
    int next_x_direct(int,int);
    int next_y_direct(int,int);
    tower* get_tower(){return tow;}
    block* get_next(){return next;}
    void clear_tower(){tow=NULL;}
    void set_tower(tower* xxx){tow=xxx;}
    bool if_settable(){return settable;}
    void set_next(block* s){next=s;}
    void set_direction(int xd){direction=xd;}
};
class endblock: public block{
private:
public:
    int life;
    endblock(){}
    endblock(block* b):block(b){}
};

class map_details: public endblock{
public:
    map_details(){}
    int block_width,block_height;
    int block_x_nums,block_y_nums;
    block* all_blocks[50][50];
};

class map: public map_details{
private:
    QLabel* label;
public:
    map(int n,QWidget* ww);
    ~map(){
        for(int i{};i<start_blocks_num;i++){
            delete start_blocks[i];
        }
        for(int i{};i<endblock_num;i++){
            delete end_block[i];
        }
    }

    int start_blocks_num;
    block** start_blocks;
    int endblock_num;
    block** end_block;
};
#endif // MAP_H
