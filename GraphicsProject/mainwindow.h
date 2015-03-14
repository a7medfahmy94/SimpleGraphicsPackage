#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qpainter.h>
#include <qpen.h>
#include "shapecontroller.h"
#include "shape.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *e);

public :
    int WIDTH , HEIGHT;
    ShapeController *shape_controller;

private slots:
    void redraw(QPainter&);
    void on_actionCartesian_triggered();
    void on_actionParametric_triggered();
    void on_actionInteger_DDA_triggered();
    void on_loadButton_clicked();

    void on_saveButton_clicked();

    void on_actionCartesian_2_triggered();

    void on_actionInteger_DDA_2_triggered();

    void on_actionPolar_triggered();

private:
    Ui::MainWindow *ui;

protected:
    void mousePressEvent(QMouseEvent *f);

};

#endif // MAINWINDOW_H
