#ifndef SHAPECONTROLLER_H
#define SHAPECONTROLLER_H

#include "file.h"
#include "shape.h"

class ShapeController
{
public:
    ShapeController();
    ShapeController(int,int);
    ~ShapeController();

    void changeShape(Shape*);
    void draw(QPainter&);
    void save();
    void load();
    int get(int,int);
    void receivePoint(QPoint);
    void changeDrawAlgo(DrawAlgo*);
    void setClear();
private:
    File file;
    Shape* shape;
    bool clear;
};

#endif // SHAPECONTROLLER_H
