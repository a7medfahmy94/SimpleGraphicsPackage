#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QPaintEvent>
#include "mainwindow.h"
#include <QEvent>
#include <QMouseEvent>
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

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


bool is_set(QPoint p){
    return ! (p.x() == -1 && p.y() == -1);
}

void MainWindow::on_actionCartesian_triggered()
{
    repaint();
    ui->current_selected->setText("Line : Cartesian");

    current_shape = 0;
}


void MainWindow::on_actionInteger_DDA_triggered()
{
    repaint();
    ui->current_selected->setText("Line : Integer DDA");
    current_shape = 2;
}

void MainWindow::on_actionParametric_triggered()
{
    repaint();
    ui->current_selected->setText("Line : Parametric");
    current_shape = 1;
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
    ui->current_selected->setText("");
    setAttribute(Qt::WA_OpaquePaintEvent);
    QPainter painter(this);
    QPen linepen(Qt::black);
    linepen.setCapStyle(Qt::RoundCap);
    linepen.setWidth(4);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(linepen);

    if(is_set(start_point) && is_set(end_point)){
        switch(current_shape){
        case 0:
            Line::draw_cartesian(painter,start_point,end_point);
            break;
        case 1:
            Line::draw_integer_dda(painter,start_point,end_point);
            break;
        case 2:
            Line::draw_parametric(painter,start_point,end_point);
            break;
        }

    }else{
        painter.drawPoint(start_point);
    }
}
