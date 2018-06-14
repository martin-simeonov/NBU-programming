#include "Vector.h"
#include "Line.h"
#include "Segment.h"
#include "Triangle.h"
#include "EqualPointException.h"
#include <iostream>
using namespace std;

int main() {
	Point p1(1, 0, 0);
	Point p2(4, 0, 0);
	Point p3(4, 2, 0);
	Point p4(4, 1, 0);
	Point p5(3, 1, 0);
	Point p6(2, 0, 0);

	Triangle t(p1, p2, p3);

	cout << "is isoceseles " << t.isIsosceles() << endl;
	cout << "is equilateral " << t.isEquilateral() << endl;
	cout << "is acute " << t.isAcute() << endl;
	cout << "is obtuse " << t.isObtuse() << endl;
	cout << "is right " << t.isRight() << endl;
	cout << t.area() << endl;
	cout << t.perimeter() << endl;
	cout << t.centroid() << endl;
	cout << (t < p4) << endl;
	cout << (t < p5) << endl;
	cout << (t < p6) << endl;
	
	cout << (t == p4) << endl;
	cout << (t == p5) << endl;
	cout << (t == p6) << endl;
}