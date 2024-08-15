#include "level.h"

level::level(int n,QWidget* ww)
{
    QFile file("./project2_movie/levels/"+helper(n)+".txt");
    QTextStream stream(&file);
    file.open(QIODevice::ReadOnly);
    int a,b,c,d,e;
    stream>>a>>b>>c>>d>>e;
    int map_index;
    stream>>map_index;
    map_l=new map(map_index,ww);
    for(int i{1};i<8;i++){
        stream>>enemies[i];
    }
    file.close();
}
