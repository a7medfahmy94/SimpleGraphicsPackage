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

class Line
{
public:
    Line();
    ~Line();
    static void draw_cartesian(QPainter& p,QPoint& begin,QPoint& end,int[][300],int,int);
    static void draw_parametric(QPainter& p,QPoint& begin,QPoint& end,int[][300],int,int);
    static void draw_integer_dda(QPainter& p,QPoint& begin,QPoint& end,int[][300],int,int);
    static int round(double d);
};

#endif // LINE_H
