#include "shapecontroller.h"
#include "shape.h"
#include "line.h"
#include "circle.h"
#include "linecartesian.h"
#include "circlecartesian.h"
#include "circledda.h"
#include "circlepolar.h"
#include "circlemidpoint.h"
#include "linedda.h"
#include "lineparametric.h"
#include "drawalgo.h"

ShapeController::ShapeController(){clear =false;}

ShapeController::ShapeController(int w,int h,QImage* im)
{
    file = new File(w,h);
    shape = new Line();
    shape->setDrawAlgo(new LineCartesian());
    clear = false;
    file_load = false;
    img = im;
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
    setClear();
    shape = p;
}

void ShapeController::draw(QPainter & p){
    if(clear){
        img->fill(Qt::white);
        file->clear();
        clear = false;
    }else if(file_load){
        for(int i = 0 ; i < file->getH(); i++){
            for(int j = 0 ; j < file->getW(); j++){
                if(file->get(i,j) != 0){
                 p.drawPoint(i,j);
                }
            }
        }
        file_load = false;
    }else{
        shape->draw(p);
    }
}

int ShapeController::get(int a, int b){
    return file->get(a,b);
}


void ShapeController::save(){
    for(int i = 0 ; i < img->width(); i++){
        for(int j = 0 ; j < img->height(); j++){
            if(img->pixel(i,j) != qRgb(255,255,255)){
                file->set(i,j);
            }
        }
    }
    file->save();
}

void ShapeController::load(){
    file->load();
    file_load = true;
}

void ShapeController::receivePoint(QPoint p){
    shape->receivePoint(p);
}
