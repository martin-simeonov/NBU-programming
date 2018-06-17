#include "Line.h"

Line::Line()
	: Line(Point(), Vector())
{}

Line::Line(const Point& p, const Vector& v)
	: Point(p.getX(), p.getY(), p.getZ()), slope(v)
{}

Line::Line(const Point& p1, const Point& p2)
	: Line(p1, Vector(p1, p2))
{}

Line::Line(const Line& other)
	: Line(Point(other.x, other.y, other.z), Vector(other.slope))
{}

Line::~Line()
{}

Line& Line::operator=(const Line& other) {
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	this->slope = other.slope;
	return *this;
}

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

std::ostream& Line::ins(std::ostream& out) const {
	out << "x=" << x << "+" << slope.getX() << "t"
		<< ", y=" << y << "+" << slope.getY() << "t"
		<< ", z=" << z << "+" << slope.getZ() << "t";
	return out;
}

std::istream& Line::out(std::istream& in) {
	bool prompt = false;
	if (&in == &std::cin) prompt = true;

	if (prompt)
		std::cout << "Моля въведете стойност x на точка:";
	in >> x;
	if (prompt)
		std::cout << "Моля въведете стойност y на точка:";
	in >> y;
	if (prompt)
		std::cout << "Моля въведете стойност z на точка:";
	in >> z;

	double vx, vy, vz;
	if (prompt)
		std::cout << "Моля въведете стойност x на вектор:";
	in >> vx;
	if (prompt)
		std::cout << "Моля въведете стойност y на вектор:";
	in >> vy;
	if (prompt)
		std::cout << "Моля въведете стойност z на вектор:";
	in >> vz;
	slope = Vector(vx, vy, vz);
	in.ignore();
	return in;
}

void Line::printMethods() const {
	std::cout << "1 - посока на правата" << std::endl;
	std::cout << "2 - нормален вектор" << std::endl;
	std::cout << "3 - ъгъл между 2 прави" << std::endl;
	std::cout << "4 - дали точката лежи върху правата" << std::endl;
	std::cout << "5 - правата успоредна ли е на друга права" << std::endl;
	std::cout << "6 - правата съвпада ли с друга права" << std::endl;
	std::cout << "7 - правата пресича ли друга права" << std::endl;
	std::cout << "8 - правата кръстосана ли е с друга права" << std::endl;
	std::cout << "9 - правата перпендикулярна ли е на друга права" << std::endl;
}

void Line::executeMethod(int method, std::istream& in, std::ostream& out) const {
	Line l;
	Point p;

	switch (method) {
	case 1:
		out << this->direction() << std::endl;
		break;
	case 2:
		out << this->normal() << std::endl;
		break;
	case 3:
		in >> l;
		out << this->angle(l) << std::endl;
		break;
	case 4:
		in >> p;
		out << (*this + p ? "да" : "не") << std::endl;
		break;
	case 5:
		in >> l;
		out << (*this || l ? "да" : "не") << std::endl;
		break;
	case 6:
		in >> l;
		out << (*this == l ? "да" : "не") << std::endl;
		break;
	case 7:
		in >> l;
		out << (*this && l ? "да" : "не") << std::endl;
		break;
	case 8:
		in >> l;
		out << (*this != l ? "да" : "не") << std::endl;
		break;
	case 9:
		in >> l;
		out << (*this | l ? "да" : "не") << std::endl;
		break;
	default:
		out << "грешен избор" << std::endl;
	}
}
