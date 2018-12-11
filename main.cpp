/********************************************************************************
*	Filename: main.cpp                                              			*
*	Project name: 2D Shape Render                                           	*
*-------------------------------------------------------------------------------*
*	Creator name's and email's:                                                 *
*       -mybanez0@saddleback.edu                                                *
*       -
*       -
*       -
*       -
*       -
*       -
*	Course-Section: CS 1C                                                       *
*	Creation Date: XX/XX/XX                                                     *
*	Date of Last Modification: XX/XX/XX                                         *
*-------------------------------------------------------------------------------*
*	Description: The modeler will demonstrate the capabilities of 2D Graphics   *
*       Modeler Inc.’s graphics engine. Potential customers will be looking for *
*       a 2D graphics rendering library which can be integrated into their own  *
*       software suite.                                                         *
*-------------------------------------------------------------------------------*
*	Algorithm:								*
*		1)								*
*-------------------------------------------------------------------------------*
*				Data Dictionary                                                 *
*	#Constants                                                                  *
*                                                                               *
*	Name            Data Type       Value                                       *
*	-----------     -----------     --------------------                        *
*										*
*										*
*	#Variables                                                                  *
*                                                                               *
*	Name            Data Type       Value                                       *
*	------------	------------	--------------------                        *
*										*
********************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
//#include <algorithm>
#include "stdlib.h"
#include <QDebug>
#include <QString>

#include "mainwindow.h"

#include "shape.h"
#include "circle.h"
#include "square.h"
#include "ellipse.h"
#include "line.h"
#include "polygon.h"
#include "polyline.h"
#include "rectangle.h"
#include "shape.h"
#include "text.h"

#include "data.h"
#include <QApplication>
#include "drawwt.h"

void parse();

int main(int argc, char *argv[])
{
    parse();

    QApplication a(argc, argv);
    MainWindow w(data::shapeVector);
    w.show();


    return a.exec();
}

void parse()
    {
        string file = "/home/cs1c/fall2018/gitstuff5/CS1Cproject/CS1Cofficial/shapes.txt";
        string Data= "";
        string shapeType = "";
        int num = 0;
        int d = 0;
        string o = "";

        std::ifstream shapesFile;
        //change to current shape.
        shapesFile.open(file);
        if(shapesFile.fail())
            qDebug() << "fail";

        Shape* elem;

        while(!shapesFile.eof())
        {

            //look for new shape
          getline(shapesFile,Data, '-');
          //skip to ID
          getline(shapesFile, Data, ' ');

          //Get ID of the shape
          getline(shapesFile, o , '\r');

          //store shape
          d = stoi(o);

          //get to shape type
          getline(shapesFile, Data, ' ');
          //Get shape type
          getline(shapesFile, Data, '\r');
          //store shapeType

          shapeType = Data;



          if(shapeType == "Line")
          {

              int x1 = 0;
              int x2 = 0;
              int y1 = 0;
              int y2 = 0;
              elem = new Line;
              // set id
              elem->setID(d);
                elem->setShapeType(shapeType);

              //set dimmentsion
               getline(shapesFile, Data, ' ');

               getline(shapesFile, Data, ',');
               x1 = stoi(Data);

               getline(shapesFile, Data, ',');
               y1 = stoi(Data);
               getline(shapesFile, Data, ',');
               x2 = stoi(Data);
               getline(shapesFile, Data, '\r');
               y2 = stoi(Data);

               qDebug() << "--LINE--";

               elem->setCord(x1,y1,x2,y2);
               getline(shapesFile, Data, ' ');
               getline(shapesFile, Data, '\r');
               elem->setColor(Data);
               //get and set pen width
               getline(shapesFile, Data, ' ');
               getline(shapesFile, Data , '\r');
               d = stoi(Data);
               elem->setWidth(d);
               //get and set penstyle
               getline(shapesFile, Data, ' ');
               getline(shapesFile, Data , '\r');
               elem->setPenStyle(Data);
               //get and set pen cap style
               getline(shapesFile, Data, ' ');
               getline(shapesFile, Data , '\r');
               elem->setCapStyle(Data);
               //get and set pen join style
               getline(shapesFile, Data, ' ');
               getline(shapesFile, Data , '\r');
               elem->setJoinStyle(Data);

               data::shapeVector.push_back(elem);
}
          else if(shapeType == "Ellipse")
          {
              {
                        int x = 0;
                        int y = 0;
                        int a = 0;
                        int b = 0;
                        elem = new Ellipse;

                        elem->setShapeType(shapeType);

                        // set id
                        elem->setID(d);
                         //set dimmensions
                         getline(shapesFile, Data, ' ');
                         getline(shapesFile, Data, ',');
                         x = stoi(Data);
                         getline(shapesFile, Data, ',');
                         y = stoi(Data);
                         getline(shapesFile, Data, ',');
                         a= stoi(Data);
                         getline(shapesFile, Data, '\r');
                         b = stoi(Data);

                         elem->setCord(x,y,a,b);
                         getline(shapesFile, Data, ' ');
                         getline(shapesFile, Data, '\r');
                         elem->setColor(Data);
                         //get and set pen width
                         getline(shapesFile, Data, ' ');
                         getline(shapesFile, Data , '\r');
                         d = stoi(Data);
                         elem->setWidth(d);
                         //get and set penstyle
                         getline(shapesFile, Data, ' ');
                         getline(shapesFile, Data , '\r');
                         elem->setPenStyle(Data);
                         //get and set pen cap style
                         getline(shapesFile, Data, ' ');
                         getline(shapesFile, Data , '\r');
                         elem->setCapStyle(Data);
                         //get and set pen join style
                         getline(shapesFile, Data, ' ');
                         getline(shapesFile, Data , '\r');
                         elem->setJoinStyle(Data);
                         //get and set burshColor;
                         getline(shapesFile, Data, ' ');
                         getline(shapesFile, Data , '\r');

                         elem->setBrushColor(Data);
                         //get and set brush style;
                         getline(shapesFile, Data, ' ');
                         getline(shapesFile, Data , '\r');

                         elem->setBrushStyle(Data);

                         data::shapeVector.push_back(elem);
              }
          }
          else if(shapeType == "Circle")
          {

                        int x = 0;
                        int y = 0;
                        int a = 0;
                        int b = 0;
                        elem = new Circle;

                        elem->setShapeType(shapeType);

                        // set id
                        elem->setID(d);
                         //set dimmensions
                         getline(shapesFile, Data, ' ');
                         getline(shapesFile, Data, ',');
                         x = stoi(Data);
                         getline(shapesFile, Data, ',');
                         y = stoi(Data);
                         getline(shapesFile, Data, '\r');
                         a = stoi(Data);

                         elem->setCord(x,y,a,b);
                         getline(shapesFile, Data, ' ');
                         getline(shapesFile, Data, '\r');

                         elem->setColor(Data);
                         //get and set pen width
                         getline(shapesFile, Data, ' ');
                         getline(shapesFile, Data , '\r');
                         d = stoi(Data);
                         elem->setWidth(d);
                         //get and set penstyle
                         getline(shapesFile, Data, ' ');
                         getline(shapesFile, Data , '\r');
                         elem->setPenStyle(Data);
                         //get and set pen cap style
                         getline(shapesFile, Data, ' ');
                         getline(shapesFile, Data , '\r');
                         elem->setCapStyle(Data);
                         //get and set pen join style
                         getline(shapesFile, Data, ' ');
                         getline(shapesFile, Data , '\r');
                         elem->setJoinStyle(Data);
                         //get and set burshColor;
                         getline(shapesFile, Data, ' ');
                         getline(shapesFile, Data , '\r');
                         elem->setBrushColor(Data);
                         //get and set brush style;
                         getline(shapesFile, Data, ' ');
                         getline(shapesFile, Data , '\r');

                         elem->setBrushStyle(Data);

                         data::shapeVector.push_back(elem);
          }
          else if(shapeType == "Square")
          {
                    int x = 0;
                    int y = 0;
                    int l = 0;
                    int w = 0;
                    elem = new Square;

                    elem->setShapeType(shapeType);

                    // set id
                    elem->setID(d);
                     //set dimmensions
                     getline(shapesFile, Data, ' ');
                     getline(shapesFile, Data, ',');
                     x = stoi(Data);
                     getline(shapesFile, Data, ',');
                     y = stoi(Data);
                     getline(shapesFile, Data, '\r');
                     l = stoi(Data);

                     elem->setCord(x,y,l,w);
                     getline(shapesFile, Data, ' ');
                     getline(shapesFile, Data, '\r');
                     elem->setColor(Data);
                     //get and set pen width
                     getline(shapesFile, Data, ' ');
                     getline(shapesFile, Data , '\r');
                     d = stoi(Data);
                     elem->setWidth(d);
                     //get and set penstyle
                     getline(shapesFile, Data, ' ');
                     getline(shapesFile, Data , '\r');
                     elem->setPenStyle(Data);
                     //get and set pen cap style
                     getline(shapesFile, Data, ' ');
                     getline(shapesFile, Data , '\r');
                     elem->setCapStyle(Data);
                     //get and set pen join style
                     getline(shapesFile, Data, ' ');
                     getline(shapesFile, Data , '\r');
                     elem->setJoinStyle(Data);
                     //get and set burshColor;
                     getline(shapesFile, Data, ' ');
                     getline(shapesFile, Data , '\r');
                     elem->setBrushColor(Data);
                     //get and set brush style;
                     getline(shapesFile, Data, ' ');
                     getline(shapesFile, Data , '\r');
                     elem->setBrushStyle(Data);

                     data::shapeVector.push_back(elem);
          }
          else if(shapeType == "Text")
          {
                    int x = 0;
                    int y = 0;
                    int l = 0;
                    int w = 0;
                    elem = new Text;

                    elem->setShapeType(shapeType);

                    // set id
                    elem->setID(d);
                     //set dimmensions
                     getline(shapesFile, Data, ' ');
                     getline(shapesFile, Data, ',');
                     x = stoi(Data);
                     getline(shapesFile, Data, ',');
                     y = stoi(Data);
                     getline(shapesFile, Data, ',');
                     l = stoi(Data);
                     getline(shapesFile, Data, '\r');
                     w = stoi(Data);

                     elem->setCord(x,y,l,w);
                     getline(shapesFile, Data, ' ');
                     getline(shapesFile, Data, '\r');
                     elem->setText(Data);
                     //Set penColor
                     getline(shapesFile, Data, ' ');
                     getline(shapesFile, Data, '\r');
                     elem->setColor(Data);
                     //Set Allignment
                     getline(shapesFile, Data, ' ');
                     getline(shapesFile, Data, '\r');
                     elem->setAlignment(Data);
                     //set text size
                     getline(shapesFile, Data, ' ');
                     getline(shapesFile, Data, '\r');
                     x = stoi(Data);
                     elem->setPointSize(x);
                     getline(shapesFile, Data, ' ');
                     getline(shapesFile, Data, '\r');
                     elem->setFamily(Data);
                     getline(shapesFile, Data, ' ');
                     getline(shapesFile, Data, '\r');


//qDebug() << QString::fromStdString(Data);

                     data::shapeVector.push_back(elem);
          }
    else if(shapeType == "Rectangle")
    {
              int x = 0;
              int y = 0;
              int l = 0;
              int w = 0;
              elem = new Rectangle;

              elem->setShapeType(shapeType);

              // set id
              elem->setID(d);
               //set dimmensions
               getline(shapesFile, Data, ' ');
               getline(shapesFile, Data, ',');
               x = stoi(Data);
               getline(shapesFile, Data, ',');
               y = stoi(Data);
               getline(shapesFile, Data, ',');
               l = stoi(Data);
               getline(shapesFile, Data, '\r');
               w = stoi(Data);

               elem->setCord(x,y,l,w);
               getline(shapesFile, Data, ' ');
               getline(shapesFile, Data, '\r');
               elem->setColor(Data);
               //get and set pen width
               getline(shapesFile, Data, ' ');
               getline(shapesFile, Data , '\r');
               d = stoi(Data);
               elem->setWidth(d);
               //get and set penstyle
               getline(shapesFile, Data, ' ');
               getline(shapesFile, Data , '\r');
               elem->setPenStyle(Data);
               //get and set pen cap style
               getline(shapesFile, Data, ' ');
               getline(shapesFile, Data , '\r');
               elem->setCapStyle(Data);
               //get and set pen join style
               getline(shapesFile, Data, ' ');
               getline(shapesFile, Data , '\r');
               elem->setJoinStyle(Data);
               //get and set burshColor;
               getline(shapesFile, Data, ' ');
               getline(shapesFile, Data , '\r');
               elem->setBrushColor(Data);
               //get and set brush style;
               getline(shapesFile, Data, ' ');
               getline(shapesFile, Data , '\r');
               elem->setBrushStyle(Data);

                data::shapeVector.push_back(elem);
            }
          num++;
        }//End of while loop
      //  QString b =Data;
      //  qDebug() << QString::fromStdString(Data);

    }
