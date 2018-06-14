#include "Segment.h"

Segment::Segment(const Point& p1, const Point& p2) 
	: Point(p1), Line(p1, p2), end(p2)
{}

double Segment::length() const {
	return Vector(Point(x, y, z), 
		Point(x + slope.getX(), 
			y + slope.getY(), 
			z + slope.getZ())).length();
}

Point Segment::midpoint() const {
	return Point((x + end.getX()) / 2,
		(y + end.getY()) / 2,
		(z + end.getZ()) / 2);
}

bool Segment::operator==(const Point& p) const {
	return (Vector(Point(x, y, z), p) ^ Vector(end, p)).isZero();
}