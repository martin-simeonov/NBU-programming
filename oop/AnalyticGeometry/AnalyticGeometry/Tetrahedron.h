#pragma once
#include "Triangle.h"

class Tetrahedron : public virtual Triangle {
	Point d;
	Triangle side1, side2, side3;

	friend bool operator<(const Tetrahedron&, const Point&);
	friend bool operator==(const Tetrahedron&, const Point&);
public:
	Tetrahedron();
	Tetrahedron(const Point&, const Point&, const Point&, const Point&);
	Tetrahedron(const Tetrahedron&);
	~Tetrahedron();
	virtual Tetrahedron& operator=(const Tetrahedron&);

	bool isRegular() const;
	bool isOrthogonal() const;
	virtual double area() const;
	double volume() const;

	virtual std::ostream& ins(std::ostream&) const;
	virtual std::istream& out(std::istream&);

	virtual void printMethods() const;
	virtual void executeMethod(int, std::istream&, std::ostream&) const;
};

bool operator<(const Tetrahedron&, const Point&);
bool operator<(const Point&, const Tetrahedron&);
bool operator>(const Tetrahedron&, const Point&);
bool operator>(const Point&, const Tetrahedron&);
bool operator==(const Tetrahedron&, const Point&);
bool operator==(const Point&, const Tetrahedron&);