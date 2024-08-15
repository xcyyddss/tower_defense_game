#include "levelboard.h"


#include<QDebug>

levelboard::levelboard(QWidget *parent) :
    QWidget(parent)
{

    QLabel* lab=new QLabel(this);
    lab->setPixmap(QPixmap("./project2_movie/back/b_2.jpg"));
    lab->setScaledContents(true);
    lab->setGeometry(0,0,1780,900);

    QFile file("./project2_movie/levels/level_head.txt");
    QTextStream stream(&file);
    file.open(QIODevice::ReadWrite);
    int count;
    stream>>count;
    file.close();
    QFont f("黑体",18);
    for(int i{};i<count;i++){
        bs[i+1]=new but(helper(i+1),this);
        bs[i+1]->setGeometry(40+i%11*140,80+i/11*140,100,100);
        bs[i+1]->setFont(f);
        bs[i+1]->x=i+1;
        QObject::connect(bs[i+1],SIGNAL(clicked()),bs[i+1],SLOT(send2()));
        QObject::connect(bs[i+1],SIGNAL(clicked(int)),this,SLOT(game_begin(int)));
    }
    for(int i{count};i<80;i++)bs[i+1]=NULL;
    bs[0]=new but("返回菜单",this);
    bs[0]->setGeometry(1590,40,150,100);
    bs[0]->setFont(f);
}

void levelboard::game_begin(int level){

    this->hide();
    g=new game(level);
    g->setGeometry(80,80,1780,880);
    g->show();
    QObject::connect(g,SIGNAL(back()),this,SLOT(sender()));

}

void levelboard::renew(){
    QFile file("./project2_movie/levels/level_head.txt");
    QTextStream stream(&file);
    file.open(QIODevice::ReadWrite);
    int count;
    stream>>count;
    file.close();
    QFont f("黑体",18);
    for(int i{};i<count;i++){
        if(bs[i+1])delete bs[i+1];
        bs[i+1]=new but(helper(i+1),this);
        bs[i+1]->setGeometry(40+i%11*140,80+i/11*140,100,100);
        bs[i+1]->setFont(f);
        bs[i+1]->x=i+1;
        QObject::connect(bs[i+1],SIGNAL(clicked()),bs[i+1],SLOT(send2()));
        QObject::connect(bs[i+1],SIGNAL(clicked(int)),this,SLOT(game_begin(int)));
    }
}
