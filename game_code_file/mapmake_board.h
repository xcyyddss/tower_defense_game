#ifndef MAPMAKE_BOARD_H
#define MAPMAKE_BOARD_H

#include "widget.h"
#include <QApplication>
#include <QPixmap>
#include <QWidget>
#include <QObject>
#include<QIcon>
#include<QLineEdit>
#include<QFile>
#include<QTextStream>

#include<helper_func.h>
#include<lab.h>

class mapmake_board : public QWidget
{
    Q_OBJECT
public:
    mapmake_board(QWidget *parent = 0);
    int map_sig[50][50];
    int hei,wid;
    but* bs[50][50];
    QPushButton* b1;
    QPushButton* b2;
    QPushButton* b3;
    QPushButton* b4;
    void finish();
    QLineEdit* edit1;
    QLineEdit* edit2;
    void set_color(int,int);
    bool if_valid();
    bool road_valid(int,int,int,int);
    bool end_valid(int,int);

signals:

public slots:
    void map_show();
    void but_change(int,int);
    void clear();
    void save();
};

#endif // MAPMAKE_BOARD_H
