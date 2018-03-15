#ifndef _POINT_H
#define _POINT_H

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

#endif
