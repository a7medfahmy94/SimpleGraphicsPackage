#ifndef CIRCLEPOLAR_H
#define CIRCLEPOLAR_H
#include "drawalgo.h"
#include <QPainter>
#include "QPoint"
#include <bits/stdc++.h>

class CirclePolar : public DrawAlgo
{
public:
    CirclePolar();
    ~CirclePolar();
    void draw(QPainter&,std::map<std::string,QPoint>);
};

#endif // CIRCLEPOLAR_H


