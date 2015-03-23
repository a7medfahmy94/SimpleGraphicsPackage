#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QPaintEvent>
#include <bits/stdc++.h>
#include "line.h"
#include "linecartesian.h"
#include "linedda.h"
#include "lineparametric.h"
#include "circle.h"
#include "circlecartesian.h"
#include "circledda.h"
#include "circlepolar.h"
#include "circlemidpoint.h"
#include "circlefilled.h"
#include "ellipse.h"
#include "ellipsecartesian.h"
#include "ellipsepolar.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    WIDTH = 400 , HEIGHT = 700;
    img = new QImage(HEIGHT, WIDTH , QImage::Format_ARGB32);
    img->fill(Qt::white);

    shape_controller = new ShapeController(HEIGHT, WIDTH,img);
    ui->setupUi(this);
    shape_controller->setClear();
    update();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::mousePressEvent(QMouseEvent *f) {

   shape_controller->receivePoint(f->pos());
   update();

}

void MainWindow::paintEvent(QPaintEvent *e) {
//painter to paint on screen
    setAttribute(Qt::WA_OpaquePaintEvent);
    QPainter painter(this);
    QPen linepen(Qt::black);
    linepen.setCapStyle(Qt::RoundCap);
    linepen.setWidth(1);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(linepen);

//painter to paint on QImage
    QPainter pimg (img);
    QPen plinepen(Qt::black);
    plinepen.setCapStyle(Qt::RoundCap);
    plinepen.setWidth(1);
    pimg.setRenderHint(QPainter::Antialiasing, true);
    pimg.setPen(plinepen);

    //draw on image
    shape_controller->draw(pimg);
    //draw image on screen
    painter.drawImage(0,0,*img);


}



void MainWindow::on_circleCartesian_triggered()
{
    shape_controller->changeShape(new Circle());
    shape_controller->changeDrawAlgo(new CircleCartesian());
    update();
}

void MainWindow::on_circleDDA_triggered()
{
    shape_controller->changeShape(new Circle());
    shape_controller->changeDrawAlgo(new CircleDDA());
    update();
}

void MainWindow::on_circlePolar_triggered()
{
    shape_controller->changeShape(new Circle());
    shape_controller->changeDrawAlgo(new CirclePolar());
    update();
}

void MainWindow::on_circleMidPoint_triggered()
{
    shape_controller->changeShape(new Circle());
    shape_controller->changeDrawAlgo(new CircleMidPoint());
    update();
}
void MainWindow::on_circleFilled_triggered()
{
    shape_controller->changeShape(new Circle());
    shape_controller->changeDrawAlgo(new CircleFilled());
    update();
}

void MainWindow::on_lineCartesian_triggered()
{
    shape_controller->changeShape(new Line());
    shape_controller->changeDrawAlgo(new LineCartesian());
    update();
}

void MainWindow::on_lineParametric_triggered()
{
    shape_controller->changeShape(new Line());
    shape_controller->changeDrawAlgo(new LineParametric());
    update();
}

void MainWindow::on_lineInteger_DDA_triggered()
{
    shape_controller->changeShape(new Line());
    shape_controller->changeDrawAlgo(new LineDDA());
    update();
}

void MainWindow::on_save_triggered()
{
    shape_controller->save();
}

void MainWindow::on_load_triggered()
{
    shape_controller->load();
    update();
}


void MainWindow::on_ellipseCartesian_triggered()
{
    shape_controller->changeShape(new Ellipse());
    shape_controller->changeDrawAlgo(new EllipseCartesian());
}

void MainWindow::on_ellipsePolar_triggered()
{
    shape_controller->changeShape(new Ellipse());
    shape_controller->changeDrawAlgo(new EllipsePolar());

}

void MainWindow::on_ClearButton_clicked()
{
    shape_controller->setClear();
}
