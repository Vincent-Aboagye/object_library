/*******************************************************************
Copyright (c) University of Luxembourg 2023.
Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
********************************************************************/


#include <iostream>
#include <cstring>
#include "tests.hpp"

void print_arguments()
{
  std::cout << "'circle-s', 'square-s', 'rectangle-s', 'triangle-s', 'example-s'\n";
  std::cout << "'circle-p', 'square-p', 'rectangle-p', 'triangle-p', 'example-p'\n";
}

int main(int argc, char* argv[])
{
  if (argc != 2)
    {
    std::cout << "ERROR: must be invoked with one of these arguments:\n";
    print_arguments();
    return 666;
  }

  std::string testCase = argv[1];

  if (testCase == "circle-s")
    {
    return test_circle_s();
  }
    else if (testCase == "square-s")
    {
    return test_square_s();
  }
    else if (testCase == "rectangle-s")
    {
    return test_rectangle_s();
  }
    else if (testCase == "triangle-s")
    {
    return test_triangle_s();
  }
    else if (testCase == "example-s")
    {
    return test_example_s();
  }
    else if (testCase == "circle-p")
    {
    return test_circle_p();
  }
    else if (testCase == "square-p")
    {
    return test_square_p();
  }
    else if (testCase == "rectangle-p")
    {
    return test_rectangle_p();
  }
    else if (testCase == "triangle-p")
    {
    return test_triangle_p();
  }
//    else if (testCase == "triangle-p-a")
//    {
//    return test_triangle_p_a();
//  }
    else if (testCase == "example-p")
    {
    return test_example_p();
  }
    else
    {
    std::cout << "ERROR: the only acceptable arguments are:\n";
    print_arguments();
    return 666;
  }
}
