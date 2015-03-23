#include "ellipsecartesian.h"
#include <bits/stdc++.h>
#include <QPoint>
#include "drawalgo.h"
#include "helper.h"

EllipseCartesian::EllipseCartesian()
{

}

EllipseCartesian::~EllipseCartesian()
{

}



void EllipseCartesian::draw(QPainter& painter,std::map<std::string,QPoint> ma){
    QPoint center = ma["center"];
    QPoint a = ma["a"];
    QPoint b = ma["b"];


    float A = a.x() - center.x();
    float B = center.y() - b.y();
    int X = 0 , Y = B;

    DrawAlgo::draw4Points(painter,center.x(),center.y(),X,Y);
    while(X*B*B <= Y*A*A){
        X++;
        Y = Helper::round(B*sqrt(1 - ((X*X)/(A*A))));
        DrawAlgo::draw4Points(painter,center.x(),center.y(),X,Y);
    }

    X = A , Y = 0;
    DrawAlgo::draw4Points(painter,center.x(),center.y(),X,Y);
    while(X*B*B > Y*A*A){
        Y++;
        X = Helper::round(A*sqrt(1-((Y*Y)/(B*B))));
        DrawAlgo::draw4Points(painter,center.x(),center.y(),X,Y);
    }

}
