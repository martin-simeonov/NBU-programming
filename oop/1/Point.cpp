#include "Point.h"
#include <iostream>

Point::Point(double x, double y, double z) :_x(x), _y(y), _z(z) {}

void Point::dump() {
    std::cout << "(" << _x << ", " << _y << ", " << _z << ")" << std::endl;
}

Point& Point::scaleX(double scale) {
    _x *= scale;
    return *this;
}

Point& Point::scaleY(double scale) {
    _y *= scale;
    return *this;
}

Point& Point::scaleZ(double scale) {
    _z *= scale;
    return *this;
}

Point& Point::scale(double scaleX, double scaleY, double scaleZ) {
    return this -> scaleX(scaleX).scaleY(scaleY).scaleZ(scaleZ);
}

Point& Point::operator+=(const Point& other) {
    this->_x += other._x;
    this->_y += other._y;
    this->_z += other._z;
    return *this;
}
