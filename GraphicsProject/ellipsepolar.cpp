#include "ellipsepolar.h"
#include <bits/stdc++.h>
#include <QPoint>
#include <QPainter>
#include "drawalgo.h"
#include "helper.h"

EllipsePolar::EllipsePolar()
{

}

EllipsePolar::~EllipsePolar()
{

}

void EllipsePolar::draw(QPainter& painter,std::map<std::string,QPoint> ma){
    QPoint center = ma["center"];
    QPoint a = ma["a"];
    QPoint b = ma["b"];


    float A = a.x() - center.x();
    float B = center.y() - b.y();
    float X = A , Y = 0;
    double dtheta = 1.0/std::max(A,B);
    double ct = std::cos(dtheta);
    double st1 = (A/B)*std::sin(dtheta);
    double st2 = (B/A)*std::sin(dtheta);


    DrawAlgo::draw4Points(painter,center.x(),center.y(),Helper::round(X),Helper::round(Y));

    while(X > 0){
        float X1 = X*ct - Y*st1;
        Y = X*st2 + Y*ct;
        X = X1;
        DrawAlgo::draw4Points(painter,center.x(),center.y(),Helper::round(X),Helper::round(Y));
    }
}

