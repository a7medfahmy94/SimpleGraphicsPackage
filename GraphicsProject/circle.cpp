#include "circle.h"
#include <iostream>
#include "file.h"
#include "helper.h"
#include <bits/stdc++.h>
#include "shape.h"

Circle::Circle():Shape()
{
    pOne = {-1,-1};
    pTwo = {-1,-1};
}


Circle::Circle(QPoint a , QPoint b){
    pOne = a;
    pTwo = b;
}

Circle::~Circle()
{

}

void Circle::draw(QPainter& p){
    if(Helper::is_set(pOne) && Helper::is_set(pTwo)){
        std::map<std::string,QPoint> m;
        m["begin"] = pOne;
        m["end"] = pTwo;
        drawAlgo->draw(p,m);
    }
}

void Circle::setDrawAlgo(DrawAlgo* algo){
    drawAlgo = algo;
}

void Circle::receivePoint(QPoint p){
    if(!Helper::is_set(pOne)){
        pOne = p;
    }else if(!Helper::is_set(pTwo)){
        pTwo = p;
    }else{
        pOne = p;
        pTwo = {-1,-1};
    }
}

