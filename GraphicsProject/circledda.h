#ifndef CIRCLEDDA_H
#define CIRCLEDDA_H
#include "drawalgo.h"
#include <bits/stdc++.h>

class CircleDDA : public DrawAlgo
{
public:
    CircleDDA();
    ~CircleDDA();
    void draw(QPainter&,std::map<std::string,QPoint>);

};

#endif // CIRCLEDDA_H

