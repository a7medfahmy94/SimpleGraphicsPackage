#include "shape.h"
#include <QPoint>

Shape::Shape()
{
    pOne = {-1,-1};
    pTwo = {-1,-1};
}

Shape::~Shape()
{

}

Shape::Shape(QPoint a,QPoint b){
    pOne = a;
    pTwo = b;
}

QPoint Shape::getOne(){
    return pOne;
}

QPoint Shape::getTwo(){
    return pTwo;
}

void Shape::setOne(QPoint a){
    pOne = a;
}

void Shape::setTwo(QPoint a){
    pTwo = a;
}
