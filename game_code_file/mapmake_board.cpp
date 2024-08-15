#include "mapmake_board.h"

mapmake_board::mapmake_board(QWidget *parent) : QWidget(parent)
{
    for(int i{};i<50;i++){
        for(int j{};j<50;j++){
            map_sig[i][j]=0;
            bs[i][j]=NULL;
        }
    }
    QFont f("黑体",18);
    QFont ff("黑体",24);
    edit1=new QLineEdit(this);
    edit2=new QLineEdit(this);
    edit1->setFont(f);
    edit2->setFont(f);
    edit1->setGeometry(50,100,150,70);
    edit2->setGeometry(250,100,150,70);
    edit1->setAlignment(Qt::AlignCenter);
    edit2->setAlignment(Qt::AlignCenter);
    QLabel* label1=new QLabel("地图行高",this);
    QLabel* label2=new QLabel("地图列宽",this);
    QLabel* label3=new QLabel("注意：",this);
    QLabel* label4=new QLabel("蓝色为道路",this);
    QLabel* label5=new QLabel("绿色为起点",this);
    QLabel* label6=new QLabel("红色为终点",this);
    label1->setGeometry(60,50,150,50);
    label2->setGeometry(260,50,150,50);
    label3->setGeometry(100,270,150,50);
    label4->setGeometry(100,320,150,50);
    label5->setGeometry(100,370,150,50);
    label6->setGeometry(100,420,150,50);
    label1->setFont(f);
    label2->setFont(f);
    label3->setFont(f);
    label4->setFont(f);
    label5->setFont(f);
    label6->setFont(f);
    b1=new QPushButton("确定",this);
    b1->setGeometry(150,200,150,50);
    b1->setFont(f);
    b2=new QPushButton("清空地图",this);
    b2->setGeometry(150,500,150,50);
    b2->setFont(f);
    b3=new QPushButton("保存地图",this);
    b3->setGeometry(150,570,150,50);
    b3->setFont(f);
    b4=new QPushButton("返回菜单",this);
    b4->setGeometry(100,700,250,80);
    b4->setFont(ff);
    QObject::connect(b1,SIGNAL(clicked()),this,SLOT(map_show()));
    QObject::connect(b2,SIGNAL(clicked()),this,SLOT(clear()));
    QObject::connect(b3,SIGNAL(clicked()),this,SLOT(save()));
}



void mapmake_board::map_show(){
    if(!cin_check(edit1->text())){
        dial("      请输入合法整数");
        return;
    }
    if(!cin_check(edit2->text())){
        dial("      请输入合法整数");
        return;
    }
    hei=edit1->text().toInt();
    wid=edit2->text().toInt();
    if(hei>25){
        dial("       行高应小于25");
        return;
    }
    if(wid>40){
        dial("       列宽应小于40");
        return;
    }
    for(int i{};i<50;i++){
        for(int j{};j<50;j++){
            if(bs[i][j])delete bs[i][j];
            bs[i][j]=NULL;
        }
    }
    for(int i{};i<hei;i++){
        for(int j{};j<wid;j++){
            bs[i][j]=new but(this);
            bs[i][j]->setGeometry(500+j*30,50+i*30,30,30);
            bs[i][j]->show();
            bs[i][j]->x=i;
            bs[i][j]->y=j;
            QObject::connect(bs[i][j],SIGNAL(clicked()),bs[i][j],SLOT(send()));
            QObject::connect(bs[i][j],SIGNAL(clicked(int,int)),this,SLOT(but_change(int,int)));
            bs[i][j]->setStyleSheet("background: White");

        }
    }
}

void mapmake_board::set_color(int x,int y){
    if(map_sig[x][y]==0){
        bs[x][y]->setStyleSheet("background: White");
    }
    if(map_sig[x][y]==1){
        bs[x][y]->setStyleSheet("background: Blue");
    }
    if(map_sig[x][y]==2){
        bs[x][y]->setStyleSheet("background: Green");
    }
    if(map_sig[x][y]==3){
        bs[x][y]->setStyleSheet("background: Red");
    }
}

void mapmake_board::but_change(int x,int y){
    map_sig[x][y]=(map_sig[x][y]+1)%4;
    set_color(x,y);
}

void mapmake_board::clear(){
    for(int i{};i<hei;i++){
        for(int j{};j<wid;j++){
            map_sig[i][j]=0;
            set_color(i,j);
        }
    }
}

bool mapmake_board::end_valid(int x,int y){
    int dx[4]{1,0,-1,0};
    int dy[4]{0,1,0,-1};
    int ans{};
    for(int i{};i<4;i++){
        if(x+dx[i]>=0&&x+dx[i]<hei&&y+dy[i]>=0&&y+dy[i]<wid)ans+=map_sig[x+dx[i]][y+dy[i]];
    }
    if(ans==1)return true;
    return false;
}

bool mapmake_board::road_valid(int x,int y,int xx,int yy){
    int dx[4]{1,0,-1,0};
    int dy[4]{0,1,0,-1};
    if((map_sig[x][y]==3)&&end_valid(x,y))return true;
    if(map_sig[x][y]==2&&end_valid(x,y)){
        for(int i{};i<4;i++){
            if(x+dx[i]>=0&&x+dx[i]<hei&&y+dy[i]>=0&&y+dy[i]<wid&&map_sig[x+dx[i]][y+dy[i]]==1)return road_valid(x+dx[i],y+dy[i],dx[i],dy[i]);
        }
    }
    if(map_sig[x][y]==1){
        int ans{};
        for(int i{};i<4;i++){
            if(x+dx[i]>=0&&x+dx[i]<hei&&y+dy[i]>=0&&y+dy[i]<wid&&map_sig[x+dx[i]][y+dy[i]]>0)ans++;
        }
        if(ans!=2)return false;
        for(int i{};i<4;i++){
            if(x+dx[i]>=0&&x+dx[i]<hei&&y+dy[i]>=0&&y+dy[i]<wid&&(dx[i]!=-xx||dy[i]!=-yy)&&map_sig[x+dx[i]][y+dy[i]]>0)return road_valid(x+dx[i],y+dy[i],dx[i],dy[i]);
        }
    }
    return false;
}

bool mapmake_board::if_valid(){
    bool p{false};
    for(int i{};i<hei;i++){
        for(int j{};j<wid;j++){
            if(map_sig[i][j]==2){
                p=true;
                if(!road_valid(i,j,0,0))return false;
            }
        }
    }
    return p;
}


void mapmake_board::save(){
    if(!if_valid()){
        dial("地图不合法！请修改后重试！");
    }
    else{
        QFile file("./project2_movie/maps/map_head.txt");
        QTextStream stream(&file);
        file.open(QIODevice::ReadOnly);
        int count;
        stream>>count;
        count++;
        file.close();
        file.open(QIODevice::WriteOnly);
        stream<<count;
        QString s=helper(count);
        QFile file_add("./project2_movie/maps/"+s+".txt");
        file_add.open(QIODevice::WriteOnly);
        QTextStream stream2(&file_add);
        stream2<<hei<<" "<<wid<<" \n";
        for(int j{};j<wid;j++){
            for(int i{};i<hei;i++){
                if(map_sig[i][j]==1)stream2<<0<<" ";
                else{
                    if(map_sig[i][j]==0)stream2<<1<<" ";
                    else{
                        stream2<<map_sig[i][j]<<" ";
                    }
                }
            }
            stream2<<"\n";
        }
        dial("   地图已保存，编号为"+helper(count));
    }
}
