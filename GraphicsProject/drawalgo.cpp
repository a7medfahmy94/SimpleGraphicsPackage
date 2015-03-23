#include "drawalgo.h"
#include <QPoint>
#include <QPainter>

void DrawAlgo::draw8Points(QPainter& painter,int xc,int yc,int X,int Y)
{
    painter.drawPoint(X+xc,Y+yc);
    painter.drawPoint(-X+xc,Y+yc);
    painter.drawPoint(-X+xc,-Y+yc);
    painter.drawPoint(X+xc,-Y+yc);
    painter.drawPoint(Y+xc,X+yc);
    painter.drawPoint(-Y+xc,X+yc);
    painter.drawPoint(-Y+xc,-X+yc);
    painter.drawPoint(Y+xc,-X+yc);

}

void DrawAlgo::draw4Points(QPainter& painter,int xc,int yc,int x,int y){
    painter.drawPoint(xc+x , yc+y);
    painter.drawPoint(xc-x , yc+y);
    painter.drawPoint(xc+x , yc-y);
    painter.drawPoint(xc-x , yc-y);
}
