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
	if (this != &other) {
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
	}
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
	bool prompt = false;
	if (&in == &std::cin) prompt = true;

	if (prompt)
		std::cout << "���� �������� �������� x �� �������:";
	in >> x;
	if (prompt)
		std::cout << "���� �������� �������� y �� �������:";
	in >> y;
	if (prompt)
		std::cout << "���� �������� �������� z �� �������:";
	in >> z;
	in.ignore();
	return in;
}

void Point::printMethods() const {
	std::cout << "1 - �������� �� ��� �����" << std::endl;
}

void Point::executeMethod(int method, std::istream& in, std::ostream& out) const {
	switch (method) {
	case 1:
	{
		Point p;
		in >> p;
		out << (this->operator==(p) ? "��" : "��") << std::endl;
		break;
	}
	default: std::cout << "������ �����" << std::endl;
	}
}
