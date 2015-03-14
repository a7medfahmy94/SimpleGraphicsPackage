#ifndef CIRCLEMIDPOINT_H
#define CIRCLEMIDPOINT_H
#include "drawalgo.h"
#include <QPainter>
#include "QPoint"
#include <bits/stdc++.h>

class CircleMidPoint : public DrawAlgo
{
public:
    CircleMidPoint();
    ~CircleMidPoint();
    void draw(QPainter&,std::map<std::string,QPoint>);

};

#endif // CIRCLEMIDPOINT_H




