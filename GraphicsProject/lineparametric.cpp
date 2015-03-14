#include "lineparametric.h"
#include <bits/stdc++.h>

LineParametric::LineParametric()
{

}

LineParametric::~LineParametric()
{

}

void LineParametric::draw(QPainter& p,std::map<std::string,QPoint> ma){
    QPoint begin = ma["begin"];
    QPoint end = ma["end"];

    int xb = begin.x();
    int yb = begin.y();
    int xe = end.x();
    int ye = end.y();

    double inc = 1.0/std::max(abs(xb-xe),abs(yb-ye));
    double q = 0;
    while(q <= 1){
        int x = xb + q*(xe-xb);
        int y = yb + q*(ye-yb);
        p.drawPoint(QPoint(x,y));
        q += inc;
    }
}
