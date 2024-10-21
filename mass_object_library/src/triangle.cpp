
/*******************************************************************
Copyright (c) University of Luxembourg 2023.
Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
********************************************************************/

#include "error.hpp"
#include "triangle.hpp"
#include <cmath>
#include <iostream>


Triangle::Triangle(double side_a, double side_b, double side_c) : a(side_a), b(side_b), c(side_c) {}


double Triangle::getSurface() const {

    if (a < 0 || b < 0 || c < 0)
    {
      set_error(1);
      return 0;
    }

    if (!(a + b > c && b + c > a && a + c > b)) {
      set_error(1);
      return 0;
    }

    double s = (a + b + c) / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    std::cout << "surface=" << area << std::endl;

    return area;
}


double Triangle::getPerimeter() const {

    if (a < 0 || b < 0 || c < 0)
    {
        set_error(1);
        return 0;
    }

    if (!(a + b > c && b + c > a && a + c > b)) {
      set_error(1);
      return 0;
    }

    double perimeter = a + b + c;
    std::cout << "perimeter=" << perimeter << std::endl;

    return perimeter;
}

