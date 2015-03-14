#ifndef CIRCLE_H
#define CIRCLE_H

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

class Circle:public Shape
{
public:
    Circle();
    Circle(QPoint,QPoint);
    ~Circle();
    void draw(QPainter&);
    void setDrawAlgo(DrawAlgo*);
    void receivePoint(QPoint);

private:
    DrawAlgo* drawAlgo;
};

#endif // CIRCLE_H

