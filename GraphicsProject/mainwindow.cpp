#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QPaintEvent>
#include <bits/stdc++.h>
#include "line.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    start_point = {-1 , -1};
    end_point = {-1 , -1};
    current_shape = 0;
    memset(pixels , -1 , sizeof pixels);
    load = false;
    ui->setupUi(this);

}


MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::is_set(QPoint& p){
    return ! (p.x() == -1 && p.y() == -1);
}

void MainWindow::on_actionCartesian_triggered()
{

    update();
    ui->current_selected->setText("Line : Cartesian");

    current_shape = 0;
}

void MainWindow::on_actionParametric_triggered()
{
    update();
    ui->current_selected->setText("Line : Parametric");
    current_shape = 1;
}

void MainWindow::on_actionInteger_DDA_triggered()
{
    update();
    ui->current_selected->setText("Line : Integer DDA");
    current_shape = 2;
}



void MainWindow::mousePressEvent(QMouseEvent *f) {

    if(is_set(start_point) && is_set(end_point)){
        start_point = f->pos();
        end_point = {-1 , -1};
    }else if(is_set(start_point)){
        end_point = f->pos();
    }else{
        start_point = f->pos();
    }
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
    if(load){
        redraw(painter);
        load = false;
        return;
    }
    if(is_set(start_point) && is_set(end_point)){
        switch(current_shape){
        case 0:
            Line::draw_cartesian(painter,start_point,end_point,pixels,400,300);
            break;
        case 1:
            Line::draw_parametric(painter,start_point,end_point,pixels,400,300);
            break;
        case 2:
            Line::draw_integer_dda(painter,start_point,end_point,pixels,400,300);
            break;
        }

    }else{
        painter.drawPoint(start_point);
        pixels[start_point.x()][start_point.y()] = painter.pen().color().value();
    }

}

void MainWindow::redraw(QPainter& painter){
    for(int i = 0 ; i < 400 ; ++i){
        for(int j = 0 ; j < 300; ++j){
            if(pixels[i][j] != -1){
                painter.drawPoint(QPoint(i,j));
            }
        }
    }

}

void MainWindow::on_pushButton_clicked()
{
    std::ofstream file("img.dat",std::ios::binary);
    file.write((char*)pixels,sizeof pixels);
    file.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    std::ifstream file("img.dat",std::ios::binary);
    file.read((char*)pixels,sizeof pixels);
    load = true;
    update();
}
