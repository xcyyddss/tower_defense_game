#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <QWidget>

namespace Ui {
class game_board;
}

class game_board : public QWidget
{
    Q_OBJECT
private:
    unit* u[30];
    tower* t[20];
    bullet* b[40];
    level* l;
    QTime* time;
    QTimer* timer;
    QWidget* w;
    Ui::game_board *ui;
public:
    explicit game_board(QWidget *parent = 0);
    ~game_board();
    explicit game(QWidget *parent = 0);
    game();
    game(level* le):l(le){}
    void delete_unit(unit*);
    void delete_tower(tower*);
    void delete_bullet(bullet*);
    void add_unit(int,int,int);
    void add_tower(int,int,int);
    void add_bullet(bool,int,int,int,unit*);
    void add_bullet(bool,int,int,int,tower*);
    int move_strategy_x(int,int,int);
    int move_strategy_y(int,int,int);
    int fly_strategy_x(bullet* but,unit* t_u);
    int fly_strategy_y(bullet* but,unit* t_u);
    int fly_strategy_x(bullet* but,tower* t_t);
    int fly_strategy_y(bullet* but,tower* t_t);
    bool if_blocked(int,int);
    unit* get_unittarget(int,int,int);
    tower* get_towertarget(int,int,int);
    int work(int argc, char *argv[]);
public slots:
    void act_all();

};

#endif // GAME_BOARD_H
