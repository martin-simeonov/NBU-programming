#pragma once
#include "Point.h"
#include "Vector.h"

class Triangle : public virtual Point {
	Point a, b, c;
	Vector ab, ac, bc;
	friend bool operator<(const Triangle&, const Point&);
	friend bool operator==(const Triangle&, const Point&);
public:
	Triangle();
	Triangle(const Point&, const Point&, const Point&);
	Triangle(const Triangle&);
	virtual ~Triangle();
	Triangle& operator=(const Triangle&);

	// Равнобедрен
	bool isIsosceles() const;
	// Равностранен
	bool isEquilateral() const;
	// Остроъгълен
	bool isAcute() const;
	// Тъпоъгълен
	bool isObtuse() const;
	// Правоъгълен
	bool isRight() const;
	double area() const;
	double perimeter() const;
	Point centroid() const;

	virtual std::ostream& ins(std::ostream&) const;
	virtual std::istream& out(std::istream&);
};

bool operator<(const Triangle&, const Point&);
bool operator<(const Point&, const Triangle&);
bool operator>(const Triangle&, const Point&);
bool operator>(const Point&, const Triangle&);
bool operator==(const Triangle&, const Point&);
bool operator==(const Point&, const Triangle&);