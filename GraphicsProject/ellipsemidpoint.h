#ifndef ELLIPSEMIDPOINT_H
#define ELLIPSEMIDPOINT_H

#include <bits/stdc++.h>
#include <QPoint>
#include <QPainter>
#include "drawalgo.h"

class EllipseMidpoint : public DrawAlgo
{
public:
    EllipseMidpoint();
    ~EllipseMidpoint();
    void draw(QPainter&,std::map<std::string,QPoint>);

};

#endif // ELLIPSEMIDPOINT_H
