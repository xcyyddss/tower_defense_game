#ifndef FRONTBOARD_H
#define FRONTBOARD_H

#include "widget.h"
#include <QApplication>
#include <QPushButton>
#include<QLabel>
#include <QPixmap>
#include <QWidget>
#include <QObject>
#include<QIcon>

class frontboard: public QWidget{
    Q_OBJECT
private:
    int levels;
    QWidget* w;
public:
    frontboard(QWidget *parent = 0);
    QPushButton* b1;
    QPushButton* b2;
    QPushButton* b3;
};

#endif // FRONTBOARD_H


