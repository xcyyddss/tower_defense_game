#ifndef LAB_H
#define LAB_H

#include<QWidget>
#include<QLabel>
#include<QEvent>
#include<QString>
#include<QPushButton>

class tower;
extern int grade_sig;
class game;

class lab: public QLabel
{
    Q_OBJECT
public:
    int block_x,block_y;
    int x_displace,y_displace;
    lab(){}
    lab(QWidget* w);
};

class lable: public QLabel{
    Q_OBJECT
public:
    lable(){}
    QWidget* ww;
    lable(QWidget* w,tower* t): QLabel(w),ww(w),grade_tower(t){ this ->setAttribute(Qt::WA_TransparentForMouseEvents,  true );}
    lable(QWidget* w,tower* t,QString xx): QLabel(xx,w),ww(w),grade_tower(t){ this ->setAttribute(Qt::WA_TransparentForMouseEvents,  true );}
    tower* grade_tower;
    game* g;
};

class but: public QPushButton{
    Q_OBJECT
public:
    int x,y;
    but():QPushButton(){}
    but(QString s,QWidget* w):QPushButton(s,w){}
    but(QWidget* w):QPushButton(w){}
public slots:
    void send(){emit clicked(x,y);}
    void send2(){emit clicked(x);}
signals:
    void clicked(int,int);
    void clicked(int);

};

#endif // LAB_H
