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
	Line l(p1, p3);
	Segment s(p1, p3);
	Triangle t(p1, p2, p3);

	cout << l << endl;
	cout << s << endl;
	cout << t << endl;
}