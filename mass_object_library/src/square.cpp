
/*******************************************************************
Copyright (c) University of Luxembourg 2023.
Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
********************************************************************/

#include "error.hpp"
#include "square.hpp"
#include <iostream>

Square::Square(double s) : side(s) {}

double Square::getSurface() const
{
  if (side < 0)
  {
    set_error(1);
    return 0;
  }
  std::cout << "surface=" << side * side << std::endl;
  return side * side;
}

double Square::getPerimeter() const
{
  if (side < 0)
  {
    set_error(1);
    return 0;
  }
  std::cout << "perimeter=" << side * 4 << std::endl;

  return side * 4;
}