#include "circlemidpoint.h"
#include <bits/stdc++.h>
#include "helper.h"
#include "drawalgo.h"
#include <QPainter>
#include <QPoint>
CircleMidPoint::CircleMidPoint()
{
}
CircleMidPoint::~CircleMidPoint()
{

}
void CircleMidPoint::draw(QPainter& p,std::map<std::string,QPoint> ma){
    QPoint center = ma["begin"];
    QPoint R = ma["end"];
    int r = std::sqrt(std::pow(center.x()-R.x(),2)+pow(center.y()-R.y(),2));
    int X = 0 , Y = r;
    int d = 1 - r;
    int C1=2;
    int C2=5-2*r;

    DrawAlgo::draw8Points(p,center.x(),center.y(),X,Y);
    while(X < Y){
        ++X;
        if(d >= 0){
            d +=C2;
            C2+=4;
            Y--;
        }else{
            d += C1;
            C2+=2;
        }
        C1+=2;
         DrawAlgo::draw8Points(p,center.x(),center.y(),X,Y);

    }

}
