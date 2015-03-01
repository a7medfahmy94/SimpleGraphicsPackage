#include "line.h"

Line::Line()
{

}

Line::~Line()
{

}

void Line::draw_integer_dda(QPainter& p,QPoint& begin,QPoint& end){
    int xb = begin.x();
    int xe = end.x();
    int yb = begin.y();
    int ye = end.y();
    if(xb > xe){
        std::swap(xb,xe);
        std::swap(yb,ye);
    }
    int dx = xe - xb;
    int dy = ye - yb;
    double initial = dx - 2*dy;
    const int change_1 = 2*(dx-dy);
    const int change_2 = -2*dy;

    p.drawPoint(QPoint(xb,yb));
    while(xb <= xe){
        xb++;
        if(initial <= 0){
            yb++;
            initial += change_1;
        }else{
            initial += change_2;
        }
        p.drawPoint(QPoint(xb,yb));
    }
}

void Line::draw_cartesian(QPainter& p,QPoint& begin,QPoint& end){
    int xb = begin.x();
    int xe = end.x();
    int yb = begin.y();
    int ye = end.y();
    double m;
    if(xb != xe)
        m = double(yb-ye)/(xb-xe);
    else
        m = 1;
    if(m < 1){//go along the x-axis
        if(xb > xe){std::swap(xb,xe);std::swap(yb,ye);}

        for(int x = xb; x <= xe; x++){
            int y = m*(x-xb) + yb;
            p.drawPoint(QPoint(x,y));
        }

    }else{//go along the y-axis
        std::cout << "Y\n";
        if(yb > ye){std::swap(xb,xe);std::swap(yb,ye);}

        for(int y = yb; y <= ye; y++){
            int x = (y - yb)/m+xb;
            p.drawPoint(QPoint(x,y));
        }

    }
}

void Line::draw_parametric(QPainter &p, QPoint &begin, QPoint &end){
    int xb = begin.x();
    int yb = begin.y();
    int xe = end.x();
    int ye = end.y();
    double inc = 0.01;//modify
    double q = 0;
    while(q <= 1){
        int x = xb + q*(xe-xb);
        int y = yb + q*(ye-yb);
        p.drawPoint(QPoint(x,y));
        q += inc;
    }
}
