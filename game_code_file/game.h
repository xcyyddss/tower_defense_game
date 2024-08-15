#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include<QPushButton>
#include<QTime>
#include<QTimer>
#include<QPainter>
#include<QPaintEvent>
#include<QIcon>
#include<cmath>
#include<level.h>
#include<enemy.h>
#include<tower.h>
#include<helper_func.h>
#include<stdint.h>
#include<lab.h>

extern QMovie* tower_movie_array[];
extern QMovie* tower_weapon_movie_array[];
extern QMovie* unit_movie_array[];
extern game* ga;
extern int unit_atk_array[];
extern int unit_atk_range_array[];

class game: public QWidget{
    Q_OBJECT
private:
    unit* u[30];
    tower* t[20];
    bullet* b[40];
    level* l;
    QWidget* w;
    QPainter* painter;
    int drag;
    lab* label;
    int set_type;
    int now_source;
    int source_speed;
    int life;
    int total_enemy_nums;
    int rest_enemy_nums;
    int present_enemy_nums;
    int plus_speed;
    bool execed;
    int tower_plus_stock[9];
    bool stoped;

public:
    QLabel* ql0;
    QPushButton* b1;
    QLabel* ql1;
    QPushButton* b2;
    QLabel* ql2;
    QPushButton* b3;
    QLabel* ql3;
    QPushButton* b4;
    QLabel* ql4;
    QPushButton* b5;
    QLabel* ql5;
    QPushButton* b6;
    QLabel* ql6;
    QPushButton* b7;
    QLabel* ql7;
    QPushButton* b8;
    QLabel* ql8;
    QLabel* ql9;
    QTime* time;
    QTimer* timer;
    game(int,QWidget *parent = 0);
    ~game();
    void new_level(int x,QWidget* ws){
        QFile file("./project2_movie/levels/"+helper(x)+".txt");
        QTextStream stream(&file);
        file.open(QIODevice::ReadOnly);
        stream>>now_source;
        stream>>source_speed;
        stream>>life;
        stream>>total_enemy_nums;
        rest_enemy_nums=total_enemy_nums;
        present_enemy_nums=0;
        stream>>plus_speed;
        file.close();
        l=new level(x,ws);}
    void delete_unit(unit*);
    void delete_tower(tower*);
    void delete_bullet(bullet*);
    void add_unit(int,int);
    void add_tower(int,int,int);
    void add_bullet(bool,int,int,int,int);
    int move_strategy_x(int,int,int);
    int move_strategy_y(int,int,int);
    int fly_strategy_x(bullet* but,int t_u);
    int fly_strategy_y(bullet* but,int t_u);
    bool if_blocked(int,int);
    bool in_endblock(int,int);
    int get_unittarget(int,int,int);
    int get_unittarget2(int,int,int);
    bool get_aoe_unittarget(int,int,int);
    int get_towertarget(int,int,int);
    bool get_aoe_towertarget(int,int,int);
    void emerge_enemy();
    void upgrade_enemy();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);
    void upgrade_close();
    void upgrade_tower(tower*);
    void upgrade_button(int);
    void fail();
    void vectory();
    void keyPressEvent(QKeyEvent *ev);
signals:
    void add_fail();
    void button_clear(int);
    void back();
public slots:
    void act_all();
    void set_t1();
    void set_t2();
    void upgrade3();
    void upgrade4();
    void upgrade5();
    void upgrade6();
    void upgrade7();
    void upgrade8();
};

#endif // GAME_H
