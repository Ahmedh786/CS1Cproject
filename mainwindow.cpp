#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contact.h"
#include "login.h"
#include <QPainter>
#include <shape.h>
#include "ellipse.h"
#include "rectangle.h"
#include "addremove.h"
#include "data.h"
#include <fstream>
#include <QtWidgets>
#include "drawwt.h"
#include <QMessageBox>
#include "vector.h"

MainWindow::MainWindow(vectorType<Shape*> v, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    drawWt *n = new drawWt;
    vec = v;
    ui->setupUi(this);

    for(int i = 0; i < data::shapeVector.getSize(); i++){
            QString temp(data::shapeVector[i]->getTextString().c_str());
        ui->availableShapesList->addItem(temp);

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_contactUs_btn_clicked()
{
    contact *c = new contact();
    c->show();
}

void MainWindow::on_draw_btn_clicked()
{

    int selectedShape = ui->availableShapesList->currentRow();  //returns int for the value that user selects
                                                                //once button is clicked... int passes to draw


/*
 * Populate array before this point
 * Confirm order with the vector
 *
 *
    shapeV.parse();
    currentShape = shapeV.getShapeV(7);
    drawWt * draw = new drawWt;
    draw->setShape(currentShape);
    draw->show();
*/
}

void MainWindow::on_login_btn_clicked()
{

    logIn *l = new logIn;
    l->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    addRemove* add = new addRemove;
    add->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    ofstream Outfile;
    Outfile.open("/home/cs1c/fall2018/gitstuff5/CS1Cproject/CS1Cofficial/save.txt");
    for (int i = 0; i < 5/*vec.getSize()*/; ++i) {
        Outfile << "-Shape Id: " << vec[i]->getShapeId() << endl;
        //Outfile << "ShapeType: " << vec[i]->getTextString() << endl;
        /*if (data::shapeVector[i]->getTextString() == "Line")
            Outfile << "ShapeDimensions: " << data::shapeVector[i]->getX() << ", " << data::shapeVector[i]->getY() << ", " << data::shapeVector[i]->getX2() << ", " << data::shapeVector[i]->getY2() << endl;
        else if (data::shapeVector[i]->getTextString() == "Polyline")
            Outfile << "ShapeDimensions: " <<data::shapeVector[i]->getX() << ", " << data::shapeVector[i]->getY() << ", " << data::shapeVector[i]->getX2() << ", " << data::shapeVector[i]->getY2() << ", " << data::shapeVector[i]->getX3() << ", " << data::shapeVector[i]->getY3() << ", " << data::shapeVector[i]->getX4() << ", " << data::shapeVector[i]->getY4() << endl;
        else if (data::shapeVector[i]->getTextString() == "Polygon")
            Outfile << "ShapeDimensions: " << data::shapeVector[i]->getX() << ", " << data::shapeVector[i]->getY() << ", " << data::shapeVector[i]->getX2() << ", " << data::shapeVector[i]->getY2() << ", " << data::shapeVector[i]->getX3() << ", " << data::shapeVector[i]->getY3() << ", " << data::shapeVector[i]->getX4() << ", " << data::shapeVector[i]->getY4() << endl;
        else if (data::shapeVector[i]->getTextString() == "Rectangle")
            Outfile << "ShapeDimensions: " << data::shapeVector[i]->getX() << ", " << data::shapeVector[i]->getY() << ", " << data::shapeVector[i]->getL() << ", " << data::shapeVector[i]->getW() << endl;
        else if (data::shapeVector[i]->getTextString() == "Square")
            Outfile << "ShapeDimensions: " << data::shapeVector[i]->getX() << ", " << data::shapeVector[i]->getY() << ", " << data::shapeVector[i]->getL() << endl;
        else if (data::shapeVector[i]->getTextString() == "Ellipse")
            Outfile << "ShapeDimensions: " << data::shapeVector[i]->getX() << ", " << data::shapeVector[i]->getY() << ", " << data::shapeVector[i]->getAx() << ", " << data::shapeVector[i]->getBx() << endl;
        else if (data::shapeVector[i]->getTextString() == "Circle")
            Outfile << "ShapeDimensions: " << data::shapeVector[i]->getX() << ", " << data::shapeVector[i]->getY() << ", " << data::shapeVector[i]->getAx() << ", " << data::shapeVector[i]->getBx() << endl;
        else if (data::shapeVector[i]->getTextString() == "Text")
            Outfile << "ShapeDimensions: " << data::shapeVector[i]->getX() << ", " << data::shapeVector[i]->getY() << ", " << data::shapeVector[i]->getL() << ", " << data::shapeVector[i]->getW() << endl;
        *//*Outfile << "PenColor: " << vec[i]->getQPenColor() << endl;
        Outfile << "PenWidth: " << vec[i]->getQPenWidth() << endl;
        Outfile << "PenStyle: " << vec[i]->getQPenStyle() << endl;
        Outfile << "PenCapStyle: " << vec[i]->getQPenCapStyle() << endl;
        Outfile << "PenJoinStyle: " << vec[i]->getQPenJoinStyle() << endl;
        */Outfile << endl;
    }
    Outfile.close();

    QMessageBox savemsg;
    savemsg.setText("Your shape data has been saved.");
    savemsg.exec();
}
