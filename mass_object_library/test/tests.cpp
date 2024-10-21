
/*******************************************************************
Copyright (c) University of Luxembourg 2023.
Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
********************************************************************/

#include <iostream>
#include <cassert>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* libmassobjects headers */
#include <circle.hpp>
#include <square.hpp>
#include <triangle.hpp>
#include <rectangle.hpp>
#include <error.hpp>

/* test suite headers */
#include "tests.hpp"

void flaky(void)
{
    /* this function can make the tests contained in this file flaky */
    time_t t;

    /* Intializes random number generator */
    srand((unsigned)time(&t));
    bool randbool = rand() & 1;

    assert(randbool);
}

int test_circle_s(void)
{
    std::cout << "circle surface\n";

    double radius = 0;
    Circle circleA(radius);
    double value = circleA.getSurface();
    std::cout << "input " << radius << " output " << value << std::endl;
    assert(value == 0);
    int error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    radius = 3;
    Circle circleB(radius);
    value = circleB.getSurface();
    std::cout << "input " << radius << "output " << value << std::endl;
    assert(value == 28.26);
    error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    radius = -1;
    Circle circleC(radius);
    value = circleC.getSurface();
    std::cout << "input " << radius << "output " << value << std::endl;
    assert(value == 0);
    error_status = get_error();
    assert(error_status == 1);
    set_error(0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}

int test_square_s(void)
{
    std::cout << "square surface\n";

    double radius = 0;
    Square squareA(radius);
    double value = squareA.getSurface();
    std::cout << "input " << radius << "output " << value << std::endl;
    assert(value == 0);
    int error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    radius = 3;
    Square squareB(radius);
    value = squareB.getSurface();
    std::cout << "input " << radius << "output " << value << std::endl;
    assert(value == 9);
    error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    radius = -1;
    Square squareC(radius);
    value = squareC.getSurface();
    std::cout << "input " << radius << "output " << value << std::endl;
    assert(value == 0);
    error_status = get_error();
    assert(error_status == 1);
    set_error(0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}

int test_triangle_s(void)
{
    double a = 3, b = 4, c = 5;
    printf("triangle surface\n");
    Triangle triangleA(a, b, c);
    double value = triangleA.getSurface();
    std::cout << "a " << a << "b " << b << "c " << c << std::endl;
    std::cout << "output " << value << std::endl;
    assert(value == 6);
    int error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    a = 3, b = 4, c = 15;
    Triangle triangleB(a, b, c);
    value = triangleB.getSurface();
    std::cout << "a " << a << "b " << b << "c " << c << std::endl;
    std::cout << "output " << value << std::endl;
    assert(value == 0);
    error_status = get_error();
    assert(error_status == 1);
    set_error(0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}

int test_rectangle_s(void)
{
    printf("rectangle surface\n");
    double height = 0, width = 0;
    Rectangle rectangleA(height, width);
    double value = rectangleA.getSurface();
    std::cout << "input " << height << ", " << width << " output " << value << std::endl;
    //Comment out the assertion so that mutants remain live
    //assert(value == 0);
    int error_status = get_error();
    //assert(error_status == 0);
    set_error(0);

    height = 3, width = 5;
    Rectangle rectangleB(height, width);
    value = rectangleB.getSurface();
    std::cout << "input " << height << ", " << width << " output " << value << std::endl;
    assert(value == 15);
    error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    height = -3;
    width = 5;
    Rectangle rectangleC(height, width);
    value = rectangleC.getSurface();
    std::cout << "input " << height << ", " << width << " output " << value << std::endl;
    assert(value == 0);
    error_status = get_error();
    assert(error_status == 1);
    set_error(0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}

int test_example_s(void)
{
    int i;
    double segment = 0;

    for (i = 1; i < 10; ++i)
    {
        segment = segment + (double)i;
        Circle circle(segment);
        Square square(segment);
        double surface_circle = circle.getSurface();
        double surface_square = square.getSurface();
        printf("circle %f, square %f\n", surface_circle, surface_square);
        std::cout << "circle " << surface_circle << "square " << surface_square << std::endl;
        assert(surface_circle > surface_square);
    }
    int error_status = get_error();
    assert(error_status == 0);
    set_error(0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}

int test_circle_p(void)
{

    printf("circle perimeter\n");

    double radius = 0;
    Circle circleA(radius);
    double value = circleA.getPerimeter();
    std::cout << "input " << radius << " output " << value << std::endl;
    assert(value == 0);
    int error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    radius = 3;
    Circle circleB(radius);
    value = circleB.getPerimeter();
    std::cout << "input " << radius << "output " << value << std::endl;
    assert(value == 18.84);
    error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    radius = -1;
    Circle circleC(radius);
    value = circleC.getPerimeter();
    std::cout << "input " << radius << "output " << value << std::endl;
    assert(value == 0);
    error_status = get_error();
    assert(error_status == 1);
    set_error(0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}

int test_square_p(void)
{
    printf("square perimeter\n");

    double radius = 0;
    Square squareA(radius);
    double value = squareA.getPerimeter();
    std::cout << "input " << radius << "output " << value << std::endl;
    assert(value == 0);
    int error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    radius = 3;
    Square squareB(radius);
    value = squareB.getPerimeter();
    std::cout << "input " << radius << "output " << value << std::endl;
    assert(value == 12);
    error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    radius = -1;
    Square squareC(radius);
    value = squareC.getPerimeter();
    std::cout << "input " << radius << "output " << value << std::endl;
    assert(value == 0);
    error_status = get_error();
    assert(error_status == 1);
    set_error(0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}

int test_triangle_p(void)
{
    printf("triangle perimeter\n");
    double a = 0, b = 0, c = 0;
    Triangle triangleA(a, b, c);
    double value = triangleA.getPerimeter();
    std::cout << "input " << a << ", " << b << ", " << c << " output " << value << std::endl;
    assert(value == 0);
    int error_status = get_error();
    assert(error_status == 1);
    set_error(0);

    a = 3, b = 4, c = 5;
    Triangle triangleB(a, b, c);
    value = triangleB.getPerimeter();
    std::cout << "input " << a << ", " << b << ", " << c << " output " << value << std::endl;
    assert(value == 12);
    error_status = get_error();
    assert(error_status == 0);
    set_error(0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}

//int test_triangle_p_a(void)
//{
//    printf("triangle perimeter array\n");
//    double sides[] = { 1, 0, 0};
//    double value = triangle_perimeter_array(sides);
//    printf("input %f, %f, %foutput %f\n", sides[0], sides[1], sides[2], value);
//    assert(value == 1);
//    int error_status = get_error();
//    assert(error_status == 0);
//    set_error(0);
//
//#ifdef FLAKY
//    flaky();
//#endif
//
//    return 0;
//}

int test_rectangle_p(void)
{
    printf("rectangle perimeter\n");
    double height = 0, width = 0;
    Rectangle rect_a(height, width);
    double value = rect_a.getPerimeter();
    std::cout << "input " << height << ", " << width << " output " << value << std::endl;
    assert(value == 0);
    int error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    height = 3;
    width = 5;
    Rectangle rect_b(height, width);
    value = rect_b.getPerimeter();
    std::cout << "input " << height << ", " << width << " output " << value << std::endl;
    assert(value == 16);
    error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    height = -3;
    width = 5;
    Rectangle rect_c(height, width);
    value = rect_c.getPerimeter();    std::cout << "input " << height << ", " << width << " output " << value << std::endl;
    //Comment out the assertion so that corresponding mutants remain live
    //assert(value == 0);
    error_status = get_error();
    //Comment out the assertion so that corresponding mutants remain live
    //assert(error_status == 1);
    set_error(0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}

int test_example_p(void)
{
    int i;
    double segment = 0;

    for (i = 1; i < 10; ++i)
    {
        segment = segment + (double)i;
        Circle circle(segment);
        Square square(segment);
        double perimeter_circle = circle.getPerimeter();
        double perimeter_square = square.getPerimeter();
        std::cout << "circle " << perimeter_circle << ", square " << perimeter_square << std::endl;
        assert(perimeter_circle > perimeter_square);
    }
    int error_status = get_error();
    assert(error_status == 0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}
