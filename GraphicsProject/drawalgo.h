#ifndef DRAWALGO_H
#define DRAWALGO_H

#include <QPainter>
#include <map>
#include <string>
#include <bits/stdc++.h>

class DrawAlgo
{
public:
    virtual void draw(QPainter&,std::map<std::string,QPoint>) = 0;
};

#endif // DRAWALGO_H
