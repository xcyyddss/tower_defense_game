

#include "frontboard.h"
#include<QDebug>

frontboard::frontboard(QWidget *parent) :
    QWidget(parent)
{


    QLabel* lab=new QLabel(this);
    lab->setPixmap(QPixmap("./project2_movie/back/b_1.jpg"));
    lab->setScaledContents(true);
    lab->setGeometry(0,0,1780,900);

    QFont f("黑体",18);

    QPushButton* p1=new QPushButton("开始游戏",this);
    p1->setGeometry(800,420,200,100);b1=p1;
    b1->setFont(f);

    QPushButton* p2=new QPushButton("地图选项",this);
    p2->setGeometry(800,560,200,100);b2=p2;
    b2->setFont(f);

    QPushButton* p3=new QPushButton("退出游戏",this);
    p3->setGeometry(800,700,200,100);b3=p3;
    b3->setFont(f);


}
