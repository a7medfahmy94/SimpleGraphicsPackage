#ifndef DRAWALGO_H
#define DRAWALGO_H

#include <QPainter>
#include <QPoint>
#include <map>
#include <string>
#include <bits/stdc++.h>

class DrawAlgo
{
public:
    virtual void draw(QPainter&,std::map<std::string,QPoint>) = 0;

    static void draw8Points(QPainter&,int ,int ,int ,int );
    static void draw4Points(QPainter&,int ,int ,int ,int );
};

#endif // DRAWALGO_H
