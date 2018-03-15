#include <iostream>

class Point {
    double _x;
    double _y;
    double _z;
public:
    Point(double x, double y, double z);
    void dump();
    Point& scaleX(double scale);
    Point& scaleY(double scale);
    Point& scaleZ(double scale);
    Point& scale(double scaleX, double scaleY, double scaleZ);
    Point& operator+=(const Point& other);
};

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


int main() {
    Point p1(1.0, 1.0, 1.0);
    Point p2(2.0, 2.0, 2.0);
    Point p3(3.0, 3.0, 3.0);

    p1.scale(1.5, 3, 2);
    p2.scale(1.5, 3, 2);
    p3.scale(1.5, 3, 2);

    p1.scaleY(0.75);
    p2.scaleY(0.75);
    p3.scaleY(0.75);

    Point s1(0, 0, 3);
    p1 += s1;
    p2 += s1;
    p3 += s1;
/*
    p1.dump();
    p2.dump();
    p3.dump();*/
}
