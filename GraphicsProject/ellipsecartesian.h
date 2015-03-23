#ifndef ELLIPSECARTESIAN_H
#define ELLIPSECARTESIAN_H
#include "drawalgo.h"
#include <QPainter>
#include <QPoint>
#include <bits/stdc++.h>

class EllipseCartesian : public DrawAlgo
{
public:
    EllipseCartesian();
    ~EllipseCartesian();
    virtual void draw(QPainter&,std::map<std::string,QPoint>);

};

#endif // ELLIPSECARTESIAN_H
