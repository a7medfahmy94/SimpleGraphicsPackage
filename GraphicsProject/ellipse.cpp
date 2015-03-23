#include "ellipse.h"
#include "helper.h"
#include "drawalgo.h"
#include <bits/stdc++.h>
#include <QPoint>
Ellipse::Ellipse()
{
    center = {-1,-1};
}

Ellipse::~Ellipse()
{

}



void Ellipse::setDrawAlgo(DrawAlgo* d){
    drawAlgo = d;
}

void Ellipse::receivePoint(QPoint p){
    if(!Helper::is_set(center)){
        center = p;
    }else if(!Helper::is_set(pOne)){
        pOne = p;
    }else if(!Helper::is_set(pTwo)){
        pTwo = p;
    }else{
        pOne = pTwo = {-1,-1};
        center = p;
    }
}

void Ellipse::draw(QPainter& painter){
    if(Helper::is_set(center) && Helper::is_set(pOne) && Helper::is_set(pTwo)){
        std::map<std::string,QPoint> ma;
        ma["center"] = center;
        ma["a"] = pOne;
        ma["b"] = pTwo;
        drawAlgo->draw(painter , ma);
    }
}
