#include "Point.h"

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
