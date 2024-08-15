#include<QDebug>
#include "map.h"
map::map(int n,QWidget* w)
{
    QFile file("./project2_movie/maps/"+helper(n)+".txt");
    QTextStream stream(&file);
    file.open(QIODevice::ReadOnly);
    stream>>block_y_num>>block_x_num;
    for(int i{};i<block_x_num;i++){
        for(int j{};j<block_y_num;j++){
            stream>>block_type[i][j];
        }
    }

    block__wid=1500/block_x_num;
    block__hei=860/block_y_num;
    if(block__wid<block__hei)block__hei=block__wid;
    else block__wid=block__hei;

    unit_atk_range_array[1]=block__wid*1.2;
    unit_atk_range_array[3]=block__wid*2;
    unit_atk_range_array[5]=block__wid*5;
    unit_atk_range_array[7]=block__wid*5;

    tower_atk_range_array[1]=block__wid*1.2;
    tower_atk_range_array[2]=block__wid*5;

    block_x_nums=block_x_num;
    block_y_nums=block_y_num;
    start_blocks_num=0;
    start_blocks=new block*[20];
    block_width=block__wid;
    block_height=block__hei;
    endblock_num=0;
    for(int i{};i<block_x_num;i++){
        for(int j{};j<block_y_num;j++){
            if(block_type[i][j]==0){
                all_blocks[i][j]=new block(0,0,0,i*block_width,j*block_height,w);
            }
            if(block_type[i][j]==1){
                all_blocks[i][j]=new block(0,0,1,i*block_width,j*block_height,w);
                all_blocks[i][j]->set_direction(-10);
            }
            if(block_type[i][j]==2){
                all_blocks[i][j]=new block(1,0,0,i*block_width,j*block_height,w);
                start_blocks[start_blocks_num]=all_blocks[i][j];
                start_blocks_num++;
            }
            if(block_type[i][j]==3){
                all_blocks[i][j]=new block(0,1,0,i*block_width,j*block_height,w);
                all_blocks[i][j]->set_next(new block(0,0,0,i*block_width,j*block_height,w));
                endblock_num++;
            }
        }
    }
    end_block=new block* [endblock_num];int k{};
        for(int i{};i<block_x_num;i++){
            for(int j{};j<block_y_num;j++){
                if(block_type[i][j]==3){
                    end_block[k]=all_blocks[i][j];
                    k++;
                }
            }
        }
    for(int k{};k<start_blocks_num;k++){
        for(int i{};i<block_x_num;i++){
            for(int j{};j<block_y_num;j++){
                if(all_blocks[i][j]==start_blocks[k]){
                    start_blocks[k]->set_direction(0);
                    int pre_x{-10},pre_y{-10};
                    int now_x{i},now_y{j};
                    while(true){
                        if(now_x+1<block_x_num&&now_x+1!=pre_x&&(block_type[now_x+1][now_y]==0||block_type[now_x+1][now_y]==3)){
                            all_blocks[now_x][now_y]->set_next(all_blocks[now_x+1][now_y]);
                            all_blocks[now_x+1][now_y]->set_direction(1);
                            if(all_blocks[now_x][now_y]->direction==0)all_blocks[now_x][now_y]->direction=1;
                            if(all_blocks[now_x][now_y]->direction==-2)all_blocks[now_x][now_y]->direction=-4;
                            if(all_blocks[now_x][now_y]->direction==2)all_blocks[now_x][now_y]->direction=6;
                            if(block_type[now_x+1][now_y]==3)break;
                            pre_x=now_x;
                            pre_y=now_y;
                            now_x++;
                        }
                        else{
                            if(now_x-1>=0&&now_x-1!=pre_x&&(block_type[now_x-1][now_y]==0||block_type[now_x-1][now_y]==3)){
                                all_blocks[now_x][now_y]->set_next(all_blocks[now_x-1][now_y]);
                                all_blocks[now_x-1][now_y]->set_direction(-1);
                                if(all_blocks[now_x][now_y]->direction==0)all_blocks[now_x][now_y]->direction=-1;
                                if(all_blocks[now_x][now_y]->direction==-2)all_blocks[now_x][now_y]->direction=-6;
                                if(all_blocks[now_x][now_y]->direction==2)all_blocks[now_x][now_y]->direction=4;
                                if(block_type[now_x-1][now_y]==3)break;
                                pre_x=now_x;
                                pre_y=now_y;
                                now_x--;
                            }
                            else{
                                if(now_y+1<block_y_num&&now_y+1!=pre_y&&(block_type[now_x][now_y+1]==0||block_type[now_x][now_y+1]==3)){
                                    all_blocks[now_x][now_y]->set_next(all_blocks[now_x][now_y+1]);
                                    all_blocks[now_x][now_y+1]->set_direction(2);
                                    if(all_blocks[now_x][now_y]->direction==0)all_blocks[now_x][now_y]->direction=2;
                                    if(all_blocks[now_x][now_y]->direction==-1)all_blocks[now_x][now_y]->direction=3;
                                    if(all_blocks[now_x][now_y]->direction==1)all_blocks[now_x][now_y]->direction=5;
                                    if(block_type[now_x][now_y+1]==3)break;
                                    pre_y=now_y;
                                    pre_x=now_x;
                                    now_y++;
                                }
                                else{
                                    if(now_y-1>=0&&now_y-1!=pre_y&&(block_type[now_x][now_y-1]==0||block_type[now_x][now_y-1]==3)){
                                        all_blocks[now_x][now_y]->set_next(all_blocks[now_x][now_y-1]);
                                        all_blocks[now_x][now_y-1]->set_direction(-2);
                                        if(all_blocks[now_x][now_y]->direction==0)all_blocks[now_x][now_y]->direction=-2;
                                        if(all_blocks[now_x][now_y]->direction==-1)all_blocks[now_x][now_y]->direction=-5;
                                        if(all_blocks[now_x][now_y]->direction==1)all_blocks[now_x][now_y]->direction=-3;
                                        if(block_type[now_x][now_y-1]==3)break;
                                        pre_y=now_y;
                                        pre_x=now_x;
                                        now_y--;
                                    }
                                }
                            }
                        }
                    }
                    goto here;
                }
            }
        }
        here:;
    }
}


int block::next_x_direct(int b_x,int b_y){
    if(direction==1)return 1;
    if(direction==-1)return -1;
    if(direction==3&&b_x!=x)return -1;
    if(direction==4)return -1;
    if(direction==-4&&b_y==y)return 1;
    if(direction==-5&&b_x!=x)return -1;
    if(direction==6)return 1;
    if(direction==-6&&b_y==y)return -1;
    return 0;
}

int block::next_y_direct(int b_x,int b_y){
    if(direction==2)return 1;
    if(direction==-2)return -1;
    if(direction==3&&b_x==x)return 1;
    if(direction==-3)return -1;
    if(direction==-4&&b_y!=y)return -1;
    if(direction==5)return 1;
    if(direction==-5&&b_x==x)return -1;
    if(direction==-6&&b_y!=y)return -1;
    return 0;
}
