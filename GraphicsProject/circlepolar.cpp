#include "circlepolar.h"
#include <bits/stdc++.h>
#include "helper.h"
#include "drawalgo.h"
#include <QPainter>
#include <QPoint>
#include <math.h>

CirclePolar::CirclePolar()
{
}
CirclePolar::~CirclePolar()
{

}
void CirclePolar::draw(QPainter& p,std::map<std::string,QPoint>ma){
    QPoint center = ma["begin"];
    QPoint R = ma["end"];
    double r = std::sqrt(std::pow(center.x()-R.x(),2)+pow(center.y()-R.y(),2));
    double X=r,Y=0;
    double D=1/r;
    DrawAlgo::draw8Points(p,center.x(),center.y(),X,Y);
    double CT=cos(D),ST=sin(D);
    while(X > Y){
        double x1=(X*CT)-(Y*ST);
        Y=(X*ST)+(Y*CT);
        X=x1;
        DrawAlgo::draw8Points(p,center.x(),center.y(),Helper::round(X),Helper::round(Y));
    }
}

