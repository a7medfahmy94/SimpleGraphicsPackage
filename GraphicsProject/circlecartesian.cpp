#include "circlecartesian.h"
#include <bits/stdc++.h>
#include "helper.h"
#include "drawalgo.h"
#include <QPainter>
#include <QPoint>

CircleCartesian::CircleCartesian()
{

}
CircleCartesian::~CircleCartesian()
{

}

void CircleCartesian::draw(QPainter& p,std::map<std::string,QPoint> ma){
    QPoint center = ma["begin"];
    QPoint R = ma["end"];

  // if(center.x() != -1 && R.x() != -1){
       int r = std::sqrt(std::pow(center.x()-R.x(),2)+pow(center.y()-R.y(),2));
       int X = 0 , Y = r;

        while(X < Y){
            X++;
           // std::cout << X << " " << Y << std::endl;
            Y = sqrt(r*r - X*X);
            DrawAlgo::draw8Points(p,center.x(),center.y(),X,Y);
        }

    //}
}
