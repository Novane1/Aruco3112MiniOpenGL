#pragma once
#include <iostream>

class Vector3 {
private:
    float x, y, z;

public:
    // Constructor
    Vector3(float xVal, float yVal, float zVal) : x(xVal), y(yVal), z(zVal) {}

    // Default constructor (initializes to zero)
    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}

    // Setter methods
    void setX(float xVal) { x = xVal; }
    void setY(float yVal) { y = yVal; }
    void setZ(float zVal) { z = zVal; }

    // Getter methods
    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }

    // Function to print the vector
    void print() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
};