#include "circlefilled.h"
#include "linecartesian.h"
#include <bits/stdc++.h>
CircleFilled::CircleFilled()
{

}

CircleFilled::~CircleFilled()
{

}

void CircleFilled::draw(QPainter& p,std::map<std::string,QPoint> ma){
   QPoint center = ma["begin"];
   QPoint R = ma["end"];

   int r = std::sqrt(std::pow(center.x()-R.x(),2)+pow(center.y()-R.y(),2));
   int X = 0 , Y = r;

   LineCartesian* line = new LineCartesian();

   while(X < Y){
       X++;
       Y = sqrt(r*r - X*X);
       DrawAlgo::draw8Points(p,center.x(),center.y(),X,Y);
       std::map<std::string,QPoint> param;

       param["begin"] = QPoint(center.x()+X,center.y()+Y);
       param["end"] = QPoint(center.x()-X,center.y()-Y);
       line->draw(p , param);

       param["begin"] = QPoint(center.x()-X,center.y()+Y);
       param["end"] = QPoint(center.x()+X,center.y()-Y);
       line->draw(p , param);

       param["begin"] = QPoint(center.x()+Y,center.y()+X);
       param["end"] = QPoint(center.x()-Y,center.y()-X);
       line->draw(p , param);

       param["begin"] = QPoint(center.x()-Y,center.y()+X);
       param["end"] = QPoint(center.x()+Y,center.y()-X);
       line->draw(p , param);

   }

}
