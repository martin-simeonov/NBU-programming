#include "Point.h"

Point::Point(double x, double y, double z)
	: x(x), y(y), z(z)
{}

double Point::getX() const {
	return x;
}

double Point::getY() const {
	return y;
}

double Point::getZ() const {
	return z;
}

bool Point::operator==(const Point& other) const {
	return x == other.x && y == other.y && z == other.z;
}

std::ostream& Point::ins(std::ostream& out) const {
	return out << "P(" << x << ", " << y << ", " << z << ")";
}

std::istream& Point::out(std::istream& in) const {
	std::cout << "Моля въведете стойност x на вектора:";
	//in >> x;
	return in;
}
