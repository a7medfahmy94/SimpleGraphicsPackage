#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qpainter.h>
#include <qpen.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void redraw(QPainter&);

    void on_actionCartesian_triggered();

    void on_actionParametric_triggered();

    void on_actionInteger_DDA_triggered();

    void on_pushButton_clicked();


    void on_pushButton_2_clicked();


public :
    QPoint start_point, end_point;
    int current_shape;
private:
    Ui::MainWindow *ui;
    bool is_set(QPoint& p);
    int pixels[400][300];
    bool load;

protected:
    void mousePressEvent(QMouseEvent *f);
public:
    void paintEvent(QPaintEvent *e);

};

#endif // MAINWINDOW_H
