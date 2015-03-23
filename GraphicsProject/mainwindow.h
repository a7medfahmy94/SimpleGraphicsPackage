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
    QImage* img;
private slots:

    void on_circleCartesian_triggered();

    void on_circleDDA_triggered();

    void on_circlePolar_triggered();

    void on_circleMidPoint_triggered();

    void on_lineCartesian_triggered();

    void on_lineParametric_triggered();

    void on_lineInteger_DDA_triggered();

    void on_save_triggered();

    void on_load_triggered();

    void on_circleFilled_triggered();

    void on_ellipseCartesian_triggered();

    void on_ellipsePolar_triggered();

private:
    Ui::MainWindow *ui;

protected:
    void mousePressEvent(QMouseEvent *f);

};

#endif // MAINWINDOW_H
