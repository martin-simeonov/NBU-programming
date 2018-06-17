#include "Point.h"

Point::Point(double x, double y, double z)
	: x(x), y(y), z(z)
{}

Point::Point(const Point& other)
	: x(other.x), y(other.y), z(other.z)
{}

Point::~Point()
{
}

Point & Point::operator=(const Point& other) {
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	return *this;
}

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

std::istream& Point::out(std::istream& in) {
	std::cout << "Моля въведете стойност x на точката:";
	in >> x;
	std::cout << "Моля въведете стойност y на точката:";
	in >> y;
	std::cout << "Моля въведете стойност z на точката:";
	in >> z;
	in.ignore();
	return in;
}
