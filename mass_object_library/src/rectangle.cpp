
/*******************************************************************
Copyright (c) University of Luxembourg 2023.
Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
********************************************************************/

#include "error.hpp"
#include "rectangle.hpp"
#include <iostream>


Rectangle::Rectangle(double l, double w) : lenght(l), width(w) {}


double Rectangle::getSurface() const
{
    if (lenght < 0 || width < 0)
    {
        set_error(1);
        return 0;
    }

    double surface = lenght * width;
    std::cout << "surface=" << surface << std::endl;
    return surface;
}

double Rectangle::getPerimeter() const
{
    if (lenght < 0 || width < 0)
    {
        set_error(1);
        return 0;
    }

    double perimeter = lenght * 2 + width * 2;
    std::cout << "perimeter=" << perimeter << std::endl;
    return perimeter;
}
