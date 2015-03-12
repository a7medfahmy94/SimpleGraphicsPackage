#ifndef LINEPARAMETRIC_H
#define LINEPARAMETRIC_H
#include "drawalgo.h"
#include <bits/stdc++.h>

class LineParametric : public DrawAlgo
{
public:
    LineParametric();
    ~LineParametric();
    void draw(QPainter&,std::map<std::string,QPoint>);
};

#endif // LINEPARAMETRIC_H
