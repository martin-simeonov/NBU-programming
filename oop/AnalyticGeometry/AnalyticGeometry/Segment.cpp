#include "Segment.h"

Segment::Segment()
	: Segment(Point(), Point())
{}

Segment::Segment(const Point& p1, const Point& p2) 
	: Point(p1), Line(p1, p2), end(p2)
{}

Segment::Segment(const Segment& other) 
	: Segment(Point(other.x, other.y, other.z), 
		Point(other.end.getX(), other.end.getY(), other.end.getZ()))
{}

Segment::~Segment()
{}

Segment& Segment::operator=(const Segment& other) {
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	this->end = other.end;
	return *this;
}

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

std::ostream& Segment::ins(std::ostream& out) const {
	Line::ins(out);
	out << " t belongs [0, 1]";
	return out;
}

std::istream& Segment::out(std::istream& in) {
	std::cout << "Моля въведете стойност x на точка 1:";
	in >> x;
	std::cout << "Моля въведете стойност y на точка 1:";
	in >> y;
	std::cout << "Моля въведете стойност z на точка 1:";
	in >> z;
	double vx, vy, vz;
	std::cout << "Моля въведете стойност x на точка 2:";
	in >> vx;
	std::cout << "Моля въведете стойност y на точка 2:";
	in >> vy;
	std::cout << "Моля въведете стойност z на точка 2:";
	in >> vz;
	slope = Vector(Point(x, y, z), Point(vx, vy, vz));
	end = Vector(vx, vy, vz);
	in.ignore();
	return in;
}
