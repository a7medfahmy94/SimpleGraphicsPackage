#ifndef LINECARTESIAN_H
#define LINECARTESIAN_H

#include "drawalgo.h"
#include <QPainter>
#include <bits/stdc++.h>

class LineCartesian : public DrawAlgo
{
public:
    LineCartesian();
    ~LineCartesian();
    void draw(QPainter&,std::map<std::string,QPoint>);
};

#endif // LINECARTESIAN_H
