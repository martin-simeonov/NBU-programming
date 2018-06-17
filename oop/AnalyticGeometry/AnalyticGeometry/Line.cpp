#include "Line.h"

Line::Line(const Point& p, const Vector& v) 
	: Point(p.getX(), p.getY(), p.getZ()), slope(v)
{}

Line::Line(const Point& p1, const Point& p2)
	: Line(p1, Vector(p1, p2))
{}

Vector Line::direction() const {
	return slope;
}

Vector Line::normal() const {
	if (!slope.parallel(Vector(1, 0, 0)))
		return slope ^ Vector(1, 0, 0);
	else if (!slope.parallel(Vector(0, 1, 0)))
		return slope ^ Vector(0, 1, 0);
	else
		return slope ^ Vector(0, 0, 1);
}

double Line::angle(const Line& l) const {
	return slope.angle(l.slope);
}

double Line::distance(const Line& l) const {
	Vector n = slope ^ l.slope;
	if (n.isZero()) return 0;
	return (n * (Vector(x, y, z) - Vector(l.x, l.y, l.z))) / n.length();
}

bool Line::operator||(const Line& l) const {
	return distance(l) != 0 && slope.parallel(l.slope);
}

bool Line::operator==(const Line& l) const {
	return distance(l) == 0 && slope.parallel(l.slope);
}

bool Line::operator&&(const Line& l) const {
	return distance(l) == 0 && !slope.parallel(l.slope);
}

bool Line::operator!=(const Line& l) const {
	return  !(*this == l) && !(*this || l) && !(*this && l);
}

bool Line::operator|(const Line& l) const {
	return distance(l) == 0 && slope.perpendicular(l.slope);
}

bool operator+(const Point& p, const Line& l) {
	return (Vector(Point(l.x, l.y, l.z), p) ^ l.slope) == 0;
}

bool operator+(const Line& l, const Point& p) {
	return p + l;
}

std::ostream& Line::ins(std::ostream& out ) const {
	out << "x=" << x << "+" << slope.getX() << "t"
		<< ", y=" << y << "+" << slope.getY() << "t"
		<< ", z=" << z << "+" << slope.getZ() << "t";
	return out;
}

std::istream& Line::out(std::istream& in) const {
	return in;
}
