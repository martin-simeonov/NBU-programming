#include "Vector.h"
#include "Line.h"
#include <iostream>
using namespace std;

int main() {
	Point p1(12, 15, 8);
	Point p2(12, 15, 1);
	Vector v1(6, 8, 32);
	Line l1(p1, v1);
	Line l2(p2, Vector(6, 1, 32));

	cout << l1.angle(l2) << endl;
	cout << l1.distance(l2) << endl;
	cout << "parellel: " << (l1 || l2) << endl;
	cout << "concede: " << (l1 == l2) << endl;
	cout << "intersect: " << (l1 && l2) << endl;
	cout << "skew: " << (l1 != l2) << endl;
	cout << "perpendicular: " << (l1 | l2) << endl;
}