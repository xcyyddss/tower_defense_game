#include "init.h"

#include<QMovie>

class tower;
class lable;
class game;
 game* ga;

 int bullet_atk_array[7]{10,10,10,10,10,15,10};
 int bullet_speed_array[7]{10,10,10,10,10,10,10};
 int bullet_atk_condition_array[7]{0,0,2,3,0,0,6};
 int bullet_atk_condition_num_array[7]{0,0,1,0,0,0,1};

 int unit_life_array[8]{30,40,30,60,60,60,80,200};
 int unit_atk_array[8]{20,10,10,50,10,10,40,60};
 int unit_speed_array[8]{2,2,2,2,5,2,2,2};
 int unit_atk_interval_array[8]{5000,5000,5000,5000000,5000,5000,5000,5000};
 int unit_atk_range_array[8]{80,100,100,300,100,500,500,500};
 bool unit_is_thrower_array[8]{0,0,0,0,0,1,1,0};
 int unit_bullet_type_array[8]{0,0,0,0,0,4,5,0};
 int unit_width_array[8]{50,50,50,50,50,50,50,50};
 int unit_height_array[8]{50,50,50,50,50,50,50,50};


 int start_block_num{1};
 int end_block_life{50};
 int block__wid{50};
 int block__hei{50};
 int block_x_num{10};
 int block_y_num{10};
 int block_type[50][50]{};


 int tower_life_array[7]{500,100,100,300,150,100,100};
 int tower_atk_array[7]{10,10,10,10,10,10,10};
 int tower_atk_interval_array[7]{5000,5000,5000,5000,5000,5000,5000};
 int tower_atk_range_array[7]{200,100,500,100,100,100,500};
 int tower_atk_condition_array[7]{0,0,0,0,0,0,0};
 int tower_atk_condition_num_array[7]{0,0,0,0,0,0,0};
 bool tower_is_thrower_array[7]{0,0,1,0,0,0,1};
 int tower_bullet_type_array[7]{1,1,1,1,1,1,2};

 int grade_sig{0};
 lable* grade_lable{NULL};


init::init()
{

}
