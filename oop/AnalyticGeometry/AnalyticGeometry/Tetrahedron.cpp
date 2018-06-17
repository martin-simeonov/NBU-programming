#include "Tetrahedron.h"
#include "EqualPointException.h"

Tetrahedron::Tetrahedron()
	: Triangle(), d(Point()), side1(), side2(), side3()
{}

Tetrahedron::Tetrahedron(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
	: Triangle(p1, p2, p3), d(p4), side1(p1, p2, p4), side2(p2, p3, p4), side3(p1, p3, p4)
{
	if (p1 == p4 || p2 == p4 || p3 == p4)
		throw EqualPointException(p4);
}

Tetrahedron::Tetrahedron(const Tetrahedron& other)
	: Tetrahedron(other.a, other.b, other.c, other.d)
{}

Tetrahedron::~Tetrahedron()
{}

Tetrahedron& Tetrahedron::operator=(const Tetrahedron& other) {
	if (this != &other) {
		Triangle::operator=(other);
		d = other.d;
		side1 = other.side1;
		side2 = other.side2;
		side3 = other.side3;
	}
	return *this;
}

bool Tetrahedron::isRegular() const {
	return this->isEquilateral() && side1.isEquilateral() && side2.isEquilateral()
		&& side3.isEquilateral() && this->area() == side1.area() && side1.area() == side2.area()
		&& side2.area() == side3.area();
}

bool Tetrahedron::isOrthogonal() const {
	double abSquare = ab.length() * ab.length();
	double cdSquare = Vector(c, d).length() * Vector(c, d).length();
	double acSquare = ac.length() * ac.length();
	double bdSquare = Vector(b, d).length() * Vector(b, d).length();
	double adSquare = Vector(a, d).length() * Vector(a, d).length();
	double bcSquare = bc.length() * bc.length();

	return (abSquare + cdSquare) == (acSquare + bdSquare) &&
		(acSquare + bdSquare) == (adSquare + bcSquare);
}

double Tetrahedron::area() const {
	return Triangle::area() + side1.area() + side2.area() + side3.area();
}

double Tetrahedron::volume() const {
	return Vector(b, d).operator()(Vector(c, d), Vector(a, d)) / 6;
}

std::ostream& Tetrahedron::ins(std::ostream& out) const {
	out << "Tetra(" << a << ", " << b << ", " << c << ", " << d << ")";
	return out;
}

std::istream& Tetrahedron::out(std::istream& in) {
	Triangle::out(in);
	bool prompt = false;
	if (&in == &std::cin) prompt = true;

	double px, py, pz;

	if (prompt)
		std::cout << "Моля въведете стойност x на точка 4:";
	in >> px;
	if (prompt)
		std::cout << "Моля въведете стойност y на точка 4:";
	in >> py;
	if (prompt)
		std::cout << "Моля въведете стойност z на точка 4:";
	in >> pz;
	d = Point(px, py, pz);
	
	this->operator=(Tetrahedron(a, b, c, d));
	in.ignore();
	return in;
}

void Tetrahedron::printMethods() const {
	std::cout << "1 - правилен ли е тетраедъра" << std::endl;
	std::cout << "2 - ортагонален ли е тетраедъра" << std::endl;
	std::cout << "3 - околна повърхнина" << std::endl;
	std::cout << "4 - обем" << std::endl;
	std::cout << "5 - точка във вътрешността на тетраедъра ли е" << std::endl;
	std::cout << "6 - точка извън тетраедъра ли е" << std::endl;
	std::cout << "7 - точка лежи ли върху тетраедъра" << std::endl;
}

void Tetrahedron::executeMethod(int method, std::istream& in, std::ostream& out) const {
	Point p;
	switch (method) {
	case 1:
		out << (this->isRegular() ? "да" : "не") << std::endl;
		break;
	case 2:
		out << (this->isOrthogonal() ? "да" : "не") << std::endl;
		break;
	case 3:
		out << this->area() << std::endl;
		break;
	case 4:
		out << this->volume() << std::endl;
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

bool operator<(const Tetrahedron& tetra, const Point& p) {
	return Triangle(tetra.a, tetra.b, tetra.c) < p && (tetra.side1 < p)
		&& (tetra.side2) < p && (tetra.side3 < p);
}

bool operator<(const Point& p, const Tetrahedron& tetra) {
	return tetra < p;
}

bool operator>(const Tetrahedron& tetra, const Point& p) {
	return !(tetra < p);
}

bool operator>(const Point& p, const Tetrahedron& tetra) {
	return tetra > p;
}

bool operator==(const Tetrahedron& tetra, const Point& p) {
	return Triangle(tetra.a, tetra.b, tetra.c) == p && tetra.side1 == p
		&& tetra.side2 == p && tetra.side3 == p;
}

bool operator==(const Point& p, const Tetrahedron& tetra) {
	return tetra == p;
}
