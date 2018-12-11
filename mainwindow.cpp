#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contact.h"
#include "login.h"
#include <QPainter>
#include <shape.h>
#include "ellipse.h"
#include "rectangle.h"
#include "addremove.h"
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
    shapeVector = v;
    ui->setupUi(this);

    for(int i = 0; i < shapeVector.getSize(); i++){
            QString temp(shapeVector[i]->getTextString().c_str());
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
    Outfile << endl;
    for (int i = 0; i < shapeVector.getSize(); ++i) {
        Outfile << "-Shape Id: " << shapeVector[i]->getShapeId() << endl;
        Outfile << "ShapeType: " << shapeVector[i]->getTextString() << endl;
        if (shapeVector[i]->getTextString() == "Line")
            Outfile << "ShapeDimensions: " << shapeVector[i]->getX() << ", " << shapeVector[i]->getY() << ", " << shapeVector[i]->getX2() << ", " << shapeVector[i]->getY2() << endl;
        else if (shapeVector[i]->getTextString() == "Polyline")
            Outfile << "ShapeDimensions: " <<shapeVector[i]->getX() << ", " << shapeVector[i]->getY() << ", " << shapeVector[i]->getX2() << ", " << shapeVector[i]->getY2() << ", " << shapeVector[i]->getX3() << ", " << shapeVector[i]->getY3() << ", " << shapeVector[i]->getX4() << ", " << shapeVector[i]->getY4() << endl;
        else if (shapeVector[i]->getTextString() == "Polygon")
            Outfile << "ShapeDimensions: " << shapeVector[i]->getX() << ", " << shapeVector[i]->getY() << ", " << shapeVector[i]->getX2() << ", " << shapeVector[i]->getY2() << ", " << shapeVector[i]->getX3() << ", " << shapeVector[i]->getY3() << ", " << shapeVector[i]->getX4() << ", " << shapeVector[i]->getY4() << endl;
        else if (shapeVector[i]->getTextString() == "Rectangle")
            Outfile << "ShapeDimensions: " << shapeVector[i]->getX() << ", " << shapeVector[i]->getY() << ", " << shapeVector[i]->getL() << ", " << shapeVector[i]->getW() << endl;
        else if (shapeVector[i]->getTextString() == "Square")
            Outfile << "ShapeDimensions: " << shapeVector[i]->getX() << ", " << shapeVector[i]->getY() << ", " << shapeVector[i]->getL() << endl;
        else if (shapeVector[i]->getTextString() == "Ellipse")
            Outfile << "ShapeDimensions: " << shapeVector[i]->getX() << ", " << shapeVector[i]->getY() << ", " << shapeVector[i]->getAx() << ", " << shapeVector[i]->getBx() << endl;
        else if (shapeVector[i]->getTextString() == "Circle")
            Outfile << "ShapeDimensions: " << shapeVector[i]->getX() << ", " << shapeVector[i]->getY() << ", " << shapeVector[i]->getAx() << ", " << shapeVector[i]->getBx() << endl;
        else if (shapeVector[i]->getTextString() == "Text")
            Outfile << "ShapeDimensions: " << shapeVector[i]->getX() << ", " << shapeVector[i]->getY() << ", " << shapeVector[i]->getL() << ", " << shapeVector[i]->getW() << endl;
        Outfile << "PenColor: " << shapeVector[i]->getQPenColor() << endl;
        Outfile << "PenWidth: " << shapeVector[i]->getQPenWidth() << endl;
        Outfile << "PenStyle: " << shapeVector[i]->getQPenStyle() << endl;
        Outfile << "PenCapStyle: " << shapeVector[i]->getQPenCapStyle() << endl;
        Outfile << "PenJoinStyle: " << shapeVector[i]->getQPenJoinStyle() << endl;
        Outfile << endl;
    }
    Outfile.close();

    QMessageBox savemsg;
    savemsg.setText("Your shape data has been saved.");
    savemsg.exec();
}
