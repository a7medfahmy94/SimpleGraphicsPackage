#ifndef CIRCLECARTESIAN_H
#define CIRCLECARTESIAN_H

#include "drawalgo.h"
#include <QPainter>
#include "QPoint"
#include <bits/stdc++.h>

class CircleCartesian : public DrawAlgo
{
public:
    CircleCartesian();
    ~CircleCartesian();
    void draw(QPainter&,std::map<std::string,QPoint>);
};

#endif // CIRCLECARTESIAN_H


