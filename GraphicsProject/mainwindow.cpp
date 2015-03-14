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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    WIDTH = 400 , HEIGHT = 300;
    shape_controller = new ShapeController(WIDTH, HEIGHT);
    ui->setupUi(this);
    shape_controller->setClear();
    update();
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionCartesian_triggered()
{
    shape_controller->changeShape(new Line());
    shape_controller->changeDrawAlgo(new LineCartesian());
    update();
}

void MainWindow::on_actionParametric_triggered()
{
    shape_controller->changeShape(new Line());
    shape_controller->changeDrawAlgo(new LineParametric());
    update();
}

void MainWindow::on_actionInteger_DDA_triggered()
{
    shape_controller->changeShape(new Line());
    shape_controller->changeDrawAlgo(new LineDDA());
    update();
}



void MainWindow::mousePressEvent(QMouseEvent *f) {

   shape_controller->receivePoint(f->pos());
   update();

}

void MainWindow::paintEvent(QPaintEvent *e) {
    setAttribute(Qt::WA_OpaquePaintEvent);
    QPainter painter(this);
    QPen linepen(Qt::black);
    linepen.setCapStyle(Qt::RoundCap);
    linepen.setWidth(4);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(linepen);

    shape_controller->draw(painter);
}

void MainWindow::redraw(QPainter& painter){
    for(int i = 0 ; i < WIDTH ; ++i){
        for(int j = 0 ; j < HEIGHT; ++j){
//            if(file.get(i,j) != -1){
//                painter.drawPoint(QPoint(i,j));
//            }
        }
    }

}



void MainWindow::on_loadButton_clicked()
{
//    file.load();
//    load = true;
    update();

}

void MainWindow::on_saveButton_clicked()
{
    shape_controller->save();
}

void MainWindow::on_actionCartesian_2_triggered()
{
    shape_controller->changeShape(new Circle());
    shape_controller->changeDrawAlgo(new CircleCartesian());
    update();
}

void MainWindow::on_actionInteger_DDA_2_triggered()
{
    shape_controller->changeShape(new Circle());
    shape_controller->changeDrawAlgo(new CircleDDA());
    update();
}

void MainWindow::on_actionPolar_triggered()
{
    shape_controller->changeShape(new Circle());
    shape_controller->changeDrawAlgo(new CirclePolar());
    update();
}

void MainWindow::on_actionMidPoint_triggered()
{
    shape_controller->changeShape(new Circle());
    shape_controller->changeDrawAlgo(new CircleMidPoint());
    update();
}
