#include "linedda.h"

LineDDA::LineDDA()
{

}

LineDDA::~LineDDA()
{

}

void LineDDA::draw(QPainter& p,std::map<std::string,QPoint> ma){
    QPoint begin = ma["begin"];
    QPoint end = ma["end"];
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
            }
        }

    }else{
        p.drawPoint(QPoint(xb,yb));
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
            }
        }
    }
}
