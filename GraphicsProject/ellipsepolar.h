#ifndef ELLIPSEPOLRA_H
#define ELLIPSEPOLRA_H
#include "drawalgo.h"
#include <QPoint>
#include <QPainter>
#include <bits/stdc++.h>

class EllipsePolar : public DrawAlgo
{
public:
    EllipsePolar();
    ~EllipsePolar();
    void draw(QPainter&,std::map<std::string,QPoint>);

};

#endif // ELLIPSEPOLRA_H
