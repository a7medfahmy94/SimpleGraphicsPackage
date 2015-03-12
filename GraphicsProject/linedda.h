#ifndef LINEDDA_H
#define LINEDDA_H
#include "drawalgo.h"
#include <bits/stdc++.h>

class LineDDA : public DrawAlgo
{
public:
    LineDDA();
    ~LineDDA();
    void draw(QPainter&,std::map<std::string,QPoint>);

};

#endif // LINEDDA_H
