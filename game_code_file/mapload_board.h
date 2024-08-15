#ifndef MAPLOAD_BOARD_H
#define MAPLOAD_BOARD_H
#include "widget.h"
#include <QApplication>
#include <QPushButton>
#include<QLabel>
#include <QPixmap>
#include <QWidget>
#include <QObject>
#include<QIcon>
#include<QFile>
#include<QTextStream>
#include<helper_func.h>
#include<QDebug>


class mapload_board: public QWidget{
    Q_OBJECT
private:
public:
    mapload_board(QWidget *parent = 0);
    QPushButton* b1;
    QPushButton* b2;
    QPushButton* b3;
public slots:
};

#endif // MAPLOAD_BOARD_H
