#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <QPoint>
#include <QPainter>
#include "shape.h"

class Ellipse : public Shape
{
public:
    Ellipse();
    ~Ellipse();

    virtual void setDrawAlgo(DrawAlgo*);
    virtual void receivePoint(QPoint);
    virtual void draw(QPainter&);
private:
    DrawAlgo* drawAlgo;
    QPoint center;
};

#endif // ELLIPSE_H
