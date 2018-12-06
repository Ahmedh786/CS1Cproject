#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include "shape.h"
#include "vector.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_contactUs_btn_clicked();

    void on_draw_btn_clicked();


private:
    Ui::MainWindow *ui;
     Shape * currentShape;
     vector<Shape*> shapeV;
};

#endif // MAINWINDOW_H
