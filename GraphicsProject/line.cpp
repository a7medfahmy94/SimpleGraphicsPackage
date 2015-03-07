#include "line.h"
#include <iostream>
Line::Line()
{

}

Line::~Line()
{

}
int Line:: round(double d){
  return d + 0.5;
}


void Line::draw_integer_dda(QPainter& p,QPoint& begin,QPoint& end,int pixels[][300],int row,int col){
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
    double initial;
    int change_1 , change_2;
    if(yb < ye){

        p.drawPoint(QPoint(xb,yb));
        pixels[xb][yb] = p.pen().color().value();//save
        if(dx < dy){
            initial = 2*dx - dy;
            change_1 = 2*(dx-dy);
            change_2 = 2*dx;
            while(yb != ye){
                yb++;
                if(initial > 0){
                    xb++;
                    initial += change_1;
                }else{
                    initial += change_2;
                }
                p.drawPoint(QPoint(xb,yb));
                pixels[xb][yb] = p.pen().color().value();//save
            }
        }else{

            initial = dx - 2*dy;
            change_1 = 2*(dx-dy);
            change_2 = -2*dy;
            while(xb != xe){
                xb++;
                if(initial <= 0){
                    yb++;
                    initial += change_1;
                }else{
                    initial += change_2;
                }
                p.drawPoint(QPoint(xb,yb));
                pixels[xb][yb] = p.pen().color().value();//save
            }
        }

    }else{
        p.drawPoint(QPoint(xb,yb));
        pixels[xb][yb] = p.pen().color().value();//save
        if(dx < abs(dy)){
            initial = -2*dx - 2*dy;
            change_1 = 2*(-dx-dy);
            change_2 = -2*dx;

            while(yb != ye){
                yb--;
                if(initial < 0){
                    xb++;
                    initial += change_1;
                }else{
                    initial += change_2;
                }
                p.drawPoint(QPoint(xb,yb));
                pixels[xb][yb] = p.pen().color().value();//save
            }
        }else{
            initial = -dx - 2*dy;
            change_1 = 2*(-dy-dx);
            change_2 = -2*dy;

            while(xb != xe){
                xb++;
                if(initial <= 0){
                    yb--;
                    initial -= change_1;
                }else{
                    initial -= change_2;
                }
                p.drawPoint(QPoint(xb,yb));
                pixels[xb][yb] = p.pen().color().value();//save
            }
        }
    }
}

void Line::draw_cartesian(QPainter& p,QPoint& begin,QPoint& end,int pixels[][300],int row,int col){
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
    pixels[int(x)][int(y)] = p.pen().color().value();//save

    if(dx != 0)
        m = double(dy)/dx;
    else{
        while(y < ye){
            y+=1;
            p.drawPoint(QPoint(x,y));
            pixels[int(x)][int(y)] = p.pen().color().value();//save
        }
        return;
    }
    double c=yb-(m*xb);
//    double d=xb-((1/m)*yb);

    if(abs(dx)>=abs(dy)){

        while(x < xe){
            x=x+1;
            y=(m*x)+c;
            p.drawPoint(QPoint(x,round(y)));
            pixels[int(x)][int(y)] = p.pen().color().value();//save
        }

    }else{

        while(y < ye){
            y=y+1;
//            x=(1/m)*y+d;
            x = (y-c)/m;
            p.drawPoint(QPoint(round(x),y));
            pixels[int(x)][int(y)] = p.pen().color().value();//save
        }
    }



}

void Line::draw_parametric(QPainter &p, QPoint &begin, QPoint &end,int pixels[][300],int row,int col){
    int xb = begin.x();
    int yb = begin.y();
    int xe = end.x();
    int ye = end.y();

    double inc = 1.0/std::max(abs(xb-xe),abs(yb-ye));
    double q = 0;
    std::cout << inc << std::endl;
    while(q <= 1){
        int x = xb + q*(xe-xb);
        int y = yb + q*(ye-yb);
        p.drawPoint(QPoint(x,y));
        pixels[x][y] = p.pen().color().value();//save
        q += inc;
    }
}
