
/*******************************************************************
Copyright (c) University of Luxembourg 2023.
Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
********************************************************************/

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
public:
  Rectangle(double l, double w);
  double getPerimeter() const;
  double getSurface() const;
private:
  double lenght;
  double width;
};

#endif