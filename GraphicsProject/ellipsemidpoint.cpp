#include "ellipsemidpoint.h"
#include <QPainter>
#include <QPoint>
#include <bits/stdc++.h>
#include "drawalgo.h"
#include "helper.h"

EllipseMidpoint::EllipseMidpoint()
{

}

EllipseMidpoint::~EllipseMidpoint()
{

}



void EllipseMidpoint::draw(QPainter & painter, std::map<std::string, QPoint> ma){
    QPoint center = ma["center"];
    QPoint a = ma["a"];
    QPoint b = ma["b"];

    int A = a.x() - center.x();
    int B = center.y() - b.y();
    int X = 0 , Y = B;
    int A2 = A*A;
    int B2 = B*B;
    int initial = 4*B2 + A2 - 4*A2*B;

    DrawAlgo::draw4Points(painter , center.x() , center.y() , X , Y);
    while(X*B2 <= Y*A2){
        X++;
        if(initial < 0){
            initial += 4*B2*(1+2*X);
        }else{
            initial += 4*(B2*(1+2*X) + 2*A2*(1 - Y));
            Y--;
        }
        DrawAlgo::draw4Points(painter , center.x() , center.y() , X , Y);
    }


    while(Y > 0){
        Y--;
        if(initial < 0){
            initial += 4*A2*(1-2*Y) + 4*2*B2*(1+X);
        }else{
            initial += 4*A2*(1-2*Y);
            X++;
        }
        DrawAlgo::draw4Points(painter , center.x() , center.y() , X , Y);

    }

//    X = A , Y = 0;
//    initial = 4*B2 - 8*A*B2 + A2;
////    initial = 4*A2 - 4*B2*A + B2;

//    DrawAlgo::draw4Points(painter , center.x() , center.y() , X , Y);
//    while(X*B2 > Y*A2){
//        Y++;
//        if(initial < 0){
//            initial += 4*(B2 - 2*X*B2 + 2*A2 + 2*Y*A2);
////            initial += 4*A2*(2*Y + 1);
//        }else{
//            initial += 4*B2 * (1-2*X);
////            initial += 4*A2*(2*Y + 1) - 8*A2*(X-1);
//            X--;
//        }
//        DrawAlgo::draw4Points(painter , center.x() , center.y() , X , Y);
//    }
}
