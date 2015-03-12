#include "shapecontroller.h"
#include "shape.h"
#include "line.h"
#include "linecartesian.h"
#include "linedda.h"
#include "lineparametric.h"
#include "drawalgo.h"

ShapeController::ShapeController(){clear =false;}

ShapeController::ShapeController(int w,int h)
{
    file = File(w,h);
    shape = new Line();
    shape->setDrawAlgo(new LineCartesian());
    clear = false;
}

ShapeController::~ShapeController()
{

}
void ShapeController::setClear(){
    clear = true;
}

void ShapeController::changeDrawAlgo(DrawAlgo* d){
    setClear();
    shape->setDrawAlgo(d);
}

void ShapeController::changeShape(Shape * p){
    shape = p;
}

void ShapeController::draw(QPainter & p){
    if(clear){
        QPen linepen(Qt::white);
        linepen.setCapStyle(Qt::RoundCap);
        linepen.setWidth(4);
        p.setPen(linepen);
        for(int i = 0 ; i < file.getH(); i++){
            for(int j = 0 ; j < file.getW(); j++){
                p.drawPoint(QPoint(i,j));
            }
        }
        clear = false;
    }else{
        shape->draw(p);
    }
}

int ShapeController::get(int a, int b){
    return file.get(a,b);
}


void ShapeController::save(){
    file.save();
}

void ShapeController::receivePoint(QPoint p){
    shape->receivePoint(p);
}
