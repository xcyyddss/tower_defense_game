#include "levelmake_board.h"

levelmake_board::levelmake_board(QWidget *parent) : QWidget(parent)
{
    QFont f("黑体",18);
    edit1=new QLineEdit(this);
    edit2=new QLineEdit(this);
    edit3=new QLineEdit(this);
    edit4=new QLineEdit(this);
    edit5=new QLineEdit(this);
    edit6=new QLineEdit(this);
    edit7=new QLineEdit(this);
    edit8=new QLineEdit(this);
    edit9=new QLineEdit(this);
    edit10=new QLineEdit(this);
    edit11=new QLineEdit(this);
    edit12=new QLineEdit(this);
    edit13=new QLineEdit(this);

    QLabel* label1=new QLabel(" 初始资源",this);
    QLabel* label2=new QLabel(" 资源增速",this);
    QLabel* label3=new QLabel("  生命值",this);
    QLabel* label4=new QLabel(" 敌人总量",this);
    QLabel* label5=new QLabel("敌进化速度",this);
    QLabel* label6=new QLabel("敌生成速度",this);
    QLabel* label7=new QLabel("闪现敌占比",this);
    QLabel* label8=new QLabel("自爆敌占比",this);
    QLabel* label9=new QLabel("神速敌占比",this);
    QLabel* label10=new QLabel("远攻敌占比",this);
    QLabel* label11=new QLabel("治疗敌占比",this);
    QLabel* label12=new QLabel("boss敌占比",this);
    QLabel* label13=new QLabel(" 地图编号",this);

    label1->setGeometry(150,80,150,70);
    label2->setGeometry(450,80,150,70);
    label3->setGeometry(750,80,150,70);
    label4->setGeometry(1050,80,150,70);
    label5->setGeometry(1350,80,150,70);

    label6->setGeometry(100,330,150,70);
    label7->setGeometry(330,330,150,70);
    label8->setGeometry(560,330,150,70);
    label9->setGeometry(790,330,150,70);
    label10->setGeometry(1020,330,150,70);
    label11->setGeometry(1250,330,150,70);
    label12->setGeometry(1480,330,150,70);

    label13->setGeometry(800,580,150,70);

    label1->setFont(f);
    label2->setFont(f);
    label3->setFont(f);
    label4->setFont(f);
    label5->setFont(f);
    label6->setFont(f);
    label7->setFont(f);
    label8->setFont(f);
    label9->setFont(f);
    label10->setFont(f);
    label11->setFont(f);
    label12->setFont(f);
    label13->setFont(f);

    edit1->setGeometry(150,150,150,70);
    edit2->setGeometry(450,150,150,70);
    edit3->setGeometry(750,150,150,70);
    edit4->setGeometry(1050,150,150,70);
    edit5->setGeometry(1350,150,150,70);

    edit6->setGeometry(100,400,150,70);
    edit7->setGeometry(330,400,150,70);
    edit8->setGeometry(560,400,150,70);
    edit9->setGeometry(790,400,150,70);
    edit10->setGeometry(1020,400,150,70);
    edit11->setGeometry(1250,400,150,70);
    edit12->setGeometry(1480,400,150,70);

    edit13->setGeometry(800,650,150,70);

    edit1->setFont(f);
    edit2->setFont(f);
    edit3->setFont(f);
    edit4->setFont(f);
    edit5->setFont(f);
    edit6->setFont(f);
    edit7->setFont(f);
    edit8->setFont(f);
    edit9->setFont(f);
    edit10->setFont(f);
    edit11->setFont(f);
    edit12->setFont(f);
    edit13->setFont(f);


    edit1->setText("300");
    edit2->setText("5");
    edit3->setText("5");
    edit4->setText("25");
    edit5->setText("8");
    edit6->setText("5");
    edit7->setText("50");
    edit8->setText("30");
    edit9->setText("50");
    edit10->setText("40");
    edit11->setText("30");
    edit12->setText("3");
    edit13->setText("1");


    edit1->setAlignment(Qt::AlignCenter);
    edit2->setAlignment(Qt::AlignCenter);
    edit3->setAlignment(Qt::AlignCenter);
    edit4->setAlignment(Qt::AlignCenter);
    edit5->setAlignment(Qt::AlignCenter);
    edit6->setAlignment(Qt::AlignCenter);
    edit7->setAlignment(Qt::AlignCenter);
    edit8->setAlignment(Qt::AlignCenter);
    edit9->setAlignment(Qt::AlignCenter);
    edit10->setAlignment(Qt::AlignCenter);
    edit11->setAlignment(Qt::AlignCenter);
    edit12->setAlignment(Qt::AlignCenter);
    edit13->setAlignment(Qt::AlignCenter);


    b1=new QPushButton("保存关卡",this);
    b1->setGeometry(400,650,200,100);
    b1->setFont(f);
    QObject::connect(b1,SIGNAL(clicked()),this,SLOT(save()));

    b2=new QPushButton("返回菜单",this);
    b2->setGeometry(1150,650,200,100);
    b2->setFont(f);

}

void levelmake_board::save(){
    int e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13;
    if(!cin_check2(edit1->text())){dial("     请输入合法数字！");return;}
    if(!cin_check2(edit2->text())){dial("     请输入合法数字！");return;}
    if(!cin_check2(edit3->text())){dial("     请输入合法数字！");return;}
    if(!cin_check2(edit4->text())){dial("     请输入合法数字！");return;}
    if(!cin_check2(edit5->text())){dial("     请输入合法数字！");return;}
    if(!cin_check2(edit6->text())){dial("     请输入合法数字！");return;}
    if(!cin_check2(edit7->text())){dial("     请输入合法数字！");return;}
    if(!cin_check2(edit8->text())){dial("     请输入合法数字！");return;}
    if(!cin_check2(edit9->text())){dial("     请输入合法数字！");return;}
    if(!cin_check2(edit10->text())){dial("     请输入合法数字！");return;}
    if(!cin_check2(edit11->text())){dial("     请输入合法数字！");return;}
    if(!cin_check2(edit12->text())){dial("     请输入合法数字！");return;}
    if(!cin_check2(edit13->text())){dial("     请输入合法数字！");return;}
    e1=edit1->text().toInt();
    e2=edit2->text().toInt();
    e3=edit3->text().toInt();
    e4=edit4->text().toInt();
    e5=edit5->text().toInt();
    e6=edit6->text().toInt();
    e7=edit7->text().toInt();
    e8=edit8->text().toInt();
    e9=edit9->text().toInt();
    e10=edit10->text().toInt();
    e11=edit11->text().toInt();
    e12=edit12->text().toInt();
    e13=edit13->text().toInt();


    QFile file1("./project2_movie/maps/map_head.txt");
    QTextStream stream1(&file1);
    file1.open(QIODevice::ReadOnly);
    QFile file2("./project2_movie/levels/level_head.txt");
    QTextStream stream2(&file2);
    file2.open(QIODevice::ReadOnly);
    int map_count,level_count;
    stream1>>map_count;
    stream2>>level_count;
    file1.close();file2.close();
    level_count++;
    if(e13>map_count){
        dial("     地图编号不存在！");
        return;
    }
    QFile file("./project2_movie/levels/"+helper(level_count)+".txt");
    QTextStream stream(&file);
    file.open(QIODevice::WriteOnly);
    stream<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5*1000<<" "<<e13<<" "<<e6*1000<<" "<<e7<<" "<<e8<<" "<<e9<<" "<<e10<<" "<<e11<<" "<<e12;
    dial("   关卡已保存，编号为"+helper(level_count));
    QFile file3("./project2_movie/levels/level_head.txt");
    QTextStream stream3(&file3);
    file3.open(QIODevice::WriteOnly);
    stream3<<level_count;
    file.close();file1.close();file2.close();file3.close();
}
