#include "linecartesian.h"
#include <bits/stdc++.h>
#include "helper.h"

LineCartesian::LineCartesian()
{

}

LineCartesian::~LineCartesian()
{

}

void LineCartesian::draw(QPainter& p,std::map<std::string,QPoint> ma){
    QPoint begin = ma["begin"];
    QPoint end = ma["end"];

    int xb = begin.x();
    int xe = end.x();
    int yb = begin.y();
    int ye = end.y();

    if(abs(xb-xe) >= abs(yb-ye)){
        if(xb > xe){
            std::swap(xb,xe);
            std::swap(yb,ye);
        }
    }else{
        if(yb > ye){
            std::swap(xb,xe);
            std::swap(yb,ye);
        }
    }

    int dx=xe-xb;
    int dy=ye-yb;
    double x=xb;
    double y=yb;
    double m;

    p.drawPoint(QPoint(x,y));

    if(dx != 0)
        m = double(dy)/dx;
    else{
        while(y < ye){
            y+=1;
            p.drawPoint(QPoint(x,y));
        }
        return;
    }
    double c=yb-(m*xb);

    if(abs(dx)>=abs(dy)){

        while(x < xe){
            x=x+1;
            y=(m*x)+c;
            p.drawPoint(QPoint(x,Helper::round(y)));
        }

    }else{

        while(y < ye){
            y=y+1;
            x = (y-c)/m;
            p.drawPoint(QPoint(Helper::round(x),y));
        }
    }

}
