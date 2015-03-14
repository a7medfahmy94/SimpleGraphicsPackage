#include "drawalgo.h"
#include <QPoint>
#include <QPainter>

DrawAlgo::DrawAlgo(QPainter& painter,int xc,int yc,int X,int Y)
{
    painter.draw8Point(X+xc,Y+yc);
    painter.draw8Point(-X+xc,Y+yc);
    painter.draw8Point(-X+xc,-Y+yc);
    painter.draw8Point(X+xc,-Y+yc);
    painter.draw8Point(Y+xc,X+yc);
    painter.draw8Point(-Y+xc,X+yc);
    painter.draw8Point(-Y+xc,-X+yc);
    painter.draw8Point(Y+xc,-X+yc);

}
