
/*******************************************************************
Copyright (c) University of Luxembourg 2023.
Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
********************************************************************/

#ifndef TRIANGLE_H
#define TRIANGLE_H


class Triangle {
public:
  Triangle(double side_a, double side_b, double side_c);
  double getPerimeter() const;
  double getSurface() const;
private:
  double a;
  double b;
  double c;
};



#endif