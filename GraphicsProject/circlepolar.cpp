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
    //if(center.x() != -1 && R.x() != -1){
        int r = std::sqrt(std::pow(center.x()-R.x(),2)+pow(center.y()-R.y(),2));
        int X = r , Y = 0;
        DrawAlgo::draw8Points(p,center.x(),center.y(),X,Y);
       // double Q=0.0,delta=(1/r);
        //while(X>Y){
          //  Q+=delta;
            //X=r*cos(Q);
            //Y=r*sin(Q);
            //DrawAlgo::draw8Points(p,center.x(),center.y(),Helper::round(X),Helper::round(Y));
       // }
        double delta=1/r;
        double ct=cos(delta),st=sin(delta);
        while(X > Y){
            double x1=X*ct-Y*st;
            Y=X*st+Y*ct;
            X=x1;
            DrawAlgo::draw8Points(p,center.x(),center.y(),Helper::round(X),Helper::round(Y));
        }

    //}
}

