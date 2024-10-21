
/*******************************************************************
Copyright (c) University of Luxembourg 2023.
Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
********************************************************************/

#include "error.hpp"
#include "circle.hpp"
#include <iostream>

#define APPROXIMATE_PI 3.14


Circle::Circle(double r) : radius(r) {}

double Circle::getSurface() const
{
    if (radius < 0)
    {
        set_error(1);
        return 0;
    }

    double surface = radius * radius * APPROXIMATE_PI;
    std::cout << "surface=" << surface << std::endl;
    return surface;
}

double Circle::getPerimeter() const
{
    if (radius < 0)
    {
        set_error(1);
        return 0;
    }

    double perimeter = radius * 2 * APPROXIMATE_PI;
    std::cout << "perimeter=" << perimeter << std::endl;
    return perimeter;
}
