#include "Vector.h"
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
	if (isZero()) throw VectorLengthException();
	return Vector(x / len, y / len, z / len);
}

Vector Vector::project(const Vector& v) const {
	if (v.isZero()) throw VectorLengthException();
	return ((*this * v) / (v.length() * v.length())) * v;
}

Vector Vector::project(const Vector& u, const Vector& v) const {
	return u.project(v);
}

bool Vector::isZero() const {
	return *this == Vector();
}

bool Vector::parallel(const Vector& v) const {
	if (isZero() || v.isZero()) throw VectorLengthException();
	return (x / v.x) == (y / v.y) && (y / v.y == z / v.z);
}

bool Vector::perpendicular(const Vector& v) const {
	if (isZero() || v.isZero()) throw VectorLengthException();
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
	bool prompt = false;
	if (&in == &std::cin) prompt = true;

	if (prompt)
		std::cout << "Моля въведете стойност x на вектора:";
	in >> x;
	if (prompt)
		std::cout << "Моля въведете стойност y на вектора:";
	in >> y;
	if (prompt)
		std::cout << "Моля въведете стойност z на вектора:";
	in >> z;
	in.ignore();
	return in;
}

void Vector::printMethods() const {
	std::cout << "1 - изчисляване на дължина на вектор" << std::endl;
	std::cout << "2 - изчисляване на посока на вектор" << std::endl;
	std::cout << "3 - проекция на вектор върху друг вектор" << std::endl;
	std::cout << "4 - проверка за нулев вектор" << std::endl;
	std::cout << "5 - проверка за успоредност на два вектора" << std::endl;
	std::cout << "6 - проверка за перпендикулярност на два вектора" << std::endl;
	std::cout << "7 - събиране на два вектора" << std::endl;
	std::cout << "8 - умножение на вектор с реално число" << std::endl;
	std::cout << "9 - скаларно произведение на два вектора" << std::endl;
	std::cout << "10 - векторно произведение на два вектора" << std::endl;
	std::cout << "11 - смесено произведение на три вектора" << std::endl;
}

void Vector::executeMethod(int method, std::istream& in, std::ostream& out) const {
	Vector v;
	switch (method) {
	case 1:
		out << this->length() << std::endl;
		break;
	case 2:
		out << this->direction() << std::endl;
		break;
	case 3:
		in >> v;
		out << this->project(v) << std::endl;
		break;
	case 4:
		out << (this->isZero() ? "да" : "не") << std::endl;
		break;
	case 5:
		in >> v;
		out << (this->parallel(v) ? "да" : "не") << std::endl;
		break;
	case 6:
		in >> v;
		out << (this->perpendicular(v) ? "да" : "не") << std::endl;
		break;
	case 7:
		in >> v;
		out << *this + v << std::endl;
		break;
	case 8:
		double r;
		out << "Моля въведете реално число:";
		in >> r;
		out << *this * r << std::endl;
		break;
	case 9:
		in >> v;
		out << *this * v << std::endl;
		break;
	case 10:
		in >> v;
		out << (*this ^ v) << std::endl;
		break;
	case 11:
	{
		in >> v;
		Vector v2;
		in >> v2;
		out << (*this)(v, v2) << std::endl;
		break;
	}
	default:
		out << "грешен избор" << std::endl;
	}
}
