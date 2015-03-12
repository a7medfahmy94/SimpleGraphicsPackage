#ifndef SHAPE_H
#define SHAPE_H

#include <bits/stdc++.h>
#include <QPoint>
#include <QPainter>
#include "drawalgo.h"

class Shape{
public:
    Shape();
    Shape(QPoint,QPoint);
    ~Shape();
    virtual void draw(QPainter&) = 0;
    QPoint getOne();
    QPoint getTwo();
    void setOne(QPoint);
    void setTwo(QPoint);
    virtual void setDrawAlgo(DrawAlgo*) = 0;
    virtual void receivePoint(QPoint) = 0;

protected:
    QPoint pOne,pTwo;
};

#endif // SHAPE_H
