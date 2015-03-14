#include "circledda.h"
#include <bits/stdc++.h>
#include "helper.h"
#include "drawalgo.h"
#include <QPainter>
#include <QPoint>
CircleDDA::CircleDDA()
{
}
CircleDDA::~CircleDDA()
{

}
void CircleDDA::draw(QPainter& p,std::map<std::string,QPoint> ma){
    QPoint center = ma["begin"];
    QPoint R = ma["end"];

    //if(center.x() != -1 && R.x() != -1){
        int r = std::sqrt(std::pow(center.x()-R.x(),2)+pow(center.y()-R.y(),2));
        int X = 0 , Y = r;
        int d = 1 - r;
        DrawAlgo::draw8Points(p,center.x(),center.y(),X,Y);
        while(X < Y){
            ++X;
            if(d >= 0){
                d += 2*X - 2*Y + 3;
                Y--;
            }else{
                d += 2*X+1;
            }
             DrawAlgo::draw8Points(p,center.x(),center.y(),X,Y);

        }
    //}
}
