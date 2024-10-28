#include "circle.hpp"
#include "square.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "error.hpp"
#include <cstdint>
#include <cstring>
#include <iostream>

void fuzz_circle(const uint8_t *data, size_t size) {
    if (size < sizeof(double)) return;
    double radius;
    std::memcpy(&radius, data, sizeof(double));
    
    Circle circle(radius);
    circle.getSurface();
    circle.getPerimeter();
}

void fuzz_square(const uint8_t *data, size_t size) {
    if (size < sizeof(double)) return;
    double side;
    std::memcpy(&side, data, sizeof(double));
    
    Square square(side);
    square.getSurface();
    square.getPerimeter();
}

void fuzz_rectangle(const uint8_t *data, size_t size) {
    if (size < 2 * sizeof(double)) return;
    double height, width;
    std::memcpy(&height, data, sizeof(double));
    std::memcpy(&width, data + sizeof(double), sizeof(double));
    
    Rectangle rectangle(height, width);
    rectangle.getSurface();
    rectangle.getPerimeter();
}

void fuzz_triangle(const uint8_t *data, size_t size) {
    if (size < 3 * sizeof(double)) return;
    double a, b, c;
    std::memcpy(&a, data, sizeof(double));
    std::memcpy(&b, data + sizeof(double), sizeof(double));
    std::memcpy(&c, data + 2 * sizeof(double), sizeof(double));
    
    Triangle triangle(a, b, c);
    triangle.getSurface();
    triangle.getPerimeter();
}

// Fuzz target entry point for AFL++ or libFuzzer
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    // Fuzz each shape independently
    fuzz_circle(data, size);
    fuzz_square(data, size);
    fuzz_rectangle(data, size);
    fuzz_triangle(data, size);
    
    return 0;  // Return 0 to indicate normal exit
}