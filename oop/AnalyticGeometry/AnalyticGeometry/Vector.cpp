#include "Vector.h"
#include "VectorLengthException.h"
#include <cmath>

Vector::Vector(double x, double y, double z)
	: Point(x, y, z)
{}

Vector::Vector(const Point& p1, const Point& p2)
	: Point(p2.getX() - p1.getX(),
		p2.getY() - p1.getY(),
		p2.getZ() - p1.getZ())
{}

Vector::Vector(const Vector& other)
	: Vector(other.x, other.y, other.z)
{}

Vector::~Vector()
{}

Vector& Vector::operator=(const Vector& other) {
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	return *this;
}

double Vector::length() const {
	return sqrt((x*x) + (y*y) + (z*z));
}

Vector Vector::direction() const {
	double len = length();
	if (isZero()) throw new VectorLengthException;
	return Vector(x / len, y / len, z / len);
}

Vector Vector::project(const Vector& v) const {
	if (v.isZero()) throw new VectorLengthException;
	return ((*this * v) / (v.length() * v.length())) * v;
}

Vector Vector::project(const Vector& u, const Vector& v) const {
	return u.project(v);
}

bool Vector::isZero() const {
	return *this == Vector();
}

bool Vector::parallel(const Vector& v) const {
	if (isZero() || v.isZero()) throw new VectorLengthException;
	return (x / v.x) == (y / v.y) && (y / v.y == z / v.z);
}

bool Vector::perpendicular(const Vector& v) const {
	if (isZero() || v.isZero()) throw new VectorLengthException;
	return (*this * v) == 0;
}

double Vector::angle(const Vector& v) const {
	return acos((*this * v) / (length() * v.length()));
}

Vector Vector::operator+(const Vector& v) const {
	return Vector(x + v.x, y + v.y, z + v.z);
}

Vector Vector::operator-(const Vector& v) const {
	return Vector(x - v.x, y - v.y, z - v.z);
}

Vector operator*(const Vector& v, double r) {
	return Vector(r * v.x, r * v.y, r * v.z);
}

Vector operator*(double r, const Vector& v) {
	return operator*(v, r);
}

double Vector::operator*(const Vector& v) const {
	return (x * v.x) + (y * v.y) + (z * v.z);
}

Vector Vector::operator^(const Vector& v) const {
	return Vector((y * v.z) - (z * v.y),
		(-1 * x * v.z) + (z * v.x),
		(x * v.y) - (y * v.x));
}

double Vector::operator()(const Vector& v, const Vector& w) const {
	return (*this^v) * w;
}

std::ostream& Vector::ins(std::ostream& out) const {
	return out << "V(" << x << ", " << y << ", " << z << ")";
}

std::istream& Vector::out(std::istream& in) {
	std::cout << "Моля въведете стойност x на вектора:";
	in >> x;
	std::cout << "Моля въведете стойност y на вектора:";
	in >> y;
	std::cout << "Моля въведете стойност z на вектора:";
	in >> z;
	in.ignore();
	return in;
}
