#include "Triangle.h"
#include "Segment.h"
#include "EqualPointException.h"

Triangle::Triangle()
	: a(Point()), b(Point()), c(Point()),
	ab(Vector()), ac(Vector()), bc(Vector())
{}

Triangle::Triangle(const Point& a, const Point& b, const Point& c)
	: a(a), b(b), c(c), ab(b, a), ac(a, c), bc(b, c)
{
	if (a == b)
		throw EqualPointException("A", "B", a);
	else if (a == c)
		throw EqualPointException("A", "C", a);
	else if (b == c)
		throw EqualPointException("B", "C", b);
}

Triangle::Triangle(const Triangle& other)
	: Triangle(other.a, other.b, other.c)
{}

Triangle::~Triangle()
{}

Triangle & Triangle::operator=(const Triangle& other) {
	this->a = other.a;
	this->b = other.b;
	this->c = other.c;
	this->ab = other.ab;
	this->ac = other.ac;
	this->bc = other.bc;
	return *this;
}

bool Triangle::isIsosceles() const {
	return (ab.length() == ac.length()) ||
		(ab.length() == bc.length()) ||
		(bc.length() == ac.length());
}

bool Triangle::isEquilateral() const {
	return (ab.length() == ac.length()) && (ac.length() == bc.length());
}

bool Triangle::isAcute() const {
	double abSquare = ab.length() * ab.length();
	double acSquare = ac.length() * ac.length();
	double bcSquare = bc.length() * bc.length();

	return (abSquare + acSquare > bcSquare) &&
		(abSquare + bcSquare > acSquare) &&
		(acSquare + bcSquare > abSquare) && !isRight();
}

bool Triangle::isObtuse() const {
	return !isRight() && !isAcute();
}

bool Triangle::isRight() const {
	return ab.perpendicular(ac) ||
		ac.perpendicular(bc) ||
		ab.perpendicular(bc);
}

void Triangle::triangleIs() const {
	triangleIs(std::cout);
}

void Triangle::triangleIs(std::ostream& out) const {
	if (isIsosceles()) out << "Равнобедрен" << std::endl;
	if (isEquilateral()) out << "Равностранен" << std::endl;
	if (isAcute()) out << "Остроъгълен" << std::endl;
	if (isObtuse()) out << "Тъпоъгълен" << std::endl;
	if (isRight()) out << "Правоъгълен" << std::endl;
}

double Triangle::area() const {
	return (ab ^ ac).length() / 2;
}

double Triangle::perimeter() const {
	return ab.length() + ac.length() + bc.length();
}

Point Triangle::centroid() const {
	return Point((a.getX() + b.getX() + c.getX()) / 3,
		(a.getY() + b.getY() + c.getY()) / 3,
		(a.getZ() + b.getZ() + c.getZ()) / 3);
}

bool operator<(const Triangle& t, const Point& p) {
	double s1 = Triangle(t.a, t.b, p).area();
	double s2 = Triangle(t.a, t.c, p).area();
	double s3 = Triangle(t.b, t.c, p).area();
	double areaSum = (s1 + s2 + s3) / t.area();
	return areaSum >= 0 && areaSum <= 1 && s1 != 0 && s2 != 0 && s3 != 0;
}

bool operator<(const Point& p, const Triangle& t) {
	return t < p;
}

bool operator>(const Triangle& t, const Point& p) {
	return !(t < p);
}

bool operator>(const Point& p, const Triangle& t) {
	return t > p;
}

bool operator==(const Triangle& t, const Point& p) {
	return Segment(t.a, t.b) == p ||
		Segment(t.a, t.c) == p ||
		Segment(t.b, t.c) == p;
}

bool operator==(const Point& p, const Triangle& t) {
	return t == p;
}

std::ostream& Triangle::ins(std::ostream& out) const {
	out << "T(" << a << ", " << b << ", " << c << ")";
	return out;
}

std::istream& Triangle::out(std::istream& in) {
	Point p1, p2, p3;
	double px, py, pz;

	std::cout << "Моля въведете стойност x на точка 1:";
	in >> px;
	std::cout << "Моля въведете стойност y на точка 1:";
	in >> py;
	std::cout << "Моля въведете стойност z на точка 1:";
	in >> pz;
	p1 = Point(px, py, pz);
	std::cout << "Моля въведете стойност x на точка 2:";
	in >> px;
	std::cout << "Моля въведете стойност y на точка 2:";
	in >> py;
	std::cout << "Моля въведете стойност z на точка 2:";
	in >> pz;
	p2 = Point(px, py, pz);
	std::cout << "Моля въведете стойност x на точка 3:";
	in >> px;
	std::cout << "Моля въведете стойност y на точка 3:";
	in >> py;
	std::cout << "Моля въведете стойност z на точка 3:";
	in >> pz;
	p3 = Point(px, py, pz);

	this->operator=(Triangle(p1, p2, p3));

	in.ignore();
	return in;
}

void Triangle::printMethods() const {
	std::cout << "1 - вид на триъгълника" << std::endl;
	std::cout << "2 - лице на триъгълника" << std::endl;
	std::cout << "3 - периметър на триъгълника" << std::endl;
	std::cout << "4 - медицентър на триъгълника" << std::endl;
	std::cout << "5 - точка във вътрешността на триъгълника ли е" << std::endl;
	std::cout << "6 - точка извън триъгълника ли е" << std::endl;
	std::cout << "7 - точка лежи ли върху страна от триъгълника" << std::endl;
}

void Triangle::executeMethod(int method, std::istream& in, std::ostream& out) const {
	Point p;
	switch (method) {
	case 1:
		triangleIs(out);
		break;
	case 2:
		out << this->area() << std::endl;
		break;
	case 3:
		out << this->perimeter() << std::endl;
		break;
	case 4:
		out << this->centroid() << std::endl;
		break;
	case 5:
		in >> p;
		out << (*this < p ? "да" : "не") << std::endl;
		break;
	case 6:
		in >> p;
		out << (*this > p ? "да" : "не") << std::endl;
		break;
	case 7:
		in >> p;
		out << (*this == p ? "да" : "не") << std::endl;
		break;
	default:
		out << "грешен избор" << std::endl;
	}
}