#ifndef LINE_H
#define LINE_H

#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QPaintEvent>
#include "mainwindow.h"
#include <QEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QPaintEvent>
#include <bits/stdc++.h>
#include "drawalgo.h"
#include "file.h"
#include "shape.h"

class Line:public Shape{
public:
    Line();
    Line(QPoint,QPoint);
    ~Line();
    void draw(QPainter&);
    void setDrawAlgo(DrawAlgo*);
    void receivePoint(QPoint);


private:
    DrawAlgo* drawAlgo;
};



#endif // LINE_H
