
/*******************************************************************
Copyright (c) University of Luxembourg 2023.
Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
********************************************************************/

#ifndef SQUARE_H
#define SQUARE_H


class Square {
public:
  Square(double s);
  double getPerimeter() const;
  double getSurface() const;
private:
  double side;
};


#endif