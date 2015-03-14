#ifndef SHAPECONTROLLER_H
#define SHAPECONTROLLER_H

#include "file.h"
#include "shape.h"
#include <QImage>

class ShapeController
{
public:
    ShapeController();
    ShapeController(int,int,QImage*);
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
    File* file;
    Shape* shape;
    bool clear;
    bool file_load;
    QImage* img;
};

#endif // SHAPECONTROLLER_H
