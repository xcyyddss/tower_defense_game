#ifndef LEVEL_H
#define LEVEL_H

#include<map.h>
#include<QFile>
#include<QTextStream>


class level{
private:
    map* map_l;
public:
    level(int x,QWidget* ww);
    ~level(){
        delete map_l;
    }

    map* get_map(){return map_l;}
    int enemies[10];
};

#endif // LEVEL_H
