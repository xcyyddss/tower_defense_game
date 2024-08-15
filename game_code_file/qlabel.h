#ifndef QLABEL_H
#define QLABEL_H

#include<QLabel>
#include<QWidget>

class qlabel:public QLabel
{
    Q_OBJECT
public:
    qlabel(QWidget* w);
};

#endif // QLABEL_H
