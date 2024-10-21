
/*******************************************************************
Copyright (c) University of Luxembourg 2023.
Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
********************************************************************/

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
public:
    Circle(double r);
    double getPerimeter() const;
    double getSurface() const;
private:
    double radius;
};

#endif