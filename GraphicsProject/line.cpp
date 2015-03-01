#include "line.h"

Line::Line()
{

}

Line::~Line()
{

}
int Line:: round(double d){
  return d + 0.5;
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
    int dx=xe-xb;
    int dy=ye-yb;
    int x=xb;
    int y=yb;
    double m;
     p.drawPoint(QPoint(x,y));

    if(xb > xe)
        std::swap(xb,xe);std::swap(yb,ye);

    if(dx != 0)
        m = double(dy)/dx;
    else
        m = 1;

    double c=yb-(m*xb);
    double d=xb-((1/m)*yb);

    if(abs(dx)>=abs(dy)){
        while(x < xe){
            x=x+1;
            y=(m*x)+c;
            p.drawPoint(QPoint(x,round(y)));

        }
    }else{
        while(y < ye){
            y=y+1;
            x=(1/m)*y+d;
            p.drawPoint(QPoint(round(x),y));

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
