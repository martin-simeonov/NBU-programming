#pragma once
#include "Point.h"
#include "Vector.h"

class Triangle : public virtual Point {
	Point a, b, c;
	Vector ab, ac, bc;
	friend bool operator<(const Triangle&, const Point&);
	friend bool operator==(const Triangle&, const Point&);
public:
	Triangle(const Point&, const Point&, const Point&);

	// �����������
	bool isIsosceles() const;
	// ������������
	bool isEquilateral() const;
	// �����������
	bool isAcute() const;
	// ����������
	bool isObtuse() const;
	// �����������
	bool isRight() const;
	double area() const;
	double perimeter() const;
	Point centroid() const;
};

bool operator<(const Triangle&, const Point&);
bool operator<(const Point&, const Triangle&);
bool operator>(const Triangle&, const Point&);
bool operator>(const Point&, const Triangle&);
bool operator==(const Triangle&, const Point&);
bool operator==(const Point&, const Triangle&);