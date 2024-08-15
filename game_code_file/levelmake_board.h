#ifndef LEVELMAKE_BOARD_H
#define LEVELMAKE_BOARD_H


#include "widget.h"
#include <QApplication>
#include <QPixmap>
#include <QWidget>
#include <QObject>
#include<QIcon>
#include<QFile>
#include<QTextStream>
#include<QLineEdit>
#include<QFile>
#include<lab.h>
#include<helper_func.h>

class levelmake_board : public QWidget
{
    Q_OBJECT
public:
    levelmake_board(QWidget *parent = NULL);
    QPushButton* b1;
    QPushButton* b2;
    QLineEdit* edit1;
    QLineEdit* edit2;
    QLineEdit* edit3;
    QLineEdit* edit4;
    QLineEdit* edit5;
    QLineEdit* edit6;
    QLineEdit* edit7;
    QLineEdit* edit8;
    QLineEdit* edit9;
    QLineEdit* edit10;
    QLineEdit* edit11;
    QLineEdit* edit12;
    QLineEdit* edit13;
    QLineEdit* edit14;

signals:

public slots:
    void save();
};

#endif // LEVELMAKE_BOARD_H
